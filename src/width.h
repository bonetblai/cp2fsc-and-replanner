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

#ifndef WIDTH_H
#define WIDTH_H

#include <cassert>
#include <iostream>
#include "action_selection.h"
#include "utils.h"

#include "and_or_search.h"
#include "features.h"
#include "and_or.h"

namespace Width {

  template<typename T>
  class ActionSelection : public ::ActionSelection<T> {
      const KP_Instance &kp_instance_;
      mutable float total_search_time_;
      mutable float total_time_;
      mutable size_t n_calls_;

    public:
      ActionSelection(const KP_Instance &kp_instance) : kp_instance_(kp_instance) { }
      virtual ~ActionSelection() { }

      virtual const char* name() const { return "width-based-action-selection"; }
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
  class Node : public AndOr::Search::Node {
    protected:
      const T *state_;
      const AndOr::Policy<T> *policy_;
      const Feature *feature_;
      int cost_;

    public:
      Node(const T *state = 0, const AndOr::Policy<T> *policy = 0, const Feature *feature = 0, int cost = 0)
        : state_(state), policy_(policy), feature_(feature), cost_(cost) {
      }
      virtual ~Node() { }
      virtual int f() const {
          std::cout << "Node::f()" << std::endl;
          return cost_;
      }
      virtual void print(std::ostream &os) const {
          os << "N[s=" << state_
             << ",policy=" << policy_
               << ",feature=" << feature_
               << ",cost=" << cost_
             << "]" << std::flush;
      }
  };

  template<typename T>
  class API : public AndOr::Search::API<T> {
    public:
      API() { }
      virtual ~API() { }
      virtual Node<T>* make_root_node(const T *state) const {
          std::cout << "API::make_root_node()" << std::endl;
          return new Node<T>(state);
      }
      virtual bool prune(const AndOr::Search::Node &n) const {
          const Node<T> &node = static_cast<const Node<T>&>(n);
          std::cout << "API::prune(): node=" << node << std::endl;
          return false;
      }
      virtual bool is_goal(const AndOr::Search::Node &n) const {
          const Node<T> &node = static_cast<const Node<T>&>(n);
          std::cout << "API::is_goal(): node=" << node << std::endl;
          return false;
      }
      virtual void expand(const AndOr::Search::Node &n, std::vector<const AndOr::Search::Node*> &successors) const {
          const Node<T> &node = static_cast<const Node<T>&>(n);
          std::cout << "API::expand(): node=" << node << std::endl;
      }
  };

  template<typename T>
  inline int ActionSelection<T>::get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const {
      AndOr::BeliefRepo<T> belief_repo;
      AndOr::Policy<T> policy(belief_repo);
      policy.make_root(&state);
      std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << policy.root() << std::endl;
      std::cout << "BEL=" << *policy.root()->belief() << ", RC=" << policy.root()->ref_count() << std::endl;

      //AndOr::OrNode<T> *root = AndOr::make_root_node(&state);
      //std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << *root << std::endl;
      //AndOr::Node<T>::deallocate(root);

      API<T> api;
      AndOr::Search::bfs<T> bfs(api);
      bfs.search(state);

      std::cout << Utils::error() << "width-based action selection not yet implemented!" << std::endl;
      exit(-1);
  }

} // namespace Width

#endif

