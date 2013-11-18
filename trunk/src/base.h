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
    static bool write_warnings_;
    static bool write_info_;
    static Instance::when_vec dummy_when_vec_;


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
        symbol_class sym_class_;
        const char *print_name_;
        Symbol *sym_type_;
        Symbol(const char *n, symbol_class c = sym_object) : sym_class_(c), print_name_(n), sym_type_(0) { }
        virtual ~Symbol() { /*delete sym_type_;*/ }
        virtual Symbol* clone() const;
        virtual void print(std::ostream &os) const { os << print_name_; }
    };
    struct symbol_vec : public std::vector<Symbol*> { };

    struct TypeSymbol : public Symbol {
        symbol_vec elements_;
        TypeSymbol(const char *n) : Symbol(n, sym_typename) { }
        virtual ~TypeSymbol() { /*for( size_t k = 0; k < elements_.size(); ++k ) delete elements_[k];*/ }
        virtual Symbol* clone() const;
        void add_element(Symbol* e);
        virtual void print(std::ostream &os) const;
    };
    struct type_symbol_vec : public std::vector<TypeSymbol*> { };

    struct VariableSymbol : public Symbol {
        mutable Symbol *value_;
        VariableSymbol(const char *n) : Symbol(n, sym_variable), value_(0) { }
        virtual ~VariableSymbol() { /*delete value_;*/ }
        virtual Symbol* clone() const;
        virtual void print(std::ostream &os) const;
    };
    struct var_symbol_vec : public std::vector<VariableSymbol*> { };

    struct PredicateSymbol : public Symbol {
        var_symbol_vec param_;
        ptr_table pos_prop_;
        ptr_table neg_prop_;
        mutable bool strongly_static_;
        PredicateSymbol(const char *n) : Symbol(n, sym_predicate), strongly_static_(false) { }
        virtual ~PredicateSymbol() { for( size_t k = 0; k < param_.size(); ++k ) delete param_[k]; }
        virtual Symbol* clone() const;
        virtual void print(std::ostream &os) const;
    };
    struct predicate_symbol_vec : public std::vector<PredicateSymbol*> { };

    struct Schema {
        var_symbol_vec param_;
        Schema() { }
        virtual ~Schema() { /*for( size_t k = 0; k < param_.size(); ++k ) delete param_[k];*/ }
        void enumerate(bool only_count = false) const;
        void rec_enumerate(size_t p, bool only_count) const;
        virtual void process_instance() const = 0;
        mutable int count_;
    };

    struct Atom {
        PredicateSymbol *pred_;
        symbol_vec param_;
        bool negated_;
        Atom(PredicateSymbol *pred, bool negated = false) : pred_(pred), negated_(negated) { }
        Atom(const Atom &atom) : pred_(atom.pred_), param_(atom.param_), negated_(atom.negated_) { }
        ~Atom() { /*delete pred_; for( size_t k = 0; k < param_.size(); ++k ) delete param_[k];*/ }
        void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        bool operator==(const Atom &atom) const;
        Instance::Atom* find_prop(Instance &ins, bool negated, bool create) const;
        void instantiate(Instance &ins, index_set &atoms) const;
        Atom* ground() const;
        std::string print_name(bool extra_neg = false) const;
        void print(std::ostream &os, bool extra_neg) const;
        void print(std::ostream &os) const { print(os, false); }
    };
    struct atom_vec : public std::vector<Atom*> { };

    struct Condition {
        Condition() { }
        virtual ~Condition() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) = 0;
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) = 0;
        virtual void instantiate(Instance &ins, index_set &condition) const = 0;
        virtual Condition* ground() const = 0;
        virtual void print(std::ostream &os) const = 0;
    };
    struct condition_vec : public std::vector<const Condition*> { };

    struct Constant : public Condition {
        bool value_;
        Constant(bool value) : value_(value) { }
        virtual ~Constant() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) { }
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) { }
        virtual void instantiate(Instance &ins, index_set &condition) const { }
        virtual Condition* ground() const { return new Constant(value_); }
        virtual void print(std::ostream &os) const { os << (value_ ? "true" : "false"); }
    };

    struct Literal : public Condition, Atom {
        Literal(const Atom &atom) : Atom(atom) { }
        virtual ~Literal() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void instantiate(Instance &ins, index_set &condition) const;
        virtual Condition* ground() const;
        virtual void print(std::ostream &os) const { Atom::print(os); }
    };

    struct EQ : public Condition, std::pair<const VariableSymbol*,const VariableSymbol*> {
        bool negated_;
        EQ(const VariableSymbol *x, const VariableSymbol *y, bool negated = false)
          : std::pair<const VariableSymbol*,const VariableSymbol*>(x, y), negated_(negated) { }
        virtual ~EQ() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void instantiate(Instance &ins, index_set &condition) const { }
        virtual Condition* ground() const;
        virtual void print(std::ostream &os) const;
    };

    struct And : public Condition, condition_vec {
        And() { }
        virtual ~And() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void instantiate(Instance &ins, index_set &condition) const;
        virtual Condition* ground() const;
        virtual void print(std::ostream &os) const;
    };

    struct Effect {
        Effect() { }
        virtual ~Effect() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) = 0;
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) = 0;
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const = 0;
        virtual Effect* ground() const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const = 0;
        virtual void print(std::ostream &os) const = 0;
    };
    struct effect_vec : public std::vector<const Effect*> { };

    struct NullEffect : public Effect {
        NullEffect() { }
        virtual ~NullEffect() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) { }
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) { }
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const { }
        virtual Effect* ground() const { return new NullEffect; }
        virtual bool is_strongly_static(const PredicateSymbol &pred) const { return true; }
        virtual void print(std::ostream &os) const { os << "<null>"; }
    };

    struct AtomicEffect : public Effect, Atom {
        AtomicEffect(const Atom &atom) : Atom(atom) { }
        virtual ~AtomicEffect() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual Effect* ground() const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Atom::print(os); }
    };

    struct AndEffect : public Effect, effect_vec {
        AndEffect() { }
        virtual ~AndEffect() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual Effect* ground() const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const;
    };

    struct ConditionalEffect : public Effect {
        const Condition *condition_;
        const Effect *effect_;
        ConditionalEffect(const Condition *condition, const Effect *effect)
          : condition_(condition), effect_(effect) { }
        virtual ~ConditionalEffect() { delete condition_; delete effect_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual Effect* ground() const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const;
    };

    struct ForallEffect : public Effect, Schema {
        const Effect *effect_;
        ForallEffect() : effect_(0) { }
        virtual ~ForallEffect() { delete effect_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void instantiate(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual void process_instance() const;
        virtual Effect* ground() const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const;
        mutable std::vector<AndEffect*> result_stack;
    };

    struct Invariant : public condition_vec, Schema {
        int type_;
        enum { AT_LEAST_ONE = 0, AT_MOST_ONE = 1, EXACTLY_ONE = 2 };
        Invariant(int type) : type_(type) { }
        Invariant(int type, const condition_vec &invariant) : condition_vec(invariant), type_(type) { }
        virtual ~Invariant() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
        mutable Instance::invariant_vec *invariant_vec_ptr_;
        mutable Instance *instance_ptr_;
    };

    struct Clause : public condition_vec {
        Clause(const condition_vec &clause) : condition_vec(clause) { }
        virtual ~Clause() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        void instantiate(Instance &ins, Instance::Clause &clause) const;
        virtual void print(std::ostream &os) const;
    };

    struct Oneof : public condition_vec {
        Oneof() { }
        Oneof(const condition_vec &oneof) : condition_vec(oneof) { }
        virtual ~Oneof() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        void instantiate(Instance &ins, Instance::Oneof &oneof) const;
        virtual void print(std::ostream &os) const;
    };

    struct InitElement {
        InitElement() { }
        virtual ~InitElement() { }
        virtual void instantiate(Instance &ins) const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const = 0;
        virtual void print(std::ostream &os) const = 0;
    };
    struct init_element_vec : public std::vector<InitElement*> { };

    struct InitLiteral : public InitElement, Atom {
        InitLiteral(const Atom &atom) : Atom(atom) { }
        virtual ~InitLiteral() { }
        void instantiate(Instance &ins, Instance::Init &state) const;
        virtual void instantiate(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Atom::print(os); }
    };

    struct InitInvariant : public InitElement, Invariant {
        InitInvariant(const Invariant &invariant) : Invariant(invariant) { }
        virtual ~InitInvariant() { }
        virtual void instantiate(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Invariant::print(os); }
    };

    struct InitClause : public InitElement, Clause {
        InitClause(const Clause &clause) : Clause(clause) { }
        virtual ~InitClause() { }
        virtual void instantiate(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Clause::print(os); }
        using Clause::instantiate;
    };

    struct InitOneof : public InitElement, Oneof {
        InitOneof(const Oneof &oneof) : Oneof(oneof) { }
        virtual ~InitOneof() { }
        virtual void instantiate(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void print(std::ostream &os) const { Oneof::print(os); }
        using Oneof::instantiate;
    };

    struct Action : public Symbol, Schema {
        const Condition *precondition_;
        const Effect *effect_;
        const Effect *observe_;
        const Effect *sensing_model_;
        Action(const char *name)
          : Symbol(name, sym_action), precondition_(0), effect_(0), observe_(0), sensing_model_(0) {
        }
        virtual ~Action() { delete precondition_; delete effect_; delete observe_; delete sensing_model_; }
        void instantiate(Instance &ins) const;
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
        mutable Instance *instance_ptr_;
    };
    struct action_vec : public std::vector<Action*> { };

    struct Sensor : public Symbol, Schema {
        const Condition *condition_;
        const Effect *sense_;
        Sensor(const char *name) : Symbol(name, sym_sensor), condition_(0), sense_(0) { }
        virtual ~Sensor() { delete condition_; delete sense_; }
        void instantiate(Instance &ins) const;
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
        mutable Instance *instance_ptr_;
    };
    struct sensor_vec : public std::vector<Sensor*> { };

    struct Axiom : public Symbol, Schema {
        const Condition *body_;
        const Effect *head_;
        Axiom(const char *name) : Symbol(name, sym_axiom), body_(0), head_(0) { }
        virtual ~Axiom() { delete body_; delete head_; }
        void instantiate(Instance &ins) const;
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
        mutable Instance *instance_ptr_;
    };
    struct axiom_vec : public std::vector<Axiom*> { };

    struct Observable {
        effect_vec observables_;
        Observable() { }
        ~Observable() { for( size_t k = 0; k < observables_.size(); ++k ) delete observables_[k]; }
        void instantiate(Instance &ins) const;
        void print(std::ostream &os) const;
    };
    struct observable_vec : public std::vector<Observable*> { };

    struct Sticky {
        effect_vec stickies_;
        Sticky() { }
        ~Sticky() { for( size_t k = 0; k < stickies_.size(); ++k ) delete stickies_[k]; }
        void instantiate(Instance &ins) const;
        void print(std::ostream &os) const;
    };
    struct sticky_vec : public std::vector<Sticky*> { };

    struct Variable : public Symbol, Schema {
        effect_vec values_;
        mutable effect_vec grounded_values_;
        Variable(const char *name) : Symbol(name, sym_varname) { }
        virtual ~Variable() {
            for( size_t k = 0; k < values_.size(); ++k )
                delete values_[k];
            for( size_t k = 0; k < grounded_values_.size(); ++k )
                delete grounded_values_[k];
        }
        //void instantiate(Instance &ins, index_set &values) const;
        void instantiate(std::vector<Variable*> &grounded_variables) const;
        virtual void process_instance() const;
        virtual Variable* make_instance(const char *name) const = 0;
        virtual bool is_observable() const = 0;
        virtual void print(std::ostream &os) const = 0;
        mutable std::vector<Variable*> *grounded_variables_ptr_;
    };
    struct variable_vec : public std::vector<Variable*> { };

    struct StateVariable : public Variable {
        bool is_observable_;
        StateVariable(const char *name, bool is_observable = false) : Variable(name), is_observable_(is_observable) { }
        virtual ~StateVariable() { }
        virtual Variable* make_instance(const char *name) const { return new StateVariable(name, is_observable_); }
        virtual bool is_observable() const { return is_observable_; }
        virtual void print(std::ostream &os) const;
    };

    struct ObsVariable : public Variable {
        ObsVariable(const char *name) : Variable(name) { }
        virtual ~ObsVariable() { }
        virtual Variable* make_instance(const char *name) const { return new ObsVariable(name); }
        virtual bool is_observable() const { return true; }
        virtual void print(std::ostream &os) const;
    };


    const char                                *domain_name_;
    const char                                *problem_name_;

    StringTable                               &tab_;
    type_symbol_vec                           dom_types_;
    TypeSymbol                                *dom_top_type_;
    symbol_vec                                dom_constants_;
    predicate_symbol_vec                      dom_predicates_;
    PredicateSymbol                           *dom_eq_pred_;

    action_vec                                dom_actions_;
    sensor_vec                                dom_sensors_;
    axiom_vec                                 dom_axioms_;
    const Condition                           *dom_goal_;
    init_element_vec                          dom_init_;
    std::vector<init_element_vec>             dom_hidden_;

    effect_vec                                *tmp_effect_vec_ptr_; // only used when parsing
    observable_vec                            dom_observables_;
    sticky_vec                                dom_stickies_;

    // For CLG-type syntax and translations
    bool                                      clg_translation_;
    Atom                                      *disable_actions_atom_;

    // For multivalued variables formulations
    bool                                      multivalued_variable_translation_;
    variable_vec                              multivalued_variables_;
    std::pair<const Atom*, const Atom*>       normal_execution_;
    std::pair<const Atom*, const Atom*>       sensing_;
    std::vector<std::pair<Atom*, Atom*> >     need_sense_;
    std::vector<std::pair<Atom*, Atom*> >     need_post_;
    const Effect                              *default_sensing_model_;
    std::vector<std::pair<std::pair<const var_symbol_vec*, const Effect*>, size_t> > sensing_models_;


    PDDL_Base(StringTable& t);
    ~PDDL_Base();

    void set_variable_type(var_symbol_vec &vec, size_t n, TypeSymbol *t);
    void set_type_type(type_symbol_vec &vec, size_t n, TypeSymbol *t);
    void set_constant_type(symbol_vec &vec, size_t n, TypeSymbol *t);
    void clear_param(var_symbol_vec &vec, size_t start = 0);
    void insert_atom(ptr_table &t, Atom *a);
    void calculate_strongly_static_predicates() const;
    void instantiate(Instance &ins) const;
    void print(std::ostream &os) const;
    PredicateSymbol* find_type_predicate(Symbol *type_sym);

    // methods for formulations in CLG-like syntax
    void declare_clg_translation();
    void map_oneofs_to_invariants();
    void translate_observe_effects_into_sensors();

    // methods for formulations in terms of multivalued variables
    void declare_multivalued_variable_translation();
    void instantiate_multivalued_variables();
    void translate_actions_for_multivalued_variable_formulation();
    void translation_for_multivalued_variable_formulation(Action &action, size_t index);
    void create_invariants_for_multivalued_variables();
    void create_invariants_for_sensing_model();
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
    bool negated_;
    const PDDL_Base::Symbol *sym_;
    PDDL_Base::symbol_vec arg_;
  public:
    PDDL_Name(const PDDL_Base::Symbol *sym, bool negated = false) : negated_(negated), sym_(sym) { };
    PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::symbol_vec &arg, size_t n);
    PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::var_symbol_vec &arg, size_t n);
    virtual ~PDDL_Name() { }
    void add(PDDL_Base::Symbol *s);
    virtual void write(std::ostream &os, bool cat) const;
};

#endif

