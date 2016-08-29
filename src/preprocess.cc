#include <cassert>
#include <list>
#include <stdlib.h>
#include "preprocess.h"
#include "utils.h"

using namespace std;

// TODO: implement proper cross-references (and update functions) and
//       relevance of atoms wrt goal

Preprocessor::Preprocessor(Instance &ins)
  : instance_(ins), options_(ins.options_) {
    for( size_t k = 0; k < instance_.n_atoms(); k++ ) atom_map_.push_back(k);
    for( size_t k = 0; k < instance_.n_actions(); k++ ) action_map_.push_back(k);
}

Preprocessor::~Preprocessor() {
}

// A conditional effect is inconsistent if adds and deletes the same fluent.
// An action is inconsistent if (unconditionally) adds and deletes the same fluent.
// This procedure removes all inconsistent conditional effects from actions, and
// marks all inconsistent actions.

void Preprocessor::mark_inconsistent_actions(bool_vec &actions_to_remove) {
    bool_vec inconsistent(instance_.n_actions(), false);
    for( size_t k = 0; k < instance_.n_actions(); k++ ) {
        Instance::Action &act = *instance_.actions_[k];

        // check for inconsistencies in add and del
        for( index_set::const_iterator it = act.effect_.begin(); it != act.effect_.end(); ++it ) {
            if( act.effect_.contains(-*it) ) {
                actions_to_remove[k] = true;
                break;
            }
        }

        // check for inconsistencies in conditional effects
        if( !actions_to_remove[k] ) {
            for( int i = 0; i < (int)act.when_.size(); ++i ) {
                Instance::When &when = act.when_[i];
                for( index_set::const_iterator it = when.effect_.begin(); it != when.effect_.end(); ++it ) {
                    if( when.effect_.contains(-*it) ) {
                        act.when_[i] = act.when_.back();
                        act.when_.pop_back();
                        --i;
                        break;
                    }
                }
            }
        }

        if( actions_to_remove[k] && options_.is_enabled("problem:print:action:inconsistent") ) {
            cout << Utils::yellow()
                 << "  action " << k << "." << act.name_ << " is inconsistent."
                 << Utils::normal() << endl;
        }
    }
}

// A conditional effect is useless if all its effects are contained in its condition.
// An action is useless if it does not have non-useless conditional effects and all
// its effects are contained in the precondition.
// This procedure remove all useless conditional effects, and marks all useless actions.

void Preprocessor::mark_useless_actions(bool_vec &actions_to_remove) {
    bool_vec useless(instance_.n_actions(), true);
    for( size_t k = 0; k < instance_.n_actions(); k++ ) {
        Instance::Action &act = *instance_.actions_[k];

        // remove useless conditional effects
        for( int i = 0; i < (int)act.when_.size(); ++i ) {
            bool useless_effect = true;
            for( index_set::const_iterator it = act.when_[i].effect_.begin(); it != act.when_[i].effect_.end(); ++it ) {
                if( !act.when_[i].condition_.contains(*it) ) {
                    useless_effect = false;
                    break;
                }
            }

            if( useless_effect ) {
                act.when_[i] = act.when_.back();
                act.when_.pop_back();
                --i;
            }
        }

        // remove useless actions
        if( act.when_.empty() ) {
            for( index_set::const_iterator it = act.effect_.begin(); it != act.effect_.end(); ++it ) {
                if( !act.precondition_.contains(*it) ) {
                    useless[k] = false;
                    break;
                } else {
                }
            }
        } else {
            useless[k] = false;
        }

        if( useless[k] ) {
            actions_to_remove[k] = true;
            if( options_.is_enabled("problem:print:action:useless") ) {
                cout << Utils::yellow()
                     << "action " << k << "." << act.name_ << " is useless."
                     << Utils::normal() << endl;
            }
        }
    }
}


// This procedure detects actions with dead preconditions determined by static atoms
// and the known atoms at initial state. It must be called after the set of static
// and reachable atoms have been computed.

