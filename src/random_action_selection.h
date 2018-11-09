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

#ifndef RANDOM_ACTION_SELECTION_H
#define RANDOM_ACTION_SELECTION_H

#include <cassert>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

#include "action_selection.h"
#include "lw1_problem.h"
#include "utils.h"

//#define DEBUG

template<typename T>
class NaiveRandomActionSelection : public ::ActionSelection<T> {
  protected:
    const LW1_Instance &lw1_instance_;

    mutable float total_search_time_;
    mutable float total_time_;
    mutable size_t n_calls_;

  public:
    NaiveRandomActionSelection(const LW1_Instance &lw1_instance, const std::map<std::string, std::string> &options)
      : lw1_instance_(lw1_instance) {
    }
    virtual ~NaiveRandomActionSelection() { }

    virtual std::string name() const { return std::string("naive-random-action-selection"); }
    virtual float get_search_time() const { return total_search_time_; }
    virtual float get_time() const { return total_time_; }
    virtual size_t n_calls() const { return n_calls_; }
    virtual void reset_stats() const {
        total_search_time_ = 0;
        total_time_ = 0;
        n_calls_ = 0;
    }

    virtual int get_plan(const T &state,
                         Instance::Plan &plan,
                         Instance::Plan &raw_plan,
                         std::vector<const T*> &sampled_state_trajectory) const {
        assert(sampled_state_trajectory.empty());
        float start_time = Utils::read_time_in_seconds();

        // compute applicable actions at state
        std::vector<int> indices_for_applicable_actions;
        for( size_t k = 0; k < lw1_instance_.actions_.size(); ++k ) {
            if( (lw1_instance_.remap_action(k) == -1) && !lw1_instance_.is_subgoaling_rule(k) ) continue;
            const Instance::Action &action = *lw1_instance_.actions_[k];
            assert(lw1_instance_.is_regular_action(k));
            if( state.applicable(action) )
                indices_for_applicable_actions.push_back(k);
        }

        // select one random applicable action
#ifdef DEBUG
        std::cout << Utils::magenta() << "#indices=" << indices_for_applicable_actions.size() << Utils::normal() << std::endl;
#endif
        int status = 0;
        if( !indices_for_applicable_actions.empty() ) {
            int random_action = indices_for_applicable_actions[lrand48() % indices_for_applicable_actions.size()];
            raw_plan.clear();
            plan.clear();
            plan.push_back(random_action);
            raw_plan.push_back(random_action);
#ifdef DEBUG
            std::cout << Utils::magenta() << "random-action=" << lw1_instance_.actions_[random_action]->name_ << Utils::normal() << std::endl;
#endif
            status = ActionSelection<T>::SOLVED;
        } else {
            status = ActionSelection<T>::NO_SOLUTION;
        }
        float elapsed_time = Utils::read_time_in_seconds() - start_time;
        total_search_time_ += elapsed_time;
        total_time_ += elapsed_time;
        return status;
    }

    virtual void calculate_assumptions(const NewSolver<T> &solver,
                                       const T &state,
                                       const Instance::Plan &plan,
                                       const Instance::Plan &raw_plan,
                                       const std::vector<const T*> &sampled_state_trajectory,
                                       const index_set &goal,
                                       std::vector<index_set> &assumptions) const {
        assert(sampled_state_trajectory.empty());
        assumptions.push_back(index_set());
    }
};

template<typename T>
class RandomActionSelection : public NaiveRandomActionSelection<T> {
  using NaiveRandomActionSelection<T>::lw1_instance_;
  using NaiveRandomActionSelection<T>::total_search_time_;
  using NaiveRandomActionSelection<T>::total_time_;
  using NaiveRandomActionSelection<T>::n_calls_;

  protected:
#ifdef SMART
    std::unique_ptr<const ::ActionSelection<T> > alternate_selection_;
#else
    const ::ActionSelection<T> *alternate_selection_;
#endif
    mutable bool used_alternate_selection_;

