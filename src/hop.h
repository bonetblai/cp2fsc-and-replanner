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

#ifndef HOP_H
#define HOP_H

#include <cassert>
#include <iostream>
#include <list>
#include <vector>

#include "action_selection.h"
#include "lw1_problem.h"
#include "inference_engine.h"
#include "utils.h"

#include "and_or_search.h"
#include "belief_features.h"
#include "and_or2.h"

//#define DEBUG

namespace HOP {

  template<typename T>
  class ActionSelection : public ::ActionSelection<T> {
      const LW1_Instance &lw1_instance_;
      const Inference::Engine<T> &inference_engine_;
      const int num_sampled_scenarios_;
      const bool prune_nodes_;

      int goal_feature_index_;
      const Width::Feature<T> *goal_feature_;
      std::vector<const Width::Feature<T>*> feature_universe_;        // set of all features
      std::vector<const Width::Feature<T>*> feature_language_;        // set of features that are considered
      std::vector<const Width::Feature<T>*> literal_features_;
      std::vector<const Width::Feature<T>*> domain_size_features_;
      std::vector<const Width::AndFeature<T>*> term_features_;
      std::vector<const Width::OrFeature<T>*> disjunctive_features_;
      std::vector<const Width::OrFeature<T>*> disjunctive_features_involving_goal_feature_;

      // bitmap for features (used when computing AND/OR lookahead tree)
      size_t feature_bitmap_size_;
      mutable unsigned *feature_bitmap_;
      mutable unsigned num_available_features_;

      mutable unsigned num_expansions_;

      mutable float total_search_time_;
      mutable float total_time_;
      mutable size_t n_calls_to_inference_engine_;
      mutable size_t n_calls_;

    public:
      ActionSelection(const LW1_Instance &lw1_instance,
                      const Inference::Engine<T> &inference_engine,
                      int num_sampled_scenarios,
                      bool prune_nodes = true)
        : lw1_instance_(lw1_instance),
          inference_engine_(inference_engine),
          num_sampled_scenarios_(num_sampled_scenarios),
          prune_nodes_(prune_nodes),
          goal_feature_index_(-1),
          goal_feature_(0),
          feature_bitmap_size_(0),
          feature_bitmap_(0),
          num_available_features_(0),
          num_expansions_(0),
          total_search_time_(0),
          total_time_(0),
          n_calls_to_inference_engine_(0),
          n_calls_(0) {
          // Initialize language of features. For each state variable X with domain { x1, ..., xn },
          // add features for Kxi and DSZ(X)
          for( size_t var_index = 0; var_index < lw1_instance_.variables_.size(); ++var_index ) {
              const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
              if( variable.is_state_variable() ) {
                  //std::cout << variable << std::endl;
                  // generate features for domain values
                  for( std::set<int>::const_iterator it = variable.domain().begin(); it != variable.domain().end(); ++it ) {
                      int feature_index = feature_universe_.size();
                      literal_features_.push_back(new Width::LiteralFeature<T>(feature_index, lw1_instance_, var_index, 1 + 2*(*it)));
                      feature_universe_.push_back(literal_features_.back());
                      feature_language_.push_back(literal_features_.back());
#ifdef DEBUG
                      std::cout << "using " << *feature_language_.back() << std::endl;
#endif

                      feature_index = feature_universe_.size();
                      literal_features_.push_back(new Width::LiteralFeature<T>(feature_index, lw1_instance_, var_index, 1 + 2*(*it) + 1));
                      feature_universe_.push_back(literal_features_.back());
                      feature_language_.push_back(literal_features_.back());
#ifdef DEBUG
                      std::cout << "using " << *feature_language_.back() << std::endl;
#endif
                  }

                  // generate feature for domain size
                  size_t dsize = variable.is_binary() ? 2 : variable.domain().size();
                  for( size_t i = 0; i < dsize; ++i ) {
                      int feature_index = feature_universe_.size();
                      domain_size_features_.push_back(new Width::DomainSizeFeatureEQ<T>(feature_index, lw1_instance_, var_index, 1 + i));
                      feature_universe_.push_back(domain_size_features_.back());
                      feature_language_.push_back(domain_size_features_.back());
#ifdef DEBUG
                      std::cout << "using " << *feature_language_.back() << std::endl;
#endif
                  }
              }
          }
#ifdef DEBUG
          std::cout << Utils::green() << "#literal-features=" << literal_features_.size() << Utils::normal() << std::endl;
          std::cout << Utils::green() << "#domain-size-features=" << domain_size_features_.size() << Utils::normal() << std::endl;
#endif

          // create goal feature
          goal_feature_index_ = feature_universe_.size();
          goal_feature_ = new Width::GoalFeature<T>(goal_feature_index_, lw1_instance_);
          feature_universe_.push_back(goal_feature_);
          feature_language_.push_back(goal_feature_);
#ifdef DEBUG
          std::cout << "using " << *goal_feature_ << std::endl;
          std::cout << Utils::green() << "#goal-features=1" << Utils::normal() << std::endl;
#endif

          std::cout << "hop: #features=" << feature_language_.size() << std::endl;

          // create feature bitmap
          create_feature_bitmap(feature_universe_);
      }
      virtual ~ActionSelection() {
          delete[] feature_bitmap_;
          for( size_t k = 0; k < feature_universe_.size(); ++k )
              delete feature_universe_[k];
      }

      // features
      void create_feature_bitmap(const std::vector<const Width::Feature<T>*> &feature_universe) {
          feature_bitmap_size_ = (feature_universe.size() >> 5) + ((feature_universe.size() % 32) == 0 ? 0 : 1);
          feature_bitmap_ = new unsigned[feature_bitmap_size_];
      }
      void reset_bitmap_for_features() const {
          memset(feature_bitmap_, 255, feature_bitmap_size_ * sizeof(unsigned));
          num_available_features_ = feature_language_.size();
      }
      bool is_feature_available(int index, int offset) const {
          assert((index >= 0) && (index < feature_bitmap_size_));
          assert((offset >= 0) && (offset < 32));
          return (feature_bitmap_[index] & (1 << offset)) != 0;
      }
      bool is_feature_available(const Width::Feature<T> &feature) const {
          int index = feature.index() >> 5, offset = feature.index() % 32;
          return is_feature_available(index, offset);
      }
      void register_feature(int index, int offset) const {
          assert((index >= 0) && (index < feature_bitmap_size_));
          assert((offset >= 0) && (offset < 32));
          feature_bitmap_[index] = feature_bitmap_[index] & ~(1 << offset);
      }
      void register_feature(const Width::Feature<T> &feature) const {
          assert(feature.index() < feature_universe_.size());
          int index = feature.index() >> 5, offset = feature.index() % 32;
          if( is_feature_available(index, offset) && (feature.index() < feature_language_.size()) )
              --num_available_features_;
          register_feature(index, offset);
      }

