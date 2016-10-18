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
    public:
      Feature() { }
      virtual ~Feature() { }
      virtual bool holds(const T &state) const = 0;
      virtual std::string to_string() const = 0;
      void print(std::ostream &os) const {
          os << to_string() << std::flush;
      }
  };

  template<typename T>
  class FeatureList : public std::list<const Feature<T>*> {
  };

  template<typename T>
  class FeatureSet : public std::set<const Feature<T>*> {
    public:
      FeatureSet() { }
      FeatureSet(const std::set<const Feature<T>*> &features)
        : std::set<const Feature<T>*>(features) {
      }
  };

  template<typename T>
  class OrFeature : public Feature<T> {
    protected:
      std::vector<const Feature<T>*> disjuncts_;

    public:
      OrFeature() { }
      virtual ~OrFeature() {
          for( size_t k = 0; k < disjuncts_.size(); ++k )
              delete disjuncts_[k];
      }
      virtual bool holds(const T &state) const {
          for( size_t k = 0; k < disjuncts_.size(); ++k ) {
              if( disjuncts_[k]->holds(state) )
                  return true;
          }
          return false;
      }
      virtual std::string to_string() const {
          std::string str("Feature[type=or");
          str += ",disjuncts={";
          for( size_t k = 0; k < disjuncts_.size(); ++k ) {
              str += disjuncts_[k]->to_string();
              if( k + 1 < disjuncts_.size() )
                  str += ",";
          }
          return str + "]";
      }
  };

  template<typename T>
  class AndFeature : public Feature<T> {
    protected:
      std::vector<const Feature<T>*> conjuncts_;

    public:
      AndFeature() { }
      virtual ~AndFeature() {
          for( size_t k = 0; k < conjuncts_.size(); ++k )
              delete conjuncts_[k];
      }
      virtual bool holds(const T &state) const {
          for( size_t k = 0; k < conjuncts_.size(); ++k ) {
              if( !conjuncts_[k]->holds(state) )
                  return false;
          }
          return true;
      }
      virtual std::string to_string() const {
          std::string str("Feature[type=and");
          str += ",conjuncts={";
          for( size_t k = 0; k < conjuncts_.size(); ++k ) {
              str += conjuncts_[k]->to_string();
              if( k + 1 < conjuncts_.size() )
                  str += ",";
          }
          return str + "]";
      }
  };

  template<typename T>
  class LiteralFeature : public Feature<T> {
    protected:
      const LW1_Instance &lw1_instance_;
      const int var_index_;
      const int literal_;

    public:
      LiteralFeature(const LW1_Instance &lw1_instance, int var_index, int literal)
        : lw1_instance_(lw1_instance), var_index_(var_index), literal_(literal) {
      }
      virtual ~LiteralFeature() { }
      virtual bool holds(const T &state) const {
          return state.satisfy(literal_ > 0 ? literal_ - 1 : -literal_ - 1, literal_ < 0);
      }
      virtual std::string to_string() const {
          std::string str("Feature[type=literal");
          str += ",name=" + State::to_string(literal_, &lw1_instance_);
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
      DomainSizeLiteralFeature(const LW1_Instance &lw1_instance, int var_index, int size)
        : lw1_instance_(lw1_instance), var_index_(var_index), size_(size) {
      }
      virtual ~DomainSizeLiteralFeature() { }
      virtual bool holds(const T &state) const {
          const LW1_Instance::Variable &var = *lw1_instance_.variables_[var_index_];
          int values = var.is_binary() ? 2 : var.domain().size();
          if( var.is_binary() ) {
              int atom_index = *var.domain().begin();
              if( state.satisfy(1 + 2*atom_index, false) )
                  --values;
              if( state.satisfy(1 + 2*atom_index + 1, false) )
                  --values;
          } else {
              for( set<int>::const_iterator it = var.domain().begin(); it != var.domain().end(); ++it ) {
                  int literal = 1 + 2*(*it) + 1;
                  if( state.satisfy(literal, false) )
                      --values;
              }
          }
          return size_ == values;
      }
      virtual std::string to_string() const {
          std::string str("Feature[type=dsz");
          str += ",var=" + lw1_instance_.variables_[var_index_]->name();
          str += ",size=" + std::to_string(size_);
          return str + "]";
      }
  };

} // namespace Width

template<typename T>
inline std::ostream& operator<<(std::ostream &os, const Width::Feature<T> &feature) {
    feature.print(os);
    return os;
}

#endif

