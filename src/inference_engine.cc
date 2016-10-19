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
#include <map>
#include <set>
#include <string>
#include <vector>

#include "inference_engine.h"

using namespace std;

//#define DEBUG

namespace Inference {

  void fill_atoms_to_var_map(const LW1_Instance &lw1_instance, map<int, int> &atoms_to_vars) {
      atoms_to_vars.clear();
      const vector<LW1_Instance::Variable*> &vars = lw1_instance.variables_;
      for( size_t var_index = 0; var_index < vars.size(); ++var_index ) {
          const LW1_Instance::Variable &variable = *vars[var_index];

          // iteraete over domain of variable to insert atoms into map
          for( set<int>::const_iterator it = variable.domain().begin(); it != variable.domain().end(); ++it ) {
              assert(atoms_to_vars.find(*it) == atoms_to_vars.end());
              atoms_to_vars.insert(make_pair(*it, var_index));
          }
      }
  }

  void fill_relevant_sensing_models(const Options::Mode &options,
                                    const Instance &instance,
                                    const LW1_Instance &lw1_instance,
                                    const Instance::Action *last_action,
                                    const set<int> &sensed_at_step,
                                    relevant_sensing_models_t &relevant_sensing_models,
                                    bool as_k_cnf) {
      assert(last_action != 0);

      // compute action-key for accessingn sensing models in lw1 instance
      string action_key;
      if( options.is_enabled("lw1:strict") ) {
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
          if( lw1_instance.sensing_models_as_k_cnf_.find(action_key) != lw1_instance.sensing_models_as_k_cnf_.end() )
              sensing_models_for_action_as_k_cnf = &lw1_instance.sensing_models_as_k_cnf_.at(action_key);
      } else {
          if( lw1_instance.sensing_models_as_k_dnf_.find(action_key) != lw1_instance.sensing_models_as_k_dnf_.end() )
              sensing_models_for_action_as_k_dnf = &lw1_instance.sensing_models_as_k_dnf_.at(action_key);
      }

      for( set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
          int sensed_literal = *it;
          int atom_index = sensed_literal < 0 ? -sensed_literal - 1 : sensed_literal - 1;
          bool negated = sensed_literal < 0;

#ifdef DEBUG
          cout << "[fill] sensed: literal=";
          LW1_State::print_literal(cout, sensed_literal, &instance);
          cout << ", index=" << atom_index << Utils::normal() << endl;
#endif

          if( options.is_enabled("solver:print:sensed-literals") ) {
              cout << Utils::yellow() << "sensed: literal=";
              LW1_State::print_literal(cout, sensed_literal, &instance);
              cout << ", index=" << atom_index << Utils::normal() << endl;
          }

          map<int, vector<int> >::const_iterator jt = lw1_instance.variables_for_atom_.find(atom_index);
          assert(jt != lw1_instance.variables_for_atom_.end());
          assert(!jt->second.empty());

          // if as_k_cnf, collect sensing models as k-cnf for values incompatible with obs. Otherwise,
          // collect sensing model as k-dnf for values compatible with obs. For binary vars (i.e. w/
          // domain of size 1), need to consider complemented value explicitly
          for( int k = 0; k < int(jt->second.size()); ++k ) {
              int var_key = jt->second[k];
              const LW1_Instance::Variable &variable = *lw1_instance.variables_[var_key];

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
                      LW1_State::print_literal(cout, kt->first, &instance);
                      cout << ", trigger=" << (kt->first != sensed_literal) << flush;
#endif
                      if( kt->first != sensed_literal ) {
                          relevant_sensing_models[sensed_literal][var_key].push_back(&kt->second);
#ifdef DEBUG
                          cout << ", k-cnf=";
                          LW1_State::print_cnf_or_dnf(cout, kt->second, &lw1_instance);
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
                      LW1_State::print_literal(cout, kt->first, &instance);
                      cout << ", trigger=" << (kt->first != sensed_literal) << flush;
#endif
                      if( kt->first == sensed_literal ) {
                          relevant_sensing_models[sensed_literal][var_key].push_back(&kt->second);
#ifdef DEBUG
                          cout << ", k-dnf=";
                          LW1_State::print_cnf_or_dnf(cout, kt->second, &lw1_instance);
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

} // namespace Inference