      void compute_state_bitmap(const T &state, std::vector<bool> &state_bitmap) const {
          for( State::const_iterator it = state.begin(); it != state.end(); ++it ) {
              //std::cout << "literal="; State::print_literal(std::cout, 1 + *it, &lw1_instance_); std::cout << std::endl;
              assert((*it >= 0) && (*it < state_bitmap.size()));
              state_bitmap[*it] = true;
          }
      }

      void compute_features(const T &state,
                            const std::vector<bool> &state_bitmap,
                            Width::FeatureSet<T> &features,
                            const std::vector<const Width::Feature<T>*> &feature_language,
                            bool verbose = false) const {
          features.clear();
          for( size_t k = 0; k < feature_language.size(); ++k ) {
              const Width::Feature<T> &feature = *feature_language[k];
              if( is_feature_available(feature) && feature.holds(state_bitmap, verbose) ) {
#ifdef DEBUG
                  std::cout << Utils::green() << "valid feature '" << feature << "'" << Utils::normal() << std::endl;
#endif
                  features.insert(&feature);
              }
          }
#ifdef DEBUG
          std::cout << Utils::green() << "#achieved-features=" << features.size() << Utils::normal() << std::endl;
#endif
      }

      // beliefs (states)
      bool is_goal(const T &state) const {
          assert(goal_feature_ != 0);
          return goal_feature_->holds(state);
      }
      int calculate_unknown_variables(const T &state, std::vector<int> *unknown_variables = 0) const {
          int number_unknown_variables = 0;
          for( size_t var_index = 0; var_index < lw1_instance_.variables_.size(); ++var_index ) {
              const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
              if( variable.is_state_variable() ) {
                  bool unknown_variable = true;
                  if( variable.is_binary() ) {
                      assert(variable.domain().size() == 1);
                      int atom = *variable.domain().begin();
                      unknown_variable = !state.satisfy(2 * atom) && !state.satisfy(2 * atom + 1);
                  } else {
                      for( std::set<int>::const_iterator it = variable.domain().begin(); it != variable.domain().end(); ++it ) {
                          int atom = *it;
                          if( state.satisfy(2 * atom) ) {
                              unknown_variable = false;
                              break;
                          }
                      }
                  }
                  if( unknown_variable ) {
                      ++number_unknown_variables;
                      if( unknown_variables != 0 )
                          unknown_variables->push_back(var_index);
                  }
              }
          }
          return number_unknown_variables;
      }
      void calculate_unknown_variables(const T &state, std::vector<int> &unknown_variables) const {
          calculate_unknown_variables(state, &unknown_variables);
      }
      bool sample(const T &state, const std::vector<int> &unknown_variables, T &sampled_hidden) const {
          assert(sampled_hidden == state);
          for( size_t k = 0; k < unknown_variables.size(); ++k ) {
              int var_index = unknown_variables[k];
              assert((var_index >= 0) && (var_index < lw1_instance_.variables_.size()));
              const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
#ifdef DEBUG
              std::cout << Utils::blue() << "variable '" << variable.name() << "' is unknown: " << Utils::normal() << std::flush;
#endif
              assert(variable.is_state_variable());
              std::vector<int> possible_values;
              if( variable.is_binary() ) {
                  int atom = *variable.domain().begin();
                  assert(!state.satisfy(2 * atom) && !state.satisfy(2 * atom + 1));
                  possible_values.push_back(2 * atom);
                  possible_values.push_back(2 * atom + 1);
              } else {
                  for( std::set<int>::const_iterator it = variable.domain().begin(); it != variable.domain().end(); ++it ) {
                      int atom = *it;
                      if( !state.satisfy(2 * atom + 1) )
                          possible_values.push_back(2 * atom);
                  }
              }
              assert(!possible_values.empty());
              int sampled_atom = possible_values[lrand48() % possible_values.size()];

#ifdef DEBUG
              std::cout << Utils::blue() << " sampled-value=";
              State::print_literal(std::cout, 1 + sampled_atom, &lw1_instance_);
              std::cout << Utils::normal() << std::endl;
#endif

              // add sampled atom to sampled state
              sampled_hidden.add(sampled_atom);
          }

          // propagate added atoms
          ++n_calls_to_inference_engine_;
          bool status = inference_engine_.propagate(sampled_hidden);
          assert(status);
          return status;
      }

      bool satisfy(const T &state, const LW1_State::clause_t &k_term) const {
          bool holds = true;
          for( size_t k = 0; k < k_term.size(); ++k ) {
              if( !state.satisfy(k_term[k] - 1) ) {
                  holds = false;
                  break;
              }
          }
          return holds;
      }
      bool satisfy(const T &state, const LW1_State::cnf_t &k_dnf) const {
          bool holds = false;
          for( size_t k = 0; k < k_dnf.size(); ++k ) {
#ifdef DEBUG
              LW1_State::print_clause_or_term(std::cout, k_dnf[k], &lw1_instance_);
              std::cout << "=";
#endif
              if( satisfy(state, k_dnf[k]) ) {
#ifdef DEBUG
                  std::cout << "true" << std::endl;
#endif
                  holds = true;
                  break;
              } else {
#ifdef DEBUG
                  std::cout << "false" << std::endl;
#endif
              }
          }
          return holds;
      }

      // nodes
      bool is_goal(const AndOr::OrNode<T> &node) const {
          return is_goal(*node.belief()->belief());
      }
      AndOr::OrNode<T>* make_root(const T &state) const {
          return new AndOr::OrNode<T>(new AndOr::Belief<T>(new T(state)), 0);
      }

      // AND/OR graph
      void reset_graph() const {
          reset_bitmap_for_features();
          num_expansions_ = 0;
      }

