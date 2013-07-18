#include <iostream>
#include "solver.h"
#include "classical_planner.h"

using namespace std;

bool Solver::solve(const State &initial_hidden_state,
                   Instance::Plan &final_plan,
                   vector<vector<int> > &fired_sensors,
                   vector<vector<int> > &sensed_literals) const {
    vector<State> assumption_vec;
    State hidden(initial_hidden_state), state;
    Instance::Plan plan;
    vector<int> sensors, sensed;

    // close hidden state with deductive rule.
    // (Disabled since if hidden is not corect, result is a propositional
    // model of invariants that can be unintended hidden state.)
    //instance_.apply_deductive_rules(hidden);

    // set initial state
    kp_instance_.set_initial_state(state);
    compute_and_add_observations(hidden, state, sensors, sensed);
    fired_sensors.push_back(sensors);
    sensed_literals.push_back(sensed);
    sensors.clear();
    sensed.clear();

    if( options_.is_enabled("print:solver:steps") ) {
        cout << ">>> initial state=";
        state.print(cout, kp_instance_);
        cout << endl << ">>> initial hidden=";
        hidden.print(cout, instance_);
        cout << endl;
    }

    // plan/replan loop
    final_plan.clear();
    size_t planner_calls = 0;
    while( !state.goal(kp_instance_) ) {

        // obtain plan for state
        int status = planner_.get_plan(state, plan);
        if( status != ClassicalPlanner::SOLVED ) {
            if( status == ClassicalPlanner::NO_SOLUTION )
                return NO_SOLUTION;
            else
                return ERROR;
        } else if( planner_.get_time() > time_bound_ ) {
            return TIME;
        }
        assert(!plan.empty());
        calculate_relevant_assumptions(plan, state, assumption_vec);
        ++planner_calls;

        if( options_.is_enabled("print:solver:plan") ) {
            cout << "Classical plan:" << endl;
            int step = 0;
            for( Instance::Plan::const_iterator a = plan.begin(); a != plan.end(); ++a, ++step ) {
                cout << "    step " << step << ": "
                     << *a << "." << kp_instance_.actions[*a]->name
                     << endl;
            }
        }
        if( options_.is_enabled("print:solver:assumptions") ) {
            cout << "Assumptions:" << endl;
            for( size_t k = 0; k < assumption_vec.size(); ++k ) {
                cout << "    step " << k << ": ";
                assumption_vec[k].print(cout, kp_instance_);
                cout << endl;
            }
        }

        // apply plan until an inconsistency is found or termination
        for( size_t k = 0; k < plan.size(); ++k ) {
            const Instance::Action &kp_act = *kp_instance_.actions[plan[k]];

            if( options_.is_enabled("print:solver:steps") ) {
                cout << ">>> x0-act=" << kp_act.name << endl;
            }

            assert(state.applicable(kp_act));
            state.apply(kp_act);
            if( !kp_instance_.is_obs_rule(plan[k]) && !kp_instance_.is_static_rule(plan[k]) ) {
                // insert action into final plan
                final_plan.push_back(plan[k]);
                //cout << "ACTION: " << instance_.actions[plan[k]]->name << endl;

                // apply action at hidden state
                const Instance::Action &act = *instance_.actions[kp_instance_.remap_[plan[k]]];
                if( !hidden.applicable(act) ) {
                    cout << "warning: action " << act.name //<< "[k=" << k << ", idx=" << plan[k] << "]"
                         << " isn't applicable at hidden state: "
                         << "check whether hidden specification is correct!"
                         << endl;

                    //cout << endl << "Plan:" << endl;
                    //for( Instance::Plan::const_iterator a = plan.begin(); a != plan.end(); ++a )
                    //    cout << "  " << kp_instance_.actions[*a]->name << endl;
                    //cout << "HIDDEN="; hidden.print(cout, instance_); cout << endl;
                    //cout << "STATE="; state.print(cout, kp_instance_); cout << endl << endl;

                    return ERROR;
                }
                hidden.apply(act);
                //instance_.apply_deductive_rules(hidden);
                compute_and_add_observations(hidden, state, sensors, sensed);
                fired_sensors.push_back(sensors);
                sensed_literals.push_back(sensed);
                sensors.clear();
                sensed.clear();
                //cout << "HIDDEN="; hidden.print(cout, instance_); cout << endl;

                if( options_.is_enabled("print:solver:steps") ) {
                    cout << ">>> state=";
                    state.print(cout, kp_instance_);
                    cout << endl << ">>> hidden=";
                    hidden.print(cout, instance_);
                    cout << endl;
                }

                // check for consistency of remaining plan
                if( inconsistent(state, assumption_vec, k+1) ) {
                    if( options_.is_enabled("print:solver:inconsistency") ||
                        options_.is_enabled("print:solver:inconsistency:details") ) {
                        cout << "*** inconsistency found with action "
                             << plan[k+1] << "." << kp_instance_.actions[plan[k+1]]->name
                             << endl;
                        if( options_.is_enabled("print:solver:inconsistency:details") ) {
                            cout << "    details:" << endl;
                            cout << "        state=";
                            state.print(cout, kp_instance_);
                            cout << endl << "        hidden=";
                            hidden.print(cout, instance_);
                            cout << endl;
                            for( size_t l = k+1; l < assumption_vec.size(); ++l ) {
                                cout << "        support[layer=" << l << "]=";
                                assumption_vec[l].print(cout, kp_instance_);
                                cout << endl;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }

    if( options_.is_enabled("print:solver:steps") ) {
        cout << " state=";
        state.print(cout, kp_instance_);
        cout << endl;
    }

    return SOLVED;
}

void Solver::calculate_relevant_assumptions(const Instance::Plan &plan,
                                            const State &state,
                                            vector<State> &assumption_vec) const {
    State final_state;
    kp_instance_.apply_plan(plan, state, final_state, assumption_vec);
}

void Solver::compute_and_add_observations(const State &hidden,
                                          State &state,
                                          vector<int> &sensors,
                                          vector<int> &sensed) const {
    // fire observation rules
    index_set observations;
    for( size_t k = 0; k < instance_.n_sensors(); ++k ) {
        const Instance::Sensor &r = *instance_.sensors[k];
        if( hidden.satisfy(r.condition) ) {
            sensors.push_back(k);
            for( index_set::const_iterator it = r.sensed.begin(); it != r.sensed.end(); ++it ) {
                assert(*it > 0);
                int obs = *it - 1;
                if( hidden.satisfy(obs) ) {
                    state.add(2*obs);
                    sensed.push_back(1 + obs);
                } else {
                    state.add(2*obs+1);
                    sensed.push_back(-(1 + obs));
                }
            }
        }
    }

    // compute the deductive closure with respect to the invariants
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        State old_state(state);
        for( size_t k = kp_instance_.first_deductive_action(); k < kp_instance_.last_deductive_action(); ++k ) {
            const Instance::Action &act = *kp_instance_.actions[k];
            if( state.applicable(act) ) {
                state.apply(act);
            }
        }
        fix_point_reached = old_state == state;
    }
}

bool Solver::inconsistent(const State &state, const vector<State> &assumption_vec, size_t k) const {
    bool verbose = options_.is_enabled("print:solver:consistency:check");
    for( State::const_iterator it = state.begin(); it != state.end(); ++it ) {
        int atom = *it/2;

        if( verbose ) {
            cout << "*** checking consistency of " << instance_.atoms[atom]->name << ": ";
        }

        if( instance_.is_observable(atom) ) {
            int comp = *it%2 == 0 ? *it + 1 : *it - 1;
            for( size_t i = k; i < assumption_vec.size(); ++i ) {
                if( assumption_vec[i].satisfy(comp) ) {
                    if( verbose ) cout << "inconsistent!" << endl;
                    return true;
                }
            }
            if( verbose ) cout << "consistent!" << endl;
        } else {
            if( verbose ) cout << " ok [not checked since not observable]" << endl;
        }
    }
    return false;
}