void Preprocessor::mark_unreachable_actions(const bool_vec &reachable_atoms, const bool_vec &static_atoms, bool_vec &actions_to_remove) {
    // compute known literals in init
    bool_vec pos_literal_in_init(instance_.n_atoms(), false);
    bool_vec neg_literal_in_init(instance_.n_atoms(), false);
    for( index_set::const_iterator it = instance_.init_.literals_.begin(); it != instance_.init_.literals_.end(); ++it ) {
        if( *it > 0 )
            pos_literal_in_init[*it - 1] = true;
        else
            neg_literal_in_init[-*it - 1] = true;
    }

    // iterate over actions and their conditional effects.
    for( size_t k = 0; k < instance_.actions_.size(); ++k ) {
        Instance::Action &act = *instance_.actions_[k];
        bool reachable_action = true;
        for( index_set::const_iterator it = act.precondition_.begin(); it != act.precondition_.end(); ++it ) {
            if( ((*it > 0) && !reachable_atoms[*it-1]) ||
                ((*it > 0) && static_atoms[*it-1] && neg_literal_in_init[*it-1]) ||
                ((*it < 0) && static_atoms[-*it-1] && pos_literal_in_init[-*it-1]) ) {
                reachable_action = false;
                break;
            }
        }
        if( !reachable_action ) {
            actions_to_remove[k] = true;
        }
    }
}

// Computes reachable atoms, actions, sensors and axioms. Assumes that all entries 
// in the input vectors are false.

