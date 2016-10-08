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

#ifndef PREPROCESS_H
#define PREPROCESS_H

#include "problem.h"
#include "index.h"
#include "options.h"

class Preprocessor {
    Instance&   instance_;
    index_vec   atom_map_;
    index_vec   action_map_;

  protected:
    void mark_inconsistent_actions(bool_vec &actions_to_remove);
    void mark_useless_actions(bool_vec &actions_to_remove);
    void mark_unreachable_actions(const bool_vec &reachable_atoms, const bool_vec &static_atoms, bool_vec &actions_to_remove);

  public:
    const Options::Mode &options_;

    Preprocessor(Instance &ins);
    ~Preprocessor();

    // methods that do NOT change the instance:
    void compute_reachability(bool_vec &reachable_atoms, bool_vec &reachable_actions, bool_vec &reachable_sensors, bool_vec &reachable_axioms) const;
    void compute_static_atoms(const bool_vec &reachable_actions, bool_vec &static_atoms) const;

    // adds atoms recursively relevant to set 'check' to set 'rel'
    void compute_relevance(const index_set &check, bool_vec &rel) const;

    // methods that ADD (information) TO the instance:

    // marks atoms not relevant to goals in instance
    void compute_irrelevant_atoms();

    // methods that REMOVE things from, or otherwise CHANGE the instance:

    // remove atoms marked irrelevant from instance (re-cross-ref)
    void remove_irrelevant_atoms();

    // compute action compilation
    void compute_action_compilation(Instance::Action &action);

    // perform standard preprocessing: remove static atoms and unreachable actions, re-cross-ref
    void preprocess(bool remove_atoms = false);
};

#endif

