#ifndef KP_PROBLEM_H
#define KP_PROBLEM_H

#include "problem.h"
#include "options.h"

class KP_Instance : public Instance {
  public:
    size_t n_standard_actions_;
    size_t n_sensor_actions_;
    size_t n_invariant_actions_;
    std::map<std::string, int> obs_rules_by_name_;
    KP_Instance(const Instance &instance, const Options::Mode &options = Options::Mode());
    ~KP_Instance() { }
    size_t first_deductive_action() const { return n_standard_actions_ + n_sensor_actions_; }
    bool is_obs_rule(const std::string &name) const {
        return obs_rules_by_name_.find(name) != obs_rules_by_name_.end();
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
    void apply_plan(const Plan &plan,
                    const State &initial_state,
                    State &final_state,
                    std::vector<State> &support_vec) const;
};

#endif

