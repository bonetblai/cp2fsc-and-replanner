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

#ifndef WIDTH_H
#define WIDTH_H

#include <cassert>
#include <iostream>
#include <list>
#include <vector>
#include "action_selection.h"
#include "lw1_problem.h"
#include "utils.h"

#include "and_or_search.h"
#include "features.h"
#include "and_or.h"

#define DEBUG

namespace Width {

  template<typename T>
  class ActionSelection : public ::ActionSelection<T> {
      const LW1_Instance &lw1_instance_;
      std::vector<const Feature<T>*> feature_language_;

      mutable float total_search_time_;
      mutable float total_time_;
      mutable size_t n_calls_;

    public:
      ActionSelection(const LW1_Instance &lw1_instance)
        : lw1_instance_(lw1_instance) {
          // Initialize language of features to be used
          //
          // For each state variable X with domain { x1, ..., xn }, add
          // features for Kxi, K-xi, and DSZ(X)
          for( size_t var_index = 0; var_index < lw1_instance_.variables_.size(); ++var_index ) {
              const LW1_Instance::Variable &var = *lw1_instance_.variables_[var_index];
              if( var.is_state_variable() ) {
                  // generate feature for domain values
                  if( var.is_binary() ) {
                      int atom = *var.domain().begin();
                      feature_language_.push_back(new LiteralFeature<T>(lw1_instance_, var_index, 1 + 2*atom));
#ifdef DEBUG
                      std::cout << "new " << *feature_language_.back() << std::endl;
#endif
                      feature_language_.push_back(new LiteralFeature<T>(lw1_instance_, var_index, 1 + 2*atom + 1));
#ifdef DEBUG
                      std::cout << "new " << *feature_language_.back() << std::endl;
#endif
                  } else {
                      for( set<int>::const_iterator it = var.domain().begin(); it != var.domain().end(); ++it ) {
                          feature_language_.push_back(new LiteralFeature<T>(lw1_instance_, var_index, 1 + 2*(*it)));
#ifdef DEBUG
                          std::cout << "new " << *feature_language_.back() << std::endl;
#endif
                      }
                  }

                  // generate feature for domain size
                  size_t dsize = var.is_binary() ? 2 : var.domain().size();
                  for( size_t i = 0; i < dsize; ++i ) {
                      feature_language_.push_back(new DomainSizeLiteralFeature<T>(lw1_instance_, var_index, 1 + i));
#ifdef DEBUG
                      std::cout << "new " << *feature_language_.back() << std::endl;
#endif
                  }
              }
          }
          std::cout << Utils::green() << "#features=" << feature_language_.size() << Utils::normal() << std::endl;
      }
      virtual ~ActionSelection() {
          for( size_t k = 0; k < feature_language_.size(); ++k )
              delete feature_language_[k];
      }

      virtual const char* name() const { return "width-based-action-selection"; }
      virtual float get_search_time() const { return total_search_time_; }
      virtual float get_time() const { return total_time_; }
      virtual size_t n_calls() const { return n_calls_; }
      virtual void reset_stats() const {
          total_search_time_ = 0;
          total_time_ = 0;
          n_calls_ = 0;
      }

      virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const;
  };

  template<typename T>
  class Node : public AndOr::Search::Node {
    protected:
      const AndOr::Policy<T> *policy_;
      const FeatureList<T> *features_;
      int cost_;

    public:
      Node(const AndOr::Policy<T> *policy = 0, const FeatureList<T> *features = 0, int cost = 0)
        : policy_(policy), features_(features), cost_(cost) {
      }
      virtual ~Node() { }

      const AndOr::Policy<T>* policy() const {
          return policy_;
      }
      const FeatureList<T>* features() const {
          return features_;
      }
      int cost() const {
          return cost_;
      }

      virtual int f() const {
          std::cout << Utils::magenta() << "Node::f()" << Utils::normal() << std::endl;
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
      const std::vector<const Feature<T>*> &feature_language_;
      bool prune_nodes_;

      mutable AndOr::BeliefRepo<T> belief_repo_;
      mutable FeatureSet<T> available_features_;

    public:
      API(const LW1_Instance &lw1_instance, const std::vector<const Feature<T>*> &feature_language, bool prune_nodes = true)
        : AndOr::Search::API<T>(lw1_instance),
          feature_language_(feature_language),
          prune_nodes_(prune_nodes) {
      }
      virtual ~API() { }

      bool is_feature_valid(const AndOr::OrNode<T> *node, const Feature<T> *feature) const {
          assert((node != 0) && (feature != 0));
#ifdef DEBUG
          std::cout << Utils::magenta() << "API::is_feature_valid():" << Utils::normal()
                    << " feature=" << *feature
                    << ", res=" << feature->holds(*node->belief()->belief())
                    << std::endl;
#endif
          return feature->holds(*node->belief()->belief());
      }
      void extract_features(const AndOr::Policy<T> &policy, FeatureList<T> &features) const {
#ifdef DEBUG
          std::cout << Utils::magenta() << "API::extract_features(): " << Utils::normal()
                    << "#tips=" << policy.tip_nodes().size()
                    << std::endl;
#endif
          assert(!policy.tip_nodes().empty());
          features.clear();
          for( typename FeatureSet<T>::const_iterator it = available_features_.begin(); it != available_features_.end(); ++it ) {
              const Feature<T> *feature = *it;
              bool feature_is_achieved = true;
              for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tip_nodes().begin(); it != policy.tip_nodes().end(); ++it ) {
                  if( !is_feature_valid(*it, feature) ) {
                      feature_is_achieved = false;
                      break;
                  }
              }
              if( feature_is_achieved ) features.push_back(feature);
          }
#ifdef DEBUG
          std::cout << "#valid-features=" << features.size() << std::endl;
#endif
      }

