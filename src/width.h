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
#include "inference_engine.h"
#include "utils.h"

#include "and_or_search.h"
#include "features.h"
#include "and_or2.h"

#define DEBUG

namespace Width {

  template<typename T>
  class ActionSelection : public ::ActionSelection<T> {
      const LW1_Instance &lw1_instance_;
      const Inference::Engine<T> &inference_engine_;

      const Feature<T> *goal_feature_;
      std::vector<const Feature<T>*> feature_language_;
      std::map<const Feature<T>*, FeatureSet<T> > subsumed_features_;
      std::vector<const Feature<T>*> disjunctive_features_involving_goal_feature_;

      mutable float total_search_time_;
      mutable float total_time_;
      mutable size_t n_calls_;

    public:
      ActionSelection(const LW1_Instance &lw1_instance, const Inference::Engine<T> &inference_engine)
        : lw1_instance_(lw1_instance),
          inference_engine_(inference_engine),
          goal_feature_(0) {
          // Initialize language of features to be used. For each
          // state variable X with domain { x1, ..., xn }, add
          // features for Kxi, K-xi, and DSZ(X)
          for( size_t var_index = 0; var_index < lw1_instance_.variables_.size(); ++var_index ) {
              const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
              if( variable.is_state_variable() ) {
                  // generate feature for domain values
                  if( variable.is_binary() ) {
                      int atom = *variable.domain().begin();
                      feature_language_.push_back(new LiteralFeature<T>(lw1_instance_, var_index, 1 + 2*atom));
#ifdef DEBUG
                      //std::cout << "new " << *feature_language_.back() << std::endl;
#endif
                      feature_language_.push_back(new LiteralFeature<T>(lw1_instance_, var_index, 1 + 2*atom + 1));
#ifdef DEBUG
                      //std::cout << "new " << *feature_language_.back() << std::endl;
#endif
                  } else {
                      for( set<int>::const_iterator it = variable.domain().begin(); it != variable.domain().end(); ++it ) {
                          feature_language_.push_back(new LiteralFeature<T>(lw1_instance_, var_index, 1 + 2*(*it)));
#ifdef DEBUG
                          //std::cout << "new " << *feature_language_.back() << std::endl;
#endif
                      }
                  }

                  // generate feature for domain size
                  size_t dsize = variable.is_binary() ? 2 : variable.domain().size();
                  for( size_t i = 0; i < dsize; ++i ) {
                      feature_language_.push_back(new DomainSizeLiteralFeature<T>(lw1_instance_, var_index, 1 + i));
#ifdef DEBUG
                      //std::cout << "new " << *feature_language_.back() << std::endl;
#endif
                  }
              }
          }

          // create goal feature
          goal_feature_ = new GoalFeature<T>(lw1_instance_);
          feature_language_.push_back(goal_feature_);
#ifdef DEBUG
          std::cout << "new " << *goal_feature_ << std::endl;
#endif

          // create disjunctive features
          std::vector<const Feature<T>*> disjunctive_features;
          for( size_t k = 0; k < feature_language_.size(); ++k ) {
              const Feature<T> &f1 = *feature_language_[k];
              for( size_t j = 1 + k; j < feature_language_.size(); ++j ) {
                  const Feature<T> &f2 = *feature_language_[j];
                  if( (dynamic_cast<const LiteralFeature<T>*>(&f1) != 0) && (dynamic_cast<const LiteralFeature<T>*>(&f2) != 0) ) {
                      if( static_cast<const LiteralFeature<T>&>(f1).var_index() == static_cast<const LiteralFeature<T>&>(f2).var_index() )
                          ;//continue;
                  }

                  OrFeature<T> *feature = new OrFeature<T>();
                  feature->add_disjunct(f1);
                  feature->add_disjunct(f2);
                  disjunctive_features.push_back(feature);
                  if( goal_feature_ == &f2 )
                      disjunctive_features_involving_goal_feature_.push_back(feature);
#ifdef DEBUG
                  //std::cout << "new " << *feature << std::endl;
#endif
              }
          }

          for( size_t k = 0; k < disjunctive_features.size(); ++k )
              feature_language_.push_back(disjunctive_features[k]);

          std::cout << Utils::green() << "#features=" << feature_language_.size() << Utils::normal() << std::endl;

          // calculate subsumed features
          for( size_t k = 0; k < feature_language_.size(); ++k ) {
              const Feature<T> &f1 = *feature_language_[k];
              subsumed_features_.emplace(&f1, FeatureSet<T>());
              for( size_t j = 1 + k; j < feature_language_.size(); ++j ) {
                  const Feature<T> &f2 = *feature_language_[j];
                  subsumed_features_.emplace(&f2, FeatureSet<T>());
                  if( f1.subsumes(f2) ) {
                      subsumed_features_[&f1].insert(&f2);
#ifdef DEBUG
                      //std::cout << "feature '" << f1 << "' subsumes '" << f2 << "'" << std::endl;
#endif
                  }
                  if( f2.subsumes(f1) ) {
                      subsumed_features_[&f2].insert(&f1);
#ifdef DEBUG
                      //std::cout << "feature '" << f2 << "' subsumes '" << f1 << "'" << std::endl;
#endif
                  }
              }
          }
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
      const FeatureSet<T> &feature_language_;
      const std::map<const Feature<T>*, FeatureSet<T> > &subsumed_features_;
      const std::vector<const Feature<T>*> disjunctive_features_involving_goal_feature_;
      bool prune_nodes_;

      mutable AndOr::BeliefRepo<T> belief_repo_;
      mutable FeatureSet<T> available_features_;

      typedef typename std::map<const AndOr::OrNode<T>*, std::pair<std::map<int, AndOr::AndNode<T>*>, std::map<const Feature<T>*, std::set<int> > > > t_map_t;
      typedef typename t_map_t::mapped_type t_map_mapped_type_t;

    public:
      API(const LW1_Instance &lw1_instance,
          const Inference::Engine<T> &inference_engine,
          const Feature<T> *goal_feature,
          const FeatureSet<T> &feature_language,
          const std::map<const Feature<T>*, FeatureSet<T> > &subsumed_features,
          const std::vector<const Feature<T>*> disjunctive_features_involving_goal_feature,
          bool prune_nodes = true)
        : AndOr::Search::API<T>(lw1_instance),
          inference_engine_(inference_engine),
          goal_feature_(goal_feature),
          feature_language_(feature_language),
          subsumed_features_(subsumed_features),
          disjunctive_features_involving_goal_feature_(disjunctive_features_involving_goal_feature),
          prune_nodes_(prune_nodes) {
      }
      virtual ~API() { }

      bool is_feature_valid(const AndOr::OrNode<T> *node, const Feature<T> &feature) const {
          assert(node != 0);
#ifdef DEBUG
          //std::cout << Utils::magenta() << "API::is_feature_valid():" << Utils::normal()
          //          << " feature=" << feature
          //          << ", res=" << feature.holds(*node->belief()->belief())
          //          << std::endl;
#endif
          return feature.holds(*node->belief()->belief());
      }
      void compute_achieved_features(const AndOr::Policy<T> &policy, const FeatureSet<T> &features, FeatureList<T> &achieved) const {
#ifdef DEBUG
          //std::cout << Utils::magenta() << "API::compute_achieved_features(): " << Utils::normal()
          //          << "#tips=" << policy.tip_nodes().size()
          //          << std::endl;
#endif
          assert(!policy.tip_nodes().empty());
          achieved.clear();
          for( typename FeatureSet<T>::const_iterator it = features.begin(); it != features.end(); ++it ) {
              const Feature<T> &feature = **it;
              bool feature_is_achieved = true;
              for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tip_nodes().begin(); it != policy.tip_nodes().end(); ++it ) {
                  if( !is_feature_valid(*it, feature) ) {
                      feature_is_achieved = false;
                      break;
                  }
              }
              if( feature_is_achieved ) {
#ifdef DEBUG
                  //std::cout << Utils::green() << "valid feature '" << feature << "'" << Utils::normal() << std::endl;
#endif
                  achieved.push_back(&feature);
              }
          }
#ifdef DEBUG
          //std::cout << Utils::green() << "#valid-features=" << features.size() << Utils::normal() << std::endl;
#endif

          // calculate subsumed features
          FeatureSet<T> subsumed_features;
          for( typename FeatureList<T>::const_iterator it = achieved.begin(); it != achieved.end(); ++it ) {
              const FeatureSet<T> &subsumed = subsumed_features_.at(*it);
              subsumed_features.insert(subsumed.begin(), subsumed.end());
          }

          // erase subsumed features
          for( typename FeatureList<T>::iterator it = achieved.begin(); it != achieved.end(); ) {
              if( subsumed_features.find(*it) != subsumed_features.end() ) {
                  it = achieved.erase(it);
              } else {
#ifdef DEBUG
                  //std::cout << Utils::green() << "non-subsumed feature '" << **it << "'" << Utils::normal() << std::endl;
#endif
                  ++it;
              }
          }
#ifdef DEBUG
          //std::cout << Utils::green() << "#non-subsumed-features=" << achieved.size() << Utils::normal() << std::endl;
#endif
      }

#if 0 // CHECK
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
#endif

