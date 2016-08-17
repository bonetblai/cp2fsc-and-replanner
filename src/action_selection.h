#ifndef ACTION_SELECTION_H
#define ACTION_SELECTION_H

#include "problem.h"
#include "kp_problem.h"
#include "utils.h"
#include <cassert>
#include <iostream>

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

