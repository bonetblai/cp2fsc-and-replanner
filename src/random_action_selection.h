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
#include <vector>

#include "action_selection.h"
#include "lw1_problem.h"
#include "utils.h"

//#define DEBUG

template<typename T>
class RandomActionSelection : public ::ActionSelection<T> {
    const LW1_Instance &lw1_instance_;

    mutable float total_search_time_;
    mutable float total_time_;
    mutable size_t n_calls_;

  public:
    RandomActionSelection(const LW1_Instance &lw1_instance)
      : lw1_instance_(lw1_instance) {
    }
    virtual ~RandomActionSelection() { }

    virtual const char* name() const { return "random-action-selection"; }
    virtual float get_search_time() const { return total_search_time_; }
    virtual float get_time() const { return total_time_; }
    virtual size_t n_calls() const { return n_calls_; }
    virtual void reset_stats() const {
        total_search_time_ = 0;
        total_time_ = 0;
        n_calls_ = 0;
    }

    virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const {
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
        if( !indices_for_applicable_actions.empty() ) {
            int random_action = indices_for_applicable_actions[lrand48() % indices_for_applicable_actions.size()];
            raw_plan.clear();
            plan.clear();
            plan.push_back(random_action);
            raw_plan.push_back(random_action);
#ifdef DEBUG
            std::cout << Utils::magenta() << "random-action=" << lw1_instance_.actions_[random_action]->name_ << Utils::normal() << std::endl;
#endif
            return ActionSelection<T>::SOLVED;
        } else {
            return ActionSelection<T>::NO_SOLUTION;
        }
    }
};

#undef DEBUG

#endif

