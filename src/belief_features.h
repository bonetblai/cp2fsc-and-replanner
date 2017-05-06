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

#ifndef BELIEF_FEATURES_H
#define BELIEF_FEATURES_H

#include <cassert>
#include <iostream>
#include <list>
#include <set>
#include <string>

#include "lw1_problem.h"
#include "and_or2.h"

namespace Width {

  template<typename T>
  class Feature {
    protected:
      int index_;

      // (default) semantic definition
      virtual bool default_holds(const AndOr::Policy<T> &policy, bool verbose = false) const {
          for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tip_nodes().begin(); it != policy.tip_nodes().end(); ++it ) {
              if( !holds(policy, *(*it)->belief()->belief(), verbose) )
                  return false;
          }
          return true;
      }

    public:
      Feature(int index) : index_(index) { }
      virtual ~Feature() { }
      virtual bool holds(const T &state, bool verbose = false) const = 0;
      virtual bool holds(const std::vector<bool> &state_bitmap, bool verbose = false) const = 0;
      virtual bool holds(const AndOr::Policy<T> &policy, const T &tip, bool verbose = false) const = 0;
      virtual bool holds(const AndOr::Policy<T> &policy, bool verbose = false) const = 0;
      virtual bool subsumes(const Feature<T> &feature) const = 0;
      virtual std::string to_string() const = 0;
      int index() const {
          return index_;
      }
      void print(std::ostream &os) const {
          os << to_string() << std::flush;
      }

