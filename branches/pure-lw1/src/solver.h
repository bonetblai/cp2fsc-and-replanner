#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "classical_planner.h"
#include "problem.h"
#include "kp_problem.h"
#include "state.h"

class Solver {
  public:
    enum { SOLVED = 0, NO_SOLUTION = 1, TIME = 2, NCALLS = 3, ERROR = 4 };
    enum { K_REPLANNER = 0, CLG = 1, LW1 = 2 };
  protected:
    const int translation_type_;
    const Instance &instance_;
    const KP_Instance &kp_instance_;
    const ClassicalPlanner &planner_;
    const int time_bound_;
    const int ncalls_bound_;
    const Options::Mode &options_;
  public:
    Solver(int translation_type,
           const Instance &instance,
           const KP_Instance &kp_instance,
           const ClassicalPlanner &planner,
           int time_bound,
           int ncalls_bound)
      : translation_type_(translation_type),
        instance_(instance), kp_instance_(kp_instance), planner_(planner),
        time_bound_(time_bound), ncalls_bound_(ncalls_bound),
        options_(instance.options_) {
    }
    virtual ~Solver() { }

    virtual int solve(const State &initial_hidden_state,
                      Instance::Plan &final_plan,
                      std::vector<std::set<int> > &fired_sensors_during_execution,
                      std::vector<std::set<int> > &sensed_literals_during_execution) const;
  protected:
    virtual void compute_and_add_observations(const Instance::Action *last_action,
                                              const State &hidden,
                                              State &state,
                                              std::set<int> &fired_sensors_at_step,
                                              std::set<int> &sensed_at_step) const;

    virtual void apply_inference(const Instance::Action *action,
                                 const std::set<int> &sensed_at_step,
                                 State &state) const;

    virtual void calculate_relevant_assumptions(const Instance::Plan &plan,
                                                const Instance::Plan &raw_plan,
                                                const State &initial_state,
                                                const index_set &goal,
                                                std::vector<index_set> &assumptions) const;

    virtual bool inconsistent(const State &state, const std::vector<State> &assumptions, size_t k) const;

  protected:
    void progress(const Instance::Plan &plan,
                  const State &initial_state,
                  const State &final_state) const;

    void regress(const Instance::Action &action,
                 const State &prev,
                 const State &next,
                 index_set &assumptions) const;
};

#endif

