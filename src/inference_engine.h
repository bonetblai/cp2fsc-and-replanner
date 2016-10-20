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

#ifndef INFERENCE_ENGINE_H
#define INFERENCE_ENGINE_H

#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "new_csp.h"
#include "inference.h"
#include "lw1_problem.h"
#include "options.h"
#include "state.h"
#include "utils.h"

//#define DEBUG

namespace Inference {

  typedef std::vector<int> clause_or_term_t;
  typedef std::vector<clause_or_term_t> cnf_or_dnf_t;
  typedef std::vector<const cnf_or_dnf_t*> sensing_models_as_cnf_or_dnf_t;
  typedef std::map<int, std::map<int, sensing_models_as_cnf_or_dnf_t> > relevant_sensing_models_t;

  void fill_atoms_to_var_map(const LW1_Instance &lw1_instance, std::map<int, int> &atoms_to_vars);
  void fill_relevant_sensing_models(const Options::Mode &options,
                                    const Instance &instance,
                                    const LW1_Instance &lw1_instance,
                                    const Instance::Action *last_action,
                                    const std::set<int> &sensed_at_step,
                                    relevant_sensing_models_t &relevant_sensing_models,
                                    bool as_k_cnf);

  template<typename T>
  class Engine {
    protected:
      const std::string name_;
      const Instance &instance_;
      const LW1_Instance &lw1_instance_;
      const Options::Mode &options_;

      virtual void internal_apply_inference(const Instance::Action *last_action,
                                            const std::set<int> &sensed_at_step,
                                            T &state) const = 0;

    public:
      Engine(const std::string &name, const Instance &instance, const LW1_Instance &lw1_instance, const Options::Mode &options)
        : name_(name),
          instance_(instance),
          lw1_instance_(lw1_instance),
          options_(options) {
      }
      virtual ~Engine() { }
      virtual void reset() = 0;
      void apply_inference(const Instance::Action *last_action,
                           const std::set<int> &sensed_at_step,
                           T &state) const {
#ifdef DEBUG
          std::cout << Utils::magenta() << ">>> state before inference=";
          state.print(std::cout, lw1_instance_);
          std::cout << Utils::normal() << std::endl;

          if( last_action != 0 )
              std::cout << "Last action=" << last_action->name_ << std::endl;
          else
              std::cout << "Last action=" << last_action << std::endl;
#endif

          float start_time = Utils::read_time_in_seconds();
          internal_apply_inference(last_action, sensed_at_step, state);
          float end_time = Utils::read_time_in_seconds();
          lw1_instance_.increase_inference_time(end_time - start_time);

#ifdef DEBUG
          std::cout << Utils::green() << ">>> state  after inference=";
          state.print(std::cout, lw1_instance_);
          std::cout << Utils::normal() << std::endl;
#endif
      }
  };

  template<typename T>
  class ForwardChaining : public Engine<T> {
    using Engine<T>::instance_;
    using Engine<T>::lw1_instance_;
    using Engine<T>::options_;

    protected:
      virtual void internal_apply_inference(const Instance::Action *last_action,
                                            const std::set<int> &sensed_at_step,
                                            T &state) const {
          assert(options_.is_enabled("lw1:inference:forward-chaining"));

#ifdef DEBUG
          std::cout << Utils::cyan() << "Using inference: 'forward-chaining' (FC)" << Utils::normal() << std::endl;
#endif

          // add observations as state literals
          for( std::set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
              int sensed_literal = *it;
              if( sensed_literal > 0 ) {
                  --sensed_literal;
                  state.remove(2*sensed_literal + 1);
                  state.add(2*sensed_literal);
#ifdef DEBUG
                  std::cout << Utils::yellow() << "[FC] Adding sensed: ";
                  LW1_State::print_literal(std::cout, 1 + 2*sensed_literal, &lw1_instance_);
                  std::cout << Utils::normal() << std::endl;
#endif
              } else {
                  sensed_literal = -sensed_literal - 1;
                  state.remove(2*sensed_literal);
                  state.add(2*sensed_literal + 1);
#ifdef DEBUG
                  std::cout << Utils::yellow() << "[FC] Adding sensed: ";
                  LW1_State::print_literal(std::cout, 1 + 2*sensed_literal + 1, &lw1_instance_);
                  std::cout << Utils::normal() << std::endl;
#endif
              }
          }

          // unleash inference
          bool fix_point_reached = false;
          while( !fix_point_reached ) {
              T old_state(state);
              for( size_t k = lw1_instance_.first_deductive_action(); k < lw1_instance_.last_deductive_action(); ++k ) {
                  const Instance::Action &act = *lw1_instance_.actions_[k];
                  if( state.applicable(act) ) {
                      state.apply(act);
#ifdef DEBUG
                      act.print(std::cout, lw1_instance_);
#endif
                  }
              }
              fix_point_reached = old_state == state;
          }
      }

