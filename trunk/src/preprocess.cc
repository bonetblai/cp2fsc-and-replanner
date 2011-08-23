#include <assert.h>
#include <list>
#include "preprocess.h"

using namespace std;

// TODO: implement proper cross-references (and update functions)
//       relevance of atoms wrt goal

Preprocessor::Preprocessor(Instance &ins, const Verbosity::Mode &vmode)
  : instance(ins), verbosity_mode(vmode) {
    for( size_t k = 0; k < instance.n_atoms(); k++ ) atom_map.push_back(k);
    for( size_t k = 0; k < instance.n_actions(); k++ ) action_map.push_back(k);
    for( size_t k = 0; k < instance.n_sensors(); k++ ) sensor_map.push_back(k);
    for( size_t k = 0; k < instance.n_axioms(); k++ ) axiom_map.push_back(k);
}

Preprocessor::~Preprocessor() {
}

void Preprocessor::compute_reachability(bool_vec &reachable_atoms, bool_vec &reachable_actions, bool_vec &reachable_sensors, bool_vec &reachable_axioms) const {
    // assumes that input vectors are all initially false

    // initial set of reachable atoms are those in the initial situation
    for( index_set::const_iterator it = instance.init.literals.begin(); it != instance.init.literals.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            reachable_atoms[idx] = true;
    }

    // extend reachable atoms with those in invariants
    for( size_t k = 0; k < instance.init.invariants.size(); ++k ) {
        const index_vec &invariant = instance.init.invariants[k];
        for( index_vec::const_iterator it = invariant.begin(); it != invariant.end(); ++it ) {
            if( *it > 0 ) {
                reachable_atoms[*it - 1] = true;
            }
        }
    }

    // extend reachable atoms with those in oneofs
    for( size_t k = 0; k < instance.init.oneofs.size(); ++k ) {
        const index_vec &oneof = instance.init.oneofs[k];
        for( index_vec::const_iterator it = oneof.begin(); it != oneof.end(); ++it ) {
            if( *it > 0 ) {
                reachable_atoms[*it - 1] = true;
            }
        }
    }

    // compute fixed point of reachable atoms using operators and axioms.
    // As a side effect, also compute reachable actions
    bool change = true;
    while( change ) {
        change = false;

        // iterate over actions
        for( size_t k = 0; k < instance.actions.size(); k++ ) {
            Instance::Action &act = *instance.actions[k];
            // check if action is reachable
            bool reachable = true;
            for( index_set::const_iterator p = act.precondition.begin(); p != act.precondition.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p-1] ) {
                    reachable = false;
                    break;
                }
            }
            if( !reachable ) continue;
            reachable_actions[k] = true;

            // add all positive effects
            for( index_set::const_iterator p = act.effect.begin(); p != act.effect.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p-1] ) {
                    reachable_atoms[*p-1] = true;
                    change = true;
                }
            }

            // add all positive effects for firable conditional effects
            for( Instance::when_vec::const_iterator it = act.when.begin(); it != act.when.end(); ++it ) {
                bool reachable = true;
                for( index_set::const_iterator p = it->condition.begin(); p != it->condition.end(); ++p ) {
                     if( (*p > 0) && !reachable_atoms[*p-1] ) {
                         reachable = false;
                         break;
                     }
                }
                if( !reachable ) continue;

                // add all positive effects
                for( index_set::const_iterator p = it->effect.begin(); p != it->effect.end(); ++p ) {
                    if( (*p > 0) && !reachable_atoms[*p-1] ) {
                        reachable_atoms[*p-1] = true;
                        change = true;
                        //cout << "atom " << *p-1 << " " << instance.atoms[*p-1]->name << " is reachable!" << endl;
                        //instance.write_atom_set(cout, it->condition);
                        //cout << endl;
                    }
                }
            }
        }

        // iterate over sensors
        for( size_t k = 0; k < instance.sensors.size(); ++k ) {
            Instance::Sensor *r = instance.sensors[k];
            assert(!r->sensed.empty());

            bool reachable = true;
            for( index_set::const_iterator p = r->condition.begin(); p != r->condition.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p-1] ) {
                    reachable = false;
                    break;
                }
            }
            if( !reachable ) continue;
            reachable_sensors[k] = true;

            // add sensed atoms to reachable set
            for( index_set::const_iterator p = r->sensed.begin(); p != r->sensed.end(); ++p ) {
                assert(*p > 0);
                if( !reachable_atoms[*p-1] ) {
                    reachable_atoms[*p-1] = true;
                    change = true;
                }
            }
        }

        // iterate over axioms
        for( size_t k = 0; k < instance.axioms.size(); ++k ) {
            Instance::Axiom *r = instance.axioms[k];
            assert(!r->head.empty());

            bool reachable = true;
            for( index_set::const_iterator p = r->body.begin(); p != r->body.end(); ++p ) {
                if( (*p > 0) && !reachable_atoms[*p-1] ) {
                    reachable = false;
                    break;
                }
            }
            if( !reachable ) continue;
            reachable_axioms[k] = true;

            // add non-primitive fluents to reachable set
            for( index_set::const_iterator p = r->head.begin(); p != r->head.end(); ++p ) {
                assert(*p > 0);
                if( !reachable_atoms[*p-1] ) {
                    reachable_atoms[*p-1] = true;
                    change = true;
                }
            }
        }
    }

    if( verbosity_mode.is_enabled("print:atom:unreachable") ) {
        for( size_t k = 0; k < instance.n_atoms(); k++ ) {
            if( !reachable_atoms[k] )
                cout << "  unreachable atom " << instance.atoms[k]->name << endl;
        }
    }
    if( verbosity_mode.is_enabled("print:action:unreachable") ) {
        for( size_t k = 0; k < instance.actions.size(); k++ ) {
            if( !reachable_actions[k] )
                cout << "  unreachable action " << instance.actions[k]->name << endl;
        }
    }
    if( verbosity_mode.is_enabled("print:sensor:unreachable") ) {
        for( size_t k = 0; k < instance.sensors.size(); k++ ) {
            if( !reachable_sensors[k] )
                cout << "  unreachable sensor " << instance.sensors[k]->name << endl;
        }
    }
    if( verbosity_mode.is_enabled("print:axiom:unreachable") ) {
        for( size_t k = 0; k < instance.axioms.size(); k++ ) {
            if( !reachable_axioms[k] )
                cout << "  unreachable axiom " << instance.axioms[k]->name << endl;
        }
    }
}

