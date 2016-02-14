#include "Inference.h"

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
               int time_bound,
               int ncalls_bound)
      : BASE_CLASS(LW1, instance, kp_instance, planner, time_bound, ncalls_bound) {
    }
    ~LW1_Solver() { }

    virtual void initialize(const KP_Instance &kp);
    virtual void clean_cnf() const;

    virtual int solve(const STATE_CLASS &initial_hidden_state,
                      Instance::Plan &final_plan,
                      std::vector<std::set<int> > &fired_sensors_during_execution,
                      std::vector<std::set<int> > &sensed_literals_during_execution) const {
        return BASE_CLASS::solve(initial_hidden_state,
                                 final_plan,
                                 fired_sensors_during_execution,
                                 sensed_literals_during_execution);
    }

    Inference::Propositional::CNF getCNF() const { return cnf; }

    // This is kept for the AC3 algorithm. It relates an atom index to its
    // corresponding variable. Public as of now
    // TODO: Make this protected
    typedef std::map<int, int> atoms_to_vars_map_t;
    atoms_to_vars_map_t atoms_to_vars_;

  protected:
    typedef std::vector<int> clause_or_term_t;
    typedef std::vector<clause_or_term_t> cnf_or_dnf_t;
    typedef std::vector<const cnf_or_dnf_t*> sensing_models_as_cnf_or_dnf_t;
    typedef std::map<int, std::map<int, sensing_models_as_cnf_or_dnf_t> > relevant_sensing_models_t;

    // A CNF is kept internally by the solver.
    // It is filled in initialize and it is completed in every iteration of 
    // apply_inference.
    // TODO: Make this safe. 
    mutable Inference::Propositional::CNF cnf;
    set<Inference::Propositional::Clause> base_theory_axioms;
    size_t frontier = 0;


    virtual void compute_and_add_observations(const Instance::Action *last_action,
                                              const STATE_CLASS &hidden,
                                              STATE_CLASS &state,
                                              std::set<int> &fired_sensors_at_step,
                                              std::set<int> &sensed_at_step) const;

    virtual void apply_inference(const Instance::Action *action,
                                 const std::set<int> &sensed_at_step,
                                 STATE_CLASS &state) const;

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

    bool value_observable_literal(const STATE_CLASS &hidden,
                                  const Instance::Action &last_action,
                                  int var_index,
                                  int index) const;

    void update_state_with_literals_for_observables(STATE_CLASS &state,
                                                    const Instance::Action &action,
                                                    const LW1_Instance::Variable &variable,
                                                    int value) const;

    void fill_relevant_sensing_models(const LW1_Instance &lw1,
                                      const Instance::Action *last_action,
                                      const std::set<int> &sensed_at_step,
                                      relevant_sensing_models_t &relevant_sensing_models,
                                      bool as_k_cnf = true) const;

    bool is_forbidden(int literal) const;
    bool is_forbidden(const clause_or_term_t &clause) const;
    void fill_atoms_to_var_map(const LW1_Instance &lw1);
};

#endif

