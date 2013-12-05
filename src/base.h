#ifndef PDDL_BASE_H
#define PDDL_BASE_H

#include "ptr_table.h"
#include "string_table.h"
#include "options.h"
#include "problem.h"
#include <cassert>
#include <list>
#include <map>
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
        virtual std::string to_string() const { return std::string(print_name_); }
        void print(std::ostream &os) const { os << to_string(); }
    };
    struct symbol_vec : public std::vector<Symbol*> { };

    struct TypeSymbol : public Symbol {
        symbol_vec elements_;
        TypeSymbol(const char *n) : Symbol(n, sym_typename) { }
        virtual ~TypeSymbol() { /*for( size_t k = 0; k < elements_.size(); ++k ) delete elements_[k];*/ }
        virtual Symbol* clone() const;
        void add_element(Symbol* e);
        virtual std::string to_string() const;
    };
    struct type_symbol_vec : public std::vector<TypeSymbol*> { };

    struct VariableSymbol : public Symbol {
        mutable Symbol *value_;
        VariableSymbol(const char *n) : Symbol(n, sym_variable), value_(0) { }
        virtual ~VariableSymbol() { /*delete value_;*/ }
        virtual Symbol* clone() const;
        virtual std::string to_string() const;
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
        virtual std::string to_string() const;
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
        Atom(const Atom &atom, bool complemented = false)
          : pred_(atom.pred_), param_(atom.param_), negated_(complemented ? !atom.negated_ : atom.negated_) { }
        ~Atom() { /*delete pred_; for( size_t k = 0; k < param_.size(); ++k ) delete param_[k];*/ }
        void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        bool operator==(const Atom &atom) const;
        bool operator<(const Atom &atom) const;
        const Atom& operator=(const Atom &atom);
        Instance::Atom* find_prop(Instance &ins, bool negated, bool create) const;
        void emit(Instance &ins, index_set &atoms) const;
        Atom* ground(bool clone_variables) const;
        bool has_free_variables(const var_symbol_vec &param) const;
        bool is_fully_instantiated() const;

        std::string to_string(bool extra_neg = false, bool mangled = false) const;
        void print(std::ostream &os, bool extra_neg = false) const { os << to_string(extra_neg); }
        static PDDL_Base *pddl_base_;
    };
    struct atom_vec : public std::vector<Atom*> { };
    struct unsigned_atom_vec : public std::vector<Atom> { };
    struct unsigned_atom_set : public std::set<Atom> { };

    struct Condition {
        Condition() : grounded_pos_(0), grounded_neg_(0) { }
        virtual ~Condition() { delete grounded_pos_; delete grounded_neg_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) = 0;
        virtual void emit(Instance &ins, index_set &condition) const = 0;
        virtual Condition* clone(bool clone_variables = false) const = 0;
        virtual Condition* ground(bool clone_variables = false, bool negate = false) const = 0;
        virtual bool has_free_variables(const var_symbol_vec &param) const = 0;
        virtual void extract_atoms(unsigned_atom_set &atoms) const = 0;
        virtual std::string to_string() const = 0;
        void print(std::ostream &os) const { os << to_string(); }
        Condition* negate() const { return ground(false, true); }
        Condition* copy() const { return ground(false, false); }

        // cache for grounded conditions
        mutable const Condition *grounded_pos_;
        mutable const Condition *grounded_neg_;
#if 0
        const Condition* fetch_cache(bool negate) const { return negate ? grounded_neg_ : grounded_pos_; }
        void update_cache(bool negate, const Condition *grounded) const {
            if( negate )
                grounded_neg_ = grounded;
            else
                grounded_pos_ = grounded;
        }
#else
        const Condition* fetch_cache(bool negate) const { return 0; }
        void update_cache(bool negate, const Condition *grounded) const { }
#endif
    };
    struct condition_vec : public std::vector<const Condition*> { };

    struct Constant : public Condition {
        bool value_;
        Constant(bool value) : value_(value) { }
        virtual ~Constant() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) { }
        virtual void emit(Instance &ins, index_set &condition) const { }
        virtual Condition* clone(bool clone_variables = false) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const { return true; }
        virtual void extract_atoms(unsigned_atom_set &atoms) const { }
        virtual std::string to_string() const { return std::string(value_ ? "true" : "false"); }
    };

    struct Literal : public Condition, Atom {
        Literal(const Atom &atom, bool complemented = false) : Atom(atom, complemented) { }
        virtual ~Literal() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual Condition* clone(bool clone_variables = false) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual std::string to_string() const { return to_string(false, false); }
        std::string to_string(bool extra_negation, bool mangled) const { return Atom::to_string(false, mangled); }
    };

    struct EQ : public Condition, std::pair<const Symbol*,const Symbol*> {
        bool negated_;
        EQ(const Symbol *x, const Symbol *y, bool negated = false)
          : std::pair<const Symbol*,const Symbol*>(x, y), negated_(negated) { }
        virtual ~EQ() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const { }
        virtual Condition* clone(bool clone_variables = false) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const { }
        virtual std::string to_string() const;
    };

    struct And : public Condition, condition_vec {
        And() { }
        And(const condition_vec &vec) : condition_vec(vec) { }
        virtual ~And() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual Condition* clone(bool clone_variables = false) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual std::string to_string() const;
    };

    struct Or : public Condition, condition_vec {
        Or() { }
        Or(const condition_vec &vec) : condition_vec(vec) { }
        virtual ~Or() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual Condition* clone(bool clone_variables = false) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual std::string to_string() const;
    };

    struct ForallCondition : public Condition, Schema {
        const Condition *condition_;
        ForallCondition() : condition_(0) { }
        virtual ~ForallCondition() { delete condition_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual void process_instance() const;
        virtual Condition* clone(bool clone_variables = false) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual std::string to_string() const;
        mutable std::vector<bool> negate_stack_;
        mutable std::vector<bool> clone_variables_stack_;
        mutable std::vector<Condition*> result_stack_;
    };

    struct ExistCondition : public Condition, Schema {
        const Condition *condition_;
        ExistCondition() : condition_(0) { }
        virtual ~ExistCondition() { delete condition_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual void process_instance() const;
        virtual Condition* clone(bool clone_variables = false) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual std::string to_string() const;
        mutable std::vector<bool> negate_stack_;
        mutable std::vector<bool> clone_variables_stack_;
        mutable std::vector<Condition*> result_stack_;
    };

    struct Variable;
    struct Effect;
    struct effect_vec : public std::vector<const Effect*> { };
    struct effect_list : public std::list<const Effect*> { };

    struct Effect {
        Effect() { }
        virtual ~Effect() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) = 0;
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const = 0;
        virtual Effect* clone(bool clone_variables = false) const = 0;
        virtual Effect* ground(bool clone_variables = false) const = 0;
        virtual bool has_free_variables(const var_symbol_vec &param) const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const = 0;
        virtual void calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const = 0;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const = 0;
        virtual Effect* reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const = 0;
        virtual void extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const = 0;
        virtual std::string to_string() const = 0;
        void print(std::ostream &os) const { os << to_string(); }
    };

    struct NullEffect : public Effect {
        NullEffect() { }
        virtual ~NullEffect() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) { }
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const { }
        virtual Effect* clone(bool clone_variables = false) const { return 0; }
        virtual Effect* ground(bool clone_variables = false) const { return 0; }
        virtual bool has_free_variables(const var_symbol_vec &param) const { return true; }
        virtual bool is_strongly_static(const PredicateSymbol &pred) const { return true; }
        virtual void calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const { }
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const { }
        virtual Effect* reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const { return 0; }
        virtual void extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const { }
        virtual std::string to_string() const { return std::string("<null>"); }
    };

    struct AtomicEffect : public Effect, Atom {
        AtomicEffect(const Atom &atom, bool complemented = false) : Atom(atom, complemented) { }
        virtual ~AtomicEffect() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual Effect* clone(bool clone_variables = false) const;
        virtual Effect* ground(bool clone_variables = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const;
        virtual Effect* reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const;
        virtual void extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const;
        virtual std::string to_string() const { return to_string(false); }
        std::string to_string(bool mangled) const { return Atom::to_string(false, mangled); }
        AtomicEffect* negate() const { return internal_ground(false, true); }
        AtomicEffect* copy() const { return internal_ground(false, false); }
      private:
        AtomicEffect* internal_ground(bool clone_variables, bool negate) const;
    };

    struct AndEffect : public Effect, effect_vec {
        AndEffect() { }
        AndEffect(const effect_vec &vec) : effect_vec(vec) { }
        virtual ~AndEffect() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual Effect* clone(bool clone_variables = false) const;
        virtual Effect* ground(bool clone_variables = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const;
        virtual Effect* reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const;
        virtual void extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const;
        virtual std::string to_string() const;
    };

    struct ConditionalEffect : public Effect {
        const Condition *condition_;
        const Effect *effect_;
        ConditionalEffect(const Condition *condition, const Effect *effect)
          : condition_(condition), effect_(effect) { }
        virtual ~ConditionalEffect() { delete condition_; delete effect_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual Effect* clone(bool clone_variables = false) const;
        virtual Effect* ground(bool clone_variables = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const;
        virtual Effect* reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const;
        virtual void extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const;
        virtual std::string to_string() const;
    };

    struct ForallEffect : public Effect, Schema {
        const Effect *effect_;
        ForallEffect() : effect_(0) { }
        virtual ~ForallEffect() { delete effect_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual void process_instance() const;
        virtual Effect* clone(bool clone_variables = false) const;
        virtual Effect* ground(bool clone_variables = false) const;
        virtual bool has_free_variables(const var_symbol_vec &param) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const;
        virtual Effect* reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const;
        virtual void extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const;
        virtual std::string to_string() const;
        mutable std::vector<AndEffect*> result_stack_;
        mutable std::vector<bool> clone_variables_stack_;
    };

    struct Invariant : public condition_vec, Schema {
        int type_;
        enum { AT_LEAST_ONE = 0, AT_MOST_ONE = 1, EXACTLY_ONE = 2 };
        Invariant(int type) : type_(type) { }
        Invariant(int type, const condition_vec &invariant) : condition_vec(invariant), type_(type) { }
        virtual ~Invariant() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void process_instance() const;
        bool reduce();
        bool has_free_variables() const;
        std::string to_string() const;
        void print(std::ostream &os) const { os << to_string(); }
        mutable Instance::invariant_vec *invariant_vec_ptr_;
        mutable std::list<Invariant*> *invariant_list_ptr_;
    };

    struct Clause : public condition_vec {
        Clause() { }
        Clause(const condition_vec &clause) : condition_vec(clause) { }
        virtual ~Clause() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        void emit(Instance &ins, Instance::Clause &clause) const;
        std::string to_string() const;
        void print(std::ostream &os) const { os << to_string(); }
    };

    struct Oneof : public condition_vec {
        Oneof() { }
        Oneof(const condition_vec &oneof) : condition_vec(oneof) { }
        virtual ~Oneof() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        void emit(Instance &ins, Instance::Oneof &oneof) const;
        std::string to_string() const;
        void print(std::ostream &os) const { os << to_string(); }
    };

    struct InitElement;
    struct init_element_vec : public std::vector<InitElement*> { };
    struct init_element_list : public std::list<InitElement*> { };

    struct InitElement {
        InitElement() { }
        virtual ~InitElement() { }
        virtual void instantiate(init_element_list &ilist) const = 0;
        virtual void emit(Instance &ins) const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const = 0;
        virtual void extract_atoms(unsigned_atom_set &atoms) const = 0;
        virtual void print(std::ostream &os) const = 0;
    };

    struct InitLiteral : public InitElement, Atom {
        InitLiteral(const Atom &atom) : Atom(atom) { }
        virtual ~InitLiteral() { }
        void emit(Instance &ins, Instance::Init &state) const;
        virtual void instantiate(init_element_list &ilist) const;
        virtual void emit(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual void print(std::ostream &os) const { Atom::print(os); }
    };

    struct InitInvariant : public InitElement, Invariant {
        InitInvariant(const Invariant &invariant) : Invariant(invariant) { }
        virtual ~InitInvariant() { }
        virtual void instantiate(init_element_list &ilist) const;
        virtual void emit(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual void print(std::ostream &os) const { Invariant::print(os); }
    };

    struct InitClause : public InitElement, Clause {
        InitClause(const Clause &clause) : Clause(clause) { }
        virtual ~InitClause() { }
        virtual void instantiate(init_element_list &ilist) const;
        virtual void emit(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual void print(std::ostream &os) const { Clause::print(os); }
        using Clause::emit;
    };

    struct InitOneof : public InitElement, Oneof {
        InitOneof(const Oneof &oneof) : Oneof(oneof) { }
        virtual ~InitOneof() { }
        virtual void instantiate(init_element_list &ilist) const;
        virtual void emit(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &pred) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual void print(std::ostream &os) const { Oneof::print(os); }
        using Oneof::emit;
    };

    struct Action;
    struct action_vec : public std::vector<Action*> { };
    struct action_list : public std::list<Action*> { };

    struct Action : public Symbol, Schema {
        const Condition *precondition_;
        const Effect *effect_;
        const Effect *observe_;
        const Effect *sensing_model_;
        Action(const char *name)
          : Symbol(name, sym_action), precondition_(0), effect_(0), observe_(0), sensing_model_(0) { }
        virtual ~Action() { delete precondition_; delete effect_; delete observe_; delete sensing_model_; }
        void instantiate(action_list &alist) const;
        void emit(Instance &ins) const;
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
        mutable std::list<Action*> *action_list_ptr_;
    };

    struct Sensor;
    struct sensor_vec : public std::vector<Sensor*> { };
    struct sensor_list : public std::list<Sensor*> { };

    struct Sensor : public Symbol, Schema {
        const Condition *condition_;
        const Effect *sense_;
        Sensor(const char *name) : Symbol(name, sym_sensor), condition_(0), sense_(0) { }
        virtual ~Sensor() { delete condition_; delete sense_; }
        void instantiate(sensor_list &slist) const;
        void emit(Instance &ins) const;
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
        mutable sensor_list *sensor_list_ptr_;
    };

    struct Axiom;
    struct axiom_vec : public std::vector<Axiom*> { };
    struct axiom_list : public std::list<Axiom*> { };

    struct Axiom : public Symbol, Schema {
        const Condition *body_;
        const Effect *head_;
        Axiom(const char *name) : Symbol(name, sym_axiom), body_(0), head_(0) { }
        virtual ~Axiom() { delete body_; delete head_; }
        void instantiate(axiom_list &alist) const;
        void emit(Instance &ins) const;
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
        mutable axiom_list *axiom_list_ptr_;
    };

    struct Observable {
        effect_vec observables_;
        Observable() { }
        ~Observable() { for( size_t k = 0; k < observables_.size(); ++k ) delete observables_[k]; }
        void emit(Instance &ins) const;
        void print(std::ostream &os) const;
    };
    struct observable_vec : public std::vector<Observable*> { };

    struct Sticky {
        effect_vec stickies_;
        Sticky() { }
        ~Sticky() { for( size_t k = 0; k < stickies_.size(); ++k ) delete stickies_[k]; }
        void emit(Instance &ins) const;
        void print(std::ostream &os) const;
    };
    struct sticky_vec : public std::vector<Sticky*> { };

    struct Variable;
    struct variable_vec : public std::vector<Variable*> { };
    struct variable_list : public std::list<Variable*> { };

    struct Variable : public Symbol, Schema {
        bool grounded_;
        effect_vec values_;
        effect_vec grounded_values_;
        std::vector<unsigned_atom_set> beam_;
        Variable(const char *name) : Symbol(name, sym_varname), grounded_(false) { }
        virtual ~Variable() {
            for( size_t k = 0; k < values_.size(); ++k )
                delete values_[k];
            for( size_t k = 0; k < grounded_values_.size(); ++k )
                delete grounded_values_[k];
        }
        void instantiate(variable_list &vlist) const;
        virtual void process_instance() const;
        virtual Variable* make_instance(const char *name) const = 0;
        virtual bool is_state_variable() const = 0;
        virtual bool is_observable_variable() const = 0;
        virtual void print(std::ostream &os) const = 0;
        mutable variable_vec *grounded_variables_ptr_;
        mutable variable_list *variable_list_ptr_;
    };

    struct StateVariable : public Variable {
        bool is_observable_;
        StateVariable(const char *name, bool is_observable = false) : Variable(name), is_observable_(is_observable) { }
        virtual ~StateVariable() { }
        virtual Variable* make_instance(const char *name) const { return new StateVariable(name, is_observable_); }
        virtual bool is_state_variable() const { return true; }
        virtual bool is_observable_variable() const { return is_observable_; }
        virtual void print(std::ostream &os) const;
    };

    struct ObsVariable : public Variable {
        ObsVariable(const char *name) : Variable(name) { }
        virtual ~ObsVariable() { }
        virtual Variable* make_instance(const char *name) const { return new ObsVariable(name); }
        virtual bool is_state_variable() const { return false; }
        virtual bool is_observable_variable() const { return true; }
        virtual void print(std::ostream &os) const;
    };


    const char                                *domain_name_;
    const char                                *problem_name_;

    StringTable                               &tab_;
    const Options::Mode                       &options_;

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
    unsigned_atom_set                         dom_static_atoms_;

    observable_vec                            dom_observables_;
    sticky_vec                                dom_stickies_;

    // For CLG-type syntax and translations
    bool                                      clg_translation_;
    Atom                                      *clg_disable_actions_;

    // For multivalued variables formulations
    bool                                      multivalued_variable_translation_;
    variable_vec                              multivalued_variables_;
    const Atom                                *normal_execution_;
    std::vector<const Atom*>                  need_sense_;
    std::vector<const Atom*>                  need_post_;
    const Effect                              *default_sensing_model_;
    std::vector<std::pair<const var_symbol_vec*, const Effect*> > sensing_models_;
    unsigned_atom_set                         observable_atoms_;
    unsigned_atom_set                         atoms_for_state_variables_;
    unsigned_atom_set                         static_observable_atoms_;
    axiom_list                                axioms_for_compiled_sensing_models_;


    PDDL_Base(StringTable& t, const Options::Mode &options);
    ~PDDL_Base();

    void set_variable_type(var_symbol_vec &vec, size_t n, TypeSymbol *t);
    void set_type_type(type_symbol_vec &vec, size_t n, TypeSymbol *t);
    void set_constant_type(symbol_vec &vec, size_t n, TypeSymbol *t);
    void clear_param(var_symbol_vec &vec, size_t start = 0);
    void insert_atom(ptr_table &t, Atom *a);
    PredicateSymbol* find_type_predicate(Symbol *type_sym);

    void calculate_strongly_static_predicates() const;
    bool truth_value_in_initial_situation(const Atom &literal) const;
    void instantiate_elements();
    void calculate_static_atoms();
    bool is_static_atom(const Atom &atom) const;

    void do_translations(variable_vec &multivalued_variables);
    void emit_instance(Instance &ins) const;
    void print(std::ostream &os) const;

    // methods for formulations in CLG-like syntax
    void declare_clg_translation();
    bool clg_translation() const { return clg_translation_; }
    void clg_map_oneofs_and_clauses_to_invariants();
    void clg_translate_observe_effects_into_sensors();

    // methods for formulations in terms of multivalued variables
    void declare_multivalued_variable_translation();
    bool multivalued_variable_translation() const { return multivalued_variable_translation_; }
    void calculate_atoms_for_state_variables();
    void calculate_observable_atoms();
    void calculate_beams_for_grounded_observable_variables();
    void calculate_beam_for_grounded_variable(Variable &var);
    void compile_static_observable_fluents(const Atom &atom);
    void translate_actions_for_multivalued_variable_formulation();
    void translation_for_multivalued_variable_formulation(Action &action, size_t index);
    void create_invariants_for_multivalued_variables();
    void create_invariants_for_sensing_model();
};

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Symbol &sym) {
    sym.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Action &action) {
    action.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Sensor &sensor) {
    sensor.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Axiom &axiom) {
    axiom.print(os);
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

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::InitElement &ielement) {
    ielement.print(os);
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
    std::string to_string(bool cat = false) const;
};

#endif