void Preprocessor::compute_reachability(bool_vec &reachable_atoms, bool_vec &reachable_actions, bool_vec &reachable_sensors, bool_vec &reachable_axioms) const {
    // initial set of reachable atoms are those in the initial situation
    for( index_set::const_iterator it = instance_.init_.literals_.begin(); it != instance_.init_.literals_.end(); ++it ) {
        if( *it > 0 ) reachable_atoms[*it - 1] = true;
    }

    // extend reachable atoms with those in oneofs
    for( size_t k = 0; k < instance_.init_.oneofs_.size(); ++k ) {
        const Instance::Oneof &oneof = instance_.init_.oneofs_[k];
        for( Instance::Oneof::const_iterator it = oneof.begin(); it != oneof.end(); ++it )
            if( *it > 0 ) reachable_atoms[*it - 1] = true;
    }

    // extend reachable atoms with those in invariants.
    for( size_t k = 0; k < instance_.init_.invariants_.size(); ++k ) {
        const Instance::Invariant &invariant = instance_.init_.invariants_[k];
        for( Instance::Invariant::const_iterator it = invariant.begin(); it != invariant.end(); ++it )
            if( *it > 0 ) reachable_atoms[*it - 1] = true;
    }

    // compute fixed point of reachable atoms using operators, sensors, and axioms.
    // As a side effect, also compute reachable actions
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        fix_point_reached = true;

        // iterate over actions
        for( size_t k = 0; k < instance_.actions_.size(); k++ ) {
            Instance::Action &act = *instance_.actions_[k];
            // check if action is reachable
            bool reachable_action = true;
            for( index_set::const_iterator p = act.precondition_.begin(); p != act.precondition_.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                    reachable_action = false;
                    break;
                }
            }
            if( !reachable_action ) continue;
            reachable_actions[k] = true;

            // add all positive effects
            for( index_set::const_iterator p = act.effect_.begin(); p != act.effect_.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                    reachable_atoms[*p - 1] = true;
                    fix_point_reached = false;
                }
            }

            // add all positive effects for firable conditional effects
            for( Instance::when_vec::const_iterator it = act.when_.begin(); it != act.when_.end(); ++it ) {
                bool reachable_effect = true;
                for( index_set::const_iterator p = it->condition_.begin(); p != it->condition_.end(); ++p ) {
                     if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                         reachable_effect = false;
                         break;
                     }
                }
                if( !reachable_effect ) continue;

                // add all positive effects
                for( index_set::const_iterator p = it->effect_.begin(); p != it->effect_.end(); ++p ) {
                    if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                        reachable_atoms[*p - 1] = true;
                        fix_point_reached = false;
                    }
                }
            }
        }

        // iterate over sensors
        for( size_t k = 0; k < instance_.sensors_.size(); ++k ) {
            Instance::Sensor *r = instance_.sensors_[k];
            assert(!r->sense_.empty());

            bool reachable_sensor = true;
            for( index_set::const_iterator p = r->condition_.begin(); p != r->condition_.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                    reachable_sensor = false;
                    break;
                }
            }
            if( !reachable_sensor ) continue;
            reachable_sensors[k] = true;

            // add sensed atoms to reachable set
            for( index_set::const_iterator p = r->sense_.begin(); p != r->sense_.end(); ++p ) {
                if( *p < 0 ) continue;
                if( !reachable_atoms[*p - 1] ) {
                    reachable_atoms[*p - 1] = true;
                    fix_point_reached = false;
                }
            }
        }

        // iterate over axioms
        for( size_t k = 0; k < instance_.axioms_.size(); ++k ) {
            Instance::Axiom *r = instance_.axioms_[k];
            assert(!r->head_.empty());

            bool reachable_axiom = true;
            for( index_set::const_iterator p = r->body_.begin(); p != r->body_.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                    reachable_axiom = false;
                    break;
                }
            }
            if( !reachable_axiom ) continue;
            reachable_axioms[k] = true;

            // add non-primitive fluents to reachable set
            for( index_set::const_iterator p = r->head_.begin(); p != r->head_.end(); ++p ) {
                assert(*p > 0);
                if( !reachable_atoms[*p - 1] ) {
                    reachable_atoms[*p - 1] = true;
                    fix_point_reached = false;
                }
            }
        }
    }

    // generate feedback
    if( options_.is_enabled("problem:print:atom:reachable") ) {
        cout << Utils::yellow();
        for( size_t k = 0; k < instance_.n_atoms(); k++ )
            if( reachable_atoms[k] ) cout << "  reachable atom " << k << "." << instance_.atoms_[k]->name_ << endl;
        cout << Utils::normal();
    }
    if( options_.is_enabled("problem:print:atom:unreachable") ) {
        cout << Utils::yellow();
        for( size_t k = 0; k < instance_.n_atoms(); k++ )
            if( !reachable_atoms[k] ) cout << "  unreachable atom " << k << "." << instance_.atoms_[k]->name_ << endl;
        cout << Utils::normal();
    }
    if( options_.is_enabled("problem:print:action:unreachable") ) {
        cout << Utils::yellow();
        for( size_t k = 0; k < instance_.actions_.size(); k++ )
            if( !reachable_actions[k] ) cout << "  unreachable action " << k << "." << instance_.actions_[k]->name_ << endl;
        cout << Utils::normal();
    }
    if( options_.is_enabled("problem:print:sensor:unreachable") ) {
        cout << Utils::yellow();
        for( size_t k = 0; k < instance_.sensors_.size(); k++ )
            if( !reachable_sensors[k] ) cout << "  unreachable sensor " << k << "." << instance_.sensors_[k]->name_ << endl;
        cout << Utils::normal();
    }
    if( options_.is_enabled("problem:print:axiom:unreachable") ) {
        cout << Utils::yellow();
        for( size_t k = 0; k < instance_.axioms_.size(); k++ )
            if( !reachable_axioms[k] ) cout << "  unreachable axiom " << k << "." << instance_.axioms_[k]->name_ << endl;
        cout << Utils::normal();
    }
}

// Compute static atoms in problem. An atom is static if its value is not changed by any action.
// Assume that all entries in input vector are false.

