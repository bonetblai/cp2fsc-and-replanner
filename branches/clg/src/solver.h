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
    const Options::Mode &options_;
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
    int solve(const State &initial_hidden__state,
              Instance::Plan &final_plan,
              std::vector<std::vector<int> > &fired_sensors,
              std::vector<std::vector<int> > &sensed_literals) const;
    void compute_and_add_observations(const State &hidden,
                                      State &state,
                                      std::vector<int> &sensors,
                                      std::vector<int> &sensed) const;
    void calculate_relevant_assumptions(const Instance::Plan &plan,
                                        const Instance::Plan &raw_plan,
                                        const State &initial_state,
                                        const index_set &goal,
                                        std::vector<index_set> &assumptions) const;
    bool inconsistent(const State &state, const std::vector<State> &assumptions, size_t k) const;
};

#endif

