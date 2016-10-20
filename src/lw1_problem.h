/*
 *  Copyright (C) 2011 - <date> Blai Bonet, Universidad Simon Bolivar
 *
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 *  Blai Bonet, bonet@ldc.usb.ve, bonetblai@gmail.com
 *
 */

#ifndef LW1_PROBLEM_H
#define LW1_PROBLEM_H

#include "kp_problem.h"
#include "options.h"
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

class LW1_Instance : public KP_Instance {
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

    // normal-execution atom, last-action-atoms and atoms-for-sensing in po_instance
    int normal_execution_atom_;
    std::set<int> last_action_atoms_;
    std::set<int> sensing_enabler_atoms_;
    std::map<std::string, std::set<int> > atoms_for_observables_;
    std::map<std::string, int> literals_for_observables_;

    // for subgoaling
    std::vector<Atom*> atoms_for_unknown_observables_at_init_;

    // for KP/s translation
    std::map<int, int> kps_atoms_;

    class Variable {
      protected:
        std::string name_;
        bool is_observable_;
        bool is_state_variable_;
        std::set<int> domain_;
        std::map<int, index_set> beams_;  // non-empty only for observable variables

      public:
        Variable(const std::string &name, bool is_observable, bool is_state_variable, const std::set<int> &domain, const std::map<int, index_set> &beams)
            : name_(name), is_observable_(is_observable), is_state_variable_(is_state_variable), domain_(domain), beams_(beams) {
        }
        const std::string& name() const { return name_; }
        bool is_observable() const { return is_observable_; }
        bool is_state_variable() const { return is_state_variable_; }
        bool is_binary() const { return domain_.size() == 1; }
        const std::set<int>& domain() const { return domain_; }
        const std::map<int, index_set>& beams() const { return beams_; }
        void print(std::ostream &os) const;
    };

    // lw1 variables and sensing models.
    // Sensing models are indexed by (action-name, value-index, var-index) and return DNF
    std::map<std::string, int> varmap_;
    std::vector<Variable*> variables_;
    std::map<int, std::vector<int> > variables_for_atom_;
    std::map<std::string, std::map<int, std::map<int, std::vector<std::vector<int> > > > > sensing_models_as_k_cnf_;
    std::map<std::string, std::map<int, std::map<int, std::vector<std::vector<int> > > > > sensing_models_as_k_dnf_;
    std::map<std::string, std::map<int, std::map<int, std::vector<std::vector<int> > > > > sensing_models_as_dnf_;
    std::map<std::string, std::set<int> > vars_sensed_by_action_;

    // inference: literals that may enter state and/or cnf (aka augmented state)
    std::set<int> non_state_literals_;
    std::set<int> clause_forbidding_literals_;

    // TODO: can we get rid of beams_for_observable_atoms_?
    index_set observable_atoms_;
    std::map<std::pair<int, int>, index_set> beams_for_observable_atoms_;
    std::vector<std::vector<int> > clauses_for_axioms_;

    // variable groups
    std::vector<std::vector<int> > atoms_for_variable_groups_;
    std::vector<std::vector<int> > vars_for_variable_groups_;
    std::map<std::pair<int, int>, int> filtering_groups_;

    LW1_Instance(const Instance &instance,
                 const PDDL_Base::variable_vec &variables,
                 const PDDL_Base::variable_group_vec &variable_groups,
                 const std::list<std::pair<const PDDL_Base::Action*, const PDDL_Base::Sensing*> > &sensing_models,
                 const std::map<std::string, std::set<std::string> > &accepted_literals_for_observables);
    ~LW1_Instance();

    bool is_forbidden(int literal) const;
    bool is_forbidden(const std::vector<int> &clause) const;

    void create_regular_action(const Action &action,
                               int action_index,
                               const index_set &observable_atoms,
                               const std::map<std::pair<int, int>, index_set> &beams_for_observable_atoms);
    void create_drule_for_var(const Action &action);
    void create_drule_for_sensing(const Action &action);
    void create_drule_for_atom(const Action &action);

    void complete_effect(index_set &effect, int literal, const Variable &variable) const;
    void complete_effect(index_set &effect, int literal) const;

    void create_sensor(const Sensor &sensor);

    virtual void cross_reference();
    virtual int remap_action(size_t action_id) const {
        return action_id < remap_.size() ? remap_[action_id] : -1;
    }
    virtual void get_goal_condition(index_set &condition) const;

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

    virtual bool has_groups() const {
        return atoms_for_variable_groups_.size() > 0;
    };

    virtual void print_stats(std::ostream &os) const;
};

inline std::ostream& operator<<(std::ostream &os, const LW1_Instance::Variable &var) {
    var.print(os);
    return os;
}

#endif

