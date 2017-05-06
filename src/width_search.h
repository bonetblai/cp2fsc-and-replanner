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

#ifndef WIDTH_SEARCH_H
#define WIDTH_SEARCH_H

#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "action_selection.h"
#include "lw1_problem.h"
#include "inference_engine.h"
#include "utils.h"

#include "belief_features2.h"
#include "and_or_search_api2.h"
#include "and_or_search2.h"

#define DEBUG

namespace Width2 {

  template<typename T>
  class ActionSelection : public ::ActionSelection<T> {
      const LW1_Instance &lw1_instance_;
      const Inference::Engine<T> &inference_engine_;

      //int goal_feature_index_;
      //const Feature<T> *goal_feature_;

      std::vector<const Feature<T>*> feature_universe_;          // set of all features created
      std::vector<const Feature<T>*> feature_language_;          // created features that are considered
      std::map<int, const Feature<T>*> global_atomic_features_;  // features that are evaluated wrt given tree
      std::vector<const Feature<T>*> local_atomic_features_;     // features evaluated at (local) node
      std::vector<const Feature<T>*> global_max_domain_size_features_;  // global max-domain-sz features (global)
      std::vector<const Feature<T>*> local_max_domain_size_features_;  // local max-domain-sz features (global)
      std::vector<const LiteralFeature<T>*> literal_features_;   // literal features

      mutable float total_search_time_;
      mutable float total_time_;
      mutable size_t n_calls_;