      int cost(const AndOr::Policy<T> &policy) const {
          return policy.cost();
      }

      virtual void reset() const {
          // CHECK
          //available_features_ = std::set<const Feature<T>*, typename Feature<T>::ptr_compare_t>(feature_language_.begin(), feature_language_.end());
          available_features_ = feature_language_;
      }
      virtual Node<T>* make_root_node(const T *state) const {
          AndOr::Policy<T> *policy = new AndOr::Policy<T>(belief_repo_, state);
          FeatureList<T> *features = new FeatureList<T>;
          compute_achieved_features(*policy, available_features_, *features);
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
          assert(node.features() != 0);
          return (node.features()->size() == 1) && (*node.features()->begin() == goal_feature_);
#if 0
          assert(node.policy() != 0);
          return is_goal(*node.policy());
#endif
      }
      virtual void expand(const AndOr::Search::Node &n, std::vector<const AndOr::Search::Node*> &successors) const {
          const Node<T> &node = static_cast<const Node<T>&>(n);
          const AndOr::Policy<T> &policy = *node.policy();
          const FeatureList<T> &features = *node.features();
          int policy_cost = node.cost();

          std::cout << Utils::magenta() << "API::expand():" << Utils::normal()
                    << " node=" << n
                    << ", #tips=" << policy.tip_nodes().size()
                    << ", cost=" << policy_cost
                    << ", features={";
          for( typename FeatureList<T>::const_iterator it = features.begin(); it != features.end(); ++it )
              std::cout << **it << ",";
          std::cout << "}" << std::endl;

          // register node's features as reached features
          for( typename FeatureList<T>::const_iterator it = features.begin(); it != features.end(); ++it )
              available_features_.erase(*it); // CHECK
          std::cout << Utils::green() << "#available-features=" << available_features_.size() << Utils::normal() << std::endl;

          // generate tip extensions for available features
          t_map_t tip_map;
          for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tip_nodes().begin(); it != policy.tip_nodes().end(); ++it ) {
              const T &tip = *(*it)->belief()->belief();
#ifdef DEBUG
              std::cout << Utils::blue() << "TIP=" << Utils::normal();
              tip.print(std::cout, &lw1_instance_);
              std::cout << std::endl;
#endif
              std::pair<typename t_map_t::iterator, bool> p = tip_map.emplace(*it, t_map_mapped_type_t());
              assert(p.second);
              if( !goal_feature_->holds(tip) ) {
                  // CHECK: not sure which feature set to use here.
                  compute_extensions_for_features(tip, feature_language_, p.first->second);
              } else {
                  std::cout << "*******************************" << std::endl;
                  p.first->second.second.insert(std::make_pair(goal_feature_, std::set<int>()));
                  for( size_t k = 0; k < disjunctive_features_involving_goal_feature_.size(); ++k ) {
                      const Feature<T> &feature = *disjunctive_features_involving_goal_feature_[k];
                      p.first->second.second.insert(std::make_pair(&feature, std::set<int>()));
                  }
              }
          }

