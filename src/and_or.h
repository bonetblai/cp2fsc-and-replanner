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
#include <string>
#include <vector>

#include "and_or_search_api.h"
#include "features.h"
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
      static bool deallocate(const Belief *belief) {
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
          std::cout << "(dtor for Belief)" << std::flush;
      }

      const T* belief() const {
          return belief_;
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

    protected:
      virtual int deallocate() const = 0;

    public:
      int ref_count() const {
          return ref_count_;
      }
      int increase_ref_count() const {
          return ++ref_count_;
      }
      const Node* copy() const {
          ++ref_count_;
          return this;
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
      const Instance::Action *action_;         // action leading to this node
      const Belief<T> *belief_;                // belief after action is applied
      std::vector<const OrNode<T>*> children_; // children nodes, one per possible observation after action

    protected:
      virtual int deallocate() const {
          if( --Node::ref_count_ == 0 ) {
              Belief<T>::deallocate(belief_);
              for( size_t i = 0; i < children_.size(); ++i )
                  Node::deallocate(children_[i]);
          }
          return ref_count_;
      }

    public:
      static bool deallocate(const AndNode *node) {
          return Node::deallocate(node);
      }

    public:
      AndNode(const Instance::Action *action, const Belief<T> *belief)
        : action_(action), belief_(belief) {
      }
      AndNode(const Instance::Action *action, const T *belief, BeliefRepo<T> &repo)
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
          // CHECK: FILL MISSING CODE
      }

      const Belief<T>* belief() const {
          return belief_;
      }
      const OrNode<T>* child(int i) const {
          assert((i >= 0) && (i < int(children_.size())));
          return children_[i];
      }
      void add_child(const OrNode<T> *child) {
          children_.push_back(child);
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
          if( --Node::ref_count_ == 0) {
              Belief<T>::deallocate(belief_);
              Node::deallocate(child_);
          }
          return ref_count_;
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
          // CHECK: FILL MISSING CODE
      }

      const Belief<T>* belief() const {
          return belief_;
      }
      const AndNode<T>* child() const {
          return child_;
      }
  };

  template<typename T>
  class OrNodeList : public std::vector<const OrNode<T>*> {
  };

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

  template<typename T>
  class Policy {
    protected:
      BeliefRepo<T> &repo_;
      const OrNode<T> *root_;
      OrNodeRepo<T> or_repo_;
      OrNodeList<T> tip_nodes_;

      void make_empty_policy(const T *belief) {
          assert(belief != 0);
          tip_nodes_.clear();
          Node::deallocate(root_);
          const Belief<T> *root_belief = repo_.get(belief);
          root_ = or_repo_.get(root_belief);//new OrNode<T>(belief, repo_, 0); // not re-using nodes in policy (i.e. policy is tree not dag)
          tip_nodes_.push_back(root_);
      }

    public:
      Policy(BeliefRepo<T> &repo, const T *belief)
        : repo_(repo), root_(0) {
          make_empty_policy(belief);
      }
      virtual ~Policy() {
          deallocate();
      }

      const OrNode<T>* root() const {
          return root_;
      }
      void deallocate() {
          if( root_ != 0 ) {
              assert(root_->ref_count() > 0);
              Node::deallocate(root_);
              root_ = 0;
          }
      }
      const OrNodeList<T>& tip_nodes() const {
          return tip_nodes_;
      }

      int cost() const {
          std::cout << Utils::magenta() << "Policy<T>::cost()" << Utils::normal() << std::endl;
          // CHECK: FILL MISSING CODE
          return 0;
      }

#if 0
      std::pair<const Policy*, int> compute_extension_for(const Search::API<T> &api, const Width::Feature<T> *feature) const {
          std::cout << Utils::magenta() << "Policy<T>::compute_extension_for()" << Utils::normal() << std::endl;
          // CHECK: FILL MISSING CODE
          // for each tip node, search for an action that once applied achieves the given feature
          bool feature_is_achieved = true;
          for( typename OrNodeList<T>::const_iterator it = tip_nodes_.begin(); it != tip_nodes_.end(); ++it ) {
              const T &tip = *(*it)->belief()->belief();
              std::cout << Utils::blue() << "TIP=" << Utils::normal();
              tip.print(std::cout, &api.lw1_instance());
              std::cout << std::endl;

              // iterate over applicable actions at belief
              int num_applicable_actions = 0;
              for( size_t i = 0; i < api.lw1_instance().actions_.size(); ++i ) {
                  if( (api.lw1_instance().remap_action(i) == -1) && !api.lw1_instance().is_subgoaling_rule(i) ) continue;
                  const Instance::Action &action = *api.lw1_instance().actions_[i];
                  assert(api.lw1_instance().is_regular_action(i));
                  if( tip.applicable(action) ) {
                      ++num_applicable_actions;
                      std::cout << Utils::red() << "action=" << Utils::normal() << action.name_ << std::endl;

                      // calculate result of action
                      T result_after_action(tip);
                      result_after_action.apply(action);

                      std::cout << Utils::blue() << "RESULT=" << Utils::normal();
                      result_after_action.print(std::cout, &api.lw1_instance());
                      std::cout << std::endl;

                      // generate successor beliefs considering possible observations.
                      // Feature is achieved iff it is achieved in all successor beliefs
                      bool feature_is_achieved_in_tip = true;
                      std::vector<std::set<int> > possible_observations;
                      //compute_possible_observations(api, action, result_after_action, possible_observations);
                      std::cout << Utils::green() << "#possible-obs=" << possible_observations.size() << Utils::normal() << std::endl;
                      for( size_t j = 0; j < possible_observations.size(); ++j ) {
                          assert(!possible_observations[j].empty());
                          const std::set<int> obs = possible_observations[j];
                          T result_after_action_and_obs(result_after_action);

                          // need to resolve dependency issue:
                          //   -- apply_inference is defined in lw1_solver which is subclass of new_solver
                          //   -- new_solver is instantiate with an action_selection mechanism
                          //   -- so, we have circular dependency
                          //apply_inference(&action, obs, result_after_action_and_obs);

                      }


#if 0
                      // if action is standard action, insert it into plan, apply it at
                      // hidden state and gather observations (if any)
                      if( !kp_instance_.is_subgoaling_rule(kp_act.index_) ) {
                          size_t action_id = kp_instance_.remap_action(plan[k]);
                          final_plan.push_back(action_id);
                          const Instance::Action &act = *instance_.actions_[action_id];

                          hidden.apply(act);
                          //instance_.apply_deductive_rules(hidden); // CHECK
                          compute_and_add_observations(&kp_act, hidden, state, fired_sensors_at_step, sensed_at_step);
                          if( (translation_type_ != LW1) || !sensed_at_step.empty() )
                              apply_inference(&kp_act, sensed_at_step, state);
                          fired_sensors_during_execution.push_back(fired_sensors_at_step);
                          sensed_literals_during_execution.push_back(sensed_at_step);
                          fired_sensors_at_step.clear();
                          sensed_at_step.clear();
                      }
#endif
                  }
              }
              std::cout << Utils::green() << "#applicable actions=" << num_applicable_actions << Utils::normal() << std::endl;
          }
          exit(0);

          if( !feature_is_achieved ) {
              return std::make_pair(static_cast<const Policy*>(0), 0);
          } else {
              // return extension that achieves feature
              return std::make_pair(static_cast<const Policy*>(0), 0);
          }
      }
#endif
  };

  template<typename T>
  inline AndNode<T>* create_and_node(const Instance::Action *action, const T *bel_a, std::vector<const T*> &successors) {
      const Belief<T> *belief_a = new Belief<T>(bel_a);
      AndNode<T> *node = new AndNode<T>(action, belief_a);
      for( size_t k = 0; k < successors.size(); ++k ) {
          const Belief<T> *belief_ao = new Belief<T>(successors[k]);
          OrNode<T> *child = new OrNode<T>(belief_ao);
          node->add_child(child);
      }
      return node;
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