void Preprocessor::compute_static_atoms(const bool_vec &reachable_actions, bool_vec &static_atoms) const {
    // get the initial situation
    bool_vec init(instance_.n_atoms(), false);
    for( index_set::const_iterator it = instance_.init_.literals_.begin(); it != instance_.init_.literals_.end(); ++it ) {
        if( *it > 0 ) init[*it - 1] = true;
    }

#if 1
    // atoms in the invariants are non-static
    for( size_t k = 0; k < instance_.init_.invariants_.size(); ++k ) {
        const Instance::Invariant &invariant = instance_.init_.invariants_[k];
        for( Instance::Invariant::const_iterator it = invariant.begin(); it != invariant.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            static_atoms[idx] = false;
        }
    }
#endif

    // atoms in the oneofs are non-static
    // TODO: not sure of this is correct!
    for( size_t k = 0; k < instance_.init_.oneofs_.size(); ++k ) {
        const Instance::Oneof &oneof = instance_.init_.oneofs_[k];
        for( Instance::Oneof::const_iterator it = oneof.begin(); it != oneof.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            static_atoms[idx] = false;
        }
    }

    // negative atoms in the body of axioms are non static
    // atoms in the head of axioms are non static
    // TODO: not sure of this is correct!
    for( size_t k = 0; k < instance_.axioms_.size(); ++k ) {
        const Instance::Axiom &axiom = *instance_.axioms_[k];
        for( index_set::const_iterator it = axiom.body_.begin(); it != axiom.body_.end(); ++it ) {
            if( *it < 0 )
                ;//static_atoms[-*it-1] = false; // TODO: CHECK THIS!
        }
        for( index_set::const_iterator it = axiom.head_.begin(); it != axiom.head_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            static_atoms[idx] = false;
        }
    }

    // an atom is not static if either it is true in init and some action
    // deletes it, or it is false in init and some action adds it
    for( size_t k = 0; k < instance_.actions_.size(); k++ ) {
        if( reachable_actions[k] ) {
            const Instance::Action &act = *instance_.actions_[k];
            for( index_set::const_iterator it = act.effect_.begin(); it != act.effect_.end(); ++it ) {
                if( (*it > 0) && !init[*it-1] )
                    static_atoms[*it - 1] = false;
                else if( (*it < 0) && init[-*it-1] )
                    static_atoms[-*it - 1] = false;
            }

            // conditional effects
            for( size_t i = 0; i < act.when_.size(); ++i ) {
                const Instance::When &when = act.when_[i];
                for( index_set::const_iterator it = when.effect_.begin(); it != when.effect_.end(); ++it ) {
                    if( (*it > 0) && !init[*it-1] )
                        static_atoms[*it-1] = false;
                    else if( (*it < 0) && init[-*it-1] )
                        static_atoms[-*it-1] = false;
                }
            }
        }
    }

    if( options_.is_enabled("problem:print:atom:static") ) {
        cout << Utils::yellow();
        for( size_t k = 0; k < instance_.n_atoms(); k++ ) {
            if( static_atoms[k] )
                cout << "  static atom " << k << "." << instance_.atoms_[k]->name_ << endl;
        }
        cout << Utils::normal();
    }
}

