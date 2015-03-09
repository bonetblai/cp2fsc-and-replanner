#include <iostream>
#include "solver.h"
#include "classical_planner.h"
#include "utils.h"

using namespace std;

int Solver::solve(const State &initial_hidden_state,
                  Instance::Plan &final_plan,
                  vector<vector<int> > &fired_sensors,
                  vector<vector<int> > &sensed_literals) const {
    vector<index_set> assumptions;
    State hidden(initial_hidden_state), state;
    Instance::Plan raw_plan, plan;
    vector<int> sensors, sensed;
    index_set goal_condition;

    // the initial hidden state is already closed with the axioms
    // (see set_initial_state in problem.cc).
    // Axioms appear in k-replanner only in translations of multivalued
    // variable problems when compiling static observables. These axioms
    // are only present in the original problem (instance_) and not in
    // the kp-problem (kp_instance_). The axioms are only used once to
    // complete the initial *hidden* state with the hidden observable
    // fluents.

    // close hidden state with deductive rule.
    // (Disabled since if hidden is not corect, result is a propositional
    // model of invariants that can be unintended hidden state.)
    //instance_.apply_deductive_rules(hidden);

    // set the initial state
    kp_instance_.set_initial_state(state);
    compute_and_add_observations(hidden, state, sensors, sensed);
    fired_sensors.push_back(sensors);
    sensed_literals.push_back(sensed);
    sensors.clear();
    sensed.clear();

    if( options_.is_enabled("solver:print:steps") ) {
        cout << ">>> initial state=";
        state.print(cout, kp_instance_);
        cout << endl << ">>> initial hidden=";
        hidden.print(cout, instance_);
        cout << endl;
    }

    // set goal state with (new-goal). It is used to compute
    // the relevant assumptions of a classical plan that are
    // then used to detect when replanning is necessary.
    kp_instance_.set_goal_condition(goal_condition);

    // plan/replan loop
    final_plan.clear();
    size_t planner_calls = 0;
    while( !state.goal(kp_instance_) ) {

        // obtain plan for state
        int status = planner_.get_plan(state, raw_plan, plan);
        if( status != ClassicalPlanner::SOLVED ) {
            if( status == ClassicalPlanner::NO_SOLUTION )
                return NO_SOLUTION;
            else
                return ERROR;
        } else if( planner_.get_time() > time_bound_ ) {
            return TIME;
        }
        assert(!plan.empty());
        ++planner_calls;

        calculate_relevant_assumptions(plan, raw_plan, state, goal_condition, assumptions);
        assert(plan.size() == assumptions.size());
        if( options_.is_enabled("solver:print:assumptions") ) {
            cout << "Assumptions (sz=" << assumptions.size() << "):" << endl;
            for( size_t k = 0; k < assumptions.size(); ++k ) {
                cout << "    step=" << k << ", "
                     << plan[k] << "." << kp_instance_.actions_[plan[k]]->name_->to_string()
                     << ": ";
                kp_instance_.write_atom_set(cout, assumptions[k]);
                cout << endl;
            }
        }

        // first assumption for reduced plan should be satisfied by current state.
        // If not, there must be an incomplete or invalid specification of hidden
        // state or initial state, or problem with domain
        assert(!assumptions.empty());
        if( !state.satisfy(assumptions[0]) ) {
            cout << Utils::error() << "current state doesn't satisfy first assumption"
                 << " in (reduced) plan: check specification!"
                 << endl;
            return ERROR;
        }

        // likewise, first action in reduced plan should be applied at current state.
        // If not, there must be an incomplete or invalid specification of hidden
        // state or initial state, or problem with domain
        if( !state.applicable(*kp_instance_.actions_[plan[0]]) ) {
            cout << Utils::error() << "first action in reduced plan isn't applicable: check specification!"
                 << endl;
            return ERROR;
        }

        // apply plan until an inconsistency is found or termination
        for( size_t k = 0; k < plan.size(); ++k ) {
            const Instance::Action &kp_act = *kp_instance_.actions_[plan[k]];
            assert(kp_instance_.is_regular_action(kp_act.index_));
            //cout << ">>> kp-action=" << kp_act.name_ << endl;

            // if current state doesn't satisfy corresponding assumption, replan
            if( !state.satisfy(assumptions[k]) || !state.applicable(kp_act) ) break;

            // apply action at state
            if( options_.is_enabled("solver:print:steps") ) {
                cout << ">>> kp-action=" << kp_act.name_;
                if( !kp_instance_.is_subgoaling_rule(plan[k]) )
                    cout << " [action=" << instance_.actions_[kp_instance_.remap_action(plan[k])]->name_ << "]" << endl;
                else
                    cout << " [subgoaling action]" << endl;
            }
            state.apply(kp_act);

            // if action is standard action, insert it into plan, apply it at
            // hidden state and gather observations (if any)
            if( !kp_instance_.is_subgoaling_rule(kp_act.index_) ) {
                size_t action_id = kp_instance_.remap_action(plan[k]);
                final_plan.push_back(action_id);
                const Instance::Action &act = *instance_.actions_[action_id];

                if( !hidden.applicable(act) ) {
                    cout << Utils::error() << "action " << act.name_->to_string()
                         << " isn't applicable at hidden state: "
                         << "check whether hidden specification is correct!"
                         << endl;
                    return ERROR;
                }

                hidden.apply(act);
                //instance_.apply_deductive_rules(hidden);
                compute_and_add_observations(hidden, state, sensors, sensed);
                fired_sensors.push_back(sensors);
                sensed_literals.push_back(sensed);
                sensors.clear();
                sensed.clear();

                if( options_.is_enabled("solver:print:steps") ) {
                    cout << ">>> state=";
                    state.print(cout, kp_instance_);
                    cout << endl << ">>> hidden=";
                    hidden.print(cout, instance_);
                    cout << endl;
                }

#if 0
                // check for consistency of remaining plan
                if( inconsistent(state, assumptions, k+1) ) {
                    if( options_.is_enabled("solver:print:inconsistency") ||
                        options_.is_enabled("solver:print:inconsistency:details") ) {
                        cout << "*** inconsistency found with action "
                             << plan[k+1] << "." << kp_instance_.actions_[plan[k+1]]->name_
                             << endl;
                        if( options_.is_enabled("solver:print:inconsistency:details") ) {
                            cout << "    details:" << endl;
                            cout << "        state=";
                            state.print(cout, kp_instance_);
                            cout << endl << "        hidden=";
                            hidden.print(cout, instance_);
                            cout << endl;
                            for( size_t l = k+1; l < assumptions.size(); ++l ) {
                                cout << "        support[layer=" << l << "]=";
                                assumptions[l].print(cout, kp_instance_);
                                cout << endl;
                            }
                        }
                    }
                    break;
                }
#endif
            }
        }
    }

    if( !hidden.goal(instance_) ) {
        cout << Utils::error() << "kp state is goal but hidden state isn't. Check specification."
             << Utils::normal() << endl;
        return ERROR;
    }

    if( options_.is_enabled("solver:print:steps") ) {
        cout << " state=";
        state.print(cout, kp_instance_);
        cout << endl;
    }

    return SOLVED;
}