    public:
      ForwardChaining(const Instance &instance, const LW1_Instance &lw1_instance_, const Options::Mode &options)
        : Engine<T>("forward-chaining", instance, lw1_instance_, options) {
      }
      virtual ~ForwardChaining() { }
      virtual void reset() { }
  };

  template<typename T>
  class UnitPropagation : public Engine<T> {
    using Engine<T>::instance_;
    using Engine<T>::lw1_instance_;
    using Engine<T>::options_;

    protected:
      std::map<int, int> atoms_to_vars_;
      std::set<Propositional::Clause> base_theory_axioms_;
      size_t frontier_;
      mutable Propositional::CNF cnf_;

      void restore_cnf() const {
          cnf_.erase(cnf_.begin() + 1 + frontier_, cnf_.end());
      }
      bool is_forbidden(int literal) const {
          assert(dynamic_cast<const LW1_Instance*>(&lw1_instance_) != 0);
          return static_cast<const LW1_Instance&>(lw1_instance_).is_forbidden(literal);
      }
      bool is_forbidden(const std::vector<int> &clause) const {
          assert(dynamic_cast<const LW1_Instance*>(&lw1_instance_) != 0);
          return static_cast<const LW1_Instance&>(lw1_instance_).is_forbidden(clause);
      }

      virtual void internal_apply_inference(const Instance::Action *last_action,
                                            const std::set<int> &sensed_at_step,
                                            T &state) const {
          assert(options_.is_enabled("lw1:inference:up"));
          assert(dynamic_cast<const LW1_Instance*>(&lw1_instance_) != 0);
          const LW1_Instance &lw1_instance = static_cast<const LW1_Instance&>(lw1_instance_);

#ifdef DEBUG
          std::cout << Utils::cyan() << "Using inference: 'unit propagation'" << Utils::normal() << std::endl;
#endif

          // find sensing models for given action that are incompatible with observations
          relevant_sensing_models_t relevant_sensing_models_as_k_cnf;
          if( last_action != 0 )
              fill_relevant_sensing_models(options_, instance_, lw1_instance, last_action, sensed_at_step, relevant_sensing_models_as_k_cnf, true);

          // construct logical theory for performing inference with unit propagation
          Inference::Propositional::CNF cnf;
          std::set<Inference::Propositional::Clause> base_theory;

          if( options_.is_enabled("lw1:inference:up:preload") )
              cnf = cnf_;

          // 0. Add observations as unit clauses
          if( options_.is_enabled("lw1:inference:up:enhanced") || options_.is_enabled("lw1:boost:literals-for-observables") ) {
              for( std::set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
                  int k_literal = *it > 0 ? 2 * (*it - 1) : 2 * (-*it - 1) + 1;
#ifdef DEBUG
                  std::cout << Utils::red() << "[UP: Theory] Add obs literal: ";
                  state.print_literal(std::cout, 1 + k_literal, &lw1_instance_);
                  std::cout << Utils::normal() << std::endl;
#endif
                  Inference::Propositional::Clause cl;
                  cl.push_back(1 + k_literal);
                  cnf.push_back(cl);
                  base_theory.insert(cl);
              }
          }

          // 1. Positive literals from state
          for( typename T::const_iterator it = state.begin(); it != state.end(); ++it ) {
#ifdef DEBUG
              std::cout << Utils::red() << "[UP] [Theory] Add literal from state: ";
              state.print_literal(std::cout, 1 + *it, &lw1_instance_);
              std::cout << Utils::normal() << std::endl;
#endif
              Inference::Propositional::Clause cl;
              cl.push_back(1 + *it); // CHECK: en implementacion de clause, 'push_back' es un 'insert'
              cnf.push_back(cl);
              base_theory.insert(cl);
          }

          // 2. Axioms: D'
          if( !options_.is_enabled("lw1:inference:up:preload") ) {
              for( std::vector<std::vector<int> >::const_iterator it = lw1_instance.clauses_for_axioms_.begin(); it != lw1_instance.clauses_for_axioms_.end(); ++it ) {
                  const std::vector<int> &clause = *it;
#ifdef DEBUG
                  std::cout << Utils::red() << "[UP] [Theory] Add axiom: ";
                  state.print_clause_or_term(std::cout, clause, &lw1_instance_);
                  std::cout << Utils::normal() << std::endl;
#endif
                  Inference::Propositional::Clause cl;
                  for( int k = 0; k < int(clause.size()); ++k )
                      cl.push_back(clause[k]);
                  cnf.push_back(cl);
                  base_theory.insert(cl);
              }
          }

          // 3. Clauses from sensing models: K_o
          for( relevant_sensing_models_t::const_iterator it = relevant_sensing_models_as_k_cnf.begin(); it != relevant_sensing_models_as_k_cnf.end(); ++it ) {
              int sensed_literal = it->first;
              for( std::map<int, sensing_models_as_cnf_or_dnf_t>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                  int var_key = jt->first;
                  const LW1_Instance::Variable &variable = *lw1_instance.variables_[var_key];
                  if( variable.is_state_variable() ) {
                      assert(jt->second.empty());
                      int k_literal = sensed_literal > 0 ? 1 + 2*(sensed_literal - 1) : 1 + 2*(-sensed_literal - 1) + 1;
#ifdef DEBUG
                      std::cout << Utils::red() << "[UP] [Theory] Add obs (state) literal: ";
                      state.print_literal(std::cout, k_literal, &lw1_instance_);
                      std::cout << Utils::normal() << std::endl;
#endif
                      Inference::Propositional::Clause cl;
                      cl.push_back(k_literal);
                      cnf.push_back(cl);
                  } else {
                      const sensing_models_as_cnf_or_dnf_t &sensing_models_as_k_cnf = jt->second;
                      for( int k = 0; k < int(sensing_models_as_k_cnf.size()); ++k ) {
                          const cnf_or_dnf_t &k_cnf_for_sensing_model = *sensing_models_as_k_cnf[k];
                          for( int j = 0; j < int(k_cnf_for_sensing_model.size()); ++j ) {
                              const clause_or_term_t &clause = k_cnf_for_sensing_model[j];
#ifdef DEBUG
                              std::cout << Utils::red() << "[UP] [Theory] Add K_o clause: ";
                              state.print_clause_or_term(std::cout, clause, &lw1_instance_);
                              std::cout << Utils::normal() << std::endl;

                              // The clause holds the indexes for the atoms
                              // To find it in atoms_, 1 must be substracted.
#ifdef DEBUG
//                              CHECK: In UP problems, K_atoms can be encountered which are not in atoms_to_var_map_
//                              as some variables (for example, wumpus) can have reduced domains.
//                              This print is commented out as a precaution.
//
//                              for( auto cl = clause.cbegin(); cl != clause.cend(); ++cl ) { // CHECK: remove auto
//                                  int cl_index = abs(*cl);
//                                  int k_literal = cl_index > 0 ? (cl_index - 1) / 2 : (-cl_index - 1) / 2 + 1;
//                                  cout << Utils::magenta() << "[UP] Related variable: ";
//                                  cout << lw1_instance.variables_[atoms_to_vars_.at(k_literal)]->name_;
//                                  cout << Utils::normal() << endl;
//                              }
#endif

#endif
                              Inference::Propositional::Clause cl;
                              for( int i = 0; i < int(clause.size()); ++i )
                                  cl.push_back(clause[i]);
                              cnf.push_back(cl);
                          }
                      }
                  }
              }
          }

          // 4. Keep (extra) static clauses
          if( options_.is_enabled("lw1:inference:up:enhanced") ) {
              std::cout << Utils::internal_error() << "lw1:inference:up:enhanced is EXPERIMENTAL!" << std::endl;
              exit(-1);

              assert(dynamic_cast<LW1_State*>(&state) != 0);
              for( int k = 0; k < int(state.cnf_.size()); ++k ) {
                  const clause_or_term_t &clause = state.cnf_[k];
#ifdef DEBUG
                  std::cout << Utils::red() << "[UP] [Theory] Add extra clause: ";
                  state.print_clause_or_term(std::cout, clause, &lw1_instance_);
                  std::cout << Utils::normal() << std::endl;
#endif
                  Inference::Propositional::Clause cl;
                  for( int i = 0; i < int(clause.size()); ++i )
                      cl.push_back(clause[i]);
                  cnf.push_back(cl);
                  base_theory.insert(cl);
              }
          }

          // 5. Perform inference
          Inference::Propositional::CNF result;
          std::vector<int> assignment;
          if( options_.is_enabled("lw1:inference:up:watched-literals") ) {
#ifdef DEBUG
              std::cout << Utils::cyan() << "[UP] Using method: 'watched-literals'" << Utils::normal() << std::endl;
#endif
              Inference::Propositional::WatchedLiterals wl;
              wl.solve(cnf, assignment);
              if( options_.is_enabled("lw1:inference:up:lookahead") ) {
                  std::cout << Utils::internal_error() << "lw1:inference:up:lookahead is EXPERIMENTAL!" << std::endl;
                  exit(-1);

#ifdef DEBUG
                  std::cout << Utils::cyan() << "[U] Using one-lookahead for 'watched-literals'" << Utils::normal() << std::endl;
#endif
                  wl.lookahead(cnf, assignment);
              }
          } else {
#ifdef DEBUG
              std::cout << Utils::cyan() << "[UP] Using method: 'DPLL'" << Utils::normal() << std::endl;
#endif
              Inference::Propositional::DPLL up;
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
                      std::cout << Utils::yellow() << "[UP] [State] Add inferred literal: ";
                      state.print_literal(std::cout, i, &lw1_instance_);
                      std::cout << Utils::normal() << std::endl;
#endif
                  }
              }
          } else {
              for( int k = 0; k < int(result.size()); ++k ) {
                  if( result[k].empty() ) {
                      std::cout << Utils::error() << "[UP] inconsistency derived during inference" << std::endl;
                      exit(255);
                  }
              }

              for( int k = 0; k < int(result.size()); ++k ) {
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
                          std::cout << Utils::yellow() << "[UP] [State] Add inferred literal: ";
                          state.print_literal(std::cout, literal, &lw1_instance_);
                          std::cout << Utils::normal() << std::endl;
#endif
                      }
                  }
              }
          }

          // 7. Insert non-forbidden clauses in result into state
          if( options_.is_enabled("lw1:inference:up:enhanced") ) {
              std::cout << Utils::internal_error() << "lw1:inference:up:enhanced is EXPERIMENTAL!" << std::endl;
              exit(-1);

              state.cnf_.clear();
              for( int k = 0; k < int(result.size()); ++k ) {
                  const Inference::Propositional::Clause &cl = result[k];
                  if( base_theory.find(cl) != base_theory.end() ) continue;
                  if( base_theory_axioms_.find(cl) != base_theory_axioms_.end() ) continue;
                  if( cl.size() > 1 ) {
                      clause_or_term_t clause;
                      for( Inference::Propositional::Clause::const_iterator it = cl.begin(); it != cl.end(); ++it )
                          clause.push_back(*it);
                      if( is_forbidden(clause) ) continue;
#ifdef DEBUG
                      std::cout << Utils::yellow() << "[UP] [State] Add clause: ";
                      state.print_clause_or_term(std::cout, clause, &lw1_instance_);
                      std::cout << Utils::normal() << std::endl;
#endif
                      state.cnf_.push_back(clause);
                  }
              }
          }

          // restore CNF
          if( options_.is_enabled("lw1:inference:up:preload") )
              restore_cnf();
      }

    public:
      UnitPropagation(const Instance &instance, const LW1_Instance &lw1_instance, const Options::Mode &options)
        : Engine<T>("unit-propagation", instance, lw1_instance, options) {
          for( size_t j = 0; j < lw1_instance.clauses_for_axioms_.size(); ++j ) {
              const std::vector<int> &clause = lw1_instance.clauses_for_axioms_[j];
              Inference::Propositional::Clause cl;
              for( size_t k = 0; k < clause.size(); ++k )
                  cl.push_back(clause[k]);
              cnf_.push_back(cl);
              base_theory_axioms_.insert(cl);
          }
          frontier_ = cnf_.size() - 1;

          // map atoms to vars 
          fill_atoms_to_var_map(lw1_instance, atoms_to_vars_);
      }
      virtual ~UnitPropagation() { }
      virtual void reset() { }
  };

  template<typename T>
  class AC3 : public Engine<T> {
    using Engine<T>::instance_;
    using Engine<T>::lw1_instance_;
    using Engine<T>::options_;

    protected:
      std::map<int, int> atoms_to_vars_;
      Inference::CSP2::Csp csp_;
      Inference::CSP2::AC3 ac3_;

      virtual void internal_apply_inference(const Instance::Action *last_action,
                                            const std::set<int> &sensed_at_step,
                                            T &state) const {
          assert(options_.is_enabled("lw1:inference:ac3"));

#ifdef DEBUG
          std::cout << Utils::cyan() << "Using inference: 'ac3' (AC3)" << Utils::normal() << std::endl;
#endif

          // reset current domains of simple variables
          csp_.reset_current_domains();

          // find sensing models for given action that are incompatible with observations
          relevant_sensing_models_t relevant_sensing_models_as_k_dnf;
          if( last_action != 0 )
              fill_relevant_sensing_models(options_, instance_, lw1_instance_, last_action, sensed_at_step, relevant_sensing_models_as_k_dnf, false);

          // 0. Domains are original domains with values pruned as indicated with the K-literals in state.
          // Basic constraints relate variable groups to state variable and variable groups to variable
          // groups.
          for( typename T::const_iterator it = state.begin(); it != state.end(); ++it ) {
              if( state.is_special(*it + 1, &lw1_instance_) ) continue;
#ifdef DEBUG
              std::cout << Utils::red() << "[CSP] Added literal from state: ";
              state.print_literal(std::cout, 1 + *it, &lw1_instance_);
              std::cout << Utils::normal() << std::endl;
#endif
              csp_.prune_domain_of_var(1 + *it);
          }

          // 1. Add observation. Pruned variable domains using k-dnf for observation. For each observation,
          // (a) if observation refers to state variable (i.e. state variable is observable), prune domain
          // of CSP variable corresponding to state variable, (b) if observation can be filtered in
          // variable group, prune from domain of CSP variable corresponding to variable group all
          // valuations that do not satisfy k-dnf, and else (c) observation is of type V=v, use the k-dnf
          // to construct constraints among the state variables mentioned in DNF

          for( relevant_sensing_models_t::const_iterator it = relevant_sensing_models_as_k_dnf.begin(); it != relevant_sensing_models_as_k_dnf.end(); ++it ) {
              int sensed_literal = it->first;

              for( std::map<int, sensing_models_as_cnf_or_dnf_t>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                  int var_key = jt->first;
                  const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_key];
                  std::pair<int, int> key(var_key, sensed_literal);
#ifdef DEBUG
                  std::cout << "[AC3] sensed literal: var=" << variable.name() << ", value=" << std::flush;
                  LW1_State::print_literal(std::cout, sensed_literal, &instance_);
                  std::cout << ", key=(" << var_key << "," << sensed_literal << ")" << std::endl;
#endif
                  if( variable.is_state_variable() ) {
                      // observation is state variable, filter it directly in variable domain
                      assert(jt->second.empty());
                      int k_literal = sensed_literal > 0 ? 1 + 2*(sensed_literal - 1) : 1 + 2*(-sensed_literal - 1) + 1;
#ifdef DEBUG
                      std::cout << Utils::red() << "[AC3] Add obs (state) k-literal: ";
                      state.print_literal(std::cout, k_literal, &lw1_instance_);
                      std::cout << Utils::normal() << std::endl;
#endif
                      csp_.prune_domain_of_var(k_literal);
                  } else if( lw1_instance_.filtering_groups_.find(key) != lw1_instance_.filtering_groups_.end() ) {
                      // observation can be filtered in variable group. Prune all valuations that are
                      // not consistent with k-dnf
                      int vg = lw1_instance_.filtering_groups_.at(key);
                      const sensing_models_as_cnf_or_dnf_t& sensing_models_as_k_dnf = jt->second;
                      for( size_t k = 0; k < sensing_models_as_k_dnf.size(); ++k ) {
                          const cnf_or_dnf_t& k_dnf_for_sensing_model = *sensing_models_as_k_dnf[k];
                          csp_.prune_valuations_of_groups(vg, k_dnf_for_sensing_model);
#ifdef DEBUG
                          std::cout << Utils::blue() << "[AC3] k-dnf or k-cnf: index=" << k << ", formula=";
                          state.print_cnf_or_dnf(std::cout, k_dnf_for_sensing_model, &lw1_instance_);
                          std::cout << Utils::normal() << std::endl;

                          for( size_t j = 0; j < k_dnf_for_sensing_model.size(); ++j ) {
                              const clause_or_term_t& term = k_dnf_for_sensing_model[j];
                              std::cout << Utils::cyan() << "[AC3] Clause or term: ";
                              state.print_clause_or_term(std::cout, term, &lw1_instance_);
                              std::cout << Utils::normal() << std::endl;
                          }
#endif
                      }

                  } else {
                      // there is no variable group where to filter observation. Use k-dnf to generate constraints in CSP
                      const sensing_models_as_cnf_or_dnf_t &sensing_models_as_k_dnf = jt->second;
                      for( size_t k = 0; k < sensing_models_as_k_dnf.size(); ++k ) {
                          const cnf_or_dnf_t &k_dnf_for_sensing_model = *sensing_models_as_k_dnf[k];
#ifdef DEBUG
                          std::cout << Utils::blue() << "[AC3] k-dnf: index =" << k << ", formula =" << Utils::normal();
                          state.print_cnf_or_dnf(std::cout, k_dnf_for_sensing_model, &lw1_instance_);
                          std::cout << std::endl;
#endif
                          bool possible = true;
                          std::set<int> possible_domain;
                          for( size_t j = 0; j < k_dnf_for_sensing_model.size(); ++j ) {
                              const clause_or_term_t &term = k_dnf_for_sensing_model[j];

                              if( term.size() > 1 ) {
                                  possible = false;
                                  break;
                              }
                              assert(term.size() == 1);
#ifdef DEBUG
                              std::cout << Utils::red() << "[AC3] Adding to possible domain_: ";
                              state.print_clause_or_term(std::cout, term, &lw1_instance_);
                              std::cout << Utils::normal() << std::endl;
#endif
                              possible_domain.insert(term[0]);
                          }
                          if( possible )
                              csp_.intersect_domain_of_var(possible_domain);
                      }
                  }
              }
          }

          // 2. Make the CSP arc consistent by running AC3. The resulting CSP should be consistent
          // (i.e. the domain of each variable should be non empty). Otherwise, there is an error in
          // the planning model
          ac3_.solve(csp_, state);
      }

    public:
      AC3(const Instance &instance, const LW1_Instance &lw1_instance, const Options::Mode &options)
        : Engine<T>("ac3", instance, lw1_instance, options),
          csp_(lw1_instance),
          ac3_(lw1_instance) {
          fill_atoms_to_var_map(lw1_instance_, atoms_to_vars_);
          csp_.set_atoms_to_var_map(atoms_to_vars_);
          csp_.calculate_common_variables_in_groups();
          ac3_.calculate_arcs(csp_);
      }
      virtual ~AC3() { }
      virtual void reset() {
          // reset current domain for variable groups; done once
          // per instance (hidden state) as variable groups should
          // correspond to static variables
          csp_.reset_current_domains_for_variable_groups();
      }
  };
} // namespace Inference

#undef DEBUG

#endif