void Preprocessor::compute_action_compilation(Instance::Action &action) {
    // generate candidate literals for completion
    index_vec candidate_literals;
    candidate_literals.reserve(2*instance_.n_atoms());
    for( size_t k = 0; k < instance_.n_atoms(); ++k ) {
        candidate_literals.push_back(1+k);
        candidate_literals.push_back(-(1+k));
    }

    // iterate over candidate literals to check for completion.
    // A completion for literal L and action a (i.e., a completion
    // for (a,L)), is a set S of literals such that:
    //
    //    1) for each conditional effect a : C -> L,
    //
    //       - C contains a literal L' such that -L' belongs to S
    //
    //    2) there is a conditional effect a : L -> -L
    //
    // The first case implies that L is not unconditionally addded
    // If S is a completion of (a,L), then the compilation of S is
    // to add the effect a : S -> -L

    for( size_t k = 0; k < candidate_literals.size(); ++k ) {
        int lit = candidate_literals[k];
        if( action.effect_.contains(lit) ) continue;

        // check first condition while building completion S
        index_set completion;
        bool valid_completion = true;
        for( size_t i = 0; i < action.when_.size(); ++i ) {
            const Instance::When &when = action.when_[i];
            if( when.effect_.contains(lit) ) {
                if( when.condition_.empty() ) {
                    valid_completion = false;
                    break;
                } else {
                    completion.insert(-*when.condition_.begin());
                }
            }
        }
        if( !valid_completion ) continue;

        // check second condition
        valid_completion = false;
        for( size_t i = 0; i < action.when_.size(); ++i ) {
            const Instance::When &when = action.when_[i];
            if( when.condition_.contains(lit) && (when.condition_.size() == 1) && when.effect_.contains(-lit) ) {
                valid_completion = true;
                break;
            }
        }

        // If valid completion, add new conditional effect
        if( valid_completion ) {
            if( options_.is_enabled("problem:print:action-compilation") ) {
                cout << Utils::yellow() << "completion for action=" << action.name_ << " and literal=";
                if( lit > 0 )
                    cout << instance_.atoms_[lit-1]->name_;
                else
                    cout << "(not " << instance_.atoms_[lit-1]->name_ << ")";
                cout << " : ";
                instance_.write_atom_set(cout, completion);
                cout << Utils::normal() << endl;
            }

            if( !completion.empty() ) {
                Instance::When new_ceff;
                new_ceff.condition_ = completion;
                new_ceff.effect_.insert(-lit);
                action.when_.push_back(new_ceff);
            } else {
                action.effect_.insert(-lit);
            }
        }
    }
}

void Preprocessor::compute_relevance(const index_set &check, bool_vec &rel) const {
#if 0
    for( index_set::const_iterator ci = check.begin(); ci != check.end(); ++ci ) {
        if (!rel[*ci])
            rel[*ci] = true;
    }
#endif
}

void Preprocessor::compute_irrelevant_atoms() {
#if 0
    bool_vec relevant;
    compute_relevance(instance_.goal_literals, relevant);
    for( size_t k = 0; k < instance_.n_atoms(); k++ ) {
        assert(k < relevant.size());
        //if( !relevant[k] ) instance_.atoms_[k]->irrelevant = true;
    }
#endif
}

void Preprocessor::remove_irrelevant_atoms() {
#if 0
    bool_vec atoms_to_remove(false, instance_.n_atoms());
    for( size_t k = 0; k < instance_.n_atoms(); k++ )
        ;//if( instance_.atoms_[k]->irrelevant ) atoms_to_remove[k] = true;

    if( trace_level > 0 ) {
        cout << "removing irrelevant atoms..." << endl;
        if( trace_level > 1 ) {
            instance_.write_atom_set(cout, atoms_to_remove);
            cout << endl;
        }
    }

    if( !atoms_to_remove.empty() ) {
        instance_.remove_atoms(atoms_to_remove, atom_map_);
        //remove_useless_actions();

        if( trace_level > 0 ) cout << "re-cross referencing..." << endl;
        instance_.clear_cross_reference();
        instance_.cross_reference();
    }
#endif
}

