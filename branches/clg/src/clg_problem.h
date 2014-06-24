#ifndef CLG_PROBLEM_H
#define CLG_PROBLEM_H

#include "kp_problem.h"
#include "options.h"
#include <map>
#include <string>

class CLG_Instance : public KP_Instance {
  public:
    size_t n_standard_actions_;
    size_t n_sensor_actions_;
    size_t n_drule_actions_;
    size_t n_subgoaling_actions_;
    const Instance &po_instance_;

    // maps standard actions in kp-problem into standard actions in po problem
    std::vector<int> remap_;

    std::multimap<index_set, const Action*> drule_store_;

    CLG_Instance(const Instance &instance);
    ~CLG_Instance();

    void create_regular_action(const Action &action, int action_index);
    void create_drules_from_invariant(const Invariant &invariant);
    void merge_drules();
    void create_sensor(const Sensor &sensor);
    void perform_subgoaling();

    virtual void cross_reference();
    virtual size_t remap_action(size_t action_id) const {
        assert(action_id < remap_.size());
        return remap_[action_id];
    }
    virtual void set_goal_condition(index_set &condition) const;

    virtual size_t first_deductive_action() const {
        return n_standard_actions_;
    }
    virtual size_t last_deductive_action() const {
        return first_deductive_action() + n_drule_actions_;
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
        return (a >= first_deductive_action()) && (a < last_deductive_action());
    }
    virtual bool is_subgoaling_rule(size_t a) const {
        size_t lower = n_standard_actions_ + n_sensor_actions_ + n_drule_actions_;
        size_t upper = lower + n_subgoaling_actions_;
        return (a >= lower) && (a < upper);
    }

    virtual void print_stats(std::ostream &os) const;
};

#endif

