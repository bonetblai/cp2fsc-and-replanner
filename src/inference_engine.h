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

#include "state.h"
#include "lw1_problem.h"
#include "csp.h"
#include "unit_propagation.h"
#include "options.h"
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

      virtual bool internal_apply_inference(const Instance::Action *last_action,
                                            const std::set<int> &sensed_at_step,
                                            T &state) const = 0;
      virtual bool internal_propagate(T &state) const = 0;

    public:
      Engine(const std::string &name, const Instance &instance, const LW1_Instance &lw1_instance, const Options::Mode &options)
        : name_(name),
          instance_(instance),
          lw1_instance_(lw1_instance),
          options_(options) {
      }
      virtual ~Engine() { }
      virtual void reset() = 0;
      bool apply_inference(const Instance::Action *last_action,
                           const std::set<int> &sensed_at_step,
                           T &state) const {
#ifdef DEBUG
          std::cout << Utils::magenta() << ">>> state before inference=";
          state.print(std::cout, lw1_instance_);
          std::cout << Utils::normal() << std::endl;

          if( last_action != nullptr )
              std::cout << "Last action=" << last_action->name() << std::endl;
          else
              std::cout << "Last action=" << last_action << std::endl;
#endif

          float start_time = Utils::read_time_in_seconds();
          bool status = internal_apply_inference(last_action, sensed_at_step, state);
          float end_time = Utils::read_time_in_seconds();
          lw1_instance_.increase_inference_time(end_time - start_time);

#ifdef DEBUG
          std::cout << Utils::green() << ">>> state  after inference=";
          state.print(std::cout, lw1_instance_);
          std::cout << Utils::normal() << std::endl;
#endif

          return status;
      }
      bool propagate(T &state) const {
#ifdef DEBUG
          std::cout << Utils::magenta() << ">>> state before inference=";
          state.print(std::cout, lw1_instance_);
          std::cout << Utils::normal() << std::endl;
#endif

          float start_time = Utils::read_time_in_seconds();
          bool status = internal_propagate(state);
          float end_time = Utils::read_time_in_seconds();
          lw1_instance_.increase_inference_time(end_time - start_time);

#ifdef DEBUG
          std::cout << Utils::green() << ">>> state  after inference=";
          state.print(std::cout, lw1_instance_);
          std::cout << Utils::normal() << std::endl;
#endif

          return status;
      }
  };

  template<typename T>
  class ForwardChaining : public Engine<T> {
    using Engine<T>::instance_;
    using Engine<T>::lw1_instance_;
    using Engine<T>::options_;

    protected:
      virtual bool internal_apply_inference(const Instance::Action *last_action,
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
                  std::cout << "[" << 2*sensed_literal << "]" << Utils::normal() << std::endl;
#endif
              } else {
                  sensed_literal = -sensed_literal - 1;
                  state.remove(2*sensed_literal);
                  state.add(2*sensed_literal + 1);
#ifdef DEBUG
                  std::cout << Utils::yellow() << "[FC] Adding sensed: ";
                  LW1_State::print_literal(std::cout, 1 + 2*sensed_literal + 1, &lw1_instance_);
                  std::cout << "[" << 2*sensed_literal + 1 << "]" << Utils::normal() << std::endl;
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
          return true; // forward chaining cannot detect inconsistencies
      }
      virtual bool internal_propagate(T &state) const {
          std::cout << Utils::internal_error() << "forward-chaining: internal_propagate() not yet implemented" << std::endl;
          exit(-1);
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
      mutable float up_time_;

      // base theories are used to detect new clauses inferred by UP
      mutable Propositional::CNF cnf_;
      mutable std::set<Propositional::Clause> base_theory_;

      // implementations of UP
      Propositional::StandardUP standard_; // inefficient implementation
      mutable Propositional::WatchedLiteralsUP watched_literals_; // efficient implementation (hopefully)

      // for storing the result of UP
      mutable Propositional::CNF reduced_cnf_;
      mutable std::vector<int> up_assignment_;

      void restore_cnf() const {
          cnf_.erase(cnf_.begin() + frontier_, cnf_.end());
          base_theory_.clear();
      }
      bool is_forbidden(int literal) const {
          assert(dynamic_cast<const LW1_Instance*>(&lw1_instance_) != nullptr);
          return static_cast<const LW1_Instance&>(lw1_instance_).is_forbidden(literal);
      }
      bool is_forbidden(const std::vector<int> &clause) const {
          assert(dynamic_cast<const LW1_Instance*>(&lw1_instance_) != nullptr);
          return static_cast<const LW1_Instance&>(lw1_instance_).is_forbidden(clause);
      }

      virtual bool internal_apply_inference(const Instance::Action *last_action,
                                            const std::set<int> &sensed_at_step,
                                            T &state) const {
          assert(options_.is_enabled("lw1:inference:up"));
          assert(dynamic_cast<const LW1_Instance*>(&lw1_instance_) != nullptr);
          const LW1_Instance &lw1_instance = static_cast<const LW1_Instance&>(lw1_instance_);

#ifdef DEBUG
          std::cout << Utils::cyan() << "Using inference: 'unit propagation'" << Utils::normal() << std::endl;
#endif

          // find sensing models for given action that are incompatible with observations
          relevant_sensing_models_t relevant_sensing_models_as_k_cnf;
          if( last_action != nullptr )
              fill_relevant_sensing_models(options_, instance_, lw1_instance, last_action, sensed_at_step, relevant_sensing_models_as_k_cnf, true);

          // check basic invariants
          assert(cnf_.empty() || options_.is_enabled("lw1:inference:up:preload"));
          assert(cnf_.size() == frontier_);

          // 0. Add observations as unit clauses
          if( options_.is_enabled("lw1:inference:up:enhanced") || options_.is_enabled("lw1:boost:literals-for-observables") ) {
              for( std::set<int>::const_iterator it = sensed_at_step.begin(); it != sensed_at_step.end(); ++it ) {
                  int k_literal = *it > 0 ? 2 * (*it - 1) : 2 * (-*it - 1) + 1;
                  cnf_.emplace_back(Propositional::Clause());
                  cnf_.back().emplace_back(1 + k_literal);
                  if( !options_.is_enabled("lw1:inference:up:watched-literals") )
                      base_theory_.insert(cnf_.back());
#ifdef DEBUG
                  std::cout << Utils::red() << "[UP] [Theory] Add obs literal: ";
                  LW1_State::print_literal(std::cout, 1 + k_literal, &lw1_instance_);
                  std::cout << "[" << k_literal << "]" << Utils::normal() << std::endl;
#endif
              }
          }

          // 1. Add positive literals from state
          for( typename T::const_iterator it = state.begin(); it != state.end(); ++it ) {
              assert(*it >= 0);
              cnf_.emplace_back(Propositional::Clause());
              cnf_.back().emplace_back(1 + *it);
              if( !options_.is_enabled("lw1:inference:up:watched-literals") )
                  base_theory_.insert(cnf_.back());
#ifdef DEBUG
              std::cout << Utils::red() << "[UP] [Theory] Add literal from state: ";
              LW1_State::print_literal(std::cout, 1 + *it, &lw1_instance_);
              std::cout << "[" << *it << "]" << Utils::normal() << std::endl;
#endif
          }

          // 2. Add axioms (if preload, these are already present)
          if( !options_.is_enabled("lw1:inference:up:preload") ) {
              for( std::vector<std::vector<int> >::const_iterator it = lw1_instance.clauses_for_axioms_.begin(); it != lw1_instance.clauses_for_axioms_.end(); ++it ) {
                  const std::vector<int> &clause = *it;
                  //cnf_.push_back(static_cast<const Propositional::Clause&>(clause));//CHECK: is this equivalent?
                  cnf_.emplace_back(static_cast<const Propositional::Clause&>(clause));
                  if( !options_.is_enabled("lw1:inference:up:watched-literals") )
                      base_theory_.insert(static_cast<const Propositional::Clause&>(clause));
#ifdef DEBUG
                  std::cout << Utils::red() << "[UP] [Theory] Add axiom: ";
                  state.print_clause_or_term(std::cout, clause, &lw1_instance_);
                  std::cout << Utils::normal() << std::endl;
#endif
              }
          }

          // 3. Add clauses from sensing models K_o
          for( relevant_sensing_models_t::const_iterator it = relevant_sensing_models_as_k_cnf.begin(); it != relevant_sensing_models_as_k_cnf.end(); ++it ) {
              int sensed_literal = it->first;
              for( std::map<int, sensing_models_as_cnf_or_dnf_t>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                  int var_key = jt->first;
                  const LW1_Instance::Variable &variable = *lw1_instance.variables_[var_key];
                  if( variable.is_state_variable() ) {
                      assert(jt->second.empty());
                      int k_literal = sensed_literal > 0 ? 2*(sensed_literal - 1) : 2*(-sensed_literal - 1) + 1;
                      cnf_.emplace_back(Propositional::Clause());
                      cnf_.back().emplace_back(1 + k_literal);
#ifdef DEBUG
                      std::cout << Utils::red() << "[UP] [Theory] Add obs (state) literal: ";
                      LW1_State::print_literal(std::cout, 1 + k_literal, &lw1_instance_);
                      std::cout << "[" << k_literal << "]" << Utils::normal() << std::endl;
#endif
                  } else {
                      const sensing_models_as_cnf_or_dnf_t &sensing_models_as_k_cnf = jt->second;
                      for( size_t k = 0; k < sensing_models_as_k_cnf.size(); ++k ) {
                          const cnf_or_dnf_t &k_cnf_for_sensing_model = *sensing_models_as_k_cnf[k];
                          for( size_t j = 0; j < k_cnf_for_sensing_model.size(); ++j ) {
                              const clause_or_term_t &clause = k_cnf_for_sensing_model[j];
                              //cnf_.push_back(static_cast<const Propositional::Clause&>(clause));//CHECK: is this equivalent?
                              cnf_.emplace_back(static_cast<const Propositional::Clause&>(clause));
#ifdef DEBUG
                              std::cout << Utils::red() << "[UP] [Theory] Add K_o clause: ";
                              state.print_clause_or_term(std::cout, clause, &lw1_instance_);
                              std::cout << Utils::normal() << std::endl;
#endif
                          }
                      }
                  }
              }
          }

          // 4. Add (extra) static clauses (if enhanced mode)
          if( options_.is_enabled("lw1:inference:up:enhanced") ) {
              std::cout << Utils::internal_error() << "lw1:inference:up:enhanced is EXPERIMENTAL!" << std::endl;
              exit(-1);

              assert(dynamic_cast<LW1_State*>(&state) != nullptr);
              for( size_t k = 0; k < state.cnf_.size(); ++k ) {
                  const clause_or_term_t &clause = state.cnf_[k];
                  //cnf_.push_back(static_cast<const Propositional::Clause&>(clause));//CHECK: is this equivalent?
                  cnf_.emplace_back(static_cast<const Propositional::Clause&>(clause));
                  if( !options_.is_enabled("lw1:inference:up:watched-literals") )
                      base_theory_.insert(static_cast<const Propositional::Clause&>(clause));
#ifdef DEBUG
                  std::cout << Utils::red() << "[UP] [Theory] Add extra clause: ";
                  state.print_clause_or_term(std::cout, clause, &lw1_instance_);
                  std::cout << Utils::normal() << std::endl;
#endif
              }
          }

          // 5. Do inference
          bool consistent = true;
          float up_start_time = Utils::read_time_in_seconds();
          if( options_.is_enabled("lw1:inference:up:watched-literals") ) {
#ifdef DEBUG
              std::cout << Utils::cyan() << "[UP] Using method: 'watched-literals'" << Utils::normal() << std::endl;
#endif
              consistent = watched_literals_.solve(cnf_, frontier_, up_assignment_);
              if( consistent && options_.is_enabled("lw1:inference:up:lookahead") ) {
                  std::cout << Utils::internal_error() << "lw1:inference:up:lookahead is EXPERIMENTAL!" << std::endl;
                  exit(-1);

#ifdef DEBUG
                  std::cout << Utils::cyan() << "[UP] Using 1-lookahead for 'watched-literals'" << Utils::normal() << std::endl;
#endif
                  consistent = watched_literals_.lookahead(cnf_, up_assignment_);
              }
              watched_literals_.restore(frontier_);
          } else {
#ifdef DEBUG
              std::cout << Utils::cyan() << "[UP] Using method: 'standard'" << Utils::normal() << std::endl;
#endif
              consistent = standard_.solve(cnf_, reduced_cnf_);
          }
          up_time_ += Utils::read_time_in_seconds() - up_start_time;

          // check consistency
          if( !consistent ) {
              restore_cnf();
              return false;
          }

          // 6. Update state: insert positive literals from result into state
          if( options_.is_enabled("lw1:inference:up:watched-literals") ) {
              for( unsigned i = 1; i < up_assignment_.size(); ++i ) {
                  int literal_sign = up_assignment_[i];
                  if( is_forbidden(i) ) continue;
                  assert((literal_sign != 0) || options_.is_enabled("lw1:inference:up:enhanced") || options_.is_enabled("lw1:inference:up:lookahead") || !options_.is_enabled("solver:classical-planner"));
                  if( literal_sign == 1 ) { // positive literal
                      state.add(i - 1);
#ifdef DEBUG
                      std::cout << Utils::yellow() << "[UP] [State] Add inferred literal: ";
                      LW1_State::print_literal(std::cout, i, &lw1_instance_);
                      std::cout << "[" << i - 1 << "]" << Utils::normal() << std::endl;
#endif
                  }
              }
          } else {
              for( size_t k = 0; k < reduced_cnf_.size(); ++k ) {
                  const Propositional::Clause &clause = reduced_cnf_[k];
                  assert(!clause.empty());

                  // if this is not a unit clause or new derived clause, skip it
                  if( clause.size() > 1 ) continue;
                  if( base_theory_.find(clause) != base_theory_.end() ) continue;
                  if( base_theory_axioms_.find(clause) != base_theory_axioms_.end() ) continue;

                  // if this is a unit clause, insert literal in state
                  int literal = clause[0];
                  if( !is_forbidden(literal) ) {
                      assert(literal != 0);
                      assert((literal > 0) || options_.is_enabled("lw1:inference:up:enhanced") || !options_.is_enabled("solver:classical-planner"));
                      if( literal > 0 ) {
                          state.add(literal - 1);
#ifdef DEBUG
                          std::cout << Utils::yellow() << "[UP] [State] Add inferred literal: ";
                          LW1_State::print_literal(std::cout, literal, &lw1_instance_);
                          std::cout << "[" << literal - 1 << "]" << Utils::normal() << std::endl;
#endif
                      }
                  }
              }
          }

          // 7. Update state: insert non-forbidden clauses in reduced cnf into state (if enhanced mode)
          if( options_.is_enabled("lw1:inference:up:enhanced") ) {
              std::cout << Utils::internal_error() << "lw1:inference:up:enhanced is EXPERIMENTAL!" << std::endl;
              exit(-1);

              // watched-literal method only returns an assignment, not a set of clauses
              assert(!options_.is_enabled("lw1:inference:up:watched-literals"));

              state.cnf_.clear();
              for( size_t k = 0; k < reduced_cnf_.size(); ++k ) {
                  const Propositional::Clause &clause = reduced_cnf_[k];

                  // if this is not a new derived clause, skip it
                  if( base_theory_.find(clause) != base_theory_.end() ) continue;
                  if( base_theory_axioms_.find(clause) != base_theory_axioms_.end() ) continue;

                  // if this is a non-forbidden non-unit clause, insert it into state
                  if( (clause.size() > 1) && !is_forbidden(clause) ) {
                      //state.cnf_.push_back(clause);//CHECK: is this equivalent?
                      state.cnf_.emplace_back(clause);
#ifdef DEBUG
                      std::cout << Utils::yellow() << "[UP] [State] Add clause: ";
                      state.print_clause_or_term(std::cout, clause, &lw1_instance_);
                      std::cout << Utils::normal() << std::endl;
#endif
                  }
              }
          }

          // 8. Restore CNF and return
          restore_cnf();
          return true;
      }
      virtual bool internal_propagate(T &state) const {
          assert(options_.is_enabled("lw1:inference:up"));
          assert(dynamic_cast<const LW1_Instance*>(&lw1_instance_) != nullptr);
          const LW1_Instance &lw1_instance = static_cast<const LW1_Instance&>(lw1_instance_);

#ifdef DEBUG
          std::cout << Utils::cyan() << "Using inference: 'unit propagation'" << Utils::normal() << std::endl;
#endif

          // check basic invariants
          assert(cnf_.empty() || options_.is_enabled("lw1:inference:up:preload"));
          assert(cnf_.size() == frontier_);

          // 1. Add positive literals from state
          for( typename T::const_iterator it = state.begin(); it != state.end(); ++it ) {
              assert(*it >= 0);
              cnf_.emplace_back(Propositional::Clause());
              cnf_.back().emplace_back(1 + *it);
              if( !options_.is_enabled("lw1:inference:up:watched-literals") )
                  base_theory_.insert(cnf_.back());
#ifdef DEBUG
              std::cout << Utils::red() << "[UP] [Theory] Add literal from state: ";
              LW1_State::print_literal(std::cout, 1 + *it, &lw1_instance_);
              std::cout << "[" << *it << "]" << Utils::normal() << std::endl;
#endif
          }

          // 2. Add axioms (if preload, these are already present)
          if( !options_.is_enabled("lw1:inference:up:preload") ) {
              for( std::vector<std::vector<int> >::const_iterator it = lw1_instance.clauses_for_axioms_.begin(); it != lw1_instance.clauses_for_axioms_.end(); ++it ) {
                  const std::vector<int> &clause = *it;
                  //cnf_.push_back(static_cast<const Propositional::Clause&>(clause));//CHECK: is this equivalent?
                  cnf_.emplace_back(static_cast<const Propositional::Clause&>(clause));
                  if( !options_.is_enabled("lw1:inference:up:watched-literals") )
                      base_theory_.insert(static_cast<const Propositional::Clause&>(clause));
#ifdef DEBUG
                  std::cout << Utils::red() << "[UP] [Theory] Add axiom: ";
                  state.print_clause_or_term(std::cout, clause, &lw1_instance_);
                  std::cout << Utils::normal() << std::endl;
#endif
              }
          }

          // 4. Add (extra) static clauses (if enhanced mode)
          if( options_.is_enabled("lw1:inference:up:enhanced") ) {
              std::cout << Utils::internal_error() << "lw1:inference:up:enhanced is EXPERIMENTAL!" << std::endl;
              exit(-1);
          }

          // 5. Do inference
          bool consistent = true;
          if( options_.is_enabled("lw1:inference:up:watched-literals") ) {
#ifdef DEBUG
              std::cout << Utils::cyan() << "[UP] Using method: 'watched-literals'" << Utils::normal() << std::endl;
#endif
              consistent = watched_literals_.solve(cnf_, frontier_, up_assignment_);
              if( consistent && options_.is_enabled("lw1:inference:up:lookahead") ) {
                  std::cout << Utils::internal_error() << "lw1:inference:up:lookahead is EXPERIMENTAL!" << std::endl;
                  exit(-1);
              }
              watched_literals_.restore(frontier_);
          } else {
#ifdef DEBUG
              std::cout << Utils::cyan() << "[UP] Using method: 'standard'" << Utils::normal() << std::endl;
#endif
              consistent = standard_.solve(cnf_, reduced_cnf_);
          }

          // check consistency
          if( !consistent ) {
              restore_cnf();
              return false;
          }

          // 6. Update state: insert positive literals from result into state
          if( options_.is_enabled("lw1:inference:up:watched-literals") ) {
              for( unsigned i = 1; i < up_assignment_.size(); ++i ) {
                  int literal_sign = up_assignment_[i];
                  if( is_forbidden(i) ) continue;
                  assert((literal_sign != 0) || options_.is_enabled("lw1:inference:up:enhanced") || options_.is_enabled("lw1:inference:up:lookahead") || !options_.is_enabled("solver:classical-planner"));
                  if( literal_sign == 1 ) { // positive literal
                      state.add(i - 1);
#ifdef DEBUG
                      std::cout << Utils::yellow() << "[UP] [State] Add inferred literal: ";
                      LW1_State::print_literal(std::cout, i, &lw1_instance_);
                      std::cout << "[" << i - 1 << "]" << Utils::normal() << std::endl;
#endif
                  }
              }
          } else {
              for( size_t k = 0; k < reduced_cnf_.size(); ++k ) {
                  const Propositional::Clause &clause = reduced_cnf_[k];
                  assert(!clause.empty());

                  // if this is not a unit clause or new derived clause, skip it
                  if( clause.size() > 1 ) continue;
                  if( base_theory_.find(clause) != base_theory_.end() ) continue;
                  if( base_theory_axioms_.find(clause) != base_theory_axioms_.end() ) continue;

                  // if this is a unit clause, insert literal in state
                  int literal = clause[0];
                  if( !is_forbidden(literal) ) {
                      assert(literal != 0);
                      assert((literal > 0) || options_.is_enabled("lw1:inference:up:enhanced") || !options_.is_enabled("solver:classical-planner"));
                      if( literal > 0 ) {
                          state.add(literal - 1);
#ifdef DEBUG
                          std::cout << Utils::yellow() << "[UP] [State] Add inferred literal: ";
                          LW1_State::print_literal(std::cout, literal, &lw1_instance_);
                          std::cout << "[" << literal - 1 << "]" << Utils::normal() << std::endl;
#endif
                      }
                  }
              }
          }

          // 7. Update state: insert non-forbidden clauses in reduced cnf into state (if enhanced mode)
          if( options_.is_enabled("lw1:inference:up:enhanced") ) {
              std::cout << Utils::internal_error() << "lw1:inference:up:enhanced is EXPERIMENTAL!" << std::endl;
              exit(-1);
          }

          // 8. Restore CNF and return
          restore_cnf();
          return true;
      }

    public:
      UnitPropagation(const Instance &instance, const LW1_Instance &lw1_instance, const Options::Mode &options)
        : Engine<T>("unit-propagation", instance, lw1_instance, options), frontier_(0), up_time_(0) {
          if( options_.is_enabled("lw1:inference:up:preload") ) {
              for( size_t j = 0; j < lw1_instance.clauses_for_axioms_.size(); ++j ) {
                  const std::vector<int> &clause = lw1_instance.clauses_for_axioms_[j];
                  cnf_.push_back(static_cast<const Propositional::Clause&>(clause));
                  if( !options_.is_enabled("lw1:inference:up:watched-literals") )
                      base_theory_.insert(static_cast<const Propositional::Clause&>(clause));
              }
              frontier_ = cnf_.size();
              if( options_.is_enabled("lw1:inference:up:watched-literals") )
                  watched_literals_.initialize(cnf_, 0);
          }
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
      CSP::Csp csp_;
      CSP::AC3 ac3_;

      virtual bool internal_apply_inference(const Instance::Action *last_action,
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
          if( last_action != nullptr )
              fill_relevant_sensing_models(options_, instance_, lw1_instance_, last_action, sensed_at_step, relevant_sensing_models_as_k_dnf, false);

          // 0. Domains are original domains with values pruned as indicated with the k-atoms in state.
          // Basic constraints relate variable groups to state variable and variable groups to variable
          // groups.
          for( typename T::const_iterator it = state.begin(); it != state.end(); ++it ) {
              int k_atom = *it;
              if( state.is_special(1 + k_atom, &lw1_instance_) ) continue;
#ifdef DEBUG
              std::cout << Utils::red() << "[AC3] Added literal from state: ";
              LW1_State::print_literal(std::cout, 1 + k_atom, &lw1_instance_);
              std::cout << "[" << *it << "]" << Utils::normal() << std::endl;
#endif
              csp_.filter_variable_with_k_atom(k_atom);
              assert(csp_.is_1consistent());
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
                  std::cout << Utils::red() << "[AC3] sensed literal: var=" << variable.name() << ", value=" << std::flush;
                  LW1_State::print_literal(std::cout, sensed_literal, &instance_);
                  std::cout << "[" << sensed_literal - 1 << "]";
                  std::cout << ", key=(" << var_key << "," << sensed_literal << ")"
                            << Utils::normal() << std::endl;
#endif
                  if( variable.is_state_variable() ) {
                      // observation is state variable, filter it directly in variable domain
                      assert(jt->second.empty());
                      int k_atom = sensed_literal > 0 ? 2*(sensed_literal - 1) : 2*(-sensed_literal - 1) + 1;
#ifdef DEBUG
                      std::cout << Utils::red() << "[AC3] Add obs (state) k-literal: ";
                      LW1_State::print_literal(std::cout, 1 + k_atom, &lw1_instance_);
                      std::cout << "[" << k_atom << "]" << Utils::normal() << std::endl;
#endif
                      csp_.filter_variable_with_k_atom(k_atom);
                      assert(csp_.is_1consistent());
                  } else if( lw1_instance_.filtering_groups_.find(key) != lw1_instance_.filtering_groups_.end() ) {
                      // observation can be filtered in variable group. Prune all valuations that are
                      // inconsistent with k-dnf
                      int vg = lw1_instance_.filtering_groups_.at(key);
                      const sensing_models_as_cnf_or_dnf_t& sensing_models_as_k_dnf = jt->second;
                      for( size_t k = 0; k < sensing_models_as_k_dnf.size(); ++k ) {
                          const cnf_or_dnf_t& k_dnf_for_sensing_model = *sensing_models_as_k_dnf[k];
#ifdef DEBUG
                          std::cout << Utils::blue() << "[AC3] k-dnf: index=" << k << ", formula=";
                          state.print_cnf_or_dnf(std::cout, k_dnf_for_sensing_model, &lw1_instance_);
                          std::cout << Utils::normal() << std::endl;

                          for( size_t j = 0; j < k_dnf_for_sensing_model.size(); ++j ) {
                              const clause_or_term_t& term = k_dnf_for_sensing_model[j];
                              std::cout << Utils::cyan() << "[AC3] term: ";
                              state.print_clause_or_term(std::cout, term, &lw1_instance_);
                              std::cout << Utils::normal() << std::endl;
                          }
#endif
                          csp_.filter_group_with_k_dnf(vg, k_dnf_for_sensing_model);
                          assert(csp_.is_1consistent());
                      }
                  } else {
                      std::cout << Utils::error() << "there is no group to filter observation" << std::endl;
                      exit(-1);

                      assert(0); // the stuff below is wrong!
                      // there is no variable group where to filter observation. Use k-dnf to generate constraints in CSP
                      const sensing_models_as_cnf_or_dnf_t &sensing_models_as_k_dnf = jt->second;
                      for( size_t k = 0; k < sensing_models_as_k_dnf.size(); ++k ) {
                          const cnf_or_dnf_t &k_dnf_for_sensing_model = *sensing_models_as_k_dnf[k];
#ifdef DEBUG
                          std::cout << Utils::blue() << "[AC3] k-dnf: index=" << k << ", formula=" << Utils::normal();
                          state.print_cnf_or_dnf(std::cout, k_dnf_for_sensing_model, &lw1_instance_);
                          std::cout << std::endl;
#endif
                          std::set<int> possible_domain;
                          for( size_t j = 0; j < k_dnf_for_sensing_model.size(); ++j ) {
                              const clause_or_term_t &k_term = k_dnf_for_sensing_model[j];
                              if( k_term.size() != 1 ) continue;
                              assert(k_term[0] > 0);
#ifdef DEBUG
                              std::cout << Utils::blue() << "[AC3] filtering with k-atom: ";
                              State::print_literal(std::cout, k_term[0], &lw1_instance_);
                              std::cout << Utils::normal() << std::endl;
#endif
                              csp_.filter_variable_with_k_atom(k_term[0] - 1);
                              assert(csp_.is_1consistent());
                          }
                      }
                  }
              }
          }

          // 2. Make the CSP arc consistent by running AC3. Normally, the resulting CSP should be
          // consistent // (i.e. the domain of each variable should be non empty). Otherwise,
          // there is an error in // the planning model
          bool status = ac3_.solve(state);
          return status;
      }
      virtual bool internal_propagate(T &state) const {
          std::cout << Utils::internal_error() << "ac3: internal_propagate() not yet implemented" << std::endl;
          exit(-1);
      }

    public:
      AC3(const Instance &instance, const LW1_Instance &lw1_instance, const Options::Mode &options)
        : Engine<T>("ac3", instance, lw1_instance, options),
          csp_(lw1_instance),
          ac3_(csp_) {
          fill_atoms_to_var_map(lw1_instance_, atoms_to_vars_);
          csp_.set_atoms_to_var_map(atoms_to_vars_);
          csp_.calculate_common_variables_in_groups();
          ac3_.calculate_arcs();
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

