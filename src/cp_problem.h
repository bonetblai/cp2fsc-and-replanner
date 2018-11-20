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

#ifndef CP_PROBLEM_H
#define CP_PROBLEM_H

#include <map>
#include <set>
#include "problem.h"
#include "state.h"

//#define OPTION_FOR_SINGLE_MONOLITHIC_ACTION

class CP_Instance : public Instance {
  protected:
    struct Tuple { // (o,q,a,q')
        const index_set *obs_;
        int obs_index_;
        int q_;
        const Action *action_;
        int qp_;
        int unused_fluent_;
        int mapped_fluent_;

        Tuple() : obs_(nullptr), obs_index_(-1), q_(-1), action_(nullptr), qp_(-1), unused_fluent_(-1), mapped_fluent_(-1) { }
        Tuple(int fsc_states, int ins_n_actions, const index_set *obs, int obs_index, int q, const Action *action, int qp)
          : obs_(obs),
            obs_index_(obs_index),
            q_(q),
            action_(action),
            qp_(qp) {
            assert((obs_ != nullptr) && (action_ != nullptr));
            unused_fluent_ = obs_index_ * fsc_states + q_;
            mapped_fluent_ = obs_index_ * fsc_states * ins_n_actions * fsc_states + q_ * ins_n_actions * fsc_states + action_->index() * fsc_states + qp_;
        }

        std::string suffix() const {
            return std::string("q") + Utils::to_string(q_) + "_obs" + Utils::to_string(obs_index_) + "_" + action_->name() + "_q" + Utils::to_string(qp_);
        }
    };
    std::vector<Tuple> tuples_;

  public:
    const int fsc_states_;
    const int bounded_reachability_;
    const bool single_monolithic_action_;
    const bool forbid_inconsistent_tuples_;
    const bool compound_obs_as_fluents_;

    bool complete_state_space_;
    StateSet initial_states_;
    StateSet reachable_space_;
    std::map<const State*, const StateSet*> reachable_space_from_initial_state_;
    std::map<index_set, int> reachable_obs_;
    std::vector<std::set<const State*> > states_for_obs_index_;
    mutable std::map<std::pair<int, const index_set*>, bool> cache_for_consistent_with_obs_;
    const Instance &instance_;

    size_t obs0_, q0_; // initial fluent index for reachable obs and FSC states
    size_t n_unused_fluents_, n_mapped_fluents_; // number of fluents used for removing inconsistent tuples
    size_t unused0_, mapped0_; // initial fluent index for unused and mapped fluents

    CP_Instance(const Instance &instance,
                int fsc_states,
                int bounded_reachability,
                bool single_monolithic_action,
                bool forbid_inconsistent_tuples,
                bool compound_obs_as_fluents);
    virtual ~CP_Instance();

    int fsc_states() const {
        return fsc_states_;
    }
    int bounded_reachability() const {
        return bounded_reachability_;
    }
    bool forbid_inconsistent_tuples() const {
        return forbid_inconsistent_tuples_;
    }
    bool compound_obs_as_fluents() const {
        return compound_obs_as_fluents_;
    }

    void add_to_initial_states(int fluent);
    bool holds_in_observation(int obs_idx, const index_set &obs, int literal) const;
    bool consistent_with_obs(int obs_idx, const index_set &condition, bool caching) const;
    int n_obs() const { return reachable_obs_.size(); }

    void add_unconditional_effects(Action &nact, const Tuple &t, const index_set &np_ns_effect) const;
    void add_conditional_effects(Action &nact, const Instance &ins, const Tuple &t, const index_set &np_ns_effect) const;

    // Remaps atoms in the initial states and then calls Instance::remove_atoms()
    virtual void remove_atoms(const bool_vec &set, index_vec &atom_map);

    // write initial states to pddl problem file
    virtual void write_problem_additional(std::ostream &os, const State *state, int indent = 4) const;
};

#endif

