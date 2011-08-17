#include <iostream>
#include "solver.h"
#include "classical_planner.h"

using namespace std;

//#define DEBUG

bool Solver::solve(const State &initial_hidden_state, vector<int> &final_plan) const {
    vector<State> assumption_vec;
    State hidden(initial_hidden_state), state;
    Instance::Plan plan;


    // set initial state
    kp_instance_.set_initial_state(state);
    compute_and_add_observations(hidden, state);

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

#ifdef DEBUG
        cout << "Plan:" << endl;
        for( Instance::Plan::const_iterator a = plan.begin(); a != plan.end(); ++a )
            cout << "  " << *a << "." << kp_instance_.actions[*a]->name << endl;
        cout << "Assumptions:" << endl;
        for( size_t k = 0; k < assumption_vec.size(); ++k ) {
            cout << "  ";
            assumption_vec[k].print(cout, kp_instance_);
            cout << endl;
        }
#endif

        // apply plan until an inconsistency is found or termination
        for( size_t k = 0; k < plan.size(); ++k ) {
            const Instance::Action &kp_act = *kp_instance_.actions[plan[k]];

#ifdef DEBUG
            cout << "state:" << endl << "  "; state.print(cout, kp_instance_); cout << endl;
            cout << "hidden:" << endl << "  "; hidden.print(cout, instance_); cout << endl;
            cout << "x0-act: " << kp_act.name << endl;
#endif

            assert(state.applicable(kp_act));
            state.apply(kp_act);
            if( !kp_instance_.is_obs_rule(plan[k]) && !kp_instance_.is_static_rule(plan[k]) ) {
                // insert action into final plan
                final_plan.push_back(plan[k]);
                //cout << "ACTION: " << instance_.actions[plan[k]]->name << endl;

                // apply action at hidden state
                const Instance::Action &act = *instance_.actions[plan[k]];
                if( !hidden.applicable(act) ) {
                    cout << "warning: action " << act.name
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
                compute_and_add_observations(hidden, state);
                //cout << "HIDDEN="; hidden.print(cout, instance_); cout << endl;

                // check for consistency of remaining plan
                if( inconsistent(state, assumption_vec, k+1) ) {
#ifdef DEBUG
                    cout << "inconsistency found with action " << plan[k+1] << endl;
                    //cout << "STATE:" << endl << "  "; state.print(cout, kp_instance_); cout << endl;
                    //cout << "HIDDEN="; hidden.print(cout, instance_); cout << endl;
                    //cout << "STATE="; state.print(cout, kp_instance_); cout << endl;
                    //for( size_t l = k+1; l < assumption_vec.size(); ++l ) {
                    //    cout << "SUP[" << l << "]="; assumption_vec[l].print(cout, kp_instance_); cout << endl;
                    //}
#endif
                    break;
                }
            }
        }
    }

#ifdef DEBUG
    cout << "FINAL STATE="; state.print(cout, kp_instance_); cout << endl;
#endif

    return SOLVED;
}

void Solver::calculate_relevant_assumptions(const Instance::Plan &plan, const State &state, vector<State> &assumption_vec) const {
    State final_state;
    kp_instance_.apply_plan(plan, state, final_state, assumption_vec);
}

void Solver::compute_and_add_observations(State &hidden, State &state) const {
    // fire observation rules
    index_set observations;
    for( size_t k = 0; k < instance_.n_sensors(); ++k ) {
        const Instance::Sensor &r = *instance_.sensors[k];
        if( hidden.satisfy(r.condition) ) {
            for( index_set::const_iterator it = r.sensed.begin(); it != r.sensed.end(); ++it ) {
                assert(*it > 0);
                int obs = *it-1;
                if( hidden.satisfy(obs) ) {
                    state.add(2*obs);
                } else {
                    state.add(2*obs+1);
                }
            }
        }
    }

    // compute the deductive closure with respect to the invariants
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        State old_state(state);
        for( size_t k = kp_instance_.first_deductive_action(); k < kp_instance_.n_actions(); ++k ) {
            const Instance::Action &act = *kp_instance_.actions[k];
            if( state.applicable(act) )
                state.apply(act);
        }
        fix_point_reached = old_state == state;
    }
}

bool Solver::inconsistent(const State &state, const vector<State> &assumption_vec, size_t k) const {
    for( State::const_iterator it = state.begin(); it != state.end(); ++it ) {
        int atom = *it/2;
#ifdef DEBUG
        cout << "checking consistency of " << instance_.atoms[atom]->name << ": ";
#endif
        if( instance_.is_observable(atom) ) {
            int comp = *it%2 == 0 ? *it + 1 : *it - 1;
            for( size_t i = k; i < assumption_vec.size(); ++i ) {
                if( assumption_vec[i].satisfy(comp) ) {
#ifdef DEBUG
                    cout << "inconsistent!" << endl;
#endif
                    return true;
                }
            }
#ifdef DEBUG
            cout << "consistent!" << endl;
#endif
        } else {
#ifdef DEBUG
            cout << " ok [non-observable]" << endl;
#endif
        }
    }
    return false;
}

