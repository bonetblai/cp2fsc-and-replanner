#ifndef PDDL_BASE_H
#define PDDL_BASE_H

#include "ptr_table.h"
#include "string_table.h"
#include "problem.h"
#include <assert.h>
#include <set>
#include <vector>

class PDDL_Base {
  public:
    static bool     write_warnings;
    static bool     write_info;

    enum symbol_class {
        sym_object,
        sym_typename,
        sym_predicate,
        sym_variable,
        sym_action,
        sym_axiom,
        sym_sensor
    };

    struct Symbol {
        symbol_class sym_class;
        const char *print_name;
        Symbol *sym_type;
        Symbol(const char *n, symbol_class c = sym_object)
          : sym_class(c), print_name(n), sym_type(0) { }
        void print(std::ostream &os) const { os << print_name; }
    };
    struct symbol_vec : public std::vector<Symbol*> { };

    struct TypeSymbol : public Symbol {
        symbol_vec elements;
        TypeSymbol(const char *n) : Symbol(n, sym_typename) { }
        void add_element(Symbol* e);
        void print(std::ostream &os) const;
    };
    struct type_vec : public std::vector<TypeSymbol*> { };

    struct VariableSymbol : public Symbol {
        mutable Symbol *value;
        VariableSymbol(const char *n) : Symbol(n, sym_variable), value(0) { }
        void print(std::ostream &os) const {
            os << print_name;
            if( sym_type ) os << " - " << sym_type->print_name;
        }
    };
    struct variable_vec : public std::vector<VariableSymbol*> { };

    struct PredicateSymbol : public Symbol {
        variable_vec param;
        ptr_table pos_goal;
        ptr_table neg_goal;
        ptr_table pos_prop;
        ptr_table neg_prop;
        mutable bool strongly_static;
        PredicateSymbol(const char *n) : Symbol(n, sym_predicate), strongly_static(false) { }
        void print(std::ostream &os) const;
    };
    struct predicate_vec : public std::vector<PredicateSymbol*> { };

    struct Atom {
        PredicateSymbol *pred;
        symbol_vec param;
        bool neg;
        Atom(PredicateSymbol *p, bool n = false) : pred(p), neg(n) { }
        Atom(const Atom &atom) : pred(atom.pred), param(atom.param), neg(atom.neg) { }
        bool operator==(const Atom &atom) const;
        Instance::Atom* find_prop(Instance &ins, bool neg, bool create) const;
        void print(std::ostream &os, bool neg) const;
        void print(std::ostream &os) const { print(os, false); }
    };
    struct atom_vec : public std::vector<Atom*> { };

    struct Condition {
        Condition() { }
        virtual ~Condition() { }
        virtual void instantiate(Instance &ins, index_set &condition) const = 0;
        virtual void print(std::ostream &os) const = 0;
    };
    struct condition_vec : public std::vector<const Condition*> { };

    struct Literal : public Condition, Atom {
        Literal(const Atom &atom) : Atom(atom) { }
        virtual ~Literal() { }
        virtual void instantiate(Instance &ins, index_set &condition) const;
        virtual void print(std::ostream &os) const { assert(0); }
    };

    struct EQ : public Condition, std::pair<const Atom*,const Atom*> {
        EQ(const Atom *p, const Atom *q) : std::pair<const Atom*,const Atom*>(p,q) { }
        virtual ~EQ() { }
        virtual void instantiate(Instance &ins, index_set &condition) const;
        virtual void print(std::ostream &os) const { assert(0); }
    };

    struct And : public Condition, condition_vec {
        And() { }
        virtual ~And() { }
        virtual void instantiate(Instance &ins, index_set &condition) const;
        virtual void print(std::ostream &os) const { assert(0); }
    };

    struct Effect {
        Effect() { }
        virtual ~Effect() { }
        virtual void print(std::ostream &os) const = 0;
        virtual void instantiate(Instance &ins, index_set &eff, Instance::Action *act = 0) const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const = 0;
    };
    struct effect_vec : public std::vector<const Effect*> { };

