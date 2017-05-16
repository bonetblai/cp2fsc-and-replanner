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

#ifndef PROBLEM_H
#define PROBLEM_H

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "index.h"
#include "options.h"

class State;
class StateSet;
class StateHash;

class Instance {
  protected:
    bool cross_referenced_;

  public:
    static bool always_write_parameters_declaration_;
    static bool always_write_requirements_declaration_;
    static bool always_write_precondition_;
    static bool always_write_conjunction_;

    class Atom {
      protected:
        std::string name_;
        unsigned index_;

      public:
        Atom(const std::string &name, unsigned index) : name_(name), index_(index) { }
        const std::string& name() const { return name_; };
        void set_index(int index) { index_ = index; }
        unsigned index() const { return index_; }
        const Atom& operator=(const Atom &atom) {
            name_ = atom.name_;
            index_ = atom.index_;
            return *this;
        }
        bool operator==(const Atom &atom) { return index_ == atom.index_; }
    };
#ifdef SMART
    class owner_atom_vec : public std::vector<std::unique_ptr<Atom> > {
      public:
        owner_atom_vec() { }
        owner_atom_vec(const owner_atom_vec &vec) = delete; // unique_ptr's can't be copied
    };
#else
    class atom_vec : public std::vector<Atom*> { };
#endif

    class When {
      protected:
        index_set condition_;
        index_set effect_;

      public:
        When() { }
        index_set& condition() { return condition_; }
        index_set& effect() { return effect_; }
        const index_set& condition() const { return condition_; }
        const index_set& effect() const { return effect_; }
        bool operator<(const When &when) const {
            return (condition_ < when.condition_) ||
                   ((condition_ == when.condition_) && (effect_ < when.effect_));
        }
        bool operator==(const When &when) const {
            return (condition_ == when.condition_) && (effect_ == when.effect_);
        }
    };
    class when_vec : public std::vector<When> { };

    class Action {
      protected:
        std::string   name_;
        size_t        index_;
        index_set     precondition_;
        index_set     effect_;
        when_vec      when_;
        size_t        cost_;
        std::string   comment_;

      public:
        Action(const std::string &name, size_t index = 0)
          : name_(name), index_(index), cost_(1) {
        }
        const std::string& name() const { return name_; }
        size_t index() const { return index_; }
        void set_index(size_t index) { index_ = index; }
        index_set& precondition() { return precondition_; }
        index_set& effect() { return effect_; }
        when_vec& when() { return when_; }
        const index_set& precondition() const { return precondition_; }
        const index_set& effect() const { return effect_; }
        const when_vec& when() const { return when_; }
        size_t cost() const { return cost_; }
        void set_cost(size_t cost) { cost_ = cost; }
        std::string& comment() { return comment_; }
        const std::string& comment() const { return comment_; }

        const Action& operator=(const Action &a) {
            name_ = a.name_;
            index_ = a.index_;
            precondition_ = a.precondition_;
            effect_ = a.effect_;
            when_ = a.when_;
            cost_ = a.cost_;
            return *this;
        }
        bool operator==(const Action &a) { return index_ == a.index_; }
        void print(std::ostream &os, const Instance &i) const;
        void write(std::ostream &os, int indent, const Instance &instance) const;
    };
#ifdef SMART
    class owner_action_vec : public std::vector<std::unique_ptr<Action> > {
      public:
        owner_action_vec() { }
        owner_action_vec(const owner_action_vec &vec) = delete; // unique_ptr's can't be copied
    };
#else
    class action_vec : public std::vector<Action*> { };
#endif

    class Sensor {
      protected:
        std::string name_;
        size_t      index_;
        index_set   condition_;
        index_set   sense_;

      public:
        Sensor(const std::string &name, size_t index) : name_(name), index_(index) { }
        const std::string& name() const { return name_; }
        size_t index() const { return index_; }
        void set_index(size_t index) { index_ = index; }
        index_set& condition() { return condition_; }
        index_set& sense() { return sense_; }
        const index_set& condition() const { return condition_; }
        const index_set& sense() const { return sense_; }

