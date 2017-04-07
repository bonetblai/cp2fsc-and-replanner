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
#include "features.h"
#include "and_or2.h"

#define DEBUG

namespace HOP {

#if 0
  template<typename T>
  class OrNode : public AndOr::OrNode<T> {
    protected:
      bool is_goal_;

    public:
      OrNode(const AndOr::Belief<T> *belief, const AndOr::AndNode<T> *parent, bool is_goal)
        : AndOr::OrNode<T>(belief, parent), is_goal_(is_goal) {
      }
      ~OrNode() { }
      bool is_goal() const {
          return is_goal_;
      }
  };
#endif

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

      size_t feature_bitmap_size_;
      mutable unsigned *feature_bitmap_;
      mutable unsigned num_available_features_;

      mutable unsigned num_expansions_;

      mutable float total_search_time_;
      mutable float total_time_;
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
          feature_bitmap_(0) {

          // Initialize language of features. For each state variable X with domain { x1, ..., xn },
          // add features for Kxi and DSZ(X)
          for( size_t var_index = 0; var_index < lw1_instance_.variables_.size(); ++var_index ) {
              const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
              if( variable.is_state_variable() ) {
                  std::cout << variable << std::endl;
                  // generate features for domain values
                  for( set<int>::const_iterator it = variable.domain().begin(); it != variable.domain().end(); ++it ) {
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
                      domain_size_features_.push_back(new Width::DomainSizeFeatureLE<T>(feature_index, lw1_instance_, var_index, 1 + i));
                      feature_universe_.push_back(domain_size_features_.back());
                      feature_language_.push_back(domain_size_features_.back());
#ifdef DEBUG
                      std::cout << "using " << *feature_language_.back() << std::endl;
#endif
                  }
              }
          }
          std::cout << Utils::green() << "#literal-features=" << literal_features_.size() << Utils::normal() << std::endl;
          std::cout << Utils::green() << "#domain-size-features=" << domain_size_features_.size() << Utils::normal() << std::endl;

          // create goal feature
          goal_feature_index_ = feature_universe_.size();
          goal_feature_ = new Width::GoalFeature<T>(goal_feature_index_, lw1_instance_);
          feature_universe_.push_back(goal_feature_);
          feature_language_.push_back(goal_feature_);
#ifdef DEBUG
          std::cout << "using " << *goal_feature_ << std::endl;
#endif
          std::cout << Utils::green() << "#goal-features=1" << Utils::normal() << std::endl;

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

      void compute_features(const T &state,
                            Width::FeatureSet<T> &features,
                            const std::vector<const Width::Feature<T>*> &feature_language,
                            bool verbose = false) const {
          features.clear();
          for( size_t k = 0; k < feature_language.size(); ++k ) {
              const Width::Feature<T> &feature = *feature_language[k];
              if( !is_feature_available(feature) ) continue;
              if( feature.holds(state, verbose) ) {
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

      // nodes
      bool is_goal(const T &state) const {
          assert(goal_feature_ != 0);
          return goal_feature_->holds(state);
      }
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

      bool expand_node(const AndOr::OrNode<T> &nodes, const Width::FeatureSet<T> &features) const {
          assert(goal_feature_ != 0);
          if( features.find(goal_feature_) != features.end() ) { // CHECK
              std::cout << "********** GOAL BELIEF **********" << std::endl;
          }
          return !features.empty() && (features.find(goal_feature_) == features.end());
      }

      void create_graph_breadth_first(AndOr::OrNode<T> *root, bool do_sampling) const {
          std::vector<AndOr::AndNode<T>*> successors;
          std::deque<AndOr::OrNode<T>*> queue;
          queue.push_front(root);
          while( !queue.empty() ) {
              AndOr::OrNode<T> *node = queue.back();
              queue.pop_back();
              std::cout << "processing=" << *node << std::endl;

              // compute features
              Width::FeatureSet<T> features;
              compute_features(*node->belief()->belief(), features, feature_language_, false);

              if( expand_node(*node, features) ) {
                  // register node's features
                  for( typename Width::FeatureSet<T>::const_iterator it = features.begin(); it != features.end(); ++it ) {
                      assert(*it != 0);
                      register_feature(**it);
                  }
                  std::cout << Utils::green() << "#available-features=" << num_available_features_ << Utils::normal() << std::endl;

                  assert(successors.empty());
                  expand(*node, successors, do_sampling);
                  std::cout << "#successors=" << successors.size() << std::endl;
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

          // generate successors for each action
          const T &tip = *node.belief()->belief();
          for( size_t action_index = 0; action_index < lw1_instance_.actions_.size(); ++action_index ) {
              if( (lw1_instance_.remap_action(action_index) == -1) && !lw1_instance_.is_subgoaling_rule(action_index) ) continue;
              assert(lw1_instance_.is_regular_action(action_index));
              const Instance::Action &action = *lw1_instance_.actions_[action_index];
              if( tip.applicable(action) ) {
                  std::cout << Utils::green() << "action=" << Utils::normal() << action.name() << std::endl;

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
                          const std::set<int> obs = possible_observations[j];

                          // possible observation is *valid* if once it is assimilated
                          // (i.e. inference is done), it results in a consistent state
                          T *result_after_action_and_obs = new T(*result_after_action);
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
                      // there are no observable variables. Hence, there is single
                      // successor equal to belief_a
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

      void compute_possible_observations(const T &tip,
                                         const Instance::Action &action,
                                         std::vector<std::set<int> > &possible_observations) const {
          map<std::string, std::set<int> >::const_iterator it = lw1_instance_.vars_sensed_by_action_.find(action.name());

#ifdef DEBUG
          //std::cout << Utils::magenta() << "Policy<T>::compute_possible_observations():" << Utils::normal()
          //          << " action=" << action.name()
          //          << ", #vars-sensed-by-action=" << (it == lw1_instance_.vars_sensed_by_action_.end() ? 0 : it->second.size())
          //          << std::endl;
#endif

          if( it != lw1_instance_.vars_sensed_by_action_.end() ) {
              assert(it->first == action.name());

              std::map<int, std::vector<int> > observable_literals;
              for( std::set<int>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                  int var_index = *jt;
                  const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
                  assert(variable.is_observable());
                  std::cout << Utils::green() << variable << Utils::normal() << std::endl;

                  // for state variable, possible observations correspond to values not tule
                  // out by tip node; i.e. X=x is possible iff K-x doesn't hold in tip. For
                  // observable variables, we generate all possible combinations. Pruning of
                  // inconsistent observation (wrt tip) is performed later using inference
                  // engine. Binary variables are handled separately as usual ...
                  if( variable.is_binary() ) {
#ifdef DEBUG
                      //std::cout << Utils::green() << "variable '" << variable.name() << "' is binary" << Utils::normal() << std::endl;
#endif
                      int atom = *variable.domain().begin();
                      if( variable.is_state_variable() ) {
#ifdef DEBUG
                          //std::cout << Utils::green() << "variable '" << variable.name() << "' is state variable" << Utils::normal() << std::endl;
#endif
                          if( !tip.satisfy(1 + 2*atom + 1) )
                              observable_literals[var_index].push_back(1 + atom);
                          if( !tip.satisfy(1 + 2*atom) )
                              observable_literals[var_index].push_back(-(1 + atom));
                      } else {
#ifdef DEBUG
                          //std::cout << Utils::green() << "variable '" << variable.name() << "' is observable variable" << Utils::normal() << std::endl;
#endif
                          observable_literals[var_index].push_back(1 + atom);
                          observable_literals[var_index].push_back(-(1 + atom));
                      }
                  } else {
#ifdef DEBUG
                      //std::cout << Utils::green() << "variable '" << variable.name() << "' is multivalued" << Utils::normal() << std::endl;
                      //if( variable.is_state_variable() )
                      //    std::cout << Utils::green() << "variable '" << variable.name() << "' is state variable" << Utils::normal() << std::endl;
                      //else
                      //    std::cout << Utils::green() << "variable '" << variable.name() << "' is observable variable" << Utils::normal() << std::endl;
#endif
                      for( set<int>::const_iterator kt = variable.domain().begin(); kt != variable.domain().end(); ++kt ) {
                          int atom = *kt;
                          if( variable.is_state_variable() ) {
                              if( !tip.satisfy(1 + 2*atom + 1) )
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
              //std::cout << Utils::green() << "#combinations-for-sensed-vars=" << possible_observations.size() << std::endl;
#endif
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

      std::pair<int, float> propagate(const AndOr::OrNode<T> *node) const {
          if( is_goal(*node) ) { // node is goal
              return std::make_pair(-1, float(0));
          } else if( node->children().empty() ) { // node is dead-end either pruned, or real dead-end
              return std::make_pair(-1, float(1000)); // CHECK: dead-end value
          } else {
              std::vector<int> best_children;
              float score_best_children = std::numeric_limits<float>::max();
              for( size_t k = 0; k < node->children().size(); ++k ) {
                  std::pair<int, float> p = propagate(node->child(k));
                  if( p.second <= score_best_children ) {
                      if( p.second < score_best_children ) {
                          score_best_children = p.second;
                          best_children.clear();
                      }
                      best_children.push_back(k);
                  }
              }
              assert(score_best_children < std::numeric_limits<float>::max());
              assert(!best_children.empty());
              int k = lrand48() % best_children.size();
              return std::make_pair(best_children[k], score_best_children);
          }
      }
      std::pair<int, float> propagate(const AndOr::AndNode<T> *node) const {
          assert(node->children().size() == 1);
          return propagate(node->child(0));
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
          std::cout << "solver=" << name() << std::endl;
          std::cout << Utils::magenta() << "HOP::ActionSelection<T>::get_plan()" << Utils::normal() << std::endl;

          // sample graph to score actions
          std::vector<float> action_scores(lw1_instance_.actions_.size(), std::numeric_limits<float>::max());
          for( size_t k = 0; k < num_sampled_scenarios_; ++k ) {
              std::cout << "running sampled scenario " << k << std::endl;
              reset_graph();

              // construct AND/OR graph rooted at state
              AndOr::OrNode<T> *root = make_root(state);
              std::cout << "root=" << *root << std::endl;
              create_graph_breadth_first(root, true);
              std::cout << "num-expansions=" << num_expansions_ << std::endl;

              // propagate values in graph
              std::pair<int, float> p = propagate(root);

              // update score for best first actions in graph
              if( action_scores[p.first] == std::numeric_limits<float>::max() )
                  action_scores[p.first] = 0;
              action_scores[p.first] += p.second / float(num_sampled_scenarios_);

              // deallocate AND/OR graph
              deallocate_graph(root);
          }

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
       
          // select best action
          int best_action_index = best_actions[lrand48() % best_actions.size()];
          const Instance::Action &best_action = *lw1_instance_.actions_[best_action_index];
          std::cout << "hop: best-action=" << best_action.name() << ", index=" << best_action_index << ", score=" << score_best_actions << std::endl;

          exit(-1);
          return 0; // CHECK: not clear what to return and how to update raw_plan and plan
      }
  };

} // namespace HOP

#undef DEBUG

#endif