void Preprocessor::compute_static_atoms(const bool_vec &reachable_actions, bool_vec &static_atoms) const {
    // assumes that inpput static_atoms is all true

    // get the initial situation
    bool_vec init(instance.n_atoms(), false);
    for( index_set::const_iterator it = instance.init.literals.begin(); it != instance.init.literals.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            init[idx] = true;
    }

    // atoms in the invariants are non-static
    for( size_t k = 0; k < instance.init.invariants.size(); ++k ) {
        const index_vec &invariant = instance.init.invariants[k];
        for( index_vec::const_iterator it = invariant.begin(); it != invariant.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            static_atoms[idx] = false;
        }
    }

    // atoms in the oneofs are non-static
    for( size_t k = 0; k < instance.init.oneofs.size(); ++k ) {
        const index_vec &oneof = instance.init.oneofs[k];
        for( index_vec::const_iterator it = oneof.begin(); it != oneof.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            static_atoms[idx] = false;
        }
    }

    // negative atoms in the body of axioms are non static
    // atoms in the head of axioms are non static
    for( size_t k = 0; k < instance.axioms.size(); ++k ) {
        const Instance::Axiom &axiom = *instance.axioms[k];
        for( index_set::const_iterator it = axiom.body.begin(); it != axiom.body.end(); ++it ) {
            if( *it < 0 )
                ;//static_atoms[-*it-1] = false; // TODO: CHECK THIS!
        }
        for( index_set::const_iterator it = axiom.head.begin(); it != axiom.head.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            static_atoms[idx] = false;
        }
    }

    // an atom is not static either if it is true in init and some action
    // deletes it, or it is false in init and some action adds it
    for( size_t k = 0; k < instance.actions.size(); k++ ) {
        if( reachable_actions[k] ) {
            const Instance::Action &act = *instance.actions[k];
            for( index_set::const_iterator it = act.effect.begin(); it != act.effect.end(); ++it ) {
                if( (*it > 0) && !init[*it-1] )
                    static_atoms[*it-1] = false;
                else if( (*it < 0) && init[-*it-1] )
                    static_atoms[-*it-1] = false;
            }

            // conditional effects
            for( size_t i = 0; i < act.when.size(); ++i ) {
                const Instance::When &when = act.when[i];
                for( index_set::const_iterator it = when.condition.begin(); it != when.condition.end(); ++it ) {
                    if( *it < 0 )
                        static_atoms[-*it-1] = false;
                }
                for( index_set::const_iterator it = when.effect.begin(); it != when.effect.end(); ++it ) {
                    if( (*it > 0) && !init[*it-1] )
                        static_atoms[*it-1] = false;
                    else if( (*it < 0) && init[-*it-1] )
                        static_atoms[-*it-1] = false;
                }
            }
        }
    }

    if( verbosity_mode.is_enabled("print:atom:static") ) {
        for( size_t k = 0; k < instance.n_atoms(); k++ ) {
            if( static_atoms[k] )
                cout << "  static atom " << k << "." << instance.atoms[k]->name << endl;
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
    bool_vec relevant;
    compute_relevance(instance.goal_literals, relevant);
    for( size_t k = 0; k < instance.n_atoms(); k++ ) {
        assert(k < relevant.size());
        //if( !relevant[k] ) instance.atoms[k]->irrelevant = true;
    }
}

void Preprocessor::remove_inconsistent_actions() {
    bool_vec inconsistent(instance.n_actions(), false);
    for( size_t k = 0; k < instance.n_actions(); k++ ) {
        Instance::Action &act = *instance.actions[k];

        // check for inconsistencies in add and del
        for( index_set::const_iterator it = act.effect.begin(); it != act.effect.end(); ++it ) {
            if( act.effect.contains(-*it) ) {
                inconsistent[k] = true;
                break;
            }
        }

        // check for inconsistencies in conditional effects
        if( !inconsistent[k] ) {
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

        if( inconsistent[k] && verbosity_mode.is_enabled("print:action:inconsistent") ) {
            cout << "  action " << act.name << " is inconsistent." << endl;
        }
    }
    instance.remove_actions(inconsistent, action_map);
}

void Preprocessor::remove_useless_effects_and_actions() {
    bool_vec useless(instance.n_actions(), true);
    for( size_t k = 0; k < instance.n_actions(); k++ ) {
        Instance::Action &act = *instance.actions[k];

        // remove useless conditional effects
        for( int i = 0; i < (int)act.when.size(); ++i ) {
            int delsz = 0;
            for( index_set::const_iterator it = act.when[i].effect.begin(); it != act.when[i].effect.end(); ++it )
                delsz += *it < 0 ? 1 : 0;
            bool useless_effect = delsz == 0;
            if( !useless_effect ) continue;
            for( index_set::const_iterator it = act.when[i].effect.begin(); it != act.when[i].effect.end(); ++it ) {
                if( (*it > 0) && !act.when[i].condition.contains(*it) ) {
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
        int delsz = 0;
        for( index_set::const_iterator it = act.effect.begin(); it != act.effect.end(); ++it )
            delsz += *it < 0 ? 1 : 0;
        if( (delsz == 0) && act.when.empty() ) {
            for( index_set::const_iterator it = act.effect.begin(); it != act.effect.end(); ++it ) {
                if( (*it > 0) && !act.precondition.contains(*it) ) {
                    useless[k] = false;
                    break;
                }
            }
        } else
            useless[k] = false;

        if( useless[k] && verbosity_mode.is_enabled("print:action:useless") ) {
            cout << "  action " << act.name << " is useless." << endl;
        }
    }
    instance.remove_actions(useless, action_map);
}

void Preprocessor::remove_irrelevant_atoms() {
#if 0
    bool_vec atoms_to_remove(false, instance.n_atoms());
    for( size_t k = 0; k < instance.n_atoms(); k++ )
        ;//if( instance.atoms[k]->irrelevant ) atoms_to_remove[k] = true;

    if( trace_level > 0 ) {
        cout << "removing irrelevant atoms..." << endl;
        if( trace_level > 1 ) {
            instance.write_atom_set(cout, atoms_to_remove);
            cout << endl;
        }
    }

    if( !atoms_to_remove.empty() ) {
        instance.remove_atoms(atoms_to_remove, atom_map);
        //remove_useless_actions();

        if( trace_level > 0 ) cout << "re-cross referencing..." << endl;
        instance.clear_cross_reference();
        instance.cross_reference();
    }
#endif
}

void Preprocessor::preprocess(bool remove_atoms, const bool_vec *known_non_static_atoms) {
    assert((known_non_static_atoms == 0) || (known_non_static_atoms->size() == instance.n_atoms()));

    // stage 1: Remove inconsistent and useless actions
    if( verbosity_mode.is_enabled("print:preprocess:stage") )
        cout << "  Stage 1: removing inconsistent & useless actions..." << endl;
    remove_inconsistent_actions();
    remove_useless_effects_and_actions();

    // after action removal, compute cross references
    if( verbosity_mode.is_enabled("print:preprocess:stage") )
        cout << "           cross referencing..." << endl;
    instance.cross_reference();

    // stage 2: Compute reachable atoms, actions, sensors and axioms
    if( verbosity_mode.is_enabled("print:preprocess:stage") )
        cout << "  Stage 2: computing reachability..." << endl;
    bool_vec reachable_atoms(instance.n_atoms(), false);
    bool_vec reachable_actions(instance.n_actions(), false);
    bool_vec reachable_sensors(instance.n_sensors(), false);
    bool_vec reachable_axioms(instance.n_axioms(), false);
    compute_reachability(reachable_atoms, reachable_actions, reachable_sensors, reachable_axioms);

    // stage 3: remove unreachable conditional effects and compute static atoms until fix point
    if( verbosity_mode.is_enabled("print:preprocess:stage") )
        cout << "  Stage 3: removing unreachable conditions effects..." << endl;
    bool_vec static_atoms(instance.n_atoms(), false);
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        if( verbosity_mode.is_enabled("print:preprocess:stage") )
            cout << "           new iteration..." << endl;
        fix_point_reached = true;
        instance.remove_unreachable_conditional_effects(reachable_atoms, static_atoms);
        instance.remove_unreachable_axioms(reachable_atoms, static_atoms);
        bool_vec static_atoms_aux(instance.n_atoms(), true);
        compute_static_atoms(reachable_actions, static_atoms_aux);
        if( known_non_static_atoms != 0 ) {
            static_atoms_aux.bitwise_complement();
            static_atoms_aux.bitwise_or(*known_non_static_atoms);
            static_atoms_aux.bitwise_complement();
        }

        // mark as non-static all non-primitive and observable fluents
        instance.set_non_primitive_and_observable_fluents();
        for( index_set::const_iterator it = instance.non_primitive_fluents.begin(); it != instance.non_primitive_fluents.end(); ++it ) {
            assert(*it >= 0);
            static_atoms[*it] = false;
            static_atoms_aux[*it] = false;
        }
        for( index_set::const_iterator it = instance.observable_fluents.begin(); it != instance.observable_fluents.end(); ++it ) {
            assert(*it >= 0);
            static_atoms[*it] = false;
            static_atoms_aux[*it] = false;
        }

        // check achievement of fix-point
        if( static_atoms != static_atoms_aux ) {
            fix_point_reached = false;
            static_atoms = static_atoms_aux;
        }
    }
    //cout << "FIX POINT REACHED!" << endl;

#if 0
    cout << "Static atoms = ";
    instance.write_atom_set(cout, static_atoms);
    cout << endl;
#endif
 
#if 0
    // stage 4: Compute static atoms
    if( trace_level > 0 ) cout << "  computing static atoms..." << endl;
    bool_vec static_atoms(instance.n_atoms(), true);
    compute_static_atoms(reachable_actions, static_atoms);
    if( known_non_static_atoms != 0 ) {
        static_atoms.bitwise_complement();
        static_atoms.bitwise_or(*known_non_static_atoms);
        static_atoms.bitwise_complement();
    }

    // mark as non-static all non-primitive and observable fluents
    instance.set_non_primitive_and_observable_fluents();
    for( index_set::const_iterator it = instance.non_primitive_fluents.begin(); it != instance.non_primitive_fluents.end(); ++it ) {
        assert(*it >= 0);
        static_atoms[*it] = false;
    }
    for( index_set::const_iterator it = instance.observable_fluents.begin(); it != instance.observable_fluents.end(); ++it ) {
        assert(*it >= 0);
        static_atoms[*it] = false;
    }
#endif

    // stage 5: Remove unreachable actions and conditional effects
    if( verbosity_mode.is_enabled("print:preprocess:stage") )
        cout << "  Stage 5: removing unreachable actions..." << endl;
    reachable_actions.bitwise_complement();
    instance.remove_actions(reachable_actions, action_map);
    instance.simplify_conditional_effects(static_atoms);

    // stage 5: Remove unreachable sensors
    if( verbosity_mode.is_enabled("print:preprocess:stage") )
        cout << "           removing unreachable sensors..." << endl;
    reachable_sensors.bitwise_complement();
    instance.remove_sensors(reachable_sensors, sensor_map);

    // stage 6: Remove unreachable axioms
#if 0 // TODO: this is all a mess...
    if( trace_level > 0) cout << "  removing unreachable axioms..." << endl;
    reachable_axioms.bitwise_complement();
    instance.remove_axioms(reachable_axioms, axiom_map);
#endif

    // after action removal, compute cross references
    if( verbosity_mode.is_enabled("print:preprocess:stage") )
        cout << "           cross referencing..." << endl;
    instance.cross_reference();

    // stage 7: Remove unreachable and static atoms
    if( verbosity_mode.is_enabled("print:preprocess:stage") )
        cout << "  Stage 7: removing unreachable and static atoms..." << endl;
    bool_vec atoms_to_remove(static_atoms);
    reachable_atoms.bitwise_complement();
    atoms_to_remove.bitwise_or(reachable_atoms);

    // make sure we don't remove unreachable goals and hidden fluents!
    for( index_set::const_iterator it = instance.goal_literals.begin(); it != instance.goal_literals.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        //if( atoms_to_remove[idx] == true ) cout << instance.atoms[idx]->name << endl;
        atoms_to_remove[idx] = false;
    }

    for( size_t k = 0; k < instance.n_sensors(); ++k ) {
        const Instance::Sensor &r = *instance.sensors[k];
        for( index_set::const_iterator it = r.sensed.begin(); it != r.sensed.end(); ++it ) {
            assert(*it > 0);
            //assert(atoms_to_remove[*it-1] == false);
            atoms_to_remove[*it-1] = false;
        }
    }

    for( size_t k = 0; k < instance.init.invariants.size(); ++k ) {
        const index_vec &invariant = instance.init.invariants[k];
        for( index_vec::const_iterator it = invariant.begin(); it != invariant.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            //assert(atoms_to_remove[idx] == false);
            atoms_to_remove[idx] = false;
        }
    }

    for( size_t k = 0; k < instance.init.oneofs.size(); ++k ) {
        const index_vec &oneof = instance.init.oneofs[k];
        for( index_vec::const_iterator it = oneof.begin(); it != oneof.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            //assert(atoms_to_remove[idx] == false);
            atoms_to_remove[idx] = false;
        }
    }

    if( remove_atoms && !atoms_to_remove.empty() ) {
        if( verbosity_mode.is_enabled("print:atom:removal") ) {
            cout << "atoms to remove = ";
            instance.write_atom_set(cout, atoms_to_remove);
            cout << endl;
        }
        instance.remove_atoms(atoms_to_remove, atom_map);
        remove_useless_effects_and_actions();
    }

    // after action removal, compute cross references
    if( verbosity_mode.is_enabled("print:preprocess:stage") )
        cout << "           cross referencing..." << endl;
    instance.cross_reference();

    // set observable atoms
    instance.set_non_primitive_and_observable_fluents();
}

