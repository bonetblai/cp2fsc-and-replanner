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

#ifndef AND_OR_H
#define AND_OR_H

#include <cassert>
#include <iostream>
#include <map>
#include <vector>
#include "utils.h"

namespace AndOr {

// general repo class
template<typename S, typename T>
class Repository {
  public:
    // CHECK: replace this by hash table
    typedef typename std::map<const S*, const T*> repo_t;
    typedef typename std::map<const S*, const T*>::const_iterator const_iterator_t;

  protected:
    repo_t repo_;

    const T* fetch(const S *key) {
        const_iterator_t it = repo_.find(key);
        if( it != repo_.end() ) {
            return it->second;
        } else {
            T *wrapped = new T(key);
            repo_.insert(std::make_pair(key, wrapped));
            return wrapped;
        }
    }
 
  public:
    Repository() { }
    ~Repository() {
        std::cout << "(dtor for Repository: size=" << repo_.size() << ")" << std::endl;
        int deleted_items = 0;
        for( const_iterator_t it = repo_.begin(); it != repo_.end(); ++it )
            deleted_items += T::deallocate(it->second) ? 1 : 0;
        assert(deleted_items == int(repo_.size()));
    }

    const T* get(const S *key) {
        return fetch(key)->copy();
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
    static bool deallocate(const Belief *belief) {
        if( belief != 0 ) {
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
    Belief(const T *belief = 0) : ref_count_(1), belief_(belief) { }
    ~Belief() { std::cout << "(dtor for Belief)" << std::flush; }

    const Belief* copy() const {
        ++ref_count_;
        return this;
    }

    void print(std::ostream &os) const {
        if( belief_ == 0 )
            os << "(null)";
        else
            belief_->print(os);
    }
};

template<typename T>
class BeliefRepo : public Repository<T, Belief<T> > {
};

// forward references
template<typename T> class AndNode;
template<typename T> class OrNode;

class Node {
  protected:
    mutable int ref_count_;

  protected:
    virtual int deallocate() const = 0;

  public:
    int ref_count() const {
        return ref_count_;
    }
    void increase_ref_count() const {
        ++ref_count_;
    }
    static bool deallocate(const Node *node) {
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
    Node() : ref_count_(1) { }
    virtual ~Node() { std::cout << "(dtor for Node)" << std::flush; }
    virtual void print(std::ostream &os) const = 0;
    virtual void pretty_print(std::ostream &os, int indent) const = 0;
};

template<typename T>
class AndNode : public Node {
  protected:
    const Belief<T> *belief_;                // belief after action is applied
    const Instance::Action *action_;         // action leading to this node
    std::vector<const OrNode<T>*> children_; // children nodes, one per possible observation after action

  protected:
    virtual int deallocate() const {
        assert(Node::ref_count_ > 0);
        Belief<T>::deallocate(belief_);
        for( size_t i = 0; i < children_.size(); ++i )
            Node::deallocate(children_[i]);
        return --Node::ref_count_;
    }

  public:
    static bool deallocate(const AndNode *node) {
        return Node::deallocate(node);
    }

  public:
    AndNode(const Belief<T> *belief, const Instance::Action *action)
      : belief_(belief), action_(action) {
    }
    AndNode(const T *belief, BeliefRepo<T> &repo, const Instance::Action *action)
      : belief_(repo.get(belief)), action_(action) {
    }
    virtual ~AndNode() {
        std::cout << "(dtor for AndNode)" << std::flush;
    }

    virtual void print(std::ostream &os) const {
        os << "AND[ptr=" << this
           << ",ref=" << Node::ref_count_
           << ",action=" << action_
           << ",children={";
        for( size_t i = 0; i < children_.size(); ++i ) {
            os << children_[i];
            if( i + 1 < children_.size() ) os << ",";
        }
        os << "}]";
    }
    virtual void pretty_print(std::ostream &os, int indent) const {
    }

    const Belief<T>* belief() const {
        return belief_;
    }
    const OrNode<T>* child(int i) const {
        assert((i >= 0) && (i < int(children_.size())));
        return children_[i];
    }
};

template<typename T>
class OrNode : public Node {
  protected:
    const Belief<T> *belief_;        // belief for this node
    const Instance::Action *action_; // action applied at belief (invariant: child_->action_ == action_)
    const AndNode<T> *child_;        // AndNode for belief after action is applied

  protected:
    virtual int deallocate() const {
        assert(Node::ref_count_ > 0);
        Belief<T>::deallocate(belief_);
        Node::deallocate(child_);
        return --Node::ref_count_;
    }

  public:
    static bool deallocate(const OrNode *node) {
        return Node::deallocate(node);
    }

  public:
    OrNode(const Belief<T> *belief, const Instance::Action *action = 0)
      : belief_(belief), action_(action), child_(0) {
    }
    OrNode(const T *belief, BeliefRepo<T> &repo, const Instance::Action *action)
      : belief_(repo.get(belief)), action_(action), child_(0) {
    }
    virtual ~OrNode() {
        std::cout << "(dtor for OrNode)" << std::flush;
    }

    virtual void print(std::ostream &os) const {
        os << "OR[ptr=" << this
           << ",ref=" << Node::ref_count_
           << ",action=" << action_
           << ",child=" << child_
           << "]";
    }
    virtual void pretty_print(std::ostream &os, int indent) const {
    }

    const Belief<T>* belief() const {
        return belief_;
    }
    const AndNode<T>* child() const {
        return child_;
    }
};

#if 0
template<typename T>
class OrNodeRepo : public Repository<T, OrNode<T> > {
};

template<typename T>
class AndNodeRepo : public Repository<T, AndNode<T> > {
};
#endif

template<typename T>
class Policy {
    BeliefRepo<T> &repo_;
    OrNode<T> *root_;

  public:
    Policy(BeliefRepo<T> &repo)
      : repo_(repo), root_(0) {
    }
    virtual ~Policy() {
        deallocate();
    }
    const OrNode<T>* root() const {
        return root_;
    }
    void make_root(const T *belief) {
        Node::deallocate(root_);
        root_ = new OrNode<T>(belief, repo_, 0); // not re-using nodes in policy (i.e. policy is tree not dag)
    }
    void deallocate() {
        if( root_ != 0 ) {
            assert(root_->ref_count() > 0);
            Node::deallocate(root_);
            root_ = 0;
        }
    }
};

}

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