      bool need_to_expand_node(const AndOr::OrNode<T> &nodes, const Width::FeatureSet<T> &features) const {
          assert(goal_feature_ != 0);
          return !features.empty() && (features.find(goal_feature_) == features.end());
      }

      void create_sampled_graph_breadth_first(AndOr::OrNode<T> *root, std::vector<std::vector<int> > &goal_paths, bool do_sampling) const {
          std::vector<AndOr::AndNode<T>*> successors;
          std::deque<AndOr::OrNode<T>*> queue;
          queue.push_front(root);
          while( !queue.empty() ) {
              AndOr::OrNode<T> *node = queue.back();
              queue.pop_back();
              //std::cout << "processing node=" << *node << std::endl;

              // compute state bitmap
              const T &state = *node->belief()->belief();
              std::vector<bool> state_bitmap(lw1_instance_.atoms_.size(), false);
              compute_state_bitmap(state, state_bitmap);

              // compute features
              Width::FeatureSet<T> features;
              compute_features(state, state_bitmap, features, feature_language_, false);

              if( features.find(goal_feature_) != features.end() ) {
                  std::deque<const Instance::Action*> path;
                  while( node->parent() != 0 ) {
                      const AndOr::AndNode<T> *parent = node->parent();
                      int action = parent->action();
                      assert((action >= 0) && (action < lw1_instance_.actions_.size()));
#ifdef SMART
                      path.push_front(lw1_instance_.actions_[action].get());
#else
                      path.push_front(lw1_instance_.actions_[action]);
#endif
                      assert(parent->parent() != 0);
                      node = const_cast<AndOr::OrNode<T>*>(parent->parent());
                  }
                  std::cout << Utils::red() << "GOAL PATH:";
                  while( !path.empty() ) {
                      std::cout << " " << path.front()->name() << std::flush;
                      path.pop_front();
                  }
                  std::cout << Utils::normal() << std::endl;
                  continue;
              }

              if( need_to_expand_node(*node, features) ) {
                  // register node's features
                  for( typename Width::FeatureSet<T>::const_iterator it = features.begin(); it != features.end(); ++it ) {
                      assert(*it != 0);
                      register_feature(**it);
                  }
                  //std::cout << Utils::green() << "#available-features=" << num_available_features_ << Utils::normal() << std::endl;

                  assert(successors.empty());
                  expand(*node, successors, do_sampling);
                  //std::cout << "#successors=" << successors.size() << std::endl;
                  for( size_t k = 0; k < successors.size(); ++k ) {
                      AndOr::AndNode<T> *succ = successors[k];
                      for( size_t j = 0; j < succ->children().size(); ++j )
                          queue.push_front(const_cast<AndOr::OrNode<T>*>(succ->child(j)));
                      node->add_child(succ);
                      succ->set_parent(node);
                  }
                  successors.clear();
              }
          }
      }
      void create_sampled_graph_breadth_first(const T &sampled_hidden, AndOr::OrNode<T> *root, std::vector<std::vector<int> > &goal_paths) const {
          std::vector<std::pair<AndOr::AndNode<T>*, const T*> > successors;
          std::deque<std::pair<AndOr::OrNode<T>*, const T*> > queue;

          float total_time = Utils::read_time_in_seconds();
          float expand_time = 0;
          float feature_time = 0;

          queue.push_front(std::make_pair(root, new T(sampled_hidden)));
          while( !queue.empty() ) {
              AndOr::OrNode<T> *node = queue.back().first;
              const T *hidden = queue.back().second;
              queue.pop_back();
              //std::cout << "processing node=" << *node << std::endl;

              // compute state bitmap
              const T &state = *node->belief()->belief();
              std::vector<bool> state_bitmap(lw1_instance_.atoms_.size(), false);
              compute_state_bitmap(state, state_bitmap);

              // compute features
              Width::FeatureSet<T> features;
              float feature_start_time = Utils::read_time_in_seconds();
              compute_features(state, state_bitmap, features, feature_language_, false);
              feature_time += Utils::read_time_in_seconds() - feature_start_time;

              if( features.find(goal_feature_) != features.end() ) {
                  // extract and store goal path
                  std::vector<int> reversed_goal_path;
                  while( node->parent() != 0 ) {
                      const AndOr::AndNode<T> *parent = node->parent();
                      int action = parent->action();
                      assert((action >= 0) && (action < lw1_instance_.actions_.size()));
                      reversed_goal_path.push_back(action);
                      assert(parent->parent() != 0);
                      node = const_cast<AndOr::OrNode<T>*>(parent->parent());
                  }
                  goal_paths.emplace_back(std::move(reversed_goal_path));

                  // free resources: free hidden states in open queue and clear queue
                  while( !queue.empty() ) {
                      delete queue.back().second;
                      queue.pop_back();
                  }
              } else if( need_to_expand_node(*node, features) ) {
                  // register node's features
                  for( typename Width::FeatureSet<T>::const_iterator it = features.begin(); it != features.end(); ++it ) {
                      assert(*it != 0);
                      register_feature(**it);
                  }
                  //std::cout << Utils::green() << "#available-features=" << num_available_features_ << Utils::normal() << std::endl;

                  assert(successors.empty());
                  float expand_start_time = Utils::read_time_in_seconds();
                  expand(*hidden, *node, successors);
                  expand_time += Utils::read_time_in_seconds() - expand_start_time;
                  //std::cout << "#successors=" << successors.size() << std::endl;
                  for( size_t k = 0; k < successors.size(); ++k ) {
                      AndOr::AndNode<T> *succ = successors[k].first;
                      const T *succ_hidden = successors[k].second;
                      for( size_t j = 0; j < succ->children().size(); ++j )
                          queue.push_front(std::make_pair(const_cast<AndOr::OrNode<T>*>(succ->child(j)), succ_hidden));
                      node->add_child(succ);
                      succ->set_parent(node);
                  }
                  successors.clear();
              } else {
                  // mark node as pruned
                  node->mark_as_pruned();
              }
              delete hidden;
          }
          total_time = Utils::read_time_in_seconds() - total_time;
          //std::cout << "time: total=" << total_time << ", expand=" << expand_time << ", feature=" << feature_time << std::endl;
      }

