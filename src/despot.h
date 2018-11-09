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

#ifndef DESPOT_H
#define DESPOT_H

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

#define DEBUG

namespace Despot {

  template<typename T>
  class ActionSelection : public ::ActionSelection<T> {
      const LW1_Instance &lw1_instance_;
      const Inference::Engine<T> &inference_engine_;

      const int num_sampled_scenarios_;
      const int despot_depth_;
      const float target_gap_;
      const float gap_reduction_rate_;
      const float regularization_constant_;

      mutable float total_search_time_;
      mutable float total_time_;
      mutable size_t n_calls_;

    public:
      ActionSelection(const LW1_Instance &lw1_instance,
                      const Inference::Engine<T> &inference_engine,
                      int num_sampled_scenarios,
                      int despot_depth,
                      float target_gap,
                      float gap_reduction_rate,
                      float regularization_constant)
        : lw1_instance_(lw1_instance),
          inference_engine_(inference_engine),
          num_sampled_scenarios_(num_sampled_scenarios),
          despot_depth_(despot_depth),
          target_gap_(target_gap),
          gap_reduction_rate_(gap_reduction_rate),
          regularization_constant_(regularization_constant) {
      }
      virtual ~ActionSelection() { }

      virtual std::string name() const {
          std::string str = std::string("despot(") +
            "num-sampled-scenarios=" + std::to_string(num_sampled_scenarios_) +
            ",despot-depth=" + std::to_string(despot_depth_) +
            ",target-gap=" + std::to_string(target_gap_) +
            ",gap-reduction-rate=" + std::to_string(gap_reduction_rate_) +
            ",regularization-constant=" + std::to_string(regularization_constant_) +
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

      virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const;

      virtual void calculate_assumptions(const NewSolver<T> &solver,
                                         const T &state,
                                         const Instance::Plan &raw_plan,
                                         const Instance::Plan &plan,
                                         const index_set &goal,
                                         std::vector<index_set> &assumptions) const {
          assert(0);
      }
  };

#if 0
  template<typename T>
  class Node : public AndOr::Search::Node {
    protected:
      const AndOr::Policy<T> *policy_;
      const FeatureSet<T> *features_;
      int cost_;
      bool is_goal_;

    public:
      Node(const AndOr::Policy<T> *policy = nullptr, const FeatureSet<T> *features = nullptr, int cost = 0, bool is_goal = false)
        : policy_(policy), features_(features), cost_(cost), is_goal_(is_goal) {
      }
      virtual ~Node() { }

      const AndOr::Policy<T>* policy() const {
          return policy_;
      }
      const FeatureSet<T>* features() const {
          return features_;
      }
      int cost() const {
          return cost_;
      }
      bool is_goal() const {
          return is_goal_;
      }

      virtual int f() const {
          //std::cout << Utils::magenta() << "Node::f()" << Utils::normal() << std::endl;
          return cost_;
      }
      virtual std::string to_string() const {
          std::string str("Node[");
          str += "policy=" + std::to_string(size_t(policy_));
          str += ",features=" + std::to_string(size_t(features_));
          str += ",cost=" + std::to_string(cost_);
          return str + "]";
      }
  };

  template<typename T>
  class API : public AndOr::Search::API<T> {
    using AndOr::Search::API<T>::lw1_instance_;

    protected:
      const Inference::Engine<T> &inference_engine_;
      const Feature<T> *goal_feature_;
      const std::vector<const Feature<T>*> &feature_universe_;
      const std::vector<const Feature<T>*> &feature_language_;
      const std::vector<const Feature<T>*> &feature_language_noext_;
      const std::vector<const OrFeature<T>*> disjunctive_features_involving_goal_feature_;
      bool prune_nodes_;

      mutable AndOr::BeliefRepo<T> belief_repo_;
      mutable unsigned *feature_bitmap_;
      mutable unsigned num_available_features_;
      size_t feature_bitmap_size_;

      std::set<int> noop_singleton_;

      typedef typename std::map<const AndOr::OrNode<T>*, std::pair<std::map<int, AndOr::AndNode<T>*>, std::map<const Feature<T>*, std::set<int> > > > t_map_t;
      typedef typename t_map_t::mapped_type t_map_mapped_type_t;

