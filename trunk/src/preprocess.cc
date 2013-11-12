#include <cassert>
#include <list>
#include <stdlib.h>
#include "preprocess.h"

using namespace std;

// TODO: implement proper cross-references (and update functions) and
//       relevance of atoms wrt goal

Preprocessor::Preprocessor(Instance &ins, const Options::Mode &options)
  : instance_(ins), options_(options) {
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
        Instance::Action &act = *instance_.actions[k];

        // check for inconsistencies in add and del
        for( index_set::const_iterator it = act.effect.begin(); it != act.effect.end(); ++it ) {
            if( act.effect.contains(-*it) ) {
                actions_to_remove[k] = true;
                break;
            }
        }

        // check for inconsistencies in conditional effects
        if( !actions_to_remove[k] ) {
            for( int i = 0; i < (int)act.when.size(); ++i ) {
                Instance::When &when = act.when[i];
                for( index_set::const_iterator it = when.effect.begin(); it != when.effect.end(); ++it ) {
                    if( when.effect.contains(-*it) ) {
                        act.when[i] = act.when.back();
                        act.when.pop_back();
                        --i;
                        break;
                    }
                }
            }
        }

        if( actions_to_remove[k] && options_.is_enabled("print:action:inconsistent") ) {
            cout << "  action " << k << "." << act.name << " is inconsistent." << endl;
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
        Instance::Action &act = *instance_.actions[k];

        // remove useless conditional effects
        for( int i = 0; i < (int)act.when.size(); ++i ) {
            bool useless_effect = true;
            for( index_set::const_iterator it = act.when[i].effect.begin(); it != act.when[i].effect.end(); ++it ) {
                if( !act.when[i].condition.contains(*it) ) {
                    useless_effect = false;
                    break;
                }
            }

            if( useless_effect ) {
                act.when[i] = act.when.back();
                act.when.pop_back();
                --i;
            }
        }

        // remove useless actions
        if( act.when.empty() ) {
            for( index_set::const_iterator it = act.effect.begin(); it != act.effect.end(); ++it ) {
                if( !act.precondition.contains(*it) ) {
                    useless[k] = false;
                    break;
                }
            }
        } else {
            useless[k] = false;
        }

        if( useless[k] ) {
            actions_to_remove[k] = true;
            if( options_.is_enabled("print:action:useless") )
                cout << "  action " << k << "." << act.name << " is useless." << endl;
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
    for( index_set::const_iterator it = instance_.init.literals.begin(); it != instance_.init.literals.end(); ++it ) {
        if( *it > 0 )
            pos_literal_in_init[*it - 1] = true;
        else
            neg_literal_in_init[-*it - 1] = true;
    }

    // iterate over actions and their conditional effects.
    for( size_t k = 0; k < instance_.actions.size(); ++k ) {
        Instance::Action &act = *instance_.actions[k];
        bool reachable_action = true;
        for( index_set::const_iterator it = act.precondition.begin(); it != act.precondition.end(); ++it ) {
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
    for( index_set::const_iterator it = instance_.init.literals.begin(); it != instance_.init.literals.end(); ++it ) {
        if( *it > 0 ) reachable_atoms[*it - 1] = true;
    }

    // extend reachable atoms with those in oneofs
    for( size_t k = 0; k < instance_.init.oneofs.size(); ++k ) {
        const Instance::Oneof &oneof = instance_.init.oneofs[k];
        for( Instance::Oneof::const_iterator it = oneof.begin(); it != oneof.end(); ++it )
            if( *it > 0 ) reachable_atoms[*it - 1] = true;
    }

    // extend reachable atoms with those in invariants.
    for( size_t k = 0; k < instance_.init.invariants.size(); ++k ) {
        const Instance::Invariant &invariant = instance_.init.invariants[k];
        for( Instance::Invariant::const_iterator it = invariant.begin(); it != invariant.end(); ++it )
            if( *it > 0 ) reachable_atoms[*it - 1] = true;
    }

    // compute fixed point of reachable atoms using operators, sensors, and axioms.
    // As a side effect, also compute reachable actions
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        fix_point_reached = true;

        // iterate over actions
        for( size_t k = 0; k < instance_.actions.size(); k++ ) {
            Instance::Action &act = *instance_.actions[k];
            // check if action is reachable
            bool reachable_action = true;
            for( index_set::const_iterator p = act.precondition.begin(); p != act.precondition.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                    reachable_action = false;
                    break;
                }
            }
            if( !reachable_action ) continue;
            reachable_actions[k] = true;

            // add all positive effects
            for( index_set::const_iterator p = act.effect.begin(); p != act.effect.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                    reachable_atoms[*p - 1] = true;
                    fix_point_reached = false;
                }
            }

            // add all positive effects for firable conditional effects
            for( Instance::when_vec::const_iterator it = act.when.begin(); it != act.when.end(); ++it ) {
                bool reachable_effect = true;
                for( index_set::const_iterator p = it->condition.begin(); p != it->condition.end(); ++p ) {
                     if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                         reachable_effect = false;
                         break;
                     }
                }
                if( !reachable_effect ) continue;

                // add all positive effects
                for( index_set::const_iterator p = it->effect.begin(); p != it->effect.end(); ++p ) {
                    if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                        reachable_atoms[*p - 1] = true;
                        fix_point_reached = false;
                    }
                }
            }
        }

        // iterate over sensors
        for( size_t k = 0; k < instance_.sensors.size(); ++k ) {
            Instance::Sensor *r = instance_.sensors[k];
            assert(!r->sense.empty());

            bool reachable_sensor = true;
            for( index_set::const_iterator p = r->condition.begin(); p != r->condition.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                    reachable_sensor = false;
                    break;
                }
            }
            if( !reachable_sensor ) continue;
            reachable_sensors[k] = true;

            // add sensed atoms to reachable set
            for( index_set::const_iterator p = r->sense.begin(); p != r->sense.end(); ++p ) {
                assert(*p > 0);
                if( !reachable_atoms[*p - 1] ) {
                    reachable_atoms[*p - 1] = true;
                    fix_point_reached = false;
                }
            }
        }

        // iterate over axioms
        for( size_t k = 0; k < instance_.axioms.size(); ++k ) {
            Instance::Axiom *r = instance_.axioms[k];
            assert(!r->head.empty());

            bool reachable_axiom = true;
            for( index_set::const_iterator p = r->body.begin(); p != r->body.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p - 1] ) {
                    reachable_axiom = false;
                    break;
                }
            }
            if( !reachable_axiom ) continue;
            reachable_axioms[k] = true;

            // add non-primitive fluents to reachable set
            for( index_set::const_iterator p = r->head.begin(); p != r->head.end(); ++p ) {
                assert(*p > 0);
                if( !reachable_atoms[*p - 1] ) {
                    reachable_atoms[*p - 1] = true;
                    fix_point_reached = false;
                }
            }
        }
    }

    // generate feedback
    if( options_.is_enabled("print:atom:reachable") ) {
        for( size_t k = 0; k < instance_.n_atoms(); k++ )
            if( reachable_atoms[k] ) cout << "  reachable atom " << k << "." << instance_.atoms[k]->name << endl;
    }
    if( options_.is_enabled("print:atom:unreachable") ) {
        for( size_t k = 0; k < instance_.n_atoms(); k++ )
            if( !reachable_atoms[k] ) cout << "  unreachable atom " << k << "." << instance_.atoms[k]->name << endl;
    }
    if( options_.is_enabled("print:action:unreachable") ) {
        for( size_t k = 0; k < instance_.actions.size(); k++ )
            if( !reachable_actions[k] ) cout << "  unreachable action " << k << "." << instance_.actions[k]->name << endl;
    }
    if( options_.is_enabled("print:sensor:unreachable") ) {
        for( size_t k = 0; k < instance_.sensors.size(); k++ )
            if( !reachable_sensors[k] ) cout << "  unreachable sensor " << k << "." << instance_.sensors[k]->name << endl;
    }
    if( options_.is_enabled("print:axiom:unreachable") ) {
        for( size_t k = 0; k < instance_.axioms.size(); k++ )
            if( !reachable_axioms[k] ) cout << "  unreachable axiom " << k << "." << instance_.axioms[k]->name << endl;
    }
}

