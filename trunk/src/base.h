#ifndef PDDL_BASE_H
#define PDDL_BASE_H

#include "ptr_table.h"
#include "string_table.h"
#include "problem.h"
#include <cassert>
#include <set>
#include <vector>

class PDDL_Base {
  public:
    static bool write_warnings;
    static bool write_info;
    static Instance::when_vec dummy_when_vec;

    enum symbol_class {
        sym_object,
        sym_typename,
        sym_predicate,
        sym_variable,
        sym_action,
        sym_axiom,
        sym_sensor,
        sym_varname
    };

    struct Symbol {
        symbol_class sym_class;
        const char *print_name;
        Symbol *sym_type;
        Symbol(const char *n, symbol_class c = sym_object) : sym_class(c), print_name(n), sym_type(0) { }
        virtual ~Symbol() { /*delete sym_type;*/ }
        virtual Symbol* clone() const;
        virtual void print(std::ostream &os) const { os << print_name; }
    };
    struct symbol_vec : public std::vector<Symbol*> { };

    struct TypeSymbol : public Symbol {
        symbol_vec elements;
        TypeSymbol(const char *n) : Symbol(n, sym_typename) { }
        virtual ~TypeSymbol() { /*for( size_t k = 0; k < elements.size(); ++k ) delete elements[k];*/ }
        virtual Symbol* clone() const;
        void add_element(Symbol* e);
        virtual void print(std::ostream &os) const;
    };
    struct type_symbol_vec : public std::vector<TypeSymbol*> { };

    struct VariableSymbol : public Symbol {
        mutable Symbol *value;
        VariableSymbol(const char *n) : Symbol(n, sym_variable), value(0) { }
        virtual ~VariableSymbol() { delete value; }
        virtual Symbol* clone() const;
        virtual void print(std::ostream &os) const;
    };
    struct var_symbol_vec : public std::vector<VariableSymbol*> { };

    struct PredicateSymbol : public Symbol {
        var_symbol_vec param;
        ptr_table pos_prop;
        ptr_table neg_prop;
        mutable bool strongly_static;
        PredicateSymbol(const char *n) : Symbol(n, sym_predicate), strongly_static(false) { }
        virtual ~PredicateSymbol() { for( size_t k = 0; k < param.size(); ++k ) delete param[k]; }
        virtual Symbol* clone() const;
        virtual void print(std::ostream &os) const;
    };
    struct predicate_symbol_vec : public std::vector<PredicateSymbol*> { };

    struct Atom {
        PredicateSymbol *pred;
        symbol_vec param;
        bool neg;
        Atom(PredicateSymbol *p, bool n = false) : pred(p), neg(n) { }
        Atom(const Atom &atom) : pred(atom.pred), param(atom.param), neg(atom.neg) { }
        ~Atom() { /*delete pred; for( size_t k = 0; k < param.size(); ++k ) delete param[k];*/ }
        bool operator==(const Atom &atom) const;
        Instance::Atom* find_prop(Instance &ins, bool neg, bool create) const;
        Atom* ground() const;
        void print(std::ostream &os, bool extra_neg) const;
        void print(std::ostream &os) const { print(os, false); }
    };
    struct atom_vec : public std::vector<Atom*> { };

    struct Condition {
        Condition() { }
        virtual ~Condition() { }
        virtual void instantiate(Instance &ins, index_set &condition) const = 0;
        virtual Condition* ground() const = 0;
        virtual void print(std::ostream &os) const = 0;
    };
    struct condition_vec : public std::vector<const Condition*> { };

    struct Literal : public Condition, Atom {
        Literal(const Atom &atom) : Atom(atom) { }
        virtual ~Literal() { }
        virtual void instantiate(Instance &ins, index_set &condition) const;
        virtual Condition* ground() const;
        virtual void print(std::ostream &os) const { Atom::print(os); }
    };

    struct EQ : public Condition, std::pair<const VariableSymbol*,const VariableSymbol*> {
        EQ(const VariableSymbol *x, const VariableSymbol *y) : std::pair<const VariableSymbol*,const VariableSymbol*>(x, y) { }
        virtual ~EQ() { }
        virtual void instantiate(Instance &ins, index_set &condition) const;
        virtual Condition* ground() const;
        virtual void print(std::ostream &os) const;
    };

    struct And : public Condition, condition_vec {
        And() { }
        virtual ~And() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void instantiate(Instance &ins, index_set &condition) const;
        virtual Condition* ground() const;
        virtual void print(std::ostream &os) const;
    };

