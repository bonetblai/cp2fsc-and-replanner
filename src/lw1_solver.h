#ifndef LW1_SOLVER_H
#define LW1_SOLVER_H

#include <vector>
#include "solver.h"
#include "classical_planner.h"
#include "problem.h"
#include "lw1_problem.h"
#include "state.h"

class LW1_Solver : public Solver {
  public:
    LW1_Solver(const Instance &instance,
               const KP_Instance &kp_instance,
               const ClassicalPlanner &planner,
               int time_bound)
      : Solver(LW1, instance, kp_instance, planner, time_bound) {
    }
    ~LW1_Solver() { }
    virtual int solve(const State &initial_hidden__state,
                      Instance::Plan &final_plan,
                      std::vector<std::set<int> > &fired_sensors,
                      std::vector<std::set<int> > &sensed_literals) const;
  protected:
    typedef std::vector<int> clause_t;
    typedef std::vector<clause_t> cnf_t;;
    typedef std::vector<const cnf_t*> sensing_models_t;
    typedef std::map<int, sensing_models_t> relevant_sensing_models_t;

    void compute_and_add_observations(const State &hidden,
                                      State &state,
                                      std::set<int> &sensors,
                                      std::set<int> &sensed) const;

    void apply_inference(const Instance::Action *action,
                         const std::set<int> &sensed,
                         State &state) const;

    void fill_relevant_sensing_models(const LW1_Instance &lw1,
                                      const Instance::Action *last_action,
                                      const std::set<int> &sensed,
                                      relevant_sensing_models_t &sensing_models) const;

    void calculate_relevant_assumptions(const Instance::Plan &plan,
                                        const Instance::Plan &raw_plan,
                                        const State &initial_state,
                                        const index_set &goal,
                                        std::vector<index_set> &assumptions) const;

    bool inconsistent(const State &state, const std::vector<State> &assumptions, size_t k) const;
};

#endif

