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

// testing
#include "and_or.h"
#include "features.h"

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

    virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const {
<<<<<<< HEAD
        AndOr::BeliefRepo<T> *belief_repo = new AndOr::BeliefRepo<T>;
        AndOr::Policy<T> policy(*belief_repo);
        policy.make_root(&state);
        std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << policy.root() << std::endl;
        policy.deallocate();
        delete belief_repo;
        std::cout << Utils::error() << "width-based planner not yet implemented!" << std::endl;
=======
        AndOr::OrNode<T> *root = AndOr::make_root_node(&state);
        std::cout << Utils::magenta() << "THIS IS A TEST: " << Utils::normal() << *root << std::endl;
        AndOr::Node<T>::deallocate(root);
        std::cout << Utils::error() << "width-based action selection not yet implemented!" << std::endl;
>>>>>>> 899aa376dc4535434fd4455fda82b8f835bdfdee
        exit(-1);
    }
};

}

#endif

