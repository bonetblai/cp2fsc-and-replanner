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

#ifndef FEATURES_H
#define FEATURES_H

#include <cassert>
#include <iostream>
#include <list>
#include <set>
#include <string>

#include "lw1_problem.h"

namespace Width {

  template<typename T>
  class Feature {
      int index_;

    public:
      Feature(int index) : index_(index) { }
      virtual ~Feature() { }
      virtual bool holds(const T &state) const = 0;
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
              return f1->to_string() < f2->to_string();
          }
      };
  };

  template<typename T>
  class FeatureSet : public std::set<const Feature<T>*, typename Feature<T>::ptr_compare_t> {
    public:
      FeatureSet() { }
      FeatureSet(const std::set<const Feature<T>*, typename Feature<T>::ptr_compare_t> &features)
        : std::set<const Feature<T>*, typename Feature<T>::ptr_compare_t>(features) {
      }
  };

  template<typename T>
  class OrFeature : public Feature<T> {
    protected:
      std::vector<const Feature<T>*> disjuncts_;

    public:
      OrFeature(int index) : Feature<T>(index) { }
      virtual ~OrFeature() {
          for( size_t k = 0; k < disjuncts_.size(); ++k )
              delete disjuncts_[k];
      }

      const std::vector<const Feature<T>*>& disjuncts() const {
          return disjuncts_;
      }
      void add_disjunct(const Feature<T> &feature) {
          disjuncts_.push_back(&feature);
      }

      virtual bool holds(const T &state) const {
          for( size_t k = 0; k < disjuncts_.size(); ++k ) {
              if( disjuncts_[k]->holds(state) )
                  return true;
          }
          return false;
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
      virtual ~AndFeature() {
          for( size_t k = 0; k < conjuncts_.size(); ++k )
              delete conjuncts_[k];
      }

      const std::vector<const Feature<T>*>& conjuncts() const {
          return conjuncts_;
      }
      void add_conjunct(const Feature<T> &feature) {
          conjuncts_.push_back(&feature);
      }

      virtual bool holds(const T &state) const {
          for( size_t k = 0; k < conjuncts_.size(); ++k ) {
              if( !conjuncts_[k]->holds(state) )
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
  class LiteralFeature : public Feature<T> {
    protected:
      const LW1_Instance &lw1_instance_;
      const int var_index_;
      const int literal_;

    public:
      LiteralFeature(int index, const LW1_Instance &lw1_instance, int var_index, int literal)
        : Feature<T>(index),
          lw1_instance_(lw1_instance),
          var_index_(var_index),
          literal_(literal) {
      }
      virtual ~LiteralFeature() { }

      int var_index() const {
          return var_index_;
      }
      int literal() const {
          return literal_;
      }

      virtual bool holds(const T &state) const {
          return state.satisfy(literal_ > 0 ? literal_ - 1 : -literal_ - 1, literal_ < 0);
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
          str += ",type=literal,name=";
          str += State::to_string(literal_, &lw1_instance_);
          return str + "]";
      }
  };

  template<typename T>
  class DomainSizeLiteralFeature : public Feature<T> {
    protected:
      const LW1_Instance &lw1_instance_;
      const int var_index_;
      const int size_;

    public:
      DomainSizeLiteralFeature(int index, const LW1_Instance &lw1_instance, int var_index, int size)
        : Feature<T>(index),
          lw1_instance_(lw1_instance),
          var_index_(var_index),
          size_(size) {
      }
      virtual ~DomainSizeLiteralFeature() { }

      int var_index() const {
          return var_index_;
      }
      int size() const {
          return size_;
      }

      virtual bool holds(const T &state) const {
          const LW1_Instance::Variable &var = *lw1_instance_.variables_[var_index_];
          int values = var.is_binary() ? 2 : var.domain().size();
          if( var.is_binary() ) {
              int atom_index = *var.domain().begin();
              if( state.satisfy(2*atom_index, false) )
                  --values;
              if( state.satisfy(2*atom_index + 1, false) )
                  --values;
          } else {
              for( set<int>::const_iterator it = var.domain().begin(); it != var.domain().end(); ++it ) {
                  int literal = 1 + 2*(*it) + 1;
                  if( state.satisfy(literal - 1, false) )
                      --values;
#ifdef DEBUG
                  std::cout << "checking "; State::print_literal(std::cout, literal, &lw1_instance_);
                  std::cout << " --> " << state.satisfy(literal - 1, false) << std::endl;
#endif
              }
#ifdef DEBUG
              std::cout << "status for " << *this << " = " << (size_ == values) << std::endl;
#endif
          }
          return size_ == values;
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
          return str + "]";
      }
  };

  template<typename T>
  class GoalFeature : public Feature<T> {
    protected:
      const LW1_Instance &lw1_instance_;
      std::vector<int> goal_literals_;

    public:
      GoalFeature(int index, const LW1_Instance &lw1_instance)
        : Feature<T>(index), lw1_instance_(lw1_instance) {
          for( index_set::const_iterator it = lw1_instance_.po_instance_.goal_literals_.begin(); it != lw1_instance_.po_instance_.goal_literals_.end(); ++it ) {
              int atom = *it > 0 ? *it - 1 : -*it - 1;
              int literal = *it > 0 ? 1 + 2*atom : 1 + 2*atom + 1;
              goal_literals_.push_back(literal);
          }
      }
      virtual ~GoalFeature() { }

      const std::vector<int>& goal_literals() const {
          return goal_literals_;
      }

      virtual bool holds(const T &state) const {
          for( size_t k = 0; k < goal_literals_.size(); ++k ) {
              int literal = goal_literals_[k];
              if( !state.satisfy(literal > 0 ? literal - 1 : -literal - 1, literal < 0) )
                  return false;
          }
          return true;
      }
      virtual bool subsumes(const Feature<T> &feature) const {
          return false;
      }
      virtual std::string to_string() const {
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
  };

} // namespace Width

template<typename T>
inline std::ostream& operator<<(std::ostream &os, const Width::Feature<T> &feature) {
    feature.print(os);
    return os;
}

#endif

