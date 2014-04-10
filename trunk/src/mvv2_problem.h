#ifndef MVV2_PROBLEM_H
#define MVV2_PROBLEM_H

#include "kp_problem.h"
#include "options.h"
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

class MVV2_Instance : public KP_Instance {
  public:
    size_t n_standard_actions_;
    size_t n_sensor_actions_;
    size_t n_drule_actions_; // sum of the three below
    size_t n_drules_for_vars_;
    size_t n_drules_for_sensing_;
    size_t n_drules_for_atoms_;
    size_t n_subgoaling_actions_;
    const Instance &po_instance_;

    // maps standard actions in kp-problem into standard actions in po problem
    std::vector<int> remap_;
    std::map<std::string, int> obs_rules_by_name_;

    // for subgoaling
    std::vector<Atom*> atoms_for_unknown_observables_at_init_;

    std::vector<std::pair<std::string, std::set<int> > > multivalued_variables_;
    std::multimap<index_set, const Action*> drule_store_;
    index_set observable_atoms_;
    std::map<int, index_set> beams_for_observable_atoms_;

    MVV2_Instance(const Instance &instance, const PDDL_Base::variable_vec &multivalued_variables);
    ~MVV2_Instance();

    void create_regular_action(const Action &action,
                               int action_index,
                               const index_set &observable_atoms,
                               const std::map<int, index_set> &beams_for_observable_atoms);
    void create_drule_for_var(const Action &action);
    void create_drule_for_sensing(const Action &action);
    void create_drule_for_atom(const Action &action);
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
        size_t lower = last_deductive_action();
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

