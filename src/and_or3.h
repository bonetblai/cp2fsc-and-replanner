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

#ifndef AND_OR3_H
#define AND_OR3_H

#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "lw1_problem.h"
#include "utils.h"

namespace AndOr3 {

  // this is a wrapper that add ref-counts to instances of T
  template<typename T>
  class Belief {
    protected:
      mutable int ref_count_; // reference count (UNUSED)
      const T *rep_;          // representation of belief

    public:
      int ref_count() const {
          return ref_count_;
      }
      int increase_ref_count() const {
          return ++ref_count_;
      }
#if 0
      const Belief* copy() const {
          ++ref_count_;
          return this;
      }
#endif
      static bool deallocate(const Belief *belief) { // CHECK
          if( belief != 0 ) {
              if( belief->ref_count_ <= 0 ) std::cout << "REF-C=" << belief->ref_count_ << std::endl;
              assert(belief->ref_count_ > 0);
              if( --belief->ref_count_ == 0 ) {
                  std::cout << Utils::green() << "[Belief::deallocate::delete:" << Utils::normal() << std::flush;
                  delete belief;
                  std::cout << Utils::green() << "]" << Utils::normal() << std::flush;
                  return true;
              }
          }
          return false;
      }

    public:
      Belief(const T *belief = 0) : ref_count_(1), rep_(belief) {
      }
      virtual ~Belief() {
          std::cout << "(dtor for Belief)" << std::flush;
      }
      const T* rep() const {
          return rep_;
      }
      void print(std::ostream &os) const {
          if( rep_ == 0 )
              os << "(null)";
          else
              rep_->print(os);
      }
  };

  // forward references
  template<typename T> class AndNode;
  template<typename T> class OrNode;

  class Node {
    protected:
      mutable int ref_count_;          // CHECK: currently unused
      mutable int cached_value_;       // used for computation of global features
      mutable bool dead_by_label_;     // either node is goal or descendant of solved OR node
      mutable bool dead_by_feature_;   // either pruned by feature or descendant of dead AND node

    protected:
      virtual int deallocate() const = 0;

    public:
      int ref_count() const {
          return ref_count_;
      }
      int increase_ref_count() const {
          return ++ref_count_;
      }
#if 0
      const Node* copy() const {
          ++ref_count_;
          return this;
      }
#endif
      static bool deallocate(const Node *node) { // CHECK
          if( node != 0 ) {
              assert(node->ref_count_ > 0);
              if( node->deallocate() == 0 ) {
                  std::cout << Utils::green() << "[Node::deallocate::delete:" << Utils::normal() << std::flush;
                  delete node;
                  std::cout << Utils::green() << "]" << Utils::normal() << std::flush;
                  return true;
              }
          }
          return false;
      }

    public:
      Node() : ref_count_(1), cached_value_(-1), dead_by_label_(false), dead_by_feature_(false) { }
      virtual ~Node() { std::cout << "(dtor for Node)" << std::flush; }
      int cached_value() const {
          return cached_value_;
      }
      void set_cached_value(int value) const {
          cached_value_ = value;
      }
      bool dead_by_label() const {
          return dead_by_label_;
      }
      void kill_by_label() const {
          dead_by_label_ = true;
      }
      bool dead_by_feature() const {
          return dead_by_feature_;
      }
      void kill_by_feature() const {
          dead_by_feature_ = true;
      }
      bool dead() const {
          return dead_by_label() || dead_by_feature();
      }

      virtual std::string to_string(const LW1_Instance *lw1_instance, const std::string &color) const = 0;
      virtual void print(std::ostream &os) const = 0;
      virtual void pretty_print(std::ostream &os, bool solution, const LW1_Instance &lw1_instance, const std::string &color, int indent = 0) const = 0;

      std::string to_string(const LW1_Instance *lw1_instance = 0) const {
          return to_string(lw1_instance, Utils::normal());
      }
  };

  template<typename T>
  class AndNode : public Node {
    protected:
      int action_;                             // action leading to this node
      const Belief<T> *belief_;                // belief after action is applied (belief for this node)
      const OrNode<T> *parent_;                // parent node
      std::vector<const OrNode<T>*> children_; // children
      mutable bool has_solution_;              // has_solution

    protected:
      virtual int deallocate() const { // CHECK
          if( --Node::ref_count_ == 0 ) {
              Belief<T>::deallocate(belief_);
              Node::deallocate(parent_);
          }
          return ref_count_;
      }

    public:
      static bool deallocate(const AndNode *node) { // CHECK
          return Node::deallocate(node);
      }

    public:
      AndNode(int action, const Belief<T> *belief, const OrNode<T> *parent)
        : action_(action), belief_(belief), parent_(parent), has_solution_(false) {
      }
      virtual ~AndNode() {
          std::cout << "(dtor for AndNode)" << std::flush;
      }

