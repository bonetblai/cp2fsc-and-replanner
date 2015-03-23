#ifndef LW1_SOLVER_H
#define LW1_SOLVER_H

// We are currently using the Solver class as base class. In the near
// future we'll change to the templatized NewSolver class to allow
// solvers with different state classes. Once the migration is complete,
// solver.{cc,h} will dissapear and new_solver.h will become solver.h

#define BASE_SELECTOR 1 // 0 for Solver, 1 for NewSolver<LW1_State>

#if BASE_SELECTOR == 0
#    define STATE_CLASS State
#    define BASE_CLASS Solver
#    include "solver.h"
#endif

#if BASE_SELECTOR == 1
#    define STATE_CLASS LW1_State
#    define BASE_CLASS NewSolver<STATE_CLASS>
#    include "new_solver.h"
#    include "lw1_state.h"
#endif

#include <vector>
#include "classical_planner.h"
#include "problem.h"
#include "lw1_problem.h"
#include "state.h"

class LW1_Solver : public BASE_CLASS {
  public:
    LW1_Solver(const Instance &instance,
               const KP_Instance &kp_instance,
               const ClassicalPlanner &planner,
               int time_bound)
      : BASE_CLASS(LW1, instance, kp_instance, planner, time_bound) {
    }
    ~LW1_Solver() { }

    virtual int solve(const STATE_CLASS &initial_hidden_state,
                      Instance::Plan &final_plan,
                      std::vector<std::set<int> > &fired_sensors,
                      std::vector<std::set<int> > &sensed_literals) const {
        return BASE_CLASS::solve(initial_hidden_state,
                                 final_plan,
                                 fired_sensors,
                                 sensed_literals);
    }

  protected:
    typedef std::vector<int> clause_t;
    typedef std::vector<clause_t> cnf_t;
    typedef std::vector<const cnf_t*> sensing_models_t;
    typedef std::map<int, sensing_models_t> relevant_sensing_models_t;

    virtual void compute_and_add_observations(const STATE_CLASS &hidden,
                                              STATE_CLASS &state,
                                              std::set<int> &sensors,
                                              std::set<int> &sensed) const;

    virtual void apply_inference(const Instance::Action *action,
                                 const std::set<int> &sensed,
                                 STATE_CLASS &state) const;

    virtual void fill_relevant_sensing_models(const LW1_Instance &lw1,
                                              const Instance::Action *last_action,
                                              const std::set<int> &sensed,
                                              relevant_sensing_models_t &sensing_models) const;

    virtual void calculate_relevant_assumptions(const Instance::Plan &plan,
                                                const Instance::Plan &raw_plan,
                                                const STATE_CLASS &initial_state,
                                                const index_set &goal,
                                                std::vector<index_set> &assumptions) const {
        BASE_CLASS::calculate_relevant_assumptions(plan,
                                                   raw_plan,
                                                   initial_state,
                                                   goal,
                                                   assumptions);
    }

    virtual bool inconsistent(const STATE_CLASS &state, const std::vector<STATE_CLASS> &assumptions, size_t k) const {
        return BASE_CLASS::inconsistent(state, assumptions, k);
    }

    bool is_forbidden(int literal) const;
    bool is_forbidden(const clause_t &clause) const;
};

#endif