// Compute static atoms in problem. An atom is static if its value is not changed by any action.
// Assume that all entries in input vector are false.

void Preprocessor::compute_static_atoms(const bool_vec &reachable_actions, bool_vec &static_atoms) const {
    // get the initial situation
    bool_vec init(instance_.n_atoms(), false);
    for( index_set::const_iterator it = instance_.init.literals.begin(); it != instance_.init.literals.end(); ++it ) {
        if( *it > 0 ) init[*it - 1] = true;
    }

#if 0
    // atoms in the invariants are non-static
    for( size_t k = 0; k < instance_.init.invariants.size(); ++k ) {
        const Instance::Invariant &invariant = instance_.init.invariants[k];
        for( Instance::Invariant::const_iterator it = invariant.begin(); it != invariant.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            static_atoms[idx] = false;
        }
    }
#endif

    // atoms in the oneofs are non-static
    // TODO: not sure of this is correct!
    for( size_t k = 0; k < instance_.init.oneofs.size(); ++k ) {
        const Instance::Oneof &oneof = instance_.init.oneofs[k];
        for( Instance::Oneof::const_iterator it = oneof.begin(); it != oneof.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            static_atoms[idx] = false;
        }
    }

    // negative atoms in the body of axioms are non static
    // atoms in the head of axioms are non static
    // TODO: not sure of this is correct!
    for( size_t k = 0; k < instance_.axioms.size(); ++k ) {
        const Instance::Axiom &axiom = *instance_.axioms[k];
        for( index_set::const_iterator it = axiom.body.begin(); it != axiom.body.end(); ++it ) {
            if( *it < 0 )
                ;//static_atoms[-*it-1] = false; // TODO: CHECK THIS!
        }
        for( index_set::const_iterator it = axiom.head.begin(); it != axiom.head.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            static_atoms[idx] = false;
        }
    }

    // an atom is not static if either it is true in init and some action
    // deletes it, or it is false in init and some action adds it
    for( size_t k = 0; k < instance_.actions.size(); k++ ) {
        if( reachable_actions[k] ) {
            const Instance::Action &act = *instance_.actions[k];
            for( index_set::const_iterator it = act.effect.begin(); it != act.effect.end(); ++it ) {
                if( (*it > 0) && !init[*it-1] )
                    static_atoms[*it - 1] = false;
                else if( (*it < 0) && init[-*it-1] )
                    static_atoms[-*it - 1] = false;
            }

            // conditional effects
            for( size_t i = 0; i < act.when.size(); ++i ) {
                const Instance::When &when = act.when[i];
                for( index_set::const_iterator it = when.effect.begin(); it != when.effect.end(); ++it ) {
                    if( (*it > 0) && !init[*it-1] )
                        static_atoms[*it-1] = false;
                    else if( (*it < 0) && init[-*it-1] )
                        static_atoms[-*it-1] = false;
                }
            }
        }
    }

    if( options_.is_enabled("print:atom:static") ) {
        for( size_t k = 0; k < instance_.n_atoms(); k++ ) {
            if( static_atoms[k] )
                cout << "  static atom " << k << "." << instance_.atoms[k]->name << endl;
        }
    }
}