  public:
#ifdef SMART
    RandomActionSelection(const LW1_Instance &lw1_instance,
                          std::unique_ptr<const ::ActionSelection<T> > &&alternate_selection,
                          std::map<std::string, std::string> &options)
      : NaiveRandomActionSelection<T>(lw1_instance, options),
        alternate_selection_(std::move(alternate_selection)) {
    }
#else
    RandomActionSelection(const LW1_Instance &lw1_instance,
                          const ::ActionSelection<T> *alternate_selection,
                          std::map<std::string, std::string> &options)
      : NaiveRandomActionSelection<T>(lw1_instance, options),
        alternate_selection_(alternate_selection) {
    }
#endif
    virtual ~RandomActionSelection() { }

    const ::ActionSelection<T>* alternate_selection() const {
        return alternate_selection_;
    }
    bool used_alternate_selection() const {
        return used_alternate_selection_;
    }

    bool is_singleton_belief(const T &state) const {
        float start_time = Utils::read_time_in_seconds();

        // need to check that each LW1 state variable is instantiated
        for( size_t var_index = 0; var_index < lw1_instance_.variables_.size(); ++var_index ) {
            const LW1_Instance::Variable &variable = *lw1_instance_.variables_[var_index];
            if( variable.is_state_variable() ) {
                // iterate over domain of variable to check whether is instantiated
                bool is_instantiated = false;
                for( std::set<int>::const_iterator it = variable.domain().begin(); it != variable.domain().end(); ++it ) {
                    int k_literal = 2 * *it;
                    if( state.satisfy(k_literal) ) {
                        is_instantiated = true;
                        break;
                    }
                }
                if( !is_instantiated ) {
                    float elapsed_time = Utils::read_time_in_seconds() - start_time;
                    total_search_time_ += elapsed_time;
                    total_time_ += elapsed_time;
                    return false;
                }
            }
        }
        float elapsed_time = Utils::read_time_in_seconds() - start_time;
        total_search_time_ += elapsed_time;
        total_time_ += elapsed_time;
        return true;
    }

    virtual std::string name() const {
        std::string str = std::string("random-action-selection(");
        if( alternate_selection_ != nullptr )
            str += alternate_selection_->name();
        return str + ")";
    }
    virtual float get_search_time() const {
        return total_search_time_ + (alternate_selection_ != nullptr ? alternate_selection_->get_search_time() : 0);
    }
    virtual float get_time() const {
        return total_time_ + (alternate_selection_ != nullptr ? alternate_selection_->get_time() : 0);
    }
    virtual size_t n_calls() const {
        return n_calls_ + (alternate_selection_ != nullptr ? alternate_selection_->n_calls() : 0);
    }
    virtual void reset_stats() const {
        if( alternate_selection_ != nullptr )
            alternate_selection_->reset_stats();
        total_search_time_ = 0;
        total_time_ = 0;
        n_calls_ = 0;
    }

    virtual int get_plan(const T &state,
                         Instance::Plan &plan,
                         Instance::Plan &raw_plan,
                         std::vector<const T*> &sampled_state_trajectory) const {
        assert(sampled_state_trajectory.empty());
        used_alternate_selection_ = (alternate_selection_ != nullptr) && is_singleton_belief(state);
        if( used_alternate_selection_ ) {
            return alternate_selection_->get_plan(state, plan, raw_plan, sampled_state_trajectory);
        } else {
            return NaiveRandomActionSelection<T>::get_plan(state, plan, raw_plan, sampled_state_trajectory);
        }
    }

    virtual void calculate_assumptions(const NewSolver<T> &solver,
                                       const T &state,
                                       const Instance::Plan &plan,
                                       const Instance::Plan &raw_plan,
                                       const std::vector<const T*> &sampled_state_trajectory,
                                       const index_set &goal,
                                       std::vector<index_set> &assumptions) const {
        assert(sampled_state_trajectory.empty());
        if( used_alternate_selection() )
            solver.calculate_relevant_assumptions(plan, raw_plan, state, goal, assumptions);
        else
            assumptions.push_back(index_set());
    }
};

#undef DEBUG

#endif

