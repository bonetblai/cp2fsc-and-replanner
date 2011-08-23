#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "classical_planner.h"
#include "problem.h"
#include "kp_problem.h"
#include "state.h"

class Solver {
  public:
    enum { SOLVED = 0, NO_SOLUTION = 1, TIME = 2, ERROR = 3 };
  protected:
    const Instance &instance_;
    const KP_Instance &kp_instance_;
    const ClassicalPlanner &planner_;
    const int time_bound_;
    const Options::Mode options_;
  public:
    Solver(const Instance &instance,
           const KP_Instance &kp_instance,
           const ClassicalPlanner &planner,
           int time_bound)
      : instance_(instance), kp_instance_(kp_instance),
        planner_(planner), time_bound_(time_bound),
        options_(instance.options_) {
    }
    ~Solver() { }
    bool solve(const State &initial_hidden__state, std::vector<int> &final_plan) const;
    void compute_and_add_observations(State &hidden, State &state) const;
    void calculate_relevant_assumptions(const Instance::Plan &plan, const State &state, std::vector<State> &assumption_vec) const;
    bool inconsistent(const State &state, const std::vector<State> &assumption_vec, size_t k) const;
};

#endif

