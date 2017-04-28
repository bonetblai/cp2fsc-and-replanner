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

#ifndef AND_OR2_H
#define AND_OR2_H

#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utils.h"

namespace AndOr {

  // general repo class
  template<typename S, typename T>
  class Repository {
    public:
      // CHECK: replace red-black tree by hash table
      typedef typename std::map<const S*, const T*> repo_t;
      typedef typename std::map<const S*, const T*>::const_iterator const_iterator;

      const_iterator begin() const {
          return repo_.begin();
      }
      const_iterator end() const {
          return repo_.end();
      }

    protected:
      std::string name_;
      repo_t repo_;

      const T* fetch(const S *key) {
          const_iterator it = repo_.find(key);
          if( it != end() ) {
              return it->second;
          } else {
              T *wrapped = new T(key);
              repo_.insert(std::make_pair(key, wrapped));
              return wrapped;
          }
      }

    public:
      Repository(const std::string &name = "") : name_(name) {
      }
      ~Repository() {
          std::cout << "(dtor for Repository '" << name_ << "': size=" << repo_.size() << ")" << std::endl;
          int deleted_items = 0;
          for( const_iterator it = begin(); it != end(); ++it ) {
              deleted_items += T::deallocate(it->second) ? 1 : 0;
              assert(it->second->ref_count() == 0);
          }
          assert(deleted_items == int(repo_.size()));
      }

      const std::string& name() const {
          return name_;
      }

      const T* get(const S *key) {
          // use cast to permit copy() implemented at abstract class
          return static_cast<const T*>(fetch(key)->copy());
      }

      size_t size() const {
          return repo_.size();
      }
  };

  // this is a wrapper that add ref-counts to instances of T
  template<typename T>
  class Belief {
    protected:
      mutable int ref_count_;
      const T *belief_;

    public:
      int ref_count() const {
          return ref_count_;
      }
      int increase_ref_count() const {
          return ++ref_count_;
      }
      const Belief* copy() const {
          ++ref_count_;
          return this;
      }
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
      Belief(const T *belief = 0) : ref_count_(1), belief_(belief) {
      }
      ~Belief() {
      }

      const T* belief() const {
          return belief_;
      }

      void print(std::ostream &os, int indent = 0) const {
          os << std::string(indent, ' ');
          if( belief_ == 0 )
              os << "(null)";
          else
              belief_->print(os);
      }
  };

  template<typename T>
  class BeliefRepo : public Repository<T, Belief<T> > {
    public:
      BeliefRepo() : Repository<T, Belief<T> >("BeliefRepo") {
      }
  };

  // forward references
  template<typename T> class AndNode;
  template<typename T> class OrNode;

  class Node {
    protected:
      mutable int ref_count_;
      mutable float score_;

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
      Node() : ref_count_(1), score_(-1) { }
      virtual ~Node() { }
      float score() const {
          return score_;
      }
      void set_score(float score) const {
          score_ = score;
      }
      int node_count() const {
          return node_count(0);
      }
      int and_node_count() const {
          return node_count(1);
      }
      int or_node_count() const {
          return node_count(2);
      }
      virtual int node_count(int type) const = 0;
      virtual void print(std::ostream &os, int indent = 0) const = 0;
      virtual void print_tree(std::ostream &os, int indent = 0) const = 0;
  };

  template<typename T>
  class AndNode : public Node {
    protected:
      int action_;                             // action leading to this node
      const Belief<T> *belief_;                // belief after action is applied (belief for this node)
      const OrNode<T> *parent_;                // parent node
      std::vector<const OrNode<T>*> children_; // children

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
        : action_(action), belief_(belief), parent_(parent) {
      }
#if 0
      AndNode(int action, const T *belief, BeliefRepo<T> &repo)
        : belief_(repo.get(belief)), action_(action) {
      }
#endif
      virtual ~AndNode() {
      }

