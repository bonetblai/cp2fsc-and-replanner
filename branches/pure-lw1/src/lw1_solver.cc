#include <iostream>
#include "lw1_solver.h"
#include "classical_planner.h"
#include "utils.h"

using namespace std;

void LW1_Solver::compute_and_add_observations(const State &hidden,
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

void LW1_Solver::apply_inference(const Instance::Action *last_action,
                                 const set<int> &sensed,
                                 State &state) const {

    cout << Utils::magenta() << ">>> state before inference=";
    state.print(cout, kp_instance_);
    cout << Utils::normal() << endl;

    assert(translation_type_ == LW1);
    assert(dynamic_cast<const LW1_Instance*>(&kp_instance_) != 0);
    const LW1_Instance &lw1 = *static_cast<const LW1_Instance*>(&kp_instance_);

    if( options_.is_enabled("lw1:inference:up") ) {
        // find sensing models for given action that are incompatible with observations
        relevant_sensing_models_t relevant_sensing_models;
        if( last_action != 0 )
            fill_relevant_sensing_models(lw1, last_action, sensed, relevant_sensing_models);

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
        for( relevant_sensing_models_t::const_iterator it = relevant_sensing_models.begin(); it != relevant_sensing_models.end(); ++it ) {
            const sensing_models_t &sensing_models = it->second;
            for( size_t k = 0; k < sensing_models.size(); ++k ) {
                const cnf_t &cnf_for_sensing_model = *sensing_models[k];
                for( size_t j = 0; j < cnf_for_sensing_model.size(); ++j ) {
                    const clause_t &clause = cnf_for_sensing_model[j];
#if UP
                    Inference::Propositional::Clause cl;
                    for( size_t i = 0; i < clause.size(); ++i )
                        cl.push_back(clause[i]);
                    cnf.push_back(cl);
#endif
                }
            }
        }

        // 4. Kept (extra) static clauses // CHECK THIS

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
                    sensing_models[sensed_literal].push_back(&kt->second);
            } else {
                int value_key = !negated ? atom_index + 1 : -(atom_index + 1);
                for( map<int, vector<vector<int> > >::const_iterator kt = sensing_models_for_var.begin(); kt != sensing_models_for_var.end(); ++kt ) {
                    if( kt->first != value_key )
                        sensing_models[sensed_literal].push_back(&kt->second);
                }
            }
        }
    }
}