void Preprocessor::preprocess(bool remove_atoms) {
    int nstage = 0;

    if( options_.is_enabled("problem:print:preprocess:stage") )
        cout << Utils::yellow() << "Preprocessing..." << Utils::normal() << endl;

    // stage: Remove inconsistent and useless actions
    bool_vec actions_to_remove(instance_.n_actions(), false);
    if( options_.is_enabled("problem:print:preprocess:stage") ) {
        cout << Utils::yellow() << "  Stage " << ++nstage << ": "
             << "removing inconsistent & useless actions..."
             << Utils::normal() << endl;
    }
    mark_inconsistent_actions(actions_to_remove);
    mark_useless_actions(actions_to_remove);
    instance_.remove_actions(actions_to_remove, action_map_);


    // stage: Compute reachable atoms, actions, sensors and axioms
    if( options_.is_enabled("problem:print:preprocess:stage") ) {
        cout << Utils::yellow() << "  Stage " << ++nstage << ": "
             << "computing reachability..."
             << Utils::normal() << endl;
    }
    bool_vec reachable_atoms(instance_.n_atoms(), false);
    bool_vec reachable_actions(instance_.n_actions(), false);
    bool_vec reachable_sensors(instance_.n_sensors(), false);
    bool_vec reachable_axioms(instance_.n_axioms(), false);
    compute_reachability(reachable_atoms, reachable_actions, reachable_sensors, reachable_axioms);


    // stage: remove unreachable conditional effects, axioms and sensors, and
    // compute static atoms until fix point.
    if( options_.is_enabled("problem:print:preprocess:stage") ) {
        cout << Utils::yellow() << "  Stage " << ++nstage << ": "
             << "removing unreachable conditional effects, axioms and sensors..."
             << Utils::normal() << endl;
    }
    bool_vec static_atoms(instance_.n_atoms(), false);
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        fix_point_reached = true;
        if( options_.is_enabled("problem:print:preprocess:stage") )
            cout << Utils::yellow() << "           new iteration..." << Utils::normal() << endl;

        instance_.remove_unreachable_conditional_effects(reachable_atoms, static_atoms);
        instance_.remove_unreachable_axioms(reachable_atoms, static_atoms);
        instance_.remove_unreachable_sensors(reachable_atoms, static_atoms);

        // compute static atoms
        bool_vec static_atoms_aux(instance_.n_atoms(), true);
        compute_static_atoms(reachable_actions, static_atoms_aux);

        // mark as non-static all non-primitive and observable fluents
        instance_.calculate_non_primitive_and_observable_fluents();
        for( index_set::const_iterator it = instance_.non_primitive_fluents_.begin(); it != instance_.non_primitive_fluents_.end(); ++it ) {
            assert(*it >= 0);
            static_atoms[*it] = static_atoms_aux[*it] = false;
        }
        for( index_set::const_iterator it = instance_.observable_fluents_.begin(); it != instance_.observable_fluents_.end(); ++it ) {
            assert(*it >= 0);
            static_atoms[*it] = static_atoms_aux[*it] = false;
        }

        // recompute rechability
        bool_vec reachable_atoms_aux(instance_.n_atoms(), false);
        bool_vec reachable_actions_aux(instance_.n_actions(), false);
        bool_vec reachable_sensors_aux(instance_.n_sensors(), false);
        bool_vec reachable_axioms_aux(instance_.n_axioms(), false);
        compute_reachability(reachable_atoms_aux, reachable_actions_aux, reachable_sensors_aux, reachable_axioms_aux);

        // check fix point
        if( (static_atoms != static_atoms_aux) ||
            (reachable_atoms != reachable_atoms_aux) ||
            (reachable_actions != reachable_actions_aux) ||
            (reachable_sensors != reachable_sensors_aux) ||
            (reachable_axioms != reachable_axioms_aux) ) {
            fix_point_reached = false;
            static_atoms = static_atoms_aux;
            reachable_atoms = reachable_atoms_aux;
            reachable_actions = reachable_actions_aux;
            reachable_sensors = reachable_sensors_aux;
            reachable_axioms = reachable_axioms_aux;
        }
    }

    // If everything is correct, there should be no unreachable axioms or sensors.
    for( int k = 0; k < (int)instance_.n_axioms(); ++k ) {
        if( !reachable_axioms[k] ) {
            cout << Utils::error() << "unreachable axiom after fix-point calculation" << endl;
            exit(-1);
        }
    }
    for( int k = 0; k < (int)instance_.n_sensors(); ++k ) {
        if( !reachable_sensors[k] ) {
            cout << Utils::error() << "unreachable sensor after fix-point calculation" << endl;
            exit(-1);
        }
    }


    // stage: Remove unreachable and useless actions
    if( options_.is_enabled("problem:print:preprocess:stage") ) {
        cout << Utils::yellow() << "  Stage " << ++nstage << ": "
             << "removing unreachable actions..."
             << Utils::normal() << endl;
    }
    reachable_actions.bitwise_complement();
    mark_useless_actions(reachable_actions);
    mark_unreachable_actions(reachable_atoms, static_atoms, reachable_actions);
    instance_.remove_actions(reachable_actions, action_map_);


    // stage: Simplify conditions and invariants
    if( options_.is_enabled("problem:print:preprocess:stage") ) {
        cout << Utils::yellow() << "  Stage " << ++nstage << ": "
             << "simplify conditions and invariants..."
             << Utils::normal() << endl;
    }
    instance_.simplify_conditions_and_invariants(reachable_atoms, static_atoms);


    // stage: Remove unreachable and 'known' static atoms
    if( options_.is_enabled("problem:print:preprocess:stage") ) {
        cout << Utils::yellow() << "  Stage " << ++nstage << ": "
             << "removing unreachable and static atoms..."
             << Utils::normal() << endl;
    }
    bool_vec atoms_to_remove(instance_.n_atoms(), false);
    for( index_set::const_iterator it = instance_.init_.literals_.begin(); it != instance_.init_.literals_.end(); ++it )
        atoms_to_remove[*it > 0 ? *it-1 : -*it-1] = true;
    atoms_to_remove.bitwise_and(static_atoms);
    reachable_atoms.bitwise_complement();
    atoms_to_remove.bitwise_or(reachable_atoms);