    public:
      ActionSelection(const LW1_Instance &lw1_instance, const Inference::Engine<T> &inference_engine)
        : lw1_instance_(lw1_instance),
          inference_engine_(inference_engine) {
          //goal_feature_index_(-1),
          //goal_feature_(0) {

          // Initialize language of features.

          // First create global atomic feature values
          for( size_t var_index = 0; var_index < lw1_instance_.variables_.size(); ++var_index ) {
              const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
              if( variable.is_state_variable() ) {
                  int feature_index = feature_universe_.size();
                  Feature<T> *feature = new DomainSizeValue<T>(feature_index, lw1_instance_, var_index);
                  global_atomic_features_.emplace(var_index, feature);
                  feature_universe_.push_back(feature);
              }
          }

          // For each state variable X with domain { x1, ..., xn },
          // add features for Kxi and DSZ(X)
          for( size_t var_index = 0; var_index < lw1_instance_.variables_.size(); ++var_index ) {
              const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
              if( variable.is_state_variable() ) {
                  std::cout << "Features for variable: " << variable << std::endl;
                  // generate features for domain values
                  for( std::set<int>::const_iterator it = variable.domain().begin(); it != variable.domain().end(); ++it ) {
                      int atom = *it;
                      int feature_index = feature_universe_.size();
                      LiteralFeature<T> *feature = new LiteralFeature<T>(feature_index, lw1_instance_, var_index, 1 + 2*atom, true);
                      local_atomic_features_.push_back(feature);
                      literal_features_.push_back(feature);
                      feature_language_.push_back(feature);
                      feature_universe_.push_back(feature);
#ifdef DEBUG
                      std::cout << "using " << *feature << std::endl;
#endif

                      feature_index = feature_universe_.size();
                      feature = new LiteralFeature<T>(feature_index, lw1_instance_, var_index, 1 + 2*atom + 1, false);
                      local_atomic_features_.push_back(feature);
                      literal_features_.push_back(feature);
                      feature_language_.push_back(feature);
                      feature_universe_.push_back(feature);
#ifdef DEBUG
                      std::cout << "using " << *feature << std::endl;
#endif
                  }

                  // domain size
                  size_t dsize = variable.is_binary() ? 2 : variable.domain().size();

#if 0
                  // generate local feature for domain size
                  int feature_index = feature_universe_.size();
                  const Feature<T> *local_base = new DomainSizeValue<T>(feature_index, lw1_instance_, var_index);
                  feature_universe_.push_back(local_base);
                  for( size_t i = 0; i < dsize; ++i ) {
                      int feature_index = feature_universe_.size();
                      ValueTestFeature<T> *feature = new ValueTestEQ<T>(feature_index, *local_base, 1 + i);
                      local_max_domain_size_features_.push_back(feature);
                      local_atomic_features_.push_back(feature);
                      feature_universe_.push_back(feature);
                      feature_language_.push_back(feature);
#ifdef DEBUG
                      std::cout << "using " << *feature << std::endl;
#endif
                  }
#endif

                  // generate global feature for domain size
                  const Feature<T> *global_base = global_atomic_features_.at(var_index);
                  for( size_t i = 0; i < dsize; ++i ) {
                      int feature_index = feature_universe_.size();
                      ValueTestFeature<T> *feature = new ValueTestEQ<T>(feature_index, *global_base, 1 + i);
                      global_max_domain_size_features_.push_back(feature);
                      feature_universe_.push_back(feature);
                      feature_language_.push_back(feature);
#ifdef DEBUG
                      std::cout << "using " << *feature << std::endl;
#endif
                  }
              }
          }
          std::cout << Utils::green() << "#global-atomic-features=" << global_atomic_features_.size() << Utils::normal() << std::endl;
          std::cout << Utils::green() << "#local-atomic-features=" << local_atomic_features_.size() << Utils::normal() << std::endl;
          std::cout << Utils::green() << "#literal-features=" << literal_features_.size() << Utils::normal() << std::endl;
          std::cout << Utils::green() << "#global-max-domain-size-features=" << global_max_domain_size_features_.size() << Utils::normal() << std::endl;

          // create 2-term features of the form (<literal-feature> AND <domain-size-feature>)
          for( size_t k = 0; k < literal_features_.size(); ++k ) {
              const Feature<T> &f1 = *literal_features_[k];
              for( size_t j = 0; j < global_max_domain_size_features_.size(); ++j ) {
                  const Feature<T> &f2 = *global_max_domain_size_features_[j];
                  int feature_index = feature_universe_.size();
                  AndFeature<T> *feature = new AndFeature<T>(feature_index);
                  feature->add_conjunct(f1);
                  feature->add_conjunct(f2);
                  feature_universe_.push_back(feature);
                  feature_language_.push_back(feature);
#ifdef DEBUG
                  std::cout << "using " << *feature << std::endl;
#endif
              }
          }

          // CHECK: mix literals for known variables w/ literals for unknown-variables
          // create 2-term features of the form (<positive-literal-feature> AND <positive-literal-size-feature>)
          for( size_t k = 0; k < literal_features_.size(); ++k ) {
              const LiteralFeature<T> &f1 = *literal_features_[k];
              //if( !f1.positive() ) continue;
              for( size_t j = k + 1; j < literal_features_.size(); ++j ) {
                  const LiteralFeature<T> &f2 = *literal_features_[j];
                  //if( !f2.positive() ) continue;
                  if( f1.var_index() == f2.var_index() ) continue;
                  int feature_index = feature_universe_.size();
                  AndFeature<T> *feature = new AndFeature<T>(feature_index);
                  feature->add_conjunct(f1);
                  feature->add_conjunct(f2);
                  feature_universe_.push_back(feature);
                  feature_language_.push_back(feature);
#ifdef DEBUG
                  std::cout << "using " << *feature << std::endl;
#endif
              }
          }


#if 0
          // create goal feature
#if 0
          goal_feature_index_ = feature_universe_.size();
          AndFeature<T> *g_feature = new AndFeature<T>(goal_feature_index_);
          for( size_t k = 0; k < xxx.size(); ++k ) {
              assert(dynamic_cast<const DomainSizeFeature<T>*>(feature_universe_[xxx[k]]) != 0);
              const DomainSizeFeature<T> &f = static_cast<const DomainSizeFeature<T>&>(*feature_universe_[xxx[k]]);
              g_feature->add_conjunct(f);
          }
          goal_feature_ = g_feature;
#else
          goal_feature_index_ = feature_universe_.size();
          goal_feature_ = new GoalFeature<T>(goal_feature_index_, lw1_instance_);
#endif
          feature_universe_.push_back(goal_feature_);
          feature_language_.push_back(goal_feature_);

#ifdef DEBUG
          //std::cout << "using " << *goal_feature_ << std::endl;
#endif
          std::cout << Utils::green() << "#goal-features=1" << Utils::normal() << std::endl;
#endif

#if 0
          // create disjunctive features
#if 1 // CHECK: REMOVE
#  if 1
          for( size_t k = 0; k < term_features_.size(); ++k ) {
              const Feature<T> &f1 = *term_features_[k];
              int feature_index = feature_universe_.size();
              OrFeature<T> *feature = new OrFeature<T>(feature_index);
              feature->add_disjunct(*goal_feature_);
              feature->add_disjunct(f1);
              disjunctive_features_.push_back(feature);
              disjunctive_features_involving_goal_feature_.push_back(feature);
              feature_universe_.push_back(feature);
          }
#  endif
#  if 0
          for( size_t k = 0; k < domain_size_features_.size(); ++k ) {
              const Feature<T> &f1 = *domain_size_features_[k];
              for( size_t j = 0; j < literal_features_.size(); ++j ) {
                  const Feature<T> &f2 = *literal_features_[j];
                  int feature_index = feature_universe_.size();
                  OrFeature<T> *feature = new OrFeature<T>(feature_index);
                  feature->add_disjunct(f1);
                  feature->add_disjunct(f2);
                  disjunctive_features_.push_back(feature);
                  feature_universe_.push_back(feature);
              }
          }
#  endif

#else
          for( size_t k = 0; k < feature_language_.size(); ++k ) {
              const Feature<T> &f1 = *feature_language_[k];
              for( size_t j = 1 + k; j < feature_language_.size(); ++j ) {
                  const Feature<T> &f2 = *feature_language_[j];
                  if( f1.subsumes(f2) || f2.subsumes(f1) ) continue;
                  int feature_index = feature_universe_.size();
                  OrFeature<T> *feature = new OrFeature<T>(feature_index);
                  feature->add_disjunct(f1);
                  feature->add_disjunct(f2);
                  disjunctive_features_.push_back(feature);
                  if( goal_feature_ == &f2 )
                      disjunctive_features_involving_goal_feature_.push_back(feature);
                  feature_universe_.push_back(feature);
              }
          }
#endif
          for( size_t k = 0; k < disjunctive_features_.size(); ++k ) {
              feature_language_.push_back(disjunctive_features_[k]);
#ifdef DEBUG
              //std::cout << "using " << *feature_language_.back() << std::endl;
#endif
          }
          std::cout << Utils::green() << "#disjunctive-features=" << disjunctive_features_.size() << Utils::normal() << std::endl;
          std::cout << Utils::green() << "#features=" << feature_language_.size() << Utils::normal() << std::endl;
#endif

#if 0
          feature_language_noext_ = feature_language_;
#if 0
          std::map<const Feature<T>*, const BoxFeature<T>*> box_map;
          std::map<const Feature<T>*, const NotFeature<T>*> not_box_map;
          for( size_t k = 0; k < disjunctive_features_.size(); ++k ) {
              const OrFeature<T> &or_feature = *disjunctive_features_[k];
              assert(or_feature.size() == 2);
              const Feature<T> &f1 = or_feature.disjunct(0);
              const Feature<T> &f2 = or_feature.disjunct(1);

              int feature_index = feature_universe_.size();
              BoxFeature<T> *box_feature = new BoxFeature<T>(feature_index, or_feature);
              feature_universe_.push_back(box_feature);

              const BoxFeature<T> *box_f1 = 0;
              if( box_map.find(&f1) != box_map.end() ) {
                  box_f1 = box_map.at(&f1);
              } else {
                  int feature_index = feature_universe_.size();
                  box_f1 = new BoxFeature<T>(feature_index, f1);
                  feature_universe_.push_back(box_f1);
                  box_map.insert(std::make_pair(&f1, box_f1));
              }

              const NotFeature<T> *not_box_f1 = 0;
              if( not_box_map.find(box_f1) != not_box_map.end() ) {
                  not_box_f1 = not_box_map.at(box_f1);
              } else {
                  int feature_index = feature_universe_.size();
                  not_box_f1 = new NotFeature<T>(feature_index, *box_f1);
                  feature_universe_.push_back(not_box_f1);
                  not_box_map.insert(std::make_pair(box_f1, not_box_f1));
              }

              const BoxFeature<T> *box_f2 = 0;
              if( box_map.find(&f2) != box_map.end() ) {
                  box_f2 = box_map.at(&f2);
              } else {
                  int feature_index = feature_universe_.size();
                  box_f2 = new BoxFeature<T>(feature_index, f2);
                  feature_universe_.push_back(box_f2);
                  box_map.insert(std::make_pair(&f2, box_f2));
              }

              const NotFeature<T> *not_box_f2 = 0;
              if( not_box_map.find(box_f2) != not_box_map.end() ) {
                  not_box_f2 = not_box_map.at(box_f2);
              } else {
                  int feature_index = feature_universe_.size();
                  not_box_f2 = new NotFeature<T>(feature_index, *box_f2);
                  feature_universe_.push_back(not_box_f2);
                  not_box_map.insert(std::make_pair(box_f2, not_box_f2));
              }

              feature_index = feature_universe_.size();
              AndFeature<T> *and_feature = new AndFeature<T>(feature_index);
              and_feature->add_conjunct(*box_feature);
              and_feature->add_conjunct(*not_box_f1);
              and_feature->add_conjunct(*not_box_f2);
              feature_language_noext_.push_back(and_feature);
              feature_universe_.push_back(and_feature);
          }
          std::cout << Utils::green() << "#features-ext=" << feature_language_noext_.size() << Utils::normal() << std::endl;
#endif
#endif
          std::cout << Utils::green() << "#feature-universe=" << feature_universe_.size() << Utils::normal() << std::endl;
          std::cout << Utils::green() << "#feature-language=" << feature_language_.size() << Utils::normal() << std::endl;
      }
      virtual ~ActionSelection() {
          assert(0);
#if 0
          for( size_t k = feature_universe_.size(); k < feature_universe_.size(); ++k )
              delete feature_universe_[k];
#endif
      }

