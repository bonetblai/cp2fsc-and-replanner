#ifndef MVV_PROBLEM_H
#define MVV_PROBLEM_H

#include "kp_problem.h"
#include "options.h"
#include <list>
#include <map>
#include <set>
#include <string>

class MVV_Instance : public KP_Instance {
  public:
    size_t n_standard_actions_;
    size_t n_sensor_actions_;
    size_t n_drule_actions_; // sum of two below
    size_t n_drules_for_vars_;
    size_t n_drules_for_sensing_models_;
    size_t n_subgoaling_actions_;
    const Instance &po_instance_;

    // maps standard actions in kp-problem into standard actions in po problem
    std::vector<int> remap_;
    std::map<std::string, int> obs_rules_by_name_;

    // for subgoaling
    std::vector<Atom*> atoms_for_unknown_observables_at_init_;

    std::vector<std::pair<std::string, std::set<int> > > multivalued_variables_;
    std::map<int, std::set<std::set<int> > > sensing_models_;
    std::map<int, std::set<std::set<int> > > enablers_for_sensing_;

    MVV_Instance(const Instance &instance,
                 const PDDL_Base::variable_vec &multivalued_variables,
                 const std::list<const PDDL_Base::Effect*> &sensing_models,
                 const std::map<PDDL_Base::Atom, PDDL_Base::Atom> &sensing_enablers,
                 const std::map<PDDL_Base::Atom, std::set<PDDL_Base::unsigned_atom_set> > &pasive_sensors);
    ~MVV_Instance();

    void create_sensor(int sensed_index);

    virtual void cross_reference();
    virtual size_t remap_action(size_t action_id) const {
        assert(action_id < remap_.size());
        return remap_[action_id];
    }
    virtual void set_goal_condition(index_set &condition) const;

    virtual size_t first_deductive_action() const {
        return n_standard_actions_ + n_sensor_actions_;
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
        size_t lower = n_standard_actions_ + n_sensor_actions_;
        size_t upper = lower + n_drule_actions_;
        return (a >= lower) && (a < upper);
    }
    virtual bool is_subgoaling_rule(size_t a) const {
        size_t lower = n_standard_actions_ + n_sensor_actions_ + n_drule_actions_;
        size_t upper = lower + n_subgoaling_actions_;
        return (a >= lower) && (a < upper);
    }

    virtual void print_stats(std::ostream &os) const;
};

#endif

