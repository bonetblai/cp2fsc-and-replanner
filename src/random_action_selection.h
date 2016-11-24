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
    NaiveRandomActionSelection(const LW1_Instance &lw1_instance)
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

    virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const {
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
};

template<typename T>
class RandomActionSelection : public NaiveRandomActionSelection<T> {
  using NaiveRandomActionSelection<T>::lw1_instance_;
  using NaiveRandomActionSelection<T>::total_search_time_;
  using NaiveRandomActionSelection<T>::total_time_;
  using NaiveRandomActionSelection<T>::n_calls_;

  protected:
    std::unique_ptr<const ::ActionSelection<T> > alternate_selection_;
    mutable bool used_alternate_selection_;

  public:
    RandomActionSelection(const LW1_Instance &lw1_instance, std::unique_ptr<const ::ActionSelection<T> > &alternate_selection)
      : NaiveRandomActionSelection<T>(lw1_instance),
        alternate_selection_(std::move(alternate_selection)) {
    }
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
        const std::vector<LW1_Instance::Variable*> &vars = lw1_instance_.variables_;
        for( size_t var_index = 0; var_index < vars.size(); ++var_index ) {
            const LW1_Instance::Variable &variable = *vars[var_index];
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
        if( alternate_selection_ != 0 )
            str += alternate_selection_->name();
        return str + ")";
    }
    virtual float get_search_time() const {
        return total_search_time_ + (alternate_selection_ != 0 ? alternate_selection_->get_search_time() : 0);
    }
    virtual float get_time() const {
        return total_time_ + (alternate_selection_ != 0 ? alternate_selection_->get_time() : 0);
    }
    virtual size_t n_calls() const {
        return n_calls_ + (alternate_selection_ != 0 ? alternate_selection_->n_calls() : 0);
    }
    virtual void reset_stats() const {
        if( alternate_selection_ != 0 )
            alternate_selection_->reset_stats();
        total_search_time_ = 0;
        total_time_ = 0;
        n_calls_ = 0;
    }

    virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const {
        used_alternate_selection_ = (alternate_selection_ != 0) && is_singleton_belief(state);
        if( used_alternate_selection_ ) {
            return alternate_selection_->get_plan(state, raw_plan, plan);
        } else {
            return NaiveRandomActionSelection<T>::get_plan(state, raw_plan, plan);
        }
    }
};

#undef DEBUG

#endif

