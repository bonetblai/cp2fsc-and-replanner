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

#ifndef CLASSICAL_PLANNER_WRAPPER_H
#define CLASSICAL_PLANNER_WRAPPER_H

#include <cassert>
#include <iostream>
#include "action_selection.h"
#include "classical_planner.h"

template<typename T>
class ClassicalPlannerWrapper : public ActionSelection<T> {
    const ClassicalPlanner &planner_;
  public:
    ClassicalPlannerWrapper(const ClassicalPlanner &planner) : planner_(planner) { }
    virtual ~ClassicalPlannerWrapper() { }

    virtual const char* name() const {
        return planner_.name();
    }
    virtual float get_search_time() const {
        return planner_.get_search_time();
    }
    virtual float get_time() const {
        return planner_.get_time();
    }
    virtual size_t n_calls() const {
        return planner_.n_calls();
    }
    virtual void reset_stats() const {
        planner_.reset_stats();
    }
    virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const {
        int status = planner_.get_plan(state, raw_plan, plan);
        if( status == ClassicalPlanner::SOLVED ) {
            return ActionSelection<T>::SOLVED;
        } else if( status == ClassicalPlanner::NO_SOLUTION ) {
            return ActionSelection<T>::NO_SOLUTION;
        } else {
            assert(status == ClassicalPlanner::ERROR);
            return ActionSelection<T>::ERROR;
        }
    }
};

#endif