          FeatureSet<T> achieved_features;
          std::set<std::vector<int> > footprints;
          // CHECK: feature set used
          for( typename FeatureSet<T>::const_iterator it = feature_language_.begin(); it != feature_language_.end(); ++it ) {
              if( achieved_features.find(*it) != achieved_features.end() ) continue;
              const Feature<T> &feature = **it;
              bool is_feature_valid = true;
              for( typename t_map_t::const_iterator jt = tip_map.begin(); jt != tip_map.end(); ++jt ) {
                  if( jt->second.second.find(&feature) == jt->second.second.end() ) {
                      is_feature_valid = false;
                      break;
                  }
              }

              if( is_feature_valid ) {
                  // create a successor policy for this feature
                  std::vector<int> fp;
                  const AndOr::Policy<T> *new_policy = extend_policy_for_feature(policy, feature, tip_map, fp);
                  if( footprints.find(fp) == footprints.end() ) {
#ifdef DEBUG
                      std::cout << "new fp=[";
                      for( size_t k = 0; k < fp.size(); ++k ) {
                          int action_index = fp[k];
                          std::cout << action_index << ".";
                          if( action_index != -1 ) {
                              assert(action_index >= 0);
                              const Instance::Action &action = *lw1_instance_.actions_[action_index];
                              std::cout << action.name_;
                          } else {
                              std::cout << "NOOP";
                          }
                          if( 1 + k < fp.size() ) std::cout << " ";
                      }
                      std::cout << "]" << std::endl;
#endif
  
                      footprints.insert(fp);
                      FeatureList<T> *new_features = new FeatureList<T>;
                      compute_achieved_features(*new_policy, feature_language_, *new_features); // CHECK: feature set
                      //int new_policy_cost = cost(*new_policy); // CHECK
                      int new_policy_cost = 1 + policy_cost; // CHECK
                      Node<T> *new_node = new Node<T>(new_policy, new_features, new_policy_cost);
                      successors.push_back(new_node);

                      // register new achieved features
                      achieved_features.insert(new_features->begin(), new_features->end());

#ifdef DEBUG
                      std::cout << Utils::red()
                                << "SUCCESSOR: feature=" << feature
                                << ", #tips=" << new_policy->tip_nodes().size()
                                << ", #features=" << new_features->size()
                                << ", cost=" << new_policy_cost
                                << Utils::normal() << std::endl;
#endif
                  } else {
                      // CHECK: need to free new_policy
                  }
              }
          }
          std::cout << "#achieved-features=" << achieved_features.size() << std::endl;
          std::cout << "#successors=" << successors.size() << std::endl;
          assert(successors.size() <= available_features_.size());
      }

