#ifndef PROBLEM_H
#define PROBLEM_H

#include <map>
#include "name.h"
#include "index.h"
#include "options.h"

class State;
class StateSet;
class StateHash;

class Instance {
    bool cross_referenced;

  public:
    static bool always_write_parameters_declaration;
    static bool always_write_requirements_declaration;
    static bool always_write_precondition;
    static bool always_write_conjunction;

    struct Atom {
        Name     *name;
        unsigned index;
        Atom(Name* n = 0, unsigned i = 0) : name(n), index(i) { }
        const Atom& operator=(const Atom &atom) {
            name = atom.name;
            index = atom.index;
            return *this;
        }
        bool operator==(const Atom &atom) { return index == atom.index; }
    };
    class atom_vec : public std::vector<Atom*> { };

    struct When {
        index_set condition;
        index_set effect;
        When() { }
    };
    struct when_vec : public std::vector<When> { };

    struct Action {
        Name*      name;
        size_t     index;
        index_set  precondition;
        index_set  effect;
        when_vec   when;
        size_t     cost;
        Action(Name* n = 0, size_t i = 0) : name(n), index(i), cost(1) { }
        const Action& operator=(const Action &a) {
            name = a.name;
            index = a.index;
            precondition = a.precondition;
            effect = a.effect;
            when = a.when;
            cost = a.cost;
            return *this;
        }
        bool operator==(const Action &a) { return index == a.index; }
        void print(std::ostream &os, const Instance &i) const;
    };
    class action_vec : public std::vector<Action*> { };

    struct Sensor {
        Name *    name;
        size_t    index;
        index_set condition;
        index_set sensed;
        Sensor(Name *n = 0, size_t i = 0) : name(n), index(i) { }
        const Sensor& operator=(const Sensor &r) {
            name = r.name;
            index = r.index;
            condition = r.condition;
            sensed = r.sensed;
            return *this;
        }
        bool operator==(const Sensor &r) { return index == r.index; }
        void print(std::ostream &os, const Instance &i) const;
    };
    class sensor_vec : public std::vector<Sensor*> { };

    struct Axiom {
        Name *    name;
        size_t    index;
        index_set body;
        index_set head;
        Axiom(Name *n = 0, size_t i = 0) : name(n), index(i) { }
        const Axiom& operator=(const Axiom &r) {
            name = r.name;
            index = r.index;
            body = r.body;
            head = r.head;
            return *this;
        }
        bool operator==(const Axiom &r) { return index == r.index; }
        void print(std::ostream &os, const Instance &i) const;
    };
    class axiom_vec : public std::vector<Axiom*> { };

    struct Invariant : public index_vec {
        int type;
        enum { AT_LEAST_ONE = 0, AT_MOST_ONE = 1, EXACTLY_ONE = 2 };
        Invariant(int t = AT_LEAST_ONE) : type(t) { }
        // Invariants of type EXACTLY_ONE shouldn't exist because
        // they are mapped into two invariants of types AT_LEAST_ONE
        // and AT_MOST_ONE respectively.
    };
    class invariant_vec : public std::vector<Invariant> { };

    struct Clause : public index_vec { };
    class clause_vec : public std::vector<Clause> { };

    struct Oneof : public index_vec { };
    class oneof_vec : public std::vector<Oneof> { };

    struct Init {
        index_set literals;
        invariant_vec invariants;
        clause_vec    clauses;
        oneof_vec     oneofs;
    };

    class Plan : public std::vector<int> { };

    Name        *name;
    atom_vec    atoms;
    action_vec  actions;
    sensor_vec  sensors;
    axiom_vec   axioms;

    Init        init;
    Init        hidden;
    index_set   goal_literals;
    index_set   non_primitive_fluents;
    index_set   observable_fluents;
    index_set   given_observables;
    index_set   given_stickies;

    // deductive rules to apply to hidden state
    action_vec  deductive_rules;

    const Options::Mode options_;

    Instance(Name *n = 0, const Options::Mode &options = Options::Mode())
      : cross_referenced(false), name(n), options_(options) {
    }
    Instance(const Options::Mode &options)
      : cross_referenced(false), name(0), options_(options) {
    }
    Instance(const Instance &ins);
    virtual ~Instance() { }

    Atom&      new_atom(Name *name);
    Action&    new_action(Name *name);
    Sensor&    new_sensor(Name *name);
    Axiom&     new_axiom(Name *name);

    // change (remove from) instance
    void remove_unreachable_conditional_effects(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void remove_unreachable_axioms(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void simplify_conditional_effects(const bool_vec &static_atoms);
    void remove_actions(const bool_vec &set, index_vec &map);
    void remove_sensors(const bool_vec &set, index_vec &map);
    void remove_axioms(const bool_vec &set, index_vec &map);
    virtual void remove_atoms(const bool_vec &set, index_vec &map);
    void set_non_primitive_and_observable_fluents();
    void set_initial_state(State &state) const;
    void set_hidden_state(State &state) const;

    // NOTE: remove_atoms must be virtual because CP_Instance needs to 
    // remap atoms in the initial states, rechable space, etc.

    // compute/clear secondary instance info
    void cross_reference();
    void clear_cross_reference();

    // access instance information
    size_t n_atoms() const { return atoms.size(); }
    size_t n_actions() const { return actions.size(); }
    size_t n_sensors() const { return sensors.size(); }
    size_t n_axioms() const { return axioms.size(); }
    bool is_non_primitive(size_t fluent) const {
        return non_primitive_fluents.find(fluent) != non_primitive_fluents.end();
    }
    bool is_observable(size_t fluent) const {
        return observable_fluents.find(fluent) != observable_fluents.end();
    }

    // generate reachable state space
    void generate_reachable_state_space(StateSet &hash) const;
    void generate_reachable_state_space(const State &state, StateSet &hash) const;
    void generate_initial_states(StateSet &initial_states) const;

    // write utilities
    void write_atom_set(std::ostream &os, const index_set &set) const;
    void write_atom_set(std::ostream &os, const bool* set) const;
    void write_atom_set(std::ostream &os, const bool_vec &set) const;
    void write_atom_sets(std::ostream &os, const index_set_vec &sets) const;
    void write_action_set(std::ostream &os, const index_vec &set) const;
    void write_action_set(std::ostream &os, const bool* set) const;
    void write_action_set(std::ostream &os, const bool_vec &set) const;
    void write_domain(std::ostream &os, int indent = 4) const;
    void write_problem(std::ostream &os, const State *state, int indent = 4) const;
    void write_problem(std::ostream &os, int indent = 4) const { write_problem(os, 0, indent); }
    void print_atoms(std::ostream &os) const;
    void print_actions(std::ostream &os) const;
    void print_sensors(std::ostream &os) const;
    void print_axioms(std::ostream &os) const;
    void print(std::ostream &os) const;

    // plan application
    void create_deductive_rules();
    void apply_deductive_rules(State &state) const;
};

#endif

