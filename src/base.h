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

#ifndef PDDL_BASE_H
#define PDDL_BASE_H

#include "ptr_table.h"
#include "string_table.h"
#include "options.h"
#include "problem.h"
#include <cassert>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#pragma GCC diagnostic ignored "-Wpragmas"

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
        sym_varname,
        sym_vargroup,
        sym_varinst
    };

    struct Symbol {
        symbol_class sym_class_;
        std::string print_name_;
        Symbol *sym_type_;
        Symbol(const std::string &name, symbol_class c = sym_object) : sym_class_(c), print_name_(name), sym_type_(0) { }
        virtual ~Symbol() { /*delete sym_type_;*/ }
        virtual Symbol* clone() const;
        virtual std::string to_string() const { return print_name_; }
        void print(std::ostream &os) const { os << to_string(); }
    };
    struct symbol_vec : public std::vector<Symbol*> { };

    struct TypeSymbol : public Symbol {
        symbol_vec elements_;
        TypeSymbol(const std::string &name) : Symbol(name, sym_typename) { }
        virtual ~TypeSymbol() { /*for( size_t k = 0; k < elements_.size(); ++k ) delete elements_[k];*/ }
        virtual Symbol* clone() const;
        void add_element(Symbol* e);
        virtual std::string to_string() const;
    };
    struct type_symbol_vec : public std::vector<TypeSymbol*> { };

    struct VariableSymbol : public Symbol {
        mutable Symbol *value_;
        VariableSymbol(const std::string &name) : Symbol(name, sym_variable), value_(0) { }
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
        PredicateSymbol(const std::string &name) : Symbol(name, sym_predicate), strongly_static_(false) { }
        virtual ~PredicateSymbol() { for( size_t k = 0; k < param_.size(); ++k ) delete param_[k]; }
        virtual Symbol* clone() const;
        virtual std::string to_string() const;
    };
    struct predicate_symbol_vec : public std::vector<PredicateSymbol*> { };

    struct Condition;
    struct Schema {
        var_symbol_vec param_;
        const Condition *such_that_;
        Schema() : such_that_(0) { }
        virtual ~Schema() { delete such_that_; /*for( size_t k = 0; k < param_.size(); ++k ) delete param_[k];*/ }
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
        bool is_strongly_static(const PredicateSymbol &p) const;
        void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        Instance::Atom* find_prop(Instance &ins, bool negated, bool create) const;
        void emit(Instance &ins, index_set &atoms) const;
        Atom* ground(bool clone_variables) const;
        bool has_free_variables(const var_symbol_vec &param) const;
        bool is_fully_instantiated() const;

        const Atom& operator=(const Atom &atom);

        // comparison operators
        bool operator==(const Atom &atom) const;
        bool operator!=(const Atom &atom) const { return !(*this == atom); }
        bool operator<(const Atom &atom) const;
        struct signed_less_comparator {
            bool operator()(const Atom &atom1, const Atom &atom2) const {
                return atom1 < atom2;
            }
        };
        struct unsigned_less_comparator {
            bool operator()(const Atom &atom1, const Atom &atom2) const;
        };

        std::string to_string(bool extra_neg = false, bool mangled = false) const;
        void print(std::ostream &os, bool extra_neg = false) const { os << to_string(extra_neg); }
        static PDDL_Base *pddl_base_;
    };
    struct atom_vec : public std::vector<Atom> { };
    struct signed_atom_set : public std::set<Atom, Atom::signed_less_comparator> {
        bool operator<(const signed_atom_set &atom_set) const;
    };
    struct unsigned_atom_set : public std::set<Atom, Atom::unsigned_less_comparator> {
        bool operator<(const unsigned_atom_set &atom_set) const;
    };

    struct Condition {
        Condition() { }
        virtual ~Condition() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) = 0;
        virtual void emit(Instance &ins, index_set &condition) const = 0;
        virtual Condition* ground(bool clone_variables = false, bool negate = false, bool replace_static_values = true) const = 0;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const = 0;
        virtual void extract_atoms(unsigned_atom_set &atoms) const = 0;
        virtual bool is_dnf(bool positive = false, const PDDL_Base *base = 0) const = 0;
        virtual bool is_term(bool positive = false, const PDDL_Base *base = 0) const = 0;
        virtual Condition* as_dnf() const = 0;
        virtual std::string to_string() const = 0;
        void print(std::ostream &os) const { os << to_string(); }
        Condition* copy_and_simplify(bool negate = false) const { return ground(false, negate, false); }
        Condition* negate_and_simplify() const { return copy_and_simplify(true); }
        bool is_grounded() const { return !has_free_variables(var_symbol_vec(), true); }
    };
    struct condition_vec : public std::vector<const Condition*> { };

    struct Constant : public Condition {
        bool value_;
        Constant(bool value) : value_(value) { }
        virtual ~Constant() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) { }
        virtual void emit(Instance &ins, index_set &condition) const { }
        virtual Condition* ground(bool clone_variables = false, bool negate = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const { return false; }
        virtual void extract_atoms(unsigned_atom_set &atoms) const { }
        virtual bool is_dnf(bool positive = false, const PDDL_Base *base = 0) const { return true; }
        virtual bool is_term(bool positive = false, const PDDL_Base *base = 0) const { return false; }
        virtual Condition* as_dnf() const;
        virtual std::string to_string() const { return std::string(value_ ? "true" : "false"); }
    };

    struct Literal : public Condition, Atom {
        Literal(const Atom &atom, bool complemented = false) : Atom(atom, complemented) { }
        virtual ~Literal() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual bool is_dnf(bool positive = false, const PDDL_Base *base = 0) const { return is_term(positive, base); }
        virtual bool is_term(bool positive = false, const PDDL_Base *base = 0) const;
        virtual Condition* as_dnf() const;
        virtual std::string to_string() const { return to_string(false, false); }
        std::string to_string(bool extra_negation, bool mangled) const { return Atom::to_string(extra_negation, mangled); }
        Condition *copy(bool clone_variables = false, bool negate = false, bool replace_static_values = false) const;
        Condition *negate(bool clone_variables = false) const { return copy(clone_variables, true); }
    };

    struct EQ : public Condition, std::pair<const Symbol*,const Symbol*> {
        bool negated_;
        EQ(const Symbol *x, const Symbol *y, bool negated = false)
          : std::pair<const Symbol*,const Symbol*>(x, y), negated_(negated) { }
        virtual ~EQ() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const { }
        virtual Condition* ground(bool clone_variables = false, bool negate = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const { }
        virtual bool is_dnf(bool positive = false, const PDDL_Base *base = 0) const { return false; }
        virtual bool is_term(bool positive = false, const PDDL_Base *base = 0) const { return false; }
        virtual Condition* as_dnf() const;
        virtual std::string to_string() const;
    };

    struct And : public Condition, condition_vec {
        And() { }
        explicit And(const condition_vec &vec) : condition_vec(vec) { }
        virtual ~And() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual bool is_dnf(bool positive = false, const PDDL_Base *base = 0) const { return is_term(positive, base); }
        virtual bool is_term(bool positive = false, const PDDL_Base *base = 0) const;
        virtual Condition* as_dnf() const;
        virtual std::string to_string() const;
    };

    struct Or : public Condition, condition_vec {
        Or() { }
        explicit Or(const condition_vec &vec) : condition_vec(vec) { }
        virtual ~Or() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual bool is_dnf(bool positive = false, const PDDL_Base *base = 0) const;
        virtual bool is_term(bool positive = false, const PDDL_Base *base = 0) const { return false; }
        virtual Condition* as_dnf() const;
        virtual std::string to_string() const;
    };

    struct ForallCondition : public Condition, Schema {
        const Condition *condition_;
        ForallCondition() : condition_(0) { }
        virtual ~ForallCondition() { delete condition_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual void process_instance() const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual bool is_dnf(bool positive = false, const PDDL_Base *base = 0) const { return false; }
        virtual bool is_term(bool positive = false, const PDDL_Base *base = 0) const { return false; }
        virtual Condition* as_dnf() const;
        virtual std::string to_string() const;
        mutable std::vector<bool> negate_stack_;
        mutable std::vector<bool> clone_variables_stack_;
        mutable std::vector<Condition*> result_stack_;
    };

    struct ExistsCondition : public Condition, Schema {
        const Condition *condition_;
        ExistsCondition() : condition_(0) { }
        virtual ~ExistsCondition() { delete condition_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &condition) const;
        virtual void process_instance() const;
        virtual Condition* ground(bool clone_variables = false, bool negate = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual bool is_dnf(bool positive = false, const PDDL_Base *base = 0) const { return false; }
        virtual bool is_term(bool positive = false, const PDDL_Base *base = 0) const { return false; }
        virtual Condition* as_dnf() const;
        virtual std::string to_string() const;
        mutable std::vector<bool> negate_stack_;
        mutable std::vector<bool> clone_variables_stack_;
        mutable std::vector<Condition*> result_stack_;
    };

    struct Variable;
    struct Effect;
    struct effect_vec : public std::vector<const Effect*> { };

    struct Effect {
        Effect() { }
        virtual ~Effect() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) = 0;
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const = 0;
        virtual Effect* ground(bool clone_variables = false, bool replace_static_values = true) const = 0;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &p) const = 0;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const = 0;
        virtual std::string to_string() const = 0;
        void print(std::ostream &os) const { os << to_string(); }
        Effect* copy_and_simplify() const { return ground(false, false); }
        bool is_grounded() const { var_symbol_vec empty_param; return !has_free_variables(empty_param, true); }
    };

    struct NullEffect : public Effect {
        NullEffect() { }
        virtual ~NullEffect() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) { }
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const { }
        virtual Effect* ground(bool clone_variables = false, bool replace_static_values = true) const { return 0; }
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const { return false; }
        virtual bool is_strongly_static(const PredicateSymbol &p) const { return true; }
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const { }
        virtual std::string to_string() const { return std::string("<null>"); }
    };

    struct AtomicEffect : public Effect, Atom {
        AtomicEffect(const Atom &atom, bool complemented = false) : Atom(atom, complemented) { }
        virtual ~AtomicEffect() { }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual Effect* ground(bool clone_variables = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const;
        virtual std::string to_string() const { return to_string(false); }
        std::string to_string(bool mangled) const { return Atom::to_string(false, mangled); }
        AtomicEffect* negate() const { return copy(false, true); }
        AtomicEffect* copy(bool clone_variables = false, bool negate = false) const;
    };

    struct AndEffect : public Effect, effect_vec {
        AndEffect() { }
        AndEffect(const effect_vec &vec) : effect_vec(vec) { }
        AndEffect(effect_vec &&vec) : effect_vec(std::move(vec)) { }
        virtual ~AndEffect() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual Effect* ground(bool clone_variables = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const;
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
        virtual Effect* ground(bool clone_variables = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const;
        virtual std::string to_string() const;
    };

    struct ForallEffect : public Effect, Schema {
        const Effect *effect_;
        ForallEffect() : effect_(0) { }
        virtual ~ForallEffect() { delete effect_; }
        virtual void remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param);
        virtual void emit(Instance &ins, index_set &eff, Instance::when_vec &when = dummy_when_vec_) const;
        virtual void process_instance() const;
        virtual Effect* ground(bool clone_variables = false, bool replace_static_values = true) const;
        virtual bool has_free_variables(const var_symbol_vec &param, bool dont_extend = false) const;
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_affected = false) const;
        virtual std::string to_string() const;
        mutable std::vector<AndEffect*> result_stack_;
        mutable std::vector<bool> clone_variables_stack_;
    };

    struct ObsVariable;
    struct StateVariable;
    struct SensingModelForObservableVariable;

    struct SensingModel {
        virtual ~SensingModel() { }
        virtual bool is_strongly_static(const PredicateSymbol &p) const = 0;
        virtual SensingModel* ground(bool clone_variables = false, bool replace_static_values = true) const = 0;
        virtual void finish_grounding(PDDL_Base *base) = 0;
        virtual bool verify(const PDDL_Base *base) const = 0;
        virtual bool is_grounded() const = 0;
        virtual SensingModel* reduce(const unsigned_atom_set &atoms_to_remove) const = 0;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_sensed_atoms = false, bool only_affected_atoms = false) const = 0;
        virtual void extend_beam_for_variable(Variable &var) const = 0;
        virtual void extract_sensing_model_for_atom(const Atom &atom, std::vector<const SensingModelForObservableVariable*> &models) const = 0;
        virtual Effect* as_effect() const = 0;
        virtual std::string to_string() const = 0;
        void print(std::ostream &os) const { os << to_string(); }
    };

    struct SensingModelForStateVariable : public SensingModel {
        std::string variable_name_;
        const StateVariable *variable_;
        symbol_vec param_;
        bool finished_grounding_;
        SensingModelForStateVariable(const StateVariable *variable = 0)
          : variable_(variable), finished_grounding_(false) { }
        virtual ~SensingModelForStateVariable() { }
        virtual bool is_strongly_static(const PredicateSymbol &p) const { return true; }
        virtual SensingModel* ground(bool clone_variables = false, bool replace_static_values = true) const;
        virtual void finish_grounding(PDDL_Base *base);
        virtual bool verify(const PDDL_Base *base) const;
        virtual bool is_grounded() const { return true; }
        virtual SensingModel* reduce(const unsigned_atom_set &atoms_to_remove) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_sensed_atoms = false, bool only_affected_atoms = false) const;
        virtual void extend_beam_for_variable(Variable &var) const { }
        virtual void extract_sensing_model_for_atom(const Atom &atom, std::vector<const SensingModelForObservableVariable*> &models) const { }
        virtual Effect* as_effect() const { return new AndEffect; }
        virtual std::string to_string() const;
    };

    struct SensingModelForObservableVariable : public SensingModel {
        std::string variable_name_;
        const ObsVariable *variable_;
        symbol_vec param_;
        bool finished_grounding_;
        const Literal *literal_;
        const Condition *dnf_;
        SensingModelForObservableVariable(const ObsVariable *variable = 0, const Literal *literal = 0, const Condition *dnf = 0)
          : variable_(variable), finished_grounding_(false), literal_(literal), dnf_(dnf) { }
        virtual ~SensingModelForObservableVariable() { delete literal_; delete dnf_; }
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual SensingModel* ground(bool clone_variables = false, bool replace_static_values = true) const;
        virtual void finish_grounding(PDDL_Base *base);
        virtual bool verify(const PDDL_Base *base) const;
        virtual bool is_grounded() const;
        SensingModelForObservableVariable* copy_and_simplify() const {
            return static_cast<SensingModelForObservableVariable*>(ground(false, false));
        }
        virtual SensingModel* reduce(const unsigned_atom_set &atoms_to_remove) const;
        virtual void extract_atoms(unsigned_atom_set &atoms, bool only_sensed_atoms = false, bool only_affected_atoms = false) const;
        void extend_beam_for_variable(Variable &var) const;
        virtual void extract_sensing_model_for_atom(const Atom &atom, std::vector<const SensingModelForObservableVariable*> &models) const;
        virtual Effect* as_effect() const;
        virtual std::string to_string() const;
    };

    struct Sensing;
    struct sensing_proxy_vec;

    struct SensingProxy {
        virtual ~SensingProxy() { }
        virtual bool is_strongly_static(const PredicateSymbol &p) const = 0;
        virtual Sensing* ground(bool clone_variables = false, bool replace_static_values = true) const = 0;
        virtual std::string to_string() const = 0;
        void print(std::ostream &os) const { os << to_string(); }
    };

    struct sensing_proxy_vec : public std::vector<const SensingProxy*> {
        Sensing* ground(bool clone_variables = false, bool replace_static_values = true) const;
        std::string to_string() const;
        void print(std::ostream &os) const { os << to_string(); }
    };

    struct BasicSensingModel : public SensingProxy {
        const SensingModel *sensing_model_;
        BasicSensingModel(const SensingModel *sensing_model = 0) : sensing_model_(sensing_model) { }
        virtual ~BasicSensingModel() { delete sensing_model_; }
        virtual bool is_strongly_static(const PredicateSymbol &p) const { return sensing_model_->is_strongly_static(p); }
        virtual Sensing* ground(bool clone_variables = false, bool replace_static_values = true) const;
        virtual std::string to_string() const { return sensing_model_->to_string(); }
    };

    struct ForallSensing : public SensingProxy, Schema {
        sensing_proxy_vec sensing_;
        ForallSensing() { }
        virtual ~ForallSensing() { for( size_t k = 0; k < sensing_.size(); ++k ) delete sensing_[k]; }
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual Sensing* ground(bool clone_variables = false, bool replace_static_values = true) const;
        virtual std::string to_string() const;
        virtual void process_instance() const;
        mutable std::vector<bool> clone_variables_stack_;
        mutable std::vector<bool> replace_static_values_stack_;
        mutable std::vector<Sensing*> result_stack_;
    };

    struct Sensing : public std::vector<const SensingModel*> {
        bool is_strongly_static(const PredicateSymbol &p) const;
        Sensing* ground(bool clone_variables = false, bool replace_static_values = true) const;
        bool finish_grounding(PDDL_Base *base);
        bool is_grounded() const;
        Sensing* copy_and_simplify() const { return ground(false, false); }
        Sensing* reduce(const unsigned_atom_set &atoms_to_remove) const;
        void extract_atoms(unsigned_atom_set &atoms, bool only_sensed_atoms = false, bool only_affected_atoms = false) const;
        void extend_beam_for_variable(Variable &var) const;
        void extract_sensing_model_for_atom(const Atom &atom, std::vector<const SensingModelForObservableVariable*> &models) const;
        Effect* as_effect() const;
        std::string to_string() const;
        void print(std::ostream &os) const { os << to_string(); }
    };

    struct Invariant : public condition_vec, Schema {
        typedef enum { AT_LEAST_ONE = 0, AT_MOST_ONE = 1, EXACTLY_ONE = 2 } type_t;
        typedef enum { GOOD = 0, BAD = 1, RECOVERABLE = 3, EMPTY = 4 } status_t;

        type_t type_;
        const Condition *Xprecondition_;
        Invariant(type_t type) : type_(type), Xprecondition_(0) { }
        Invariant(type_t type, const condition_vec &invariant) : condition_vec(invariant), type_(type), Xprecondition_(0) { }
        virtual ~Invariant() { for( size_t k = 0; k < size(); ++k ) delete (*this)[k]; delete Xprecondition_; }
        virtual void process_instance() const;
        void clear();
        status_t Xeduce();
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

    struct Unknown : public Atom, Schema {
        Unknown(const Atom &atom) : Atom(atom) { }
        virtual ~Unknown() { }
        virtual void process_instance() const;
        std::string to_string() const;
        void print(std::ostream &os) const { os << to_string(); }
    };

    struct InitElement;
#ifdef SMART
    struct owned_init_element_vec : public std::vector<std::unique_ptr<InitElement> > { };
    struct owned_init_element_list : public std::list<std::unique_ptr<InitElement> > { };
#else
    struct init_element_vec : public std::vector<InitElement*> { };
    struct init_element_list : public std::list<InitElement*> { };
#endif

    struct InitElement {
        InitElement() { }
        virtual ~InitElement() { }
#ifdef SMART
        virtual void instantiate(owned_init_element_list &ilist) const = 0;
#else
        virtual void instantiate(init_element_list &ilist) const = 0;
#endif
        virtual void emit(Instance &ins) const = 0;
        virtual bool is_strongly_static(const PredicateSymbol &p) const = 0;
        virtual void extract_atoms(unsigned_atom_set &atoms) const = 0;
        virtual void print(std::ostream &os) const = 0;
    };

    struct InitLiteral : public InitElement, Atom {
        InitLiteral(const Atom &atom) : Atom(atom) { }
        virtual ~InitLiteral() { }
        void emit(Instance &ins, Instance::Init &state) const;
#ifdef SMART
        virtual void instantiate(owned_init_element_list &ilist) const;
#else
        virtual void instantiate(init_element_list &ilist) const;
#endif
        virtual void emit(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual void print(std::ostream &os) const { Atom::print(os); }
    };

    struct InitInvariant : public InitElement, Invariant {
        InitInvariant(const Invariant &invariant) : Invariant(invariant) { }
        virtual ~InitInvariant() { }
#ifdef SMART
        virtual void instantiate(owned_init_element_list &ilist) const;
#else
        virtual void instantiate(init_element_list &ilist) const;
#endif
        virtual void emit(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual void print(std::ostream &os) const { Invariant::print(os); }
    };

    struct InitClause : public InitElement, Clause {
        InitClause(const Clause &clause) : Clause(clause) { }
        virtual ~InitClause() { }
#ifdef SMART
        virtual void instantiate(owned_init_element_list &ilist) const;
#else
        virtual void instantiate(init_element_list &ilist) const;
#endif
        virtual void emit(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual void print(std::ostream &os) const { Clause::print(os); }
        using Clause::emit;
    };

    struct InitOneof : public InitElement, Oneof {
        InitOneof(const Oneof &oneof) : Oneof(oneof) { }
        virtual ~InitOneof() { }
#ifdef SMART
        virtual void instantiate(owned_init_element_list &ilist) const;
#else
        virtual void instantiate(init_element_list &ilist) const;
#endif
        virtual void emit(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual void print(std::ostream &os) const { Oneof::print(os); }
        using Oneof::emit;
    };

    struct InitUnknown : public InitElement, Unknown {
        InitUnknown(const Unknown &unknown) : Unknown(unknown) { }
        virtual ~InitUnknown() { }
#ifdef SMART
        virtual void instantiate(owned_init_element_list &ilist) const;
#else
        virtual void instantiate(init_element_list &ilist) const;
#endif
        virtual void emit(Instance &ins) const;
        virtual bool is_strongly_static(const PredicateSymbol &p) const;
        virtual void extract_atoms(unsigned_atom_set &atoms) const;
        virtual void print(std::ostream &os) const { Unknown::print(os); }
        using Unknown::emit;
    };

    struct Action;
#ifdef SMART
    struct owned_action_vec : public std::vector<std::unique_ptr<Action> > { };
    struct owned_action_list : public std::list<std::unique_ptr<Action> > { };
#else
    struct action_vec : public std::vector<Action*> { };
    struct action_list : public std::list<Action*> { };
#endif

    struct Action : public Symbol, Schema {
        const Condition *precondition_;
        const Effect *effect_;
        const Effect *observe_;
        const Sensing *sensing_;
        const sensing_proxy_vec *sensing_proxy_;
        std::string comment_;
        Action(const std::string &name);
        virtual ~Action();
        bool is_special_action() const;
#ifdef SMART
        void instantiate(owned_action_list &alist) const;
#else
        void instantiate(action_list &alist) const;
#endif
        void emit(Instance &ins) const;
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
#ifdef SMART
        mutable owned_action_list *action_list_ptr_;
#else
        mutable action_list *action_list_ptr_;
#endif
    };

    struct Sensor;
#ifdef SMART
    struct owned_sensor_vec : public std::vector<std::unique_ptr<Sensor> > { };
    struct owned_sensor_list : public std::list<std::unique_ptr<Sensor> > { };
#else
    struct sensor_vec : public std::vector<Sensor*> { };
    struct sensor_list : public std::list<Sensor*> { };
#endif

    struct Sensor : public Symbol, Schema {
        const Condition *condition_;
        const Effect *sense_;
        Sensor(const std::string &name) : Symbol(name, sym_sensor), condition_(0), sense_(0) { }
        virtual ~Sensor() { delete condition_; delete sense_; }
#ifdef SMART
        void instantiate(owned_sensor_list &slist) const;
#else
        void instantiate(sensor_list &slist) const;
#endif
        void emit(Instance &ins) const;
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
#ifdef SMART
        mutable owned_sensor_list *sensor_list_ptr_;
#else
        mutable sensor_list *sensor_list_ptr_;
#endif
    };

    struct Axiom;
#ifdef SMART
    struct owned_axiom_vec : public std::vector<std::unique_ptr<Axiom> > { };
    struct owned_axiom_list : public std::list<std::unique_ptr<Axiom> > { };
#else
    struct axiom_vec : public std::vector<Axiom*> { };
    struct axiom_list : public std::list<Axiom*> { };
#endif

    struct Axiom : public Symbol, Schema {
        const Condition *body_;
        const Effect *head_;
        Axiom(const std::string &name) : Symbol(name, sym_axiom), body_(0), head_(0) { }
        virtual ~Axiom() { delete body_; delete head_; }
#ifdef SMART
        void instantiate(owned_axiom_list &alist) const;
#else
        void instantiate(axiom_list &alist) const;
#endif
        void emit(Instance &ins) const;
        virtual void process_instance() const;
        virtual void print(std::ostream &os) const;
#ifdef SMART
        mutable owned_axiom_list *axiom_list_ptr_;
#else
        mutable axiom_list *axiom_list_ptr_;
#endif
    };

    struct Observable;
#ifdef SMART
    struct owned_observable_vec : public std::vector<std::unique_ptr<Observable> > { };
    struct owned_observable_list : public std::list<std::unique_ptr<Observable> > { };
#else
    struct observable_vec : public std::vector<Observable*> { };
    struct observable_list : public std::list<Observable*> { };
#endif

    struct Observable {
        effect_vec observables_;
        Observable() { }
        ~Observable() { for( size_t k = 0; k < observables_.size(); ++k ) delete observables_[k]; }
#ifdef SMART
        void instantiate(owned_observable_list &olist) const;
#else
        void instantiate(observable_list &olist) const;
#endif
        void emit(Instance &ins) const;
        void print(std::ostream &os) const;
    };

    struct Sticky;
#ifdef SMART
    struct owned_sticky_vec : public std::vector<std::unique_ptr<Sticky> > { };
    struct owned_sticky_list : public std::list<std::unique_ptr<Sticky> > { };
#else
    struct sticky_vec : public std::vector<Sticky*> { };
    struct sticky_list : public std::list<Sticky*> { };
#endif

    struct Sticky {
        effect_vec stickies_;
        Sticky() { }
        ~Sticky() { for( size_t k = 0; k < stickies_.size(); ++k ) delete stickies_[k]; }
#ifdef SMART
        void instantiate(owned_sticky_list &slist) const;
#else
        void instantiate(sticky_list &slist) const;
#endif
        void emit(Instance &ins) const;
        void print(std::ostream &os) const;
    };

    struct StateVariableList;
#ifdef SMART
    struct owned_variable_vec : public std::vector<std::unique_ptr<Variable> > { };
    struct owned_variable_list : public std::list<std::unique_ptr<Variable> > { };
#else
    struct variable_vec : public std::vector<Variable*> { };
    struct variable_list : public std::list<Variable*> { };
#endif
    struct state_variable_vec : public std::vector<StateVariable*> { };
    struct state_variable_list_vec : public std::vector<StateVariableList*> { };

    struct Variable : public Symbol, Schema {
        bool grounded_;
        effect_vec domain_;
        unsigned_atom_set grounded_domain_;
        std::map<Atom, unsigned_atom_set, Atom::unsigned_less_comparator> beam_;

        Variable(const Variable &var) = delete;
        Variable(const std::string &name) : Symbol(name, sym_varname), grounded_(false) { }
        virtual ~Variable() {
            for( size_t k = 0; k < domain_.size(); ++k )
                delete domain_[k];
        }

#ifdef SMART
        void instantiate(owned_variable_list &vlist) const;
#else
        void instantiate(variable_list &vlist) const;
#endif
        const unsigned_atom_set& beam_for_value(const Atom &value) const {
            return beam_.at(value);
        }
        bool is_binary() const { return grounded_domain_.size() == 1; }

        virtual void process_instance() const;
#ifdef SMART
        virtual std::unique_ptr<Variable> make_instance(const std::string &name) const = 0;
#else
        virtual Variable* make_instance(const std::string &name) const = 0;
#endif
        virtual bool is_state_variable() const = 0;
        virtual bool is_observable_variable() const = 0;
#pragma GCC diagnostic ignored "-Woverloaded-virtual"
        virtual std::string to_string(bool only_name = false, bool cat = false) const = 0;
#pragma GCC diagnostic warning "-Woverloaded-virtual"
        virtual void print(std::ostream &os) const { os << to_string(); }
#ifdef SMART
        mutable owned_variable_vec *grounded_variables_ptr_;
        mutable owned_variable_list *variable_list_ptr_;
#else
        mutable variable_vec *grounded_variables_ptr_;
        mutable variable_list *variable_list_ptr_;
#endif
    };

    struct StateVariable : public Variable {
        bool is_observable_;
        StateVariable(const StateVariable &var) = delete;
        StateVariable(const std::string &name, bool is_observable = false) : Variable(name), is_observable_(is_observable) { }
        virtual ~StateVariable() { }
#ifdef SMART
        virtual std::unique_ptr<Variable> make_instance(const std::string &name) const;
#else
        virtual Variable* make_instance(const std::string &name) const;
#endif
        virtual bool is_state_variable() const { return true; }
        virtual bool is_observable_variable() const { return is_observable_; }
        virtual std::string to_string(bool only_name = false, bool cat = false) const;
    };

    struct ObsVariable : public Variable {
        ObsVariable(const ObsVariable &var) = delete;
        ObsVariable(const std::string &name) : Variable(name) { }
        virtual ~ObsVariable() { }
#ifdef SMART
        virtual std::unique_ptr<Variable> make_instance(const std::string &name) const;
#else
        virtual Variable* make_instance(const std::string &name) const;
#endif
        virtual bool is_state_variable() const { return false; }
        virtual bool is_observable_variable() const { return true; }
        virtual std::string to_string(bool only_name = false, bool cat = false) const;
    };

    struct StateVariableList {
        StateVariableList() { }
        virtual ~StateVariableList() { }
        virtual state_variable_vec* ground(const PDDL_Base *base) const = 0;
        virtual std::string to_string() const = 0;
        void print(std::ostream &os) const { os << to_string(); }
    };

    struct SingleStateVariableList : public Symbol, StateVariableList {
        std::string variable_name_;
        const StateVariable *variable_;
        symbol_vec param_;
        SingleStateVariableList(const std::string &name) : Symbol(name, sym_varinst) { }
        virtual ~SingleStateVariableList() { }
        virtual state_variable_vec* ground(const PDDL_Base *base) const;
        virtual std::string to_string() const { return "<not yet implemented>"; }
    };

    struct ForallStateVariableList : public StateVariableList, Schema {
        state_variable_list_vec group_;
        ForallStateVariableList() { }
        virtual ~ForallStateVariableList() { }
        virtual void process_instance() const;
        virtual state_variable_vec* ground(const PDDL_Base *base) const;
        virtual std::string to_string() const { return "<not yet implemented>"; }
        mutable std::vector<state_variable_vec*> result_stack_;
        mutable std::vector<const PDDL_Base*> base_stack_;
    };

    struct VariableGroup;
#ifdef SMART
    struct owned_variable_group_vec : public std::vector<std::unique_ptr<VariableGroup> > { };
    struct owned_variable_group_list : public std::list<std::unique_ptr<VariableGroup> > { };
#else
    struct variable_group_vec : public std::vector<VariableGroup*> { };
    struct variable_group_list : public std::list<VariableGroup*> { };
#endif

    struct VariableGroup : public Symbol, Schema {
        bool grounded_;
        state_variable_list_vec group_;
        state_variable_vec grounded_group_;
        unsigned_atom_set grounded_domain_;
        std::set<std::string> grounded_group_str_;
        std::vector<std::pair<const Variable*, Atom> > filtered_observations_;
        VariableGroup(const std::string &name) : Symbol(name, sym_vargroup), grounded_(false) { }
        virtual ~VariableGroup() { }
#ifdef SMART
        void instantiate(const PDDL_Base *base, owned_variable_group_list &vglist) const;
#else
        void instantiate(const PDDL_Base *base, variable_group_list &vglist) const;
#endif
        virtual void process_instance() const;
        virtual std::string to_string() const;
#ifdef SMART
        mutable owned_variable_group_list *variable_group_list_ptr_;
#else
        mutable variable_group_list *variable_group_list_ptr_;
#endif
        mutable const PDDL_Base *base_ptr_;
    };

    // end of definitions for internal structures

    std::string                               domain_name_;
    std::string                               problem_name_;

    StringTable                               &parser_symbol_table_;
    const Options::Mode                       &options_;

    type_symbol_vec                           dom_types_;
    TypeSymbol                                *dom_top_type_;
    symbol_vec                                dom_constants_;
    predicate_symbol_vec                      dom_predicates_;
    PredicateSymbol                           *dom_eq_pred_;

#ifdef SMART
    owned_action_vec                                dom_actions_;
    owned_sensor_vec                                dom_sensors_;
    owned_axiom_vec                                 dom_axioms_;
#else
    action_vec                                dom_actions_;
    sensor_vec                                dom_sensors_;
    axiom_vec                                 dom_axioms_;
#endif
    const Condition                           *dom_goal_;
#ifdef SMART
    owned_init_element_vec                          dom_init_;
    std::vector<owned_init_element_vec>             dom_hidden_;
    std::vector<owned_init_element_vec>             dom_explicit_initial_states_; // explicit initial states for conformant problem
#else
    init_element_vec                          dom_init_;
    std::vector<init_element_vec>             dom_hidden_;
    std::vector<init_element_vec>             dom_explicit_initial_states_; // explicit initial states for conformant problem
#endif
    unsigned_atom_set                         dom_static_atoms_;

#ifdef SMART
    owned_observable_vec                            dom_observables_;
    owned_sticky_vec                                dom_stickies_;
#else
    observable_vec                            dom_observables_;
    sticky_vec                                dom_stickies_;
#endif

    // set of initial literals (extracted from InitElements in dom_init_
    unsigned_atom_set                         set_of_initial_literals_;

    // name of original actions in problem
    std::set<std::string>                     original_actions_;

    // For CLG and lw1 translations
#ifdef SMART
    std::unique_ptr<const Atom>               normal_execution_;
#else
    const Atom                                *normal_execution_;
#endif

    // For CLG-type syntax and translations
    bool                                      clg_translation_;

    // For lw1 formulations
    bool                                      lw1_translation_;
#ifdef SMART
    owned_variable_vec                              lw1_uninstantiated_variables_;
    owned_variable_vec                              lw1_variables_;
#else
    variable_vec                              lw1_uninstantiated_variables_;
    variable_vec                              lw1_variables_;
#endif
    unsigned_atom_set                         observable_atoms_;
    unsigned_atom_set                         atoms_for_state_variables_;
    unsigned_atom_set                         atoms_for_variable_groups_;
    unsigned_atom_set                         static_observable_atoms_;
    unsigned_atom_set                         sensed_atoms_;
    std::set<std::string>                     simple_sensors_for_variables_;
    std::map<unsigned_atom_set,const Action*> post_actions_for_lw1_translation_;
    std::map<std::string, const Atom*>        need_set_sensing_atoms_;
    std::map<unsigned_atom_set, const Atom*>  need_post_atoms_;
    std::map<std::string, const Atom*>        sensing_atoms_;
    std::map<signed_atom_set, const Atom*>    atoms_for_terms_for_type3_sensing_drules_;
    std::map<std::string, const Atom*>        lw1_sensing_enabler_atoms_;
    std::map<std::pair<const Action*, std::pair<const ObsVariable*, Atom> >, const Atom*> lw1_sensing_enablers_;
    std::map<std::string, std::set<std::string> > lw1_enablers_for_actions_;
    std::map<std::string, const Atom*>        lw1_last_action_atoms_;
    std::map<std::string, std::set<std::string> > lw1_accepted_literals_for_observables_;

    const Sensing                             *lw1_default_sensing_;
    const sensing_proxy_vec                   *lw1_default_sensing_proxy_;

#ifdef SMART
    owned_variable_group_vec                        lw1_variable_groups_;
    owned_variable_group_vec                        lw1_uninstantiated_variable_groups_;
#else
    variable_group_vec                        lw1_variable_groups_;
    variable_group_vec                        lw1_uninstantiated_variable_groups_;
#endif
    std::map<std::string, const VariableGroup*> lw1_ad_hoc_groups_;

    std::map<const Action*, std::map<const ObsVariable*, std::map<Atom, std::list<const And*> > > > lw1_sensing_models_index_;
    std::map<const StateVariable*, std::vector<const Action*> > lw1_actions_for_observable_state_variables_;
    std::list<std::pair<const Action*, const Sensing*> > lw1_sensing_models_;
    std::map<std::pair<const ObsVariable*, Atom>, std::map<std::string, std::set<const Action*> > > lw1_xxx_;

    PDDL_Base(StringTable &parser_symbol_table, const Options::Mode &options);
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

    void do_translation();
#ifdef SMART
    void do_lw1_translation(const owned_variable_vec* &variables,
                            const owned_variable_group_vec* &variable_groups,
                            const std::list<std::pair<const Action*, const Sensing*> >* &sensing_models,
                            const std::map<std::string, std::set<std::string> >* &accepted_literals_for_observables);
#else
    void do_lw1_translation(const variable_vec* &variables,
                            const variable_group_vec* &variable_groups,
                            const std::list<std::pair<const Action*, const Sensing*> >* &sensing_models,
                            const std::map<std::string, std::set<std::string> >* &accepted_literals_for_observables);
#endif
    void emit_instance(Instance &ins) const;
    void print(std::ostream &os) const;

    // translations
    int get_translation_type() const { return clg_translation() ? 1 : (lw1_translation() ? 2 : 0); }

    // creation of atoms
    PredicateSymbol* create_predicate(const std::string &name, const var_symbol_vec *param = 0);
    Atom* create_atom(const Atom &atom) const;
    Atom* create_atom(const std::string &name, const var_symbol_vec *param = 0);
    void create_normal_execution_atom();

    // methods for formulations in CLG-like syntax
    void declare_clg_translation();
    bool clg_translation() const { return clg_translation_; }
    void clg_map_oneofs_and_clauses_to_invariants();
    void clg_translate_actions();
    void clg_translate(Action &action);

    // methods for lw1 formulation
    void declare_lw1_translation();
    bool lw1_translation() const { return lw1_translation_; }
    void lw1_calculate_atoms_for_state_variables();
    void lw1_calculate_atoms_for_variable_group(VariableGroup &group, int index);
    void lw1_calculate_atoms_for_variable_groups();
    void lw1_calculate_beams_for_grounded_observable_variables();
    void lw1_calculate_beam_for_grounded_variable(Variable &var);
    void lw1_remove_variables_with_empty_grounded_domain();
    void lw1_remove_empty_variable_groups();
    void lw1_translate_actions();
    void lw1_translate(Action &action);
    void lw1_create_post_action(const unsigned_atom_set &atoms);

    void lw1_emit_and_protect_atoms_for_observable_variables(Instance &ins) const;
    void lw1_protect_enablers_for_sensing(Instance &ins) const;
    void lw1_translate_actions_strict();
    void lw1_translate_strict(Action &action);
    void lw1_translate_strict_NEW(Action &action);

    // methods to handle sensing for lw1
    void lw1_finish_grounding_of_sensing(const Sensing* &sensing);

    // methods to create deductive rules for lw1
    void lw1_create_deductive_rules_for_variables();
    void lw1_create_drule_var_exhaustive(const Variable &variable, const Atom &value);
    void lw1_create_drule_var_exclusive(const Variable &variable, const Atom &value);

    // methods to create deductive rules for sensing
    void lw1_index_sensing_models();
    void lw1_create_deductive_rules_for_sensing();
    void lw1_create_type1_sensing_drule(const Atom &obs, const And &term, int index);
    void lw1_create_type2_sensing_drule(const Atom &obs, const And &term, int index);

    // methods to create type3 deductive rules (for lw1)
    void lw1_create_type3_sensing_drule(const Action &action,
                                        const ObsVariable &variable,
                                        const Atom &value,
                                        const And &term,
                                        const std::list<const And*> &dnf,
                                        int index);
    const Atom& lw1_fetch_atom_for_negated_term(const And &term);

    // methods to create type4 deductive rules (for lw1)
    void lw1_create_type4_sensing_drule(const Action *action, const StateVariable &variable, const Atom &value);
    void lw1_create_type4_sensing_drule(const Action &action,
                                        const ObsVariable &variable,
                                        const Atom &value,
                                        const std::map<Atom, std::list<const And*> > &sensing_models_for_action_and_var);
    void lw1_create_type4_boost_sensing_drule(const Action &action,
                                              const ObsVariable &variable,
                                              const Atom &value,
                                              const std::map<Atom, std::list<const And*> > &sensing_models_for_action_and_var);
    void lw1_create_type5_sensing_drule(const ObsVariable &variable);
    const Atom& lw1_fetch_sensing_enabler(const std::string &action, const std::string &variable, const std::string &value);
    const Atom& lw1_fetch_sensing_enabler(const Action &action, const ObsVariable &variable, const Atom &value);
    const Atom& lw1_fetch_sensing_enabler(const StateVariable &variable, const Atom &value);
    const Atom& lw1_fetch_last_action_atom(const Action &action);
    void lw1_calculate_enablers_for_sensing();
    void lw1_patch_actions_with_enablers_for_sensing();

    // methods to create sensors (for lw1)
    void lw1_create_simple_sensors_for_atoms(const unsigned_atom_set &atoms);
    void lw1_create_sensors_for_atom(const Atom &atom, const Condition &condition, int sensor_index = -1);
    void lw1_create_sensors_for_atom(const Atom &atom, const signed_atom_set &condition, int sensor_index = -1);

    // methods to compile static observables (for lw1)
    void lw1_calculate_post_condition(const Condition *precondition, const Effect *effect, signed_atom_set &post_condition) const;
    void lw1_simplify_post_condition(signed_atom_set &post_condition) const;
    bool lw1_is_literal_implied(const Atom &literal, const Condition &condition, bool complement_literal = false) const;
    bool lw1_is_literal_implied(const Atom &literal, const signed_atom_set &condition, bool complement_literal = false) const;
    bool lw1_is_literal_implied(const Atom &literal, const std::vector<const Atom*> &condition, bool complement_literal = false) const;
    bool lw1_test_on_initial_state_for_static_observable(const signed_atom_set &condition) const;
    bool lw1_test_on_actions_for_static_observable(const signed_atom_set &condition, const Atom &atom) const;
    void lw1_remove_subsumed_conditions(std::set<signed_atom_set> &conditions) const;
    void lw1_compile_static_observable(const Atom &atom);
    void lw1_add_axiom_for_static_observable(const Literal &literal, const Condition &condition);

    // methods to complete effects (for lw1)
    void lw1_complete_effect_for_actions();
    const AndEffect* lw1_complete_effect(Effect *effect) const;
    const AndEffect* lw1_canonize_effect(Effect *effect) const;
    void lw1_complete_effect_with_variable(AndEffect *effect, const Variable &var) const;

    // methods to fetch/create support atoms for translations
    const Atom* lw1_fetch_need_set_sensing_atom(const Action &action);
    const Atom* lw1_fetch_enabler_for_sensing(const unsigned_atom_set &atoms);
    const Atom* lw1_fetch_enabler_for_sensing(const Atom &atom);

    // methods to perform action compilation (this action compilation is outside preprocessing)
    void lw1_do_action_compilation();
    void lw1_do_action_compilation(Action &action);

    // cleanup lw1 translation (called by dtor)
    void lw1_cleanup();
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

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::SensingModel &sensing_model) {
    sensing_model.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::SensingProxy &sensing) {
    sensing.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::sensing_proxy_vec &sensing) {
    sensing.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const PDDL_Base::Sensing &sensing) {
    sensing.print(os);
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

class PDDL_Name {
  protected:
    bool negated_;
    const PDDL_Base::Symbol *sym_;
    PDDL_Base::symbol_vec args_;

  public:
    PDDL_Name(const PDDL_Base::Symbol *sym, bool negated = false)
      : negated_(negated), sym_(sym) {
    }
    PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::var_symbol_vec &args)
      : negated_(false), sym_(sym) {
        for( size_t k = 0; k < args.size(); ++k )
            args_.push_back(args[k]->value_);
    }
    virtual ~PDDL_Name() { }
    void add(PDDL_Base::Symbol *s) { args_.push_back(s); }
    std::string to_string(bool mangled = false) const {
        std::string str;
        if( mangled ) {
            if( negated_ ) str += "not_";
            str += sym_->print_name_;
            for( size_t k = 0; k < args_.size(); ++k )
                str += std::string("_") + args_[k]->print_name_;
        } else {
            if( negated_ ) str += "(not ";
            str += std::string("(") + sym_->print_name_;
            for( size_t k = 0; k < args_.size(); ++k )
                str += std::string(" ") + args_[k]->print_name_;
            str += ")";
            if( negated_ ) str += ")";
        }
        return str;
    }
};

inline std::ostream& operator<<(std::ostream &os, const PDDL_Name &name) {
    os << name.to_string();
    return os;
}

#endif