      void deallocate_graph(const AndOr::OrNode<T> *node) const {
          for( size_t k = 0; k < node->children().size(); ++k )
              deallocate_graph(node->child(k));
          delete node->belief()->belief();
          delete node->belief();
          delete node;
      }
      void deallocate_graph(const AndOr::AndNode<T> *node) const {
          for( size_t k = 0; k < node->children().size(); ++k )
              deallocate_graph(node->child(k));
          delete node->belief()->belief();
          delete node->belief();
          delete node;
      }

      void expand(const AndOr::OrNode<T> &node, std::vector<AndOr::AndNode<T>*> &successors, bool do_sampling) const {
          ++num_expansions_;

#ifdef DEBUG
          std::cout << Utils::blue() << "state=" << Utils::normal();
          node.belief()->belief()->print(std::cout, &lw1_instance_);
          std::cout << std::endl;
#endif

          // generate successors for each action
          const T &tip = *node.belief()->belief();
          for( size_t action_index = 0; action_index < lw1_instance_.actions_.size(); ++action_index ) {
              if( (lw1_instance_.remap_action(action_index) == -1) && !lw1_instance_.is_subgoaling_rule(action_index) ) continue;
              assert(lw1_instance_.is_regular_action(action_index));
              const Instance::Action &action = *lw1_instance_.actions_[action_index];
              if( tip.applicable(action) ) {
                  //std::cout << Utils::green() << "action=" << Utils::normal() << action.name() << std::endl;

                  // calculate result of action
                  T *result_after_action = new T(tip);
                  result_after_action->apply(action);

#ifdef DEBUG
                  std::cout << Utils::blue() << "RESULT(a=" << action.name() << ")=" << Utils::normal();
                  result_after_action->print(std::cout, &lw1_instance_);
                  std::cout << std::endl;
#endif

                  // generate successor considering possible observations. Feature is achieved iff it
                  // is achieved in all successor beliefs
                  std::vector<std::set<int> > possible_observations;
                  compute_possible_observations(*result_after_action, action, possible_observations);
#ifdef DEBUG 
                  std::cout << Utils::green() << "#possible-obs=" << possible_observations.size() << Utils::normal() << std::endl;
#endif

                  // generate valid successors after (action,obs). A valid successor
                  // is a belief in which inference after obs doesn't detect inconsistency
                  std::vector<const T*> valid_successors;
                  if( !possible_observations.empty() ) {
                      // there is at least one observable variable. Incorporate
                      // observations and make inference to see which ones are
                      // incompatible with current belief
                      for( size_t j = 0; j < possible_observations.size(); ++j ) {
                          assert(!possible_observations[j].empty());
                          const std::set<int> &obs = possible_observations[j];

                          // possible observation is *valid* if once it is assimilated
                          // (i.e. inference is done), it results in a consistent state
                          T *result_after_action_and_obs = new T(*result_after_action);
                          ++n_calls_to_inference_engine_;
                          bool status = inference_engine_.apply_inference(&action, obs, *result_after_action_and_obs);
                          if( status ) {
                              valid_successors.push_back(result_after_action_and_obs);
#ifdef DEBUG
                              std::cout << Utils::blue() << "RESULT(a=" << action.name()
                                        << ",o=obs[" << j << "])=" << Utils::normal();
                              result_after_action_and_obs->print(std::cout, &lw1_instance_);
                              std::cout << std::endl;
#endif
                          } else {
#ifdef DEBUG
                              std::cout << Utils::blue() << "INCONSISTENT(a=" << action.name()
                                        << ",o=obs[" << j << "])=" << Utils::normal();
                              result_after_action_and_obs->print(std::cout, &lw1_instance_);
                              std::cout << std::endl;
#endif
                              delete result_after_action_and_obs;
                          }
                      }
                  } else {
                      // there are no observable variables. Hence, there is single successor equal to belief_a
                      assert(lw1_instance_.vars_sensed_by_action_.find(action.name()) == lw1_instance_.vars_sensed_by_action_.end());
                      valid_successors.push_back(new T(*result_after_action));
                  }
#ifdef DEBUG
                  std::cout << Utils::green() << "#valid-successors=" << valid_successors.size() << Utils::normal() << std::endl;
#endif

                  // create AND node with valid successors
                  assert(!valid_successors.empty());
                  if( do_sampling ) {
                      int k = lrand48() % valid_successors.size();
                      const T *sampled_succ = valid_successors[k];
                      valid_successors[k] = valid_successors[0];
                      valid_successors[0] = sampled_succ;
                      while( valid_successors.size() > 1 ) {
                          delete valid_successors.back();
                          valid_successors.pop_back();
                      }
                      assert(valid_successors.size() == 1);
                  }
                  AndOr::AndNode<T> *and_node = AndOr::create_and_node(action_index, result_after_action, valid_successors);
                  successors.push_back(and_node);
              }
          }
      }

