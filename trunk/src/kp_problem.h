#ifndef KP_PROBLEM_H
#define KP_PROBLEM_H

#include "problem.h"
#include "base.h"
#include "options.h"
#include <string>

class KP_Instance : public Instance {
  public:
    const Instance &po_instance_;
    size_t n_standard_actions_;
    size_t n_sensor_actions_;
    size_t n_invariant_actions_;
    size_t n_subgoaling_actions_;

    // maps standard actions in kp-problem into standard actions in po problem
    std::vector<int> remap_;
    std::map<std::string, int> obs_rules_by_name_;

    // for subgoaling
    Atom *new_goal_;
    size_t index_for_goal_action_;
    std::vector<Atom*> atoms_for_unknown_observables_at_init_;

    KP_Instance(const Instance &instance, const PDDL_Base::variable_vec &multivalued_variables);
    ~KP_Instance();

    virtual void cross_reference();

    size_t first_deductive_action() const { return n_standard_actions_ + n_sensor_actions_; }
    size_t last_deductive_action() const { return first_deductive_action() + n_invariant_actions_; }
    bool is_obs_rule(const std::string &name) const {
        return obs_rules_by_name_.find(name) != obs_rules_by_name_.end();
    }
    bool is_regular_action(size_t a) const {
        return (a < n_standard_actions_) || is_subgoaling_rule(a);
    }
    bool is_obs_rule(size_t a) const {
        size_t lower = n_standard_actions_;
        size_t upper = lower + n_sensor_actions_;
        return (a >= lower) && (a < upper);
    }
    bool is_static_rule(size_t a) const {
        size_t lower = n_standard_actions_ + n_sensor_actions_;
        size_t upper = lower + n_invariant_actions_;
        return (a >= lower) && (a < upper);
    }
    bool is_subgoaling_rule(size_t a) const {
        size_t lower = n_standard_actions_ + n_sensor_actions_ + n_invariant_actions_;
        size_t upper = lower + n_subgoaling_actions_;
        return (a >= lower) && (a < upper);
    }
    bool is_goal_action(size_t a) const { return a == index_for_goal_action_; }

    bool apply_plan(const Plan &plan,
                    const State &initial_state,
                    State &final_state,
                    std::vector<State> &support_vec) const;

    virtual void write_problem(std::ostream &os, const State *state = 0, int indent = 4) const;

    void print_stats(std::ostream &os) const;
};

#endif