    struct Effect {
        Effect() { }
        virtual ~Effect() { }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec) const = 0;
        virtual Effect* ground() const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const = 0;
        virtual void print(std::ostream &os) const = 0;
    };
    struct effect_vec : public std::vector<const Effect*> { };

    struct NullEffect : public Effect {
        NullEffect() { }
        virtual ~NullEffect() { }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec) const { }
        virtual Effect* ground() const { return new NullEffect(); }
        virtual bool is_strongly_static(const PredicateSymbol &pred) const { return true; }
        virtual void print(std::ostream &os) const { os << "<null-effect>"; }
    };

    struct AtomicEffect : public Effect, Atom {
        AtomicEffect(const Atom &atom) : Atom(atom) { }
        virtual ~AtomicEffect() { }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec) const;
        virtual Effect* ground() const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Atom::print(os); }
    };

    struct AndEffect : public Effect, effect_vec {
        AndEffect() { }
        virtual ~AndEffect() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec) const;
        virtual Effect* ground() const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const;
    };

    struct ConditionalEffect : public Effect {
        const Condition *condition;
        const Effect *effect;
        ConditionalEffect(const Condition *cond, const Effect *eff) : condition(cond), effect(eff) { }
        virtual ~ConditionalEffect() { delete condition; delete effect; }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec) const;
        virtual Effect* ground() const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const;
    };

    struct ForallEffect : public Effect {
        var_symbol_vec param;
        const Effect *effect;
        ForallEffect() : effect(0) { }
        virtual ~ForallEffect() { for( size_t k = 0; k < param.size(); ++k ) delete param[k]; delete effect; }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec) const;
        void build(Instance &ins, size_t p, index_set &eff, Instance::when_vec &when = dummy_when_vec) const;
        virtual Effect* ground() const;
        void build_for_ground(size_t p, AndEffect &result) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const;
    };

    struct Invariant : public condition_vec {
        int type;
        enum { AT_LEAST_ONE = 0, AT_MOST_ONE = 1, EXACTLY_ONE = 2 };
        Invariant(int t, const condition_vec &invariant) : condition_vec(invariant), type(t) { }
        virtual ~Invariant() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void instantiate(Instance &ins, Instance::Invariant &invariant) const;
        virtual void print(std::ostream &os) const;
    };

    struct Clause : public condition_vec {
        Clause(const condition_vec &clause) : condition_vec(clause) { }
        virtual ~Clause() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void instantiate(Instance &ins, Instance::Clause &clause) const;
        virtual void print(std::ostream &os) const;
    };

    struct Oneof : public condition_vec {
        Oneof(const condition_vec &oneof) : condition_vec(oneof) { }
        virtual ~Oneof() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void instantiate(Instance &ins, Instance::Oneof &oneof) const;
        virtual void print(std::ostream &os) const;
    };

    struct InitElement {
        InitElement() { }
        virtual ~InitElement() { }
        virtual void instantiate(Instance &ins, Instance::Init &init) const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const = 0;
        virtual void print(std::ostream &os) const = 0;
    };
    struct init_element_vec : public std::vector<InitElement*> { };

    struct InitLiteral : public InitElement, Atom {
        InitLiteral(const Atom &atom) : Atom(atom) { }
        virtual ~InitLiteral() { }
        virtual void instantiate(Instance &ins, Instance::Init &init) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Atom::print(os); }
    };

    struct InitInvariant : public InitElement, Invariant {
        InitInvariant(const Invariant &invariant) : Invariant(invariant) { }
        virtual ~InitInvariant() { }
        virtual void instantiate(Instance &ins, Instance::Init &init) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Invariant::print(os); }
        using Invariant::instantiate;
    };

    struct InitClause : public InitElement, Clause {
        InitClause(const Clause &clause) : Clause(clause) { }
        virtual ~InitClause() { }
        virtual void instantiate(Instance &ins, Instance::Init &init) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Clause::print(os); }
        using Clause::instantiate;
    };

    struct InitOneof : public InitElement, Oneof {
        InitOneof(const Oneof &oneof) : Oneof(oneof) { }
        virtual ~InitOneof() { }
        virtual void instantiate(Instance &ins, Instance::Init &init) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Oneof::print(os); }
        using Oneof::instantiate;
    };

    struct Action : public Symbol {
        var_symbol_vec param;
        const Condition *precondition;
        const Effect *effect;
        const Effect *observe;
        const Effect *sensing_model;
        Action(const char *name)
          : Symbol(name, sym_action), precondition(0), effect(0), observe(0), sensing_model(0) {
        }
        ~Action() {
            for( size_t k = 0; k < param.size(); ++k )
                delete param[k];
            delete precondition;
            delete effect;
            delete observe;
            delete sensing_model;
        }
        void instantiate(Instance &ins) const;
        void build(Instance &ins, size_t p, int pass) const;
        virtual void print(std::ostream &os) const;
        mutable int action_count_;
    };
    struct action_vec : public std::vector<Action*> { };

    struct Sensor : public Symbol {
        var_symbol_vec param;
        const Condition *condition;
        const Effect *sense;
        Sensor(const char *name) : Symbol(name, sym_sensor), condition(0), sense(0) { }
        ~Sensor() { for( size_t k = 0; k < param.size(); ++k ) delete param[k]; delete condition; delete sense; }
        void instantiate(Instance &ins) const;
        void build(Instance &ins, size_t p) const;
        virtual void print(std::ostream &os) const;
    };
    struct sensor_vec : public std::vector<Sensor*> { };

    struct Axiom : public Symbol {
        var_symbol_vec param;
        const Condition *body;
        const Effect *head;
        Axiom(const char *name) : Symbol(name, sym_axiom), body(0), head(0) { }
        ~Axiom() { for( size_t k = 0; k < param.size(); ++k ) delete param[k]; delete body; delete head; }
        void instantiate(Instance &ins) const;
        void build(Instance &ins, size_t p) const;
        virtual void print(std::ostream &os) const;
    };
    struct axiom_vec : public std::vector<Axiom*> { };

    struct Observable {
        var_symbol_vec param;
        const Effect *observables;
        Observable() : observables(0) { }
        ~Observable() { for( size_t k = 0; k < param.size(); ++k ) delete param[k]; delete observables; }
        void instantiate(Instance &ins) const;
        void build(Instance &ins, size_t p) const;
        void print(std::ostream &os) const;
    };
    struct observable_vec : public std::vector<Observable*> { };

    struct Sticky {
        var_symbol_vec param;
        const Effect *stickies;
        Sticky() : stickies(0) { }
        ~Sticky() { for( size_t k = 0; k < param.size(); ++k ) delete param[k]; delete stickies; }
        void instantiate(Instance &ins) const;
        void build(Instance &ins, size_t p) const;
        void print(std::ostream &os) const;
    };
    struct sticky_vec : public std::vector<Sticky*> { };

    struct Variable : public Symbol {
        effect_vec values;
        Variable(const char *name) : Symbol(name, sym_varname) { }
        virtual ~Variable() { }
        virtual void instantiate(Instance &ins, index_set &values) const = 0;
        virtual void print(std::ostream &os) const = 0;
    };
    struct variable_vec : public std::vector<Variable*> { };

    struct StateVariable : public Variable {
        bool is_observable;
        StateVariable(const char *name) : Variable(name), is_observable(false) { }
        virtual ~StateVariable() { }
        virtual void instantiate(Instance &ins, index_set &values) const;
        virtual void print(std::ostream &os) const;
    };

    struct ObsVariable : public Variable {
        ObsVariable(const char *name) : Variable(name) { }
        virtual ~ObsVariable() { }
        virtual void instantiate(Instance &ins, index_set &values) const;
        virtual void print(std::ostream &os) const;
    };


    const char                      *domain_name;
    const char                      *problem_name;

    StringTable                     &tab;
    type_symbol_vec                 dom_types;
    TypeSymbol                      *dom_top_type;
    symbol_vec                      dom_constants;
    predicate_symbol_vec            dom_predicates;
    PredicateSymbol                 *dom_eq_pred;

    action_vec                      dom_actions;
    sensor_vec                      dom_sensors;
    axiom_vec                       dom_axioms;
    const Condition                 *dom_goal;
    init_element_vec                dom_init;
    std::vector<init_element_vec>   dom_hidden;
    observable_vec                  dom_observables;
    sticky_vec                      dom_stickies;

    // For CLG-type syntax and translations
    Atom                            *disable_actions_atom;

    // For translations
    bool                            translation;
    variable_vec                    dom_variables;
    index_set_vec                   dom_var_values;


    PDDL_Base(StringTable& t);
    ~PDDL_Base();

    void set_variable_type(var_symbol_vec &vec, size_t n, TypeSymbol *t);
    void set_type_type(type_symbol_vec &vec, size_t n, TypeSymbol *t);
    void set_constant_type(symbol_vec &vec, size_t n, TypeSymbol *t);
    void clear_param(var_symbol_vec &vec, size_t start = 0);
    void insert_atom(ptr_table &t, Atom *a);
    void calculate_strongly_static_predicates() const;
    void map_oneofs_to_invariants();
    void translate_observe_effects_into_sensors();
    void do_translation();
    void instantiate(Instance &ins) const;
    void print(std::ostream &os) const;
    PredicateSymbol* find_type_predicate(Symbol *type_sym);
};

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Symbol &sym) {
    sym.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Atom &atom) {
    atom.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Condition &condition) {
    condition.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Effect &effect) {
    effect.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Invariant &invariant) {
    invariant.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Clause &clause) {
    clause.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Oneof &oneof) {
    oneof.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::InitElement &element) {
    element.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Observable &observable) {
    observable.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Sticky &sticky) {
    sticky.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Variable &variable) {
    variable.print(os);
    return os;
}


class PDDL_Name : public Name {
    bool _neg;
    const PDDL_Base::Symbol *_sym;
    PDDL_Base::symbol_vec _arg;
  public:
    PDDL_Name(const PDDL_Base::Symbol *sym, bool neg = false) : _neg(neg), _sym(sym) { };
    PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::symbol_vec &arg, size_t n);
    PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::var_symbol_vec &arg, size_t n);
    virtual ~PDDL_Name() { }
    void add(PDDL_Base::Symbol *s);
    virtual void write(std::ostream &os, bool cat) const;
};

#endif