      virtual std::string to_string(const LW1_Instance *lw1_instance, const std::string &color) const {
          std::string str = color + "And[";
          str += std::string("ptr=0x") + std::to_string(size_t(this));
          str += std::string(",ref=") + std::to_string(Node::ref_count_);
          if( lw1_instance != 0 ) {
              const Instance::Action &action = *lw1_instance->actions_[action_];
              str += std::string(",action=") + Utils::blue() + action.name() + color;
          } else {
              str += std::string(",action=") + std::to_string(action_);
          }
          str += std::string(",parent=0x") + std::to_string(size_t(parent_));
          str += std::string(",solution=") + std::to_string(has_solution_);
          return str + "]" + Utils::normal();
      }
      virtual void print(std::ostream &os) const {
          os << Node::to_string();
      }
      virtual void pretty_print(std::ostream &os, bool solution, const LW1_Instance &lw1_instance, const std::string &color, int indent = 0) const {
          os << std::string(2 * indent, ' ')
             << std::to_string(indent) << ".";
          if( dead_by_label() )
               os << to_string(&lw1_instance, Utils::red());
          else if( dead_by_feature() )
               os << to_string(&lw1_instance, Utils::magenta());
          else
               os << to_string(&lw1_instance, color);
          os << std::endl;
          for( size_t k = 0; k < children_.size(); ++k )
              children_[k]->pretty_print(os, solution, lw1_instance, color, 1 + indent);
      }

      const int action() const {
          return action_;
      }
      const Belief<T>* belief() const {
          return belief_;
      }
      const OrNode<T>* parent() const {
          return parent_;
      }
      void set_parent(const OrNode<T> *parent) {
          parent_ = parent;
      }
      bool has_solution() const {
          return has_solution_;
      }
      void set_has_solution(bool has_solution) const {
          has_solution_ = has_solution;
      }
      void clear_dead_by_feature() const {
          dead_by_feature_ = false;
      }

      const std::vector<const OrNode<T>*>& children() const {
          return children_;
      }
      const OrNode<T>* child(int k) const {
          assert((k >= 0) && (k < children_.size()));
          return children_[k];
      }
      void reserve(size_t num_children) {
          children_.reserve(num_children);
      }
      size_t add_child(const OrNode<T> *child) {
          children_.push_back(child);
          return children_.size();
      }
  };

  template<typename T>
  class OrNode : public Node {
    protected:
      const Belief<T> *belief_;                 // belief for this node
      const AndNode<T> *parent_;                // parent node
      std::vector<const AndNode<T>*> children_; // children
      bool is_goal_;                            // is_goal
      mutable int best_child_;                  // index of best child

    protected:
      virtual int deallocate() const { // CHECK
          if( --Node::ref_count_ == 0) {
              Belief<T>::deallocate(belief_);
              Node::deallocate(parent_);
          }
          return ref_count_;
      }

    public:
      static bool deallocate(const OrNode *node) { // CHECK
          return Node::deallocate(node);
      }

    public:
      OrNode(const Belief<T> *belief, const AndNode<T> *parent, bool is_goal)
        : belief_(belief), parent_(parent), is_goal_(is_goal), best_child_(-1) {
      }
      virtual ~OrNode() {
          std::cout << "(dtor for OrNode)" << std::flush;
      }

      virtual std::string to_string(const LW1_Instance *lw1_instance, const std::string &color) const {
          std::string str = color + "Or[";
          str += std::string("ptr=0x") + std::to_string(size_t(this));
          str += std::string(",ref=") + std::to_string(Node::ref_count_);
          str += std::string(",parent=0x") + std::to_string(size_t(parent_));
          str += std::string(",best-child=") + std::to_string(best_child_);
          str += std::string(",is-goal=") + std::to_string(is_goal_);
          return str + "]" + Utils::normal();
      }
      virtual void print(std::ostream &os) const {
          os << Node::to_string();
      }
      virtual void pretty_print(std::ostream &os, bool solution, const LW1_Instance &lw1_instance, const std::string &color, int indent = 0) const {
          os << std::string(2 * indent, ' ')
             << std::to_string(indent) << ".";
          if( dead_by_label() )
               os << to_string(&lw1_instance, Utils::red());
          else if( dead_by_feature() )
               os << to_string(&lw1_instance, Utils::magenta());
          else
               os << to_string(&lw1_instance, color);
          os << std::endl;
          if( solution && (best_child_ != -1) ) {
              assert((best_child_ >= 0) && (best_child_ < children_.size()));
              children_[best_child_]->pretty_print(os, solution, lw1_instance, color, 1 + indent);
          } else {
              for( size_t k = 0; k < children_.size(); ++k )
                  children_[k]->pretty_print(os, solution, lw1_instance, color, 1 + indent);
          }
      }

      const Belief<T>* belief() const {
          return belief_;
      }
      const AndNode<T>* parent() const {
          return parent_;
      }
      bool is_goal() const {
          return is_goal_;
      }
      int best_child() const {
          return best_child_;
      }
      void set_best_child(int best_child) const {
          best_child_ = best_child;
      }
      void clear_dead_by_feature() const {
          dead_by_feature_ = false;
      }

      const std::vector<const AndNode<T>*>& children() const {
          return children_;
      }
      const AndNode<T>* child(int k) const {
          assert((k >= 0) && (k < children_.size()));
          return children_[k];
      }
      void reserve(size_t num_children) {
          children_.reserve(num_children);
      }
      size_t add_child(const AndNode<T> *child) {
          children_.push_back(child);
          return children_.size();
      }
  };

} // namespace AndOr3

inline std::ostream& operator<<(std::ostream &os, const AndOr3::Node &node) {
    node.print(os);
    return os;
}

#endif