    struct NullEffect : public Effect {
        NullEffect() { }
        virtual ~NullEffect() { }
        virtual void print(std::ostream &os) const { }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::Action *act = 0) const { }
        virtual bool is_strongly_static(const PredicateSymbol &pred) const { return true; }
    };

    struct AtomicEffect : public Effect, Atom {
        AtomicEffect(const Atom &atom) : Atom(atom) { }
        virtual ~AtomicEffect() { }
        virtual void print(std::ostream &os) const { assert(0); }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::Action *act = 0) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
    };

    struct AndEffect : public Effect, effect_vec {
        AndEffect() { }
        virtual ~AndEffect() { }
        virtual void print(std::ostream &os) const { assert(0); }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::Action *act = 0) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
    };

    struct ConditionalEffect : public Effect {
        const Condition *condition;
        const Effect *effect;
        ConditionalEffect(const Condition *cond, const Effect *eff) : condition(cond), effect(eff) { }
        virtual ~ConditionalEffect() { }
        virtual void print(std::ostream &os) const { assert(0); }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::Action *act = 0) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
    };

    struct ForallEffect : public Effect {
        variable_vec param;
        const Effect *effect;
        ForallEffect() : effect(0) { }
        virtual ~ForallEffect() { }
        virtual void print(std::ostream &os) const { assert(0); }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::Action *act = 0) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        void build(Instance &ins, size_t p, index_set &eff, Instance::Action *act) const;
    };

    struct Invariant : public condition_vec {
        Invariant(const condition_vec &invariant) : condition_vec(invariant) { }
        virtual ~Invariant() { }
        virtual void instantiate(Instance &ins, index_vec &invariant) const;
        virtual void print(std::ostream &os) const { assert(0); }
    };

    struct Clause : public condition_vec {
        Clause(const condition_vec &clause) : condition_vec(clause) { }
        virtual ~Clause() { }
        virtual void instantiate(Instance &ins, index_vec &clause) const;
        virtual void print(std::ostream &os) const { assert(0); }
    };

    struct Oneof : public condition_vec {
        Oneof(const condition_vec &oneof) : condition_vec(oneof) { }
        virtual ~Oneof() { }
        virtual void instantiate(Instance &ins, index_vec &oneof) const;
        virtual void print(std::ostream &os) const { assert(0); }
    };

    struct InitElement {
        InitElement() { }
        virtual ~InitElement() { }
        virtual void print(std::ostream &os) const = 0;
        virtual void instantiate(Instance &ins, Instance::Init &init) const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const = 0;
    };
    struct init_element_vec : public std::vector<InitElement*> { };

    struct InitLiteral : public InitElement, Atom {
        InitLiteral(const Atom &atom) : Atom(atom) { }
        virtual ~InitLiteral() { }
        virtual void print(std::ostream &os) const { assert(0); }
        virtual void instantiate(Instance &ins, Instance::Init &init) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
    };

    struct InitInvariant : public InitElement, Invariant {
        InitInvariant(const Invariant &invariant) : Invariant(invariant) { }
        virtual ~InitInvariant() { }
        virtual void print(std::ostream &os) const { assert(0); }
        virtual void instantiate(Instance &ins, Instance::Init &init) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
    };

    struct InitClause : public InitElement, Clause {
        InitClause(const Clause &clause) : Clause(clause) { }
        virtual ~InitClause() { }
        virtual void print(std::ostream &os) const { assert(0); }
        virtual void instantiate(Instance &ins, Instance::Init &init) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
    };

    struct InitOneof : public InitElement, Oneof {
        InitOneof(const Oneof &oneof) : Oneof(oneof) { }
        virtual ~InitOneof() { }
        virtual void print(std::ostream &os) const { assert(0); }
        virtual void instantiate(Instance &ins, Instance::Init &init) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
    };

    struct Action : public Symbol {
        variable_vec param;
        const Condition *precondition;
        const Effect *effect;
        Action(const char *name) : Symbol(name, sym_action), precondition(0), effect(0) { }
        ~Action() { }
        void instantiate(Instance &ins) const;
        void print(std::ostream &os) const;
        void build(Instance &ins, size_t p) const;
    };
    struct action_vec : public std::vector<Action*> { };

    struct Sensor : public Symbol {
        variable_vec param;
        const Condition *condition;
        const Effect *sensed;
        Sensor(const char *name) : Symbol(name, sym_sensor), condition(0), sensed(0) { }
        ~Sensor() { }
        void instantiate(Instance &ins) const;
        void print(std::ostream &os) const;
        void build(Instance &ins, size_t p) const;
    };
    struct sensor_vec : public std::vector<Sensor*> { };

    struct Axiom : public Symbol {
        variable_vec param;
        const Condition *body;
        const Effect *head;
        Axiom(const char *name) : Symbol(name, sym_axiom), body(0), head(0) { }
        ~Axiom() { }
        void instantiate(Instance &ins) const;
        void print(std::ostream &os) const;
        void build(Instance &ins, size_t p) const;
    };
    struct axiom_vec : public std::vector<Axiom*> { };

    struct Observable {
        variable_vec param;
        const Effect *observables;
        Observable() : observables(0) { }
        ~Observable() { }
        void instantiate(Instance &ins) const;
        void print(std::ostream &os) const;
        void build(Instance &ins, size_t p) const;
    };
    struct observable_vec : public std::vector<Observable*> { };

    struct Sticky {
        variable_vec param;
        const Effect *stickies;
        Sticky() : stickies(0) { }
        ~Sticky() { }
        void instantiate(Instance &ins) const;
        void print(std::ostream &os) const;
        void build(Instance &ins, size_t p) const;
    };
    struct sticky_vec : public std::vector<Sticky*> { };

    const char* domain_name;
    const char* problem_name;

    StringTable      &tab;
    type_vec         dom_types;
    TypeSymbol       *dom_top_type;
    symbol_vec       dom_constants;
    predicate_vec    dom_predicates;
    PredicateSymbol  *dom_eq_pred;

    action_vec       dom_actions;
    sensor_vec       dom_sensors;
    axiom_vec        dom_axioms;
    const Condition  *dom_goal;
    init_element_vec dom_init;
    init_element_vec dom_hidden;
    observable_vec   dom_observables;
    sticky_vec       dom_stickies;

    PDDL_Base(StringTable& t);
    ~PDDL_Base();

    void set_variable_type(variable_vec &vec, size_t n, TypeSymbol *t);
    void set_type_type(type_vec &vec, size_t n, TypeSymbol *t);
    void set_constant_type(symbol_vec &vec, size_t n, TypeSymbol *t);
    void clear_param(variable_vec &vec, size_t start = 0);
    void insert_atom(ptr_table &t, Atom *a);
    void calculate_strongly_static_predicates() const;
    void instantiate(Instance &ins) const;
    void print(std::ostream &os) const;
    PredicateSymbol* find_type_predicate(Symbol *type_sym);
};

class InstanceName : public Name {
    const char* domain_name;
    const char* problem_name;
  public:
    InstanceName(const char *d, const char *p) : domain_name(d), problem_name(p) { }
    virtual ~InstanceName() { }
    virtual void write(std::ostream &os, bool cat) const;
};

class PDDL_Name : public Name {
    bool _neg;
    const PDDL_Base::Symbol *_sym;
    PDDL_Base::symbol_vec _arg;
  public:
    PDDL_Name(const PDDL_Base::Symbol *sym, bool n = false) : _neg(n), _sym(sym) { };
    PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::symbol_vec &arg, size_t n);
    PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::variable_vec &arg, size_t n);
    virtual ~PDDL_Name() { }
    void add(PDDL_Base::Symbol *s);
    virtual void write(std::ostream &os, bool cat) const;
};

#endif
