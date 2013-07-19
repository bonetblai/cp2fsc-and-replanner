#include <cassert>
#include <cstdlib>
#include "kp_problem.h"
#include "state.h"

using namespace std;

KP_Instance::KP_Instance(const Instance &ins, const Options::Mode &options)
  : Instance(options), po_instance_(ins),
    n_standard_actions_(0), n_sensor_actions_(0), n_invariant_actions_(0) {

    // set name
    if( dynamic_cast<const InstanceName*>(ins.name) != 0 ) {
        set_name(new InstanceName(*dynamic_cast<const InstanceName*>(ins.name)));
    } else {
        set_name(new CopyName(ins.name->to_string()));
    }

    // create K0 atoms
    atoms.reserve(2*ins.n_atoms());
    for( size_t k = 0; k < ins.n_atoms(); k++ ) {
        string name = ins.atoms[k]->name->to_string();
        new_atom(new CopyName("(K_" + name + ")"));
        new_atom(new CopyName("(K_not_" + name + ")"));
    }

    // set initial atoms
    for( index_set::const_iterator it = ins.init.literals.begin(); it != ins.init.literals.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            init.literals.insert(1 + 2*idx);
        else
            init.literals.insert(1 + 2*idx+1);
    }

    // set goal atoms
    for( index_set::const_iterator it = ins.goal_literals.begin(); it != ins.goal_literals.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            goal_literals.insert(1 + 2*idx);
        else
            goal_literals.insert(1 + 2*idx+1);
    }

    // add known literals in initial situation
    for( size_t k = 0; k < ins.n_atoms(); k++ ) {
        const Atom &atom = *ins.atoms[k];
        if( (init.literals.find(1 + 2*k) == init.literals.end()) &&
            (init.literals.find(1 + 2*k+1) == init.literals.end()) ) {
            // check that atom does not appear in invariants
            bool in_invariant = false;
            for( size_t i = 0; !in_invariant && (i < ins.init.invariants.size()); ++i ) {
                for( size_t j = 0; j < ins.init.invariants[i].size(); ++j ) {
                    int lit = ins.init.invariants[i][j];
                    if( (lit > 0) && ((int)atom.index == lit-1) ) {
                        in_invariant = true;
                        break;
                    }
                }
            }

            // if not in some invariant, add K_not_<atom> to init
            if( !in_invariant ) {
                init.literals.insert(1 + 2*k+1);
                if( options_.is_enabled("print:kp:atom:init") ) {
                    cout << "Atom " << atoms[2*k+1]->name << " added to init" << endl;
                }
            }
        }
    }

    // create K-actions
    remap_ = vector<int>(ins.n_actions(),-1);
    for( size_t k = 0; k < ins.n_actions(); k++ ) {
        const Action &act = *ins.actions[k];
        Action &nact = new_action(new CopyName(act.name->to_string()));
        remap_[k] = k;

        // preconditions
        for( index_set::const_iterator it = act.precondition.begin(); it != act.precondition.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                nact.precondition.insert(1 + 2*idx);
            else
                nact.precondition.insert(1 + 2*idx+1);
        }

        // support and cancellation rules for effects
        for( index_set::const_iterator it = act.effect.begin(); it != act.effect.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 ) {
                nact.effect.insert(1 + 2*idx);
                nact.effect.insert(-(1 + 2*idx+1));
            } else {
                nact.effect.insert(1 + 2*idx+1);
                nact.effect.insert(-(1 + 2*idx));
            }
        }

        // support and cancellation rules for conditional effects
        for( size_t i = 0; i < act.when.size(); ++i ) {
            const When &when = act.when[i];
            When sup_eff, can_eff;
            for( index_set::const_iterator it = when.condition.begin(); it != when.condition.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 ) {
                    sup_eff.condition.insert(1 + 2*idx);
                    can_eff.condition.insert(-(1 + 2*idx+1));
                } else {
                    sup_eff.condition.insert(1 + 2*idx+1);
                    can_eff.condition.insert(-(1 + 2*idx));
                }
            }
            for( index_set::const_iterator it = when.effect.begin(); it != when.effect.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 ) {
                    sup_eff.effect.insert(1 + 2*idx);
                    can_eff.effect.insert(-(1 + 2*idx+1));
                } else {
                    sup_eff.effect.insert(1 + 2*idx+1);
                    can_eff.effect.insert(-(1 + 2*idx));
                }
            }
            nact.when.push_back(sup_eff);
            nact.when.push_back(can_eff);
        }

        if( options_.is_enabled("print:kp:action:regular") ) {
            nact.print(cout, *this);
        }
    }
    n_standard_actions_ = n_actions();

    // create sensor rules
    for( size_t k = 0; k < ins.n_sensors(); k++ ) {
        const Sensor &r = *ins.sensors[k];
        assert(!r.sensed.empty());

        // create common condition
        index_set common_condition;
        for( index_set::const_iterator it = r.condition.begin(); it != r.condition.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                common_condition.insert(1 + 2*idx);
            else
                common_condition.insert(1 + 2*idx+1);
        }

        // generate different rule for every sensed fluent
        int obs = 0;
        for( index_set::const_iterator it = r.sensed.begin(); it != r.sensed.end(); ++it ) {
            assert(*it > 0);
            int idx = *it-1;
            for( size_t n = 0; n < 2; ++n ) {
                ostringstream s;
                s << "sensor-" << r.name->to_string() << "-obs" << obs << "-ver" << n;
                Action &nact = new_action(new CopyName(s.str()));

                // conditional effect
                When c_eff;
                c_eff.condition.insert(common_condition.begin(), common_condition.end());
                c_eff.condition.insert(-(1 + 2*idx));
                c_eff.condition.insert(-(1 + 2*idx+1));
                if( n == 0 ) {
                    c_eff.effect.insert(1 + 2*idx);
                } else {
                    c_eff.effect.insert(1 + 2*idx+1);
                }

                // add conditional effect to rule
                obs_rules_by_name_[nact.name->to_string()] = n_actions();
                nact.when.push_back(c_eff);
                if( options_.is_enabled("print:kp:action:sensor") ) {
                    nact.print(cout, *this);
                }
            }
            ++obs;
        }
    }
    n_sensor_actions_ = n_actions() - n_standard_actions_;

    // create invariant rules
    size_t invariant_no = 0;
    for( invariant_vec::const_iterator it = ins.init.invariants.begin(); it != ins.init.invariants.end(); ++it ) {
        const Invariant &invariant = *it;
        assert(invariant.type == Invariant::AT_LEAST_ONE);

        for( size_t k = 0; k < invariant.size(); ++k ) {
            ostringstream s;
            s << "invariant-" << invariant_no++;
            Action &nact = new_action(new CopyName(s.str()));

            // conditional effects
            When c_eff;
            if( invariant.type == Invariant::AT_LEAST_ONE ) {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k )
                            c_eff.condition.insert(1 + 2*idx+1);
                        else {
                            c_eff.condition.insert(-(1 + 2*idx+1)); // TODO: check if necessary
                            c_eff.effect.insert(1 + 2*idx);
                        }
                    } else {
                        if( i != k )
                            c_eff.condition.insert(1 + 2*idx);
                        else {
                            c_eff.condition.insert(-(1 + 2*idx)); // TODO: check if necessary
                            c_eff.effect.insert(1 + 2*idx+1);
                        }
                    }
                }
            } else {
                // This should be dead code.
                assert(invariant.type == Invariant::AT_MOST_ONE);
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i == k ) {
                            c_eff.condition.insert(1 + 2*idx);
                        } else {
                            c_eff.condition.insert(-(1 + 2*idx)); // TODO: check if necessary
                            c_eff.effect.insert(1 + 2*idx+1);
                        }
                    } else {
                        if( i == k ) {
                            c_eff.condition.insert(1 + 2*idx+1);
                        } else {
                            c_eff.condition.insert(-(1 + 2*idx+1)); // TODO: check if necessary
                            c_eff.effect.insert(1 + 2*idx);
                        }
                    }
                }
            }

            // push conditional effect
            nact.when.push_back(c_eff);
            if( options_.is_enabled("print:kp:action:invariant") ) {
                nact.print(cout, *this);
            }
        }
    }
    n_invariant_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_;
}