    public:
      API(const LW1_Instance &lw1_instance,
          const Inference::Engine<T> &inference_engine,
          const Feature<T> *goal_feature,
          const std::vector<const Feature<T>*> &feature_universe,
          const std::vector<const Feature<T>*> &feature_language,
          const std::vector<const Feature<T>*> &feature_language_noext,
          const std::vector<const OrFeature<T>*> disjunctive_features_involving_goal_feature,
          bool prune_nodes = true)
        : AndOr::Search::API<T>(lw1_instance),
          inference_engine_(inference_engine),
          goal_feature_(goal_feature),
          feature_universe_(feature_universe),
          feature_language_(feature_language),
          feature_language_noext_(feature_language_noext),
          disjunctive_features_involving_goal_feature_(disjunctive_features_involving_goal_feature),
          prune_nodes_(prune_nodes) {
          feature_bitmap_size_ = (feature_universe_.size() >> 5) + ((feature_universe_.size() % 32) == 0 ? 0 : 1);
          feature_bitmap_ = new unsigned[feature_bitmap_size_];
          noop_singleton_ = std::set<int>();
          noop_singleton_.insert(-1);
      }
      virtual ~API() {
          //delete[] available_features_bitmap_;
          //delete[] available_features_ext_bitmap_;
          delete[] feature_bitmap_;
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
      bool is_feature_available(const Feature<T> &feature) const {
          int index = feature.index() >> 5, offset = feature.index() % 32;
          return is_feature_available(index, offset);
      }
      void register_feature(int index, int offset) const {
          assert((index >= 0) && (index < feature_bitmap_size_));
          assert((offset >= 0) && (offset < 32));
          feature_bitmap_[index] = feature_bitmap_[index] & ~(1 << offset);
      }
      void register_feature(const Feature<T> &feature) const {
          assert(feature.index() < feature_universe_.size());
          int index = feature.index() >> 5, offset = feature.index() % 32;
          if( is_feature_available(index, offset) && (feature.index() < feature_language_.size()) )
              --num_available_features_;
          register_feature(index, offset);
      }

      bool is_feature_valid(const T &tip, const Feature<T> &feature, bool verbose = false) const {
          return feature.holds(tip, verbose);
      }
      bool is_feature_valid(const AndOr::Policy<T> &policy, const T &tip, const Feature<T> &feature, bool verbose = false) const {
          return feature.holds(policy, tip, verbose);
      }
      bool is_feature_valid(const AndOr::Policy<T> &policy, const Feature<T> &feature, bool verbose = false) const {
          return feature.holds(policy, verbose);
      }
      void compute_achieved_features(const AndOr::Policy<T> &policy,
                                     const std::vector<const Feature<T>*> &feature_language,
                                     bool (API::*is_feature_available)(const Feature<T> &feature) const,
                                     FeatureSet<T> &achieved,
                                     bool verbose = false) const {
#ifdef DEBUG
          std::cout << Utils::magenta() << "API::compute_achieved_features(): " << Utils::normal()
                    << "#tips=" << policy.tip_nodes().size()
                    << std::endl;
#endif
          assert(!policy.tip_nodes().empty());
          achieved.clear();
          for( size_t k = 0; k < feature_language.size(); ++k ) {
              const Feature<T> &feature = *feature_language[k];
              if( !(this->*is_feature_available)(feature) ) continue;
              if( is_feature_valid(policy, feature, verbose) ) {
#ifdef DEBUG
                  //std::cout << Utils::green() << "valid feature '" << feature << "'" << Utils::normal() << std::endl;
#endif
                  achieved.insert(&feature);
              }
          }
#ifdef DEBUG
          std::cout << Utils::green() << "#achieved-features=" << achieved.size() << Utils::normal() << std::endl;
#endif
      }

      int cost(const AndOr::Policy<T> &policy) const {
          return policy.cost();
      }

      virtual void reset() const {
          reset_bitmap_for_features(); // CHECK: ext
      }
      virtual Node<T>* make_root_node(const T *state) const {
          AndOr::Policy<T> *policy = new AndOr::Policy<T>(belief_repo_, state);
          FeatureSet<T> *features = new FeatureSet<T>;
          compute_achieved_features(*policy, feature_language_noext_, &API::is_feature_available, *features, false); // CHECK: ext
          int policy_cost = cost(*policy);
          bool is_goal = features->find(goal_feature_) != features->end();
          return new Node<T>(policy, features, policy_cost, is_goal);
      }
      virtual bool prune(const AndOr::Search::Node &n) const {
          if( prune_nodes_ ) {
              const Node<T> &node = static_cast<const Node<T>&>(n);
              if( node.features() != nullptr ) {
                  for( typename FeatureSet<T>::const_iterator it = node.features()->begin(); it != node.features()->end(); ++it ) {
                      if( is_feature_available(**it) ) // CHECK: ext
                          return false;
                  }
              }
              std::cout << Utils::magenta() << "API::prune():" << Utils::normal()
                        << " node=" << n
                        << ": " << Utils::red() << "prune node!" << Utils::normal()
                        << std::endl;
              return true;
          } else {
              std::cout << Utils::magenta() << "API::prune():" << Utils::normal() << " pruning is off" << std::endl;
              return false;
          }
      }
      virtual bool is_goal(const AndOr::Search::Node &n) const {
          const Node<T> &node = static_cast<const Node<T>&>(n);
          return node.is_goal();
      }
      virtual void expand(const AndOr::Search::Node &n, std::vector<const AndOr::Search::Node*> &successors) const {
          const Node<T> &node = static_cast<const Node<T>&>(n);
          const AndOr::Policy<T> &policy = *node.policy();
          const FeatureSet<T> &features = *node.features();
          int policy_cost = node.cost();

          std::cout << Utils::magenta() << "API::expand():" << Utils::normal() << std::flush
                    << " ptr=" << &n
                    << " node=" << n
                    << ", #tips=" << policy.tip_nodes().size()
                    << ", cost=" << policy_cost;
#if 0 // CHECK
                    << ", features={";
          for( typename FeatureSet<T>::const_iterator it = features.begin(); it != features.end(); ++it )
              std::cout << **it << ",";
          std::cout << "}";
#endif
          std::cout << std::endl;

          // register node's features as reached features
          for( typename FeatureSet<T>::const_iterator it = features.begin(); it != features.end(); ++it ) {
              assert(*it != nullptr);
              register_feature(**it); // CHECK: ext
          }
          std::cout << Utils::green() << "#available-features=" << num_available_features_ << Utils::normal() << std::endl;

          // generate tip extensions for available features
          t_map_t tip_map;
          for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tip_nodes().begin(); it != policy.tip_nodes().end(); ++it ) {
#ifdef DEBUG
              const T &tip = *(*it)->belief()->belief();
              std::cout << Utils::blue() << "TIP=" << Utils::normal();
              tip.print(std::cout, &lw1_instance_);
              std::cout << std::endl;
#endif
              compute_extensions_for_tip(*it, tip_map);
          }

          // calculate features reached along every branch (tip node) by inserting
          // features reached in first branch and then removing features not achieved
          // in some other branch
          std::set<const Feature<T>*> features_reached_by_all_branches;
          for( typename std::map<const Feature<T>*, std::set<int> >::const_iterator jt = tip_map.begin()->second.second.begin(); jt != tip_map.begin()->second.second.end(); ++jt ) {
              assert(is_feature_available(*jt->first));
              features_reached_by_all_branches.insert(jt->first);
          }

          for( typename std::set<const Feature<T>*>::iterator jt = features_reached_by_all_branches.begin(); jt != features_reached_by_all_branches.end(); ) {
              const Feature<T> &feature = **jt;
              bool valid_feature = true;
              for( typename t_map_t::const_iterator kt = ++tip_map.begin(); kt != tip_map.end(); ++kt ) {
                  if( kt->second.second.find(&feature) == kt->second.second.end() ) {
                      valid_feature = false;
                      break;
                  }
              }
              if( !valid_feature )
                  jt = features_reached_by_all_branches.erase(jt);
              else
                  ++jt;
          }
          std::cout << "#features-reached-by-all-branches=" << features_reached_by_all_branches.size() << std::endl;

          // compute successor nodes
          FeatureSet<T> features_achieved_by_successors;
          for( typename std::set<const Feature<T>*>::const_iterator jt = features_reached_by_all_branches.begin(); jt != features_reached_by_all_branches.end(); ++jt ) {
              const Feature<T> &feature = **jt;
              if( features_achieved_by_successors.find(&feature) != features_achieved_by_successors.end() )
                  continue;

              // create new policy for feature
              std::vector<int> fp;
              const AndOr::Policy<T> *new_policy = extend_policy_for_feature(policy, feature, tip_map, fp);
              assert(is_feature_valid(*new_policy, feature));
std::cout << "NEW POLICY FOR " << feature << std::endl;

#ifdef DEBUG
              std::cout << "fp=[";
              for( size_t k = 0; k < fp.size(); ++k ) {
                  int action_index = fp[k];
                  if( action_index != -1 ) {
                      const Instance::Action &action = *lw1_instance_.actions_[action_index];
                      std::cout << action_index << "." << action.name();
                  } else {
                      std::cout << action_index << "." << "NOOP";
                  }
                  if( 1 + k < fp.size() ) std::cout << " ";
              }
              std::cout << "]" << std::endl;
#endif

              // create successor node
              FeatureSet<T> *new_features = new FeatureSet<T>;
              compute_achieved_features(*new_policy, feature_language_noext_, &API::is_feature_available, *new_features); // CHECK: ext
              int new_policy_cost = 1 + policy_cost; // CHECK
              bool is_goal = new_features->find(goal_feature_) != new_features->end();
              Node<T> *new_node = new Node<T>(new_policy, new_features, new_policy_cost, is_goal);
              successors.push_back(new_node);

              // register new achieved features
              features_achieved_by_successors.insert(new_features->begin(), new_features->end());

#ifdef DEBUG
              std::cout << Utils::red()
                        << "SUCCESSOR: n=" << new_node
                        << ", feature=" << feature
                        << ", #tips=" << new_policy->tip_nodes().size()
                        << ", #features=" << new_features->size()
                        << ", cost=" << new_policy_cost
                        << Utils::normal() << std::endl;
              //std::cout << *new_features << std::endl;
#endif
          }
          std::cout << "#features-achieved-by-successors=" << features_achieved_by_successors.size() << std::endl;
          std::cout << "#successors=" << successors.size() << std::endl;
      }