      void compute_extensions_for_features(const T &tip,
                                           const FeatureSet<T> &features,
                                           t_map_mapped_type_t &maps) const {
#ifdef DEBUG
          std::cout << Utils::magenta() << "API::compute_extensions_for_features():" << Utils::normal()
                                        << " tip=" << &tip
                                        << std::endl;
#endif
          assert(!goal_feature_->holds(tip));
          for( size_t k = 0; k < lw1_instance_.actions_.size(); ++k ) {
              if( (lw1_instance_.remap_action(k) == -1) && !lw1_instance_.is_subgoaling_rule(k) ) continue;
              const Instance::Action &action = *lw1_instance_.actions_[k];
              assert(lw1_instance_.is_regular_action(k));
              if( tip.applicable(action) ) {
                  std::cout << Utils::green() << "action=" << Utils::normal() << action.name_ << std::endl;

                  // calculate result of action
                  T *result_after_action = new T(tip);
                  result_after_action->apply(action);

#ifdef DEBUG
                  //std::cout << Utils::blue() << "RESULT(a=" << action.name_ << ")=" << Utils::normal();
                  //result_after_action->print(std::cout, &lw1_instance_);
                  //std::cout << std::endl;
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
                              //std::cout << Utils::blue() << "RESULT(a=" << action.name_
                              //          << ",o=obs[" << j << "])=" << Utils::normal();
                              //result_after_action_and_obs->print(std::cout, &lw1_instance_);
                              //std::cout << std::endl;
#endif
                          } else {
                              delete result_after_action_and_obs;
                          }
                      }
                  } else {
                      // there are no observable variables. Hence, there is single
                      // successor equal to belief_a
                      assert(lw1_instance_.vars_sensed_by_action_.find(action.name_->to_string()) == lw1_instance_.vars_sensed_by_action_.end());
                      valid_successors.push_back(new T(*result_after_action));
                  }
#ifdef DEBUG
                  //std::cout << Utils::green() << "#valid-successors=" << valid_successors.size() << Utils::normal() << std::endl;
#endif
                  assert(!valid_successors.empty());

