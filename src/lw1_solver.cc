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

// Fills the CNF in the solver.
void LW1_Solver::initialize(const KP_Instance &kp) {
#ifndef USE_INFERENCE_ENGINE
    assert(dynamic_cast<const LW1_Instance*>(&kp) != 0);
    const LW1_Instance &lw1 = *static_cast<const LW1_Instance*>(&kp_instance_);
    for( size_t j = 0; j < lw1.clauses_for_axioms_.size(); ++j ) {
        const vector<int> &clause = lw1.clauses_for_axioms_[j];
        Inference::Propositional::Clause cl;
        for( size_t k = 0; k < clause.size(); ++k )
            cl.push_back(clause[k]);
        cnf_.push_back(cl);
        base_theory_axioms_.insert(cl);
    }
    frontier_ = cnf_.size() - 1;
    fill_atoms_to_var_map(lw1);
#endif
}

// Deletes all clauses preserving the axioms
// TODO: Make this safe
void LW1_Solver::clean_cnf() const {
    cnf_.erase(cnf_.begin() + 1 + frontier_, cnf_.end());
}

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
#ifdef USE_INFERENCE_ENGINE
    inference_engine_.apply_inference(last_action, sensed_at_step, state);
#else
    float start_time = Utils::read_time_in_seconds();

#ifdef DEBUG
    cout << Utils::magenta() << ">>> state before inference=";
    state.print(cout, kp_instance_);
    cout << Utils::normal() << endl;

    if( last_action != 0 )
        cout << "Last action=" << last_action->name_ << endl;
    else
        cout << "Last action=" << last_action << endl;