KP_Instance::~KP_Instance() {
}

void KP_Instance::cross_reference() {
    size_t k = 0;
    while( k < n_actions() ) {
        if( actions[k]->name->to_string().compare(0, 7, "sensor-") == 0 ) {
            n_standard_actions_ = k;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        if( actions[k]->name->to_string().compare(0, 10, "invariant-") == 0 ) {
            n_sensor_actions_ = k - n_standard_actions_;
            break;
        }
        ++k;
    }
    n_invariant_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_;

    // remap actions into po instance
    for( size_t k = 0; k < n_standard_actions_; ++k ) {
        remap_[k] = -1;
        for( size_t j = 0; j < po_instance_.n_actions(); ++j ) {
            if( actions[k]->name->to_string() == po_instance_.actions[j]->name->to_string() ) {
                remap_[k] = j;
                break;
            }
        }
    }

    Instance::cross_referenced = true;
}

// This function apply given plan at given initial state and returns the final
// state and the assumptions made by the plan. If plan is applicable, returns
// true. Otherwise, returns false.

bool KP_Instance::apply_plan(const Plan &plan, const State &initial_state, State &final_state, vector<State> &assumption_vec) const {
    assumption_vec.clear();
    vector<State> support_vec;

    final_state = initial_state;
    for( size_t k = 0; k < plan.size(); ++k ) {
        const Instance::Action &act = *actions[plan[k]];
        assert(final_state.applicable(act));

        // check that preconditions hold at current state (final_state)
        if( !final_state.satisfy(act.precondition) ) return false;

        State assumption;
        State support;

        // add positive preconditions to support
        for( index_set::const_iterator it = act.precondition.begin(); it != act.precondition.end(); ++it ) {
            if( *it > 0 ) {
                support.add(*it-1);
            }
        }

        // add positive conditions of triggered conditional effects to support and
        // the assumptions made with observations rules
        for( size_t i = 0; i < act.when.size(); ++i ) {
            const Instance::When &w = act.when[i];
            if( final_state.satisfy(w.condition) ) {
                for( index_set::const_iterator it = w.condition.begin(); it != w.condition.end(); ++it ) {
                    if( *it > 0 ) {
                        support.add(*it-1);
                    }
                }
                if( is_obs_rule(plan[k]) ) {
                    for( index_set::const_iterator it = w.effect.begin(); it != w.effect.end(); ++it ) {
                        assert(*it > 0);
                        if( !final_state.satisfy(*it-1) ) {
                            assumption.add(*it-1);
                        }
                    }
                }
            }
        }
        support_vec.push_back(support);
        assumption_vec.push_back(assumption);

        // apply action to state
        final_state.apply(act);
    }

    // calculate and consolidate the relevant assumptions
    assert(support_vec.size() == assumption_vec.size());
    State relevant, support;
    for( int i = assumption_vec.size()-1; i >= 0; --i ) {
        support.add(support_vec[i]);
        for( State::const_iterator it = assumption_vec[i].begin(); it != assumption_vec[i].end(); ++it ) {
            if( support.satisfy(*it) ) {
                relevant.add(*it);
            }
        }
        assumption_vec[i] = relevant;
    }

    return true;
}

