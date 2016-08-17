#ifndef WIDTH_H
#define WIDTH_H

#include <cassert>
#include <iostream>
#include "action_selection.h"

template<typename T>
class WidthBasedPlanner : public ActionSelection<T> {
    const KP_Instance &kp_instance_;
    mutable float total_search_time_;
    mutable float total_time_;
    mutable size_t n_calls_;

  public:
    WidthBasedPlanner(const KP_Instance &kp_instance) : kp_instance_(kp_instance) { }
    virtual ~WidthBasedPlanner() { }

    virtual const char* name() const { return "width-based-planner"; }
    virtual float get_search_time() const { return total_search_time_; }
    virtual float get_time() const { return total_time_; }
    virtual size_t n_calls() const { return n_calls_; }
    virtual void reset_stats() const {
        total_search_time_ = 0;
        total_time_ = 0;
        n_calls_ = 0;
    }

    virtual int get_plan(const T &state, Instance::Plan &raw_plan, Instance::Plan &plan) const {
        std::cout << Utils::error() << "width-based planner not yet implemented!" << std::endl;
        exit(-1);
    }
};

#endif

