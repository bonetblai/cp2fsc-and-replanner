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
#include <string>

#include "lw1_problem.h"

//#define DEBUG

namespace Width2 {

  template<typename T>
  class Feature {
    protected:
      int index_;
      bool cached_;

    public:
      Feature(int index, bool cached) : index_(index), cached_(cached) { }
      virtual ~Feature() { }

      int index() const {
          return index_;
      }
      bool cached() const {
          return cached_;
      }
      void print(std::ostream &os, bool pretty = false) const {
          os << to_string(pretty) << std::flush;
      }

      // feature types
      virtual bool atomic() const = 0;      // if true, feature value cannot be decomposed
      virtual bool value_term() const = 0;  // if true, this is not a feature but a value to construct a feature

      // basic functions
      virtual int value(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const = 0;
      virtual bool holds(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const = 0;
      virtual std::string to_string(bool pretty = false) const = 0;

      // comparison for feature pointers
      struct ptr_compare_t {
          bool operator()(const Feature<T> *f1, const Feature<T> *f2) const {
              return f1->index_ < f2->index_;
          }
      };
  };

  template<typename T>
  class LiteralFeature : public Feature<T> {
    using Feature<T>::index;
    using Feature<T>::cached;
    protected:
      const LW1_Instance &lw1_instance_;
      const int var_index_;
      const int literal_;
      const bool positive_;

    public:
      LiteralFeature(int index, const LW1_Instance &lw1_instance, int var_index, int literal, bool positive)
        : Feature<T>(index, false),
          lw1_instance_(lw1_instance),
          var_index_(var_index),
          literal_(literal),
          positive_(positive) {
      }
      virtual ~LiteralFeature() { }

      const LW1_Instance& lw1_instance() const {
          return lw1_instance_;
      }
      int var_index() const {
          return var_index_;
      }
      int literal() const {
          return literal_;
      }
      bool positive() const {
          return positive_;
      }

      virtual bool atomic() const {
          return true;
      }
      virtual bool value_term() const {
          return false;
      }
      virtual int value(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          int feature_value = -1;
          if( cached() && (cache != 0) ) {
              assert((index() >= 0) && (index() < (*cache).size()));
              feature_value = (*cache)[index()];
          } else {
              feature_value = belief.satisfy(literal_ > 0 ? literal_ - 1 : -literal_ - 1, literal_ < 0) ? 1 : 0;
          }
          if( verbose ) std::cout << *this << " --> " << feature_value << std::endl;
          return feature_value;
      }
      virtual bool holds(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          return value(belief, cache, verbose) == 1;
      }
      virtual std::string to_string(bool pretty = false) const {
          if( pretty ) {
              return State::to_string(literal_, &lw1_instance_);
          } else {
              std::string str("Feature[index=");
              str += std::to_string(this->index());
              str += ",type=literal,name=";
              str += State::to_string(literal_, &lw1_instance_);
              return str + "]";
          }
      }
  };

  template<typename T>
  class DomainSizeValue : public Feature<T> {
    using Feature<T>::index;
    using Feature<T>::cached;
    protected:
      const LW1_Instance &lw1_instance_;
      const int var_index_;

    public:
      DomainSizeValue(int index, const LW1_Instance &lw1_instance, int var_index)
        : Feature<T>(index, true),
          lw1_instance_(lw1_instance),
          var_index_(var_index) {
      }
      virtual ~DomainSizeValue() { }

      const LW1_Instance& lw1_instance() const {
          return lw1_instance_;
      }
      int var_index() const {
          return var_index_;
      }

      int num_possible_values(const T &belief, bool verbose = false) const {
          const LW1_Instance::Variable &var = *lw1_instance_.variables_[var_index_];
          int num_values = var.is_binary() ? 2 : var.domain().size();
          if( var.is_binary() ) {
              int atom_index = *var.domain().begin();
              if( belief.satisfy(2*atom_index, false) )
                  --num_values;
              if( belief.satisfy(2*atom_index + 1, false) )
                  --num_values;
          } else {
              for( std::set<int>::const_iterator it = var.domain().begin(); it != var.domain().end(); ++it ) {
                  int literal = 1 + 2*(*it) + 1;
                  if( belief.satisfy(literal - 1, false) )
                      --num_values;
#ifdef DEBUG
                  std::cout << "checking "; belief::print_literal(std::cout, literal, &lw1_instance_);
                  std::cout << " --> " << belief.satisfy(literal - 1, false) << std::endl;
#endif
              }
          }
          if( verbose ) std::cout << "domain-size(var=" << var.name() << ") --> " << num_values << std::endl;
          return num_values;
      }

      virtual bool atomic() const {
          return true;
      }
      virtual bool value_term() const {
          return true;
      }
      virtual int value(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          int feature_value = -1;
          if( cached() && (cache != 0) ) {
              assert((index() >= 0) && (index() < (*cache).size()));
              feature_value = (*cache)[index()];
          } else {
              feature_value = num_possible_values(belief, verbose);
          }
          if( verbose ) std::cout << *this << " --> " << feature_value << std::endl;
          if( feature_value < -1 ) exit(0);
          return feature_value;
      }
      virtual bool holds(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          std::cout << Utils::internal_error() << "holds() called for feature value" << std::endl;
          exit(-1);
      }
      virtual std::string to_string(bool pretty = false) const {
          if( pretty ) {
              return std::string("dsz(") + lw1_instance_.variables_[var_index_]->name() + ")";
          } else {
              std::string str("Feature[index=");
              str += std::to_string(this->index());
              str += ",type=dsz-value,var=" + lw1_instance_.variables_[var_index_]->name();
              return str + "]";
          }
      }
  };

  template<typename T>
  class ValueTestFeature : public Feature<T> {
    protected:
      const Feature<T> &base_;
      int target_;
      int test_type_;

    public:
      ValueTestFeature(int index, const Feature<T> &base, int target, int test_type)
        : Feature<T>(index, false),
          base_(base),
          target_(target),
          test_type_(test_type) {
      }
      virtual ~ValueTestFeature() { }

      const Feature<T> &base() const {
          return base_;
      }
      int target() const {
          return target_;
      }
      int test_type() const {
          return test_type;
      }

      virtual bool atomic() const {
          return false;
      }
      virtual bool value_term() const {
          return false;
      }
      virtual int value(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          int feature_value = -1;
          int base_value = base_.value(belief, cache, verbose);
          if( test_type_ == 0 ) { // EQ
              feature_value = base_value == target_ ? 1 : 0;
          } else if( test_type_ == 1 ) { // LE
              feature_value = base_value <= target_ ? 1 : 0;
          } else {
              assert(test_type_ == 2); // GE
              feature_value = base_value >= target_ ? 1 : 0;
          }
          if( verbose ) std::cout << *this << " --> " << feature_value << std::endl;
          return feature_value;
      }
      virtual bool holds(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          return value(belief, cache, verbose) == 1;
      }
      virtual std::string to_string(bool pretty = false) const {
          if( pretty ) {
              std::string str = base_.to_string(pretty);
              if( test_type_ == 0 )
                  str += std::string("=");
              else if( test_type_ == 1 )
                  str += std::string("<=");
              else
                  str += std::string(">=");
              str += std::to_string(target_);
              return str;
          } else {
              std::string str("Feature[index=");
              str += std::to_string(this->index());
              str += ",type=value-test,base=" + base_.to_string(pretty);
              str += ",target=" + std::to_string(target_);
              str += ",test-type=" + std::to_string(test_type_);
              return str + "]";
          }
      }
  };

  template<typename T>
  class ValueTestEQ : public ValueTestFeature<T> {
    public:
      ValueTestEQ(int index, const Feature<T> &base, int target)
        : ValueTestFeature<T>(index, base, target, 0) {
      }
      virtual ~ValueTestEQ() { }
  };

  template<typename T>
  class ValueTestLE : public ValueTestFeature<T> {
    public:
      ValueTestLE(int index, const Feature<T> &base, int target)
        : ValueTestFeature<T>(index, base, target, 1) {
      }
      virtual ~ValueTestLE() { }
  };

  template<typename T>
  class ValueTestGE : public ValueTestFeature<T> {
    public:
      ValueTestGE(int index, const Feature<T> &base, int target)
        : ValueTestFeature<T>(index, base, target, 2) {
      }
      virtual ~ValueTestGE() { }
  };

  template<typename T>
  class GoalFeature : public Feature<T> {
    using Feature<T>::index;
    using Feature<T>::cached;
    protected:
      const LW1_Instance &lw1_instance_;
      std::vector<int> goal_literals_;

    public:
      GoalFeature(int index, const LW1_Instance &lw1_instance)
        : Feature<T>(index, false), lw1_instance_(lw1_instance) {
          for( index_set::const_iterator it = lw1_instance_.po_instance_.goal_literals_.begin(); it != lw1_instance_.po_instance_.goal_literals_.end(); ++it ) {
              int atom = *it > 0 ? *it - 1 : -*it - 1;
              int literal = *it > 0 ? 1 + 2*atom : 1 + 2*atom + 1;
              goal_literals_.push_back(literal);
          }
      }
      virtual ~GoalFeature() { }

      const LW1_Instance& lw1_instance() const {
          return lw1_instance_;
      }
      const std::vector<int>& goal_literals() const {
          return goal_literals_;
      }

      virtual bool atomic() const {
          return true;
      }
      virtual bool value_term() const {
          return false;
      }
      virtual int value(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          int feature_value = -1;
          if( cached() && (cache != 0) ) {
              assert((index() >= 0) && (index() < (*cache).size()));
              feature_value = (*cache)[index()];
          } else {
              feature_value = 1;
              for( size_t k = 0; k < goal_literals_.size(); ++k ) {
                  int literal = goal_literals_[k];
                  if( !belief.satisfy(literal > 0 ? literal - 1 : -literal - 1, literal < 0) ) {
                      feature_value = 0;
                      break;
                  }
              }
          }
          if( verbose ) std::cout << *this << " --> " << feature_value << std::endl;
          return feature_value;
      }
      virtual bool holds(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          return value(belief, cache, verbose) == 1;
      }
      virtual std::string to_string(bool pretty = false) const {
          if( pretty ) {
              return "[goal]";
          } else {
              std::string str("Feature[index=");
              str += std::to_string(this->index());
              str += ",type=goal,literals={";
              for( size_t k = 0; k < goal_literals_.size(); ++k ) {
                  int literal = goal_literals_[k];
                  str += State::to_string(literal, &lw1_instance_);
                  if( 1 + k < goal_literals_.size() )
                      str += ",";
              }
              return str + "}]";
          }
      }
  };

#if 0
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
#endif

#if 0
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

      virtual bool holds(const T &belief, bool verbose = false) const {
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
#endif

#if 0
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

      virtual bool holds(const T &belief, bool verbose = false) const {
          return !feature_.holds(belief, verbose);
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
#endif

#if 0
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

      virtual bool holds(const T &belief, bool verbose = false) const {
          for( size_t k = 0; k < disjuncts_.size(); ++k ) {
              if( disjuncts_[k]->holds(belief, verbose) )
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
#endif

  template<typename T>
  class AndFeature : public Feature<T> {
    protected:
      std::vector<const Feature<T>*> conjuncts_;

    public:
      AndFeature(int index) : Feature<T>(index, false) { }
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

      virtual bool atomic() const {
          return false;
      }
      virtual bool value_term() const {
          return false;
      }
      virtual int value(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          int feature_value = 1;
          for( size_t k = 0; k < conjuncts_.size(); ++k ) {
              if( conjuncts_[k]->value(belief, cache, verbose) == 0 )
                  feature_value = 0;
          }
          return feature_value;
      }
      virtual bool holds(const T &belief, const std::vector<int> *cache = 0, bool verbose = false) const {
          return value(belief, cache, verbose) == 1;
      }
      virtual std::string to_string(bool pretty = false) const {
          if( pretty ) {
              std::string str;
              for( size_t k = 0; k < conjuncts_.size(); ++k ) {
                  str += conjuncts_[k]->to_string(pretty);
                  if( k + 1 < conjuncts_.size() )
                      str += " & ";
              }
              return str;
          } else {
              std::string str("Feature[index=");
              str += std::to_string(this->index());
              str += ",type=and,conjuncts={";
              for( size_t k = 0; k < conjuncts_.size(); ++k ) {
                  str += conjuncts_[k]->to_string(pretty);
                  if( k + 1 < conjuncts_.size() )
                      str += ",";
              }
              return str + "}]";
          }
      }
  };

} // namespace Width2

template<typename T>
inline std::ostream& operator<<(std::ostream &os, const Width2::Feature<T> &feature) {
    feature.print(os, true);
    return os;
}

#undef DEBUG

#endif