      virtual std::string name() const { return std::string("width-based-action-selection"); }
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
  class API : public AndOr3::Search::API<T> {
    using AndOr3::Search::API<T>::lw1_instance_;

    protected:
      const Inference::Engine<T> &inference_engine_;
      //const Feature<T> *goal_feature_;
      const std::vector<const Feature<T>*> &feature_universe_;
      const std::vector<const Feature<T>*> &feature_language_;
      const std::map<int, const Feature<T>*> &global_atomic_features_;
      const std::vector<const Feature<T>*> &local_atomic_features_;
      //const std::vector<const Feature<T>*> &feature_language_noext_;
      //const std::vector<const OrFeature<T>*> disjunctive_features_involving_goal_feature_;
      bool prune_nodes_;

      //mutable AndOr::BeliefRepo<T> belief_repo_;
      mutable unsigned *feature_bitmap_;
      mutable unsigned num_available_features_;
      size_t feature_bitmap_size_;

      typedef std::map<AndOr3::Node*, std::vector<int> > cache_t;
      mutable cache_t feature_value_cache_;

      mutable std::vector<std::set<const AndOr3::OrNode<T>*> > support_for_features_;

    public:
      API(const LW1_Instance &lw1_instance,
          const Inference::Engine<T> &inference_engine,
          //const Feature<T> *goal_feature,
          const std::vector<const Feature<T>*> &feature_universe,
          const std::vector<const Feature<T>*> &feature_language,
          const std::map<int, const Feature<T>*> &global_atomic_features,
          const std::vector<const Feature<T>*> &local_atomic_features,
          //const std::vector<const Feature<T>*> &feature_language_noext,
          //const std::vector<const OrFeature<T>*> disjunctive_features_involving_goal_feature,
          bool prune_nodes = true)
        : AndOr3::Search::API<T>(lw1_instance),
          inference_engine_(inference_engine),
          //goal_feature_(goal_feature),
          feature_universe_(feature_universe),
          feature_language_(feature_language),
          global_atomic_features_(global_atomic_features),
          local_atomic_features_(local_atomic_features),
          //feature_language_noext_(feature_language_noext),
          //disjunctive_features_involving_goal_feature_(disjunctive_features_involving_goal_feature),
          prune_nodes_(prune_nodes) {
          feature_bitmap_size_ = (feature_universe_.size() >> 5) + ((feature_universe_.size() % 32) == 0 ? 0 : 1);
          feature_bitmap_ = new unsigned[feature_bitmap_size_];

          // create support for features
          support_for_features_.resize(1 + feature_language_.back()->index());
      }
      virtual ~API() {
          delete[] feature_bitmap_;
      }

