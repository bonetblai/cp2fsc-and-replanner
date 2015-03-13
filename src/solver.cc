#include <iostream>
#include "solver.h"
#include "classical_planner.h"
#include "lw1_problem.h"
#include "utils.h"

using namespace std;

int Solver::solve(const State &initial_hidden_state,
                  Instance::Plan &final_plan,
                  vector<set<int> > &fired_sensors,
                  vector<set<int> > &sensed_literals) const {
    vector<index_set> assumptions;
    State hidden(initial_hidden_state), state;
    Instance::Plan raw_plan, plan;
    set<int> sensors, sensed;
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
    if( translation_type_ != LW1 )
        compute_and_add_observations(hidden, state, sensors, sensed);
    apply_inference(0, sensed, state);
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
                if( (translation_type_ != LW1) || !sensed.empty() )
                    apply_inference(&kp_act, sensed, state);
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
                                          set<int> &sensors,
                                          set<int> &sensed) const {
    assert(sensors.empty());
    assert(sensed.empty());

    // fire observation rules
    index_set observations;
    for( size_t k = 0; k < instance_.n_sensors(); ++k ) {
        const Instance::Sensor &r = *instance_.sensors_[k];
        if( hidden.satisfy(r.condition_) ) {
            // PURE-LW1: En la version pure-lwq, el valor de los literales observables
            // se debe calcular aqui. Dicho valor se calculaba antes en la accion
            // set-sensing (ver comentario en base.cc).
            //
            // Dichos valores no deben agregarse a ninguno de los estados (en forma
            // de literales). Mas bien, se debe identificar las formulas a ser 
            // agregadas para el Unit-Resolution (UR). Dichas formulas se agregaran
            // abajo.
            sensors.insert(k);
            for( index_set::const_iterator it = r.sense_.begin(); it != r.sense_.end(); ++it ) {
                int obs = *it > 0 ? *it - 1 : -*it - 1;
                if( hidden.satisfy(obs) ) {
                    state.remove(2*obs + 1);
                    state.add(2*obs);
                    sensed.insert(1 + obs);
                } else {
                    state.remove(2*obs);
                    state.add(2*obs+1);
                    sensed.insert(-(1 + obs));
                }
            }
        }
    }
}