        const Sensor& operator=(const Sensor &r) {
            name_ = r.name_;
            index_ = r.index_;
            condition_ = r.condition_;
            sense_ = r.sense_;
            return *this;
        }
        bool operator==(const Sensor &r) { return index_ == r.index_; }
        void print(std::ostream &os, const Instance &i) const;
        void write(std::ostream &os, int indent, const Instance &instance) const;
    };
#ifdef SMART
    class owner_sensor_vec : public std::vector<std::unique_ptr<Sensor> > {
      public:
        owner_sensor_vec() { }
        owner_sensor_vec(const owner_sensor_vec &vec) = delete; // unique_ptr's can't be copied
    };
#else
    class sensor_vec : public std::vector<Sensor*> { };
#endif

    class Axiom {
      protected:
        std::string name_;
        size_t      index_;
        index_set   body_;
        index_set   head_;

      public:
        Axiom(const std::string &name, size_t index) : name_(name), index_(index) { }
        const std::string& name() const { return name_; }
        size_t index() const { return index_; }
        index_set& body() { return body_; }
        index_set& head() { return head_; }
        const index_set& body() const { return body_; }
        const index_set& head() const { return head_; }
        const Axiom& operator=(const Axiom &r) {
            name_ = r.name_;
            index_ = r.index_;
            body_ = r.body_;
            head_ = r.head_;
            return *this;
        }
        bool operator==(const Axiom &r) { return index_ == r.index_; }
        void print(std::ostream &os, const Instance &i) const;
        void write(std::ostream &os, int indent, const Instance &instance) const;
    };
#ifdef SMART
    class owner_axiom_vec : public std::vector<std::unique_ptr<Axiom> > {
      public:
        owner_axiom_vec() { }
        owner_axiom_vec(const owner_axiom_vec &vec) = delete; // unique_ptr's can't be copied
    };
#else
    class axiom_vec : public std::vector<Axiom*> { };
#endif

    // After instantiation, all invariants are of type AT_LEAST_ONE.
    class Invariant : public index_vec {
      protected:
        int type_;
        index_set Xprecondition_;

      public:
        Invariant(int type = AT_LEAST_ONE) : type_(type) { }
        Invariant(int type, const Invariant &invariant)
          : index_vec(invariant), type_(type), Xprecondition_(invariant.Xprecondition_) {
        }
        int type() const { return type_; }
        const index_set& Xprecondition() const { return Xprecondition_; }
        index_set& Xprecondition() { return Xprecondition_; }
        void write(std::ostream &os, int indent, const Instance &instance) const;

      public:
        enum { AT_LEAST_ONE = 0, AT_MOST_ONE = 1, EXACTLY_ONE = 2 };
    };
    class invariant_vec : public std::vector<Invariant> { };

    class Clause : public index_vec { };
    class clause_vec : public std::vector<Clause> { };

    class Oneof : public index_vec { };
    class oneof_vec : public std::vector<Oneof> { };

    class Init {
      protected:
        index_set     literals_;
        invariant_vec invariants_;
        clause_vec    clauses_;
        oneof_vec     oneofs_;

      public:
        index_set& literals() { return literals_; }
        invariant_vec& invariants() { return invariants_; }
        clause_vec& clauses() { return clauses_; }
        oneof_vec& oneofs() { return oneofs_; }
        const index_set& literals() const { return literals_; }
        const invariant_vec& invariants() const { return invariants_; }
        const clause_vec& clauses() const { return clauses_; }
        const oneof_vec& oneofs() const { return oneofs_; }
    };
    class init_vec : public std::vector<Init> { };

    class Plan : public std::vector<int> { };

    std::string domain_name_;
    std::string problem_name_;
#ifdef SMART
    owner_atom_vec    atoms_;
    owner_action_vec  actions_;
    owner_sensor_vec  sensors_;
    owner_axiom_vec   axioms_;
#else
    atom_vec    atoms_;
    action_vec  actions_;
    sensor_vec  sensors_;
    axiom_vec   axioms_;
#endif

    Init        init_;
    init_vec    hidden_;
    init_vec    explicit_initial_states_;
    index_set   goal_literals_;
    index_set   non_primitive_fluents_;
    index_set   observable_fluents_;
    index_set   given_observables_;
    index_set   given_stickies_;

    index_set   static_atoms_from_base_; // static atoms detected in PDDL_Base

    // deductive rules to apply to hidden state
#ifdef SMART
    owner_action_vec  deductive_rules_;
#else
    action_vec  deductive_rules_;
#endif

    const Options::Mode &options_;