void Preprocessor::compute_action_completion(Instance::Action &action) {
    // generate candidate literals for completion
    index_vec candidate_literals;
    candidate_literals.reserve(2*instance_.n_atoms());
    for( size_t k = 0; k < instance_.n_atoms(); ++k ) {
        candidate_literals.push_back(1+k);
        candidate_literals.push_back(-(1+k));
    }

    // iterate over candidate literals to check for completion.
    // A completion for literal L and action a is a set S of
    // literals such that:
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
        if( action.effect.contains(lit) ) continue;

        // check first condition while building completion S
        index_set completion;
        bool valid_completion = true;
        for( size_t i = 0; i < action.when.size(); ++i ) {
            const Instance::When &when = action.when[i];
            if( when.effect.contains(lit) ) {
                if( when.condition.empty() ) {
                    valid_completion = false;
                    break;
                } else {
                    completion.insert(-*when.condition.begin());
                }
            }
        }
        if( !valid_completion ) continue;

        // check second sondition
        valid_completion = false;
        for( size_t i = 0; i < action.when.size(); ++i ) {
            const Instance::When &when = action.when[i];
            if( when.condition.contains(lit) && (when.condition.size() == 1) && when.effect.contains(-lit) ) {
                valid_completion = true;
                break;
            }
        }

        // If valid completion, add new conditional effect
        if( valid_completion ) {
            if( options_.is_enabled("print:literal-completion") ) {
                cout << "completion for action=" << action.name << " and literal=";
                if( lit > 0 )
                    cout << instance_.atoms[lit-1]->name;
                else
                    cout << "(not " << instance_.atoms[lit-1]->name << ")";
                cout << " : ";
                instance_.write_atom_set(cout, completion);
                cout << endl;
            }

            if( !completion.empty() ) {
                Instance::When new_ceff;
                new_ceff.condition = completion;
                new_ceff.effect.insert(-lit);
                action.when.push_back(new_ceff);
            } else {
                action.effect.insert(-lit);
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
        //if( !relevant[k] ) instance_.atoms[k]->irrelevant = true;
    }
#endif
}

void Preprocessor::remove_irrelevant_atoms() {
#if 0
    bool_vec atoms_to_remove(false, instance_.n_atoms());
    for( size_t k = 0; k < instance_.n_atoms(); k++ )
        ;//if( instance_.atoms[k]->irrelevant ) atoms_to_remove[k] = true;

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






void Preprocessor::preprocess(bool remove_atoms, bool do_action_completion) {
    if( options_.is_enabled("print:preprocess:stage") )
        cout << "Preprocessing..." << endl;

    // stage 1: Remove inconsistent and useless actions
    bool_vec actions_to_remove(instance_.n_actions(), false);
    if( options_.is_enabled("print:preprocess:stage") )
        cout << "  Stage 1: removing inconsistent & useless actions..." << endl;
    mark_inconsistent_actions(actions_to_remove);
    mark_useless_actions(actions_to_remove);
    instance_.remove_actions(actions_to_remove, action_map_);


    // stage 2: Compute reachable atoms, actions, sensors and axioms
    if( options_.is_enabled("print:preprocess:stage") )
        cout << "  Stage 2: computing reachability..." << endl;
    bool_vec reachable_atoms(instance_.n_atoms(), false);
    bool_vec reachable_actions(instance_.n_actions(), false);
    bool_vec reachable_sensors(instance_.n_sensors(), false);
    bool_vec reachable_axioms(instance_.n_axioms(), false);
    compute_reachability(reachable_atoms, reachable_actions, reachable_sensors, reachable_axioms);


    // stage 3: remove unreachable conditional effects, axioms and sensors, and
    // compute static atoms until fix point.
    if( options_.is_enabled("print:preprocess:stage") )
        cout << "  Stage 3: removing unreachable conditions effects..." << endl;
    bool_vec static_atoms(instance_.n_atoms(), false);
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        fix_point_reached = true;
        if( options_.is_enabled("print:preprocess:stage") )
            cout << "           new iteration..." << endl;

        instance_.remove_unreachable_conditional_effects(reachable_atoms, static_atoms);
        instance_.remove_unreachable_axioms(reachable_atoms, static_atoms);
        instance_.remove_unreachable_sensors(reachable_atoms, static_atoms);

        // compute static atoms
        bool_vec static_atoms_aux(instance_.n_atoms(), true);
        compute_static_atoms(reachable_actions, static_atoms_aux);

        // mark as non-static all non-primitive and observable fluents
        instance_.calculate_non_primitive_and_observable_fluents();
        for( index_set::const_iterator it = instance_.non_primitive_fluents.begin(); it != instance_.non_primitive_fluents.end(); ++it ) {
            assert(*it >= 0);
            static_atoms[*it] = static_atoms_aux[*it] = false;
        }
        for( index_set::const_iterator it = instance_.observable_fluents.begin(); it != instance_.observable_fluents.end(); ++it ) {
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
            cout << "error: unreachable axiom after fix-point calculation" << endl;
            exit(-1);
        }
    }
    for( int k = 0; k < (int)instance_.n_sensors(); ++k ) {
        if( !reachable_sensors[k] ) {
            cout << "error: unreachable sensor after fix-point calculation" << endl;
            exit(-1);
        }
    }


    // stage 4: Remove unreachable and useless actions
    if( options_.is_enabled("print:preprocess:stage") )
        cout << "  Stage 4: removing unreachable actions..." << endl;
    reachable_actions.bitwise_complement();
    mark_useless_actions(reachable_actions);
    mark_unreachable_actions(reachable_atoms, static_atoms, reachable_actions);
    instance_.remove_actions(reachable_actions, action_map_);


    // stage 5: Simplify conditions and invariants
    if( options_.is_enabled("print:preprocess:stage") )
        cout << "  Stage 5: simplify conditions and invariants..." << endl;
    instance_.simplify_conditions_and_invariants(reachable_atoms, static_atoms);


    // stage 6: Remove unreachable and 'known' static atoms
    if( options_.is_enabled("print:preprocess:stage") )
        cout << "  Stage 6: removing unreachable and static atoms..." << endl;
    bool_vec atoms_to_remove(instance_.n_atoms(), false);
    for( index_set::const_iterator it = instance_.init.literals.begin(); it != instance_.init.literals.end(); ++it ) {
        atoms_to_remove[*it > 0 ? *it-1 : -*it-1] = true;
    }
    atoms_to_remove.bitwise_and(static_atoms);
    reachable_atoms.bitwise_complement();
    atoms_to_remove.bitwise_or(reachable_atoms);

#if 0
    // make sure we don't remove unreachable goals and hidden fluents!
    for( index_set::const_iterator it = instance_.goal_literals.begin(); it != instance_.goal_literals.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        //if( atoms_to_remove[idx] == true ) cout << instance_.atoms[idx]->name << endl;
        atoms_to_remove[idx] = false;
    }

    for( size_t k = 0; k < instance_.n_sensors(); ++k ) {
        const Instance::Sensor &r = *instance_.sensors[k];
        for( index_set::const_iterator it = r.sense.begin(); it != r.sense.end(); ++it ) {
            assert(*it > 0);
            //assert(atoms_to_remove[*it-1] == false);
            atoms_to_remove[*it-1] = false;
        }
    }

    for( size_t k = 0; k < instance_.init.invariants.size(); ++k ) {
        const Instance::Invariant &invariant = instance_.init.invariants[k];
        for( Instance::Invariant::const_iterator it = invariant.begin(); it != invariant.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            //assert(atoms_to_remove[idx] == false);
            atoms_to_remove[idx] = false;
        }
    }

    for( size_t k = 0; k < instance_.init.oneofs.size(); ++k ) {
        const Instance::Oneof &oneof = instance_.init.oneofs[k];
        for( Instance::Oneof::const_iterator it = oneof.begin(); it != oneof.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            //assert(atoms_to_remove[idx] == false);
            atoms_to_remove[idx] = false;
        }
    }
#endif

    if( remove_atoms && !atoms_to_remove.empty() ) {
        if( options_.is_enabled("print:atom:removal") ) {
            cout << "atoms to remove = ";
            instance_.write_atom_set(cout, atoms_to_remove);
            cout << endl;
        }
        instance_.remove_atoms(atoms_to_remove, atom_map_);
    }


    // recalculate non-primitive and observable atoms
    instance_.calculate_non_primitive_and_observable_fluents();


#if 0 // This old stuff. It should not be necessary
    // stage 7: Create deductive rules
    if( options_.is_enabled("print:preprocess:stage") )
        cout << "  Stage 7: computing deductive rules..." << endl;
    instance_.create_deductive_rules();
#endif


    // stage 7: Perform action completion. This is only valid for k-replanner.
    if( do_action_completion ) {
        if( options_.is_enabled("print:preprocess:stage") )
            cout << "  Stage 7: computing action completion..." << endl;
        for( size_t k = 0; k < instance_.n_actions(); ++k ) {
            compute_action_completion(*instance_.actions[k]);
        }
    }


    // do cross referencing
    instance_.cross_reference();
}

