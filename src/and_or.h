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

// this is a wrapper that add ref-counts to instances of T
template<typename T>
class Belief {
  protected:
    mutable int ref_count_;
    const T *belief_;

    // need static repo of beliefs, and methods to clean all beliefs in repo, fetch belief, etc.

  public:
    static void deallocate(const Belief *belief) {
        if( belief != 0 ) {
            assert(belief->ref_count_ > 0);
            if( --belief->ref_count_ == 0 )
                delete belief;
        }
    }

  public:
    Belief(const T *belief = 0) : ref_count_(1), belief_(belief) { }
    ~Belief() { } 

    const Belief* copy() const {
        ++ref_count_;
        return this;
    }
};


template<typename T>
class BeliefRepo {
  public:
    // CHECK: replace this by hash table
    typedef typename std::map<const T*, const Belief<T>*> repo_t;
    typedef typename std::map<const T*, const Belief<T>*>::const_iterator const_iterator_t;

  protected:
    repo_t repo_;

  public:
    BeliefRepo() { }
    ~BeliefRepo() {
        for( const_iterator_t it = repo_.begin(); it != repo_.end(); ++it ) {
            delete it->second;
            //delete it->first; // BE SURE THIS WAS ALLOCATED!
        }
    }

    const Belief<T>* fetch(const T *belief) {
        const_iterator_t it = repo_.find(belief);
        if( it != repo_.end() ) {
            return it->second->copy();
        } else {
            Belief<T> *wrapped = new Belief<T>(belief);
            repo_.insert(std::make_pair(belief, wrapped));
            return wrapped->copy();
        }
    }
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
    void increase_ref_count() const {
        ++ref_count_;
    }
    static void deallocate(const Node *node) {
        if( node != 0 ) {
            assert(node->ref_count_ > 0);
            if( node->deallocate() == 0 ) {
                std::cout << Utils::green() << "[deallocate::delete:" << Utils::normal() << std::flush;
                delete node;
                std::cout << Utils::green() << "]" << Utils::normal() << std::flush;
            }
        }
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
        for( size_t i = 0; i < children_.size(); ++i )
            Node::deallocate(children_[i]);
        return --Node::ref_count_;
    }

  public:
    AndNode(const Belief<T> *belief, const Instance::Action *action = 0)
      : belief_(belief), action_(action) {
    }
    virtual ~AndNode() { std::cout << "(dtor for AndNode)" << std::flush; }
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
};

template<typename T>
class OrNode : public Node {
  protected:
    const Belief<T> *belief_;        // belief for this node
    const Instance::Action *action_; // action applied at belief (invariant: child_->action_ == action_)
    const AndNode<T> *child_;        // AndNode for belief after action is applied

  protected:
    virtual int deallocate() const {
        if( child_ != 0 ) Node::deallocate(child_);
        return --Node::ref_count_;
    }

  public:
    OrNode(const Belief<T> *belief, const Instance::Action *action = 0)
      : belief_(belief), action_(action), child_(0) {
    }
    virtual ~OrNode() { std::cout << "(dtor for OrNode)" << std::flush; }
    virtual void print(std::ostream &os) const {
        os << "OR[ptr=" << this
           << ",ref=" << Node::ref_count_
           << ",action=" << action_
           << ",child=" << child_
           << "]";
    }
    virtual void pretty_print(std::ostream &os, int indent) const {
    }
};

template<typename T>
class Policy {
    BeliefRepo<T> &repo_;
    OrNode<T> *root_;
    // need repo of beliefs, beliefs may be needed to be wrapped within
    // class with ref-counts to avoid making too many copies

  public:
    Policy(BeliefRepo<T> &repo) : repo_(repo), root_(0) { }
    virtual ~Policy() {
        deallocate();
    }
    const OrNode<T>* root() const { return root_; }
    void make_root(const T *belief) {
        Node::deallocate(root_);
        const Belief<T> *root_belief = repo_.fetch(belief);
        root_ = new OrNode<T>(root_belief, 0);
    }
    void deallocate() {
        Node::deallocate(root_);
    }
};

}

inline std::ostream& operator<<(std::ostream &os, const AndOr::Node &node) {
    node.print(os);
    return os;
}

#endif