      void compute_extensions_for_tip(const AndOr::OrNode<T> *tip_ptr, t_map_t &tip_map) const {
          const T &tip = *tip_ptr->belief()->belief();
          std::pair<typename t_map_t::iterator, bool> p = tip_map.emplace(tip_ptr, t_map_mapped_type_t());
          assert(p.second);
          if( !is_feature_valid(tip, *goal_feature_) ) {
              compute_extensions_for_tip(tip, p.first->second);
          } else {
              // tip node is goal. Use noop and mark all features involving goal
              std::cout << "*******************************" << std::endl;
              assert(is_feature_available(*goal_feature_));
              p.first->second.second.insert(std::make_pair(goal_feature_, noop_singleton_));
              for( size_t k = 0; k < disjunctive_features_involving_goal_feature_.size(); ++k ) {
                  const Feature<T> &feature = *disjunctive_features_involving_goal_feature_[k];
                  if( is_feature_available(feature) )
                      p.first->second.second.insert(std::make_pair(&feature, noop_singleton_));
              }
          }
      }

      void compute_extensions_for_tip(const T &tip, t_map_mapped_type_t &maps) const {
#ifdef DEBUG
          std::cout << Utils::magenta() << "API::compute_extensions_for_tip():" << Utils::normal()
                                        << " tip=" << &tip
                                        << std::endl;
#endif
          assert(!is_feature_valid(tip, *goal_feature_));

          // compute available features reached with noop action (index = -1)
          for( typename std::vector<const Feature<T>*>::const_iterator it = feature_language_.begin(); it != feature_language_.end(); ++it ) {
              const Feature<T> &feature = **it;
              if( !is_feature_available(feature) ) continue;
              if( is_feature_valid(tip, feature) ) {
                  maps.second.emplace(&feature, noop_singleton_);
#ifdef DEBUG
                  //std::cout << Utils::red()
                  //          << "feature '" << feature << "'"
                  //          << " holds after action NOOP"
                  //          << Utils::normal() << std::endl;
#endif
              }
          }

          // for each action, compute available features reached with action
          for( size_t action_index = 0; action_index < lw1_instance_.actions_.size(); ++action_index ) {
              if( (lw1_instance_.remap_action(action_index) == -1) && !lw1_instance_.is_subgoaling_rule(action_index) ) continue;
              const Instance::Action &action = *lw1_instance_.actions_[action_index];
              assert(lw1_instance_.is_regular_action(action_index));
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

                  // generate successor beliefs considering possible observations.
                  // Feature is achieved iff it is achieved in all successor beliefs
                  std::vector<std::set<int> > possible_observations;
                  compute_possible_observations(*result_after_action, action, possible_observations);
#ifdef DEBUG
                  //std::cout << Utils::green() << "#possible-obs=" << possible_observations.size() << Utils::normal() << std::endl;
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
                              //std::cout << Utils::blue() << "INCONSISTENT(a=" << action.name()
                              //          << ",o=obs[" << j << "])=" << Utils::normal();
                              //result_after_action_and_obs->print(std::cout, &lw1_instance_);
                              //std::cout << std::endl;
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
                  assert(!valid_successors.empty());

                  // check for available features on valid successors
                  bool action_achieves_some_feature = false;
                  for( typename std::vector<const Feature<T>*>::const_iterator it = feature_language_.begin(); it != feature_language_.end(); ++it ) {
                      const Feature<T> &feature = **it;
                      if( !is_feature_available(feature) ) continue;

                      bool is_valid = true;
                      for( size_t j = 0; j < valid_successors.size(); ++j ) {
                          const T &successor = *valid_successors[j];
                          if( !is_feature_valid(successor, feature) ) {
                              is_valid = false;
                              break;
                          }
                      }
                      if( is_valid ) {
                          action_achieves_some_feature = true;
                          maps.second.emplace(&feature, std::set<int>());
                          maps.second[&feature].insert(action_index);
#ifdef DEBUG
                          //std::cout << Utils::red()
                          //          << "feature '" << feature << "'"
                          //          << " holds after action " << action.name()
                          //          << Utils::normal() << std::endl;
#endif
                      }
                  }

                  if( action_achieves_some_feature ) {
                      // update and_node_map
                      AndOr::AndNode<T> *and_node = AndOr::create_and_node(action_index, result_after_action, valid_successors);
                      maps.first.insert(std::make_pair(action_index, and_node));
                  } else {
                      // delete result after action and all valid successors
                      delete result_after_action;
                      for( size_t j = 0; j < valid_successors.size(); ++j )
                          delete valid_successors[j];
                  }
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
                  //std::cout << Utils::green() << variable << Utils::normal() << std::endl;

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

      const AndOr::Policy<T>* extend_policy_for_feature(const AndOr::Policy<T> &policy,
                                                        const Feature<T> &feature,
                                                        const t_map_t &tip_map,
                                                        std::vector<int> &fp) const {
          fp.clear();
          AndOr::Policy<T> *new_policy = new AndOr::Policy<T>(policy.repo());
          for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tip_nodes().begin(); it != policy.tip_nodes().end(); ++it ) {
              const AndOr::OrNode<T> *tip = *it;
              const t_map_mapped_type_t &maps = tip_map.at(tip);
              const std::set<int> &actions_for_feature = maps.second.at(&feature);
              assert(!actions_for_feature.empty());
              int action = *actions_for_feature.begin();
              fp.push_back(action);
              if( action == -1 ) {
                  // this is the noop action, keep this tip in new policy
                  new_policy->add_tip(tip);
              } else {
                  AndOr::AndNode<T> *and_node = maps.first.at(action);
                  assert(and_node != nullptr);

                  // link and-node to (old) policy and create tips for new policy
                  and_node->set_parent(tip);
                  for( size_t j = 0; j < and_node->children().size(); ++j ) {
                      const AndOr::OrNode<T> *new_tip = and_node->child(j);
                      new_policy->add_tip(new_tip);
#if 0 // CHECK
                      std::cout << "NEW-TIP=";
                      new_tip->belief()->belief()->print(std::cout, &lw1_instance_);
                      std::cout << std::endl;
#endif
                  }
              }
          }
          return new_policy;
      }

  };
#endif