#if 0
    // make sure we don't remove unreachable goals and hidden fluents!
    for( index_set::const_iterator it = instance_.goal_literals_.begin(); it != instance_.goal_literals_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        //if( atoms_to_remove[idx] == true ) cout << instance_.atoms_[idx]->name_ << endl;
        atoms_to_remove[idx] = false;
    }

    for( size_t k = 0; k < instance_.n_sensors(); ++k ) {
        const Instance::Sensor &r = *instance_.sensors_[k];
        for( index_set::const_iterator it = r.sense_.begin(); it != r.sense_.end(); ++it ) {
            assert(*it > 0);
            //assert(atoms_to_remove[*it-1] == false);
            atoms_to_remove[*it-1] = false;
        }
    }

    for( size_t k = 0; k < instance_.init_.invariants_.size(); ++k ) {
        const Instance::Invariant &invariant = instance_.init_.invariants_[k];
        for( Instance::Invariant::const_iterator it = invariant.begin(); it != invariant.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            //assert(atoms_to_remove[idx] == false);
            atoms_to_remove[idx] = false;
        }
    }

    for( size_t k = 0; k < instance_.init_.oneofs_.size(); ++k ) {
        const Instance::Oneof &oneof = instance_.init_.oneofs_[k];
        for( Instance::Oneof::const_iterator it = oneof.begin(); it != oneof.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            //assert(atoms_to_remove[idx] == false);
            atoms_to_remove[idx] = false;
        }
    }
#endif

    if( remove_atoms && !atoms_to_remove.empty() )
        instance_.remove_atoms(atoms_to_remove, atom_map_);

    // recalculate non-primitive and observable atoms
    instance_.calculate_non_primitive_and_observable_fluents();

#if 0 // This old stuff. It should not be necessary
    // stage: Create deductive rules
    if( options_.is_enabled("problem:print:preprocess:stage") ) {
        cout << Utils::yellow() << "  Stage " << ++nstage << ": "
             << "computing deductive rules..." << endl;
    }
    instance_.create_deductive_rules();
#endif

    // stage: Perform action compilation. This is only valid for k-replanner.
    if( options_.is_enabled("problem:action-compilation") ) {
        if( options_.is_enabled("problem:print:preprocess:stage") ) {
            cout << Utils::yellow() << "  Stage " << ++nstage << ": "
                 << "performing action compilation for " << instance_.n_actions() << " action(s) ..."
                 << Utils::normal() << endl;
        }
        for( size_t k = 0; k < instance_.n_actions(); ++k )
            compute_action_compilation(*instance_.actions_[k]);
    }

    // stage: cross reference
    if( options_.is_enabled("problem:print:preprocess:stage") ) {
        cout << Utils::yellow() << "  Stage " << ++nstage << ": "
             << "computing cross references..."
             << Utils::normal() << endl;
    }
    instance_.cross_reference();
}