      // bitmap for features
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
      void re_establish_feature(int index, int offset) const {
          assert((index >= 0) && (index < feature_bitmap_size_));
          assert((offset >= 0) && (offset < 32));
          feature_bitmap_[index] = feature_bitmap_[index] | (1 << offset);
      }
      void re_establish_feature(const Feature<T> &feature) const {
          assert(feature.index() < feature_universe_.size());
          assert(!is_feature_available(feature));
          ++num_available_features_;
          int index = feature.index() >> 5, offset = feature.index() % 32;
          re_establish_feature(index, offset);
      }

      void bottom_up_pass(const AndOr3::OrNode<T> &node, const Feature<T> &feature, bool verbose = false) const {
          if( node.children().empty() ) {
              node.set_cached_value(feature.value(*node.belief()->rep(), 0, verbose));
          } else {
              int min_value = std::numeric_limits<int>::max();
              for( size_t k = 0; k < node.children().size(); ++k ) {
                  const AndOr3::AndNode<T> &child = *node.child(k);
                  bottom_up_pass(child, feature, verbose);
                  min_value = std::min(min_value, child.cached_value());
              }
              node.set_cached_value(min_value);
          }
          if( verbose ) std::cout << "bottom-up: value for " << feature << " at " << node << " --> " << node.cached_value() << std::endl;
      }
      void bottom_up_pass(const AndOr3::AndNode<T> &node, const Feature<T> &feature, bool verbose = false) const {
          assert(!node.children().empty());
          int max_value = std::numeric_limits<int>::min();
          for( size_t k = 0; k < node.children().size(); ++k ) {
              const AndOr3::OrNode<T> &child = *node.child(k);
              bottom_up_pass(child, feature, verbose);
              max_value = std::max(max_value, child.cached_value());
          }
          node.set_cached_value(max_value);
          if( verbose ) std::cout << "bottom-up: value for " << feature << " at " << node << " --> " << node.cached_value() << std::endl;
      }
      void top_down_pass(const AndOr3::OrNode<T> &node, const Feature<T> &feature, bool verbose = false) const {
          if( node.parent() != 0 ) {
              node.set_cached_value(node.parent()->cached_value());
          }
          for( size_t k = 0; k < node.children().size(); ++k ) {
              const AndOr3::AndNode<T> &child = *node.child(k);
              top_down_pass(child, feature, verbose);
          }
          if( verbose ) std::cout << "top-down: value for " << feature << " at " << node << " --> " << node.cached_value() << std::endl;
      }
      void top_down_pass(const AndOr3::AndNode<T> &node, const Feature<T> &feature, bool verbose = false) const {
          assert(node.parent() != 0);
          node.set_cached_value(std::max(node.cached_value(), node.parent()->cached_value()));
          for( size_t k = 0; k < node.children().size(); ++k ) {
              const AndOr3::OrNode<T> &child = *node.child(k);
              top_down_pass(child, feature, verbose);
          }
          if( verbose ) std::cout << "top-down: value for " << feature << " at " << node << " --> " << node.cached_value() << std::endl;
      }