  template<typename T>
  inline int ActionSelection<T>::get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const { // CHECK: incomplete code
#if 0
      std::cout << Utils::magenta() << "Width::ActionSelection<T>::get_plan()" << Utils::normal() << std::endl;

      //AndOr::BeliefRepo<T> belief_repo;
      //AndOr::Policy<T> policy(belief_repo);
      //policy.make_root(&state);
      //std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << policy.root() << std::endl;
      //std::cout << "BEL=" << *policy.root()->belief() << ", RC=" << policy.root()->ref_count() << std::endl;

      //AndOr::OrNode<T> *root = AndOr::make_root_node(&state);
      //std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << *root << std::endl;
      //AndOr::Node<T>::deallocate(root);

      // CHECK: testing: turn off pruning
      API<T> api(lw1_instance_, inference_engine_, goal_feature_, feature_universe_, feature_language_, feature_language_noext_, disjunctive_features_involving_goal_feature_, true);
      AndOr::Search::bfs<T> bfs(lw1_instance_, api);
      bfs.search(state);

      std::cout << Utils::error() << "width-based action selection not yet implemented!" << std::endl;
      exit(-1);
#endif
      std::cout << "solver=" << name() << std::endl;
      std::cout << Utils::error() << "despot not yet implemented!" << std::endl;
      exit(-1);
      return 0;
  }

} // namespace Despot

#undef DEBUG

#endif

