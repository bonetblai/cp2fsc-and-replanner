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

class CP_Instance : public Instance {
  public:
    const int fsc_states_;
    const int bounded_reachability_;
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
                bool forbid_inconsistent_tuples = false,
                bool compound_obs_as_fluents = false);
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
    bool consistent_with_obs(int obs_idx, const index_set &condition, bool caching) const;
    int n_obs() const { return reachable_obs_.size(); }

    // Remaps atoms in the initial states and then calls Instance::remove_atoms()
    virtual void remove_atoms(const bool_vec &set, index_vec &atom_map);

    // write initial states to pddl problem file
    virtual void write_problem_additional(std::ostream &os, const State *state, int indent = 4) const;
};

#endif