void Solver::apply_inference(const Instance::Action *last_action,
                             const set<int> &sensed,
                             State &state) const {

    cout << Utils::magenta() << ">>> state before inference=";
    state.print(cout, kp_instance_);
    cout << Utils::normal() << endl;

    if( translation_type_ == LW1 ) {
        if( options_.is_enabled("lw1:inference:up") ) {
            assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
            const LW1_Instance &lw1 = *static_cast<const LW1_Instance*>(&kp_instance_);

            // find sensing models for given action that are incompatible with observations
            map<int, vector<const vector<vector<int> >*> > relevant_sensing_models;
            if( last_action != 0 ) {
                // compute action-key for accessingn sensing models in lw1 instance
                string action_key;
                size_t pos = last_action->name_->to_string().find("__set_sensing__");
                if( pos != string::npos ) {
                    action_key = string(last_action->name_->to_string(), 0, pos);
                    pos = string::npos;
                } else {
                    pos = last_action->name_->to_string().find("__effect__");
                }
                if( pos != string::npos ) {
                    action_key = string(last_action->name_->to_string(), 0, pos);
                    pos = string::npos;
                } else {
                    pos = last_action->name_->to_string().find("__turn_on_sensor__");
                }
                if( pos != string::npos ) {
                    action_key = string(last_action->name_->to_string(), 0, pos);
                    pos = string::npos;
                }
                assert(action_key != "");

                // fill in relevant sensing models
                const map<int, map<int, vector<vector<int> > > > *sensing_models_for_action = 0;
                if( lw1.sensing_models_.find(action_key) != lw1.sensing_models_.end() )
                    sensing_models_for_action = &lw1.sensing_models_.find(action_key)->second;

                for( set<int>::const_iterator it = sensed.begin(); it != sensed.end(); ++it ) {
                    int sensed_literal = *it;
                    int atom_index = sensed_literal < 0 ? -sensed_literal - 1 : sensed_literal - 1;
                    bool negated = sensed_literal < 0;

                    if( options_.is_enabled("solver:print:sensed-literals") ) {
                        cout << Utils::yellow()
                             << "sensed: literal="
                             << (negated ? "(not " : "")
                             << lw1.po_instance_.atoms_[atom_index]->name_
                             << (negated ? ")" : "")
                             << ", index=" << atom_index
                             << Utils::normal() << endl;
                    }

                    map<int, vector<int> >::const_iterator jt = lw1.variables_for_atom_.find(atom_index);
                    assert(jt != lw1.variables_for_atom_.end());
                    assert(!jt->second.empty());

                    // collect sensing models for values incompatible with obs.
                    // For binary vars (i.e. w/ domain of size 1), need to
                    // consider complemented value explicitly
                    for( size_t k = 0; k < jt->second.size(); ++k ) {
                        int var_key = jt->second[k];
                        const LW1_Instance::Variable &variable = *lw1.multivalued_variables_[var_key];
                        if( variable.is_state_variable_ ) continue;

                        assert(sensing_models_for_action != 0);
                        assert(sensing_models_for_action->find(var_key) != sensing_models_for_action->end());
                        const map<int, vector<vector<int> > > &sensing_models_for_var = sensing_models_for_action->find(var_key)->second;

                        if( variable.domain_.size() == 1 ) {
                            int value_key_for_complemented_literal = negated ? atom_index + 1 : -(atom_index + 1);
                            map<int, vector<vector<int> > >::const_iterator kt = sensing_models_for_var.find(value_key_for_complemented_literal);
                            if( kt != sensing_models_for_var.end() )
                                relevant_sensing_models[sensed_literal].push_back(&kt->second);
                        } else {
                            int value_key = !negated ? atom_index + 1 : -(atom_index + 1);
                            for( map<int, vector<vector<int> > >::const_iterator kt = sensing_models_for_var.begin(); kt != sensing_models_for_var.end(); ++kt ) {
                                if( kt->first != value_key )
                                    relevant_sensing_models[sensed_literal].push_back(&kt->second);
                            }
                        }
                    }
                }
            }

            // construct logical theory for performing inference with unit propagation
#if UP
            Inference::Propositional::CNF cnf;
#endif

            // 1. Positive literals from state
            for( State::const_iterator it = state.begin(); it != state.end(); ++it ) {
#if UP
                Inference::Propositional::Clause cl;
                cl.push_back(1 + *it); // NOTA: en implementacion de clause, 'push_back' es un 'insert'
                cnf.push_back(cl);
#endif
            }

            // 2. Axioms: D'
            for( vector<vector<int> >::const_iterator it = lw1.clauses_for_axioms_.begin(); it != lw1.clauses_for_axioms_.end(); ++it ) {
#if UP
                Inference::Propositional::Clause cl;
                const vector<int> &clause = *it;
                for( size_t k = 0; k < clause.size(); ++k )
                    cl.push_back(clause[k]);
                cnf.push_back(cl);
#endif
            }

            // 3. Clauses from sensing models: K_o
            for( map<int, vector<const vector<vector<int> >*> >::const_iterator it = relevant_sensing_models.begin(); it != relevant_sensing_models.end(); ++it ) {
                const vector<const vector<vector<int> >*> &sensing_models = it->second;
                for( size_t k = 0; k < sensing_models.size(); ++k ) {
                    const vector<vector<int> > &cnf_for_sensing_model = *sensing_models[k];
                    for( size_t j = 0; j < cnf_for_sensing_model.size(); ++j ) {
                        const vector<int> &clause = cnf_for_sensing_model[j];
#if UP
                        Inference::Propositional::Clause cl;
                        for( size_t i = 0; i < clause.size(); ++i )
                            cl.push_back(clause[i]);
                        cnf.push_back(cl);
#endif
                    }
                }
            }

            // 4. Kept (extra) static clauses
            // CHECK: MISSING

            // inference
#if UP
            Inference::Propositional::CNF result;
#endif
            if( options_.is_enabled("lw1:inference:up:1-lookahead") ) {
                cout << Utils::error() << "inference method 'lw1:inference:up:1-lookahead' not yet implemented" << endl;
                exit(255);
            } else {
#if UP
                Inference::Propositional::UnitPropagation up;
                up.reduce(cnf, result);
#endif
            }

            // insert positive literals from result into state
#if UP
            for( size_t k = 0; k < result.size(); ++k ) {
                const Inference::Propositional::Clause &clause = result[k];
                if( clause.size() == 1 ) {
                    int literal = *clause.begin();
                    assert(literal != 0);
                    if( literal > 0 ) {
                        state.add(literal - 1);
                    }
                }
            }
#endif

            // PROVISIONAL: TO BE REMOVED WHEN UP INFERENCE IS WORKING
            bool fix_point_reached = false;
            while( !fix_point_reached ) {
                State old_state(state);
                for( size_t k = kp_instance_.first_deductive_action(); k < kp_instance_.last_deductive_action(); ++k ) {
                    const Instance::Action &act = *kp_instance_.actions_[k];
                    if( state.applicable(act) )
                        state.apply(act);
                }
                fix_point_reached = old_state == state;
            }
        } else {
            cout << Utils::error() << "unspecified inference method for lw1" << endl;
            exit(255);
        }
    } else {
        // translation_type is either K_REPLANNER or CLG. 

        // compute deductive closure with respect to invariants (for K-replanner and clg)
        bool fix_point_reached = false;
        while( !fix_point_reached ) {
            State old_state(state);
            for( size_t k = kp_instance_.first_deductive_action(); k < kp_instance_.last_deductive_action(); ++k ) {
                const Instance::Action &act = *kp_instance_.actions_[k];
                if( state.applicable(act) )
                    state.apply(act);
            }
            fix_point_reached = old_state == state;
        }
    }

    cout << Utils::green() << ">>> state  after inference=";
    state.print(cout, kp_instance_);
    cout << Utils::normal() << endl;
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

