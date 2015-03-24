#include <iostream>
#include "lw1_solver.h"
#include "classical_planner.h"
#include "utils.h"
#include "Inference.h"

using namespace std;

void LW1_Solver::compute_and_add_observations(const STATE_CLASS &hidden,
                                              STATE_CLASS &state,
                                              set<int> &sensors,
                                              set<int> &sensed) const {
    assert(sensors.empty());
    assert(sensed.empty());

    // fire observation rules
    index_set observations;
    for( size_t k = 0; k < instance_.n_sensors(); ++k ) {
        const Instance::Sensor &r = *instance_.sensors_[k];
        if( hidden.satisfy(r.condition_) ) {
            sensors.insert(k);
            for( index_set::const_iterator it = r.sense_.begin(); it != r.sense_.end(); ++it ) {
                int obs = *it > 0 ? *it - 1 : -*it - 1;
                sensed.insert(hidden.satisfy(obs) ? 1 + obs : -(1 + obs));
            }
        }
    }
}

void LW1_Solver::apply_inference(const Instance::Action *last_action,
                                 const set<int> &sensed,
                                 STATE_CLASS &state) const {

    float start_time = Utils::read_time_in_seconds();

    cout << Utils::magenta() << ">>> state before inference=";
    state.print(cout, kp_instance_);
    cout << Utils::normal() << endl;

    if( last_action != 0 )
        cout << "Last action=" << last_action->name_ << endl;
    else
        cout << "Last action=" << last_action << endl;

    assert(translation_type_ == LW1);
    assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
    const LW1_Instance &lw1 = *static_cast<const LW1_Instance*>(&kp_instance_);

    if( options_.is_enabled("lw1:inference:forward-chaining") ) {
        cout << Utils::cyan() << "Using inference: 'forward-chaining'" << Utils::normal() << endl;

        // add observations as state literals
        for( set<int>::const_iterator it = sensed.begin(); it != sensed.end(); ++it ) {
            int sensed_literal = *it;
            if( sensed_literal > 0 ) {
                --sensed_literal;
                state.remove(2*sensed_literal + 1);
                state.add(2*sensed_literal);
                //cout << "Adding sensed: "; LW1_State::print_literal(cout, 1 + 2*sensed_literal, &kp_instance_); cout << endl;
            } else {
                sensed_literal = -sensed_literal - 1;
                state.remove(2*sensed_literal);
                state.add(2*sensed_literal + 1);
                //cout << "Adding sensed: "; LW1_State::print_literal(cout, 1 + 2*sensed_literal + 1, &kp_instance_); cout << endl;
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
                    //act.print(cout, kp_instance_);
                }
            }
            fix_point_reached = old_state == state;
        }
    } else if( options_.is_enabled("lw1:inference:up") ) {
        cout << Utils::cyan() << "Using inference: 'unit propagation'" << Utils::normal() << endl;

        // find sensing models for given action that are incompatible with observations
        relevant_sensing_models_t relevant_sensing_models;
        if( last_action != 0 )
            fill_relevant_sensing_models(lw1, last_action, sensed, relevant_sensing_models);

        // construct logical theory for performing inference with unit propagation
#if defined(UP)
        set<Inference::Propositional::Clause> base_theory;
        Inference::Propositional::CNF cnf;
#endif

        // 0. Add observations as unit clauses
        set<int> unit_clauses_for_observations;
        if( options_.is_enabled("lw1:inference:up:enhanced") ) {
            for( set<int>::const_iterator it = sensed.begin(); it != sensed.end(); ++it ) {
                int k_literal = *it > 0 ? 2 * (*it - 1) : 2 * (-*it - 1) + 1;
                unit_clauses_for_observations.insert(1 + k_literal);
                //cout << Utils::red() << "[Theory] Add obs literal: ";
                //state.print_literal(cout, 1 + k_literal, &kp_instance_);
                //cout << Utils::normal() << endl;
#if defined(UP)
                Inference::Propositional::Clause cl;
                cl.push_back(1 + k_literal);
                cnf.push_back(cl);
                base_theory.insert(cl);
#endif
            }
        }

        // 1. Positive literals from state
        for( STATE_CLASS::const_iterator it = state.begin(); it != state.end(); ++it ) {
            //cout << Utils::red() << "[Theory] Add literal: ";
            //state.print_literal(cout, 1 + *it, &kp_instance_);
            //cout << Utils::normal() << endl;
#if defined(UP)
            Inference::Propositional::Clause cl;
            cl.push_back(1 + *it); // NOTA: en implementacion de clause, 'push_back' es un 'insert'
            cnf.push_back(cl);
            base_theory.insert(cl);
#endif
        }

        // 2. Axioms: D'
        for( vector<vector<int> >::const_iterator it = lw1.clauses_for_axioms_.begin(); it != lw1.clauses_for_axioms_.end(); ++it ) {
            const vector<int> &clause = *it;
            //cout << Utils::red() << "[Theory] Add axiom: ";
            //state.print_clause(cout, clause, &kp_instance_);
            //cout << Utils::normal() << endl;
#if defined(UP)
            Inference::Propositional::Clause cl;
            for( size_t k = 0; k < clause.size(); ++k )
                cl.push_back(clause[k]);
            cnf.push_back(cl);
            base_theory.insert(cl);
#endif
        }

        // 3. Clauses from sensing models: K_o
        for( relevant_sensing_models_t::const_iterator it = relevant_sensing_models.begin(); it != relevant_sensing_models.end(); ++it ) {
            const sensing_models_t &sensing_models = it->second;
            for( size_t k = 0; k < sensing_models.size(); ++k ) {
                const cnf_t &cnf_for_sensing_model = *sensing_models[k];
                for( size_t j = 0; j < cnf_for_sensing_model.size(); ++j ) {
                    const clause_t &clause = cnf_for_sensing_model[j];
                    //cout << Utils::red() << "[Theory] Add K_o clause: ";
                    //state.print_clause(cout, clause, &kp_instance_);
                    //cout << Utils::normal() << endl;
#if defined(UP)
                    Inference::Propositional::Clause cl;
                    for( size_t i = 0; i < clause.size(); ++i )
                        cl.push_back(clause[i]);
                    cnf.push_back(cl);
#endif
                }
            }
        }

        // 4. Kept (extra) static clauses
        if( options_.is_enabled("lw1:inference:up:enhanced") ) {
#if BASE_SELECTOR == 1
            assert(dynamic_cast<LW1_State*>(&state) != 0);
            for( size_t k = 0; k < state.cnf_.size(); ++k ) {
                const clause_t &clause = state.cnf_[k];
                cout << Utils::red() << "[Theory] Add extra clause: ";
                state.print_clause(cout, clause, &kp_instance_);
                cout << Utils::normal() << endl;
#    if defined(UP)
                Inference::Propositional::Clause cl;
                for( size_t i = 0; i < clause.size(); ++i )
                    cl.push_back(clause[i]);
                cnf.push_back(cl);
                base_theory.insert(cl);
#    endif
            }
#endif
        }

        // 5. Perform inference
#if defined(UP)
        Inference::Propositional::CNF result;
#endif
        if( options_.is_enabled("lw1:inference:up:1-lookahead") ) {
            cout << Utils::error() << "inference method 'lw1:inference:up:1-lookahead' not yet implemented" << endl;
            exit(255);
        } else {
#if defined(UP)
            float start_time = Utils::read_time_in_seconds();
            Inference::Propositional::UnitPropagation up;
            up.reduce(cnf, result);
            float end_time = Utils::read_time_in_seconds();
            kp_instance_.inference_time_ += end_time - start_time;
#endif
        }

        // 6. Insert positive literals from result into state
#if defined(UP)
        for( size_t k = 0; k < result.size(); ++k ) {
            if( result[k].empty() ) {
                cout << Utils::error() << "inconsistency derived during inference" << endl;
                exit(255);
            }
        }

        for( size_t k = 0; k < result.size(); ++k ) {
            const Inference::Propositional::Clause &cl = result[k];
            if( base_theory.find(cl) != base_theory.end() ) continue;
            if( cl.size() == 1 ) {
                int literal = *cl.begin();
                if( unit_clauses_for_observations.find(literal) != unit_clauses_for_observations.end() ) continue;
                if( is_forbidden(literal) ) continue;
                assert(literal != 0);
                assert((literal > 0) || options_.is_enabled("lw1:inference:up:enhanced"));
                if( literal > 0 ) {
                    state.add(literal - 1);
                    cout << Utils::yellow() << "[State] Add inferred literal: ";
                    state.print_literal(cout, literal, &kp_instance_);
                    cout << Utils::normal() << endl;
                }
            }
        }
#endif

        // 7. Insert non-forbidden clauses in result into state
        if( options_.is_enabled("lw1:inference:up:enhanced") ) {
#if BASE_SELECTOR == 1
#    if defined(UP)
            for( size_t k = 0; k < result.size(); ++k ) {
                const Inference::Propositional::Clause &cl = result[k];
                if( base_theory.find(cl) != base_theory.end() ) continue;
                if( cl.size() > 1 ) {
                    clause_t clause;
                    for( Inference::Propositional::Clause::const_iterator it = cl.begin(); it != cl.end(); ++it )
                        clause.push_back(*it);
                    if( is_forbidden(clause) ) continue;

                    cout << Utils::yellow() << "[State] Add clause: ";
                    state.print_clause(cout, clause, &kp_instance_);
                    cout << Utils::normal() << endl;
                    state.cnf_.push_back(clause);
                }
            }
#    endif
#endif
        }
    } else {
        cout << Utils::error() << "unspecified inference method for lw1" << endl;
        exit(255);
    }

    // update time for inference
    float end_time = Utils::read_time_in_seconds();
    //kp_instance_.inference_time_ += end_time - start_time;

    cout << Utils::green() << ">>> state  after inference=";
    state.print(cout, kp_instance_);
    cout << Utils::normal() << endl;
}

void LW1_Solver::fill_relevant_sensing_models(const LW1_Instance &lw1,
                                              const Instance::Action *last_action,
                                              const set<int> &sensed,
                                              LW1_Solver::relevant_sensing_models_t &sensing_models) const {
    assert(last_action != 0);

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
        int value_key = !negated ? atom_index + 1 : -(atom_index + 1);

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
                    sensing_models[sensed_literal].push_back(&kt->second);
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