      bool is_goal(const AndOr::OrNode<T> *node) const {
#ifdef DEBUG
          std::cout << Utils::magenta() << "API::is_goal(<node>): " << Utils::normal()
                    << "res=" << node->belief()->belief()->is_goal(lw1_instance_)
                    << std::endl;
#endif
          return node->belief()->belief()->is_goal(lw1_instance_);
      }
      bool is_goal(const AndOr::Policy<T> &policy) const {
#ifdef DEBUG
          std::cout << Utils::magenta() << "API::is_goal(<policy>): " << Utils::normal()
                    << "#tips=" << policy.tip_nodes().size()
                    << std::endl;
#endif
          assert(!policy.tip_nodes().empty());
          for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tip_nodes().begin(); it != policy.tip_nodes().end(); ++it ) {
              if( !is_goal(*it) )
                  return false;
          }
          return true;
      }
      int cost(const AndOr::Policy<T> &policy) const {
          return policy.cost();
      }

      virtual void reset() const {
          available_features_ = std::set<const Feature<T>*>(feature_language_.begin(), feature_language_.end());
      }
      virtual Node<T>* make_root_node(const T *state) const {
          AndOr::Policy<T> *policy = new AndOr::Policy<T>(belief_repo_, state);
          FeatureList<T> *features = new FeatureList<T>;
          extract_features(*policy, *features);
          int policy_cost = cost(*policy);
          return new Node<T>(policy, features, policy_cost);
      }
      virtual bool prune(const AndOr::Search::Node &n) const {
          if( prune_nodes_ ) {
              std::cout << Utils::magenta() << "API::prune():" << Utils::normal() << " node=" << n << ": " << std::flush;
              const Node<T> &node = static_cast<const Node<T>&>(n);
              if( node.features() != 0 ) {
                  for( typename FeatureList<T>::const_iterator it = node.features()->begin(); it != node.features()->end(); ++it ) {
                      if( available_features_.find(*it) != available_features_.end() ) {
                          std::cout << Utils::red() << "don't prune node!" << Utils::normal() << std::endl;
                          return false;
                      }
                  }
              }
              std::cout << Utils::red() << "prune node!" << Utils::normal() << std::endl;
              return true;
          } else {
              std::cout << Utils::magenta() << "API::prune():" << Utils::normal() << " pruning is off" << std::endl;
              return false;
          }
      }
      virtual bool is_goal(const AndOr::Search::Node &n) const {
          const Node<T> &node = static_cast<const Node<T>&>(n);
          assert(node.policy() != 0);
          return is_goal(*node.policy());
      }
      virtual void expand(const AndOr::Search::Node &n, std::vector<const AndOr::Search::Node*> &successors) const {
          std::cout << Utils::magenta() << "API::expand():" << Utils::normal() << " node=" << n << std::endl;
          const Node<T> &node = static_cast<const Node<T>&>(n);
          const AndOr::Policy<T> &policy = *node.policy();
          int policy_cost = node.cost();

          // register node's features as reached features
          assert(node.features() != 0);
          for( typename FeatureList<T>::const_iterator it = node.features()->begin(); it != node.features()->end(); ++it )
              available_features_.erase(*it);

          // perform expansion geared towards available features
          std::cout << Utils::green() << "#available-features=" << available_features_.size() << Utils::normal() << std::endl;
          for( typename FeatureSet<T>::const_iterator it = available_features_.begin(); it != available_features_.end(); ++it ) {
              const Feature<T> *feature = *it;
              // if there is an extension across all branches of node's plan
              // that achieves the given feature, generate a successor for it
              std::pair<const AndOr::Policy<T>*, int> p = policy.compute_extension_for(*this, feature);
              if( p.first != 0 ) {
                  FeatureList<T> *ext_features = new FeatureList<T>;
                  extract_features(*p.first, *ext_features);
                  int ext_policy_cost = policy_cost + p.second;
                  successors.push_back(new Node<T>(p.first, ext_features, ext_policy_cost));
              }
          }
          std::cout << "#successors=" << successors.size() << std::endl;
          assert(successors.size() <= available_features_.size());
      }
  };

  template<typename T>
  inline int ActionSelection<T>::get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const { // CHECK: incomplete code
      //AndOr::BeliefRepo<T> belief_repo;
      //AndOr::Policy<T> policy(belief_repo);
      //policy.make_root(&state);
      //std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << policy.root() << std::endl;
      //std::cout << "BEL=" << *policy.root()->belief() << ", RC=" << policy.root()->ref_count() << std::endl;

      //AndOr::OrNode<T> *root = AndOr::make_root_node(&state);
      //std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << *root << std::endl;
      //AndOr::Node<T>::deallocate(root);

      API<T> api(lw1_instance_, feature_language_, false); // CHECK: testing: turn off pruning
      AndOr::Search::bfs<T> bfs(lw1_instance_, api);
      bfs.search(state);

      std::cout << Utils::error() << "width-based action selection not yet implemented!" << std::endl;
      exit(-1);
  }

} // namespace Width

#undef DEBUG

#endif

