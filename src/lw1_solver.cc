/*
 *  Copyright (C) 2011 - <date> Blai Bonet, Universidad Simon Bolivar
 *
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 *  Blai Bonet, bonet@ldc.usb.ve, bonetblai@gmail.com
 *
 */

#include <cassert>
#include <iostream>

#include "lw1_solver.h"
#include "classical_planner.h"
#include "utils.h"

//#define DEBUG

using namespace std;

void LW1_Solver::compute_and_add_observations(const Instance::Action *last_action,
                                              const STATE_CLASS &hidden,
                                              STATE_CLASS &state,
                                              set<int> &fired_sensors_at_step,
                                              set<int> &sensed_at_step) const {
    assert(fired_sensors_at_step.empty());
    assert(sensed_at_step.empty());

    assert(translation_type_ == LW1);
    assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
    const LW1_Instance &lw1 = *static_cast<const LW1_Instance*>(&kp_instance_);

    if( options_.is_enabled("lw1:strict") && (last_action != 0) ) {
        map<string, set<int> >::const_iterator it = lw1.vars_sensed_by_action_.find(last_action->name_->to_string());
        if( it != lw1.vars_sensed_by_action_.end() ) {
            for( set<int>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                const LW1_Instance::Variable &variable = *lw1.variables_[*jt];
                assert(variable.is_observable());

                // if state variable, the value of observed literal (either true or false)
                // is directly obtained from the hidden state. If non-state variable, need
                // to use sensing model to determine the value. If the domain size is 1,
                // there are only two values for the variable, true or false corresponding
                // to the positive and negative literal respectively. If domain size > 1,
                // each value corresponds to a different literal (from which one and only
                // one must be true).

                if( variable.is_binary() ) {
                    int index = *variable.domain().begin();
                    bool satisfy = value_observable_literal(hidden, *last_action, *jt, index);
                    sensed_at_step.insert(satisfy ? 1 + index : -(1 + index));
                    if( options_.is_enabled("lw1:boost:literals-for-observables") ) {
                        update_state_with_literals_for_observables(state, *last_action, variable, satisfy ? 1 + index : -(1 + index));
                    }
                } else {
                    bool some_value_sensed = false;
                    for( set<int>::const_iterator kt = variable.domain().begin(); kt != variable.domain().end(); ++kt ) {
                        int index = *kt;
                        bool satisfy = value_observable_literal(hidden, *last_action, *jt, index);
                        if( satisfy ) {
                            if( !some_value_sensed ) {
                                sensed_at_step.insert(1 + index);
                                some_value_sensed = true;
                                if( options_.is_enabled("lw1:boost:literals-for-observables") ) {
                                    update_state_with_literals_for_observables(state, *last_action, variable, 1 + index);
                                }
                            } else {
                                cout << Utils::error() << "more than one value sensed for variable '"
                                     << variable.name() << "' with action '"
                                     << last_action->name_->to_string() << "'"
                                     << endl;
                            }
                        }
                    }
                    if( !some_value_sensed ) {
                        cout << Utils::error() << "no value sensed for variable '"
                             << variable.name() << "' with action '"
                             << last_action->name_->to_string() << "'"
                             << endl;
                    }
                }
            }
        }
    } else if( !options_.is_enabled("lw1:strict") ) {
        // fire observation rules
        index_set observations;
        for( size_t k = 0; k < instance_.n_sensors(); ++k ) {
            const Instance::Sensor &r = *instance_.sensors_[k];
            if( hidden.satisfy(r.condition_) ) {
#ifdef DEBUG
                cout << Utils::yellow() << "firing sensor: " << Utils::normal();
                r.print(cout, instance_);
#endif
                fired_sensors_at_step.insert(k);
                for( index_set::const_iterator it = r.sense_.begin(); it != r.sense_.end(); ++it ) {
                    int obs = *it > 0 ? *it - 1 : -*it - 1;
                    bool satisfy = hidden.satisfy(obs);
#ifdef DEBUG
                    if( satisfy ) {
                        cout << Utils::yellow() << "[State] Add inferred literal: ";
                        hidden.print_literal(cout, obs, &kp_instance_);
                        cout << Utils::normal() << endl;
                    }
                    if( !satisfy ) {
                        cout << Utils::yellow() << "[State] Add inferred literal: ";
                        cout << "(not ";
                        hidden.print_literal(cout, obs, &kp_instance_);
                        cout << ")" << Utils::normal() << endl;
                    }
#endif
                    sensed_at_step.insert(satisfy ? 1 + obs : -(1 + obs));
                }
            }
        }
    }

#ifdef DEBUG
    for( set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
        int obs = *it > 0 ? *it - 1 : -*it - 1;
        cout << Utils::yellow() << "sensed: literal=";
        LW1_State::print_literal(cout, *it, &instance_);
        cout << ", index=" << obs << Utils::normal() << endl;
    }
#endif
}