      bool expand(const T &hidden, const AndOr::OrNode<T> &node, std::vector<std::pair<AndOr::AndNode<T>*, const T*> > &successors) const {
          ++num_expansions_;

#ifdef DEBUG
          std::cout << Utils::blue() << "state=" << Utils::normal();
          node.belief()->belief()->print(std::cout, &lw1_instance_);
          std::cout << std::endl;
          std::cout << Utils::blue() << "hidden=" << Utils::normal();
          hidden.print(std::cout, &lw1_instance_);
          std::cout << std::endl;
#endif

          // generate successors for each action
          const T &tip = *node.belief()->belief();
          for( size_t action_index = 0; action_index < lw1_instance_.actions_.size(); ++action_index ) {
              if( (lw1_instance_.remap_action(action_index) == -1) && !lw1_instance_.is_subgoaling_rule(action_index) ) continue;
              assert(lw1_instance_.is_regular_action(action_index));
              const Instance::Action &action = *lw1_instance_.actions_[action_index];
              if( tip.applicable(action) ) {
                  //std::cout << Utils::green() << "action=" << Utils::normal() << action.name() << std::endl;

                  // calculate result of action
                  T *result_after_action = new T(tip);
                  result_after_action->apply(action);
                  T *hidden_after_action = new T(hidden);
                  hidden_after_action->apply(action);

#ifdef DEBUG
                  std::cout << Utils::blue() << "RESULT(a=" << action.name() << ")=" << Utils::normal();
                  result_after_action->print(std::cout, &lw1_instance_);
                  std::cout << std::endl;
                  std::cout << Utils::blue() << "HIDDEN-RESULT(a=" << action.name() << ")=" << Utils::normal();
                  hidden_after_action->print(std::cout, &lw1_instance_);
                  std::cout << std::endl;
#endif

                  // calculate obs and result of action + obs
                  std::set<int> obs;
                  std::map<int, std::pair<const LW1_Instance::Variable*, const std::vector<std::vector<int> >*> > observed_literals;
                  compute_observation(*hidden_after_action, *result_after_action, action, obs, observed_literals);
                  T *result_after_action_and_obs = new T(*result_after_action);

                  // check whether we need to call inference engine
                  bool need_to_call_inference_engine = false;
                  for( std::set<int>::const_iterator it = obs.begin(); !need_to_call_inference_engine && (it != obs.end()); ++it ) {
                      int literal = *it;
                      int k_literal = literal > 0 ? 1 + 2 * (literal - 1) : 1 + 2 * (-literal - 1) + 1;
                      const LW1_Instance::Variable &variable = *observed_literals.at(*it).first;
                      const std::vector<std::vector<int> > &model = *observed_literals.at(*it).second;
#ifdef DEBUG
                      std::cout << "observed: literal=";
                      LW1_State::print_literal(std::cout, literal, &lw1_instance_.po_instance_);
                      std::cout << std::flush << ", k-literal=";
                      LW1_State::print_literal(std::cout, k_literal, &lw1_instance_);
                      std::cout << std::flush << ", variable=" << variable.name() << std::endl;
#endif
                      if( !variable.is_state_variable() ) {
                          if( !satisfy(*result_after_action_and_obs, model) )
                              need_to_call_inference_engine = true;
                      } else {
                          if( !result_after_action_and_obs->satisfy(k_literal - 1) )
                              need_to_call_inference_engine = true;
                      }
                  }

                  bool good_successor = true;
                  if( need_to_call_inference_engine ) {
                      ++n_calls_to_inference_engine_;
                      bool status = inference_engine_.apply_inference(&action, obs, *result_after_action_and_obs);
                      if( status ) {
#ifdef DEBUG
                          std::cout << Utils::blue() << "RESULT(a=" << action.name() << ",obs-sz=" << obs.size() << ")=" << Utils::normal();
                          result_after_action_and_obs->print(std::cout, &lw1_instance_);
                          std::cout << std::endl;
#endif
                      } else {
                          assert(0); // CHECK: see below for else case of good_successor
                          good_successor = false;
                      }
                  } else {
                      // there are no observable variables. Hence, there is single successor equal to belief_a
#ifdef DEBUG
                      std::cout << Utils::bold() << "Single successor equal to bel_a" << Utils::normal() << std::endl;
#endif
                  }

                  if( good_successor ) {
                      std::vector<const T*> valid_successors(1, result_after_action_and_obs);
                      AndOr::AndNode<T> *and_node = AndOr::create_and_node(action_index, result_after_action, valid_successors);
                      successors.push_back(std::make_pair(and_node, hidden_after_action));
                  } else {
                     // a bad successor means that the hidden sampled state is inconsistent
                     while( !successors.empty() ) {
                         delete successors.back().first;
                         delete successors.back().second;
                         successors.pop_back();
                     }
                     delete result_after_action;
                     return false;
                  }
              }
          }
          return true;
      }