      // comparison for feature pointers
      struct ptr_compare_t {
          bool operator()(const Feature<T> *f1, const Feature<T> *f2) const {
              return f1->index_ < f2->index_;
          }
      };
  };

  template<typename T>
  class FeatureSet : public std::set<const Feature<T>*, typename Feature<T>::ptr_compare_t> {
    protected:
      typedef typename std::set<const Feature<T>*, typename Feature<T>::ptr_compare_t> base_class_t;

    public:
      FeatureSet() { }
      FeatureSet(const std::set<const Feature<T>*, typename Feature<T>::ptr_compare_t> &features)
        : std::set<const Feature<T>*, typename Feature<T>::ptr_compare_t>(features) {
      }
      ~FeatureSet() { }
      void print(std::ostream &os) const {
          for( typename base_class_t::const_iterator it = base_class_t::begin(); it != base_class_t::end(); ++it )
              os << **it << std::endl;
      }
  };

  template<typename T>
  class BoxFeature : public Feature<T> {
    protected:
      const Feature<T> &feature_;

    public:
      BoxFeature(int index, const Feature<T> &feature)
        : Feature<T>(index), feature_(feature) {
      }
      virtual ~BoxFeature() { }

      const Feature<T>& feature() const {
          return feature_;
      }

      virtual bool holds(const T &state, bool verbose = false) const {
          std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
          assert(0);
      }
      virtual bool holds(const AndOr::Policy<T> &policy, const T &tip, bool verbose = false) const {
          for( typename AndOr::OrNodeList<T>::const_iterator it = policy.tip_nodes().begin(); it != policy.tip_nodes().end(); ++it ) {
              if( !feature_.holds(policy, *(*it)->belief()->belief(), verbose) )
                  return false;
          }
          return true;
      }
      virtual bool holds(const AndOr::Policy<T> &policy, bool verbose = false) const {
          return policy.tip_nodes().empty() ? true : holds(policy, *(*policy.tip_nodes().begin())->belief()->belief(), verbose);
      }
      virtual bool subsumes(const Feature<T> &feature) const {
          return false;
      }
      virtual std::string to_string() const {
          std::string str("Feature[index=");
          str += std::to_string(this->index());
          str += ",type=box,feature=";
          str += feature_.to_string();
          return str + "]";
      }
  };

  template<typename T>
  class NotFeature : public Feature<T> {
    protected:
      const Feature<T> &feature_;

    public:
      NotFeature(int index, const Feature<T> &feature)
        : Feature<T>(index), feature_(feature) {
      }
      virtual ~NotFeature() { }

      const Feature<T>& feature() const {
          return feature_;
      }

      virtual bool holds(const T &state, bool verbose = false) const {
          return !feature_.holds(state, verbose);
      }
      virtual bool holds(const std::vector<bool> &state_bitmap, bool verbose = false) const {
          return !feature_.holds(state_bitmap, verbose);
      }
      virtual bool holds(const AndOr::Policy<T> &policy, const T &tip, bool verbose = false) const {
          return !feature_.holds(policy, tip, verbose);
      }
      virtual bool holds(const AndOr::Policy<T> &policy, bool verbose = false) const {
          return policy.tip_nodes().empty() ? true : !feature_.holds(policy, verbose);
      }
      virtual bool subsumes(const Feature<T> &feature) const {
          return false;
      }
      virtual std::string to_string() const {
          std::string str("Feature[index=");
          str += std::to_string(this->index());
          str += ",type=not,feature=";
          str += feature_.to_string();
          return str + "]";
      }
  };

  template<typename T>
  class OrFeature : public Feature<T> {
    protected:
      std::vector<const Feature<T>*> disjuncts_;

    public:
      OrFeature(int index) : Feature<T>(index) { }
      virtual ~OrFeature() { }

      size_t size() const {
          return disjuncts_.size();
      }
      const Feature<T>& disjunct(int i) const {
          assert((i >= 0) && (i < disjuncts_.size()));
          return *disjuncts_[i];
      }
      const std::vector<const Feature<T>*>& disjuncts() const {
          return disjuncts_;
      }
      void add_disjunct(const Feature<T> &feature) {
          disjuncts_.push_back(&feature);
      }

      virtual bool holds(const T &state, bool verbose = false) const {
          for( size_t k = 0; k < disjuncts_.size(); ++k ) {
              if( disjuncts_[k]->holds(state, verbose) )
                  return true;
          }
          return false;
      }
      virtual bool holds(const std::vector<bool> &state_bitmap, bool verbose = false) const {
          for( size_t k = 0; k < disjuncts_.size(); ++k ) {
              if( disjuncts_[k]->holds(state_bitmap, verbose) )
                  return true;
          }
          return false;
      }
      virtual bool holds(const AndOr::Policy<T> &policy, const T &tip, bool verbose = false) const {
          for( size_t k = 0; k < disjuncts_.size(); ++k ) {
              if( disjuncts_[k]->holds(policy, tip, verbose) )
                  return true;
          }
          return false;
      }
      virtual bool holds(const AndOr::Policy<T> &policy, bool verbose = false) const {
          return Feature<T>::default_holds(policy, verbose);
      }
      virtual bool subsumes(const Feature<T> &feature) const {
          assert(disjuncts_.size() > 1);
          if( dynamic_cast<const OrFeature<T>*>(&feature) != 0 ) {
              const OrFeature<T> &or_feature = static_cast<const OrFeature<T>&>(feature);
              if( disjuncts_.size() <= or_feature.disjuncts_.size() ) {
                  std::set<const Feature<T>*> fset(or_feature.disjuncts_.begin(), or_feature.disjuncts_.end());
                  for( size_t k = 0; k < disjuncts_.size(); ++k ) {
                      if( fset.find(disjuncts_[k]) == fset.end() )
                          return false;
                  }
                  return true;
              }
          }
          return false;
      }
      virtual std::string to_string() const {
          std::string str("Feature[index=");
          str += std::to_string(this->index());
          str += ",type=or,disjuncts={";
          for( size_t k = 0; k < disjuncts_.size(); ++k ) {
              str += disjuncts_[k]->to_string();
              if( k + 1 < disjuncts_.size() )
                  str += ",";
          }
          return str + "}]";
      }
  };

  template<typename T>
  class AndFeature : public Feature<T> {
    protected:
      std::vector<const Feature<T>*> conjuncts_;

    public:
      AndFeature(int index) : Feature<T>(index) { }
      virtual ~AndFeature() { }

      size_t size() const {
          return conjuncts_.size();
      }
      const Feature<T>& conjunct(int i) const {
          assert((i >= 0) && (i < conjuncts_.size()));
          return *conjuncts_[i];
      }
      const std::vector<const Feature<T>*>& conjuncts() const {
          return conjuncts_;
      }
      void add_conjunct(const Feature<T> &feature) {
          conjuncts_.push_back(&feature);
      }

      virtual bool holds(const T &state, bool verbose = false) const {
          for( size_t k = 0; k < conjuncts_.size(); ++k ) {
              if( !conjuncts_[k]->holds(state, verbose) )
                  return false;
          }
          return true;
      }
      virtual bool holds(const std::vector<bool> &state_bitmap, bool verbose = false) const {
          for( size_t k = 0; k < conjuncts_.size(); ++k ) {
              if( !conjuncts_[k]->holds(state_bitmap, verbose) )
                  return false;
          }
          return true;
      }
      virtual bool holds(const AndOr::Policy<T> &policy, const T &tip, bool verbose = false) const {
          for( size_t k = 0; k < conjuncts_.size(); ++k ) {
              if( !conjuncts_[k]->holds(policy, tip, verbose) )
                  return false;
          }
          return true;
      }
      virtual bool holds(const AndOr::Policy<T> &policy, bool verbose = false) const {
          for( size_t k = 0; k < conjuncts_.size(); ++k ) {
              if( !conjuncts_[k]->holds(policy, verbose) )
                  return false;
          }
          return true;
      }
      virtual bool subsumes(const Feature<T> &feature) const {
          std::set<const Feature<T>*> fset(conjuncts_.begin(), conjuncts_.end());
          if( dynamic_cast<const AndFeature<T>*>(&feature) != 0 ) {
              const AndFeature<T> &and_feature = static_cast<const AndFeature<T>&>(feature);
              if( conjuncts_.size() >= and_feature.conjuncts_.size() ) {
                  for( size_t k = 0; k < and_feature.conjuncts_.size(); ++k ) {
                      if( fset.find(and_feature.conjuncts_[k]) == fset.end() )
                          return false;
                  }
                  return true;
              }
              return false;
          } else {
              return fset.find(&feature) != fset.end();
          }
      }
      virtual std::string to_string() const {
          std::string str("Feature[index=");
          str += std::to_string(this->index());
          str += ",type=and,conjuncts={";
          for( size_t k = 0; k < conjuncts_.size(); ++k ) {
              str += conjuncts_[k]->to_string();
              if( k + 1 < conjuncts_.size() )
                  str += ",";
          }
          return str + "}]";
      }
  };

  template<typename T>
  class DomainSizeFeature : public Feature<T> {
    protected:
      const LW1_Instance &lw1_instance_;
      const int test_type_;
      const int var_index_;
      const int size_;

      DomainSizeFeature(int index, const LW1_Instance &lw1_instance, int test_type, int var_index, int size)
        : Feature<T>(index),
          lw1_instance_(lw1_instance),
          test_type_(test_type),
          var_index_(var_index),
          size_(size) {
      }

    public:
      virtual ~DomainSizeFeature() { }

      const LW1_Instance& lw1_instance() const {
          return lw1_instance_;
      }
      int var_index() const {
          return var_index_;
      }
      int size() const {
          return size_;
      }

      int num_possible_values(const T &state, bool verbose = false) const {
          const LW1_Instance::Variable &var = *lw1_instance_.variables_[var_index_];
          int num_values = var.is_binary() ? 2 : var.domain().size();
          if( var.is_binary() ) {
              int atom_index = *var.domain().begin();
              if( state.satisfy(2*atom_index, false) )
                  --num_values;
              if( state.satisfy(2*atom_index + 1, false) )
                  --num_values;
          } else {
              for( std::set<int>::const_iterator it = var.domain().begin(); it != var.domain().end(); ++it ) {
                  int literal = 1 + 2*(*it) + 1;
                  if( state.satisfy(literal - 1, false) )
                      --num_values;
#ifdef DEBUG
                  std::cout << "checking "; State::print_literal(std::cout, literal, &lw1_instance_);
                  std::cout << " --> " << state.satisfy(literal - 1, false) << std::endl;
#endif
              }
#ifdef DEBUG
              std::cout << "value for " << var << " = " << num_values << std::endl;
#endif
          }
          return num_values;
      }
      int num_possible_values(const std::vector<bool> &state_bitmap, bool verbose = false) const {
          const LW1_Instance::Variable &var = *lw1_instance_.variables_[var_index_];
          int num_values = var.is_binary() ? 2 : var.domain().size();
          if( var.is_binary() ) {
              int atom_index = *var.domain().begin();
              assert((2 * atom_index >= 0) && (2 * atom_index < state_bitmap.size()));
              if( state_bitmap[2 * atom_index] )
                  --num_values;
              assert((2 * atom_index + 1 >= 0) && (2 * atom_index + 1 < state_bitmap.size()));
              if( state_bitmap[2 * atom_index + 1] )
                  --num_values;
          } else {
              for( std::set<int>::const_iterator it = var.domain().begin(); it != var.domain().end(); ++it ) {
                  int k_literal = 1 + 2 * (*it) + 1;
                  assert((k_literal - 1 >= 0) && (k_literal - 1 < state_bitmap.size()));
                  if( state_bitmap[k_literal - 1] )
                      --num_values;
#ifdef DEBUG
                  std::cout << "checking "; State::print_literal(std::cout, k_literal, &lw1_instance_);
                  std::cout << " --> " << state_bitmap[k_literal - 1] << std::endl;
#endif
              }
#ifdef DEBUG
              std::cout << "value for " << var << " = " << num_values << std::endl;
#endif
          }
          return num_values;
      }

      virtual bool holds(const T &state, bool verbose = false) const {
          int num_values = num_possible_values(state, verbose);
          if( test_type_ == 0 ) { // equality
              return num_values == size_;
          } else if( test_type_ == 1 ) { // less than or equal
              return num_values <= size_;
          } else if( test_type_ == 2 ) { // greater than or equal
              return num_values >= size_;
          } else {
              std::cout << Utils::internal_error() << "unexpected test type in DomainSizeLiteral" << std::endl;
              exit(255);
          }
      }
      virtual bool holds(const std::vector<bool> &state_bitmap, bool verbose = false) const {
          int num_values = num_possible_values(state_bitmap, verbose);
          if( test_type_ == 0 ) { // equality
              return num_values == size_;
          } else if( test_type_ == 1 ) { // less than or equal
              return num_values <= size_;
          } else if( test_type_ == 2 ) { // greater than or equal
              return num_values >= size_;
          } else {
              std::cout << Utils::internal_error() << "unexpected test type in DomainSizeLiteral" << std::endl;
              exit(255);
          }
      }
      virtual bool holds(const AndOr::Policy<T> &policy, const T &tip, bool verbose = false) const {
          // feature can't decompose into simpler features
          return holds(tip, verbose);
      }
      virtual bool holds(const AndOr::Policy<T> &policy, bool verbose = false) const {
          return Feature<T>::default_holds(policy, verbose);
      }
      virtual bool subsumes(const Feature<T> &feature) const {
          if( dynamic_cast<const OrFeature<T>*>(&feature) != 0 ) {
              const OrFeature<T> &or_feature = static_cast<const OrFeature<T>&>(feature);
              assert(or_feature.disjuncts().size() > 1);
              for( size_t k = 0; k < or_feature.disjuncts().size(); ++k ) {
                  if( this == or_feature.disjuncts()[k] )
                      return true;
              }
              return false;
          }
          return false;
      }
      virtual std::string to_string() const {
          std::string str("Feature[index=");
          str += std::to_string(this->index());
          str += ",type=dsz,var=" + lw1_instance_.variables_[var_index_]->name();
          str += ",size=" + std::to_string(size_);
          str += ",test=" + std::to_string(test_type_);
          return str + "]";
      }
  };

  template<typename T>
  class DomainSizeFeatureEQ : public DomainSizeFeature<T> {
    public:
      DomainSizeFeatureEQ(int index, const LW1_Instance &lw1_instance, int var_index, int size)
        : DomainSizeFeature<T>(index, lw1_instance, 0, var_index, size) {
      }
      virtual ~DomainSizeFeatureEQ() { }
  };

  template<typename T>
  class DomainSizeFeatureLE : public DomainSizeFeature<T> {
    public:
      DomainSizeFeatureLE(int index, const LW1_Instance &lw1_instance, int var_index, int size)
        : DomainSizeFeature<T>(index, lw1_instance, 1, var_index, size) {
      }
      virtual ~DomainSizeFeatureLE() { }
  };

  template<typename T>
  class DomainSizeFeatureGE : public DomainSizeFeature<T> {
    public:
      DomainSizeFeatureGE(int index, const LW1_Instance &lw1_instance, int var_index, int size)
        : DomainSizeFeature<T>(index, lw1_instance, 2, var_index, size) {
      }
      virtual ~DomainSizeFeatureGE() { }
  };

  template<typename T>
  class LiteralFeature : public Feature<T> {
    protected:
      const LW1_Instance &lw1_instance_;
      const int var_index_;
      const int k_literal_;

    public:
      LiteralFeature(int index, const LW1_Instance &lw1_instance, int var_index, int k_literal)
        : Feature<T>(index),
          lw1_instance_(lw1_instance),
          var_index_(var_index),
          k_literal_(k_literal) {
          assert(k_literal_ > 0);
      }
      virtual ~LiteralFeature() { }

      const LW1_Instance& lw1_instance() const {
          return lw1_instance_;
      }
      int var_index() const {
          return var_index_;
      }
      int k_literal() const {
          return k_literal_;
      }

      virtual bool holds(const T &state, bool verbose = false) const {
          if( verbose )
              std::cout << *this << " --> " << state.satisfy(k_literal_ - 1) << std::endl;
          return state.satisfy(k_literal_ - 1);
      }
      virtual bool holds(const std::vector<bool> &state_bitmap, bool verbose = false) const {
          if( verbose )
              std::cout << *this << " --> " << state_bitmap[k_literal_ - 1] << std::endl;
          return state_bitmap[k_literal_ - 1];
      }
      virtual bool holds(const AndOr::Policy<T> &policy, const T &tip, bool verbose = false) const {
          // feature can't decompose into simpler features
          return holds(tip, verbose);
      }
      virtual bool holds(const AndOr::Policy<T> &policy, bool verbose = false) const {
          return Feature<T>::default_holds(policy, verbose);
      }
      virtual bool subsumes(const Feature<T> &feature) const {
          if( dynamic_cast<const OrFeature<T>*>(&feature) != 0 ) {
              const OrFeature<T> &or_feature = static_cast<const OrFeature<T>&>(feature);
              assert(or_feature.disjuncts().size() > 1);
              for( size_t k = 0; k < or_feature.disjuncts().size(); ++k ) {
                  if( this == or_feature.disjuncts()[k] )
                      return true;
              }
              return false;
          } else if( dynamic_cast<const DomainSizeFeature<T>*>(&feature) != 0 ) {
              const DomainSizeFeature<T> &dsz_feature = static_cast<const DomainSizeFeature<T>&>(feature);
              return (k_literal_ > 0) && (var_index_ == dsz_feature.var_index()) && (dsz_feature.size() == 1);
          }
          return this == &feature;
      }
      virtual std::string to_string() const {
          std::string str("Feature[index=");
          str += std::to_string(this->index());
          str += ",type=literal,name=";
          str += State::to_string(k_literal_, &lw1_instance_);
          return str + "]";
      }
  };

  template<typename T>
  class GoalFeature : public Feature<T> {
    protected:
      const LW1_Instance &lw1_instance_;
      std::vector<int> goal_k_literals_;

    public:
      GoalFeature(int index, const LW1_Instance &lw1_instance)
        : Feature<T>(index), lw1_instance_(lw1_instance) {
          for( index_set::const_iterator it = lw1_instance_.po_instance_.goal_literals_.begin(); it != lw1_instance_.po_instance_.goal_literals_.end(); ++it ) {
              int atom = *it > 0 ? *it - 1 : -*it - 1;
              int k_literal = *it > 0 ? 1 + 2*atom : 1 + 2*atom + 1;
              goal_k_literals_.push_back(k_literal);
          }
      }
      virtual ~GoalFeature() { }

      const LW1_Instance& lw1_instance() const {
          return lw1_instance_;
      }
      const std::vector<int>& goal_k_literals() const {
          return goal_k_literals_;
      }

      virtual bool holds(const T &state, bool verbose = false) const {
          for( size_t k = 0; k < goal_k_literals_.size(); ++k ) {
              int k_literal = goal_k_literals_[k];
              if( !state.satisfy(k_literal - 1) )
                  return false;
          }
          return true;
      }
      virtual bool holds(const std::vector<bool> &state_bitmap, bool verbose = false) const {
          for( size_t k = 0; k < goal_k_literals_.size(); ++k ) {
              int k_literal = goal_k_literals_[k];
              assert(k_literal > 0);
              if( !state_bitmap[k_literal - 1] )
                  return false;
          }
          return true;
      }
      virtual bool holds(const AndOr::Policy<T> &policy, const T &tip, bool verbose = false) const {
          // feature can't decompose into simpler features
          return holds(tip, verbose);
      }
      virtual bool holds(const AndOr::Policy<T> &policy, bool verbose = false) const {
          return Feature<T>::default_holds(policy, verbose);
      }
      virtual bool subsumes(const Feature<T> &feature) const {
          return false;
      }
      virtual std::string to_string() const {
          std::string str("Feature[index=");
          str += std::to_string(this->index());
          str += ",type=goal,k-literals={";
          for( size_t k = 0; k < goal_k_literals_.size(); ++k ) {
              int k_literal = goal_k_literals_[k];
              str += State::to_string(k_literal, &lw1_instance_);
              if( 1 + k < goal_k_literals_.size() )
                  str += ",";
          }
          return str + "}]";
      }
  };

} // namespace Width

template<typename T>
inline std::ostream& operator<<(std::ostream &os, const Width::Feature<T> &feature) {
    feature.print(os);
    return os;
}

template<typename T>
inline std::ostream& operator<<(std::ostream &os, const Width::FeatureSet<T> &feature_set) {
    feature_set.print(os);
    return os;
}

#endif