void LW1_Solver::apply_inference(const Instance::Action *last_action,
                                 const set<int> &sensed_at_step,
                                 STATE_CLASS &state) const {
    bool status = inference_engine_.apply_inference(last_action, sensed_at_step, state);
    if( !status ) {
        std::cout << Utils::internal_error() << "inconsistency reached during apply_inference() at state (lw1_solver.cc)" << std::endl;
        exit(-1);
    }
}

bool LW1_Solver::value_observable_literal(const STATE_CLASS &hidden,
                                          const Instance::Action &last_action,
                                          int var_index,
                                          int index) const {
    assert(index >= 0);

    // case when observed variable is not a state variable
    assert(translation_type_ == LW1);
    assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
    const LW1_Instance &lw1 = *static_cast<const LW1_Instance*>(&kp_instance_);
    const LW1_Instance::Variable &variable = *lw1.variables_[var_index];
    string action_key = last_action.name_->to_string();
    //cout << Utils::red() << "XXXXXX.0: index=" << index << ", name="; State::print_literal(cout, 1 + index, &instance_); cout << Utils::normal() << endl;

    // handle easy case when the variable is a state variable
    if( variable.is_state_variable() ) {
#ifdef DEBUG
        cout << Utils::cyan()
             << "Evaluation: action=" << action_key
             << ", variable=" << variable.name()
             << ", value=";
        State::print_literal(cout, 1 + index, &instance_);
        cout << " ==> " << (hidden.satisfy(index) ? "TRUE" : "FALSE")
             << Utils::normal() << endl;
#endif
        return hidden.satisfy(index);
    }
    //cout << "XXXXXX.1" << endl;

    if( lw1.sensing_models_as_dnf_.find(action_key) == lw1.sensing_models_as_dnf_.end() ) {
        cout << Utils::warning() << "no sensing model for action '" << action_key << "'"
             << ": assuming model is constant false!"
             << endl;
        return false;
    }
    const map<int, map<int, vector<vector<int> > > > &sensing_models_for_action = lw1.sensing_models_as_dnf_.at(action_key);
    //cout << "XXXXXX.2" << endl;

    if( sensing_models_for_action.find(var_index) == sensing_models_for_action.end() ) {
        cout << Utils::error() << "no sensing model for variable '"
             << variable.name() << "' for action '"
             << action_key << "'" << endl;
        return false;
    }
    const map<int, vector<vector<int> > > &sensing_models_for_action_and_var = sensing_models_for_action.at(var_index);
    //cout << "XXXXXX.3" << endl;

    if( sensing_models_for_action_and_var.find(1 + index) == sensing_models_for_action_and_var.end() ) {
        // there is no sensing model for this value. Assuming it is false.
        return false;
    }
    const vector<vector<int> > &dnf = sensing_models_for_action_and_var.at(1 + index);
    //cout << Utils::red() << "XXXXXX.4: #terms=" << dnf.size() << Utils::normal() << endl;

    // evaluate dnf at hidden state and return its value
    bool value = false;
    for( size_t k = 0; k < dnf.size(); ++k ) {
        const vector<int> &term = dnf[k];
        bool valid_term = true;
        //cout << Utils::red() << "XXXXXX.5: #lits in term[" << k << "]=" << term.size() << ", validity=" << flush;
        for( size_t j = 0; j < term.size(); ++j ) {
            int literal = term[j];
            if( (literal > 0) && !hidden.satisfy(literal - 1) )
                valid_term = false;
            if( (literal < 0) && hidden.satisfy(-literal - 1) )
                valid_term = false;
            //cout << " " << literal << "."; State::print_literal(cout, literal, &instance_); cout << ":" << (valid_term ? "TRUE" : "FALSE");
            if( !valid_term ) break;
        }
        //cout << Utils::normal() << endl;
        value = value || valid_term;
        if( value ) break;
    }

#ifdef DEBUG
    cout << Utils::cyan()
         << "Evaluation: action=" << action_key
         << ", variable=" << variable.name()
         << ", value=";
    State::print_literal(cout, 1 + index, &instance_);
    cout << " ==> " << (value ? "TRUE" : "FALSE")
         << Utils::normal() << endl;
#endif

    return value;
}

