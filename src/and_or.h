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
#include "utils.h"

namespace AndOr {

// forward references
template<typename T> class AndNode;
template<typename T> class OrNode;

template<typename T>
class Node {
  protected:
    mutable int ref_count_;

  protected:
    virtual int deallocate() const = 0;

  public:
    void increase_ref_count() const {
        ++ref_count_;
    }
    static void deallocate(const Node<T> *node) {
        assert(node != 0);
        assert(node->ref_count_ > 0);
        if( node->deallocate() == 0 ) {
            std::cout << Utils::green() << "[deallocate::delete:" << Utils::normal() << std::flush;
            delete node;
            std::cout << Utils::green() << "]" << Utils::normal() << std::flush;
        }
    }

  public:
    Node() : ref_count_(1) { }
    virtual ~Node() { std::cout << "(ctor for Node)" << std::flush; }
    virtual void print(std::ostream &os) const = 0;
    virtual void pretty_print(std::ostream &os, int indent) const = 0;
};

template<typename T>
class AndNode : public Node<T> {
  protected:
    const T *belief_;                        // belief after action is applied
    const Instance::Action *action_;         // action leading to this node
    std::vector<const OrNode<T>*> children_; // children nodes, one per possible observation after action

  protected:
    virtual int deallocate() const {
        for( size_t i = 0; i < children_.size(); ++i )
            Node<T>::deallocate(children_[i]);
        return --Node<T>::ref_count_;
    }

  public:
    AndNode(const T *belief, const Instance::Action *action = 0)
      : belief_(belief), action_(action) {
    }
    virtual ~AndNode() { std::cout << "(ctor for AndNode)" << std::flush; }
    virtual void print(std::ostream &os) const {
        os << "AND[ptr=" << this
           << ",ref=" << Node<T>::ref_count_
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
class OrNode : public Node<T> {
  protected:
    const T *belief_;                // belief for this node
    const Instance::Action *action_; // action applied at belief (invariant: child_->action_ == action_)
    const AndNode<T> *child_;        // AndNode for belief after action is applied

  protected:
    virtual int deallocate() const {
        if( child_ != 0 ) Node<T>::deallocate(child_);
        return --Node<T>::ref_count_;
    }

  public:
    OrNode(const T *belief, const Instance::Action *action = 0)
      : belief_(belief), action_(action), child_(0) {
    }
    virtual ~OrNode() { std::cout << "(ctor for OrNode)" << std::flush; }
    virtual void print(std::ostream &os) const {
        os << "OR[ptr=" << this
           << ",ref=" << Node<T>::ref_count_
           << ",action=" << action_
           << ",child=" << child_
           << "]";
    }
    virtual void pretty_print(std::ostream &os, int indent) const {
    }
};

template<typename T>
inline OrNode<T>* make_root_node(const T *belief) {
    return new OrNode<T>(belief, 0);
}

}

template<typename T>
inline std::ostream& operator<<(std::ostream &os, const AndOr::Node<T> &node) {
    node.print(os);
    return os;
}

#endif