void Solver::calculate_relevant_assumptions(const Instance::Plan &plan,
                                            const Instance::Plan &raw_plan,
                                            const State &initial_state,
                                            const index_set &goal,
                                            vector<index_set> &assumptions) const {
    // calculate assumptions for raw plan
    vector<index_set> assumptions_on_raw_plan;
    kp_instance_.calculate_relevant_assumptions(raw_plan, initial_state, goal, assumptions_on_raw_plan);
    assert(raw_plan.size() == assumptions_on_raw_plan.size());

    // extract assumptions for cooked plan
    assumptions.clear();
    assumptions.reserve(plan.size());
    for( size_t k = 0, i = 0; k < raw_plan.size(); ++k, ++i ) {
        while( (k < raw_plan.size()) && (raw_plan[k] != plan[i]) ) ++k;
        assert(((k == raw_plan.size()) && (i == plan.size())) || (raw_plan[k] == plan[i]));
        if( k < raw_plan.size() ) assumptions.push_back(assumptions_on_raw_plan[k]);
    }
    assert(plan.size() == assumptions.size());
}

void Solver::compute_and_add_observations(const State &hidden,
                                          State &state,
                                          vector<int> &sensors,
                                          vector<int> &sensed) const {
    // fire observation rules
    index_set observations;
    for( size_t k = 0; k < instance_.n_sensors(); ++k ) {
        const Instance::Sensor &r = *instance_.sensors_[k];
        if( hidden.satisfy(r.condition_) ) {
            // PURE_LW1: En la version pure-lwq, el valor de los literales observables
            // se debe calcular aqui. Dicho valor se calculaba antes en la accion
            // set-sensing (ver comentario en base.cc).
            //
            // Dichos valores no deben agregarse a ninguno de los estados (en forma
            // de literales). Mas bien, se debe identificar las formulas a ser 
            // agregadas para el Unit-Resolution (UR). Dichas formulas se agregaran
            // abajo.
            sensors.push_back(k);
            for( index_set::const_iterator it = r.sense_.begin(); it != r.sense_.end(); ++it ) {
                int obs = *it > 0 ? *it - 1 : -*it - 1;
                if( hidden.satisfy(obs) ) {
                    state.remove(2*obs + 1);
                    state.add(2*obs);
                    sensed.push_back(1 + obs);
                } else {
                    state.remove(2*obs);
                    state.add(2*obs+1);
                    sensed.push_back(-(1 + obs));
                }
            }
        }
    }

    // compute the deductive closure with respect to the invariants
    // PURE_LW1: Se corre UR con lo observado y las formulas identificadas arriba.
    // Los literales (de estado) que sean inferidos por UR son agregados al
    // estado (que representa el belief state del agente)
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        State old_state(state);
        for( size_t k = kp_instance_.first_deductive_action(); k < kp_instance_.last_deductive_action(); ++k ) {
            const Instance::Action &act = *kp_instance_.actions_[k];
            if( state.applicable(act) ) {
                state.apply(act);
            }
        }
        fix_point_reached = old_state == state;
    }
}

bool Solver::inconsistent(const State &state, const vector<State> &assumptions, size_t k) const {
    bool verbose = options_.is_enabled("solver:print:consistency:check");
    for( State::const_iterator it = state.begin(); it != state.end(); ++it ) {
        int atom = *it/2;

        if( verbose ) {
            cout << "*** checking consistency of " << instance_.atoms_[atom]->name_ << ": ";
        }

        if( instance_.is_observable(atom) ) {
            int comp = *it%2 == 0 ? *it + 1 : *it - 1;
            for( size_t i = k; i < assumptions.size(); ++i ) {
                cout << "assumption: " << assumptions[i] << endl;
                if( assumptions[i].satisfy(comp) ) {
                    if( verbose ) cout << "inconsistent!" << endl;
                    return true;
                }
            }
            if( verbose ) cout << "consistent!" << endl;
        } else {
            if( verbose ) cout << " [not checked since not observable]" << endl;
        }
    }
    return false;
}

