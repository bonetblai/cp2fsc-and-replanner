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
#include "utils.h"

#include "and_or_search.h"
#include "features.h"
#include "and_or.h"

namespace Width {

  template<typename T>
  class ActionSelection : public ::ActionSelection<T> {
      const KP_Instance &kp_instance_;
      std::vector<const Feature*> feature_language_;

      mutable float total_search_time_;
      mutable float total_time_;
      mutable size_t n_calls_;

    public:
      ActionSelection(const KP_Instance &kp_instance) : kp_instance_(kp_instance) { }
      virtual ~ActionSelection() { }

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
      const FeatureList *features_;
      int cost_;

    public:
      Node(const AndOr::Policy<T> *policy = 0, const FeatureList *features = 0, int cost = 0)
        : policy_(policy), features_(features), cost_(cost) {
      }
      virtual ~Node() { }

      const AndOr::Policy<T>* policy() const {
          return policy_;
      }
      const FeatureList* features() const {
          return features_;
      }

      virtual int f() const {
          std::cout << Utils::magenta() << "Node::f()" << Utils::normal() << std::endl;
          return cost_;
      }
      virtual void print(std::ostream &os) const {
          os << "N["
             << "policy=" << policy_
             << ",features=" << features_
             << ",cost=" << cost_
             << "]" << std::flush;
      }
  };

  template<typename T>
  class API : public AndOr::Search::API<T> {
    protected:
      const KP_Instance &kp_instance_;
      const std::vector<const Feature*> &feature_language_;
      bool prune_nodes_;

      mutable AndOr::BeliefRepo<T> belief_repo_;
      mutable FeatureSet available_features_;

    public:
      API(const KP_Instance &kp_instance, const std::vector<const Feature*> &feature_language, bool prune_nodes = true)
        : kp_instance_(kp_instance), feature_language_(feature_language), prune_nodes_(prune_nodes) {
      }
      virtual ~API() { }

      bool is_feature_valid(const AndOr::OrNode<T> *node, const Feature *feature) const {
          std::cout << Utils::magenta() << "API::is_feature_valid()" << Utils::normal() << std::endl;
          // CHECK: FILL MISSING CODE
          return false;
      }
      void extract_features(const AndOr::Policy<T> &policy, FeatureList &features) const {
          std::cout << Utils::magenta() << "API::extract_features()" << Utils::normal() << std::endl;
          features.clear();
          for( FeatureSet::const_iterator it = available_features_.begin(); it != available_features_.end(); ++it ) {
              const Feature *feature = *it;
              bool feature_is_achieved = true;
              for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tips().begin(); it != policy.tips().end(); ++it ) {
                  if( !is_feature_valid(*it, feature) ) {
                      feature_is_achieved = false;
                      break;
                  }
              }
              if( feature_is_achieved ) features.push_back(feature);
          }
          std::cout << "#features=" << features.size() << std::endl;
      }

      bool is_goal(const AndOr::OrNode<T> *node) const {
          std::cout << Utils::magenta() << "API::is_goal(): " << Utils::normal() << node->belief()->belief()->is_goal(kp_instance_) << std::endl;
          return node->belief()->belief()->is_goal(kp_instance_);
      }
      bool is_goal(const AndOr::Policy<T> &policy) const {
          std::cout << Utils::magenta() << "API::is_goal(): " << Utils::normal() << "#tips=" << policy.tips().size() << std::endl;
          for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tips().begin(); it != policy.tips().end(); ++it ) {
              if( !is_goal(*it) )
                  return false;
          }
          return true;
      }
      int cost(const AndOr::Policy<T> &policy) const {
          return policy.cost();
      }

      virtual void reset() const {
          available_features_ = std::set<const Feature*>(feature_language_.begin(), feature_language_.end());
      }
      virtual Node<T>* make_root_node(const T *state) const {
          AndOr::Policy<T> *policy = new AndOr::Policy<T>(belief_repo_);
          policy->make_root(state);
          FeatureList *features = new FeatureList;
          extract_features(*policy, *features);
          int policy_cost = cost(*policy);
          return new Node<T>(policy, features, policy_cost);
      }
      virtual bool prune(const AndOr::Search::Node &n) const {
          if( prune_nodes_ ) {
              std::cout << Utils::magenta() << "API::prune():" << Utils::normal() << " node=" << n << ": " << std::flush;
              const Node<T> &node = static_cast<const Node<T>&>(n);
              if( node.features() != 0 ) {
                  for( FeatureList::const_iterator it = node.features()->begin(); it != node.features()->end(); ++it ) {
                      if( available_features_.find(*it) != available_features_.end() ) {
                          std::cout << Utils::red() << "don't prune node!" << Utils::normal() << std::endl;
                          return false;
                      }
                  }
              }
              std::cout << Utils::red() << "prune node!" << Utils::normal() << std::endl;
              return true;
          } else {
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

          // register node's features as reached features
          assert(node.features() != 0);
          for( FeatureList::const_iterator it = node.features()->begin(); it != node.features()->end(); ++it )
              available_features_.erase(*it);

          // perform expansion geared towards available features
          std::vector<std::pair<const AndOr::Policy<T>*, const FeatureList*> > extensions;
          for( FeatureSet::const_iterator it = available_features_.begin(); it != available_features_.end(); ++it ) {
              const Feature *feature = *it;
              // if there is an extension across all branches of node's plan
              // that achieves the given feature, store such extension
              // CHECK: FILL MISSING CODE
          }
          std::cout << "#extensions=" << extensions.size() << std::endl;

          // for each extension, create a successor node
          successors.clear();
          for( size_t i = 0; i < extensions.size(); ++i ) {
              const AndOr::Policy<T> *policy = extensions[i].first;
              const FeatureList *features = extensions[i].second;
              int policy_cost = cost(*policy);
              successors.push_back(new Node<T>(policy, features, policy_cost));
          }
          std::cout << "#successors=" << successors.size() << std::endl;
      }
  };

  template<typename T>
  inline int ActionSelection<T>::get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const { // CHECK: incomplete
      //AndOr::BeliefRepo<T> belief_repo;
      //AndOr::Policy<T> policy(belief_repo);
      //policy.make_root(&state);
      //std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << policy.root() << std::endl;
      //std::cout << "BEL=" << *policy.root()->belief() << ", RC=" << policy.root()->ref_count() << std::endl;

      //AndOr::OrNode<T> *root = AndOr::make_root_node(&state);
      //std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << *root << std::endl;
      //AndOr::Node<T>::deallocate(root);

      API<T> api(kp_instance_, feature_language_, false);
      AndOr::Search::bfs<T> bfs(api);
      bfs.search(state);

      std::cout << Utils::error() << "width-based action selection not yet implemented!" << std::endl;
      exit(-1);
  }

} // namespace Width

#endif