void LW1_Solver::update_state_with_literals_for_observables(STATE_CLASS &state,
                                                            const Instance::Action &action,
                                                            const LW1_Instance::Variable &variable,
                                                            int value) const {
    const LW1_Instance &lw1 = *static_cast<const LW1_Instance*>(&kp_instance_);
    int index = value > 0 ? value - 1 : -value - 1;
    map<string, set<int> >::const_iterator it = lw1.atoms_for_observables_.find(variable.name());
    if( (it != lw1.atoms_for_observables_.end()) && (it->second.find(index) != it->second.end()) ) {
        state.add(value > 0 ? 2*index : 2*index + 1);
#ifdef DEBUG
        cout << Utils::cyan()
             << "Update state with literal for observable: variable=" << variable.name()
             << ", value=" << value
             << ", value-index=" << index
             << ", atom=";
        State::print_literal(cout, value, &lw1.po_instance_);
        cout << endl;
#endif
    }
}

void LW1_Solver::fill_relevant_sensing_models(const LW1_Instance &lw1,
                                              const Instance::Action *last_action,
                                              const set<int> &sensed_at_step,
                                              LW1_Solver::relevant_sensing_models_t &relevant_sensing_models,
                                              bool as_k_cnf) const {
    assert(last_action != 0);

    // compute action-key for accessingn sensing models in lw1 instance
    string action_key;
    if( options_.is_enabled("lw1:strict") ) {
        action_key = last_action->name_->to_string();
    } else {
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
    }
    assert(action_key != "");

    // fill in relevant sensing models
    const map<int, map<int, vector<vector<int> > > > *sensing_models_for_action_as_k_cnf = 0;
    const map<int, map<int, vector<vector<int> > > > *sensing_models_for_action_as_k_dnf = 0;
    if( as_k_cnf ) {
        if( lw1.sensing_models_as_k_cnf_.find(action_key) != lw1.sensing_models_as_k_cnf_.end() )
            sensing_models_for_action_as_k_cnf = &lw1.sensing_models_as_k_cnf_.at(action_key);
    } else {
        if( lw1.sensing_models_as_k_dnf_.find(action_key) != lw1.sensing_models_as_k_dnf_.end() )
            sensing_models_for_action_as_k_dnf = &lw1.sensing_models_as_k_dnf_.at(action_key);
    }

    for( set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
        int sensed_literal = *it;
        int atom_index = sensed_literal < 0 ? -sensed_literal - 1 : sensed_literal - 1;
        bool negated = sensed_literal < 0;

#ifdef DEBUG
        cout << "[fill] sensed: literal=";
        LW1_State::print_literal(cout, sensed_literal, &instance_);
        cout << ", index=" << atom_index << Utils::normal() << endl;
#endif

        if( options_.is_enabled("solver:print:sensed-literals") ) {
            cout << Utils::yellow() << "sensed: literal=";
            LW1_State::print_literal(cout, sensed_literal, &instance_);
            cout << ", index=" << atom_index << Utils::normal() << endl;
        }

        map<int, vector<int> >::const_iterator jt = lw1.variables_for_atom_.find(atom_index);
        assert(jt != lw1.variables_for_atom_.end());
        assert(!jt->second.empty());

        // if as_k_cnf, collect sensing models as k-cnf for values incompatible with obs. Otherwise,
        // collect sensing model as k-dnf for values compatible with obs. For binary vars (i.e. w/
        // domain of size 1), need to consider complemented value explicitly
        for( size_t k = 0; k < jt->second.size(); ++k ) {
            int var_key = jt->second[k];
            const LW1_Instance::Variable &variable = *lw1.variables_[var_key];

            if( variable.is_state_variable() ) {
                relevant_sensing_models[sensed_literal].insert(make_pair(var_key, sensing_models_as_cnf_or_dnf_t()));
                continue;
            }

            // for non-binary variables, the values for observables are positive atoms
            // and these are used to access the sensing models. Hence, we can discard
            // negative observed literals.
            if( (variable.domain().size() > 1) && negated ) continue;

            if( as_k_cnf ) {
                assert(sensing_models_for_action_as_k_cnf != 0);
                const map<int, vector<vector<int> > > &sensing_models_for_var_as_k_cnf = sensing_models_for_action_as_k_cnf->at(var_key);
                for( map<int, vector<vector<int> > >::const_iterator kt = sensing_models_for_var_as_k_cnf.begin(); kt != sensing_models_for_var_as_k_cnf.end(); ++kt ) {
#ifdef DEBUG
                    cout << "[fill] sensing model: obs=";
                    LW1_State::print_literal(cout, kt->first, &instance_);
                    cout << ", trigger=" << (kt->first != sensed_literal) << flush;
#endif
                    if( kt->first != sensed_literal ) {
                        relevant_sensing_models[sensed_literal][var_key].push_back(&kt->second);
#ifdef DEBUG
                        cout << ", k-cnf=";
                        LW1_State::print_cnf_or_dnf(cout, kt->second, &kp_instance_);
#endif
                    }
#ifdef DEBUG
                    cout << endl;
#endif
                }
            } else {
                assert(sensing_models_for_action_as_k_dnf != 0);
                const map<int, vector<vector<int> > > &sensing_models_for_var_as_k_dnf = sensing_models_for_action_as_k_dnf->at(var_key);
                for( map<int, vector<vector<int> > >::const_iterator kt = sensing_models_for_var_as_k_dnf.begin(); kt != sensing_models_for_var_as_k_dnf.end(); ++kt ) {
#ifdef DEBUG
                    cout << "[fill] sensing model: obs=";
                    LW1_State::print_literal(cout, kt->first, &instance_);
                    cout << ", trigger=" << (kt->first != sensed_literal) << flush;
#endif
                    if( kt->first == sensed_literal ) {
                        relevant_sensing_models[sensed_literal][var_key].push_back(&kt->second);
#ifdef DEBUG
                        cout << ", k-dnf=";
                        LW1_State::print_cnf_or_dnf(cout, kt->second, &kp_instance_);
#endif
                    }
#ifdef DEBUG
                    cout << endl;
#endif
                }
            }
        }
    }
}

bool LW1_Solver::is_forbidden(int literal) const {
    assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
    return static_cast<const LW1_Instance&>(kp_instance_).is_forbidden(literal);
}

bool LW1_Solver::is_forbidden(const LW1_Solver::clause_or_term_t &clause) const {
    assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
    return static_cast<const LW1_Instance&>(kp_instance_).is_forbidden(clause);
}

#undef DEBUG