#endif

    assert(translation_type_ == LW1);
    assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
    const LW1_Instance &lw1 = *static_cast<const LW1_Instance*>(&kp_instance_);

    if( options_.is_enabled("lw1:inference:forward-chaining") ) {
#ifdef DEBUG
        cout << Utils::cyan() << "Using inference: 'forward-chaining' (FC)" << Utils::normal() << endl;
#endif

        // add observations as state literals
        for( set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
            int sensed_literal = *it;
            if( sensed_literal > 0 ) {
                --sensed_literal;
                state.remove(2*sensed_literal + 1);
                state.add(2*sensed_literal);
#ifdef DEBUG
                cout << Utils::yellow() << "[FC] Adding sensed: ";
                LW1_State::print_literal(cout, 1 + 2*sensed_literal, &kp_instance_);
                cout << Utils::normal() << endl;
#endif
            } else {
                sensed_literal = -sensed_literal - 1;
                state.remove(2*sensed_literal);
                state.add(2*sensed_literal + 1);
#ifdef DEBUG
                cout << Utils::yellow() << "[FC] Adding sensed: ";
                LW1_State::print_literal(cout, 1 + 2*sensed_literal + 1, &kp_instance_);
                cout << Utils::normal() << endl;
#endif
            }
        }

        // unleash inference
        bool fix_point_reached = false;
        while( !fix_point_reached ) {
            STATE_CLASS old_state(state);
            for( size_t k = kp_instance_.first_deductive_action(); k < kp_instance_.last_deductive_action(); ++k ) {
                const Instance::Action &act = *kp_instance_.actions_[k];
                if( state.applicable(act) ) {
                    state.apply(act);
#ifdef DEBUG
                    act.print(cout, kp_instance_);
#endif
                }
            }
            fix_point_reached = old_state == state;
        }
    } else if( options_.is_enabled("lw1:inference:up")) {
#ifdef DEBUG
        cout << Utils::cyan() << "Using inference: 'unit propagation'" << Utils::normal() << endl;
#endif

        // find sensing models for given action that are incompatible with observations
        relevant_sensing_models_t relevant_sensing_models_as_k_cnf;
        if( last_action != 0 )
            fill_relevant_sensing_models(lw1, last_action, sensed_at_step, relevant_sensing_models_as_k_cnf, true);

        // construct logical theory for performing inference with unit propagation
        Inference::Propositional::CNF cnf;
        set<Inference::Propositional::Clause> base_theory;

        if( options_.is_enabled("lw1:inference:up:preload") )
            cnf = cnf_;

        // 0. Add observations as unit clauses
        if( options_.is_enabled("lw1:inference:up:enhanced") || options_.is_enabled("lw1:boost:literals-for-observables") ) {
            for( set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
                int k_literal = *it > 0 ? 2 * (*it - 1) : 2 * (-*it - 1) + 1;
#ifdef DEBUG
                cout << Utils::red() << "[UP: Theory] Add obs literal: ";
                state.print_literal(cout, 1 + k_literal, &kp_instance_);
                cout << Utils::normal() << endl;
#endif
                Inference::Propositional::Clause cl;
                cl.push_back(1 + k_literal);
                cnf.push_back(cl);
                base_theory.insert(cl);
            }
        }

        // 1. Positive literals from state
        for( STATE_CLASS::const_iterator it = state.begin(); it != state.end(); ++it ) {
#ifdef DEBUG
            cout << Utils::red() << "[UP] [Theory] Add literal from state: ";
            state.print_literal(cout, 1 + *it, &kp_instance_);
            cout << Utils::normal() << endl;
#endif
            Inference::Propositional::Clause cl;
            cl.push_back(1 + *it); // CHECK: en implementacion de clause, 'push_back' es un 'insert'
            cnf.push_back(cl);
            base_theory.insert(cl);
        }

        // 2. Axioms: D'
        if( !options_.is_enabled("lw1:inference:up:preload") ) {
            for( vector<vector<int> >::const_iterator it = lw1.clauses_for_axioms_.begin(); it != lw1.clauses_for_axioms_.end(); ++it ) {
                const vector<int> &clause = *it;
#ifdef DEBUG
                cout << Utils::red() << "[UP] [Theory] Add axiom: ";
                state.print_clause_or_term(cout, clause, &kp_instance_);
                cout << Utils::normal() << endl;
#endif
                Inference::Propositional::Clause cl;
                for( size_t k = 0; k < clause.size(); ++k )
                    cl.push_back(clause[k]);
                cnf.push_back(cl);
                base_theory.insert(cl);
            }
        }

        // 3. Clauses from sensing models: K_o
        for( relevant_sensing_models_t::const_iterator it = relevant_sensing_models_as_k_cnf.begin(); it != relevant_sensing_models_as_k_cnf.end(); ++it ) {
            int sensed_literal = it->first;
            for( map<int, sensing_models_as_cnf_or_dnf_t>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                int var_key = jt->first;
                const LW1_Instance::Variable &variable = *lw1.variables_[var_key];
                if( variable.is_state_variable() ) {
                    assert(jt->second.empty());
                    int k_literal = sensed_literal > 0 ? 1 + 2*(sensed_literal - 1) : 1 + 2*(-sensed_literal - 1) + 1;
#ifdef DEBUG
                    cout << Utils::red() << "[UP] [Theory] Add obs (state) literal: ";
                    state.print_literal(cout, k_literal, &kp_instance_);
                    cout << Utils::normal() << endl;
#endif
                    Inference::Propositional::Clause cl;
                    cl.push_back(k_literal);
                    cnf.push_back(cl);
                } else {
                    const sensing_models_as_cnf_or_dnf_t &sensing_models_as_k_cnf = jt->second;
                    for( size_t k = 0; k < sensing_models_as_k_cnf.size(); ++k ) {
                        const cnf_or_dnf_t &k_cnf_for_sensing_model = *sensing_models_as_k_cnf[k];
                        for( size_t j = 0; j < k_cnf_for_sensing_model.size(); ++j ) {
                            const clause_or_term_t &clause = k_cnf_for_sensing_model[j];
#ifdef DEBUG
                            cout << Utils::red() << "[UP] [Theory] Add K_o clause: ";
                            state.print_clause_or_term(cout, clause, &kp_instance_);
                            cout << Utils::normal() << endl;

                            // The clause holds the indexes for the atoms
                            // To find it in atoms_, 1 must be substracted.
#ifdef DEBUG
//                            CHECK: In UP problems, K_atoms can be encountered which are not in atoms_to_var_map_
//                            as some variables (for example, wumpus) can have reduced domains.
//                            This print is commented out as a precaution.
//
//                            for( auto cl = clause.cbegin(); cl != clause.cend(); ++cl ) { // CHECK: remove auto
//                                int cl_index = abs(*cl);
//                                int k_literal = cl_index > 0 ? (cl_index - 1) / 2 : (-cl_index - 1) / 2 + 1;
//                                cout << Utils::magenta() << "[UP] Related variable: ";
//                                cout << lw1.variables_[atoms_to_vars_.at(k_literal)]->name_;
//                                cout << Utils::normal() << endl;
//                            }
#endif

#endif
                            Inference::Propositional::Clause cl;
                            for( size_t i = 0; i < clause.size(); ++i )
                                cl.push_back(clause[i]);
                            cnf.push_back(cl);
                        }
                    }
                }
            }
        }

        // 4. Kept (extra) static clauses
        if( options_.is_enabled("lw1:inference:up:enhanced") ) {
            std::cout << Utils::internal_error() << "lw1:inference:up:enhanced is EXPERIMENTAL!" << std::endl;
            exit(-1);

#if BASE_SELECTOR == 1
            assert(dynamic_cast<LW1_State*>(&state) != 0);
            for( size_t k = 0; k < state.cnf_.size(); ++k ) {
                const clause_or_term_t &clause = state.cnf_[k];
#    ifdef DEBUG
                cout << Utils::red() << "[UP] [Theory] Add extra clause: ";
                state.print_clause_or_term(cout, clause, &kp_instance_);
                cout << Utils::normal() << endl;
#    endif
                Inference::Propositional::Clause cl;
                for( size_t i = 0; i < clause.size(); ++i )
                    cl.push_back(clause[i]);
                cnf.push_back(cl);
                base_theory.insert(cl);
            }
#endif // BASE_SELECTOR == 1
        }

        // 5. Perform inference
        Inference::Propositional::CNF result;
        vector<int> assignment;
        if( options_.is_enabled("lw1:inference:up:watched-literals") ) {
#ifdef DEBUG
            cout << Utils::cyan() << "[UP] Using method: 'watched-literals'" << Utils::normal() << endl;
#endif
            Inference::Propositional::WatchedLiterals wl;
            wl.solve(cnf, assignment);
            if( options_.is_enabled("lw1:inference:up:lookahead") ) {
                std::cout << Utils::internal_error() << "lw1:inference:up:lookahead is EXPERIMENTAL!" << std::endl;
                exit(-1);

#ifdef DEBUG
                cout << Utils::cyan() << "[U] Using one-lookahead for 'watched-literals'" << Utils::normal() << endl;
#endif
                wl.lookahead(cnf, assignment);
            }
        } else {
#ifdef DEBUG
            cout << Utils::cyan() << "[UP] Using method: 'Standard'" << Utils::normal() << endl;
#endif
            Inference::Propositional::Standard up;
            up.solve(cnf, result);
        }

        // 6. Insert positive literals from result into state
        if( options_.is_enabled("lw1:inference:up:watched-literals") ) {
            for(unsigned i = 1; i < assignment.size(); ++i) {
                int literal = assignment[i];
                if( is_forbidden(i) ) continue;
                assert((literal != 0) || options_.is_enabled("lw1:inference:up:enhanced") || options_.is_enabled("lw1:inference:up:lookahead"));
                if( literal == 1 ) {
                    state.add(i-1);
#ifdef DEBUG
                    cout << Utils::yellow() << "[UP] [State] Add inferred literal: ";
                    state.print_literal(cout, i, &kp_instance_);
                    cout << Utils::normal() << endl;
#endif
                }
            }
        } else {
            for( size_t k = 0; k < result.size(); ++k ) {
                if( result[k].empty() ) {
                    cout << Utils::error() << "[UP] inconsistency derived during inference" << endl;
                    exit(255);
                }
            }

            for( size_t k = 0; k < result.size(); ++k ) {
                const Inference::Propositional::Clause &cl = result[k];
                if( base_theory.find(cl) != base_theory.end() ) continue;
                if( base_theory_axioms_.find(cl) != base_theory_axioms_.end() ) continue; // CHECK
                if( cl.size() == 1 ) {
                    int literal = *cl.begin();
                    if( is_forbidden(literal) ) continue;
                    assert(literal != 0);
                    assert((literal > 0) || options_.is_enabled("lw1:inference:up:enhanced"));
                    if( literal > 0 ) {
                        state.add(literal - 1);
#ifdef DEBUG
                        cout << Utils::yellow() << "[UP] [State] Add inferred literal: ";
                        state.print_literal(cout, literal, &kp_instance_);
                        cout << Utils::normal() << endl;
#endif
                    }
                }
            }
        }

        // 7. Insert non-forbidden clauses in result into state
        if( options_.is_enabled("lw1:inference:up:enhanced") ) {
            std::cout << Utils::internal_error() << "lw1:inference:up:enhanced is EXPERIMENTAL!" << std::endl;
            exit(-1);

#if BASE_SELECTOR == 1
            state.cnf_.clear();
            for( size_t k = 0; k < result.size(); ++k ) {
                const Inference::Propositional::Clause &cl = result[k];
                if( base_theory.find(cl) != base_theory.end() ) continue;
                if( base_theory_axioms_.find(cl) != base_theory_axioms_.end() ) continue;
                if( cl.size() > 1 ) {
                    clause_or_term_t clause;
                    for( Inference::Propositional::Clause::const_iterator it = cl.begin(); it != cl.end(); ++it )
                        clause.push_back(*it);
                    if( is_forbidden(clause) ) continue;
#    ifdef DEBUG
                    cout << Utils::yellow() << "[UP] [State] Add clause: ";
                    state.print_clause_or_term(cout, clause, &kp_instance_);
                    cout << Utils::normal() << endl;
#    endif
                    state.cnf_.push_back(clause);
                }
            }
        }

        // Cleaning CNF
        if( options_.is_enabled("lw1:inference:up:preload") )
            clean_cnf();
#endif // if BASE_SELECTOR == 1
    } else if( options_.is_enabled("lw1:inference:ac3") ) {
#ifdef DEBUG
        cout << Utils::cyan() << "Using inference: 'ac3' (AC3)" << Utils::normal() << endl;
#endif
        Inference::CSP::Csp csp;
        csp.reset_current_domains();

        // find sensing models for given action that are incompatible with observations
        relevant_sensing_models_t relevant_sensing_models_as_k_dnf;
        if( last_action != 0 )
            fill_relevant_sensing_models(lw1, last_action, sensed_at_step, relevant_sensing_models_as_k_dnf, false);


        // 0. Domains are original domains with values pruned as indicated with the K-literals in state.
        // Basic constraints relate variable groups to state variable and variable groups to variable
        // groups.
        for( STATE_CLASS::const_iterator it = state.begin(); it != state.end(); ++it ) {
            if( state.is_special(*it + 1, &kp_instance_) ) continue;
#ifdef DEBUG
            cout << Utils::red() << "[CSP] Added literal from state: ";
            state.print_literal(cout, 1 + *it, &kp_instance_);
            cout << Utils::normal() << endl;
#endif
            csp.prune_domain_of_var(1 + *it);
        }

        // 1. Add observation. Pruned variable domains using k-dnf for observation. For each observation,
        // (a) if observation refers to state variable (i.e. state variable is observable), prune domain
        // of CSP variable corresponding to state variable, (b) if observation can be filtered in
        // variable group, prune from domain of CSP variable corresponding to variable group all
        // valuations that do not satisfy k-dnf, and else (c) observation is of type V=v, use the k-dnf
        // to construct constraints among the state variables mentioned in DNF

        for( relevant_sensing_models_t::const_iterator it = relevant_sensing_models_as_k_dnf.begin(); it != relevant_sensing_models_as_k_dnf.end(); ++it ) {
            int sensed_literal = it->first;

            for( map<int, sensing_models_as_cnf_or_dnf_t>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                int var_key = jt->first;
                const LW1_Instance::Variable &variable = *lw1.variables_[var_key];
                pair<int, int> key(var_key, sensed_literal);
#ifdef DEBUG
                cout << "[AC3] sensed literal: var=" << variable.name() << ", value=" << flush;
                LW1_State::print_literal(cout, sensed_literal, &instance_);
                cout << ", key=(" << var_key << "," << sensed_literal << ")" << endl;
#endif
                if( variable.is_state_variable() ) {
                    // observation is state variable, filter it directly in variable domain
                    assert(jt->second.empty());
                    int k_literal = sensed_literal > 0 ? 1 + 2*(sensed_literal - 1) : 1 + 2*(-sensed_literal - 1) + 1;
#ifdef DEBUG
                    cout << Utils::red() << "[AC3] Add obs (state) k-literal: ";
                    state.print_literal(cout, k_literal, &kp_instance_);
                    cout << Utils::normal() << endl;
#endif
                    csp.prune_domain_of_var(k_literal);
                } else if( lw1.filtering_groups_.find(key) != lw1.filtering_groups_.end() ) {
                    // observation can be filtered in variable group. Prune all valuations that are
                    // not consistent with k-dnf
                    int vg = lw1.filtering_groups_.at(key);
                    const sensing_models_as_cnf_or_dnf_t& sensing_models_as_k_dnf = jt->second;
                    for( size_t k = 0; k < sensing_models_as_k_dnf.size(); ++k ) {
                        const cnf_or_dnf_t& k_dnf_for_sensing_model = *sensing_models_as_k_dnf[k];
                        csp.prune_valuations_of_groups(vg, k_dnf_for_sensing_model, kp_instance_);
#ifdef DEBUG
                        cout << Utils::blue() << "[AC3] k-dnf or k-cnf: index=" << k << ", formula=";
                        state.print_cnf_or_dnf(cout, k_dnf_for_sensing_model, &kp_instance_);
                        cout << Utils::normal() << endl;

                        for( size_t j = 0; j < k_dnf_for_sensing_model.size(); ++j ) {
                            const clause_or_term_t& term = k_dnf_for_sensing_model[j];
                            cout << Utils::cyan() << "[AC3] Clause or term: ";
                            state.print_clause_or_term(cout, term, &kp_instance_);
                            cout << Utils::normal() << endl;
                        }
#endif
                    }

                } else {
                    // there is no variable group where to filter observation. Use k-dnf to generate constraints in CSP
                    const sensing_models_as_cnf_or_dnf_t &sensing_models_as_k_dnf = jt->second;
                    for( size_t k = 0; k < sensing_models_as_k_dnf.size(); ++k ) {
                        const cnf_or_dnf_t &k_dnf_for_sensing_model = *sensing_models_as_k_dnf[k];
#ifdef DEBUG
                        cout << Utils::blue() << "[AC3] k-dnf: index =" << k << ", formula =" << Utils::normal();
                        state.print_cnf_or_dnf(cout, k_dnf_for_sensing_model, &kp_instance_);
                        cout << endl;
#endif
                        bool possible = true;
                        set<int> possible_domain;
                        for( size_t j = 0; j < k_dnf_for_sensing_model.size(); ++j ) {
                            const clause_or_term_t &term = k_dnf_for_sensing_model[j];

                            if( term.size() > 1 ) {
                                possible = false;
                                break;
                            }
                            assert(term.size() == 1);
#ifdef DEBUG
                            cout << Utils::red() << "[AC3] Adding to possible domain_: ";
                            state.print_clause_or_term(cout, term, &kp_instance_);
                            cout << Utils::normal() << endl;
#endif
                            possible_domain.insert(term[0]);
                        }
                        if( possible )
                            csp.intersect_domain_of_var(possible_domain);
                    }
                }
            }
        }

        // 2. Make the CSP arc consistent by running AC3. The resulting CSP should be consistent
        // (i.e. the domain of each variable should be non empty). Otherwise, there is an error in
        // the planning model
        Inference::CSP::AC3 ac3;
        ac3.solve_groups(csp, state, kp_instance_);
    } else {
        cout << Utils::error() << "unspecified inference method for lw1" << endl;
        exit(255);
    }

    // update time for inference
    float end_time = Utils::read_time_in_seconds();
    kp_instance_.increase_inference_time(end_time - start_time);

#ifdef DEBUG
    cout << Utils::green() << ">>> state  after inference=";
    state.print(cout, kp_instance_);
    cout << Utils::normal() << endl;
#endif
#endif
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
        cout << Utils::error() << "no sensing model for action '" << action_key << "'" << endl;
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

void LW1_Solver::fill_atoms_to_var_map(const KP_Instance& lw1) {
    atoms_to_vars_.clear();
    const std::vector<LW1_Instance::Variable*> &vars = ((const LW1_Instance&)lw1).variables_;
    for( int v = 0; v < vars.size(); ++v ) {
        const LW1_Instance::Variable &var = *vars[v];
        // Iterating the domain of variables, inserting in atoms_to_vars the
        for( std::set<int>::const_iterator dom = var.domain().cbegin(); dom != var.domain().cend(); ++dom ) {
            assert(atoms_to_vars_.find(*dom) == atoms_to_vars_.cend());
            atoms_to_vars_.insert(make_pair(*dom, v));

        }
    }
}

#undef DEBUG

