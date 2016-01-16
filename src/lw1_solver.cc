#include <cassert>
#include <iostream>
#include "lw1_solver.h"
#include "classical_planner.h"
#include "utils.h"
#include "inference.h"
#include "csp.h"

#define DEBUG

using namespace std;

// Fills the CNF in the solver.
void LW1_Solver::initialize(const KP_Instance &kp) {
    assert(dynamic_cast<const LW1_Instance*>(&kp) != 0);
    const LW1_Instance &lw1 = *static_cast<const LW1_Instance*>(&kp_instance_);
    for (auto it = lw1.clauses_for_axioms_.begin(); it != lw1.clauses_for_axioms_.end(); it++) {
        const vector<int> &clause = *it;

        Inference::Propositional::Clause cl;
        for(auto k = 0; k < clause.size(); ++k)
            cl.push_back(clause[k]);
        cnf.push_back(cl);
        base_theory_axioms.insert(cl);
    }

    frontier = cnf.size()-1;
}

// Deletes all clauses preserving the axioms
// TODO: Make this safe
void LW1_Solver::clean_cnf() const {
    cnf.erase(cnf.begin()+1+frontier, cnf.end());
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

                // if state variable, the value of observed literal (either true or false)
                // is directly obtained from the hidden state. If non-state variable, need
                // to use sensing model to determine the value. If the domain size is 1,
                // there are only two values for the variable, true or false corresponding
                // to the positive and negative literal respectively. If domain size > 1,
                // each value corresponds to a different literal (from which one and only
                // one must be true).

                if( variable.domain_.size() == 1 ) {
                    int index = *variable.domain_.begin();
                    bool satisfy = value_observable_literal(hidden, *last_action, *jt, index);
                    sensed_at_step.insert(satisfy ? 1 + index : -(1 + index));
                    if( options_.is_enabled("lw1:boost:literals-for-observables") ) {
                        update_state_with_literals_for_observables(state, *last_action, variable, satisfy ? 1 + index : -(1 + index));
                    }
                } else {
                    bool some_value_sensed = false;
                    for( set<int>::const_iterator kt = variable.domain_.begin(); kt != variable.domain_.end(); ++kt ) {
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
                                     << variable.name_ << "' with action '"
                                     << last_action->name_->to_string() << "'"
                                     << endl;
                            }
                        }
                    }
                    if( !some_value_sensed ) {
                        cout << Utils::error() << "no value sensed for variable '"
                             << variable.name_ << "' with action '"
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

#ifndef DEBUG
    if( options_.is_enabled("solver:print:sensed-literals") ) {
#endif
        for( set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
            int obs = *it > 0 ? *it - 1 : -*it - 1;
            cout << Utils::yellow()
                 << "sensed: literal="
                 << (*it > 0 ? "" : "(not ")
                 << instance_.atoms_[obs]->name_
                 << (*it > 0 ? "" : ")")
                 << ", index=" << obs
                 << Utils::normal() << endl;
        }
#ifndef DEBUG
    }
#endif
}