                  // check features on valid successors
                  bool action_achieves_some_feature = false;
                  for( typename FeatureSet<T>::const_iterator it = features.begin(); it != features.end(); ++it ) {
                      const Feature<T> &feature = **it;
                      bool is_feature_valid = true;
                      for( size_t j = 0; j < valid_successors.size(); ++j ) {
                          const T &successor = *valid_successors[j];
                          if( !feature.holds(successor) ) {
                              is_feature_valid = false;
                              break;
                          } else {
#ifdef DEBUG
                              //std::cout << Utils::red() << "feature '" << feature << "' holds in succesor " << j << Utils::normal() << std::endl;
#endif
                          }
                      }
                      if( is_feature_valid ) {
                          action_achieves_some_feature = true;
                          maps.second.emplace(&feature, std::set<int>());
                          maps.second[&feature].insert(k);
#ifdef DEBUG
                          //std::cout << Utils::red()
                          //          << "feature '" << feature << "'"
                          //          << " holds after action " << action.name_
                          //          << Utils::normal() << std::endl;
#endif
                      }
                  }

                  if( action_achieves_some_feature ) {
                      // update and_node_map
                      AndOr::AndNode<T> *and_node = AndOr::create_and_node(&action, result_after_action, valid_successors);
                      maps.first.insert(std::make_pair(k, and_node));
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
          map<std::string, std::set<int> >::const_iterator it = lw1_instance_.vars_sensed_by_action_.find(action.name_->to_string());

#ifdef DEBUG
          //std::cout << Utils::magenta() << "Policy<T>::compute_possible_observations():" << Utils::normal()
          //          << " action=" << action.name_
          //          << ", #vars-sensed-by-action=" << (it == lw1_instance_.vars_sensed_by_action_.end() ? 0 : it->second.size())
          //          << std::endl;
#endif

          if( it != lw1_instance_.vars_sensed_by_action_.end() ) {
              assert(it->first == action.name_->to_string());

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
              if( actions_for_feature.empty() ) {
                  assert(goal_feature_->holds(*tip->belief()->belief()));
                  new_policy->add_tip(tip);
                  fp.push_back(-1);
              } else {
                  assert(!actions_for_feature.empty());
                  int action = *actions_for_feature.begin();
                  AndOr::AndNode<T> *and_node = maps.first.at(action);
                  assert(and_node != 0);
                  fp.push_back(action);

                  // link and-node to (old) policy and create tips for new policy
                  and_node->set_parent(tip);
                  for( size_t j = 0; j < and_node->children().size(); ++j )
                      new_policy->add_tip(and_node->children()[j]);
#if 0 // CHECK
                  for( size_t j = 0; j < and_node->children().size(); ++j ) {
                      const AndOr::OrNode<T> *new_tip = and_node->child(j);
                      std::cout << "NEW-TIP=";
                      new_tip->belief()->belief()->print(std::cout, &lw1_instance_);
                      std::cout << std::endl;
                  }
#endif
              }
          }
          return new_policy;
      }

  };

  template<typename T>
  inline int ActionSelection<T>::get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const { // CHECK: incomplete code
      std::cout << Utils::magenta() << "Width::ActionSelection<T>::get_plan()" << Utils::normal() << std::endl;

      //AndOr::BeliefRepo<T> belief_repo;
      //AndOr::Policy<T> policy(belief_repo);
      //policy.make_root(&state);
      //std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << policy.root() << std::endl;
      //std::cout << "BEL=" << *policy.root()->belief() << ", RC=" << policy.root()->ref_count() << std::endl;

      //AndOr::OrNode<T> *root = AndOr::make_root_node(&state);
      //std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << *root << std::endl;
      //AndOr::Node<T>::deallocate(root);

      FeatureSet<T> feature_language_set = std::set<const Feature<T>*, typename Feature<T>::ptr_compare_t>(feature_language_.begin(), feature_language_.end());
      API<T> api(lw1_instance_, inference_engine_, goal_feature_, feature_language_set, subsumed_features_, disjunctive_features_involving_goal_feature_, true); // CHECK: testing: turn off pruning
      AndOr::Search::bfs<T> bfs(lw1_instance_, api);
      bfs.search(state);

      std::cout << Utils::error() << "width-based action selection not yet implemented!" << std::endl;
      exit(-1);
  }

} // namespace Width

#undef DEBUG

#endif

