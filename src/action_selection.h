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

#ifndef ACTION_SELECTION_H
#define ACTION_SELECTION_H

#include <cassert>
#include <iostream>
#include "problem.h"
#include "kp_problem.h"
#include "utils.h"

template<typename T> class ActionSelection {
  public:
    ActionSelection() { }
    virtual ~ActionSelection() { }

    enum { SOLVED = 0, NO_SOLUTION = 1, ERROR = 2 };

    virtual const char* name() const = 0;
    virtual float get_search_time() const = 0;
    virtual float get_time() const = 0;
    virtual size_t n_calls() const = 0;
    virtual void reset_stats() const = 0;
    virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const = 0;
};

#endif