void LW1_Solver::apply_inference(const Instance::Action *last_action,
                                 const set<int> &sensed_at_step,
                                 STATE_CLASS &state) const {
    float start_time = Utils::read_time_in_seconds();

#ifdef DEBUG
    cout << Utils::magenta() << ">>> state before inference=";
    state.print(cout, kp_instance_);
    cout << Utils::normal() << endl;

    if (last_action != 0)
        cout << "Last action=" << last_action->name_ << endl;
    else
        cout << "Last action=" << last_action << endl;
#endif

    assert(translation_type_ == LW1);
    assert(dynamic_cast<const LW1_Instance *>(&kp_instance_) != 0);
    const LW1_Instance &lw1 = *static_cast<const LW1_Instance *>(&kp_instance_);

    if (options_.is_enabled("lw1:inference:forward-chaining")) {
#ifdef DEBUG
        cout << Utils::cyan() << "Using inference: 'forward-chaining'" << Utils::normal() << endl;
#endif

        // add observations as state literals
        for (set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it) {
            int sensed_literal = *it;
            if (sensed_literal > 0) {
                --sensed_literal;
                state.remove(2 * sensed_literal + 1);
                state.add(2 * sensed_literal);
#ifdef DEBUG
                cout << Utils::yellow() << "Adding sensed: ";
                LW1_State::print_literal(cout, 1 + 2 * sensed_literal, &kp_instance_);
                cout << Utils::normal() << endl;
#endif
            } else {
                sensed_literal = -sensed_literal - 1;
                state.remove(2 * sensed_literal);
                state.add(2 * sensed_literal + 1);
#ifdef DEBUG
                cout << Utils::yellow() << "Adding sensed: ";
                LW1_State::print_literal(cout, 1 + 2 * sensed_literal + 1, &kp_instance_);
                cout << Utils::normal() << endl;
#endif
            }
        }

        // unleash inference
        bool fix_point_reached = false;
        while (!fix_point_reached) {
            STATE_CLASS old_state(state);
            for (size_t k = kp_instance_.first_deductive_action(); k < kp_instance_.last_deductive_action(); ++k) {
                const Instance::Action &act = *kp_instance_.actions_[k];
                if (state.applicable(act)) {
                    state.apply(act);
                    act.print(cout, kp_instance_);
                }
            }
            fix_point_reached = old_state == state;
        }
    } else if (options_.is_enabled("lw1:inference:up")) {
#ifdef DEBUG
        cout << Utils::cyan() << "Using inference: 'unit propagation'" << Utils::normal() << endl;
#endif

        // find sensing models for given action that are incompatible with observations
        relevant_sensing_models_as_cnf_t relevant_sensing_models_as_cnf;
        if (last_action != 0)
            fill_relevant_sensing_models(lw1, last_action, sensed_at_step, relevant_sensing_models_as_cnf);

        // construct logical theory for performing inference with unit propagation
#ifdef UP
        Inference::Propositional::CNF cnf;
        set<Inference::Propositional::Clause> base_theory;

        if (options_.is_enabled("lw1:inference:preload"))
            cnf = this->cnf;
#endif

        // 0. Add observations as unit clauses
        if (options_.is_enabled("lw1:inference:up:enhanced") ||
            options_.is_enabled("lw1:boost:literals-for-observables")) {
            for (set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it) {
                int k_literal = *it > 0 ? 2 * (*it - 1) : 2 * (-*it - 1) + 1;
#ifdef DEBUG
                cout << Utils::red() << "[Theory] Add obs literal: ";
                state.print_literal(cout, 1 + k_literal, &kp_instance_);
                cout << Utils::normal() << endl;
#endif
#ifdef UP
                Inference::Propositional::Clause cl;
                cl.push_back(1 + k_literal);
                cnf.push_back(cl);
                base_theory.insert(cl);
#endif
            }
        }

        // 1. Positive literals from state
        for (STATE_CLASS::const_iterator it = state.begin(); it != state.end(); ++it) {
#ifdef DEBUG
            cout << Utils::red() << "[Theory] Add literal from state: ";
            state.print_literal(cout, 1 + *it, &kp_instance_);
            cout << Utils::normal() << endl;
#endif
#ifdef UP
            Inference::Propositional::Clause cl;
            cl.push_back(1 + *it); // CHECK: en implementacion de clause, 'push_back' es un 'insert'
            cnf.push_back(cl);
            base_theory.insert(cl);
#endif
        }

        // 2. Axioms: D'
        if (!options_.is_enabled("lw1:inference:preload")) {
            for (vector<vector<int> >::const_iterator it = lw1.clauses_for_axioms_.begin();
                 it != lw1.clauses_for_axioms_.end(); ++it) {
                const vector<int> &clause = *it;
#ifdef DEBUG
                cout << Utils::red() << "[Theory] Add axiom: ";
                state.print_clause(cout, clause, &kp_instance_);
                cout << Utils::normal() << endl;
#endif
#ifdef UP
                Inference::Propositional::Clause cl;
                for (size_t k = 0; k < clause.size(); ++k)
                    cl.push_back(clause[k]);
                cnf.push_back(cl);
                base_theory.insert(cl);
#endif
            }
        }

        // 3. Clauses from sensing models: K_o
        for (relevant_sensing_models_as_cnf_t::const_iterator it = relevant_sensing_models_as_cnf.begin();
             it != relevant_sensing_models_as_cnf.end(); ++it) {
            int sensed_literal = it->first;
            for (map<int, sensing_models_as_cnf_t>::const_iterator jt = it->second.begin();
                 jt != it->second.end(); ++jt) {
                int var_key = jt->first;
                const LW1_Instance::Variable &variable = *lw1.variables_[var_key];
                if (variable.is_state_variable_) {
                    assert(jt->second.empty());
                    int k_literal =
                            sensed_literal > 0 ? 1 + 2 * (sensed_literal - 1) : 1 + 2 * (-sensed_literal - 1) + 1;
#ifdef DEBUG
                    cout << Utils::red() << "[Theory] Add obs (state) literal: ";
                    state.print_literal(cout, k_literal, &kp_instance_);
                    cout << Utils::normal() << endl;
#endif
#ifdef UP
                    Inference::Propositional::Clause cl;
                    cl.push_back(k_literal);
                    cnf.push_back(cl);
#endif
                } else {
                    const sensing_models_as_cnf_t &sensing_models_as_cnf = jt->second;
                    for (size_t k = 0; k < sensing_models_as_cnf.size(); ++k) {
                        const cnf_t &cnf_for_sensing_model = *sensing_models_as_cnf[k];
                        for (size_t j = 0; j < cnf_for_sensing_model.size(); ++j) {
                            const clause_t &clause = cnf_for_sensing_model[j];
#ifdef DEBUG
                            cout << Utils::red() << "[Theory] Add K_o clause: ";
                            state.print_clause(cout, clause, &kp_instance_);
                            cout << Utils::normal() << endl;

                            // The clause holds the indexes for the atoms
                            // To find it in atoms_, 1 must be substracted.
#ifdef DEBUG
//                            for (auto cl = clause.cbegin(); cl != clause.cend(); cl++) {
//                                int cl_index = *cl;
//                                int k_literal = cl_index > 0 ? (cl_index - 1) / 2 : (-cl_index - 1) / 2 + 1;
//                                cout << Utils::magenta() << "Related variable to " << cl_index << ": ";
//                                cout << lw1.variables_[atoms_to_vars_.at(k_literal)]->name_;
//                                cout << Utils::normal() << endl;
//                            }
#endif

#endif
#ifdef UP
                            Inference::Propositional::Clause cl;
                            for (size_t i = 0; i < clause.size(); ++i)
                                cl.push_back(clause[i]);
                            cnf.push_back(cl);
#endif
                        }
                    }
                }
            }
        }

        // 4. Kept (extra) static clauses
        if (options_.is_enabled("lw1:inference:up:enhanced")) {
#if BASE_SELECTOR == 1
            assert(dynamic_cast<LW1_State *>(&state) != 0);
            for (size_t k = 0; k < state.cnf_.size(); ++k) {
                const clause_t &clause = state.cnf_[k];
#    ifdef DEBUG
                cout << Utils::red() << "[Theory] Add extra clause: ";
                state.print_clause(cout, clause, &kp_instance_);
                cout << Utils::normal() << endl;
#    endif
#    ifdef UP
                Inference::Propositional::Clause cl;
                for (size_t i = 0; i < clause.size(); ++i)
                    cl.push_back(clause[i]);
                cnf.push_back(cl);
                base_theory.insert(cl);
#    endif
            }
#endif
        }

        // 5. Perform inference
#ifdef UP
        Inference::Propositional::CNF result;
        vector<int> assignment;
#endif
        if (options_.is_enabled("lw1:inference:up:lookahead")) {
            cout << Utils::error() << "inference method 'lw1:inference:up:lookahead' not yet implemented" << endl;
            exit(255);
        } else if (options_.is_enabled("lw1:inference:watched-literals")) {
#ifdef UP
#    ifdef DEBUG
            cout << Utils::cyan() << "Using method: 'watched-literals'" << Utils::normal() << endl;
#    endif
            Inference::Propositional::WatchedLiterals wl;
            wl.solve(cnf, assignment);
        } else {
#    ifdef DEBUG
            cout << Utils::cyan() << "Using method: 'DPLL'" << Utils::normal() << endl;
#    endif
            Inference::Propositional::DPLL up;
            up.solve(cnf, result);
        }
#endif

        // 6. Insert positive literals from result into state
#ifdef UP
        if (options_.is_enabled("lw1:inference:watched-literals")) {
            for (unsigned i = 1; i < assignment.size(); ++i) {
                int literal = assignment[i];
                if (is_forbidden(i)) continue;
                assert(literal != 0); // CHECK
                // assert((literal > 0) || options_.is_enabled("lw1:inference:up:enhanced"));
                if (literal == 1) {
                    state.add(i - 1);
#    ifdef DEBUG
                    cout << Utils::yellow() << "[State] Add inferred literal: ";
                    state.print_literal(cout, i, &kp_instance_);
                    cout << Utils::normal() << endl;
#    endif
                }
            }
        } else {
            for (size_t k = 0; k < result.size(); ++k) {
                if (result[k].empty()) {
                    cout << Utils::error() << "inconsistency derived during inference" << endl;
                    exit(255);
                }
            }

            for (size_t k = 0; k < result.size(); ++k) {
                const Inference::Propositional::Clause &cl = result[k];
                if (base_theory.find(cl) != base_theory.end()) continue;
                if (base_theory_axioms.find(cl) != base_theory_axioms.end()) continue; // CHECK
                if (cl.size() == 1) {
                    int literal = *cl.begin();
                    if (is_forbidden(literal)) continue;
                    assert(literal != 0);
                    assert((literal > 0) || options_.is_enabled("lw1:inference:up:enhanced"));
                    if (literal > 0) {
                        state.add(literal - 1);
#    ifdef DEBUG
                        cout << Utils::yellow() << "[State] Add inferred literal: ";
                        state.print_literal(cout, literal, &kp_instance_);
                        cout << Utils::normal() << endl;
#    endif
                    }
                }
            }
        }
#endif // ifdef UP


        // 7. Insert non-forbidden clauses in result into state
        if (options_.is_enabled("lw1:inference:up:enhanced")) {
#if BASE_SELECTOR == 1
#    ifdef UP
            state.cnf_.clear();
            for (size_t k = 0; k < result.size(); ++k) {
                const Inference::Propositional::Clause &cl = result[k];
                if (base_theory.find(cl) != base_theory.end()) continue;
                if (base_theory_axioms.find(cl) != base_theory_axioms.end()) continue;
                if (cl.size() > 1) {
                    clause_t clause;
                    for (Inference::Propositional::Clause::const_iterator it = cl.begin(); it != cl.end(); ++it)
                        clause.push_back(*it);
                    if (is_forbidden(clause)) continue;
#        ifdef DEBUG
                    cout << Utils::yellow() << "[State] Add clause: ";
                    state.print_clause(cout, clause, &kp_instance_);
                    cout << Utils::normal() << endl;
#        endif
                    state.cnf_.push_back(clause);
                }
            }
        }

        // Cleaning CNF
        if (options_.is_enabled("lw1:inference:preload"))
            clean_cnf();
#    endif // ifdef UP
#endif // if BASE_SELECTOR == 1
    } else if (options_.is_enabled("lw1:inference:arc-consistency")) {
#ifdef DEBUG
        cout << Utils::cyan() << "Using inference: 'arc consistency'" << Utils::normal() << endl;
#endif
        Inference::CSP::Csp csp;
        Inference::CSP::AC3 ac3;

        // Compute relevant sensing model
        // From this method the K_o used for AC3 are extracted
        relevant_sensing_models_as_cnf_t relevant_sensing_models_as_cnf;
        if (last_action != 0)
            fill_relevant_sensing_models(lw1, last_action, sensed_at_step, relevant_sensing_models_as_cnf);

        for (relevant_sensing_models_as_cnf_t::const_iterator it = relevant_sensing_models_as_cnf.begin();
             it != relevant_sensing_models_as_cnf.end(); ++it) {
            int sensed_literal = it->first;
            for (map<int, sensing_models_as_cnf_t>::const_iterator jt = it->second.begin();
                 jt != it->second.end(); ++jt) {
                int var_key = jt->first;
                const LW1_Instance::Variable &variable = *lw1.variables_[var_key];
                if (variable.is_state_variable_) {
                    assert(jt->second.empty());
                    int k_literal =
                            sensed_literal > 0 ? 1 + 2 * (sensed_literal - 1) : 1 + 2 * (-sensed_literal - 1) + 1;
#ifdef DEBUG
                    cout << Utils::red() << "[Theory] Add obs (state) literal: ";
                    state.print_literal(cout, k_literal, &kp_instance_);
                    cout << Utils::normal() << endl;
#endif
//                    Inference::Propositional::Clause cl;
//                    cl.push_back(k_literal);
////                    cnf.push_back(cl);
                } else {
                    const sensing_models_as_cnf_t &sensing_models_as_cnf = jt->second;

                    for (size_t k = 0; k < sensing_models_as_cnf.size(); ++k) {
                        const cnf_t &cnf_for_sensing_model = *sensing_models_as_cnf[k];

                        for (size_t j = 0; j < cnf_for_sensing_model.size(); ++j) {
                            const clause_t &clause = cnf_for_sensing_model[j];
#ifdef DEBUG
                            cout << Utils::red() << "[Theory] Add K_o clause: ";
                            state.print_clause(cout, clause, &kp_instance_);
                            cout << Utils::normal() << endl;

                            // The clause holds the indexes for the atoms
                            // To find it in atoms_, 1 must be substracted.
//                            for (auto cl = clause.cbegin(); cl != clause.cend(); cl++) {
//                                int cl_index = *cl;
//                                int k_literal = cl_index > 0 ? (cl_index - 1) / 2 : (-cl_index - 1) / 2 + 1;
//                                cout << Utils::magenta() << "Related variable to " << cl_index << ": ";
//                                cout << lw1.variables_[atoms_to_vars_.at(k_literal)]->name_;
//                                cout << Utils::normal() << endl;
//                            }

#endif
                            Inference::Propositional::Clause cl;
                            for (size_t i = 0; i < clause.size(); ++i) {
                                cl.push_back(clause[i]);
                            }

                            // Constraints are added to the CSP
                            csp.add_constraint(cl);
                        }
                    }
                }
            }
        }

        // 1. Positive literals from state
        for (STATE_CLASS::const_iterator it = state.begin(); it != state.end(); ++it) {
#ifdef DEBUG
            cout << Utils::red() << "[Theory] Add literal from state: ";
            state.print_literal(cout, 1 + *it, &kp_instance_);
            cout << Utils::normal() << endl;
#endif
#ifdef UP
            Inference::Propositional::Clause cl;
            cl.push_back(1 + *it); // CHECK: en implementacion de clause, 'push_back' es un 'insert'
            cnf.push_back(cl);
            csp.add_constraint(cl);
#endif
        }


        // The CSP is solved
        ac3.solve(csp, state, kp_instance_);
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
    if( variable.is_state_variable_ ) {
#ifdef DEBUG
        cout << Utils::cyan()
             << "Evaluation: action=" << action_key
             << ", variable=" << variable.name_
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
    const map<int, map<int, vector<vector<int> > > > &sensing_models_for_action = lw1.sensing_models_as_dnf_.find(action_key)->second;
    //cout << "XXXXXX.2" << endl;

    if( sensing_models_for_action.find(var_index) == sensing_models_for_action.end() ) {
        cout << Utils::error() << "no sensing model for variable '"
             << variable.name_ << "' for action '"
             << action_key << "'" << endl;
        return false;
    }
    const map<int, vector<vector<int> > > &sensing_models_for_action_and_var = sensing_models_for_action.find(var_index)->second;
    //cout << "XXXXXX.3" << endl;

    if( sensing_models_for_action_and_var.find(1 + index) == sensing_models_for_action_and_var.end() ) {
        // there is no sensing model for this value. Assuming it is false.
        return false;
    }
    const vector<vector<int> > &dnf = sensing_models_for_action_and_var.find(1 + index)->second;
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
         << ", variable=" << variable.name_
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
    map<string, set<int> >::const_iterator it = lw1.atoms_for_observables_.find(variable.name_);
    if( (it != lw1.atoms_for_observables_.end()) && (it->second.find(index) != it->second.end()) ) {
        state.add(value > 0 ? 2*index : 2*index + 1);
#ifdef DEBUG
        cout << Utils::cyan()
             << "Update state with literal for observable: variable=" << variable.name_
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
                                              LW1_Solver::relevant_sensing_models_as_cnf_t &sensing_models_as_cnf) const {
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
    const map<int, map<int, vector<vector<int> > > > *sensing_models_for_action = 0;
    if( lw1.sensing_models_as_k_cnf_.find(action_key) != lw1.sensing_models_as_k_cnf_.end() )
        sensing_models_for_action = &lw1.sensing_models_as_k_cnf_.find(action_key)->second;

    for( set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
        int sensed_literal = *it;
        int atom_index = sensed_literal < 0 ? -sensed_literal - 1 : sensed_literal - 1;
        bool negated = sensed_literal < 0;
        int value_key = !negated ? atom_index + 1 : -(atom_index + 1);

        if( options_.is_enabled("solver:print:sensed-literals") ) {
            cout << Utils::yellow() << "sensed: literal=";
            State::print_literal(cout, sensed_literal, &instance_);
            cout << ", index=" << atom_index << Utils::normal() << endl;
        }

        map<int, vector<int> >::const_iterator jt = lw1.variables_for_atom_.find(atom_index);
        assert(jt != lw1.variables_for_atom_.end());
        assert(!jt->second.empty());

        // collect sensing models for values incompatible with obs.
        // For binary vars (i.e. w/ domain of size 1), need to
        // consider complemented value explicitly
        for( size_t k = 0; k < jt->second.size(); ++k ) {
            int var_key = jt->second[k];
            const LW1_Instance::Variable &variable = *lw1.variables_[var_key];

            if( variable.is_state_variable_ ) {
                sensing_models_as_cnf[sensed_literal].insert(make_pair(var_key, sensing_models_as_cnf_t()));
                continue;
            }

            // for non-binary variables, the values for observables are positive atoms
            // and these are used to access the sensing models. Hence, we can discard
            // negative observed literals.
            if( (variable.domain_.size() > 1) && negated ) continue;

            assert(sensing_models_for_action != 0);
            assert(sensing_models_for_action->find(var_key) != sensing_models_for_action->end());
            const map<int, vector<vector<int> > > &sensing_models_for_var = sensing_models_for_action->find(var_key)->second;

            for( map<int, vector<vector<int> > >::const_iterator kt = sensing_models_for_var.begin(); kt != sensing_models_for_var.end(); ++kt ) {
                //cout << "SM: obs=";
                //LW1_State::print_literal(cout, kt->first, &instance_);
                //cout << ", trigger=" << (kt->first != value_key) << flush;
                if( kt->first != value_key ) {
                    sensing_models_as_cnf[sensed_literal][var_key].push_back(&kt->second);
                    //cout << ", cnf=";
                    //LW1_State::print_cnf(cout, kt->second, &kp_instance_);
                }
                //cout << endl;
            }
        }
    }
}

bool LW1_Solver::is_forbidden(int literal) const {
    assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
    return static_cast<const LW1_Instance&>(kp_instance_).is_forbidden(literal);
}

bool LW1_Solver::is_forbidden(const LW1_Solver::clause_t &clause) const {
    assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
    return static_cast<const LW1_Instance&>(kp_instance_).is_forbidden(clause);
}

void LW1_Solver::fill_atoms_to_var_map(const LW1_Instance &lw1) {
    const std::vector<LW1_Instance::Variable*> &vars = lw1.variables_;
    for (int v = 0; v < vars.size(); v++) {
        const LW1_Instance::Variable &var = *vars[v];
        // Iterating the domain of variables, inserting in atoms_to_vars the
        for (std::set<int>::const_iterator dom = var.domain_.cbegin(); dom != var.domain_.cend(); dom++) {
            assert(atoms_to_vars_.find(*dom) == atoms_to_vars_.cend());
            atoms_to_vars_.insert(make_pair(*dom, v));

        }
    }
}



#undef DEBUG