      virtual void reset() const {
          reset_bitmap_for_features();
          feature_value_cache_.clear();
      }
      virtual AndOr3::OrNode<T>* make_root_node(const T *state) const {
          return new AndOr3::OrNode<T>(new AndOr3::Belief<T>(state), 0, is_goal(state));
      }
      virtual bool prune(const AndOr3::OrNode<T> &node, bool verbose = false) const {
          // check whether this node can be pruned using features
          bool prune_node = prune_nodes_;
          if( prune_node ) {
              cache_t::const_iterator it = feature_value_cache_.find(const_cast<AndOr3::OrNode<T>*>(&node));
              assert(it != feature_value_cache_.end());
              for( size_t k = 0; k < feature_language_.size(); ++k ) {
                  const Feature<T> &feature = *feature_language_[k];
                  if( is_feature_available(feature) && feature.holds(*node.belief()->rep(), &it->second) ) {
                      prune_node = false;
                      break;
                  }
              }
              if( prune_node && verbose ) std::cout << Utils::magenta() << "prune: node=" << node << Utils::normal() << std::endl;
          }
          return prune_node;
      }
      virtual bool is_goal(const T *n) const {
          return (n != 0) && n->is_goal(lw1_instance_);
      }
      virtual void expand(const AndOr3::OrNode<T> &n, std::vector<AndOr3::AndNode<T>*> &successors) const {
          const AndOr3::Belief<T> &belief = *n.belief();
          const T &tip = *belief.rep();

#ifdef DEBUG
          std::cout << Utils::magenta() << "API::expand():" << Utils::normal() << std::flush
                    << " ptr=" << &n
                    << " node=" << n
                    << std::endl;
#endif

          // for each action, compute available features reached with action
          successors.clear();
          for( size_t action_index = 0; action_index < lw1_instance_.actions_.size(); ++action_index ) {
              if( (lw1_instance_.remap_action(action_index) == -1) && !lw1_instance_.is_subgoaling_rule(action_index) ) continue;
              const Instance::Action &action = *lw1_instance_.actions_[action_index];
              assert(lw1_instance_.is_regular_action(action_index));
              if( tip.applicable(action) ) {
                  //std::cout << Utils::green() << "action=" << Utils::normal() << action.name() << std::endl;

                  // calculate result of action
                  T *result_after_action = new T(tip);
                  result_after_action->apply(action);

#ifdef DEBUG
                  std::cout << Utils::blue() << "RESULT(a=" << action.name() << ")=" << Utils::normal();
                  //result_after_action->print(std::cout, &lw1_instance_);
                  std::cout << std::endl;
#endif

                  // generate successor beliefs considering possible observations.
                  std::vector<std::set<int> > possible_observations;
                  compute_possible_observations(*result_after_action, action, possible_observations);
#ifdef DEBUG
                  //std::cout << Utils::green() << "#possible-obs=" << possible_observations.size() << Utils::normal() << std::endl;
#endif

                  // generate valid successors after (action,obs). A valid successor
                  // is a belief in which inference after obs doesn't detect inconsistency
                  std::vector<std::pair<int, const T*> > valid_successors;
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
                          bool status = inference_engine_.apply_inference(&action, obs, *result_after_action_and_obs);
                          if( status ) {
                              valid_successors.push_back(std::make_pair(j, result_after_action_and_obs));
#ifdef DEBUG
                              std::cout << Utils::blue() << "RESULT(a=" << action.name()
                                        << ",o=obs[" << j << "])=" << Utils::normal();
                              //result_after_action_and_obs->print(std::cout, &lw1_instance_);
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
                      valid_successors.push_back(std::make_pair(-1, new T(*result_after_action)));
                  }
#ifdef DEBUG
                  //std::cout << Utils::green() << "#valid-successors-after-action=" << valid_successors.size() << Utils::normal() << std::endl;
#endif
                  assert(!valid_successors.empty());

                  // generate successors for this action
                  AndOr3::AndNode<T> *action_node = new AndOr3::AndNode<T>(action_index, new AndOr3::Belief<T>(result_after_action), &n);
                  action_node->reserve(valid_successors.size());
                  for( size_t j = 0; j < valid_successors.size(); ++j ) {
                      const std::pair<int, const T*> p = valid_successors[j];
                      action_node->add_child(new AndOr3::OrNode<T>(new AndOr3::Belief<T>(p.second), action_node, is_goal(p.second)));
                  }
                  successors.push_back(action_node);
              }
          }
#ifdef DEBUG
          //std::cout << Utils::green() << "#successors=" << successors.size() << Utils::normal() << std::endl;
#endif
      }
      virtual void compute_features(const AndOr3::OrNode<T> &root, const std::vector<AndOr3::OrNode<T>*> &fringe, bool verbose = false) const {
          //assert(verify_supports());

          // skip nodes that have an entry on the cache as this nodes re-entered the queue
          // A node re-enters the queue when it was previously marked as dead-by-feature but
          // then cleared when a new solution (tip) node was generated
          std::vector<bool> skip_list(fringe.size(), false);
          for( size_t k = 0; k < fringe.size(); ++k ) {
              if( feature_value_cache_.find(fringe[k]) != feature_value_cache_.end() )
                  skip_list[k] = true;
          }

          // global atomic features
          for( typename std::map<int, const Feature<T>*>::const_iterator it = global_atomic_features_.begin(); it != global_atomic_features_.end(); ++it ) {
              const Feature<T> &feature = *it->second;

              // compute values at all nodes in tree
              bottom_up_pass(root, feature, verbose);
              top_down_pass(root, feature, verbose);

              // save feature value for fringe nodes
              for( size_t k = 0; k < fringe.size(); ++k ) {
                  if( !skip_list[k] ) {
                      AndOr3::OrNode<T> *node = fringe[k];
                      cache_t::iterator jt = feature_value_cache_.find(node);
                      if( jt == feature_value_cache_.end() ) {
                          feature_value_cache_.emplace(std::piecewise_construct,
                                                       std::forward_as_tuple(node),
                                                       std::forward_as_tuple(global_atomic_features_.size(), 0));
                          jt = feature_value_cache_.find(node);
                      }
                      assert(feature.index() < jt->second.size());
                      jt->second[feature.index()] = node->cached_value();
                  }
              }
          }

#ifdef DEBUG
          for( size_t k = 0; k < fringe.size(); ++k ) {
              AndOr3::OrNode<T> *node = fringe[k];
              cache_t::iterator jt = feature_value_cache_.find(node);
              assert(jt != feature_value_cache_.end());
              const std::vector<int> &cache = jt->second;
              std::cout << "global features for node=" << *node << std::endl;
              for( typename std::map<int, const Feature<T>*>::const_iterator it = global_atomic_features_.begin(); it != global_atomic_features_.end(); ++it ) {
                  const Feature<T> &feature = *it->second;
                  std::cout << "    value(" << feature << ")=" << feature.value(*node->belief()->rep(), &cache) << std::endl;
              }
          }
#endif
      }
      virtual void register_features(const AndOr3::OrNode<T> &node, bool verbose = false) const {
          //assert(verify_supports());
          cache_t::const_iterator it = feature_value_cache_.find(const_cast<AndOr3::OrNode<T>*>(&node));
          assert(it != feature_value_cache_.end());
          for( size_t k = 0; k < feature_language_.size(); ++k ) {
              const Feature<T> &feature = *feature_language_[k];
              if( feature.holds(*node.belief()->rep(), &it->second, false) ) {
                  // update support and mark feature as seen
                  assert((feature.index() >= 0) && (feature.index() < support_for_features_.size()));
                  support_for_features_[feature.index()].insert(&node);
                  if( is_feature_available(feature) ) {
                      register_feature(feature);
#ifdef DEBUG
                      std::cout << "feature achieved --> " << feature << std::endl;
#endif
                  }
              }
          }
          //assert(verify_supports());
      }
      virtual void kill_by_label(const AndOr3::OrNode<T> &node) const {
          //assert(verify_supports());
          if( !node.children().empty() ) { // CHECK: test if node was expanded (wouldn't work if node is dead-end, though)
              cache_t::const_iterator it = feature_value_cache_.find(const_cast<AndOr3::OrNode<T>*>(&node));
              assert(it != feature_value_cache_.end());
              if( it != feature_value_cache_.end() ) {
                  for( size_t k = 0; k < feature_language_.size(); ++k ) {
                      const Feature<T> &feature = *feature_language_[k];
                      if( feature.holds(*node.belief()->rep(), &it->second, false) ) {
                          assert((feature.index() >= 0) && (feature.index() < support_for_features_.size()));
                          assert(support_for_features_[feature.index()].find(&node) != support_for_features_[feature.index()].end());
                          support_for_features_[feature.index()].erase(&node);
                          if( support_for_features_[feature.index()].empty() ) {
                              re_establish_feature(feature);
#ifdef DEBUG
                              std::cout << "feature re-established --> " << feature << std::endl;
#endif
                          }
                      }
                  }
              }
          }
          node.kill_by_label();
          //assert(verify_supports());
      }
      virtual void kill_by_label(const AndOr3::AndNode<T> &node) const {
          node.kill_by_label();
      }

