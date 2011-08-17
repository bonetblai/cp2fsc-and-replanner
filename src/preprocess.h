#ifndef PREPROCESS_H
#define PREPROCESS_H

#include "problem.h"
#include "index.h"
#include "verbosity.h"

class Preprocessor {
  public:
    Instance&   instance;
    index_vec   atom_map;
    index_vec   action_map;
    index_vec   sensor_map;
    index_vec   axiom_map;
    index_vec   inv_map;

  protected:
    void remove_inconsistent_actions();
    void remove_useless_effects_and_actions();

  public:
    Verbosity::Mode verbosity_mode;

    Preprocessor(Instance &ins, const Verbosity::Mode &vmode = Verbosity::Mode());
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

    // perform standard preprocessing: remove static atoms and unreachable actions, re-cross-ref
    void preprocess(bool remove_atoms = true, const bool_vec *known_non_static_atoms = 0);
};

#endif

