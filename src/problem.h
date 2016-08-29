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
  protected:
    bool cross_referenced_;

  public:
    static bool always_write_parameters_declaration_;
    static bool always_write_requirements_declaration_;
    static bool always_write_precondition_;
    static bool always_write_conjunction_;

    struct Atom {
        Name     *name_;
        unsigned index_;
        Atom(Name* name = 0, unsigned index = 0) : name_(name), index_(index) { }
        ~Atom() { delete name_; }
        const Atom& operator=(const Atom &atom) {
            name_ = atom.name_;
            index_ = atom.index_;
            return *this;
        }
        bool operator==(const Atom &atom) { return index_ == atom.index_; }
    };
    class atom_vec : public std::vector<Atom*> { };

    struct When {
        index_set condition_;
        index_set effect_;
        When() { }
        bool operator<(const When &when) const {
            return (condition_ < when.condition_) ||
                   ((condition_ == when.condition_) && (effect_ < when.effect_));
        }
        bool operator==(const When &when) const {
            return (condition_ == when.condition_) && (effect_ == when.effect_);
        }
    };
    struct when_vec : public std::vector<When> { };

    struct Action {
        Name*       name_;
        size_t      index_;
        index_set   precondition_;
        index_set   effect_;
        when_vec    when_;
        size_t      cost_;
        std::string comment_;
        Action(Name* name = 0, size_t index = 0) : name_(name), index_(index), cost_(1) { }
        ~Action() { delete name_; }
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
    class action_vec : public std::vector<Action*> { };

    struct Sensor {
        Name *    name_;
        size_t    index_;
        index_set condition_;
        index_set sense_;
        Sensor(Name *name = 0, size_t index = 0) : name_(name), index_(index) { }
        ~Sensor() { delete name_; }
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
    class sensor_vec : public std::vector<Sensor*> { };

    struct Axiom {
        Name *    name_;
        size_t    index_;
        index_set body_;
        index_set head_;
        Axiom(Name *name = 0, size_t index = 0) : name_(name), index_(index) { }
        const Axiom& operator=(const Axiom &r) {
            name_ = r.name_;
            index_ = r.index_;
            body_ = r.body_;
            head_ = r.head_;
            return *this;
        }
        ~Axiom() { delete name_; }
        bool operator==(const Axiom &r) { return index_ == r.index_; }
        void print(std::ostream &os, const Instance &i) const;
        void write(std::ostream &os, int indent, const Instance &instance) const;
    };
    class axiom_vec : public std::vector<Axiom*> { };

    // After instantiation, all invariants are of type AT_LEAST_ONE.
    struct Invariant : public index_vec {
        int type_;
        index_set Xprecondition_;
        enum { AT_LEAST_ONE = 0, AT_MOST_ONE = 1, EXACTLY_ONE = 2 };
        Invariant(int type = AT_LEAST_ONE) : type_(type) { }
        Invariant(int type, const Invariant &invariant)
          : index_vec(invariant), type_(type), Xprecondition_(invariant.Xprecondition_) { }
        void write(std::ostream &os, int indent, const Instance &instance) const;
    };
    class invariant_vec : public std::vector<Invariant> { };

    struct Clause : public index_vec { };
    class clause_vec : public std::vector<Clause> { };

    struct Oneof : public index_vec { };
    class oneof_vec : public std::vector<Oneof> { };

    struct Init {
        index_set     literals_;
        invariant_vec invariants_;
        clause_vec    clauses_;
        oneof_vec     oneofs_;
    };
    class init_vec : public std::vector<Init> { };

    class Plan : public std::vector<int> { };

    Name        *name_;
    atom_vec    atoms_;
    action_vec  actions_;
    sensor_vec  sensors_;
    axiom_vec   axioms_;

    Init        init_;
    init_vec    hidden_;
    index_set   goal_literals_;
    index_set   non_primitive_fluents_;
    index_set   observable_fluents_;
    index_set   given_observables_;
    index_set   given_stickies_;

    // deductive rules to apply to hidden state
    action_vec  deductive_rules_;

    const Options::Mode &options_;

    // actions that correspond to original problem
    std::set<std::string> original_actions_;

    Instance(Name *name, const Options::Mode &options)
      : cross_referenced_(false), name_(name), options_(options) {
    }
    Instance(const Options::Mode &options)
      : cross_referenced_(false), name_(0), options_(options) {
    }
    Instance(const Instance &ins);
    virtual ~Instance();

    Atom&      new_atom(Name *name);
    Action&    new_action(Name *name);
    Sensor&    new_sensor(Name *name);
    Axiom&     new_axiom(Name *name);

    // change (remove from) instance
    void set_name(Name *name) { delete name_; name_ = name; }
    void remove_unreachable_conditional_effects(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void remove_unreachable_axioms(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void remove_unreachable_sensors(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void simplify_conditions_and_invariants(const bool_vec &reachable_atoms, const bool_vec &static_atoms);
    void remove_actions(const bool_vec &set, index_vec &map);
    void calculate_non_primitive_and_observable_fluents();
    void set_initial_state(State &state, bool apply_axioms = true) const;
    void set_hidden_state(int k, State &state) const;
    int num_hidden_states() const { return hidden_.size(); }

    // NOTE: remove_atoms must be virtual because CP_Instance needs to 
    // remap atoms in the initial states, rechable space, etc.
    virtual void remove_atoms(const bool_vec &set, index_vec &map);

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
    void generate_reachable_state_space(StateSet &hash) const;
    void generate_reachable_state_space(const State &state, StateSet &hash) const;
    void generate_initial_states(StateSet &initial_states) const;

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
    void write_domain(std::ostream &os, int indent = 4) const;
    virtual void write_problem(std::ostream &os, const State *state, int indent = 4) const;
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