      bool verify_supports() const {
          bool bug = false;
          for( size_t k = 0; k < feature_language_.size(); ++k ) {
              const Feature<T> &feature = *feature_language_[k];
              if( is_feature_available(feature) && !support_for_features_[feature.index()].empty() ) {
                  std::cout << "available feature " << feature << " has non-empty support" << std::endl;
                  bug = true;
              }
              if( !is_feature_available(feature) && support_for_features_[feature.index()].empty() ) {
                  std::cout << "non-available feature " << feature << " has empty support" << std::endl;
                  bug = true;
              }
          }
          assert(!bug);
      }

      void compute_possible_observations(const T &tip,
                                         const Instance::Action &action,
                                         std::vector<std::set<int> > &possible_observations) const {
          std::map<std::string, std::set<int> >::const_iterator it = lw1_instance_.vars_sensed_by_action_.find(action.name());

#ifdef DEBUG
          //std::cout << Utils::magenta() << "API<T>::compute_possible_observations():" << Utils::normal()
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
                          if( !tip.satisfy(2*atom + 1) )
                              observable_literals[var_index].push_back(1 + atom);
                          if( !tip.satisfy(2*atom) )
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
                      for( std::set<int>::const_iterator kt = variable.domain().begin(); kt != variable.domain().end(); ++kt ) {
                          int atom = *kt;
                          if( variable.is_state_variable() ) {
                              if( !tip.satisfy(2*atom + 1) )
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
          //std::cout << Utils::magenta() << "API<T>::generate_combinations_recursively()" << Utils::normal() << std::endl;
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
              // we don't perform any check on consistency of partial combination.
              // Such a check is performed later at full combination using the
              // inference engine.
#ifdef DEBUG
              //std::cout << "possible-observation:";
#endif
              std::set<int> observation;
              for( size_t i = 0; i < combination.size(); ++i ) {
                  observation.insert(combination[i].second);
#ifdef DEBUG
                   //std::cout << " [var=" << lw1_instance_.variables_[combination[i].first]->name()
                   //          << ",value=";
                   //State::print_literal(std::cout, combination[i].second, &lw1_instance_.po_instance_);
                   //std::cout << "]";
#endif
              }
              possible_observations.push_back(observation);
#ifdef DEBUG
               //std::cout << std::endl;
#endif
          }
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

      // CHECK: testing: turn off pruning

      API<T> api(lw1_instance_, inference_engine_, feature_universe_, feature_language_, global_atomic_features_, local_atomic_features_, true);
      AndOr3::Search::bfs<T> bfs(lw1_instance_, api);
      const AndOr3::OrNode<T> *root = bfs.search(state);
      std::cout << Utils::green() << "STATUS=" << api.has_solution(*root) << Utils::normal() << std::endl;
      if( api.has_solution(*root) )
          root->pretty_print(std::cout, true, lw1_instance_, Utils::cyan());
      else
          root->pretty_print(std::cout, false, lw1_instance_, Utils::cyan());
      std::cout << Utils::green() << "STATUS=" << api.has_solution(*root) << Utils::normal() << std::endl;

      std::cout << Utils::error() << "width-based action selection not yet implemented!" << std::endl;
      exit(-1);
  }

} // namespace Width2

#undef DEBUG

#endif