      void compute_possible_observations(const T &tip,
                                         const Instance::Action &action,
                                         std::vector<std::set<int> > &possible_observations) const {
          std::map<std::string, std::set<int> >::const_iterator it = lw1_instance_.vars_sensed_by_action_.find(action.name());

#ifdef DEBUG
          std::cout << Utils::magenta() << "Policy<T>::compute_possible_observations():" << Utils::normal()
                    << " action=" << action.name()
                    << ", #vars-sensed-by-action=" << (it == lw1_instance_.vars_sensed_by_action_.end() ? 0 : it->second.size())
                    << std::endl;
#endif

          if( it != lw1_instance_.vars_sensed_by_action_.end() ) {
              assert(it->first == action.name());
              std::map<int, std::vector<int> > observable_literals;
              for( std::set<int>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                  int var_index = *jt;
                  const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
                  assert(variable.is_observable());
#ifdef DEBUG
                  std::cout << Utils::green() << variable << Utils::normal() << std::endl;
#endif

                  // for state variable, possible observations correspond to values not rule
                  // out by tip node; i.e. X=x is possible iff K-x doesn't hold in tip. For
                  // observable variables, we generate all possible combinations. Pruning of
                  // inconsistent observation (wrt tip) is performed later using inference
                  // engine. Binary variables are handled separately as usual ...
                  if( variable.is_binary() ) {
#ifdef DEBUG
                      std::cout << Utils::green() << "variable '" << variable.name() << "' is binary" << Utils::normal() << std::endl;
#endif
                      int atom = *variable.domain().begin();
                      if( variable.is_state_variable() ) {
#ifdef DEBUG
                          std::cout << Utils::green() << "variable '" << variable.name() << "' is state variable" << Utils::normal() << std::endl;
#endif
                          if( !tip.satisfy(2 * atom + 1) )
                              observable_literals[var_index].push_back(1 + atom);
                          if( !tip.satisfy(2 * atom) )
                              observable_literals[var_index].push_back(-(1 + atom));
                      } else {
#ifdef DEBUG
                          std::cout << Utils::green() << "variable '" << variable.name() << "' is observable variable" << Utils::normal() << std::endl;
#endif
                          observable_literals[var_index].push_back(1 + atom);
                          observable_literals[var_index].push_back(-(1 + atom));
                      }
                  } else {
#ifdef DEBUG
                      std::cout << Utils::green() << "variable '" << variable.name() << "' is multivalued" << Utils::normal() << std::endl;
                      if( variable.is_state_variable() )
                          std::cout << Utils::green() << "variable '" << variable.name() << "' is state variable" << Utils::normal() << std::endl;
                      else
                          std::cout << Utils::green() << "variable '" << variable.name() << "' is observable variable" << Utils::normal() << std::endl;
#endif
                      for( std::set<int>::const_iterator kt = variable.domain().begin(); kt != variable.domain().end(); ++kt ) {
                          int atom = *kt;
#ifdef DEBUG
                          std::cout << "Literals: positive=";
                          State::print_literal(std::cout, 1 + 2 * atom, &lw1_instance_);
                          std::cout << ", negative=";
                          State::print_literal(std::cout, 1 + 2 * atom + 1, &lw1_instance_);
                          std::cout << ", satisfy-positive= ";
                          std::cout << tip.satisfy(2 * atom);
                          std::cout << std::endl;
#endif
                          if( variable.is_state_variable() ) {
                              if( !tip.satisfy(2 * atom + 1) )
                                  observable_literals[var_index].push_back(1 + atom);
                          } else {
                              observable_literals[var_index].push_back(1 + atom);
                          }
                      }
                  }
              }

              // generate all combinations
              possible_observations.clear();
              std::vector<std::pair<int, int> > combination;
              generate_combinations_recursively(tip, observable_literals.begin(), observable_literals.end(), combination, possible_observations);
              assert(combination.empty());
#ifdef DEBUG
              std::cout << Utils::green() << "#combinations-for-sensed-vars=" << possible_observations.size() << std::endl;
#endif
          }
      }
      void compute_observation(const T &hidden,
                               const T &tip,
                               const Instance::Action &action,
                               std::set<int> &observation,
                               std::map<int, std::pair<const LW1_Instance::Variable*, const std::vector<std::vector<int> >*> > &observed_literals) const {
          std::map<std::string, std::set<int> >::const_iterator it = lw1_instance_.vars_sensed_by_action_.find(action.name());

#ifdef DEBUG
          std::cout << Utils::magenta() << "Policy<T>::compute_observation():" << Utils::normal()
                    << " action=" << action.name()
                    << ", #vars-sensed-by-action=" << (it == lw1_instance_.vars_sensed_by_action_.end() ? 0 : it->second.size())
                    << std::endl;
#endif

          // fetch sensing models for observable non-state variables
          const std::map<int, std::map<int, std::vector<std::vector<int> > > > *sensing_models_for_action_as_k_dnf = 0;
          if( lw1_instance_.sensing_models_as_k_dnf_.find(action.name()) != lw1_instance_.sensing_models_as_k_dnf_.end() )
              sensing_models_for_action_as_k_dnf = &lw1_instance_.sensing_models_as_k_dnf_.at(action.name());

          // iterate over observable variables for action
          if( it != lw1_instance_.vars_sensed_by_action_.end() ) {
              assert(it->first == action.name());
              for( std::set<int>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                  int var_index = *jt;
                  const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
                  assert(variable.is_observable());
#ifdef DEBUG
                  std::cout << Utils::green() << variable << Utils::normal() << std::endl;
#endif

                  // For observable non-state variables, need to check sensing models. For observable
                  // state variables, return the value of the variable. In the latter case, binary 
                  // variables are handled seprately.
                  if( !variable.is_state_variable() ) {
#ifdef DEBUG
                      std::cout << Utils::green() << "variable '" << variable.name() << "' is observable variable" << Utils::normal() << std::endl;
#endif
                      assert(sensing_models_for_action_as_k_dnf != 0);
                      assert(sensing_models_for_action_as_k_dnf->find(var_index) != sensing_models_for_action_as_k_dnf->end());
                      const std::map<int, std::vector<std::vector<int> > > &sensing_models_for_var_as_k_dnf = sensing_models_for_action_as_k_dnf->at(var_index);
                      bool some_value_is_satisfied = false;
                      for( std::map<int, std::vector<std::vector<int> > >::const_iterator kt = sensing_models_for_var_as_k_dnf.begin(); kt != sensing_models_for_var_as_k_dnf.end(); ++kt ) {
#ifdef DEBUG
                          std::cout << Utils::bold() << "sensing model: obs=";
                          LW1_State::print_literal(std::cout, kt->first, &lw1_instance_.po_instance_);
                          std::cout << ", k-dnf=";
                          LW1_State::print_cnf_or_dnf(std::cout, kt->second, &lw1_instance_);
                          std::cout << ", status=" << satisfy(hidden, kt->second) << Utils::normal() << std::endl;
#endif

                          // check whether hidden state satisfies sensing model
                          if( satisfy(hidden, kt->second) ) {
                              observation.insert(kt->first);
                              some_value_is_satisfied = true;
                              assert(observed_literals.find(kt->first) == observed_literals.end());
                              observed_literals.insert(std::make_pair(kt->first, std::make_pair(&variable, &kt->second)));
                              break;
                          }
                      }
                      assert(some_value_is_satisfied);
                  } else {
#ifdef DEBUG
                      std::cout << Utils::green() << "variable '" << variable.name() << "' is state variable" << Utils::normal() << std::endl;
#endif
                      if( variable.is_binary() ) {
#ifdef DEBUG
                          std::cout << Utils::green() << "variable '" << variable.name() << "' is binary" << Utils::normal() << std::endl;
#endif
                          assert(variable.domain().size() == 1);
                          int atom = *variable.domain().begin();
                          bool some_value_is_satisfied = false;
                          if( hidden.satisfy(2 * atom) ) {
                              assert(!some_value_is_satisfied);
                              observation.insert(1 + atom);
                              some_value_is_satisfied = true;
                              assert(observed_literals.find(1 + atom) == observed_literals.end());
                              observed_literals.insert(std::make_pair(1 + atom, std::make_pair(&variable, static_cast<const std::vector<std::vector<int> >*>(0))));
                          }
                          if( hidden.satisfy(2 * atom + 1) ) {
                              assert(!some_value_is_satisfied);
                              observation.insert(-(1 + atom));
                              some_value_is_satisfied = true;
                              assert(observed_literals.find(-(1 + atom)) == observed_literals.end());
                              observed_literals.insert(std::make_pair(-(1 + atom), std::make_pair(&variable, static_cast<const std::vector<std::vector<int> >*>(0))));
                          }
                          assert(some_value_is_satisfied);
                      } else {
#ifdef DEBUG
                          std::cout << Utils::green() << "variable '" << variable.name() << "' is multivalued" << Utils::normal() << std::endl;
#endif

                          bool some_value_is_satisfied = false;
                          for( std::set<int>::const_iterator kt = variable.domain().begin(); kt != variable.domain().end(); ++kt ) {
                              int atom = *kt;
#ifdef DEBUG
                              std::cout << "Literals: positive=";
                              State::print_literal(std::cout, 1 + 2 * atom, &lw1_instance_);
                              std::cout << ", negative=";
                              State::print_literal(std::cout, 1 + 2 * atom + 1, &lw1_instance_);
                              std::cout << ", satisfy-positive= ";
                              std::cout << tip.satisfy(2 * atom);
                              std::cout << std::endl;
#endif
                              if( hidden.satisfy(2 * atom) ) {
                                  observation.insert(1 + atom);
                                  some_value_is_satisfied = true;
                                  assert(observed_literals.find(1 + atom) == observed_literals.end());
                                  observed_literals.insert(std::make_pair(1 + atom, std::make_pair(&variable, static_cast<const std::vector<std::vector<int> >*>(0))));
                                  break;
                              }
                          }
                          assert(some_value_is_satisfied);
                      }
                  }
              }
          }
      }