    // actions that correspond to original problem
    std::set<std::string> original_actions_;

    Instance(const std::string &domain_name, const std::string &problem_name, const Options::Mode &options)
      : cross_referenced_(false),
        domain_name_(domain_name),
        problem_name_(problem_name),
        options_(options) {
    }
    Instance(const Options::Mode &options)
      : cross_referenced_(false),
        options_(options) {
    }
#ifndef SMART
    //Instance(const Instance &ins); // CHECK: NOT USED
#endif
    virtual ~Instance();

    Atom&      new_atom(const std::string &name);
    Action&    new_action(const std::string &name);
    Sensor&    new_sensor(const std::string &name);
    Axiom&     new_axiom(const std::string &name);

    void set_domain_name(const std::string &domain_name) { domain_name_ = domain_name; }
    void set_problem_name(const std::string &problem_name) { problem_name_ = problem_name; }
    void remove_unreachable_conditional_effects(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void remove_unreachable_axioms(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void remove_unreachable_sensors(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void simplify_conditions_and_invariants(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void remove_actions(const bool_vec &set, index_vec &map);
    void calculate_non_primitive_and_observable_fluents();
    void set_state(const Init &init, State &state, bool apply_axioms = true) const;
    void set_initial_state(State &state, bool apply_axioms = true) const;
    void set_hidden_state(int k, State &state) const;
    int num_hidden_states() const { return hidden_.size(); }

    // NOTE: remove_atoms must be virtual because CP_Instance needs to
    // remap atoms in the initial states, rechable space, etc.
    virtual void remove_atoms(const bool_vec &set, index_vec &atom_map);

    // The following atoms should not be removed or simplified.
    index_set protected_atoms_;

    // compute/clear secondary instance info
    void clear_cross_reference();
    virtual void cross_reference();

    // access instance information
    size_t n_atoms() const { return atoms_.size(); }
    size_t n_actions() const { return actions_.size(); }
    size_t n_sensors() const { return sensors_.size(); }
    size_t n_axioms() const { return axioms_.size(); }
    bool is_non_primitive(size_t fluent) const {
        return non_primitive_fluents_.find(fluent) != non_primitive_fluents_.end();
    }
    bool is_observable(size_t fluent) const {
        return observable_fluents_.find(fluent) != observable_fluents_.end();
    }

    // reserve space
    void reserve_actions(int n) { actions_.reserve(n); }
    void reserve_sensors(int n) { sensors_.reserve(n); }
    void reserve_axioms(int n) { axioms_.reserve(n); }

    // generate reachable state space
    void generate_reachable_state_space(StateSet &hash, bool verbose = false) const;
    void generate_reachable_state_space(const State &state, StateSet &hash, bool verbose = false) const;
    void generate_initial_states(StateSet &initial_states, bool verbose = false) const;

    // set/get original actions
    bool is_original_action(const std::string &action_name) const {
        return original_actions_.find(action_name) != original_actions_.end();
    }
    void declare_original_action(const std::string &action_name) {
        original_actions_.insert(action_name);
    }

    // write utilities
    void write_atom_set(std::ostream &os, const index_set &set) const;
    void write_atom_set(std::ostream &os, const bool* set) const;
    void write_atom_set(std::ostream &os, const bool_vec &set) const;
    void write_atom_sets(std::ostream &os, const std::vector<index_set> &sets) const;
    void write_action_set(std::ostream &os, const index_vec &set) const;
    void write_action_set(std::ostream &os, const bool* set) const;
    void write_action_set(std::ostream &os, const bool_vec &set) const;
    virtual void write_domain_additional(std::ostream &os, int indent) const { }
    virtual void write_problem_additional(std::ostream &os, const State *state, int indent) const { }
    virtual void write_problem(std::ostream &os, const State *state, int indent = 4) const;
    void write_domain(std::ostream &os, int indent = 4) const;
    void write_problem(std::ostream &os, int indent = 4) const { write_problem(os, 0, indent); }
    void print_atoms(std::ostream &os) const;
    void print_actions(std::ostream &os) const;
    void print_sensors(std::ostream &os) const;
    void print_axioms(std::ostream &os) const;
    void print(std::ostream &os) const;

    // deductive rules
    void create_deductive_rules();
    void apply_deductive_rules(State &state) const;
};

#endif

