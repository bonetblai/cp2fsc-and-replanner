#ifndef KP_PROBLEM_H
#define KP_PROBLEM_H

#include "problem.h"
#include "base.h"
#include "options.h"
#include <map>
#include <string>

class KP_Instance : public Instance {
  public:
    KP_Instance(const Options::Mode &options);
    virtual ~KP_Instance() { }

    // for subgoaling
    Atom *new_goal_;
    size_t index_for_goal_action_;

    virtual void cross_reference() = 0;
    virtual size_t remap_action(size_t action_id) const = 0;
    virtual void set_goal_condition(index_set &condition) const = 0;

    virtual size_t first_deductive_action() const = 0;
    virtual size_t last_deductive_action() const = 0;
    virtual bool is_regular_action(size_t a) const = 0;
    virtual bool is_obs_rule(size_t a) const = 0;
    virtual bool is_static_rule(size_t a) const = 0;
    virtual bool is_subgoaling_rule(size_t a) const = 0;
    virtual bool is_goal_action(size_t a) const {
        return a == index_for_goal_action_;
    }
    virtual void print_stats(std::ostream &os) const = 0;

    virtual void calculate_relevant_assumptions(const Plan &plan,
                                                const State &initial_state,
                                                const index_set &goal,
                                                std::vector<index_set> &assumptions) const;
#if 0
    bool apply_plan(const Plan &plan,
                    const State &initial_state,
                    State &final_state,
                    std::vector<State> &support_vec) const;
#endif

    virtual void write_problem(std::ostream &os, const State *state = 0, int indent = 4) const;
};

class Standard_KP_Instance : public KP_Instance {
  public:
    size_t n_standard_actions_;
    size_t n_sensor_actions_;
    size_t n_invariant_actions_;
    size_t n_subgoaling_actions_;
    const Instance &po_instance_;

    // maps standard actions in kp-problem into standard actions in po problem
    std::vector<int> remap_;
    //std::map<std::string, int> obs_rules_by_name_;

    // for subgoaling
    std::vector<Atom*> atoms_for_unknown_observables_at_init_;

    Standard_KP_Instance(const Instance &instance, const PDDL_Base::variable_vec &multivalued_variables);
    Standard_KP_Instance(const Instance &instance);
    ~Standard_KP_Instance();

    virtual void cross_reference();
    virtual size_t remap_action(size_t action_id) const {
        assert(action_id < remap_.size());
        return remap_[action_id];
    }
    virtual void set_goal_condition(index_set &condtion) const;

    virtual size_t first_deductive_action() const {
        return n_standard_actions_ + n_sensor_actions_;
    }
    virtual size_t last_deductive_action() const {
        return first_deductive_action() + n_invariant_actions_;
    }
    virtual bool is_regular_action(size_t a) const {
        return (a < n_standard_actions_) || is_subgoaling_rule(a);
    }
    virtual bool is_obs_rule(size_t a) const {
        size_t lower = n_standard_actions_;
        size_t upper = lower + n_sensor_actions_;
        return (a >= lower) && (a < upper);
    }
    virtual bool is_static_rule(size_t a) const {
        size_t lower = n_standard_actions_ + n_sensor_actions_;
        size_t upper = lower + n_invariant_actions_;
        return (a >= lower) && (a < upper);
    }
    virtual bool is_subgoaling_rule(size_t a) const {
        size_t lower = n_standard_actions_ + n_sensor_actions_ + n_invariant_actions_;
        size_t upper = lower + n_subgoaling_actions_;
        return (a >= lower) && (a < upper);
    }

#if 0
    virtual bool is_obs_rule(const std::string &name) const {
        return obs_rules_by_name_.find(name) != obs_rules_by_name_.end();
    }
#endif

    virtual void print_stats(std::ostream &os) const;
};

#endif