      virtual int node_count(int type) const {
          int count = 0;
          for( size_t k = 0; k < children_.size(); ++k )
              count += children_[k]->node_count(type);
          return type != 2 ? 1 + count : count;
      }
      virtual void print(std::ostream &os, int indent = 0) const {
          os << std::string(indent, ' ')
             << Utils::blue()
             << "AND[ptr=" << this
             << ",ref=" << Node::ref_count_
             << ",action=" << action_
             << ",parent=" << parent_
             << ",score=" << score_
             << "}]"
             << Utils::normal();
      }
      virtual void print_tree(std::ostream &os, int indent = 0) const {
          os << std::string(indent, ' ');
          print(os, 0);
          os << std::endl;
          for( size_t k = 0; k < children_.size(); ++k )
              children_[k]->print_tree(os, 4 + indent);
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

      const std::vector<const OrNode<T>*>& children() const {
          return children_;
      }
      const OrNode<T>* child(int k) const {
          assert((k >= 0) && (k < children_.size()));
          return children_[k];
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
      OrNode(const Belief<T> *belief, const AndNode<T> *parent)
        : belief_(belief), parent_(parent) {
      }
#if 0
      OrNode(const T *belief, BeliefRepo<T> &repo, int action)
        : belief_(repo.get(belief)), action_(action), child_(0) {
      }
#endif
      virtual ~OrNode() {
      }

      virtual int node_count(int type) const {
          int count = 0;
          for( size_t k = 0; k < children_.size(); ++k )
              count += children_[k]->node_count(type);
          return type != 1 ? 1 + count : count;
      }
      virtual void print(std::ostream &os, int indent = 0) const {
          os << std::string(indent, ' ')
             << Utils::green()
             << "OR[ptr=" << this
             << ",ref=" << Node::ref_count_
             << ",parent=" << parent_
             << ",score=" << score_
             << "]" 
             << Utils::normal();
      }
      virtual void print_tree(std::ostream &os, int indent = 0) const {
          os << std::string(indent, ' ');
          print(os, 0);
          os << std::endl;
          for( size_t k = 0; k < children_.size(); ++k )
              children_[k]->print_tree(os, 4 + indent);
      }

      const Belief<T>* belief() const {
          return belief_;
      }
      const AndNode<T>* parent() const {
          return parent_;
      }
      void set_parent(const AndNode<T> *parent) {
          parent_ = parent;
      }

      const std::vector<const AndNode<T>*>& children() const {
          return children_;
      }
      const AndNode<T>* child(int k) const {
          assert((k >= 0) && (k < children_.size()));
          return children_[k];
      }
      size_t add_child(const AndNode<T> *child) {
          children_.push_back(child);
          return children_.size();
      }
  };

  template<typename T>
  class OrNodeList : public std::vector<const OrNode<T>*> {
  };

#if 0
#if 1
  template<typename T>
  class OrNodeRepo : public Repository<Belief<T>, OrNode<T> > {
    public:
      OrNodeRepo() : Repository<Belief<T>, OrNode<T> >("OrNodeRepo") {
      }
  };

  template<typename T>
  class AndNodeRepo : public Repository<T, AndNode<T> > {
    public:
      AndNodeRepo() : Repository<Belief<T>, AndNode<T> >("AndNodeRepo") {
      }
  };
#endif
#endif

  template<typename T>
  class Policy {
    protected:
      mutable BeliefRepo<T> *repo_;
      OrNodeList<T> tip_nodes_;

      void make_empty_policy(const T *belief) {
          assert(belief != 0);
          tip_nodes_.clear();
#if 0
          Node::deallocate(root_);
          const Belief<T> *root_belief = repo_.get(belief);
          root_ = new OrNode<T>(root_belief, 0);
          tip_nodes_.push_back(root_);
#endif
          OrNode<T> *root = new OrNode<T>(repo_->get(belief), 0);
          tip_nodes_.push_back(root);
      }

    public:
      Policy(BeliefRepo<T> &repo) : repo_(&repo) {
      }
      Policy(BeliefRepo<T> &repo, const T *belief)
        : repo_(&repo) {
          make_empty_policy(belief);
      }
      virtual ~Policy() {
          //deallocate();
      }

#if 0
      const OrNode<T>* root() const {
          return root_;
      }
#endif
      BeliefRepo<T>& repo() const {
          return *repo_;
      }
      const OrNodeList<T>& tip_nodes() const {
          return tip_nodes_;
      }
      void add_tip(const OrNode<T> *tip) {
          tip_nodes_.push_back(tip);
      }

      int cost() const {
          //std::cout << Utils::magenta() << "Policy<T>::cost()" << Utils::normal() << std::endl;
          // CHECK: FILL MISSING CODE
          return 0;
      }

#if 0
      void deallocate() { // CHECK
          if( root_ != 0 ) {
              assert(root_->ref_count() > 0);
              Node::deallocate(root_);
              root_ = 0;
          }
      }
#endif
  };

  template<typename T>
  inline AndNode<T>* create_and_node(int action, const T *bel_a, std::vector<const T*> &successors) {
      const Belief<T> *belief_a = new Belief<T>(bel_a);
      AndNode<T> *and_node = new AndNode<T>(action, belief_a, 0);
      for( size_t k = 0; k < successors.size(); ++k ) {
          const Belief<T> *belief_ao = new Belief<T>(successors[k]);
          OrNode<T> *child = new OrNode<T>(belief_ao, and_node);
          and_node->add_child(child);
      }
      return and_node;
  }

} // namespace AndOr

template<typename T>
inline std::ostream& operator<<(std::ostream &os, const AndOr::Belief<T> &belief) {
    belief.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const AndOr::Node &node) {
    node.print(os);
    return os;
}

#endif