      void generate_combinations_recursively(const T &tip, // currently not used
                                             std::map<int, std::vector<int> >::const_iterator it,
                                             const std::map<int, std::vector<int> >::const_iterator end,
                                             std::vector<std::pair<int, int> > &combination,
                                             std::vector<std::set<int> > &possible_observations) const {
#ifdef DEBUG
          //std::cout << Utils::magenta() << "Policy<T>::generate_combinations_recursively()" << Utils::normal() << std::endl;
#endif
          if( it != end ) {
              // extend combination with (variable,value) pair from available
              // option, and make recursive call to generate all possible combinations
              int var_index = it->first;
              const std::vector<int> &options = it->second;
              for( size_t k = 0; k < options.size(); ++k ) {
                  int literal = options[k];
                  combination.push_back(std::make_pair(var_index, literal));
                  ++it;
                  generate_combinations_recursively(tip, it, end, combination, possible_observations);
                  --it;
                  combination.pop_back();
              }
          } else {
              // we don't perform any check on consitency of combination.
              // Such a check is performed later using the inference engine.
              std::set<int> observation;
              for( size_t i = 0; i < combination.size(); ++i )
                  observation.insert(combination[i].second);
              possible_observations.push_back(observation);
          }
      }

      float propagate(const AndOr::OrNode<T> *node) const {
          if( is_goal(*node) ) { // node is goal
              node->set_score(0);
          } else if( node->children().empty() ) { // node is dead-end either pruned, or real dead-end
              if( node->pruned() ) {
                  // score is proportional to 1 + number of unknown variables
                  int number_unknown_variables = calculate_unknown_variables(*node->belief()->belief());
                  node->set_score(100 * (1 + number_unknown_variables)); // CHECK: value
                  //node->set_score(1000); // CHECK: value
              } else {
                  // node is a real dead-end
                  node->set_score(10000); // CHECK: value
              }
          } else {
              float score_best_children = std::numeric_limits<float>::max();
              for( size_t k = 0; k < node->children().size(); ++k ) {
                  float score = propagate(node->child(k));
                  if( score < score_best_children )
                      score_best_children = score;
              }
              assert(score_best_children < std::numeric_limits<float>::max());
              node->set_score(score_best_children);
          }
          return node->score();
      }
      float propagate(const AndOr::AndNode<T> *node) const {
          assert(node->children().size() == 1);
          float score = 1 + propagate(node->child(0)); // CHECK: should add action cost
          node->set_score(score);
          return node->score();
      }

      virtual std::string name() const {
          std::string str = std::string("hop(") +
            "num-sampled-scenarios=" + std::to_string(num_sampled_scenarios_) +
            ",prune-nodes=" + std::to_string(prune_nodes_) +
            ")";
          return str;
      }
      virtual float get_search_time() const { return total_search_time_; }
      virtual float get_time() const { return total_time_; }
      virtual size_t n_calls() const { return n_calls_; }
      virtual void reset_stats() const {
          total_search_time_ = 0;
          total_time_ = 0;
          n_calls_ = 0;
      }

      virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const {
          std::cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << std::endl;
          float start_time = Utils::read_time_in_seconds();
          ++n_calls_;

          // easy case: current state is goal state
          if( is_goal(state) ) {
              assert(state.applicable(*lw1_instance_.top_subgoaling_action()));
              raw_plan.push_back(lw1_instance_.index_top_subgoaling_action());
              plan.push_back(lw1_instance_.index_top_subgoaling_action());
              float end_time = Utils::read_time_in_seconds();
              total_search_time_ += end_time - start_time;
              total_time_ += end_time - start_time;
              return ActionSelection<T>::SOLVED;
          }

          // determine known/unknown variables at state
          std::vector<int> unknown_variables;
          calculate_unknown_variables(state, unknown_variables);

#ifdef DEBUG
          std::cout << Utils::magenta();
          std::cout << "belief=";
          state.print(std::cout, lw1_instance_);
          std::cout << Utils::normal() << std::endl;
#endif

          // sample graph to score actions
          std::map<int, std::map<std::vector<int>, int> > goal_paths;
          std::vector<float> action_scores(lw1_instance_.actions_.size(), std::numeric_limits<float>::max());
          for( size_t k = 0; k < num_sampled_scenarios_; ++k ) {
              reset_graph();
              //std::cout << Utils::bold() << "**** Running sampled scenario " << k << Utils::normal() << std::endl;

              // sample (full) state from given state (belief)
              T sampled_hidden(state);
              sample(state, unknown_variables, sampled_hidden);

#ifdef DEBUG
              std::cout << Utils::magenta();
              std::cout << "sampled=";
              sampled_hidden.print(std::cout, lw1_instance_);
              std::cout << Utils::normal() << std::endl;
#endif

              // construct AND/OR graph rooted at state
              std::vector<std::vector<int> > goal_paths_in_graph;
              AndOr::OrNode<T> *root = make_root(state);
              //std::cout << "root=" << *root << std::endl;
              //create_sampled_graph_breadth_first(root, goal_paths_in_graph, true); // CHECK: another sampled graph?
              create_sampled_graph_breadth_first(sampled_hidden, root, goal_paths_in_graph);
              //std::cout << "num-expansions=" << num_expansions_ << ", #root-children=" << root->children().size() << ", #gp=" << goal_paths_in_graph.size() << std::endl;

              // store goal-paths found in sampled graph
              for( size_t j = 0; j < goal_paths_in_graph.size(); ++j ) {
                  const std::vector<int> &path = goal_paths_in_graph[j];
                  if( goal_paths.find(path.back()) == goal_paths.end() ) {
                      std::map<std::vector<int>, int> path_map;
#ifndef NO_EMPLACE
                      path_map.emplace(path, 1);
                      goal_paths.emplace(path.back(), std::move(path_map));
#else
                      path_map.insert(std::make_pair(path, 1));
                      goal_paths.insert(std::make_pair(path.back(), path_map));
#endif
                  } else {
                      std::map<std::vector<int>, int> &path_map = goal_paths.at(path.back());
                      if( path_map.find(path) == path_map.end() ) {
#ifndef NO_EMPLACE
                          path_map.emplace(path, 1);
#else
                          path_map.insert(std::make_pair(path, 1));
#endif
                      } else {
                          ++path_map[path];
                      }
                  }
              }

              // propagate values in graph
              propagate(root);
              //root->print_tree(std::cout);

              // update score for best children in graph
              for( size_t j = 0; j < root->children().size(); ++j ) {
                  int action = root->child(j)->action();
                  if( action_scores[action] == std::numeric_limits<float>::max() )
                      action_scores[action] = 0;
                  action_scores[action] += root->child(j)->score() / float(num_sampled_scenarios_);
              }

              // deallocate AND/OR graph
              deallocate_graph(root);
          }

#ifdef DEBUG
          // print goal-paths
          std::cout << Utils::bold() << "**** goal-paths" << Utils::normal() << std::endl;
          for( std::map<int, std::map<std::vector<int>, int> >::const_iterator it = goal_paths.begin(); it != goal_paths.end(); ++it ) {
              int first_action = it->first;
              const std::map<std::vector<int>, int> &path_map = it->second;
              std::cout << "  first-action=" << first_action << std::endl;
              for( std::map<std::vector<int>, int>::const_iterator jt = path_map.begin(); jt != path_map.end(); ++jt ) {
                  const std::vector<int> &path = jt->first;
                  assert(first_action == path.back());
                  std::cout << "    count=" << jt->second << ", path=";
                  for( size_t k = path.size(); k > 0; --k )
                      std::cout << " " << path[k - 1];
                  std::cout << std::endl;
              }
          }
#endif

          // compute best actions
          std::vector<int> best_actions;
          float score_best_actions = std::numeric_limits<float>::max();
          for( size_t k = 0; k < action_scores.size(); ++k ) {
              if( action_scores[k] <= score_best_actions ) {
                  if( action_scores[k] < score_best_actions ) {
                      score_best_actions = action_scores[k];
                      best_actions.clear();
                  }
                  best_actions.push_back(k);
              }
          }
          assert(score_best_actions < std::numeric_limits<float>::max());
          assert(!best_actions.empty());

#ifdef DEBUG
          // print action scores
          for( size_t k = 0; k < action_scores.size(); ++k ) {
              if( action_scores[k] < std::numeric_limits<float>::max() ) {
                  const Instance::Action &action = *lw1_instance_.actions_[k];
                  std::cout << Utils::cyan() << "score for '" << action.name() << "' is " << action_scores[k] << Utils::normal() << std::endl;
              }
          }
#endif
       
          // select best action
          int best_action_index = best_actions[lrand48() % best_actions.size()];

#ifdef DEBUG
          // print best action
          const Instance::Action &best_action = *lw1_instance_.actions_[best_action_index];
          assert(state.applicable(best_action));
          std::cout << Utils::blue() << "hop: best-actions=[";
          for( size_t k = 0; k < best_actions.size(); ++k ) {
              int index = best_actions[k];
              std::cout << lw1_instance_.actions_[index]->name() << "[index=" << index << "],";
          }
          std::cout << "], selected=" << best_action.name()
                    << ", index=" << best_action_index
                    << ", score=" << score_best_actions
                    << std::endl;
          std::cout << Utils::normal();
          std::cout << "n-ie=" << n_calls_to_inference_engine_ << std::endl;
#endif

          // sample goal-path using best action
          const std::vector<int> *sampled_path = 0;
          if( goal_paths.find(best_action_index) != goal_paths.end() ) {
              const std::map<std::vector<int>, int> &path_map = goal_paths.at(best_action_index);
              int path_count = 0;
              for( std::map<std::vector<int>, int>::const_iterator it = path_map.begin(); it != path_map.end(); ++it )
                  path_count += it->second;
              int path_index = lrand48() % path_count;
              for( std::map<std::vector<int>, int>::const_iterator it = path_map.begin(); it != path_map.end(); ++it ) {
                  if( path_index < it->second ) {
                      sampled_path = &it->first;
                      break;
                  } else {
                      path_index -= it->second;
                  }
              }
              assert(sampled_path != 0);
              assert(sampled_path->back() == best_action_index);

#ifdef DEBUG
              // print sampled path
              std::cout << Utils::bold() << "sampled-path(sz=" << sampled_path->size() << "):";
              for( size_t k = sampled_path->size(); k > 0; --k )
                  std::cout << " " << lw1_instance_.actions_[(*sampled_path)[k - 1]]->name();
              std::cout << Utils::normal() << std::endl;
#endif
          }

          // construct sampled path to be returned
          if( sampled_path != 0 ) {
              for( size_t k = sampled_path->size(); k > 0; --k ) {
                  int action = (*sampled_path)[k - 1];
                  raw_plan.push_back(action);
                  plan.push_back(action);
              }
              raw_plan.push_back(lw1_instance_.index_top_subgoaling_action());
              plan.push_back(lw1_instance_.index_top_subgoaling_action());
          } else {
              raw_plan.push_back(best_action_index);
              plan.push_back(best_action_index);
          }

          float end_time = Utils::read_time_in_seconds();
          total_search_time_ += end_time - start_time;
          total_time_ += end_time - start_time;
          return ActionSelection<T>::SOLVED;
      }

      virtual void calculate_assumptions(const NewSolver<T> &solver,
                                         const T &state,
                                         const Instance::Plan &raw_plan,
                                         const Instance::Plan &plan,
                                         const index_set &goal,
                                         std::vector<index_set> &assumptions) const {
          // apply actions in plan as long as they are applicable // CHECK: wrong as it may lead to a dead-end (see medpks)
          assumptions.insert(assumptions.end(), plan.size(), index_set());
      }
  };

} // namespace HOP

#undef DEBUG

#endif

