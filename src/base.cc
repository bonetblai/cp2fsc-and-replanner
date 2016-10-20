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

#include <cassert>
#include <iomanip>
#include <stdlib.h>
#include "base.h"
#include "base_dnf.h"
#include "utils.h"

//#define DEBUG

using namespace std;

bool PDDL_Base::write_warnings_ = true;
bool PDDL_Base::write_info_ = true;
Instance::when_vec PDDL_Base::dummy_when_vec_;
PDDL_Base *PDDL_Base::Atom::pddl_base_ = 0;

template <class T>
static void copy_symbol_vec(const vector<T> &src, vector<T> &dst) {
    dst.clear();
    dst.reserve(src.size());
    for( typename vector<T>::const_iterator it = src.begin(); it != src.end(); ++it ) {
        dst.push_back(static_cast<T>((*it)->clone()));
    }
}

static void clone_parameters(const PDDL_Base::var_symbol_vec &param, PDDL_Base::var_symbol_vec &clone) {
    clone.clear();
    clone.reserve(param.size());
    for( size_t k = 0; k < param.size(); ++k ) {
        clone.push_back(dynamic_cast<PDDL_Base::VariableSymbol*>(param[k]->clone()));
        if( clone.back() == 0 ) {
            cout << Utils::error() << "parameter conversion failed for " << *param[k] << endl;
            exit(255);
        }
    }
}


PDDL_Base::PDDL_Base(StringTable &t, const Options::Mode &options)
  : domain_name_(0), problem_name_(0),
    tab_(t), options_(options),
    dom_top_type_(0), dom_goal_(0),
    normal_execution_(0),
    clg_translation_(false),
    lw1_translation_(false),
    lw1_default_sensing_(0), lw1_default_sensing_proxy_(0) {

    // setup predicate for equality
    StringTable::Cell *sc = tab_.inserta("object");
    dom_top_type_ = new TypeSymbol(sc->text);
    sc->val = dom_top_type_;
    sc = tab_.inserta("=");
    dom_eq_pred_ = new PredicateSymbol(sc->text);
    sc->val = dom_eq_pred_;
    dom_eq_pred_->param_.push_back(new VariableSymbol("?x"));
    dom_eq_pred_->param_.push_back(new VariableSymbol("?y"));
    dom_eq_pred_->param_[0]->sym_type_ = dom_top_type_;
    dom_eq_pred_->param_[1]->sym_type_ = dom_top_type_;
}

PDDL_Base::~PDDL_Base() {
    delete dom_eq_pred_;
    delete dom_top_type_;
    delete dom_goal_;

    // TODO: for being able to remove actions/sensors and other symbols, symbols
    // cannot be shared between the parser and *-instances. Probably will need to
    // a symbol tape to store the symbols for each instance.
    for( size_t k = 0; k < dom_init_.size(); ++k )
        delete dom_init_[k];
    for( size_t k = 0; k < dom_hidden_.size(); ++k ) {
        for( size_t j = 0; j < dom_hidden_[k].size(); ++j )
            delete dom_hidden_[k][j];
    }
    for( size_t k = 0; k < dom_actions_.size(); ++k )
        delete dom_actions_[k];
    for( size_t k = 0; k < dom_sensors_.size(); ++k )
        delete dom_sensors_[k];
    for( size_t k = 0; k < dom_axioms_.size(); ++k )
        delete dom_axioms_[k];
    for( size_t k = 0; k < dom_observables_.size(); ++k )
        delete dom_observables_[k];
    for( size_t k = 0; k < dom_stickies_.size(); ++k )
        delete dom_stickies_[k];

    for( size_t k = 0; k < dom_constants_.size(); ++k )
        delete dom_constants_[k];
    for( size_t k = 0; k < dom_predicates_.size(); ++k )
        delete dom_predicates_[k];
    for( size_t k = 0; k < dom_types_.size(); ++k )
        delete dom_types_[k];
}

void PDDL_Base::set_variable_type(var_symbol_vec &vec, size_t n, TypeSymbol *t) {
    for( size_t k = n; k > 0; k-- ) {
        if( vec[k-1]->sym_type_ != 0 ) return;
        vec[k-1]->sym_type_ = t;
    }
}

void PDDL_Base::set_type_type(type_symbol_vec &vec, size_t n, TypeSymbol *t) {
    for( size_t k = vec.size(); k > 0; k-- ) {
        if( vec[k-1]->sym_type_ != 0 ) return;
        vec[k-1]->sym_type_ = t;
    }
}

void PDDL_Base::set_constant_type(symbol_vec &vec, size_t n, TypeSymbol *t) {
    for( size_t k = n; k > 0; k-- ) {
        if( vec[k-1]->sym_type_ != 0 ) return;
        vec[k-1]->sym_type_ = t;
        t->add_element(vec[k-1]);
    }
}

void PDDL_Base::clear_param(var_symbol_vec &vec, size_t start) {
    for( size_t k = start; k < vec.size(); ++k )
        tab_.set(vec[k]->print_name_, static_cast<void*>(0));
}

void PDDL_Base::insert_atom(ptr_table &t, Atom *a) {
    ptr_table *r = &t;
    for( size_t k = 0; k < a->param_.size(); ++k )
        r = r->insert_next(a->param_[k]);
    r->val = a;
}

PDDL_Base::PredicateSymbol* PDDL_Base::find_type_predicate(Symbol *type_sym) {
    for( size_t k = 0; k < dom_predicates_.size(); ++k ) {
        if( dom_predicates_[k]->print_name_ == type_sym->print_name_ )
            return dom_predicates_[k];
    }
    cout << Utils::error() << "no type predicate found for type " << type_sym->print_name_ << endl;
    exit(255);
}

void PDDL_Base::calculate_strongly_static_predicates() const {
    cout << Utils::magenta() << "strongly-static predicates:" << Utils::normal();
    bool some_strongly_static = false;
    for( size_t p = 0; p < dom_predicates_.size(); ++p ) {
        PredicateSymbol &pred = *dom_predicates_[p];
        bool strongly_static = true;

        for( size_t k = 0; strongly_static && (k < lw1_variables_.size()); ++k ) {
            for( size_t i = 0; strongly_static && (i < lw1_variables_[k]->domain_.size()); ++i )
                strongly_static = lw1_variables_[k]->domain_[i]->is_strongly_static(pred);
        }

        for( size_t k = 0; strongly_static && (k < dom_init_.size()); ++k ) {
            const InitElement &ielement = *dom_init_[k];
            strongly_static = ielement.is_strongly_static(pred);
        }

        for( size_t k = 0; strongly_static && (k < dom_axioms_.size()); ++k ) {
            const Axiom &axiom = *dom_axioms_[k];
            strongly_static = axiom.head_->is_strongly_static(pred);
        }

        for( size_t k = 0; strongly_static && (k < dom_actions_.size()); ++k ) {
            Action &act = *dom_actions_[k];
            strongly_static = act.effect_ == 0 ? true : act.effect_->is_strongly_static(pred);
            strongly_static = strongly_static && (act.sensing_ == 0 ? true : act.sensing_->is_strongly_static(pred));
        }

        if( lw1_default_sensing_ != 0 )
            strongly_static = strongly_static && lw1_default_sensing_->is_strongly_static(pred);

        pred.strongly_static_ = strongly_static;
        if( strongly_static ) cout << " '" << pred.print_name_ << "'";
        if( strongly_static ) some_strongly_static = true;
    }
    if( !some_strongly_static ) cout << " <none>";
    cout << endl;
}

bool PDDL_Base::truth_value_in_initial_situation(const Atom &literal) const {
    //cout << "Fetching truth value of " << literal << " at init: " << flush;
    assert(literal.pred_->strongly_static_);
    unsigned_atom_set::const_iterator it = set_of_initial_literals_.find(literal);
    if( it != set_of_initial_literals_.end() ) {
        //cout << "value=" << (literal.negated_ == it->negated_ ? "true" : "false") << endl;
        return literal.negated_ == it->negated_;
    } else {
        //cout << "value=" << (literal.negated_ ? "true" : "false") << endl;
        return literal.negated_;
    }
}

void PDDL_Base::instantiate_elements() {
    // calculate strongly-static predicates. Used to instantiate
    // things more efficiently by not generating objects with
    // false static conditions.
    calculate_strongly_static_predicates();
    Atom::pddl_base_ = this;

    // instantiate init elements. We do this first to calculate set
    // of initial literals so that formula grounding is more efficient
    init_element_list ilist;
    for( size_t k = 0; k < dom_init_.size(); ++k ) {
        dom_init_[k]->instantiate(ilist);
        delete dom_init_[k];
    }
    dom_init_.clear();
    dom_init_.reserve(ilist.size());
    dom_init_.insert(dom_init_.end(), ilist.begin(), ilist.end());

    // extract set of initial literals
    for( size_t k = 0; k < dom_init_.size(); ++k ) {
        if( dynamic_cast<const InitLiteral*>(dom_init_[k]) != 0 )
            set_of_initial_literals_.insert(*static_cast<const InitLiteral*>(dom_init_[k]));
    }

    // instantiate lw1 variables (only for lw1 translation)
    variable_list vlist;
    for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
        lw1_variables_[k]->instantiate(vlist);
        //delete lw1_variables_[k]; // CHECK: The symbol associated to orig var is deleted (not in instantiation)
    }
    lw1_variables_.clear();
    lw1_variables_.reserve(vlist.size());
    lw1_variables_.insert(lw1_variables_.end(), vlist.begin(), vlist.end());

    if( options_.is_enabled("lw1:print:variables") ) {
        for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
            const Variable &var = *lw1_variables_[k];
            cout << Utils::magenta() << "variable '" << var.print_name_ << "':" << Utils::normal();
            for( unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it )
                cout << " " << *it;
            cout << endl;
        }
    }

    // instantiate groups of variables
    variable_group_list vglist;
    for( size_t k = 0; k < lw1_variable_groups_.size(); ++k ) {
        lw1_variable_groups_[k]->instantiate(this, vglist);
        //delete lw1_variable_groups_[k]; // CHECK: The symbol associated to orig var is deleted (not in instantiation)
    }
    lw1_variable_groups_.clear();
    lw1_variable_groups_.reserve(vglist.size());
    lw1_variable_groups_.insert(lw1_variable_groups_.end(), vglist.begin(), vglist.end());
    lw1_remove_empty_variable_groups();

    if( options_.is_enabled("lw1:print:variables:groups") ) {
        for( size_t k = 0; k < lw1_variable_groups_.size(); ++k ) {
            const VariableGroup &group = *lw1_variable_groups_[k];
            cout << Utils::magenta() << "variable group: " << Utils::normal()
                 << group.to_string()
                 << endl;
        }
    }

    // ground default sensing model
    if( lw1_default_sensing_proxy_ != 0 ) {
        lw1_default_sensing_ = lw1_default_sensing_proxy_->ground();
        lw1_finish_grounding_of_sensing(lw1_default_sensing_);
    }

    // instantiate actions
    action_list alist;
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        dom_actions_[k]->instantiate(alist);
        delete dom_actions_[k];
    }
    dom_actions_.clear();
    dom_actions_.reserve(alist.size());
    dom_actions_.insert(dom_actions_.end(), alist.begin(), alist.end());

    // finish grounding the sensing and insert default-sensing-model into action with empty sensing models
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        Action &action = *dom_actions_[k];
        if( action.sensing_ != 0 )
            lw1_finish_grounding_of_sensing(action.sensing_);
        else if( lw1_default_sensing_ != 0 )
            action.sensing_ = lw1_default_sensing_->copy_and_simplify();
    }

    // instantiate sensors
    sensor_list slist;
    for( size_t k = 0; k < dom_sensors_.size(); ++k ) {
        dom_sensors_[k]->instantiate(slist);
        delete dom_sensors_[k];
    }
    dom_sensors_.clear();
    dom_sensors_.reserve(slist.size());
    dom_sensors_.insert(dom_sensors_.end(), slist.begin(), slist.end());

    // instantiate axioms
    axiom_list xlist;
    for( size_t k = 0; k < dom_axioms_.size(); ++k ) {
        dom_axioms_[k]->instantiate(xlist);
        delete dom_axioms_[k];
    }
    dom_axioms_.clear();
    dom_axioms_.reserve(xlist.size());
    dom_axioms_.insert(dom_axioms_.end(), xlist.begin(), xlist.end());

    // instantiate observables
    cout << "instantiating observables ..." << flush;
    observable_list olist;
    for( size_t k = 0; k < dom_observables_.size(); ++k ) {
        dom_observables_[k]->instantiate(olist);
        delete dom_observables_[k];
    }
    dom_observables_.clear();
    dom_observables_.reserve(olist.size());
    dom_observables_.insert(dom_observables_.end(), olist.begin(), olist.end());
    cout << " done" << endl;

    // instantiate stickies
    cout << "instantiating stickies ..." << flush;
    sticky_list tlist;
    for( size_t k = 0; k < dom_stickies_.size(); ++k ) {
        dom_stickies_[k]->instantiate(tlist);
        delete dom_stickies_[k];
    }
    dom_stickies_.clear();
    dom_stickies_.reserve(olist.size());
    dom_stickies_.insert(dom_stickies_.end(), tlist.begin(), tlist.end());
    cout << " done" << endl;

    // calculate static atoms
    calculate_static_atoms();
}

void PDDL_Base::calculate_static_atoms() {
    dom_static_atoms_.clear();
    unsigned_atom_set affected_atoms;

    // calculate affected atoms and candidate set for static atoms
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        const Action &action = *dom_actions_[k];
        if( action.precondition_ != 0 ) action.precondition_->extract_atoms(dom_static_atoms_);
        if( action.effect_ != 0 ) {
            action.effect_->extract_atoms(dom_static_atoms_);
            action.effect_->extract_atoms(affected_atoms, true);
        }
        if( action.observe_ != 0 ) action.observe_->extract_atoms(dom_static_atoms_);
        if( action.sensing_ != 0 ) {
            action.sensing_->extract_atoms(dom_static_atoms_);
            action.sensing_->extract_atoms(affected_atoms, false, true);
        }
    }

    for( size_t k = 0; k < dom_sensors_.size(); ++k ) {
        const Sensor &sensor = *dom_sensors_[k];
        if( sensor.condition_ != 0 ) sensor.condition_->extract_atoms(dom_static_atoms_);
        if( sensor.sense_ != 0 ) sensor.sense_->extract_atoms(dom_static_atoms_);
    }

    for( size_t k = 0; k < dom_axioms_.size(); ++k ) {
        const Axiom &axiom = *dom_axioms_[k];
        if( axiom.body_ != 0 ) axiom.body_->extract_atoms(dom_static_atoms_);
        if( axiom.head_ != 0 ) axiom.head_->extract_atoms(dom_static_atoms_);
    }

    for( size_t k = 0; k < dom_init_.size(); ++k ) {
        dom_init_[k]->extract_atoms(dom_static_atoms_);
    }

    // erase affected atoms from candidate set
    for( unsigned_atom_set::iterator it = affected_atoms.begin(); it != affected_atoms.end(); ++it )
        dom_static_atoms_.erase(*it);

    if( options_.is_enabled("problem:print:atom:static") ) {
        cout << Utils::magenta() << "static atoms (n=" << dom_static_atoms_.size() << "):" << Utils::normal();
        for( unsigned_atom_set::iterator it = dom_static_atoms_.begin(); it != dom_static_atoms_.end(); ++it )
            cout << " " << *it;
        cout << (dom_static_atoms_.empty() ? " <none>" : "") << endl;
    }
}

bool PDDL_Base::is_static_atom(const Atom &atom) const {
    return atom.pred_->strongly_static_ || (dom_static_atoms_.find(atom) != dom_static_atoms_.end());
}

PDDL_Base::PredicateSymbol* PDDL_Base::create_predicate(const string &name, const var_symbol_vec *param) {
    PredicateSymbol *new_predicate_symbol = new PredicateSymbol(strdup(name.c_str()));
    if( param != 0 ) new_predicate_symbol->param_ = *param;
    dom_predicates_.push_back(new_predicate_symbol);
    return new_predicate_symbol;
}

PDDL_Base::Atom* PDDL_Base::create_atom(const string &name, const var_symbol_vec *param) {
    Atom *atom = new Atom(create_predicate(name, param));
    //cout << "Atom " << *atom << " created!" << endl;
    return atom;
}

void PDDL_Base::create_normal_execution_atom() {
    normal_execution_ = create_atom("normal-execution");
}

void PDDL_Base::declare_clg_translation() {
    if( !clg_translation_ )
        cout << Utils::blue() << "entering CLG-compatibility mode" << Utils::normal() << endl;
    clg_translation_ = true;
}

void PDDL_Base::clg_map_oneofs_and_clauses_to_invariants() {
    // extract oneofs and clauses
    vector<pair<int, InitOneof*> > oneofs;
    vector<pair<int, InitClause*> > clauses;
    for( size_t k = 0; k < dom_init_.size(); ++k ) {
        InitElement *ie = dom_init_[k];
        if( dynamic_cast<InitOneof*>(ie) != 0 ) {
            oneofs.push_back(make_pair(k, static_cast<InitOneof*>(ie)));
            dom_init_[k] = 0;
        } else if( dynamic_cast<InitClause*>(ie) != 0 ) {
            clauses.push_back(make_pair(k, static_cast<InitClause*>(ie)));
            dom_init_[k] = 0;
        }
    }

    // make oneofs into exactly-one invariants
    for( size_t k = 0; k < oneofs.size(); ++k ) {
        Invariant invariant(Invariant::EXACTLY_ONE, *oneofs[k].second);
        // BLAI: check precondition
        //if( normal_execution_ != 0 ) invariant.Xprecondition_ = Literal(*normal_execution_).copy();
        dom_init_[oneofs[k].first] = new InitInvariant(invariant);
        invariant.clear();           // to avoid destruction of elements
        oneofs[k].second->clear();   // to avoid destruction of elements
        delete oneofs[k].second;
    }

    // make clauses into at-least-one invariants
    for( size_t k = 0; k < clauses.size(); ++k ) {
        Invariant invariant(Invariant::AT_LEAST_ONE, *clauses[k].second);
        // BLAI: check precondition
        //if( normal_execution_ != 0 ) invariant.Xprecondition_ = Literal(*normal_execution_).copy();
        dom_init_[clauses[k].first] = new InitInvariant(invariant);
        invariant.clear();           // to avoid destruction of elements
        clauses[k].second->clear();  // to avoid destruction of elements
        delete clauses[k].second;
    }
}

void PDDL_Base::clg_translate_actions() {
    if( !clg_translation_ ) return;

    // compute actions that need translation (those with :observe statement)
    action_vec actions_to_translate;
    for( int k = 0; k < (int)dom_actions_.size(); ++k ) {
        if( dom_actions_[k]->observe_ != 0 ) {
            actions_to_translate.push_back(dom_actions_[k]);
            dom_actions_[k] = dom_actions_.back();
            dom_actions_.pop_back();
            --k;
        } else {
            // this action is not modified so it is an original action
            original_actions_.insert(dom_actions_[k]->print_name_);
        }
    }

    // create atoms needed in translation
    if( !actions_to_translate.empty() ) {
        create_normal_execution_atom();

        // extend initial and goal situations with (normal-execution)
        dom_init_.push_back(new InitLiteral(*normal_execution_));
        if( dom_goal_ == 0 ) {
            dom_goal_ = new And;
        } else if( dynamic_cast<const And*>(dom_goal_) == 0 ) {
            And *new_goal = new And;
            assert(dom_goal_->is_grounded());
            new_goal->push_back(dom_goal_->copy_and_simplify());
            delete dom_goal_;
            dom_goal_ = new_goal;
        }
        static_cast<And*>(const_cast<Condition*>(dom_goal_))->push_back(Literal(*normal_execution_).copy());

        // extend preconditions of other actions with (normal-execution).
        if( !dom_actions_.empty() ) {
            cout << Utils::blue() << "(clg) extending preconditions with '(normal-execution)' for "
                 << dom_actions_.size() << " action(s)" << Utils::normal() << endl;
            for( size_t k = 0; k < dom_actions_.size(); ++k ) {
                Action &action = *dom_actions_[k];
                And *precondition = new And;
                if( action.precondition_ != 0 ) precondition->push_back(action.precondition_);
                precondition->push_back(new Literal(*normal_execution_));
                assert(precondition->is_grounded());
                action.precondition_ = precondition->copy_and_simplify();
                delete precondition;
            }
        }
    }

    // translate actions
    for( size_t k = 0; k < actions_to_translate.size(); ++k ) {
        Action *action = actions_to_translate[k];
        assert(action->observe_->is_grounded());
        dom_actions_.push_back(action);
        clg_translate(*action);
    }
}

void PDDL_Base::clg_translate(Action &action) {
    assert(action.observe_ != 0);

    original_actions_.insert(action.print_name_); // this action counts as the original action

    // save observations and create (do-post-sense-for-<action> <args>) predicate
    const Effect *observe = action.observe_;
    Atom need_post(create_predicate(string("need-post-for-") + action.print_name_, &action.param_));
    need_post.param_.insert(need_post.param_.begin(), action.param_.begin(), action.param_.end());

    // Must do 3 things for this action:
    //
    // 1) modify the action to add precondition (normal-execution), and
    //    effects (do-post-sense-for-<action> <args>) and (not (normal-execution))

    And precondition;
    if( action.precondition_ != 0 ) precondition.push_back(action.precondition_);
    precondition.push_back(Literal(*normal_execution_).copy());
    assert(precondition.is_grounded());
    action.precondition_ = precondition.copy_and_simplify();
    for( size_t k = 0; k < precondition.size(); ++k )
        delete precondition[k];
    precondition.clear();

    AndEffect effect;
    if( action.effect_ != 0 ) effect.push_back(action.effect_);
    effect.push_back(AtomicEffect(*normal_execution_).negate());
    effect.push_back(AtomicEffect(need_post).copy());
    assert(effect.is_grounded());
    action.effect_ = effect.copy_and_simplify();
    for( size_t k = 0; k < effect.size(); ++k )
        delete effect[k];
    effect.clear();

    action.observe_ = 0;
    if( options_.is_enabled("clg:print:effect") || options_.is_enabled("clg:print:generated") )
        cout << Utils::yellow() << action << Utils::normal();

    //
    // 2) create sensor sensor-<action> with same arguments, condition
    //    (do-post-sense-for-<action> <args>), and sense <observation>

    Sensor *sensor = new Sensor(strdup((string("sensor-for-") + action.print_name_).c_str()));
    clone_parameters(action.param_, sensor->param_);
    sensor->condition_ = new Literal(need_post);
    sensor->sense_ = observe;

    // remap parameters and insert
    const_cast<Condition*>(sensor->condition_)->remap_parameters(action.param_, sensor->param_);
    const_cast<Effect*>(sensor->sense_)->remap_parameters(action.param_, sensor->param_);
    assert(!sensor->condition_->has_free_variables(sensor->param_));
    assert(!sensor->sense_->has_free_variables(sensor->param_));
    dom_sensors_.push_back(sensor);
    if( options_.is_enabled("clg:print:sensors") || options_.is_enabled("clg:print:generated") )
        cout << Utils::yellow() << *sensor << Utils::normal();

    //
    // 3) create action (post-sense-<action> <args>) with precondition
    //    (do-post-sense-for-<action> <args>) and effects that remove
    //    precondition and add (normal-execution)

    Action *post_action = new Action(strdup((string(action.print_name_) + "__post__").c_str()));
    clone_parameters(action.param_, post_action->param_);
    post_action->precondition_ = Literal(need_post).copy();
    effect.push_back(AtomicEffect(*normal_execution_).copy());
    effect.push_back(AtomicEffect(need_post).negate());
    post_action->effect_ = effect.copy_and_simplify();
    delete effect[1];
    delete effect[0];
    effect.clear();

    // remap parameters and insert
    const_cast<Condition*>(post_action->precondition_)->remap_parameters(action.param_, post_action->param_);
    const_cast<Effect*>(post_action->effect_)->remap_parameters(action.param_, post_action->param_);
    assert(!post_action->precondition_->has_free_variables(post_action->param_));
    assert(!post_action->effect_->has_free_variables(post_action->param_));
    dom_actions_.push_back(post_action);
    if( options_.is_enabled("clg:print:post") || options_.is_enabled("clg:print:generated") )
        cout << Utils::yellow() << *post_action << Utils::normal();
}

void PDDL_Base::declare_lw1_translation() {
    if( !lw1_translation_ )
        cout << Utils::blue() << "performing lw1 translation" << Utils::normal() << endl;
    lw1_translation_ = true;
}

// Stores the atoms for all state variables in the unsigned_atom_set
// atoms_for_state_variables_.
void PDDL_Base::lw1_calculate_atoms_for_state_variables() {
    atoms_for_state_variables_.clear();
    for( int k = 0; k < int(lw1_variables_.size()); ++k ) {
        const Variable &var = *lw1_variables_[k];
        if( var.is_state_variable() ) {
            atoms_for_state_variables_.insert(var.grounded_domain_.begin(), var.grounded_domain_.end());
        }
    }

    if( options_.is_enabled("lw1:print:atoms-for-state-variables") ) {
        cout << Utils::magenta() << "atoms for state variables:" << Utils::normal();
        for( unsigned_atom_set::iterator it = atoms_for_state_variables_.begin(); it != atoms_for_state_variables_.end(); ++it )
            cout << " " << *it;
        cout << endl;
    }
}

void PDDL_Base::lw1_calculate_atoms_for_variable_groups() {
    atoms_for_variable_groups_.clear();
    for( int k = 0; k < int(lw1_variable_groups_.size()); ++k ) {
        VariableGroup &group = *lw1_variable_groups_[k];
        int dsize = 1;
        for( int j = 0; j < int(group.grounded_group_.size()); ++j ) {
            const StateVariable &var = *group.grounded_group_[j];
            dsize *= var.is_binary() ? 2 : var.grounded_domain_.size();
        }

#ifdef DEBUG
        cout << Utils::magenta() << "variable group '" << group.print_name_ << "':" << Utils::normal() << endl
             << "  values[dsize=" << dsize << "]:" << flush;
#endif

        for( int j = 0; j < dsize; ++j ) {
            string name = string("vg_") + to_string(k) + "_" + to_string(j);
            Atom *new_atom = create_atom(name);
            group.grounded_domain_.insert(*new_atom);
            atoms_for_variable_groups_.insert(*new_atom);
#ifdef DEBUG
            cout << " " << *new_atom;
#endif
            delete new_atom;
        }
#ifdef DEBUG
        cout << endl;
#endif
    }
}

void PDDL_Base::lw1_calculate_beams_for_grounded_observable_variables() {
    for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
        Variable &var = *lw1_variables_[k];
        if( var.is_observable_variable() ) {
            lw1_calculate_beam_for_grounded_variable(var);

            // print beam (if requested)
            if( options_.is_enabled("lw1:print:beams") ) {
                for( unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it ) {
                    cout << Utils::magenta()
                         << "beam for value '" << *it << "' of var '" << var.print_name_ << "' ('*' means static):"
                         << Utils::normal();
                    const unsigned_atom_set &beam = var.beam_.at(*it);
                    for( unsigned_atom_set::const_iterator jt = beam.begin(); jt != beam.end(); ++jt )
                        cout << " " << *jt << (is_static_atom(*jt) ? "*" : "");
                    cout << endl;
                }
                if( var.is_binary() ) {
                    Atom negated(*var.grounded_domain_.begin(), true);
                    cout << Utils::magenta()
                         << "beam for value '" << negated << "' of var '" << var.print_name_ << "' ('*' means static):"
                         << Utils::normal();
                    const unsigned_atom_set &beam = var.beam_.at(negated);
                    for( unsigned_atom_set::const_iterator jt = beam.begin(); jt != beam.end(); ++jt )
                        cout << " " << *jt << (is_static_atom(*jt) ? "*" : "");
                    cout << endl;
                }
            }

            // remove static atoms from beams
            for( unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it ) {
                unsigned_atom_set reduced_beam;
                if( var.beam_.find(*it) == var.beam_.end() ) continue;
                const unsigned_atom_set &beam = var.beam_.at(*it);
                for( unsigned_atom_set::const_iterator jt = beam.begin(); jt != beam.end(); ++jt ) {
                    if( !is_static_atom(*jt) ) reduced_beam.insert(*jt);
                }
                var.beam_[*it] = reduced_beam;
                if( reduced_beam.empty() && options_.is_enabled("lw1:boost:compile-static-observables") ) {
                    cout << Utils::error() << "lw1:boost:compile-static-observables is deprecated" << endl;
                    exit(-1);
                    lw1_compile_static_observable(*it);
                }
            }
        }
    }
}

void PDDL_Base::lw1_calculate_beam_for_grounded_variable(Variable &var) {
    if( var.is_state_variable() ) {
        for( unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it )
            var.beam_[*it].insert(*it);
    } else {
        // fill up beams for values of variable
        for( int k = 0; k < int(dom_actions_.size()); ++k ) {
            const Action &action = *dom_actions_[k];
            if( action.sensing_ != 0 )
                action.sensing_->extend_beam_for_variable(var);
        }

        // remove values with empty beam
        for( unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ) {
            if( var.beam_.find(*it) == var.beam_.end() )
                var.grounded_domain_.erase(*it++);
            else
                ++it;
        }

        signed_atom_set values;
        values.insert(var.grounded_domain_.begin(), var.grounded_domain_.end());
        if( var.is_binary() ) values.insert(Atom(*var.grounded_domain_.begin(), true));

        // calculate variable group where to filter this observable literal
        //for( unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it ) {
        for( signed_atom_set::const_iterator it = values.begin(); it != values.end(); ++it ) {
            //std::map<Atom, unsigned_atom_set, Atom::unsigned_less_comparator>::const_iterator jt = var.beam_.find(*it); // CHECK
            //assert(jt != var.beam_.end()); // CHECK
            //const unsigned_atom_set &beam = jt->second; // CHECK
            const unsigned_atom_set &beam = var.beam_.at(*it);

            VariableGroup *best_group = 0;
            for( int k = 0; k < int(lw1_variable_groups_.size()); ++k ) {
                VariableGroup &group = *lw1_variable_groups_[k];
                bool good = true;
                for( unsigned_atom_set::const_iterator kt = beam.begin(); good && (kt != beam.end()); ++kt ) {
                    bool found_in_group = false;
                    for( int j = 0; j < int(lw1_variables_.size()); ++j ) {
                        const Variable &v = *lw1_variables_[j];
                        if( v.is_state_variable() && (v.grounded_domain_.find(*kt) != v.grounded_domain_.end()) ) {
                            if( group.grounded_group_str_.find(v.print_name_) != group.grounded_group_str_.end() ) {
                                found_in_group = true;
                                break;;
                            }
                        }
                    }
                    good = good && found_in_group;
                }
                if( good && ((best_group == 0) || (group.grounded_group_.size() < best_group->grounded_group_.size())) )
                    best_group = &group;
            }

            if( best_group != 0 ) {
#ifdef DEBUG
                cout << "observation '" << *it << "' for " << var << " will be filtered in group " << best_group->print_name_ << endl;
#endif
                best_group->filtered_observations_.push_back(make_pair(&var, *it));
            }
        }
    }
}

void PDDL_Base::lw1_remove_variables_with_empty_grounded_domain() {
    for( int k = 0; k < int(lw1_variables_.size()); ++k ) {
        const Variable &var = *lw1_variables_[k];
        if( var.grounded_domain_.empty() ) {
            cout << "removing variable '" << var.to_string(true) << "' because it has empty grounded domain" << endl;
            delete &var;
            lw1_variables_[k] = lw1_variables_.back();
            lw1_variables_.pop_back();
            --k;
        }
    }
}

void PDDL_Base::lw1_remove_empty_variable_groups() {
    for( int k = 0; k < int(lw1_variable_groups_.size()); ++k ) {
        const VariableGroup &group = *lw1_variable_groups_[k];
        if( group.grounded_group_.empty() ) {
            cout << "removing variable group '" << group.print_name_ << "' because it is empty" << endl;
            delete &group;
            lw1_variable_groups_[k] = lw1_variable_groups_.back();
            lw1_variable_groups_.pop_back();
            --k;
        }
    }
}

void PDDL_Base::lw1_translate_actions() {
    assert(!options_.is_enabled("lw1:strict"));
    assert(lw1_translation_);

    // compute actions that need translation (those with non-null sensing model)
    action_vec actions_to_translate;
    for( int k = 0; k < (int)dom_actions_.size(); ++k ) {
        if( dom_actions_[k]->sensing_ != 0 ) {
            actions_to_translate.push_back(dom_actions_[k]);
            dom_actions_[k] = dom_actions_.back();
            dom_actions_.pop_back();
            --k;
        } else {
            // this action is not modified so it is an original action
            original_actions_.insert(dom_actions_[k]->print_name_);
        }
    }

    // create atoms needed in translation
    if( !actions_to_translate.empty() ) {
        create_normal_execution_atom();

        // extend initial and goal situations with (normal-execution)
        dom_init_.push_back(new InitLiteral(*normal_execution_));
        if( dom_goal_ == 0 ) {
            dom_goal_ = new And;
        } else if( dynamic_cast<const And*>(dom_goal_) == 0 ) {
            And *new_goal = new And;
            assert(dom_goal_->is_grounded());
            new_goal->push_back(dom_goal_->copy_and_simplify());
            delete dom_goal_;
            dom_goal_ = new_goal;
        }
        static_cast<And*>(const_cast<Condition*>(dom_goal_))->push_back(Literal(*normal_execution_).copy());

        // extend preconditions of other actions with (normal-execution).
        if( !dom_actions_.empty() ) {
            cout << Utils::blue() << "(lw1) extending preconditions with '(normal-execution)' for "
                 << dom_actions_.size() << " action(s)" << Utils::normal() << endl;
            for( size_t k = 0; k < dom_actions_.size(); ++k ) {
                Action &action = *dom_actions_[k];
                And *precondition = new And;
                if( action.precondition_ != 0 ) precondition->push_back(action.precondition_);
                precondition->push_back(Literal(*normal_execution_).copy());
                assert(precondition->is_grounded());
                action.precondition_ = precondition->copy_and_simplify();
                delete precondition;
            }
        }
    }

    // translate actions
    for( size_t k = 0; k < actions_to_translate.size(); ++k ) {
        Action *action = actions_to_translate[k];
        assert(action->sensing_->is_grounded());
        lw1_translate(*action);
        //delete action; // CHECK: guess: delete params that are needed in sensing model (invariants)
    }

    // complete actions' effects
    if( options_.is_enabled("lw1:boost:complete-effects") )
        lw1_complete_effect_for_actions();
}

void PDDL_Base::lw1_translate(Action &action) {
    assert(!options_.is_enabled("lw1:strict"));
    assert(action.param_.empty()); // action must be instantiated

    And precondition;
    AndEffect effect;

    unsigned_atom_set atoms_to_remove(atoms_for_state_variables_);
    atoms_to_remove.insert(static_observable_atoms_.begin(), static_observable_atoms_.end());
    const Sensing *reduced_sensing = action.sensing_->reduce(atoms_to_remove);
    bool need_effect_action = action.effect_ != 0;
    bool need_set_sensing_action = reduced_sensing != 0;

    // calculate sensed atoms
    unsigned_atom_set sensed_atoms;
    action.sensing_->extract_atoms(sensed_atoms, true);

    // fetch (create) (need-post) atoms
    const Atom &need_post = *lw1_fetch_enabler_for_sensing(sensed_atoms);

    // create __effect__ action (if needed)
    if( need_effect_action ) {
        // Action that execute only the effects on state variables (i.e. no sensing model involved)
        Action *effect_action = new Action(strdup((string(action.print_name_) + "__effect__").c_str()));
        original_actions_.insert(effect_action->print_name_);             // this action counts as the original action

        // precondition
        if( action.precondition_ != 0 ) precondition.push_back(action.precondition_);
        precondition.push_back(Literal(*normal_execution_).copy());       // (normal-execution)
        assert(precondition.is_grounded());
        effect_action->precondition_ = precondition.copy_and_simplify();
        delete precondition.back();
        precondition.clear();

        // effect
        effect.push_back(action.effect_);
        effect.push_back(AtomicEffect(*normal_execution_).negate());      // (not (normal-execution))
        if( need_set_sensing_action ) {
            const Atom& need_set_sensing = *lw1_fetch_need_set_sensing_atom(action);
            effect.push_back(AtomicEffect(need_set_sensing).copy());      // (need-set-sensing <param>)
        } else {
            effect.push_back(AtomicEffect(need_post).copy());             // (need-post <param>)
            for( unsigned_atom_set::const_iterator it = sensed_atoms.begin(); it != sensed_atoms.end(); ++it ) {
                const Atom& enabler = *lw1_fetch_enabler_for_sensing(*it);
                effect.push_back(AtomicEffect(enabler).copy());      // (sensing-<atom>)
            }
            lw1_sensing_models_.push_back(make_pair(&action, action.sensing_->copy_and_simplify()));
            //cout << Utils::yellow()<< "XX0: action=" << action.print_name_ << ", sm=" << *lw1_sensing_models_.back().second << Utils::normal() << endl;
        }
        assert(effect.is_grounded());
        effect_action->effect_ = effect.copy_and_simplify();
        while( effect.size() > 1 ) {
            delete effect.back();
            effect.pop_back();
        }
        effect.clear();

        // insert action
        dom_actions_.push_back(effect_action);
        if( options_.is_enabled("lw1:print:effect") || options_.is_enabled("lw1:print:generated") )
            cout << Utils::yellow() << *effect_action << Utils::normal();
    }

    if( need_set_sensing_action ) {
        // Action that computes the effects on observables (i.e. sensing model)
        Action *set_sensing_action = new Action(strdup((string(action.print_name_) + "__set_sensing__").c_str()));

        // precondition
        if( need_effect_action ) {
            const Atom& need_set_sensing = *lw1_fetch_need_set_sensing_atom(action);
            precondition.push_back(Literal(need_set_sensing).copy());     // (need-set-sensing <param>)
        } else {
            if( action.precondition_ != 0 ) precondition.push_back(action.precondition_);
            precondition.push_back(Literal(*normal_execution_).copy());   // (normal-execution)
            original_actions_.insert(set_sensing_action->print_name_);    // this action counts as the original action
        }
        assert(precondition.is_grounded());
        set_sensing_action->precondition_ = precondition.copy_and_simplify();
        delete precondition.back();
        precondition.clear();

        // effects
        effect.push_back(reduced_sensing->as_effect());
        effect.push_back(AtomicEffect(need_post).copy());                 // (need-post <param>)
        for( unsigned_atom_set::const_iterator it = sensed_atoms.begin(); it != sensed_atoms.end(); ++it ) {
            const Atom& enabler = *lw1_fetch_enabler_for_sensing(*it);
            effect.push_back(AtomicEffect(enabler).copy());          // (sensing-<atom>)
        }
        if( need_effect_action ) {
            const Atom& need_set_sensing = *lw1_fetch_need_set_sensing_atom(action);
            effect.push_back(AtomicEffect(need_set_sensing).negate());    // (not (need-set-sensing <param>))
        } else {
            effect.push_back(AtomicEffect(*normal_execution_).negate());  // (not (normal-execution))
        }
        assert(effect.is_grounded());
        set_sensing_action->effect_ = effect.copy_and_simplify();
        while( !effect.empty() ) {
            delete effect.back();
            effect.pop_back();
        }

        // insert action
        dom_actions_.push_back(set_sensing_action);
        if( options_.is_enabled("lw1:print:set-sensing") || options_.is_enabled("lw1:print:generated") )
            cout << Utils::yellow() << *set_sensing_action << Utils::normal();

        // store sensing model for generating invariants later
        lw1_sensing_models_.push_back(make_pair(&action, action.sensing_->copy_and_simplify()));
        //cout << Utils::yellow() << "XX1: action=" << action.print_name_ << ", sm=" << *lw1_sensing_models_.back().second << Utils::normal() << endl;
    }

    if( !need_effect_action && !need_set_sensing_action ) {
        // Action that only turns on the sensor
        Action *turn_on_sensor_action = new Action(strdup((string(action.print_name_) + "__turn_on_sensor__").c_str()));
        original_actions_.insert(turn_on_sensor_action->print_name_);     // this action counts as the original action

        // precondition
        if( action.precondition_ != 0 ) precondition.push_back(action.precondition_);
        precondition.push_back(Literal(*normal_execution_).copy());       // (normal-execution)
        assert(precondition.is_grounded());
        turn_on_sensor_action->precondition_ = precondition.copy_and_simplify();
        delete precondition.back();
        precondition.clear();

        // effects
        effect.push_back(AtomicEffect(need_post).copy());                 // (need-post <param>)
        effect.push_back(AtomicEffect(*normal_execution_).negate());      // (not (normal-execution))
        for( unsigned_atom_set::const_iterator it = sensed_atoms.begin(); it != sensed_atoms.end(); ++it ) {
            const Atom& enabler = *lw1_fetch_enabler_for_sensing(*it);
            effect.push_back(AtomicEffect(enabler).copy());          // (sensing-<atom>)
        }
        turn_on_sensor_action->effect_ = effect.copy_and_simplify();
        while( !effect.empty() ) {
            delete effect.back();
            effect.pop_back();
        }

        // insert action
        dom_actions_.push_back(turn_on_sensor_action);
        if( options_.is_enabled("lw1:print:turn-on-sensor") || options_.is_enabled("lw1:print:generated") )
            cout << Utils::yellow() << *turn_on_sensor_action << Utils::normal();

        // store sensing model
        lw1_sensing_models_.push_back(make_pair(&action, action.sensing_->copy_and_simplify()));
        //cout << Utils::yellow()<< "XX2: action=" << action.print_name_ << ", sm=" << *lw1_sensing_models_.back().second << Utils::normal() << endl;
    }

    // Sensors for this action
    lw1_create_simple_sensors_for_atoms(sensed_atoms);

    // Post action that re-establish normal execution
    lw1_create_post_action(sensed_atoms);
}

void PDDL_Base::lw1_emit_and_protect_atoms_for_observable_variables(Instance &ins) const {
    for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
        const Variable &variable = *lw1_variables_[k];
        if( !variable.is_state_variable() ) {
            for( unsigned_atom_set::const_iterator it = variable.grounded_domain_.begin(); it != variable.grounded_domain_.end(); ++it ) {
                const Atom &value = *it;
                index_set index;
                value.emit(ins, index);
                ins.protected_atoms_.insert(*index.begin() - 1);
            }
        }
    }
}

// CHECK: is this function needed? After fixing lw1_problem, it may be not!
// only used with lw1:boost:single-sensing-literal-enablers
void PDDL_Base::lw1_protect_enablers_for_sensing(Instance &ins) const {
    for( map<string, const Atom*>::const_iterator it = lw1_sensing_enabler_atoms_.begin(); it != lw1_sensing_enabler_atoms_.end(); ++it ) {
        const Atom &value = *it->second;
        index_set index;
        value.emit(ins, index);
        ins.protected_atoms_.insert(*index.begin() - 1);
        //cout << "protecting enabler: " << *it->second << endl; // CHECK
    }
}

void PDDL_Base::lw1_translate_actions_strict() {
    assert(options_.is_enabled("lw1:strict"));
    assert(lw1_translation_);

    // extract sensing models
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        const Action &action = *dom_actions_[k];
        if( action.sensing_ != 0 ) {
            lw1_sensing_models_.push_back(make_pair(&action, action.sensing_->copy_and_simplify()));
            //cout << Utils::yellow()<< "XX3: action=" << action.print_name_ << ", sm=" << *lw1_sensing_models_.back().second << Utils::normal() << endl;
        }
        original_actions_.insert(action.print_name_);
    }

    // if requested, manage sensing with post actions
    if( options_.is_enabled("lw1:boost:enable-post-actions") ) {
        // compute actions that need post actions (those with non-null sensing model)
        action_vec actions_to_translate;
        for( int k = 0; k < (int)dom_actions_.size(); ++k ) {
            if( dom_actions_[k]->sensing_ != 0 ) {
                actions_to_translate.push_back(dom_actions_[k]);
                dom_actions_[k] = dom_actions_.back();
                dom_actions_.pop_back();
                --k;
            }
        }

        // create atoms needed in translation
        if( !actions_to_translate.empty() ) {
            create_normal_execution_atom();

            // extend initial and goal situations with (normal-execution)
            dom_init_.push_back(new InitLiteral(*normal_execution_));
            if( dom_goal_ == 0 ) {
                dom_goal_ = new And;
            } else if( dynamic_cast<const And*>(dom_goal_) == 0 ) {
                And *new_goal = new And;
                assert(dom_goal_->is_grounded());
                new_goal->push_back(dom_goal_->copy_and_simplify());
                delete dom_goal_;
                dom_goal_ = new_goal;
            }
            static_cast<And*>(const_cast<Condition*>(dom_goal_))->push_back(Literal(*normal_execution_).copy());

            // extend preconditions of other actions with (normal-execution).
            if( !dom_actions_.empty() ) {
                cout << Utils::blue() << "(lw1) extending preconditions with '(normal-execution)' for "
                     << dom_actions_.size() << " action(s)" << Utils::normal() << endl;
                for( size_t k = 0; k < dom_actions_.size(); ++k ) {
                    Action &action = *dom_actions_[k];
                    And *precondition = new And;
                    if( action.precondition_ != 0 ) precondition->push_back(action.precondition_);
                    precondition->push_back(Literal(*normal_execution_).copy());
                    assert(precondition->is_grounded());
                    action.precondition_ = precondition->copy_and_simplify();
                    delete precondition;
                }
            }
        }

        // translate actions
        for( size_t k = 0; k < actions_to_translate.size(); ++k ) {
            Action *action = actions_to_translate[k];
            assert(action->sensing_->is_grounded());
            lw1_translate_strict_NEW(*action);
        }
    }

    // complete actions' effects
    if( options_.is_enabled("lw1:boost:complete-effects") )
        lw1_complete_effect_for_actions();
}

void PDDL_Base::lw1_translate_strict(Action &action) { // CHECK: replace this by NEW below
    assert(options_.is_enabled("lw1:strict"));
    assert(action.param_.empty()); // action must be instantiated
    cout << Utils::error() << "lw1_translate_strict() is deprecated by new function" << endl;
    exit(-1);

    // (normal-execution) must be inserted in precondition and it must
    // be deleted in effects. The effects should also assert the corresponding
    // enablers for sensing

    if( dynamic_cast<const And*>(action.precondition_) == 0 ) {
        And *new_precondition = new And;
        if( action.precondition_ != 0 ) new_precondition->push_back(action.precondition_);
        action.precondition_ = new_precondition;
    }
    const_cast<And*>(static_cast<const And*>(action.precondition_))->push_back(Literal(*normal_execution_).copy());

    if( dynamic_cast<const AndEffect*>(action.effect_) == 0 ) {
        AndEffect *new_effect = new AndEffect;
        if( action.effect_ != 0 ) new_effect->push_back(action.effect_);
        action.effect_ = new_effect;
    }
    const_cast<AndEffect*>(static_cast<const AndEffect*>(action.effect_))->push_back(AtomicEffect(*normal_execution_).negate());

    const Atom *last_action_atom = 0;
    if( options_.is_enabled("lw1:boost:single-sensing-literal-enablers") ) {
        cout << Utils::error() << "lw1:boost:single-sensing-literal-enablers is deprecated" << endl;
        exit(-1);
    } else {
        last_action_atom = &lw1_fetch_last_action_atom(action);
        const_cast<AndEffect*>(static_cast<const AndEffect*>(action.effect_))->push_back(AtomicEffect(*last_action_atom).copy());
    }

    dom_actions_.push_back(&action);
    if( options_.is_enabled("lw1:print:effect") || options_.is_enabled("lw1:print:generated") )
        cout << Utils::yellow() << action << Utils::normal();

    // create post-action that remove enablers for sensing and resumes normal-execution
    Action *post_action = new Action(strdup((string(action.print_name_) + "__post-action__").c_str()));
    And *precondition = new And;
    precondition->push_back(Literal(*normal_execution_).negate());
    precondition->push_back(Literal(*last_action_atom).copy());
    post_action->precondition_ = precondition;

    AndEffect *effect = new AndEffect;
    effect->push_back(AtomicEffect(*normal_execution_).copy());
    effect->push_back(AtomicEffect(*last_action_atom).negate());
    post_action->effect_ = effect;

    dom_actions_.push_back(post_action);
    if( options_.is_enabled("lw1:print:post") || options_.is_enabled("lw1:print:generated") )
        cout << Utils::yellow() << *post_action << Utils::normal();
}

void PDDL_Base::lw1_translate_strict_NEW(Action &action) {
    assert(options_.is_enabled("lw1:strict"));
    assert(action.param_.empty()); // action must be instantiated

    // (normal-execution) must be inserted in precondition and it must
    // be deleted in effects.

    // The effects should also add the corresponding need-post atom

    // calculate sensed atoms
    unsigned_atom_set sensed_atoms;
    action.sensing_->extract_atoms(sensed_atoms, true);
    const Atom &enabler_for_sensing = *lw1_fetch_enabler_for_sensing(sensed_atoms);

    And *new_precondition = 0;
    if( dynamic_cast<const And*>(action.precondition_) == 0 ) {
        new_precondition = new And;
        if( action.precondition_ != 0 ) new_precondition->push_back(action.precondition_);
    } else {
        new_precondition = const_cast<And*>(static_cast<const And*>(action.precondition_));
    }
    new_precondition->push_back(Literal(*normal_execution_).copy());
    action.precondition_ = new_precondition;

    AndEffect *new_effect = 0;
    if( dynamic_cast<const AndEffect*>(action.effect_) == 0 ) {
        new_effect = new AndEffect;
        if( action.effect_ != 0 ) new_effect->push_back(action.effect_);
    } else {
        new_effect = const_cast<AndEffect*>(static_cast<const AndEffect*>(action.effect_));
    }
    new_effect->push_back(AtomicEffect(*normal_execution_).negate());
    new_effect->push_back(AtomicEffect(enabler_for_sensing).copy());

    for( unsigned_atom_set::const_iterator it = sensed_atoms.begin(); it != sensed_atoms.end(); ++it ) {
        const Atom &enabler = *lw1_fetch_enabler_for_sensing(*it);
        new_effect->push_back(AtomicEffect(enabler).copy());
    }
    action.effect_ = new_effect;

    dom_actions_.push_back(&action);
    if( options_.is_enabled("lw1:print:effect") || options_.is_enabled("lw1:print:generated") )
        cout << Utils::yellow() << action << Utils::normal();

    // Post action that re-establish normal execution
    lw1_create_post_action(sensed_atoms);
}

void PDDL_Base::lw1_create_simple_sensors_for_atoms(const unsigned_atom_set &atoms) {
    for( unsigned_atom_set::const_iterator it = atoms.begin(); it != atoms.end(); ++it ) {
        const Atom &atom = *it;
        if( simple_sensors_for_variables_.find(atom.to_string(atom.negated_, true)) == simple_sensors_for_variables_.end() ) {
            Literal condition(*lw1_fetch_enabler_for_sensing(atom));
            lw1_create_sensors_for_atom(atom, condition);
            simple_sensors_for_variables_.insert(atom.to_string(atom.negated_, true));
        }
    }
}

void PDDL_Base::lw1_create_sensors_for_atom(const Atom &atom, const Condition &condition, int sensor_index) {
    bool variable_found = false;
    for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
        const Variable &var = *lw1_variables_[k];
        if( var.grounded_domain_.find(atom) != var.grounded_domain_.end() ) {
            if( !var.is_observable_variable() ) continue;
            variable_found = true;

            //if( !var.is_observable_variable() ) {
            //    cout << Utils::warning() << "variable " << var.print_name_
            //         << " isn't observable but its value " << atom << " is sensed" << endl;
            //}

            // create sensor for each enabler
            string name = string("sensor-for-") + var.to_string(true, true) + "-" + atom.to_string(atom.negated_, true) + "-true";
            if( sensor_index != -1 ) name += "-" + Utils::to_string(sensor_index);
            Sensor *sensor = new Sensor(strdup(name.c_str()));

            // condition of sensor is enabler plus conditions on other values of variable
            And *sensor_condition = 0;
            if( dynamic_cast<const And*>(&condition) != 0 )
                sensor_condition = static_cast<And*>(condition.copy_and_simplify());
            else {
                sensor_condition = new And;
                sensor_condition->push_back(condition.copy_and_simplify());
            }

            //for( unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it )
            //    if( *it != atom ) sensor_condition->push_back(Literal(*it).negate());
            sensor->condition_ = sensor_condition;

            // sensed value is atom
            sensor->sense_ = AtomicEffect(atom, atom.negated_).copy();

            // insert sensor
            dom_sensors_.push_back(sensor);
            if( options_.is_enabled("lw1:print:sensors") || options_.is_enabled("lw1:print:generated") )
                cout << Utils::yellow() << *sensor << Utils::normal();

            // if this is a binary variable, create a copy that sets value to false
            if( var.is_binary() ) {
                string name = string("sensor-for-") + var.to_string(true, true) + "-" + atom.to_string(atom.negated_, true) + "-false";
                if( sensor_index != -1 ) name += "-" + Utils::to_string(sensor_index);
                Sensor *sensor = new Sensor(strdup(name.c_str()));

                // condition of sensor is just enabler because there are no other values for the variable
                sensor->condition_ = condition.copy_and_simplify();

                // sensed value is negated atom
                sensor->sense_ = AtomicEffect(atom, !atom.negated_).copy();

                // insert sensor
                dom_sensors_.push_back(sensor);
                if( options_.is_enabled("lw1:print:sensors") || options_.is_enabled("lw1:print:generated") )
                    cout << Utils::yellow() << *sensor << Utils::normal();
            }
        }
    }

    if( !variable_found ) {
        cout << Utils::error() << "no observable variable found for (sensed) atom '"
             << atom << "'; sensor not generated" << endl;
    }
}

void PDDL_Base::lw1_create_sensors_for_atom(const Atom &atom, const signed_atom_set &condition, int sensor_index) {
    And casted_condition;
    casted_condition.reserve(condition.size());
    for( signed_atom_set::const_iterator it = condition.begin(); it != condition.end(); ++it )
        casted_condition.push_back(Literal(*it).copy());
    lw1_create_sensors_for_atom(atom, casted_condition, sensor_index);
}

void PDDL_Base::lw1_create_post_action(const unsigned_atom_set &atoms) {
    map<unsigned_atom_set, const Action*>::const_iterator it = post_actions_for_lw1_translation_.find(atoms);
    if( it == post_actions_for_lw1_translation_.end() ) {
        string name = string("post-action-") + Utils::to_string(post_actions_for_lw1_translation_.size());
        Action *post_action = new Action(strdup(name.c_str()));

        // precondition
        const Atom &enabler = *lw1_fetch_enabler_for_sensing(atoms);
        post_action->precondition_ = Literal(enabler).copy();

        // effect
        AndEffect effect;
        effect.push_back(AtomicEffect(*normal_execution_).copy());
        effect.push_back(AtomicEffect(enabler).negate());
        for( unsigned_atom_set::const_iterator it = atoms.begin(); it != atoms.end(); ++it ) {
            const Atom& enabler = *lw1_fetch_enabler_for_sensing(*it);
            effect.push_back(AtomicEffect(enabler).negate());
        }
        post_action->effect_ = effect.copy_and_simplify();
        delete effect[1];
        delete effect[0];
        effect.clear();

        // insert action
        post_actions_for_lw1_translation_.insert(make_pair(atoms, post_action));
        dom_actions_.push_back(post_action);
        if( options_.is_enabled("lw1:print:post") || options_.is_enabled("lw1:print:generated") )
            cout << Utils::yellow() << *post_action << Utils::normal();
    }
}

void PDDL_Base::lw1_finish_grounding_of_sensing(const Sensing* &sensing) {
    //cout << "GROUNDED (before finishing): " << *sensing << endl;
    const_cast<Sensing*>(sensing)->finish_grounding(this);
    //cout << "GROUNDED (after finishing): " << *sensing << endl;
    if( sensing->empty() ) {
        delete sensing;
        sensing = 0;
    }
}

void PDDL_Base::lw1_create_deductive_rules_for_variables() {
    cout << Utils::blue() << "(lw1) creating deductive rules for variables..." << Utils::normal() << endl;
    for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
        const Variable &var = *lw1_variables_[k];
        if( var.is_binary() ) continue;
        for( unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it ) {
            lw1_create_drule_var_exhaustive(var, *it);
            lw1_create_drule_var_exclusive(var, *it);
        }
    }
}

// exhaustivity of values for variable; i.e. AND_{x' != x} -x' => x for all values x of variable
void PDDL_Base::lw1_create_drule_var_exhaustive(const Variable &variable, const Atom &value) {
    assert(!value.negated_);
    string name = string("drule-var-exhaustive-") + variable.to_string(true, true) + "-" + value.to_string(false, true);
    Action *drule = new Action(strdup(name.c_str()));

    And *precondition = new And;
    for( unsigned_atom_set::const_iterator it = variable.grounded_domain_.begin(); it != variable.grounded_domain_.end(); ++it ) {
        assert(!it->negated_);
        if( &*it != &value )
            precondition->push_back(Literal(*it).negate());
        else
            drule->effect_ = AtomicEffect(*it).copy();
    }
    drule->precondition_ = precondition;

    // insert decision rules
    dom_actions_.push_back(drule);
    if( options_.is_enabled("lw1:print:drule:var") || options_.is_enabled("lw1:print:drule") )
        cout << Utils::yellow() << *drule << Utils::normal();
}

// mutual exclusivity of values for variable; i.e. x => -x' for all values x and x' of variable
void PDDL_Base::lw1_create_drule_var_exclusive(const Variable &variable, const Atom &value) {
    assert(!value.negated_);
    string name = string("drule-var-exclusive-") + variable.to_string(true, true) + "-" + value.to_string(false, true);
    Action *drule = new Action(strdup(name.c_str()));

    AndEffect *effect = new AndEffect;
    for( unsigned_atom_set::const_iterator it = variable.grounded_domain_.begin(); it != variable.grounded_domain_.end(); ++it ) {
        assert(!it->negated_);
        if( &*it != &value ) {
            effect->push_back(AtomicEffect(*it).negate());
        } else {
            drule->precondition_ = Literal(*it).copy();
        }
    }
    drule->effect_ = effect;

    // insert decision rules
    dom_actions_.push_back(drule);
    if( options_.is_enabled("lw1:print:drule:var") || options_.is_enabled("lw1:print:drule") )
        cout << Utils::yellow() << *drule << Utils::normal();
}

void PDDL_Base::lw1_index_sensing_models() {
    // consolidate sensing models for each literal
    for( list<pair<const Action*, const Sensing*> >::const_iterator it = lw1_sensing_models_.begin(); it != lw1_sensing_models_.end(); ++it ) {
        const Action &action = *it->first;
        const Sensing &sensing = *it->second;
        for( size_t k = 0; k < sensing.size(); ++k ) {
            if( dynamic_cast<const SensingModelForObservableVariable*>(sensing[k]) != 0 ) {
                const SensingModelForObservableVariable &model = *static_cast<const SensingModelForObservableVariable*>(sensing[k]);
                const ObsVariable *variable = model.variable_;
                const Literal &literal = *model.literal_;
                const Condition *dnf = model.dnf_;
                if( dynamic_cast<const Constant*>(dnf) != 0 ) {
                    // nothing to do
#ifndef NDEBUG
                    const Constant *constant = static_cast<const Constant*>(dnf);
                    assert(constant->value_);
#endif
                } else {
                    assert(dnf->is_dnf());
                    if( dynamic_cast<const Or*>(dnf) != 0 ) {
                        const Or *disjunction = static_cast<const Or*>(dnf);
                        for( size_t j = 0; j < disjunction->size(); ++j ) {
                            const Condition *disjunct = (*disjunction)[j];
                            if( dynamic_cast<const And*>(disjunct) != 0 ) {
                                lw1_sensing_models_index_[&action][variable][literal].push_back(static_cast<const And*>(disjunct->copy_and_simplify()));
                            } else if( dynamic_cast<const Literal*>(disjunct) != 0 ) {
                                And *term = new And;
                                term->push_back(disjunct->copy_and_simplify());
                                lw1_sensing_models_index_[&action][variable][literal].push_back(term);
                            } else {
                                cout << Utils::error() << "expecting dnf; got '" << *dnf << "'" << endl;
                                continue;
                            }
                        }
                    } else if( dynamic_cast<const And*>(dnf) != 0 ) {
                        lw1_sensing_models_index_[&action][variable][literal].push_back(static_cast<const And*>(dnf->copy_and_simplify()));
                    } else if( dynamic_cast<const Literal*>(dnf) != 0 ) {
                        And *term = new And;
                        term->push_back(dnf->copy_and_simplify());
                        lw1_sensing_models_index_[&action][variable][literal].push_back(term);
                    } else {
                        cout << Utils::error() << "expecting dnf; got '" << *dnf << "'" << endl;
                        continue;
                    }
                }
                lw1_xxx_[make_pair(variable, literal)][dnf->to_string()].insert(&action);
            } else {
                assert(dynamic_cast<const SensingModelForStateVariable*>(sensing[k]) != 0 );
                const SensingModelForStateVariable &model = *static_cast<const SensingModelForStateVariable*>(sensing[k]);
                assert(model.variable_ != 0);
                lw1_actions_for_observable_state_variables_[model.variable_].push_back(&action);;
            }
        }
    }
}

void PDDL_Base::lw1_create_deductive_rules_for_sensing() {
    cout << Utils::blue() << "(lw1) creating deductive rules for sensing..." << Utils::normal() << endl;

    // index the sensing models by sensed literals
    lw1_index_sensing_models();

    // create single enablers
    if( options_.is_enabled("lw1:boost:single-sensing-literal-enablers") ) {
        cout << Utils::error() << "lw1:boost:single-sensing-literal-enablers is deprecated" << endl;
        exit(-1);
        lw1_calculate_enablers_for_sensing();
    }

#if 0
    for( map<pair<const ObsVariable*, Atom>, map<string, set<const Action*> > >::const_iterator it = lw1_xxx_.begin(); it != lw1_xxx_.end(); ++it ) {
        cout << "Model: variable=" << it->first.first->to_string()
             << ", value=" << it->first.second
             << endl;
        for( map<string, set<const Action*> >::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
             cout << "    dnf=" << jt->first
                  << ", actions={";
            for( set<const Action*>::const_iterator kt = jt->second.begin(); kt != jt->second.end(); ++kt )
                cout << (*kt)->print_name_ << ",";
            cout << "}" << endl;
        }
    }
#endif


    // The models are now stored in lw1_sensing_models_index_. Indexed by
    //
    //   (action a, variable Y, value y)
    //
    // and returning DNF t_1 v t_2 v ... v t_n. This model implements the
    // sensing model:
    //
    //     W_a(Y=y) = t_1 v t_2 v ... v t_n
    //
    // where the term t_i is of the form L^i_1 & L^i_2 & ... & L^i_{n_i}



    // CHECK: fix this description. It is deprecated!
    //
    // there are three types of deductive rules associated to such a model.
    // The first two types are required for completeness for width 1 problems,
    // while the third type is optional, useful for problems with larger width,
    // and turned on with the option "lw1:boost:drule:sensing:type3"

    // for observable state variables:
    //
    // * [REQUIRED] type4 deductive rules for (action a, variable Y, value y):
    //
    //       precondition = <enabler>
    //       effect = not <enabler> & Y=y
    //
    // for observable non-state variables:
    //
    // * [REQUIRED] type4 deductive rules for (action a, variable Y, value y):
    //
    //   if not lw1:boost:drule:type4 || lw1:boost:drule:type4:add ||
    //      DNF for W_a(Y=y) has more than one term:
    //
    //       precondition = <enabler>
    //       effect = not <enabler>
    //           [for each term t_i = Li1 & Li2 & ... Lin in W_a(Y=y') with y' != y]
    //               [for k = 1 to n]
    //                   &_[j != k] Lij => -Lik
    //
    //   else [i.e. if lw1:boost:drule:type4 && DNF for W_a(Y=y) = L1 & ... & Ln]
    //
    //       precondition = <enabler> & -L1 & -L2 & ... & -Ln
    //       effect = not <enabler> & L1 & L2 & ... & Ln
    //
    //   where <enabler> is either Last-Action=a or sensing enabler atom.
    //
    // * [BOOST] type3 deductive rules for (action a, variable Y, value y) with
    //   model W_a(Y=y) = t1 v t2 v ... v tn:
    //
    //     for i = 1 to n:
    //
    //       precondition = <enabler>, &_{j != i} negated-tj, Y=y
    //       effect = ti
    //
    //     rules for adding negated-ti:
    //
    //       precondition = <enabler>, -Lij
    //       effect = negated-ti
    //
    //  * [BOOST,NOT CURRENT ACTIVE] type5 deductive rules for (action a, variable Y, value y):
    //


    // type 4 deductive rules: enabler & L^i_1 & L^i_2 & ... & L^i_{n_i} => S
    //
    //     precondition = enabler
    //
    //
    //
    //
    //
    // type 1 deductive rules are: Last=a & L^i_1 & L^i_2 & ... & L^i_{n_i} => S
    // for each 1 <= i <= n
    //
    // type 2 deductive rules are: Last=a & -S & { L^i_j : j != k } => -L^i_k
    // for each 1 <= i <= n, 1 <= k <= n_i
    //
    // type 3 deductive rules are: Last=a & S & { -L_k : k != i } => L^i_1 & ... & L^i_{n_i}
    // for each 1 <= i <= n, and L_k in C_k for k != i

    // there are O(n) type-1 drules for each model, O(nm) type-2 rules where m
    // m is the max size of a term, and O(m^n) type-3 drules.

    // create deductive rules for sensing
    if( options_.is_enabled("lw1:strict") ) {
        // deductive rules for sensing for literals of observable variables (must be performed before default sensing drules)
        if( options_.is_enabled("lw1:boost:literals-for-observables") ) {
            for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
                const Variable &variable = *lw1_variables_[k];
                if( !variable.is_state_variable() ) {
                    assert(variable.is_observable_variable());
                    const ObsVariable &obs_variable = *static_cast<const ObsVariable*>(&variable);
                    lw1_create_type5_sensing_drule(obs_variable); // CHECK
                }
            }
        }

        // deductive rules for sensing for observable state variables
        for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
            const Variable &variable = *lw1_variables_[k];
            if( variable.is_state_variable() && variable.is_observable_variable() ) {
                const StateVariable &state_variable = *static_cast<const StateVariable*>(&variable);
                const unsigned_atom_set &domain = state_variable.grounded_domain_;


                if( !options_.is_enabled("lw1:boost:single-sensing-literal-enablers") ) {
                    // generate type4 drules for each value and action
                    const vector<const Action*> &actions = lw1_actions_for_observable_state_variables_.at(&state_variable);
                    for( size_t j = 0; j < actions.size(); ++j ) {
                        const Action *action = actions[j];

                        // generate type4 drules for each value
                        for( unsigned_atom_set::const_iterator it = domain.begin(); it != domain.end(); ++it )
                            lw1_create_type4_sensing_drule(action, state_variable, *it);

                        // if variable is binary, generate rule for negative value
                        if( state_variable.is_binary() ) {
                            Atom negated_value(*domain.begin(), true);
                            assert(negated_value.negated_);
                            lw1_create_type4_sensing_drule(action, state_variable, negated_value);
                        }
                    }
                } else {
                    assert(options_.is_enabled("lw1:boost:single-sensing-literal-enablers"));
                    cout << Utils::error() << "lw1:boost:single-sensing-literal-enablers is deprecated" << endl;
                    exit(-1);
#if 0
                    // generate type4 drules for each value
                    for( unsigned_atom_set::const_iterator it = domain.begin(); it != domain.end(); ++it )
                        lw1_create_type4_sensing_drule(0, state_variable, *it);

                    // if variable is binary, generate rule for negative value
                    if( state_variable.is_binary() ) {
                        Atom negated_value(*domain.begin(), true);
                        assert(negated_value.negated_);
                        lw1_create_type4_sensing_drule(0, state_variable, negated_value);
                    }

                    // store required enablers for each action that senses this literal
                    for( size_t j = 0; j < actions.size(); ++j ) {
                        const Action &action = *actions[j];

                        for( unsigned_atom_set::const_iterator it = domain.begin(); it != domain.end(); ++it ) {
                            const Atom &enabler = lw1_fetch_sensing_enabler(state_variable, *it);
                            lw1_enablers_for_actions_[action.print_name_].insert(enabler.to_string(false, true));
                            cout << Utils::red() << "Store: enabler=" << enabler << ", action=" << action.print_name_ << Utils::normal() << endl;
                        }

                        if( state_variable.is_binary() ) {
                            Atom negated_value(*domain.begin(), true);
                            assert(negated_value.negated_);
                            const Atom &enabler = lw1_fetch_sensing_enabler(state_variable, negated_value);
                            lw1_enablers_for_actions_[action.print_name_].insert(enabler.to_string(false, true));
                            cout << Utils::red() << "Store: enabler=" << enabler << ", action=" << action.print_name_ << Utils::normal() << endl;
                        }
                    }
#endif
                }
            }
        }

        // deductive rules for sensing for observable non-state variables
        if( !options_.is_enabled("lw1:boost:single-sensing-literal-enablers") ) {
            for( map<const Action*, map<const ObsVariable*, map<Atom, list<const And*> > > >::const_iterator it = lw1_sensing_models_index_.begin(); it != lw1_sensing_models_index_.end(); ++it ) {
                const Action &action = *it->first;
                for( map<const ObsVariable*, map<Atom, list<const And*> > >::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                    const ObsVariable &variable = *jt->first;
                    for( map<Atom, list<const And*> >::const_iterator kt = jt->second.begin(); kt != jt->second.end(); ++kt ) {
                        const Atom &value = kt->first;
                        if( !value.negated_ || variable.is_binary() ) { //|| options_.is_enabled("lw1:boost:literals-for-observables") ) {
                            lw1_create_type4_sensing_drule(action, variable, value, jt->second);
                            if( options_.is_enabled("lw1:boost:drule:sensing:type4") )
                                lw1_create_type4_boost_sensing_drule(action, variable, value, jt->second);
                        }
                    }
                }
            }
        } else {
            assert(options_.is_enabled("lw1:boost:single-sensing-literal-enablers"));
            cout << Utils::error() << "lw1:boost:single-sensing-literal-enablers is deprecated" << endl;
            exit(-1);
#if 0
            for( map<pair<const ObsVariable*, Atom>, map<string, set<const Action*> > >::const_iterator it = lw1_xxx_.begin(); it != lw1_xxx_.end(); ++it ) {
                const ObsVariable &variable = *it->first.first;
                const Atom &value = it->first.second;
                if( !value.negated_ || variable.is_binary() || options_.is_enabled("lw1:boost:literals-for-observables") ) {
                    for( map<string, set<const Action*> >::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                        assert(!jt->second.empty());
                        const Action &action = **jt->second.begin();
                        const map<Atom, list<const And*> > &sensing_models_for_var = lw1_sensing_models_index_[&action][&variable];
                        lw1_create_type4_sensing_drule(action, variable, value, sensing_models_for_var);
                        if( options_.is_enabled("lw1:boost:drule:sensing:type4") )
                            lw1_create_type4_boost_sensing_drule(action, variable, value, jt->second);
                    }
                }
            }
#endif
        }

        // type3 deductive rules for sensing for observable non-state variables
        if( options_.is_enabled("lw1:boost:drule:sensing:type3") ) {
            for( map<const Action*, map<const ObsVariable*, map<Atom, list<const And*> > > >::const_iterator it = lw1_sensing_models_index_.begin(); it != lw1_sensing_models_index_.end(); ++it ) {
                const Action &action = *it->first;
                for( map<const ObsVariable*, map<Atom, list<const And*> > >::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                    const ObsVariable &variable = *jt->first;
                    for( map<Atom, list<const And*> >::const_iterator kt = jt->second.begin(); kt != jt->second.end(); ++kt ) {
                        const Atom &value = kt->first;
                        const list<const And*> &dnf = kt->second;
                        size_t num_type3_drules = 0;
                        for( list<const And*>::const_iterator term = dnf.begin(); term != dnf.end(); ++term) {
                            assert(dynamic_cast<const And*>(*term) != 0);
                            lw1_create_type3_sensing_drule(action, variable, value, **term, dnf, num_type3_drules++);
                        }
                    }
                }
            }
        }
    } else {
        for( map<const Action*, map<const ObsVariable*, map<Atom, list<const And*> > > >::const_iterator it = lw1_sensing_models_index_.begin(); it != lw1_sensing_models_index_.end(); ++it ) {
            const Action &action = *it->first;
            for( map<const ObsVariable*, map<Atom, list<const And*> > >::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                const ObsVariable *variable = jt->first;
                for( map<Atom, list<const And*> >::const_iterator kt = jt->second.begin(); kt != jt->second.end(); ++kt ) {
                    const Atom &value = kt->first;
                    const list<const And*> &dnf = kt->second;

                    //size_t num_type1_drules = 0;
                    size_t num_type2_drules = 0;
                    size_t num_type3_drules = 0;
                    for( list<const And*>::const_iterator term = dnf.begin(); term != dnf.end(); ++term) {
                        assert(dynamic_cast<const And*>(*term) != 0);
                        //lw1_create_type1_sensing_drule(value, **term, num_type1_drules++); // disabled: see comment below
                        lw1_create_type2_sensing_drule(value, **term, num_type2_drules++);
                        if( options_.is_enabled("lw1:boost:drule:sensing:type3") )
                            lw1_create_type3_sensing_drule(action, *variable, value, **term, dnf, num_type3_drules++);
                    }
                }
            }
        }
    }
}

// these rules are not necessary and may be wrong: they are of the form term => obs
void PDDL_Base::lw1_create_type1_sensing_drule(const Atom &obs, const And &term, int index) {
    assert(options_.is_enabled("lw1:aaai"));

    // type-1 sensing drules
    string name = string("drule-sensing-type1-") + obs.to_string(false, true) + "-" + Utils::to_string(index);
    Action *drule = new Action(strdup(name.c_str()));
    drule->precondition_ = term.copy_and_simplify();
    drule->effect_ = AtomicEffect(obs).copy();

    // insert action for deductive rule
    dom_actions_.push_back(drule);
    if( options_.is_enabled("lw1:print:drule:sensing") || options_.is_enabled("lw1:print:drule") )
        cout << Utils::yellow() << *drule << Utils::normal();
}

// type2 sensing drules are only used in lw1:aaai option
void PDDL_Base::lw1_create_type2_sensing_drule(const Atom &obs, const And &term, int index) {
    assert(options_.is_enabled("lw1:aaai"));

    for( size_t k = 0; k < term.size(); ++k ) {
        string name = string("drule-sensing-type2-") + obs.to_string(false, true) + "-" + Utils::to_string(index);
        Action *drule = new Action(strdup(name.c_str()));

        // precondition
        And *precondition = new And;
        for( size_t i = 0; i < term.size(); ++i ) {
            assert(dynamic_cast<const Literal*>(term[i]) != 0);
            if( i != k )
                precondition->push_back(static_cast<const Literal*>(term[i])->copy());
        }
        precondition->push_back(Literal(obs).negate());
        drule->precondition_ = precondition;

        // effect
        AndEffect *effect = new AndEffect;
        assert(dynamic_cast<const Literal*>(term[k]) != 0);
        effect->push_back(AtomicEffect(*static_cast<const Literal*>(term[k])).negate());
        drule->effect_= effect;

        // insert action for deductive rule
        dom_actions_.push_back(drule);
        if( options_.is_enabled("lw1:print:drule:sensing") || options_.is_enabled("lw1:print:drule") )
            cout << Utils::yellow() << *drule << Utils::normal();
    }
}

void PDDL_Base::lw1_create_type3_sensing_drule(const Action &action,
                                               const ObsVariable &variable,
                                               const Atom &value,
                                               const And &term,
                                               const list<const And*> &dnf,
                                               int index) {
    assert(options_.is_enabled("lw1:aaai") || options_.is_enabled("lw1:strict"));

    // revise beam: at this stage, the beam only contains non-static atoms.
    // Hence, if the beam for value is non-empty, don't generate type3 sensing drule
    assert(variable.grounded_domain_.find(value) != variable.grounded_domain_.end());
    map<Atom, unsigned_atom_set, Atom::unsigned_less_comparator>::const_iterator it = variable.beam_.find(value);
    assert(it != variable.beam_.end());
    if( !it->second.empty() ) {
        //cout << Utils::warning() << "skipping type3 sensing rules for '" << value << "' because they are not safe" << endl;
        return;
    }

#ifdef DEBUG
    cout << "Type3: var=" << variable << ", value=" << value << ", term=" << term << ", dnf=[";
    for( list<const And*>::const_iterator it = dnf.begin(); it != dnf.end(); ++it )
        cout << **it << ",";
    cout << "]" << endl;
#endif

    string name = string("drule-sensing-type3-") + value.to_string(false, true) + "-" + Utils::to_string(index);
    Action *drule = new Action(strdup(name.c_str()));

    // precondition
    And *precondition = new And;
    if( options_.is_enabled("lw1:boost:enable-post-actions") )
        drule->precondition_ = Literal(*lw1_fetch_enabler_for_sensing(value)).copy();
    else
        drule->precondition_ = Literal(lw1_fetch_last_action_atom(action)).copy();

    for( list<const And*>::const_iterator other_term = dnf.begin(); other_term != dnf.end(); ++other_term ) {
        if( *other_term != &term )
            precondition->push_back(Literal(lw1_fetch_atom_for_negated_term(**other_term)).copy());
    }
    precondition->push_back(Literal(value).copy());
    drule->precondition_ = precondition;

    // effect
    AndEffect *effect = new AndEffect;
    for( size_t k = 0; k < term.size(); ++k ) {
        assert(dynamic_cast<const Literal*>(term[k]) != 0);
        effect->push_back(AtomicEffect(*static_cast<const Literal*>(term[k])).copy());
    }
    drule->effect_ = effect;

    // insert action for deductive rule
    dom_actions_.push_back(drule);
    if( options_.is_enabled("lw1:print:drule:sensing") || options_.is_enabled("lw1:print:drule") )
        cout << Utils::yellow() << *drule << Utils::normal();
}

const PDDL_Base::Atom& PDDL_Base::lw1_fetch_atom_for_negated_term(const And &term) {
    signed_atom_set condition;
    for( size_t k = 0; k < term.size(); ++k ) {
        assert(dynamic_cast<const Literal*>(term[k]) != 0);
        const Literal &literal = *static_cast<const Literal*>(term[k]);
        condition.insert(literal);
    }

    map<signed_atom_set, const Atom*>::const_iterator it = atoms_for_terms_for_type3_sensing_drules_.find(condition);
    if( it != atoms_for_terms_for_type3_sensing_drules_.end() ) {
        return *it->second;
    } else {
        // first create atom
        string name = string("negated-term-") + Utils::to_string(atoms_for_terms_for_type3_sensing_drules_.size());
        Atom *atom = create_atom(name);
        atoms_for_terms_for_type3_sensing_drules_.insert(make_pair(condition, atom));

        // now create deductive rules for this atom: -L => -atom for each literal L in term
        for( size_t k = 0; k < term.size(); ++k ) {
            const Literal &literal = *static_cast<const Literal*>(term[k]);
            string name = string("drule-atom-") + atom->to_string(false, true) + "-" + Utils::to_string(k);
            Action *drule = new Action(strdup(name.c_str()));
            drule->precondition_ = literal.negate();
            drule->effect_ = AtomicEffect(*atom).copy();

            // insert action for deductive rule
            dom_actions_.push_back(drule);
            if( options_.is_enabled("lw1:print:drule:sensing") || options_.is_enabled("lw1:print:drule") )
                cout << Utils::yellow() << *drule << Utils::normal();
        }

        // return atom
        return *atom;
    }
}

// this is a default drule for observable state variables
void PDDL_Base::lw1_create_type4_sensing_drule(const Action *action, const StateVariable &variable, const Atom &value) {
    assert(options_.is_enabled("lw1:strict"));

#ifdef DEBUG
    //cout << "Type4: class=STATE"
    //     << ", variable=" << variable.to_string(true, false)
    //     << ", value=" << value.to_string(false, false)
    //     << endl;
#endif

    assert(!value.negated_ || variable.is_binary());

    string name = string("drule-sensing-type4state-") + variable.to_string(false, true) + "-" + value.to_string(false, true);
    Action *drule = new Action(strdup(name.c_str()));

    // pass the variable name to lw1_problem.cc in the comment for this action
    drule->comment_ = variable.to_string(false, true);

    // precondition and effect
    if( options_.is_enabled("lw1:boost:enable-post-actions") ) {
        drule->precondition_ = Literal(*lw1_fetch_enabler_for_sensing(value)).copy();
    } else {
        assert(action != 0);
        drule->precondition_ = Literal(lw1_fetch_last_action_atom(*action)).copy();
    }
    drule->effect_ = AtomicEffect(value).copy();

    // insert action for deductive rule
    dom_actions_.push_back(drule);
    if( options_.is_enabled("lw1:print:drule:sensing") || options_.is_enabled("lw1:print:drule") )
        cout << Utils::yellow() << *drule << Utils::normal();
}

void PDDL_Base::lw1_create_type4_sensing_drule(const Action &action,
                                               const ObsVariable &variable,
                                               const Atom &value,
                                               const map<Atom, list<const And*> > &sensing_models_for_action_and_var) {
    assert(options_.is_enabled("lw1:strict"));

#ifdef DEBUG
    cout << "Type4: class=OBS"
         << ", action=" << action.print_name_
         << ", observable-variable=" << variable.to_string(true, false)
         << ", value=" << value.to_string(false, false)
         << endl;
#endif

    if( sensing_models_for_action_and_var.size() <= 1 ) {
        cout << Utils::error() << "not enough sensing models for action '" << action.print_name_
             << "' and obs-variable '" << variable.to_string(true, false) << "'" << endl;
        return;
    }

    assert(variable.beam_.find(value) != variable.beam_.end());
    assert(!value.negated_ || variable.is_binary()); // || options_.is_enabled("lw1:boost:literals-for-observables")); // CHECK

    // find out whether something needs to be done
    if( options_.is_enabled("lw1:boost:drule:sensing:type4") ) {
        const And *term = 0;
        for( map<Atom, list<const And*> >::const_iterator it = sensing_models_for_action_and_var.begin(); it != sensing_models_for_action_and_var.end(); ++it ) {
            const Atom &other_value = it->first;
            const list<const And*> &dnf = it->second;
            if( (other_value == value) && (dnf.size() == 1) ) {
                term = *dnf.begin();
                break;
            }
        }

        // if boosting type4 drules and not adding redundant rules, return (do nothing)
        if( (term != 0) && !options_.is_enabled("lw1:boost:drule:sensing:type4:add") )
            return;
    }

    string name = string("drule-sensing-type4obs-") + action.print_name_ + "-" + variable.to_string(false, true) + "-" + value.to_string(false, true);
    Action *drule = new Action(strdup(name.c_str()));

    // pass the variable name to lw1_problem.cc in the comment for this action
    drule->comment_ = variable.to_string(false, true) + " " + value.to_string(false, true);

    // exactly 1 precondition, the sensing enabler atom
    if( options_.is_enabled("lw1:boost:enable-post-actions") )
        drule->precondition_ = Literal(*lw1_fetch_enabler_for_sensing(value)).copy();
    else
        drule->precondition_ = Literal(lw1_fetch_last_action_atom(action)).copy();

    // effects
    AndEffect *and_effect = new AndEffect;
    for( map<Atom, list<const And*> >::const_iterator it = sensing_models_for_action_and_var.begin(); it != sensing_models_for_action_and_var.end(); ++it ) {
        const Atom &other_value = it->first;
        const list<const And*> &dnf = it->second;
        if( other_value != value ) {
            for( list<const And*>::const_iterator jt = dnf.begin(); jt != dnf.end(); ++jt ) {
                const And &term = **jt;
                assert(!term.empty());
                if( term.size() == 1 ) {
                    // this unconditional effect becomes conditional when lw1 problem is constructed
                    assert(dynamic_cast<const Literal*>(term[0]) != 0);
                    const Literal &literal = *static_cast<const Literal*>(term[0]);
                    and_effect->push_back(AtomicEffect(literal).negate());
                } else {
                    for( size_t k = 0; k < term.size(); ++k ) {
                        assert(dynamic_cast<const Literal*>(term[k]) != 0);
                        const Literal &literal = *static_cast<const Literal*>(term[k]);
                        AtomicEffect *effect = AtomicEffect(literal).negate();
                        And *condition = new And;
                        for( size_t j = 0; j < term.size(); ++j ) {
                            if( j != k ) {
                                assert(dynamic_cast<const Literal*>(term[j]) != 0);
                                condition->push_back(static_cast<const Literal*>(term[j])->copy());
                            }
                        }
                        // condition needs to be augmented with -Khead when lw1 problem is constructed
                        and_effect->push_back(new ConditionalEffect(condition, effect));
                    }
                }
            }
        }
    }
    assert(!and_effect->empty());
    drule->effect_ = and_effect;

    // insert action for deductive rule
    dom_actions_.push_back(drule);
    if( options_.is_enabled("lw1:print:drule:sensing") || options_.is_enabled("lw1:print:drule") )
        cout << Utils::yellow() << *drule << Utils::normal();
}

void PDDL_Base::lw1_create_type4_boost_sensing_drule(const Action &action,
                                                     const ObsVariable &variable,
                                                     const Atom &value,
                                                     const map<Atom, list<const And*> > &sensing_models_for_action_and_var) {
    assert(options_.is_enabled("lw1:strict"));
    assert(options_.is_enabled("lw1:boost:drule:sensing:type4"));

#ifdef DEBUG
    cout << "Type4: class=OBS-BOOST"
         << ", action=" << action.print_name_
         << ", observable-variable=" << variable.to_string(true, false)
         << ", value=" << value.to_string(false, false)
         << endl;
#endif

    if( sensing_models_for_action_and_var.size() <= 1 ) {
        cout << Utils::error() << "not enough sensing models for action '" << action.print_name_
             << "' and obs-variable '" << variable.to_string(true, false) << "'" << endl;
        return;
    }

    assert(variable.beam_.find(value) != variable.beam_.end());
    assert(!value.negated_ || variable.is_binary()); // || options_.is_enabled("lw1:boost:literals-for-observables")); // CHECK

    // find out whether something needs to be done
    const And *term = 0;
    for( map<Atom, list<const And*> >::const_iterator it = sensing_models_for_action_and_var.begin(); it != sensing_models_for_action_and_var.end(); ++it ) {
        const Atom &other_value = it->first;
        const list<const And*> &dnf = it->second;
        if( (other_value == value) && (dnf.size() == 1) ) {
            term = *dnf.begin();
            break;
        }
    }
    if( term == 0 ) return;

    string name = string("drule-sensing-type4obs-boost-") + action.print_name_ + "-" + variable.to_string(false, true) + "-" + value.to_string(false, true);
    Action *drule = new Action(strdup(name.c_str()));

    // pass the variable name to lw1_problem.cc in the comment for this action
    drule->comment_ = variable.to_string(false, true) + " " + value.to_string(false, true);

    // preconditions are the sensing enabler atom and all the complemented
    // literals in the term
    And *precondition = new And;
    if( options_.is_enabled("lw1:boost:enable-post-actions") )
        precondition->push_back(Literal(*lw1_fetch_enabler_for_sensing(value)).copy());
    else
        precondition->push_back(Literal(lw1_fetch_last_action_atom(action)).copy());
    for( size_t k = 0; k < term->size(); ++k ) {
        assert(dynamic_cast<const Literal*>((*term)[k]) != 0);
        const Literal &literal = *static_cast<const Literal*>((*term)[k]);
        precondition->push_back(literal.negate());
    }
    drule->precondition_ = precondition;

    // effects
    assert(!term->empty());
    AndEffect *effect = new AndEffect;
    for( size_t k = 0; k < term->size(); ++k ) {
        assert(dynamic_cast<const Literal*>((*term)[k]) != 0);
        const Literal &literal = *static_cast<const Literal*>((*term)[k]);
        effect->push_back(AtomicEffect(literal).copy());
    }
    drule->effect_ = effect;

    // insert action for deductive rule
    dom_actions_.push_back(drule);
    if( options_.is_enabled("lw1:print:drule:sensing") || options_.is_enabled("lw1:print:drule") )
        cout << Utils::yellow() << *drule << Utils::normal();
}

void PDDL_Base::lw1_create_type5_sensing_drule(const ObsVariable &variable) {
    assert(options_.is_enabled("lw1:strict"));
    assert(options_.is_enabled("lw1:boost:literals-for-observables"));

#ifdef DEBUG
    cout << "Type5: observable-variable=" << variable.to_string(true, false) << ", domain-sz=" << variable.grounded_domain_.size() << endl;
    assert(!variable.grounded_domain_.empty());
#endif

    // collect all values of variable as strings into vector. If variable is binary, extend domain with negative literal
    vector<Atom> grounded_domain;
    for( unsigned_atom_set::const_iterator it = variable.grounded_domain_.begin(); it != variable.grounded_domain_.end(); ++it )
        grounded_domain.push_back(*it);
    if( grounded_domain.size() == 1 )
        grounded_domain.push_back(Atom(grounded_domain[0], true));

    // find those values for which a translation can be performed
    for( size_t k = 0; k < grounded_domain.size(); ++k ) {
        const Atom &value = grounded_domain[k];

#ifdef DEBUG
        cout << "       value=" << value << flush;
#endif

        assert(variable.beam_.find(value) != variable.beam_.end());
        //if( !options_.is_enabled("lw1:boost:literals-for-observables:dynamic") && !variable.beam_.find(value)->second.empty() ) { // CHECK
        if( !variable.beam_.find(value)->second.empty() ) {
#ifdef DEBUG
            cout << " ... skip because beam is non-empty" << endl;
#endif
            continue;
        }

        // the beam for atom is empty meaning that the formula is given by static variables: good to go!
        set<string> models_for_value;
        const list<const And*> *dnf = 0;
        for( map<const Action*, map<const ObsVariable*, map<Atom, list<const And*> > > >::const_iterator it = lw1_sensing_models_index_.begin(); it != lw1_sensing_models_index_.end(); ++it ) {
            for( map<const ObsVariable*, map<Atom, list<const And*> > >::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                if( jt->first != &variable ) continue;
                for( map<Atom, list<const And*> >::const_iterator kt = jt->second.begin(); kt != jt->second.end(); ++kt ) {
                    if( kt->first == value ) {
                        dnf = &kt->second;
                        string dnf_as_string("(or");
                        for( list<const And*>::const_iterator term = kt->second.begin(); term != kt->second.end(); ++term )
                            dnf_as_string += " " + (*term)->to_string();
                        dnf_as_string += ")";
                        models_for_value.insert(dnf_as_string);
                    }
                }
            }
        }
        if( dnf == 0 ) {
#ifdef DEBUG
            cout << " ... skip because there is no dnf" << endl;
#endif
            continue;
        }

        // if there is just one model, all actions that sense the atom have the same sensing model and we can generate a deductive rule for it
        if( models_for_value.size() == 1 ) {
            lw1_accepted_literals_for_observables_[variable.to_string(false, true)].insert(value.to_string(false, true));
#if 0 // CHECK: type5
            size_t n = 0;
            for( list<const And*>::const_iterator term = dnf->begin(); term != dnf->end(); ++term, ++n ) {
                string name = string("drule-sensing-type5-") + variable.to_string(false, true) + "-" + value.to_string(false, true) + "-term-" + Utils::to_string(1 + n);
                Action *drule = new Action(strdup(name.c_str()));

                // precondition and effect
                drule->precondition_ = (*term)->copy_and_simplify();
                drule->effect_ = AtomicEffect(value).copy();

                // insert action for deductive rule
                dom_actions_.push_back(drule);
                if( options_.is_enabled("lw1:print:drule:sensing") || options_.is_enabled("lw1:print:drule") )
                    cout << Utils::yellow() << *drule << Utils::normal();
            }
#endif
#ifdef DEBUG
            cout << ", model=" << *models_for_value.begin() << endl;
#endif
        } else {
#ifdef DEBUG
            cout << " ... skip because there is more than one model:" << endl;
            for( set<string>::const_iterator it = models_for_value.begin(); it != models_for_value.end(); ++it )
                cout << "           " << *it << endl;
#endif
        }
    }
}

const PDDL_Base::Atom& PDDL_Base::lw1_fetch_sensing_enabler(const string &action, const string &variable, const string &value) {
    string name = string("enable-sensing-for-") + action + "-" + variable + "-" + value;
    const map<string, const Atom*>::const_iterator it = lw1_sensing_enabler_atoms_.find(name);
    if( it == lw1_sensing_enabler_atoms_.end() ) {
        Atom *atom = create_atom(name);
        lw1_sensing_enabler_atoms_.insert(make_pair(name, atom));
        return *atom;
    } else {
        return *it->second;
    }
}

const PDDL_Base::Atom& PDDL_Base::lw1_fetch_sensing_enabler(const Action &action, const ObsVariable &variable, const Atom &value) {
    return lw1_fetch_sensing_enabler(action.print_name_, variable.to_string(false, true), value.to_string(false, true));
}

const PDDL_Base::Atom& PDDL_Base::lw1_fetch_sensing_enabler(const StateVariable &variable, const Atom &value) {
    return lw1_fetch_sensing_enabler("PROXY", variable.to_string(false, true), value.to_string(false, true));
}

const PDDL_Base::Atom& PDDL_Base::lw1_fetch_last_action_atom(const Action &action) {
    map<string, const Atom*>::const_iterator it = lw1_last_action_atoms_.find(action.print_name_);
    if( it != lw1_last_action_atoms_.end() ) {
        return *it->second;
    } else {
        // create new atom
        string name = string("last-action-was-") + action.print_name_;
        Atom *atom = create_atom(name);
        lw1_last_action_atoms_.insert(make_pair(action.print_name_, atom));
        //cout << "Atom " << *atom << " created!" << endl;
        return *atom;
    }
}

// lw1:boost:single-sensing-literal-enablers
void PDDL_Base::lw1_calculate_enablers_for_sensing() { // CHECK: this is not called now: lw1:boost:single-sensing-literal-enablers is NOT SUPPORTED (deprecated?)
    for( map<pair<const ObsVariable*, Atom>, map<string, set<const Action*> > >::const_iterator it = lw1_xxx_.begin(); it != lw1_xxx_.end(); ++it ) {
        const ObsVariable &variable = *it->first.first;
        const Atom &value = it->first.second;

        for( map<string, set<const Action*> >::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
            assert(!jt->second.empty());
            const Action &representative = **jt->second.begin();
            const Atom &enabler = lw1_fetch_sensing_enabler(representative, variable, value);

            //cout << "Enabler for action=" << representative.print_name_
            //     << ", var=" << variable.to_string(false, true)
            //     << ", value=" << value.to_string(false, true)
            //     << endl
            //     << "    " << enabler
            //     << endl;

            assert(lw1_sensing_enablers_.find(make_pair(&representative, make_pair(&variable, value))) == lw1_sensing_enablers_.end());
            lw1_sensing_enablers_[make_pair(&representative, make_pair(&variable, value))] = &enabler;
            lw1_enablers_for_actions_[representative.print_name_].insert(enabler.to_string(false, true));
            cout << Utils::red() << "Store: enabler=" << enabler << ", action=" << representative.print_name_ << Utils::normal() << endl;

            for( set<const Action*>::const_iterator kt = jt->second.begin(); kt != jt->second.end(); ++kt ) {
                if( *kt != &representative ) {
                    assert(lw1_sensing_enablers_.find(make_pair(*kt, make_pair(&variable, value))) == lw1_sensing_enablers_.end());
                    lw1_sensing_enablers_[make_pair(*kt, make_pair(&variable, value))] = &enabler;
                    lw1_enablers_for_actions_[(*kt)->print_name_].insert(enabler.to_string(false, true));
                    //cout << "    also enabler for action=" << (*kt)->print_name_
                    //     << ", var=" << variable.to_string(false, true)
                    //     << ", value=" << value.to_string(false, true)
                    //     << endl;
                    cout << Utils::red() << "       enabler=" << enabler << ", action=" << (*kt)->print_name_ << Utils::normal() << endl;
                }
            }
        }
    }
}

void PDDL_Base::lw1_patch_actions_with_enablers_for_sensing() {
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        Action &action = *dom_actions_[k];

        // make sure effect is AndEffect
        if( dynamic_cast<const AndEffect*>(action.effect_) == 0 ) {
            AndEffect *new_effect = new AndEffect;
            if( action.effect_ != 0 ) new_effect->push_back(action.effect_);
            action.effect_ = new_effect;
        }
        AndEffect &effect = *const_cast<AndEffect*>(static_cast<const AndEffect*>(action.effect_));

        if( !options_.is_enabled("lw1:boost:single-sensing-literal-enablers") ) {
            // patch effect according to generated last-action-atoms
            map<string, const Atom*>::const_iterator it = lw1_last_action_atoms_.find(action.print_name_);
            if( it != lw1_last_action_atoms_.end() ) {
                effect.push_back(AtomicEffect(*it->second).copy());
                for( map<string, const Atom*>::const_iterator jt = lw1_last_action_atoms_.begin(); jt != lw1_last_action_atoms_.end(); ++jt ) {
                    if( jt != it ) effect.push_back(AtomicEffect(*jt->second).negate());
                }
            } else if( !action.is_special_action() ) {
                for( map<string, const Atom*>::const_iterator jt = lw1_last_action_atoms_.begin(); jt != lw1_last_action_atoms_.end(); ++jt ) {
                    effect.push_back(AtomicEffect(*jt->second).negate());
                }
            }
        } else {
            cout << Utils::error() << "lw1:boost:single-sensing-literal-enablers is deprecated" << endl;
            exit(-1);
            map<string, set<string> >::const_iterator it = lw1_enablers_for_actions_.find(action.print_name_);
            if( it != lw1_enablers_for_actions_.end() ) {
                const set<string> &enablers_for_action = it->second;
                for( map<std::string, const Atom*>::const_iterator jt = lw1_sensing_enabler_atoms_.begin(); jt != lw1_sensing_enabler_atoms_.end(); ++jt ) {
                    if( enablers_for_action.find(jt->first) != enablers_for_action.end() ) {
                        effect.push_back(AtomicEffect(*jt->second).copy());
                    } else {
                        effect.push_back(AtomicEffect(*jt->second).negate());
                    }
                }
            } else if( !action.is_special_action() ) {
                for( map<std::string, const Atom*>::const_iterator jt = lw1_sensing_enabler_atoms_.begin(); jt != lw1_sensing_enabler_atoms_.end(); ++jt ) {
                    effect.push_back(AtomicEffect(*jt->second).negate());
                }
            }
        }
    }
}

void PDDL_Base::lw1_calculate_post_condition(const Condition *precondition, const Effect *effect, signed_atom_set &post_condition) const {
    unsigned_atom_set condition;

    // calculate literals in precondition
    if( dynamic_cast<const And*>(precondition) != 0 ) {
        const And &and_precondition = *static_cast<const And*>(precondition);
        for( size_t k = 0; k < and_precondition.size(); ++k ) {
            assert(dynamic_cast<const Literal*>(and_precondition[k]) != 0);
            condition.insert(*static_cast<const Literal*>(and_precondition[k]));
        }
    } else if( dynamic_cast<const Literal*>(precondition) != 0 ) {
        condition.insert(*static_cast<const Literal*>(precondition));
    }

    // calculate post condition (this works because sets are unsigned)
    if( dynamic_cast<const AndEffect*>(effect) != 0 ) {
        const AndEffect &and_effect = *static_cast<const AndEffect*>(effect);
        for( size_t k = 0; k < and_effect.size(); ++k ) {
            if( dynamic_cast<const AtomicEffect*>(and_effect[k]) != 0 ) {
                const AtomicEffect &effect = *static_cast<const AtomicEffect*>(and_effect[k]);
                condition.erase(effect);
                condition.insert(effect);
            }
        }
    } else if( dynamic_cast<const AtomicEffect*>(effect) != 0 ) {
        condition.erase(*static_cast<const AtomicEffect*>(effect));
        condition.insert(*static_cast<const AtomicEffect*>(effect));
    }

    post_condition.clear();
    post_condition.insert(condition.begin(), condition.end());
}

void PDDL_Base::lw1_simplify_post_condition(signed_atom_set &post_condition) const {
    vector<const Atom*> literals;
    literals.reserve(post_condition.size());
    for( signed_atom_set::const_iterator it = post_condition.begin(); it != post_condition.end(); ++it )
        literals.push_back(new Atom(*it));

    // simplify
    size_t k = 0;
    while( k < literals.size() ) {
        const Atom *lit = literals[k];
        literals[k] = literals.back();
        literals.pop_back();
        if( !lw1_is_literal_implied(*lit, literals) ) {
            literals.push_back(literals[k]);
            literals[k] = lit;
            ++k;
        }
    }

    // create result and return
    post_condition.clear();
    for( size_t k = 0; k < literals.size(); ++k ) {
        post_condition.insert(*literals[k]);
        delete literals[k];
    }
}

bool PDDL_Base::lw1_is_literal_implied(const Atom &literal, const Condition &condition, bool complement_literal) const {
    vector<const Atom*> condition_vector;
    assert((dynamic_cast<const Literal*>(&condition) != 0) || (dynamic_cast<const And*>(&condition) != 0));
    if( dynamic_cast<const Literal*>(&condition) != 0 ) {
        condition_vector.push_back(static_cast<const Literal*>(&condition));
    } else {
        const And &and_condition = *static_cast<const And*>(&condition);
        condition_vector.reserve(and_condition.size());
        for( size_t k = 0; k < and_condition.size(); ++k ) {
            assert(dynamic_cast<const Literal*>(and_condition[k]) != 0);
            condition_vector.push_back(static_cast<const Literal*>(and_condition[k]));
        }
    }
    return lw1_is_literal_implied(literal, condition_vector, complement_literal);
}

bool PDDL_Base::lw1_is_literal_implied(const Atom &literal, const signed_atom_set &condition, bool complement_literal) const {
    vector<const Atom*> condition_vector;
    condition_vector.reserve(condition.size());
    for( signed_atom_set::const_iterator it = condition.begin(); it != condition.end(); ++it )
        condition_vector.push_back(&*it);
    return lw1_is_literal_implied(literal, condition_vector, complement_literal);
}

bool PDDL_Base::lw1_is_literal_implied(const Atom &literal, const vector<const Atom*> &condition, bool complement_literal) const {
    //cout << "checking whether " << literal << " with comp=" << complement_literal << " is implied by:";
    //for( size_t i = 0; i < condition.size(); ++i ) cout << " " << *condition[i]; cout << " ==> ";

    // first check whether literal belongs to condition
    Atom negated_literal(literal, true);
    for( size_t k = 0; k < condition.size(); ++k ) {
        if( (!complement_literal && (literal == *condition[k])) || (complement_literal && (negated_literal == *condition[k])) ) {
            //cout << "(case 0) TRUE" << endl;
            return true;
        }
    }

    // another possibility is that the condition contains a positive literal that is mutex with the (complemented) literal
    if( (literal.negated_ && !complement_literal) || (!literal.negated_ && complement_literal) ) {
        for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
            const Variable &var = *lw1_variables_[k];
            unsigned_atom_set::const_iterator it = var.grounded_domain_.find(literal);
            if( it != var.grounded_domain_.end() ) {
                for( size_t i = 0; i < condition.size(); ++i ) {
                    unsigned_atom_set::const_iterator jt = var.grounded_domain_.find(*condition[i]);
                    if( !condition[i]->negated_ && (it != jt) && (jt != var.grounded_domain_.end()) ) {
                        //cout << "(case 1) TRUE" << endl;
                        return true;
                    }
                }
            }
        }
    }

    // if both tests fail, return false
    //cout << "FALSE" << endl;
    return false;
}

// To pass test, condition should be false at init
bool PDDL_Base::lw1_test_on_initial_state_for_static_observable(const signed_atom_set &condition) const {
    //cout << Utils::yellow() << "checking s0-test: condition='" << condition << "'";
    for( signed_atom_set::const_iterator it = condition.begin(); it != condition.end(); ++it ) {
        signed_atom_set::const_iterator jt = set_of_initial_literals_.find(*it);
        if( it->negated_ == !jt->negated_ ) {
            //cout << ", result=true" << Utils::normal() << endl;
            return true;
        }
    }
    //cout << ", result=false" << Utils::normal() << endl;
    return false;
}

// To pass test, every action that makes condition true should sense atom
// and every action that senses atom should make condition true. Makes
// condition true means that the condition is false before the action and
// true after the action. A sufficient test for this is that the condition and
// action's precondition are mutually inconsistent, and that every literal in
// in the condition is either in the precondition and not removed, or in the
// action's effect.
bool PDDL_Base::lw1_test_on_actions_for_static_observable(const signed_atom_set &condition, const Atom &atom) const {
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        const Action &action = *dom_actions_[k];

        unsigned_atom_set sensed_atoms;
        if( action.sensing_ != 0 ) action.sensing_->extract_atoms(sensed_atoms, true);
        bool action_senses_atom = sensed_atoms.find(atom) != sensed_atoms.end();

        bool action_makes_condition_true = false;
        //signed_atom_set precondition, effect;
        if( action.precondition_ != 0 ) {
            bool condition_is_inconsistent_with_precondition = false;
            for( signed_atom_set::const_iterator it = condition.begin(); it != condition.end(); ++it ) {
                if( lw1_is_literal_implied(*it, *action.precondition_, true) ) {
                    //cout << Utils::yellow() << "comp of " << *it << " is implied by precondition=" << *action.precondition_ << Utils::normal() << endl;
                    condition_is_inconsistent_with_precondition = true;
                    break;
                }
            }

            // if condition is inconsistent with precondition, then need to check
            // that every literal in the condition is either implied by precondition
            // and not removed, or is added by the action's effect
            if( condition_is_inconsistent_with_precondition ) {
                action_makes_condition_true = true;
                for( signed_atom_set::const_iterator it = condition.begin(); it != condition.end(); ++it ) {
                    const Atom &literal = *it;
                    Atom negated_literal(*it, true);
                    bool implied_by_precondition = lw1_is_literal_implied(literal, *action.precondition_);
                    bool removed_by_effect = false;
                    bool added_by_effect = false;
                    if( action.effect_ != 0 ) {
                        if( dynamic_cast<const AndEffect*>(action.effect_) != 0 ) {
                            const AndEffect &and_effect = *static_cast<const AndEffect*>(action.effect_);
                            for( size_t i = 0; i < and_effect.size(); ++i ) {
                                if( dynamic_cast<const AtomicEffect*>(and_effect[i]) != 0 ) {
                                    const Atom &effect = *static_cast<const AtomicEffect*>(and_effect[i]);
                                    if( effect == literal ) added_by_effect = true;
                                    if( effect == negated_literal ) removed_by_effect = true;
                                    if( added_by_effect || removed_by_effect ) break;
                                }
                            }
                        } else if( dynamic_cast<const AtomicEffect*>(action.effect_) != 0 ) {
                            const Atom &effect = *static_cast<const AtomicEffect*>(action.effect_);
                            if( effect == literal ) added_by_effect = true;
                            if( effect == negated_literal ) removed_by_effect = true;
                        }
                    }
                    if( (!implied_by_precondition || removed_by_effect) && !added_by_effect ) {
                        //cout << Utils::magenta() << "literal=" << *it << ", implied=" << implied_by_precondition << ", removed=" << removed_by_effect << ", added=" << added_by_effect << endl << Utils::normal();
                        action_makes_condition_true = false;
                        break;
                    }
                }
            }
        }

        if( action_makes_condition_true && !action_senses_atom ) {
            return false;
        }
        if( !action_makes_condition_true && action_senses_atom ) {
            return false;
        }
    }
    return true;
}

void PDDL_Base::lw1_remove_subsumed_conditions(set<signed_atom_set> &conditions) const {
    set<signed_atom_set> non_dominated_conditions;
    for( set<signed_atom_set>::const_iterator it = conditions.begin(); it != conditions.end(); ++it ) {
        bool subsumed_by = false;
        for( set<signed_atom_set>::const_iterator jt = conditions.begin(); jt != conditions.end(); ++jt ) {
            if( it != jt ) {
                // test if *it is subsumed by *jt (i.e., if *it contains *jt)
                bool subsumed = true;
                for( signed_atom_set::const_iterator kt = jt->begin(); kt != jt->end(); ++kt ) {
                    if( it->find(*kt) == it->end() ) {
                        subsumed = false;
                        break;
                    }
                }
                if( subsumed ) {
                    subsumed_by = true;
                    break;
                }
            }
        }
        if( !subsumed_by ) non_dominated_conditions.insert(*it);
    }
    conditions = non_dominated_conditions;
}

void PDDL_Base::lw1_compile_static_observable(const Atom &atom) { // CHECK: compile_static_observables is deprecated in this version
    cout << Utils::blue() << "(lw1) compiling static observable '" << atom << "'" << Utils::normal() << endl;
    cout << Utils::error() << "lw1:boost:compile-static-observables is deprecated" << endl;
    exit(-1);

    // iterate over all sensing models extracting those relevant to atom
    Atom negated_atom(atom, true);
    vector<const SensingModelForObservableVariable*> extracted_sensing_models;
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        const Action &action = *dom_actions_[k];
        if( action.sensing_ != 0 ) {
            action.sensing_->extract_sensing_model_for_atom(atom, extracted_sensing_models);
            action.sensing_->extract_sensing_model_for_atom(negated_atom, extracted_sensing_models);
        }
    }

    // remove duplicate sensing models (this is incomplete and inefficient as comparison is string based)
    set<string> extracted_sensing_models_str;
    for( int k = 0; k < (int)extracted_sensing_models.size(); ++k ) {
        string str = extracted_sensing_models[k]->to_string();
        if( extracted_sensing_models_str.find(str) == extracted_sensing_models_str.end() ) {
            extracted_sensing_models_str.insert(str);
        } else {
            delete extracted_sensing_models[k];
            extracted_sensing_models[k] = extracted_sensing_models.back();
            extracted_sensing_models.pop_back();
            --k;
        }
    }

    // print sensing models
    if( options_.is_enabled("lw1:print:compiled-static-sensing") ) {
        cout << Utils::magenta() << "sensing models for '" << atom << "':" << Utils::normal() << endl;
        for( size_t k = 0; k < extracted_sensing_models.size(); ++k )
            cout << "    " << *extracted_sensing_models[k] << endl;
    }

    // generate axioms for filtered sensing models. Axioms are only used in lw1 to
    // complete the initial hidden state with the static observables. Only generate
    // axioms for positive observables as negative value is assumed by default.
    for( size_t k = 0; k < extracted_sensing_models.size(); ++k ) {
        const SensingModelForObservableVariable &sensing_model = *extracted_sensing_models[k];
        assert(sensing_model.is_grounded());
        if( !sensing_model.literal_->negated_ ) {
            const Literal &literal = *sensing_model.literal_;
            const Condition *dnf = sensing_model.dnf_;
            if( dynamic_cast<const Or*>(dnf) != 0 ) {
                const Or *disjunction = static_cast<const Or*>(dnf);
                for( size_t j = 0; j < disjunction->size(); ++j ) {
                    const Condition *disjunct = (*disjunction)[j];
                    lw1_add_axiom_for_static_observable(literal, *disjunct);
                }
            } else if( dynamic_cast<const And*>(dnf) != 0 ) {
                lw1_add_axiom_for_static_observable(literal, *dnf);
            } else if( dynamic_cast<const Literal*>(dnf) != 0 ) {
                lw1_add_axiom_for_static_observable(literal, *dnf);
            } else {
                cout << Utils::error() << "expecting dnf; got '" << *dnf << "'" << endl;
            }
        }
        delete extracted_sensing_models[k];
    }
    extracted_sensing_models.clear();

    // insert atom into set of static observable atoms
    static_observable_atoms_.insert(atom);

    //NEW_SENSING_SYNTAX: need fix // CHECK
#if 0
    // calculate prime implicant for conditions on observable atom
    cout << Utils::red() << "calculating prime implicant for conditions on observable atom: " << atom << Utils::normal() << endl;
    set<signed_atom_set> candidate_post_conditions;
    unsigned_atom_set atoms_to_remove;
    atoms_to_remove.insert(atom);

    vector<bool> affected_action(dom_actions_.size(), false);
    vector<const Sensing*> reduced_sensing_for_actions(dom_actions_.size(), 0);
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        Action &action = *dom_actions_[k];
        if( action.sensing_ != 0 ) {
            const Sensing *reduced_sensing = action.sensing_->reduce(atoms_to_remove);
            if( (reduced_sensing == 0) || (reduced_sensing->to_string() != action.sensing_->to_string()) ) {
                cout << "AFFECTED: sensing=" << *action.sensing_ << flush;
                if( reduced_sensing != 0 ) cout << ", reduced=" << *reduced_sensing << endl;
                affected_action[k] = true;
                reduced_sensing_for_actions[k] = reduced_sensing;
                signed_atom_set post_condition;
                lw1_calculate_post_condition(action.precondition_, action.effect_, post_condition);
                lw1_simplify_post_condition(post_condition);
                candidate_post_conditions.insert(post_condition);
            } else {
                delete reduced_sensing;
            }
        }
    }

#if 0
    // apply test and filter candidate conditions
    set<signed_atom_set> post_conditions;
    for( set<signed_atom_set>::const_iterator it = candidate_post_conditions.begin(); it != candidate_post_conditions.end(); ++it ) {
        //cout << "c-POST={"; for(signed_atom_set::const_iterator jt=it->begin();jt != it->end();++jt) cout << *jt << ","; cout << "}" << endl;
        if( lw1_test_on_initial_state_for_static_observable(*it) &&
            lw1_test_on_actions_for_static_observable(*it, atom) )
            post_conditions.insert(*it);
    }
    lw1_remove_subsumed_conditions(post_conditions);
    //cout << Utils::red() << "#post-conditions=" << post_conditions.size() << Utils::normal() << endl;

    // modify sensing models of actions: if pasive sensor for atom cannot be created,
    // reduce sensing model and insert atom, otherwise remove atom and reduce model.
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        if( affected_action[k] ) {
            Action &action = *dom_actions_[k];
            const Sensing *reduced_sensing = reduced_sensing_for_actions[k];
            if( post_conditions.empty() ) {
                if( reduced_sensing == 0 ) {
                    reduced_sensing = AtomicEffect(atom).copy();
                } else {
                    if( dynamic_cast<AndEffect*>(reduced_sensing) == 0 ) {
                        AndEffect *and_effect = new AndEffect;
                        and_effect->push_back(reduced_sensing);
                        reduced_sensing = and_effect;
                    }
                    static_cast<AndEffect*>(reduced_sensing)->push_back(AtomicEffect(atom).copy());
                }
            }
            assert(action.sensing_ != 0);
            delete action.sensing_;
            action.sensing_ = reduced_model;
            reduced_sensing_for_actions[k] = 0;
        }
    }

    // create sensor
    if( !post_conditions.empty() ) {
        // for each condition, create a pasive sensor
        size_t index = 0;
        for( set<signed_atom_set>::const_iterator it = post_conditions.begin(); it != post_conditions.end(); ++it ) {
            //cout << "POST={"; for(signed_atom_set::const_iterator jt=it->begin();jt != it->end();++jt) cout << *jt << ","; cout << "}" << endl;
            //if( it->size() > 2 ) continue; // NOTE: THIS HACK SHOULD DISSAPEAR WHEN FIXING test_on_...
            lw1_create_sensors_for_atom(atom, *it, index++);
        }
    }
#endif
#endif
}

void PDDL_Base::lw1_add_axiom_for_static_observable(const Literal &literal, const Condition &condition) {
    string axiom_name("[axiom for static observable '");
    Axiom *axiom = new Axiom(strdup((axiom_name + literal.to_string() + "']").c_str()));
    axiom->head_ = new AtomicEffect(literal);
    axiom->body_ = condition.copy_and_simplify();
    dom_axioms_.push_back(axiom);

    if( options_.is_enabled("lw1:print:axioms") ) {
        cout << Utils::yellow() << *axiom << endl;
    }
}

void PDDL_Base::lw1_complete_effect_for_actions() {
    cout << Utils::blue() << "(lw1) completing effects of actions" << Utils::normal() << endl;
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        Action &action = *dom_actions_[k];
        string action_name(action.print_name_);
        assert(action_name.compare(0, 6, "drule-") != 0); // CHECK
        //if( action_name.compare(0, 10, "drule-var-") == 0 ) continue; // CHECK
        //if( action_name.compare(0, 25, "drule-sensing-type4state-") == 0 ) continue; // CHECK
        action.effect_ = lw1_complete_effect(const_cast<Effect*>(action.effect_));
    }
}

const PDDL_Base::AndEffect* PDDL_Base::lw1_complete_effect(Effect *effect) const {
    if( effect == 0 ) return 0;

    AndEffect *canonical = const_cast<AndEffect*>(lw1_canonize_effect(effect));

    // for each positive effect literal, if it corresponds to a variable,
    // then set the literals for other values to false
    for( size_t k = 0; k < lw1_variables_.size(); ++k ) {
        const Variable &var = *lw1_variables_[k];
        if( var.is_state_variable() ) lw1_complete_effect_with_variable(canonical, var);
    }
    return canonical;
}

const PDDL_Base::AndEffect* PDDL_Base::lw1_canonize_effect(Effect *effect) const {
    // put effect into canonical form (and ... )
    AndEffect *canonical = 0;
    if( (dynamic_cast<AtomicEffect*>(effect) != 0) || (dynamic_cast<ConditionalEffect*>(effect) != 0) ) {
        canonical = new AndEffect;
        canonical->push_back(effect);
    } else {
        assert(dynamic_cast<AndEffect*>(effect) != 0);
        canonical = static_cast<AndEffect*>(effect);
    }

    // canonize conditional effects as (when (...) (and ...))
    for( size_t k = 0; k < canonical->size(); ++k ) {
        const Effect *eff = (*canonical)[k];
        if( dynamic_cast<const ConditionalEffect*>(eff) != 0 ) {
            const ConditionalEffect *ceff = static_cast<const ConditionalEffect*>(eff);
            if( dynamic_cast<const AndEffect*>(ceff->effect_) == 0 ) {
                AndEffect *and_effect = new AndEffect;
                and_effect->push_back(ceff->effect_);
                const_cast<ConditionalEffect*>(ceff)->effect_ = and_effect;
            }
        }
    }
    return canonical;
}

void PDDL_Base::lw1_complete_effect_with_variable(AndEffect *effect, const Variable &var) const {
    vector<Effect*> additions;
    for( size_t k = 0; k < effect->size(); ++k ) {
        if( dynamic_cast<const AtomicEffect*>((*effect)[k]) != 0 ) {
            const AtomicEffect &literal = *static_cast<const AtomicEffect*>((*effect)[k]);
            if( !literal.negated_ && (var.grounded_domain_.find(literal) != var.grounded_domain_.end()) ) {
                for( unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it ) {
                    assert(!it->negated_);
                    if( literal != *it ) additions.push_back(AtomicEffect(*it).negate());
                }
            }
        } else {
            assert(dynamic_cast<const ConditionalEffect*>((*effect)[k]) != 0);
            const ConditionalEffect *ceff = static_cast<const ConditionalEffect*>((*effect)[k]);
            assert(dynamic_cast<const AndEffect*>(ceff->effect_) != 0);
            lw1_complete_effect_with_variable(const_cast<AndEffect*>(static_cast<const AndEffect*>(ceff->effect_)), var);
        }
    }
    effect->insert(effect->end(), additions.begin(), additions.end());
}

const PDDL_Base::Atom* PDDL_Base::lw1_fetch_need_set_sensing_atom(const Action &action) {
    const map<string, const Atom*>::const_iterator it = need_set_sensing_atoms_.find(action.print_name_);
    if( it == need_set_sensing_atoms_.end() ) {
        string name = string("need-set-sensing-for-") + action.print_name_;
        Atom *atom = create_atom(name);
        need_set_sensing_atoms_.insert(make_pair(action.print_name_, atom));
        return atom;
    } else {
        return it->second;
    }
}

const PDDL_Base::Atom* PDDL_Base::lw1_fetch_enabler_for_sensing(const unsigned_atom_set &atoms) {
    const map<unsigned_atom_set, const Atom*>::const_iterator it = need_post_atoms_.find(atoms);
    if( it == need_post_atoms_.end() ) {
        string name = string("enable-sensing-for-set-") + Utils::to_string(need_post_atoms_.size());
        Atom *atom = create_atom(name);
        need_post_atoms_.insert(make_pair(atoms, atom));
        return atom;
    } else {
        return it->second;
    }
}

const PDDL_Base::Atom* PDDL_Base::lw1_fetch_enabler_for_sensing(const Atom &atom) {
    const map<string, const Atom*>::const_iterator it = sensing_atoms_.find(atom.to_string(atom.negated_, true));
    if( it == sensing_atoms_.end() ) {
        string name = string("enable-sensing-for-") + atom.to_string(atom.negated_, true);
        Atom *new_atom = create_atom(name);
        sensing_atoms_.insert(make_pair(atom.to_string(atom.negated_, true), new_atom));
        return new_atom;
    } else {
        return it->second;
    }
}

void PDDL_Base::do_translation() {
    instantiate_elements();
    assert(!lw1_translation_);

    // translate oneofs into invariants and observe effects in actions (CLG-compatibility mode)
    if( clg_translation_ ) {
        clg_translate_actions();                      // don't change order: first creates
        clg_map_oneofs_and_clauses_to_invariants();   // (normal-execution) that is neede by second
    }

    // if no translation, mark every action as original action
    if( !clg_translation_ ) {
        for( size_t k = 0; k < dom_actions_.size(); ++k ) {
            const Action &action = *dom_actions_[k];
            original_actions_.insert(string(action.print_name_));
        }
    }
}

void PDDL_Base::do_lw1_translation(const variable_vec* &variables,
                                   const variable_group_vec* &variable_groups,
                                   const list<pair<const Action*, const Sensing*> >* &sensing_models,
                                   const map<string, set<string> >* &accepted_literals_for_observables) {
    instantiate_elements();
    assert(!clg_translation_);

    // translate variable formulations
    if( lw1_translation_ ) {
        lw1_calculate_atoms_for_state_variables();
        lw1_calculate_atoms_for_variable_groups();
        lw1_calculate_beams_for_grounded_observable_variables();
        lw1_remove_variables_with_empty_grounded_domain();

        if( options_.is_enabled("lw1:strict") ) {
            lw1_translate_actions_strict();
        } else {
            lw1_translate_actions();
        }

        lw1_create_deductive_rules_for_variables();
        lw1_create_deductive_rules_for_sensing();

        if( !options_.is_enabled("lw1:boost:enable-post-actions") ) {
            lw1_patch_actions_with_enablers_for_sensing();
        }

        variables = &lw1_variables_;
        variable_groups = &lw1_variable_groups_;
        sensing_models = &lw1_sensing_models_;
        accepted_literals_for_observables = &lw1_accepted_literals_for_observables_;
    }

    // if no translation, mark every action as original action
    if( !lw1_translation_ ) {
        for( size_t k = 0; k < dom_actions_.size(); ++k ) {
            const Action &action = *dom_actions_[k];
            original_actions_.insert(string(action.print_name_));
        }
    }
}

void PDDL_Base::emit_instance(Instance &ins) const {
    const char *dname = tab_.table_char_map().strdup(domain_name_ ? domain_name_ : "??");
    const char *pname = tab_.table_char_map().strdup(problem_name_ ? problem_name_ : "??");
    ins.name_ = new InstanceName(dname, pname);
    delete[] dname;
    delete[] pname;

    // emit initial situation.
    for( size_t k = 0; k < dom_init_.size(); ++k )
        dom_init_[k]->emit(ins);

    // emit hidden initial situation
    cout << "calculating " << dom_hidden_.size() << " hidden state(s)" << endl;
    ins.hidden_.resize(dom_hidden_.size());
    for( size_t k = 0; k < dom_hidden_.size(); ++k ) {
        for( size_t j = 0; j < dom_hidden_[k].size(); ++j ) {
            assert(dynamic_cast<const InitLiteral*>(dom_hidden_[k][j]) != 0);
            static_cast<const InitLiteral*>(dom_hidden_[k][j])->emit(ins, ins.hidden_[k]);
        }
    }

    // emit goal situation
    if( dom_goal_ != 0 )
        dom_goal_->emit(ins, ins.goal_literals_);

    // emit actions
    for( size_t k = 0; k < dom_actions_.size(); ++k )
        dom_actions_[k]->emit(ins);

    // emit sensors
    for( size_t k = 0; k < dom_sensors_.size(); ++k )
        dom_sensors_[k]->emit(ins);

    // emit axioms
    for( size_t k = 0; k < dom_axioms_.size(); ++k )
        dom_axioms_[k]->emit(ins);

    // emit observables
    for( size_t k = 0; k < dom_observables_.size(); ++k )
        dom_observables_[k]->emit(ins);

    // emit sticky
    for( size_t k = 0; k < dom_stickies_.size(); ++k )
        dom_stickies_[k]->emit(ins);

    // emit static atoms
    for( unsigned_atom_set::const_iterator it = dom_static_atoms_.begin(); it != dom_static_atoms_.end(); ++it )
        it->emit(ins, ins.static_atoms_from_base_);

    // emit atoms for observable variables (if static)
    if( lw1_translation_ && options_.is_enabled("lw1:strict") ) {
        lw1_emit_and_protect_atoms_for_observable_variables(ins);
        if( options_.is_enabled("lw1:boost:single-sensing-literal-enablers") ) {
            cout << Utils::error() << "lw1:boost:single-sensing-literal-enablers is deprecated" << endl;
            exit(-1);
            lw1_protect_enablers_for_sensing(ins); // CHECK: can this be removed?
        }
    }

    // declare original actions
    for( set<string>::const_iterator it = original_actions_.begin(); it != original_actions_.end(); ++it )
        ins.declare_original_action(*it);
}

void PDDL_Base::print(ostream &os) const {
    os << "[PDDL_Base::print() not yet implemented]" << endl;
}

PDDL_Base::Symbol* PDDL_Base::Symbol::clone() const {
    Symbol *cl = new Symbol(strdup(print_name_), sym_class_);
    cl->sym_type_ = sym_type_;
    return cl;
}

void PDDL_Base::TypeSymbol::add_element(Symbol *e) {
    elements_.push_back(e);
    if( sym_type_ != 0 ) static_cast<TypeSymbol*>(sym_type_)->add_element(e);
}

string PDDL_Base::TypeSymbol::to_string() const {
    string str(print_name_);
    if( sym_type_ ) str += " - " + sym_type_->to_string();
#if 0
    str += "): {";
    for( size_t k = 0; k < elements_.size(); ++k )
        str += elements_[k]->to_string() + ",";
    str += "}";
#endif
    return str;
}

PDDL_Base::Symbol* PDDL_Base::TypeSymbol::clone() const {
    TypeSymbol *cl = new TypeSymbol(strdup(print_name_));
    cl->sym_type_ = sym_type_;
    copy_symbol_vec<Symbol*>(elements_, cl->elements_);
    return cl;
}

PDDL_Base::Symbol* PDDL_Base::VariableSymbol::clone() const {
    VariableSymbol *cl = new VariableSymbol(strdup(print_name_));
    cl->sym_type_ = sym_type_;
    cl->value_ = value_;
    return cl;
}

string PDDL_Base::VariableSymbol::to_string() const {
    string str;
    if( value_ == 0 ) {
        str += print_name_;
        if( sym_type_ ) str += " - " + sym_type_->to_string();
    } else {
        str += value_->to_string();
    }
    return str;
}

PDDL_Base::Symbol* PDDL_Base::PredicateSymbol::clone() const {
    PredicateSymbol *cl = new PredicateSymbol(strdup(print_name_));
    cl->sym_type_ = sym_type_;
    cl->strongly_static_ = strongly_static_;
    copy_symbol_vec<VariableSymbol*>(param_, cl->param_);
    return cl;
}

string PDDL_Base::PredicateSymbol::to_string() const {
    string str(print_name_);
    for( size_t k = 0; k < param_.size(); ++k )
        str += " " + param_[k]->to_string();
    return str + ")";
}

void PDDL_Base::Schema::enumerate(bool only_count) const {
    count_ = 0;
    for( size_t k = 0; k < param_.size(); ++k )
        param_[k]->value_ = 0;
    rec_enumerate(0, only_count);
}

void PDDL_Base::Schema::rec_enumerate(size_t p, bool only_count) const {
    if( p < param_.size() ) {
        TypeSymbol *t = static_cast<TypeSymbol*>(param_[p]->sym_type_);
        for( size_t k = 0; k < t->elements_.size(); ++k ) {
            param_[p]->value_ = t->elements_[k];
            // TODO: incremental pruning
            rec_enumerate(p+1, only_count);
        }
        param_[p]->value_ = 0;
    } else {
        if( only_count )
            ++count_;
        else
            process_instance();
    }
}

bool PDDL_Base::Atom::is_strongly_static(const PredicateSymbol &p) const {
    assert((pred_->print_name_ != p.print_name_) || (pred_ == &p));
    assert((pred_->print_name_ == p.print_name_) || (pred_ != &p));
    return pred_ != &p;
}

void PDDL_Base::Atom::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < param_.size(); ++k ) {
        for( size_t i = 0; i < old_param.size(); ++i ) {
            if( param_[k] == old_param[i] ) {
                param_[k] = new_param[i];
                break;
            }
        }
    }
}

bool PDDL_Base::Atom::operator==(const Atom &atom) const {
    if( pred_ != atom.pred_ ) return false;
    if( negated_ != atom.negated_ ) return false;
    assert(param_.size() == atom.param_.size());
    for( size_t k = 0; k < param_.size(); ++k )
        if( param_[k] != atom.param_[k] ) return false;
    return true;
}

bool PDDL_Base::Atom::operator<(const Atom &atom) const {
    if( pred_ < atom.pred_ ) return true;
    if( pred_ > atom.pred_ ) return false;
    if( !negated_ && atom.negated_ ) return true;
    if( negated_ && !atom.negated_ ) return false;
    assert(param_.size() == atom.param_.size());
    for( size_t k = 0; k < param_.size(); ++k ) {
        if( param_[k] < atom.param_[k] ) return true;
        if( param_[k] > atom.param_[k] ) return false;
    }
    return false;
}

bool PDDL_Base::Atom::unsigned_less_comparator::operator()(const Atom &atom1, const Atom &atom2) const {
    if( atom1.pred_ < atom2.pred_ ) return true;
    if( atom1.pred_ > atom2.pred_ ) return false;
    assert(atom1.param_.size() == atom2.param_.size());
    for( size_t k = 0; k < atom1.param_.size(); ++k ) {
        if( atom1.param_[k] < atom2.param_[k] ) return true;
        if( atom1.param_[k] > atom2.param_[k] ) return false;
    }
    return false;
}

const PDDL_Base::Atom& PDDL_Base::Atom::operator=(const Atom &atom) {
    pred_ = atom.pred_;
    param_ = atom.param_;
    negated_ = atom.negated_;
    return *this;
}

Instance::Atom* PDDL_Base::Atom::find_prop(Instance &ins, bool negated, bool create) const {
    ptr_table *r = negated ? &(pred_->neg_prop_) : &(pred_->pos_prop_);
    for( size_t k = 0; k < param_.size(); ++k ) {
        if( param_[k]->sym_class_ == sym_variable )
            r = r->insert_next(static_cast<VariableSymbol*>(param_[k])->value_);
        else
            r = r->insert_next(param_[k]);
    }
    if( !r->val ) {
        if( !create ) return 0;
        PDDL_Name a_name(pred_, negated);
        for( size_t k = 0; k < param_.size(); ++k ) {
            if( param_[k]->sym_class_ == sym_variable )
	        a_name.add(static_cast<VariableSymbol*>(param_[k])->value_);
            else
	        a_name.add(param_[k]);
        }
        Instance::Atom &p = ins.new_atom(new CopyName(a_name.to_string(true)));
        r->val = &p;
    }
    return static_cast<Instance::Atom*>(r->val);
}

PDDL_Base::Atom* PDDL_Base::Atom::ground(bool clone_variables) const {
    Atom *result = new Atom(*this);
    for( size_t k = 0; k < param_.size(); ++k ) {
        symbol_class c = param_[k]->sym_class_;
        assert((c == sym_object) || (c == sym_variable));
        if( c == sym_variable ) {
            const VariableSymbol *var = static_cast<const VariableSymbol*>(param_[k]);
            if( var->value_ != 0 )
                result->param_[k] = var->value_;
            else if( clone_variables )
                result->param_[k] = new VariableSymbol(strdup(var->print_name_));
        }
    }
    return result;
}

bool PDDL_Base::Atom::has_free_variables(const var_symbol_vec &param) const {
    for( size_t k = 0; k < param_.size(); ++k ) {
        if( param_[k]->sym_class_ == sym_variable ) {
            bool found = false;
            for( size_t i = 0; i < param.size(); ++i ) {
                if( param_[k] == param[i] ) {
                    found = true;
                    break;
                }
            }
            if( !found ) return true;
        }
    }
    return false;
}

bool PDDL_Base::Atom::is_fully_instantiated() const {
    for( size_t k = 0; k < param_.size(); ++k ) {
        if( (param_[k]->sym_class_ == sym_variable) &&
            (static_cast<VariableSymbol*>(param_[k])->value_ == 0) ) {
            return false;
        }
    }
    return true;
}

void PDDL_Base::Atom::emit(Instance &ins, index_set &atoms) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !negated_ )
        atoms.insert(1 + p->index_);
    else
        atoms.insert(-(1 + p->index_));
}

string PDDL_Base::Atom::to_string(bool extra_neg, bool mangled) const {
    string str, sep(mangled ? "_" : " "), beg(mangled ? "" : "("), end(mangled ? "" : ")");
    extra_neg = extra_neg ? !negated_ : negated_;
    if( extra_neg ) str += beg + "not" + sep;
    str += beg + pred_->print_name_;
    for( size_t k = 0; k < param_.size(); ++k ) {
        if( (param_[k]->sym_class_ == sym_variable) && (static_cast<VariableSymbol*>(param_[k])->value_ != 0) )
            str += sep + static_cast<VariableSymbol*>(param_[k])->value_->to_string();
        else
            str += sep + param_[k]->to_string();
    }
    str += end;
    if( extra_neg ) str += end;
    return str;
}

bool PDDL_Base::signed_atom_set::operator<(const signed_atom_set &atom_set) const {
    if(size() < atom_set.size()) return true;
    if(size() > atom_set.size()) return false;
    for( const_iterator it = begin(), jt = atom_set.begin(); it != end(); ++it, ++jt ) {
        if( key_comp()(*it, *jt) ) return true;
        if( key_comp()(*jt, *it) ) return false;
    }
    return false;
}

bool PDDL_Base::unsigned_atom_set::operator<(const unsigned_atom_set &atom_set) const {
    if(size() < atom_set.size()) return true;
    if(size() > atom_set.size()) return false;
    for( const_iterator it = begin(), jt = atom_set.begin(); it != end(); ++it, ++jt ) {
        if( key_comp()(*it, *jt) ) return true;
        if( key_comp()(*jt, *it) ) return false;
    }
    return false;
}

PDDL_Base::Condition* PDDL_Base::Constant::ground(bool clone_variables, bool negate, bool replace_static_values) const {
    return new Constant(negate ? !value_ : value_);
}

PDDL_Base::Condition* PDDL_Base::Constant::as_dnf() const {
    cout << Utils::error() << "as_dnf() should not be called on Constant: first ground the condition!" << endl;
    exit(255);
}

void PDDL_Base::Literal::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    Atom::remap_parameters(old_param, new_param);
}

void PDDL_Base::Literal::emit(Instance &ins, index_set &condition) const {
    Atom::emit(ins, condition);
}

PDDL_Base::Condition* PDDL_Base::Literal::ground(bool clone_variables, bool negate, bool replace_static_values) const {
    return copy(clone_variables, negate, replace_static_values);
}

bool PDDL_Base::Literal::has_free_variables(const var_symbol_vec &param, bool) const {
    return Atom::has_free_variables(param);
}

void PDDL_Base::Literal::extract_atoms(unsigned_atom_set &atoms) const {
    atoms.insert(*this);
}

bool PDDL_Base::Literal::is_term(bool positive, const PDDL_Base *base) const {
    if( positive && negated_ ) {
        if( base == 0 ) {
            return false;
        } else {
            // if there is a non-binary var such that negated literal (atom) is value, return false
            bool value_for_some_variable = false;
            for( size_t k = 0; k < base->lw1_variables_.size(); ++k ) {
                const Variable &var = *base->lw1_variables_[k];
                if( var.grounded_domain_.find(*this) == var.grounded_domain_.end() ) continue;
                value_for_some_variable = true;
                if( !var.is_binary() ) return false;
            }
            return value_for_some_variable;
        }
    }
    return true;
}

PDDL_Base::Condition* PDDL_Base::Literal::as_dnf() const {
    return copy(true);
}

PDDL_Base::Condition* PDDL_Base::Literal::copy(bool clone_variables, bool negate, bool replace_static_values) const {
    Condition *result = 0;
    Atom *atom = Atom::ground(false);
    if( replace_static_values && pred_->strongly_static_ && (pddl_base_ != 0) && atom->is_fully_instantiated() ) {
        bool value = pddl_base_->truth_value_in_initial_situation(*atom);
        result = new Constant(negate ? !value : value);
    } else {
        result = new Literal(*atom, negate);
    }
    delete atom;
    return result;
}

void PDDL_Base::EQ::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < old_param.size(); ++k ) {
        if( first == old_param[k] ) {
            first = new_param[k];
            break;
        }
    }
    for( size_t k = 0; k < old_param.size(); ++k ) {
        if( second == old_param[k] ) {
            second = new_param[k];
            break;
        }
    }
}

PDDL_Base::Condition* PDDL_Base::EQ::ground(bool clone_variables, bool negate, bool replace_static_values) const {
    EQ *result = new EQ(first, second, negate ? !negated_ : negated_);
    if( first->sym_class_ == sym_variable ) {
        if( static_cast<const VariableSymbol*>(first)->value_ != 0 )
            result->first = static_cast<const VariableSymbol*>(first)->value_;
        else if( clone_variables )
            result->first = new VariableSymbol(strdup(first->print_name_));
    }
    if( second->sym_class_ == sym_variable ) {
        if( static_cast<const VariableSymbol*>(second)->value_ != 0 )
            result->second = static_cast<const VariableSymbol*>(second)->value_;
        else if( clone_variables )
            result->second = new VariableSymbol(strdup(second->print_name_));
    }

    // check if result can be reduced to a boolean constant
    if( (result->first->sym_class_ == sym_object) && (result->second->sym_class_ == sym_object) ) {
        bool value = result->first == result->second;
        value = result->negated_ ? !value : value;
        delete result;
        return new Constant(value);
    } else {
        return result;
    }
}

bool PDDL_Base::EQ::has_free_variables(const var_symbol_vec &param, bool) const {
    if( first->sym_class_ == sym_variable ) {
        bool found = false;
        for( size_t k = 0; k < param.size(); ++k ) {
            if( first == param[k] ) {
                found = true;
                break;
            }
        }
        if( !found ) return true;
    }
    if( second->sym_class_ == sym_variable ) {
        bool found = false;
        for( size_t k = 0; k < param.size(); ++k ) {
            if( second == param[k] ) {
                found = true;
                break;
            }
        }
        if( !found ) return true;
    }
    return false;
}

PDDL_Base::Condition* PDDL_Base::EQ::as_dnf() const {
    cout << Utils::error() << "as_dnf() should not be called on EQ: first ground the condition!" << endl;
    exit(255);
}

string PDDL_Base::EQ::to_string() const {
    string str;
    if( negated_ ) str += "(not ";
    str += "(= " + first->to_string() + " " + second->to_string() + ")";
    if( negated_ ) str += ")";
    return str;
}

void PDDL_Base::And::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < size(); ++k )
        const_cast<Condition*>((*this)[k])->remap_parameters(old_param, new_param);
}

void PDDL_Base::And::emit(Instance &ins, index_set &condition) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->emit(ins, condition);
}

PDDL_Base::Condition* PDDL_Base::And::ground(bool clone_variables, bool negate, bool replace_static_values) const {
    Condition *result = 0;
    condition_vec conditions;
    for( size_t k = 0; k < size(); ++k ) {
        Condition *item = (*this)[k]->ground(clone_variables, negate, replace_static_values);
        if( dynamic_cast<Constant*>(item) != 0 ) {
            Constant &constant = *static_cast<Constant*>(item);
            if( (!negate && constant.value_) || (negate && !constant.value_) ) {
                // item is neutral constant
                delete item;
            } else {
                // item alone determines truth value
                delete item;
                for( size_t i = 0; i < conditions.size(); ++i ) delete conditions[i];
                result = new Constant(negate ? true : false);
                break;
            }
        } else if( !negate && (dynamic_cast<And*>(item) != 0) ) {
            And &item_list = *static_cast<And*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                conditions.push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else if( negate && (dynamic_cast<Or*>(item) != 0) ) {
            Or &item_list = *static_cast<Or*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                conditions.push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else {
            conditions.push_back(item);
        }
    }

    // check if result can be reduced to constant or single condition
    if( result == 0 ) {
        if( conditions.empty() ) {
            result = new Constant(negate ? false : true);
        } else if( conditions.size() == 1 ) {
            result = const_cast<Condition*>(conditions[0]);
        } else {
            result = negate ? static_cast<Condition*>(new Or(conditions)) : static_cast<Condition*>(new And(conditions));
        }
    }
    return result;
}

bool PDDL_Base::And::has_free_variables(const var_symbol_vec &param, bool dont_extend) const {
    for( size_t k = 0; k < size(); ++k ) {
        if( (*this)[k]->has_free_variables(param, dont_extend) )
            return true;
    }
    return false;
}

void PDDL_Base::And::extract_atoms(unsigned_atom_set &atoms) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->extract_atoms(atoms);
}

bool PDDL_Base::And::is_term(bool positive, const PDDL_Base *base) const {
    if( size() <= 1 ) return false;
    for( size_t k = 0; k < size(); ++k ) {
        if( dynamic_cast<const Literal*>((*this)[k]) == 0 )
            return false;
        else if( !(*this)[k]->is_term(positive, base) )
            return false;
    }
    return true;
}

PDDL_Base::Condition* PDDL_Base::And::as_dnf() const {
    Condition *dnf = (*begin())->as_dnf();
    if( size() > 1 ) {
        for( size_t k = 1; k < size(); ++k ) {
            Condition *sub = (*this)[k]->as_dnf();
            Condition *new_dnf = 0;
            if( dynamic_cast<Literal*>(dnf) != 0 ) {
                if( dynamic_cast<Literal*>(sub) != 0 )
                    new_dnf = distribute_and(*static_cast<Literal*>(dnf), *static_cast<Literal*>(sub));
                else if( dynamic_cast<And*>(sub) != 0 )
                    new_dnf = distribute_and(*static_cast<And*>(sub), *static_cast<Literal*>(dnf));
                else if( dynamic_cast<Or*>(sub) != 0 )
                    new_dnf = distribute_and(*static_cast<Or*>(sub), *static_cast<Literal*>(dnf));
            } else if( dynamic_cast<And*>(dnf) != 0 ) {
                if( dynamic_cast<Literal*>(sub) != 0 )
                    new_dnf = distribute_and(*static_cast<And*>(dnf), *static_cast<Literal*>(sub));
                else if( dynamic_cast<And*>(sub) != 0 )
                    new_dnf = distribute_and(*static_cast<And*>(dnf), *static_cast<And*>(sub));
                else if( dynamic_cast<Or*>(sub) != 0 )
                    new_dnf = distribute_and(*static_cast<Or*>(sub), *static_cast<And*>(dnf));
            } else if( dynamic_cast<Or*>(dnf) != 0 ) {
                if( dynamic_cast<Literal*>(sub) != 0 )
                    new_dnf = distribute_and(*static_cast<Or*>(dnf), *static_cast<Literal*>(sub));
                else if( dynamic_cast<And*>(sub) != 0 )
                    new_dnf = distribute_and(*static_cast<Or*>(dnf), *static_cast<And*>(sub));
                else if( dynamic_cast<Or*>(sub) != 0 )
                    new_dnf = distribute_and(*static_cast<Or*>(dnf), *static_cast<Or*>(sub));
            }
            delete dnf;
            delete sub;
            dnf = new_dnf;
        }
    }
    return dnf;
}

string PDDL_Base::And::to_string() const {
    string str("(and");
    for( size_t k = 0; k < size(); ++k )
        str += " " + (*this)[k]->to_string();
    return str + ")";
}

void PDDL_Base::Or::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < size(); ++k )
        const_cast<Condition*>((*this)[k])->remap_parameters(old_param, new_param);
}

void PDDL_Base::Or::emit(Instance &ins, index_set &condition) const {
    cout << Utils::error() << "'Or' should have dissapeared before instantiating: " << *this << endl;
    exit(255);
}

PDDL_Base::Condition* PDDL_Base::Or::ground(bool clone_variables, bool negate, bool replace_static_values) const {
    Condition *result = 0;
    condition_vec conditions;
    for( size_t k = 0; k < size(); ++k ) {
        Condition *item = (*this)[k]->ground(false, negate, replace_static_values);
        if( dynamic_cast<Constant*>(item) != 0 ) {
            Constant &constant = *static_cast<Constant*>(item);
            if( (!negate && !constant.value_) || (negate && constant.value_) ) {
                // item is neutral constant
                delete item;
            } else {
                // item alone determines truth value
                delete item;
                for( size_t i = 0; i < conditions.size(); ++i ) delete conditions[i];
                result = new Constant(!negate ? true : false);
                break;
            }
        } else if( !negate && (dynamic_cast<Or*>(item) != 0) ) {
            Or &item_list = *static_cast<Or*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                conditions.push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else if( negate && (dynamic_cast<And*>(item) != 0) ) {
            And &item_list = *static_cast<And*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                conditions.push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else {
            conditions.push_back(item);
        }
    }

    // check if result can be reduced to constant or single condition
    if( result == 0 ) {
        if( conditions.empty() ) {
            return new Constant(negate ? true : false);
        } else if( conditions.size() == 1 ) {
            return const_cast<Condition*>(conditions[0]);
        } else {
            return negate ? static_cast<Condition*>(new And(conditions)) : static_cast<Condition*>(new Or(conditions));
        }
    }
    return result;
}

bool PDDL_Base::Or::has_free_variables(const var_symbol_vec &param, bool dont_extend) const {
    for( size_t k = 0; k < size(); ++k ) {
        if( (*this)[k]->has_free_variables(param, dont_extend) )
            return true;
    }
    return false;
}

void PDDL_Base::Or::extract_atoms(unsigned_atom_set &atoms) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->extract_atoms(atoms);
}

bool PDDL_Base::Or::is_dnf(bool positive, const PDDL_Base *base) const {
    if( size() <= 1 ) return false;
    for( size_t k = 0; k < size(); ++k ) {
        if( !(*this)[k]->is_term(positive, base) )
            return false;
    }
    return true;
}

PDDL_Base::Condition* PDDL_Base::Or::as_dnf() const {
    Condition *dnf = (*begin())->as_dnf();
    if( size() > 1 ) {
        for( size_t k = 1; k < size(); ++k ) {
            Condition *sub = (*this)[k]->as_dnf();
            Condition *new_dnf = 0;
            if( dynamic_cast<Literal*>(dnf) != 0 ) {
                if( dynamic_cast<Literal*>(sub) != 0 )
                    new_dnf = distribute_or(*static_cast<Literal*>(dnf), *static_cast<Literal*>(sub));
                else if( dynamic_cast<And*>(sub) != 0 )
                    new_dnf = distribute_or(*static_cast<And*>(sub), *static_cast<Literal*>(dnf));
                else if( dynamic_cast<Or*>(sub) != 0 )
                    new_dnf = distribute_or(*static_cast<Or*>(sub), *static_cast<Literal*>(dnf));
            } else if( dynamic_cast<And*>(dnf) != 0 ) {
                if( dynamic_cast<Literal*>(sub) != 0 )
                    new_dnf = distribute_or(*static_cast<And*>(dnf), *static_cast<Literal*>(sub));
                else if( dynamic_cast<And*>(sub) != 0 )
                    new_dnf = distribute_or(*static_cast<And*>(dnf), *static_cast<And*>(sub));
                else if( dynamic_cast<Or*>(sub) != 0 )
                    new_dnf = distribute_or(*static_cast<Or*>(sub), *static_cast<And*>(dnf));
            } else if( dynamic_cast<Or*>(dnf) != 0 ) {
                if( dynamic_cast<Literal*>(sub) != 0 )
                    new_dnf = distribute_or(*static_cast<Or*>(dnf), *static_cast<Literal*>(sub));
                else if( dynamic_cast<And*>(sub) != 0 )
                    new_dnf = distribute_or(*static_cast<Or*>(dnf), *static_cast<And*>(sub));
                else if( dynamic_cast<Or*>(sub) != 0 )
                    new_dnf = distribute_or(*static_cast<Or*>(dnf), *static_cast<Or*>(sub));
            }
            delete dnf;
            delete sub;
            dnf = new_dnf;
        }
    }
    return dnf;
}

string PDDL_Base::Or::to_string() const {
    string str("(or");
    for( size_t k = 0; k < size(); ++k )
        str += " " + (*this)[k]->to_string();
    return str + ")";
}

void PDDL_Base::ForallCondition::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    const_cast<Condition*>(condition_)->remap_parameters(old_param, new_param);
}

void PDDL_Base::ForallCondition::emit(Instance &ins, index_set &condition) const {
    cout << Utils::error() << "'ForallCondition' should have dissapeared before instantiating: " << *this << endl;
    exit(255);
}

PDDL_Base::Condition* PDDL_Base::ForallCondition::ground(bool clone_variables, bool negate, bool replace_static_values) const {
    negate_stack_.push_back(negate);
    clone_variables_stack_.push_back(clone_variables);
    result_stack_.push_back(negate ? static_cast<Condition*>(new Or) : static_cast<Condition*>(new And));
    enumerate(true);
    if( negate )
        static_cast<Or*>(result_stack_.back())->reserve(count_);
    else
        static_cast<And*>(result_stack_.back())->reserve(count_);
    enumerate();

    Condition *result = result_stack_.back();
    result_stack_.pop_back();
    clone_variables_stack_.pop_back();
    negate_stack_.pop_back();
    assert(dynamic_cast<Constant*>(result) || dynamic_cast<And*>(result) || dynamic_cast<Or*>(result));
    assert(negate || dynamic_cast<And*>(result));
    assert(!negate || dynamic_cast<Or*>(result));

    // check if result can be reduced to a constant or single condition
    if( dynamic_cast<Constant*>(result) != 0 ) {
        assert(negate || !static_cast<Constant*>(result)->value_);
        assert(!negate || static_cast<Constant*>(result)->value_);
        return result;
    } else if( !negate ) {
        And *and_result = static_cast<And*>(result);
        if( and_result->empty() ) {
            delete and_result;
            return new Constant(true);
        } else if( and_result->size() == 1 ) {
            Condition *single = const_cast<Condition*>((*and_result)[0]);
            and_result->clear();
            delete and_result;
            return single;
        } else {
            return and_result;
        }
    } else {
        Or *or_result = static_cast<Or*>(result);
        if( or_result->empty() ) {
            delete or_result;
            return new Constant(false);
        } else if( or_result->size() == 1 ) {
            Condition *single = const_cast<Condition*>((*or_result)[0]);
            or_result->clear();
            delete or_result;
            return single;
        } else {
            return or_result;
        }
    }
}

void PDDL_Base::ForallCondition::process_instance() const {
    bool negate = negate_stack_.back();
    bool clone_variables = clone_variables_stack_.back();
    if( dynamic_cast<Constant*>(result_stack_.back()) != 0 ) {
        return; // value is already reduced to absorbing constant
    } else if( !negate ) {
        assert(dynamic_cast<And*>(result_stack_.back()) != 0);
        And &and_result = *static_cast<And*>(result_stack_.back());
        Condition *item = condition_->ground(clone_variables, false);
        if( dynamic_cast<Constant*>(item) != 0 ) {
            bool value = static_cast<Constant*>(item)->value_;
            delete item;
            if( !value ) {
                delete result_stack_.back();
                result_stack_.pop_back();
                result_stack_.push_back(new Constant(false));
            }
        } else if( dynamic_cast<And*>(item) != 0 ) {
            And &item_list = *static_cast<And*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                and_result.push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else {
            and_result.push_back(item);
        }
    }  else {
        assert(dynamic_cast<Or*>(result_stack_.back()) != 0);
        Or &or_result = *static_cast<Or*>(result_stack_.back());
        Condition *item = condition_->ground(clone_variables, true);
        if( dynamic_cast<Constant*>(item) != 0 ) {
            bool value = static_cast<Constant*>(item)->value_;
            delete item;
            if( value ) {
                delete result_stack_.back();
                result_stack_.pop_back();
                result_stack_.push_back(new Constant(true));
            }
        } else if( dynamic_cast<Or*>(item) != 0 ) {
            Or &item_list = *static_cast<Or*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                or_result.push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else {
            or_result.push_back(item);
        }
    }
}

bool PDDL_Base::ForallCondition::has_free_variables(const var_symbol_vec &param, bool dont_extend) const {
    var_symbol_vec nparam(param);
    if( !dont_extend ) nparam.insert(nparam.end(), param_.begin(), param_.end());
    return condition_->has_free_variables(nparam, dont_extend);
}

void PDDL_Base::ForallCondition::extract_atoms(unsigned_atom_set &atoms) const {
    cout << Utils::error() << "extract_atoms() should not be called on ForallCondition: first ground the condition!" << endl;
    exit(255);
}

PDDL_Base::Condition* PDDL_Base::ForallCondition::as_dnf() const {
    cout << Utils::error() << "as_dnf() should not be called on ForallCondition: first ground the condition!" << endl;
    exit(255);
}

string PDDL_Base::ForallCondition::to_string() const {
    string str("(forall (");
    for( size_t k = 0; k < param_.size(); ++k )
        str += (k > 0 ? " " : "") + param_[k]->to_string();
    str += ") " + condition_->to_string() + ")";
    return str;
}

void PDDL_Base::ExistsCondition::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    const_cast<Condition*>(condition_)->remap_parameters(old_param, new_param);
}

void PDDL_Base::ExistsCondition::emit(Instance &ins, index_set &condition) const {
    cout << Utils::error() << "'ExistsCondition' should have dissapeared before instantiating: " << *this << endl;
    exit(255);
}

PDDL_Base::Condition* PDDL_Base::ExistsCondition::ground(bool clone_variables, bool negate, bool replace_static_values) const {
    negate_stack_.push_back(negate);
    clone_variables_stack_.push_back(clone_variables);
    result_stack_.push_back(negate ? static_cast<Condition*>(new And) : static_cast<Condition*>(new Or));
    enumerate(true);
    if( negate )
        static_cast<And*>(result_stack_.back())->reserve(count_);
    else
        static_cast<Or*>(result_stack_.back())->reserve(count_);
    enumerate();

    Condition *result = result_stack_.back();
    result_stack_.pop_back();
    clone_variables_stack_.pop_back();
    negate_stack_.pop_back();
    assert(dynamic_cast<Constant*>(result) || dynamic_cast<And*>(result) || dynamic_cast<Or*>(result));
    assert(negate || dynamic_cast<Or*>(result));
    assert(!negate || dynamic_cast<And*>(result));

    // check if result can be reduced to a constant or single condition
    if( dynamic_cast<Constant*>(result) != 0 ) {
        assert(negate || !static_cast<Constant*>(result)->value_);
        assert(!negate || static_cast<Constant*>(result)->value_);
        return result;
    } else if( !negate ) {
        Or *or_result = static_cast<Or*>(result);
        if( or_result->empty() ) {
            delete or_result;
            return new Constant(false);
        } else if( or_result->size() == 1 ) {
            Condition *single = const_cast<Condition*>((*or_result)[0]);
            or_result->clear();
            delete or_result;
            return single;
        } else {
            return or_result;
        }
    } else {
        And *and_result = static_cast<And*>(result);
        if( and_result->empty() ) {
            delete and_result;
            return new Constant(true);
        } else if( and_result->size() == 1 ) {
            Condition *single = const_cast<Condition*>((*and_result)[0]);
            and_result->clear();
            delete and_result;
            return single;
        } else {
            return and_result;
        }
    }
}

void PDDL_Base::ExistsCondition::process_instance() const {
    bool negate = negate_stack_.back();
    bool clone_variables = clone_variables_stack_.back();
    if( dynamic_cast<Constant*>(result_stack_.back()) != 0 ) {
        return; // value is already reduced to absorbing constant
    } else if( !negate ) {
        assert(dynamic_cast<Or*>(result_stack_.back()) != 0);
        Or &or_result = *static_cast<Or*>(result_stack_.back());
        Condition *item = condition_->ground(clone_variables, false);
        if( dynamic_cast<Constant*>(item) != 0 ) {
            bool value = static_cast<Constant*>(item)->value_;
            delete item;
            if( value ) {
                delete result_stack_.back();
                result_stack_.pop_back();
                result_stack_.push_back(new Constant(true));
            }
        } else if( dynamic_cast<Or*>(item) != 0 ) {
            Or &item_list = *static_cast<Or*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                or_result.push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else {
            or_result.push_back(item);
        }
    }  else {
        assert(dynamic_cast<And*>(result_stack_.back()) != 0);
        And &and_result = *static_cast<And*>(result_stack_.back());
        Condition *item = condition_->ground(clone_variables, true);
        if( dynamic_cast<Constant*>(item) != 0 ) {
            bool value = static_cast<Constant*>(item)->value_;
            delete item;
            if( !value ) {
                delete result_stack_.back();
                result_stack_.pop_back();
                result_stack_.push_back(new Constant(false));
            }
        } else if( dynamic_cast<And*>(item) != 0 ) {
            And &item_list = *static_cast<And*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                and_result.push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else {
            and_result.push_back(item);
        }
    }
}

bool PDDL_Base::ExistsCondition::has_free_variables(const var_symbol_vec &param, bool dont_extend) const {
    var_symbol_vec nparam(param);
    if( !dont_extend ) nparam.insert(nparam.end(), param_.begin(), param_.end());
    return condition_->has_free_variables(nparam, dont_extend);
}

void PDDL_Base::ExistsCondition::extract_atoms(unsigned_atom_set &atoms) const {
    cout << Utils::error() << "extract_atoms() should not be called on ExistsCondition: first ground the condition!" << endl;
    exit(255);
}

PDDL_Base::Condition* PDDL_Base::ExistsCondition::as_dnf() const {
    cout << Utils::error() << "as_dnf() should not be called on ExistsCondition: first ground the condition!" << endl;
    exit(255);
}

string PDDL_Base::ExistsCondition::to_string() const {
    string str("(exists (");
    for( size_t k = 0; k < param_.size(); ++k )
        str += (k > 0 ? " " : "") + param_[k]->to_string();
    str += ") " + condition_->to_string() + ")";
    return str;
}

void PDDL_Base::AtomicEffect::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    Atom::remap_parameters(old_param, new_param);
}

void PDDL_Base::AtomicEffect::emit(Instance &ins, index_set &eff, Instance::when_vec&) const {
    Atom::emit(ins, eff);
}

PDDL_Base::Effect* PDDL_Base::AtomicEffect::ground(bool clone_variables, bool replace_static_values) const {
    return copy(clone_variables, false);
}

bool PDDL_Base::AtomicEffect::has_free_variables(const var_symbol_vec &param, bool) const {
    return Atom::has_free_variables(param);
}

bool PDDL_Base::AtomicEffect::is_strongly_static(const PredicateSymbol &p) const {
    return Atom::is_strongly_static(p);
}

void PDDL_Base::AtomicEffect::extract_atoms(unsigned_atom_set &atoms, bool only_affected) const {
    atoms.insert(*this);
}

PDDL_Base::AtomicEffect* PDDL_Base::AtomicEffect::copy(bool clone_variables, bool negate) const {
    Atom *atom = Atom::ground(clone_variables);
    AtomicEffect *result = new AtomicEffect(*atom, negate);
    delete atom;
    return result;
}

void PDDL_Base::AndEffect::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < size(); ++k )
        const_cast<Effect*>((*this)[k])->remap_parameters(old_param, new_param);
}

void PDDL_Base::AndEffect::emit(Instance &ins, index_set &eff, Instance::when_vec &when) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->emit(ins, eff, when);
}

PDDL_Base::Effect* PDDL_Base::AndEffect::ground(bool clone_variables, bool replace_static_values) const {
    effect_vec effects;
    for( size_t k = 0; k < size(); ++k ) {
        Effect *item = (*this)[k]->ground(clone_variables, replace_static_values);
        if( item != 0 ) {
            assert(dynamic_cast<NullEffect*>(item) == 0);
            if( dynamic_cast<AndEffect*>(item) != 0 ) {
                AndEffect &item_list = *static_cast<AndEffect*>(item);
                for( size_t i = 0; i < item_list.size(); ++i)
                    effects.push_back(item_list[i]);
                item_list.clear();
                delete item;
            } else {
                effects.push_back(item);
            }
        }
    }

    // check if result can be reduced to null or single effect
    Effect *result = 0;
    if( !effects.empty() ) {
        if( effects.size() == 1 )
            result = const_cast<Effect*>(effects[0]);
        else
            result = new AndEffect(effects);
        effects.clear();
    }
    return result;
}

bool PDDL_Base::AndEffect::has_free_variables(const var_symbol_vec &param, bool dont_extend) const {
    for( size_t k = 0; k < size(); ++k ) {
        if( (*this)[k]->has_free_variables(param, dont_extend) )
            return true;
    }
    return false;
}

bool PDDL_Base::AndEffect::is_strongly_static(const PredicateSymbol &p) const {
    bool strongly_static = true;
    for( size_t k = 0; strongly_static && (k < size()); ++k )
        strongly_static = (*this)[k]->is_strongly_static(p);
    return strongly_static;
}

void PDDL_Base::AndEffect::extract_atoms(unsigned_atom_set &atoms, bool only_affected) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->extract_atoms(atoms, only_affected);
}

string PDDL_Base::AndEffect::to_string() const {
    string str("(and");
    for( size_t k = 0; k < size(); ++k )
        str += " " + (*this)[k]->to_string();
    return str + ")";
}

void PDDL_Base::ConditionalEffect::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    const_cast<Condition*>(condition_)->remap_parameters(old_param, new_param);
    const_cast<Effect*>(effect_)->remap_parameters(old_param, new_param);
}

void PDDL_Base::ConditionalEffect::emit(Instance &ins, index_set &eff, Instance::when_vec &when) const {
    Instance::When single_when;
    condition_->emit(ins, single_when.condition_);
    effect_->emit(ins, single_when.effect_, when);
    when.push_back(single_when);
}

PDDL_Base::Effect* PDDL_Base::ConditionalEffect::ground(bool clone_variables, bool replace_static_values) const {
    Effect *result = 0;
    Effect *grounded_effect = effect_->ground(clone_variables, replace_static_values);
    if( grounded_effect != 0 ) {
        Condition *grounded_condition = condition_->ground(clone_variables, false, replace_static_values);
        if( dynamic_cast<Constant*>(grounded_condition) != 0 ) {
            bool value = static_cast<Constant*>(grounded_condition)->value_;
            delete grounded_condition;
            if( value )
                result = grounded_effect;
            else
                delete grounded_effect;
        } else {
            result = new ConditionalEffect(grounded_condition, grounded_effect);
        }
    }
    return result;
}

bool PDDL_Base::ConditionalEffect::has_free_variables(const var_symbol_vec &param, bool dont_extend) const {
    return condition_->has_free_variables(param, dont_extend) || effect_->has_free_variables(param, dont_extend);
}

bool PDDL_Base::ConditionalEffect::is_strongly_static(const PredicateSymbol &p) const {
    return effect_->is_strongly_static(p);
}

void PDDL_Base::ConditionalEffect::extract_atoms(unsigned_atom_set &atoms, bool only_affected) const {
    if( !only_affected ) condition_->extract_atoms(atoms);
    effect_->extract_atoms(atoms, only_affected);
}

string PDDL_Base::ConditionalEffect::to_string() const {
    string str;
    str += "(when " + condition_->to_string() + " " + effect_->to_string() + ")";
    return str;
}

void PDDL_Base::ForallEffect::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    const_cast<Effect*>(effect_)->remap_parameters(old_param, new_param);
}

void PDDL_Base::ForallEffect::emit(Instance &ins, index_set &eff, Instance::when_vec &when) const {
    cout << Utils::error() << "emit() should not be called on ForallEffect: first ground the effect!" << endl;
    exit(255);
}

PDDL_Base::Effect* PDDL_Base::ForallEffect::ground(bool clone_variables, bool replace_static_values) const {
    clone_variables_stack_.push_back(clone_variables);
    result_stack_.push_back(new AndEffect);
    enumerate(true);
    result_stack_.back()->reserve(count_);
    enumerate();
    AndEffect *result = result_stack_.back();
    result_stack_.pop_back();
    clone_variables_stack_.pop_back();

    // check if result can be reduced to null or single effect
    if( result->empty() ) {
        delete result;
        return 0;
    } else if( result->size() == 1 ) {
        Effect *single = const_cast<Effect*>((*result)[0]);
        result->clear();
        delete result;
        return single;
    } else {
        return result;
    }
}

void PDDL_Base::ForallEffect::process_instance() const {
    Condition *such_that = 0;
    if( such_that_ != 0 ) such_that = such_that_->ground(false, false, true);
    if( (such_that_ == 0) || (dynamic_cast<const Constant*>(such_that) != 0) ) {
        const Constant *constant = static_cast<const Constant*>(such_that);
        if( (such_that_ == 0) || constant->value_ ) {
            Effect *item = effect_->ground(clone_variables_stack_.back());
            if( item != 0 ) {
                assert(dynamic_cast<NullEffect*>(item) == 0);
                if( dynamic_cast<AndEffect*>(item) != 0 ) {
                    AndEffect &item_list = *static_cast<AndEffect*>(item);
                    for( size_t i = 0; i < item_list.size(); ++i)
                        result_stack_.back()->push_back(item_list[i]);
                    item_list.clear();
                    delete item;
                } else {
                    result_stack_.back()->push_back(item);
                }
            }
        }
    } else if( such_that_ != 0 ) {
        cout << Utils::error() << "condition '" << *such_that_
             << "' in such-that statement must ground to constant value" << endl;
    }
    if( such_that_ != 0 ) delete such_that;
}

bool PDDL_Base::ForallEffect::has_free_variables(const var_symbol_vec &param, bool dont_extend) const {
    var_symbol_vec nparam(param);
    if( !dont_extend ) nparam.insert(nparam.end(), param_.begin(), param_.end());
    return effect_->has_free_variables(nparam, dont_extend);
}

bool PDDL_Base::ForallEffect::is_strongly_static(const PredicateSymbol &p) const {
    return effect_->is_strongly_static(p);
}

void PDDL_Base::ForallEffect::extract_atoms(unsigned_atom_set &atoms, bool only_affected) const {
    cout << Utils::error() << "extract_atoms() should not be called on ForallEffect: first ground the effect!" << endl;
    exit(255);
}

string PDDL_Base::ForallEffect::to_string() const {
    string str("(forall (");
    for( size_t k = 0; k < param_.size(); ++k )
        str += (k > 0 ? " " : "") + param_[k]->to_string();
    str += ")";
    if( such_that_ != 0 ) {
        str += " such-that ";
        str += such_that_->to_string();
    }
    return str + " " + effect_->to_string() + ")";
}

PDDL_Base::SensingModel* PDDL_Base::SensingModelForStateVariable::ground(bool, bool) const {
    // ground variable
    SensingModelForStateVariable *model = new SensingModelForStateVariable;
    if( !finished_grounding_ ) {
        model->variable_name_ = string("(") + variable_->print_name_;
        for( size_t k = 0; k < param_.size(); ++k )
            model->variable_name_ += " " + param_[k]->to_string();
        model->variable_name_ += ")";
    } else {
        model->variable_ = variable_;
        model->finished_grounding_ = true;
    }
    return model;
}

void PDDL_Base::SensingModelForStateVariable::finish_grounding(PDDL_Base *base) {
    // look for observable state variable in base
    if( !finished_grounding_ ) {
        for( size_t k = 0; k < base->lw1_variables_.size(); ++k ) {
            Variable &var = *base->lw1_variables_[k];
            if( var.is_state_variable() && (variable_name_ == var.print_name_) ) {
                StateVariable &variable = *static_cast<StateVariable*>(&var);
                variable.is_observable_ = true;
                variable_ = &variable;
                finished_grounding_ = true;
                break;
            }
        }
        if( !finished_grounding_ )
            cout << Utils::error() << "sensed state variable '" << variable_name_ << "' not found" << endl;
    }
    finished_grounding_ = true;
}

bool PDDL_Base::SensingModelForStateVariable::verify(const PDDL_Base *base) const {
    return variable_ != 0;
}

PDDL_Base::SensingModel* PDDL_Base::SensingModelForStateVariable::reduce(const unsigned_atom_set &atoms_to_remove) const {
    return 0;
}

void PDDL_Base::SensingModelForStateVariable::extract_atoms(unsigned_atom_set &atoms, bool only_sensed_atoms, bool only_affected_atoms) const {
    // \emptyset = affected \subset sensed = all = { all atoms in variable's domain }
    if( !only_affected_atoms ) {
        // include all atoms in variable domains
        if( variable_ == 0 ) {
            cout << Utils::error() << "internal state variable is null. Look for previous error(s)." << endl;
            return;
        }
        atoms.insert(variable_->grounded_domain_.begin(), variable_->grounded_domain_.end());
    }
}

string PDDL_Base::SensingModelForStateVariable::to_string() const {
    if( variable_ == 0 )
        return string("[incomplete-grounding substitute variable '") + variable_name_ + "']";
    else
        return string("(state-variable ") + variable_->print_name_ + ")";
}

bool PDDL_Base::SensingModelForObservableVariable::is_strongly_static(const PredicateSymbol &p) const {
    return literal_->is_strongly_static(p);
}

PDDL_Base::SensingModel* PDDL_Base::SensingModelForObservableVariable::ground(bool clone_variables, bool replace_static_values) const {
    // ground variable
    SensingModelForObservableVariable *model = new SensingModelForObservableVariable;
    if( !finished_grounding_ ) {
        model->variable_name_ = string("(") + variable_->print_name_;
        for( size_t k = 0; k < param_.size(); ++k )
            model->variable_name_ += " " + param_[k]->to_string();
        model->variable_name_ += ")";
    } else {
        model->variable_ = variable_;
        model->finished_grounding_ = true;
    }

    // ground literal and dnf
    Condition *grounded_literal = literal_->ground(clone_variables, false, replace_static_values);
    assert(dynamic_cast<Literal*>(grounded_literal) != 0);
    model->literal_ = static_cast<Literal*>(grounded_literal);
    model->dnf_ = dnf_->ground(clone_variables, false, replace_static_values);
    //cout << "grounded: " << flush << *model << endl;
    return model;
}

void PDDL_Base::SensingModelForObservableVariable::finish_grounding(PDDL_Base *base) {
    // look for observable variable in base
    if( !finished_grounding_ ) {
        for( size_t k = 0; k < base->lw1_variables_.size(); ++k ) {
            Variable &var = *base->lw1_variables_[k];
            if( !var.is_state_variable() && (variable_name_ == var.print_name_) ) {
                ObsVariable &variable = *static_cast<ObsVariable*>(&var);
                variable_ = &variable;
                finished_grounding_ = true;
                break;
            }
        }
        if( !finished_grounding_ )
            cout << Utils::error() << "sensed observable variable '" << variable_name_ << "' not found" << endl;
    }
    finished_grounding_ = true;
}

bool PDDL_Base::SensingModelForObservableVariable::verify(const PDDL_Base *base) const {
    bool return_value = variable_ != 0;

    // check that literal is value of observable variable
    if( variable_ != 0 ) {
        string literal_name = literal_->to_string();
        if( variable_->is_binary() ) {
            const Atom &value = *variable_->grounded_domain_.begin();
            if( (value.to_string() != literal_name) && (string("(not ") + value.to_string() + ")" != literal_name) ) {
                cout << Utils::error() << "value '" << literal_name
                     << "' doesn't belong to domain of '" << *variable_ << "'" << endl;
                return_value = false;
            }
        } else {
            bool value_found = false;
            for( unsigned_atom_set::const_iterator it = variable_->grounded_domain_.begin(); it != variable_->grounded_domain_.end(); ++it ) {
                if( it->to_string() == literal_name ) {
                    value_found = true;
                    break;
                }
            }
            if( !value_found ) {
                cout << Utils::error() << "value '" << literal_name
                     << "' doesn't belong to domain of '" << *variable_ << "'" << endl;
                return_value = false;
            }
        }
    }

    // check format of DNF
    bool in_dnf = dnf_->is_dnf();
    if( !in_dnf ) {
        if( base->options_.is_enabled("lw1:sensing:make-dnf") ) {
            cout << Utils::yellow() << "transforming reduced formula '" << *dnf_
                 << "' for model of '" << *(const Atom*)literal_ << "' into dnf"
                 << Utils::normal() << endl;
            const Condition *new_dnf = dnf_->as_dnf();
            cout << "result is '" << *new_dnf << "'" << endl;
            delete dnf_;
            const_cast<SensingModelForObservableVariable*>(this)->dnf_ = new_dnf;
            assert(dnf_->is_dnf());
            in_dnf = true;
        } else {
            cout << Utils::error() << "reduced formula '" << *dnf_
                 << "' for model of '" << *(const Atom*)literal_ << "' isn't dnf! "
                 << Utils::red() << "(discarding sensing model)" << Utils::normal() << endl;
            return_value = false;
        }
    }

    if( in_dnf && !dnf_->is_dnf(true, base) ) {
        cout << Utils::warning() << "reduced dnf '" << *dnf_
             << "' for model of '" << *(const Atom*)literal_ << "' isn't positive!" << endl;
    }

    return return_value;
}

bool PDDL_Base::SensingModelForObservableVariable::is_grounded() const {
    return literal_->is_grounded() && dnf_->is_grounded();
}

PDDL_Base::SensingModel* PDDL_Base::SensingModelForObservableVariable::reduce(const unsigned_atom_set &atoms_to_remove) const {
    assert(literal_->is_grounded());
    assert(dnf_->is_grounded());
    if( dynamic_cast<const Constant*>(dnf_) != 0 ) {
#ifndef NDEBUG
        const Constant *constant = static_cast<const Constant*>(dnf_);
        assert(constant->value_);
#endif
    }
    return atoms_to_remove.find(*literal_) != atoms_to_remove.end() ? 0 : copy_and_simplify();
}

void PDDL_Base::SensingModelForObservableVariable::extract_atoms(unsigned_atom_set &atoms, bool only_sensed_atoms, bool only_affected_atoms) const {
    // affected = sensed \subset all = { sensed + all atoms in model }
    literal_->extract_atoms(atoms);
    if( !only_sensed_atoms && !only_affected_atoms)
        dnf_->extract_atoms(atoms);
}

void PDDL_Base::SensingModelForObservableVariable::extend_beam_for_variable(Variable &var) const {
    if( var.grounded_domain_.find(*literal_) != var.grounded_domain_.end() ) {
        unsigned_atom_set context;
        dnf_->extract_atoms(context);
        var.beam_[*literal_].insert(context.begin(), context.end());
    }
}

void PDDL_Base::SensingModelForObservableVariable::extract_sensing_model_for_atom(const Atom &atom, vector<const SensingModelForObservableVariable*> &models) const {
    if( atom == *literal_ ) models.push_back(copy_and_simplify());
}

PDDL_Base::Effect* PDDL_Base::SensingModelForObservableVariable::as_effect() const {
    assert(is_grounded());
    vector<const Condition*> conditions;
    if( dynamic_cast<const Or*>(dnf_) != 0 ) {
        const Or *disjunction = static_cast<const Or*>(dnf_);
        for( size_t k = 0; k < disjunction->size(); ++k ) {
            const Condition *disjunct = (*disjunction)[k];
            conditions.push_back(disjunct->copy_and_simplify());
        }
    } else if( dynamic_cast<const And*>(dnf_) != 0 ) {
        conditions.push_back(dnf_->copy_and_simplify());
    } else if( dynamic_cast<const Literal*>(dnf_) != 0 ) {
        conditions.push_back(dnf_->copy_and_simplify());
    } else if( dynamic_cast<const Constant*>(dnf_) != 0 ) {
        assert(static_cast<const Constant*>(dnf_)->value_);
    } else {
        cout << Utils::error() << "expecting dnf; got '" << *dnf_ << "'" << endl;
    }
    AndEffect *effect = new AndEffect;
    for( size_t k = 0; k < conditions.size(); ++k ) {
        const Condition *condition = conditions[k];
        AtomicEffect *head = new AtomicEffect(*literal_);
        effect->push_back(new ConditionalEffect(condition, head));
    }
    return effect;
}

string PDDL_Base::SensingModelForObservableVariable::to_string() const {
    string str("(model-for ");
    str += variable_name_ == "" ? string("(null)") : variable_name_;
    str += " " + literal_->to_string() + " " + dnf_->to_string() + ")";
    return str;
}

string PDDL_Base::sensing_proxy_vec::to_string() const {
    string str("(sensing-proxy-list");
    for( size_t k = 0; k < size(); ++k )
        str += " " + (*this)[k]->to_string();
    return str + ")";
}

PDDL_Base::Sensing* PDDL_Base::sensing_proxy_vec::ground(bool clone_variables, bool replace_static_values) const {
    Sensing *sensing = new Sensing;
    for( size_t k = 0; k < size(); ++k ) {
        Sensing *s = (*this)[k]->ground(clone_variables, replace_static_values);
        for( size_t i = 0; i < s->size(); ++i )
            sensing->push_back((*s)[i]);
        s->clear();
        delete s;
    }
    return sensing;
}

PDDL_Base::Sensing* PDDL_Base::BasicSensingModel::ground(bool clone_variables, bool replace_static_values) const {
    Sensing *sensing = new Sensing;
    sensing->push_back(sensing_model_->ground(clone_variables, replace_static_values));
    return sensing;
}

void PDDL_Base::ForallSensing::process_instance() const {
    Condition *such_that = 0;
    if( such_that_ != 0 ) such_that = such_that_->ground(false, false, true);
    if( (such_that_ == 0) || (dynamic_cast<const Constant*>(such_that) != 0) ) {
        const Constant *constant = static_cast<const Constant*>(such_that);
        if( (such_that_ == 0) || constant->value_ ) {
            Sensing *sensing = sensing_.ground(clone_variables_stack_.back(), replace_static_values_stack_.back());
            if( sensing != 0 ) {
                for( size_t k = 0; k < sensing->size(); ++k )
                    result_stack_.back()->push_back((*sensing)[k]);
                sensing->clear();
                delete sensing;
            }
        }
    } else if( such_that_ != 0 ) {
        cout << Utils::error() << "condition '" << *such_that_
             << "' in such-that statement must ground to constant value" << endl;
    }
    if( such_that_ != 0 ) delete such_that;
}

bool PDDL_Base::ForallSensing::is_strongly_static(const PredicateSymbol &p) const {
    for( size_t k = 0; k < sensing_.size(); ++k ) {
        if( !sensing_[k]->is_strongly_static(p) )
            return false;
    }
    return true;
}

PDDL_Base::Sensing* PDDL_Base::ForallSensing::ground(bool clone_variables, bool replace_static_values) const {
    clone_variables_stack_.push_back(clone_variables);
    replace_static_values_stack_.push_back(replace_static_values);
    result_stack_.push_back(new Sensing);
    enumerate(true);
    result_stack_.back()->reserve(count_);
    enumerate();
    Sensing *sensing = result_stack_.back();
    result_stack_.pop_back();
    clone_variables_stack_.pop_back();
    replace_static_values_stack_.pop_back();
    return sensing;
}

string PDDL_Base::ForallSensing::to_string() const {
    string str("(forall (");
    for( size_t k = 0; k < param_.size(); ++k )
        str += (k > 0 ? " " : "") + param_[k]->to_string();
    str += ")";
    if( such_that_ != 0 ) {
        str += " such-that ";
        str += such_that_->to_string();
    }
    for( size_t k = 0; k < sensing_.size(); ++k )
        str += " " + sensing_[k]->to_string();
    return str + ")";
}

bool PDDL_Base::Sensing::is_strongly_static(const PredicateSymbol &p) const {
    for( size_t k = 0; k < size(); ++k ) {
        if( !(*this)[k]->is_strongly_static(p) )
            return false;
    }
    return true;
}

PDDL_Base::Sensing* PDDL_Base::Sensing::ground(bool clone_variables, bool replace_static_values) const {
    Sensing *grounded_sensing = new Sensing;
    for( size_t k = 0; k < size(); ++k )
        grounded_sensing->push_back((*this)[k]->ground(clone_variables, replace_static_values));
    return grounded_sensing;
}

bool PDDL_Base::Sensing::finish_grounding(PDDL_Base *base) {
    bool verify = true;
    vector<const SensingModel*> result;
    for( size_t k = 0; k < size(); ++k ) {
        const_cast<SensingModel*>((*this)[k])->finish_grounding(base);
        if( (*this)[k]->verify(base) ) {
            result.push_back((*this)[k]);
        } else {
            delete (*this)[k];
            verify = false;
        }
    }

    // verify that every value of sensed observable variable has a model

    // 1. Collect sensed observable variables
    set<const ObsVariable*> variables;
    map<string, set<string> > sensed_values_for_var;
    map<pair<string, string>, string> model_for_sensed_value_for_var;
    for( size_t k = 0; k < result.size(); ++k ) {
        if( dynamic_cast<const SensingModelForObservableVariable*>(result[k]) != 0 ) {
            const SensingModelForObservableVariable *model = static_cast<const SensingModelForObservableVariable*>(result[k]);
            assert(model->variable_ != 0);
            const ObsVariable &var = *model->variable_;
            variables.insert(&var);
            sensed_values_for_var[var.to_string()].insert(model->literal_->to_string());
            model_for_sensed_value_for_var[make_pair(var.to_string(), model->literal_->to_string())] = model->dnf_->to_string();
        }
    }

    // 2. Check that every value has a model
    for( set<const ObsVariable*>::const_iterator it = variables.begin(); it != variables.end(); ++it ) {
        const ObsVariable &var = **it;
        string varname = var.to_string();
        if( var.is_binary() ) {
            string value = var.grounded_domain_.begin()->to_string();
            string not_value = string("(not ") + value + ")";
            if( sensed_values_for_var[varname].find(value) == sensed_values_for_var[varname].end() ) {
                map<pair<string, string>, string>::const_iterator it = model_for_sensed_value_for_var.find(make_pair(varname, not_value));
                if( (it == model_for_sensed_value_for_var.end()) || (it->second != "true") ) {
                    cout << Utils::error() << "no sensing model for value '" << value
                         << "' of variable '" << var << "'" << endl;
                }
            }
            if( sensed_values_for_var[varname].find(not_value) == sensed_values_for_var[varname].end() ) {
                map<pair<string, string>, string>::const_iterator it = model_for_sensed_value_for_var.find(make_pair(varname, value));
                if( (it == model_for_sensed_value_for_var.end()) || (it->second != "true") ) {
                    cout << Utils::error() << "no sensing model for value '" << not_value
                         << "' of variable '" << var << "'" << endl;
                }
            }
        } else {
            for( unsigned_atom_set::const_iterator jt = var.grounded_domain_.begin(); jt != var.grounded_domain_.end(); ++jt ) {
                string value = jt->to_string();
                if( sensed_values_for_var[varname].find(value) == sensed_values_for_var[varname].end() ) {
                    cout << Utils::error() << "no sensing model for value '" << value
                         << "' of variable '" << var << "'" << endl;
                }
            }
        }
    }

    // 3. Remove models with 'false' dnf
    for( int k = 0; k < (int)result.size(); ++k ) {
        if( dynamic_cast<const SensingModelForObservableVariable*>(result[k]) != 0 ) {
            const SensingModelForObservableVariable *model = static_cast<const SensingModelForObservableVariable*>(result[k]);
            if( dynamic_cast<const Constant*>(model->dnf_) != 0 ) {
                const Constant *constant = static_cast<const Constant*>(model->dnf_);
                if( !constant->value_ ) {
                    delete result[k];
                    result[k] = result.back();
                    result.pop_back();
                    --k;
                }
            }
        }
    }

    // set result and return
    *static_cast<vector<const SensingModel*>*>(this) = result;
    return verify;
}

bool PDDL_Base::Sensing::is_grounded() const {
    for( size_t k = 0; k < size(); ++k ) {
        if( !(*this)[k]->is_grounded() )
            return false;
    }
    return true;
}

PDDL_Base::Sensing* PDDL_Base::Sensing::reduce(const unsigned_atom_set &atoms_to_remove) const {
    Sensing *reduced_sensing = new Sensing;
    for( size_t k = 0; k < size(); ++k ) {
        const SensingModel *model = (*this)[k];
        SensingModel *reduced_model = model->reduce(atoms_to_remove);
        if( reduced_model != 0 ) reduced_sensing->push_back(reduced_model);
    }

    if( reduced_sensing->empty() ) {
        delete reduced_sensing;
        reduced_sensing = 0;
    }
    return reduced_sensing;
}

void PDDL_Base::Sensing::extract_atoms(unsigned_atom_set &atoms, bool only_sensed_atoms, bool only_affected_atoms) const {
    for( size_t k = 0; k < size(); ++k ) {
        const SensingModel *model = (*this)[k];
        model->extract_atoms(atoms, only_sensed_atoms, only_affected_atoms);
    }
}

void PDDL_Base::Sensing::extend_beam_for_variable(Variable &var) const {
    for( size_t k = 0; k < size(); ++k ) {
        const SensingModel *model = (*this)[k];
        model->extend_beam_for_variable(var);
    }
}

void PDDL_Base::Sensing::extract_sensing_model_for_atom(const Atom &atom, vector<const SensingModelForObservableVariable*> &models) const {
    for( size_t k = 0; k < size(); ++k ) {
        const SensingModel *model = (*this)[k];
        model->extract_sensing_model_for_atom(atom, models);
    }
}

PDDL_Base::Effect* PDDL_Base::Sensing::as_effect() const {
    assert(is_grounded());
    AndEffect *effect = new AndEffect;
    for( size_t k = 0; k < size(); ++k ) {
        const SensingModel *model = (*this)[k];
        effect->push_back(model->as_effect());
    }
    return effect;
}

string PDDL_Base::Sensing::to_string() const {
    string str("(");
    for( size_t k = 0; k < size(); ++k ) {
        str += (*this)[k]->to_string();
        if( k + 1 < size() ) str += " ";
    }
    return str + ")";
}

void PDDL_Base::Invariant::process_instance() const {
    Invariant invariant(type_);
    invariant.reserve(size());
    for( size_t k = 0; k < size(); ++k )
        invariant.push_back((*this)[k]->ground());

    if( invariant.Xeduce() == GOOD ) {
        invariant_list_ptr_->push_back(new Invariant(invariant));
        invariant.clear();
    }
}

void PDDL_Base::Invariant::clear() {
    condition_vec::clear();
    Xprecondition_ = 0;
}

PDDL_Base::Invariant::status_t PDDL_Base::Invariant::Xeduce() {
    condition_vec to_remove;
    status_t status = GOOD;
    bool remove_invariant = false;
    Invariant reduced_invariant(type_);
    for( size_t k = 0; k < size(); ++k ) {
        const Condition *condition = (*this)[k];
        if( dynamic_cast<const Constant*>(condition) ) {
            bool value = static_cast<const Constant*>(condition)->value_;
            to_remove.push_back(condition);
            if( value ) {
                //cout << "Removing invariant " << *this << " because is tautological" << endl;
                remove_invariant = true;
            } else {
                //cout << "Pruning condition " << *condition << "because is false" << endl;
            }
        } else if( dynamic_cast<const Literal*>(condition) ) {
            reduced_invariant.push_back(condition);
        } else if( dynamic_cast<const And*>(condition) ) {
            status = RECOVERABLE; // temporal status, final status is determined below
            const And &conjunction = *static_cast<const And*>(condition);
            for( size_t i = 0; i < conjunction.size(); ++i ) {
                if( dynamic_cast<const Literal*>(conjunction[i]) == 0 ) {
                    status = BAD; // this invariant is no longer recoverable
                    break;
                }
            }
            if( status == RECOVERABLE ) reduced_invariant.push_back(condition);
        } else {
            cout << Utils::warning() << "invariant must be clause at time of instantiation (skipping): got " << *condition << endl;
            remove_invariant = true;
            to_remove.push_back(condition);
            //exit(255);
        }
    }

    clear();
    if( (status != BAD) && reduced_invariant.empty() ) {
        status = EMPTY;
    } else if( (status != BAD) && !remove_invariant ) {
        assert((status == GOOD) || (status == RECOVERABLE));
        if( (status == GOOD) || (reduced_invariant.size() == 2) ) {
            *this = reduced_invariant;
            reduced_invariant.clear();
        } else {
            status = BAD;
        }
    } else {
        status = BAD;
    }
    return status;
}

string PDDL_Base::Invariant::to_string() const {
    string str;
    if( type_ == AT_LEAST_ONE ) str += "(at-least-one";
    else if( type_ == AT_MOST_ONE ) str +=  "(at-most-one";
    else str += "(exactly-one";

    if( !param_.empty() ) {
        str += " (";
        for( size_t k = 0; k < param_.size(); ++k )
            str += (k > 0 ? " " : "") + param_[k]->to_string();
        str += ")";
    }

    if( Xprecondition_ != 0 ) {
        str += " (:precondition " + Xprecondition_->to_string() + ")";
    }

    for( size_t k = 0; k < size(); ++k )
        str += " " + (*this)[k]->to_string();
    return str + ")";
}

bool PDDL_Base::Invariant::has_free_variables() const {
    for( size_t k = 0; k < size(); ++k ) {
        if( (*this)[k]->has_free_variables(param_) )
            return true;
    }
    return false;
}

void PDDL_Base::Clause::emit(Instance &ins, Instance::Clause &clause) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        Instance::Atom *p = lit->find_prop(ins, false, true);
        if( !lit->negated_ )
            clause.push_back(1 + p->index_);
        else
            clause.push_back(-(1 + p->index_));
    }
}

string PDDL_Base::Clause::to_string() const {
    string str("(or");
    for( size_t k = 0; k < size(); ++k )
        str += " " + (*this)[k]->to_string();
    return str + ")";
}

void PDDL_Base::Oneof::emit(Instance &ins, Instance::Oneof &oneof) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        Instance::Atom *p = lit->find_prop(ins, false, true);
        if( !lit->negated_ )
            oneof.push_back(1 + p->index_);
        else
            oneof.push_back(-(1 + p->index_));
    }
}

string PDDL_Base::Oneof::to_string() const {
    string str("(oneof");
    for( size_t k = 0; k < size(); ++k )
        str += " " + (*this)[k]->to_string();
    return str + ")";
}

void PDDL_Base::Unknown::process_instance() const {
    cout << Utils::internal_error() << "call to PDDL_Base::Unknown::process_instance()" << endl;
    exit(255);
}

string PDDL_Base::Unknown::to_string() const {
    return string("(unknown ") + Atom::to_string() + ")";
}

void PDDL_Base::InitLiteral::emit(Instance &ins, Instance::Init &state) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !negated_ ) {
        state.literals_.insert(1 + p->index_);
    } else {
        state.literals_.insert(-(1 + p->index_));
    }
}

void PDDL_Base::InitLiteral::instantiate(init_element_list &ilist) const {
    Atom *atom = ground(false);
    ilist.push_back(new InitLiteral(*atom));
    delete atom;
}

void PDDL_Base::InitLiteral::emit(Instance &ins) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !negated_ ) {
        ins.init_.literals_.insert(1 + p->index_);
    } else {
        ins.init_.literals_.insert(-(1 + p->index_));
    }
}

bool PDDL_Base::InitLiteral::is_strongly_static(const PredicateSymbol &p) const {
    return true;
}

void PDDL_Base::InitLiteral::extract_atoms(unsigned_atom_set &atoms) const {
    atoms.insert(*this);
}

void PDDL_Base::InitInvariant::instantiate(init_element_list &ilist) const {
    assert(!Invariant::has_free_variables());
    list<Invariant*> invariant_list;
    invariant_list_ptr_ = &invariant_list;
    enumerate();
    for( list<Invariant*>::iterator it = invariant_list.begin(); it != invariant_list.end(); ++it ) {
        ilist.push_back(new InitInvariant(**it));
        (*it)->clear();
        delete *it;
    }
}

void PDDL_Base::InitInvariant::emit(Instance &ins) const {

    // construct invariant
    Instance::Invariant typed_invariant(type_);
    for( size_t k = 0; k < size(); ++k ) {
        assert(dynamic_cast<const Literal*>((*this)[k]) != 0);
        const Literal &literal = *static_cast<const Literal*>((*this)[k]);
        Instance::Atom *p = literal.find_prop(ins, false, true);
        if( !literal.negated_ )
            typed_invariant.push_back(1 + p->index_);
        else
            typed_invariant.push_back(-(1 + p->index_));
    }

    // construct precondition
    if( Xprecondition_ != 0 ) {
        And precondition;
        if( dynamic_cast<const Literal*>(Xprecondition_) != 0 ) {
            precondition.push_back(Xprecondition_);
        } else {
            assert(dynamic_cast<const And*>(Xprecondition_) != 0);
            const And &and_precondition = *static_cast<const And*>(Xprecondition_);
            precondition.insert(precondition.end(), and_precondition.begin(), and_precondition.end());
        }
        for( size_t k = 0; k < precondition.size(); ++k ) {
            assert(dynamic_cast<const Literal*>(precondition[k]) != 0);
            const Literal &literal = *static_cast<const Literal*>(precondition[k]);
            Instance::Atom *p = literal.find_prop(ins, false, true);
            if( !literal.negated_ )
                typed_invariant.Xprecondition_.insert(1 + p->index_);
            else
                typed_invariant.Xprecondition_.insert(-(1 + p->index_));
        }
        precondition.clear();
    }

    // emit invariant
    if( typed_invariant.type_ != EXACTLY_ONE ) {
        ins.init_.invariants_.push_back(typed_invariant);
    } else {
        Instance::Invariant at_least_one(AT_LEAST_ONE, typed_invariant);
        Instance::Invariant at_most_one(AT_MOST_ONE, typed_invariant);
        ins.init_.invariants_.push_back(at_least_one);
        ins.init_.invariants_.push_back(at_most_one);
    }
}

// TODO: fix strongly-static detection. It seems that only need to be checked
// for oneofs because invariants should not define initial states and clauses
// only filter states generated by oneofs.
bool PDDL_Base::InitInvariant::is_strongly_static(const PredicateSymbol &p) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        assert((lit->pred_->print_name_ != p.print_name_) || (lit->pred_ == &p));
        assert((lit->pred_->print_name_ == p.print_name_) || (lit->pred_ != &p));
        if( lit->pred_ == &p ) return false;
    }
    return true;
}

void PDDL_Base::InitInvariant::extract_atoms(unsigned_atom_set &atoms) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->extract_atoms(atoms);
}

void PDDL_Base::InitClause::instantiate(init_element_list &ilist) const {
    Clause clause;
    for( size_t k = 0; k < size(); ++k )
        clause.push_back((*this)[k]->ground());
    ilist.push_back(new InitClause(clause));
    clause.clear();
}

void PDDL_Base::InitClause::emit(Instance &ins) const {
    Instance::Clause clause;
    Clause::emit(ins, clause);
    ins.init_.clauses_.push_back(clause);
}

bool PDDL_Base::InitClause::is_strongly_static(const PredicateSymbol &p) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        assert((lit->pred_->print_name_ != p.print_name_) || (lit->pred_ == &p));
        assert((lit->pred_->print_name_ == p.print_name_) || (lit->pred_ != &p));
        if( lit->pred_ == &p ) return false;
    }
    return true;
}

void PDDL_Base::InitClause::extract_atoms(unsigned_atom_set &atoms) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->extract_atoms(atoms);
}

void PDDL_Base::InitOneof::instantiate(init_element_list &ilist) const {
    Oneof oneof;
    for( size_t k = 0; k < size(); ++k )
        oneof.push_back((*this)[k]->ground());
    ilist.push_back(new InitOneof(oneof));
    oneof.clear();
}

void PDDL_Base::InitOneof::emit(Instance &ins) const {
    Instance::Oneof oneof;
    Oneof::emit(ins, oneof);
    ins.init_.oneofs_.push_back(oneof);
}

bool PDDL_Base::InitOneof::is_strongly_static(const PredicateSymbol &p) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        assert((lit->pred_->print_name_ != p.print_name_) || (lit->pred_ == &p));
        assert((lit->pred_->print_name_ == p.print_name_) || (lit->pred_ != &p));
        if( lit->pred_ == &p ) return false;
    }
    return true;
}

void PDDL_Base::InitOneof::extract_atoms(unsigned_atom_set &atoms) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->extract_atoms(atoms);
}

void PDDL_Base::InitUnknown::instantiate(init_element_list &ilist) const {
    cout << Utils::internal_error() << "call to PDDL_Base::InitUnknown::instantiate()" << endl;
    exit(255);
}

void PDDL_Base::InitUnknown::emit(Instance &ins) const {
    cout << Utils::internal_error() << "call to PDDL_Base::InitUnknown::emit()" << endl;
    exit(255);
}

bool PDDL_Base::InitUnknown::is_strongly_static(const PredicateSymbol &p) const {
    cout << Utils::internal_error() << "call to PDDL_Base::InitUnknown::is_strongly_static()" << endl;
    exit(255);
}

void PDDL_Base::InitUnknown::extract_atoms(unsigned_atom_set &atoms) const {
    cout << Utils::internal_error() << "call to PDDL_Base::InitUnknown::extract_atoms()" << endl;
    exit(255);
}

bool PDDL_Base::Action::is_special_action() const {
    return (strncmp(print_name_, "post-action-", 12) == 0) || (strncmp(print_name_, "drule-", 6) == 0);
}

void PDDL_Base::Action::instantiate(action_list &alist) const {
    size_t base_count = alist.size();
    action_list_ptr_ = &alist;
    cout << "instantiating action '" << print_name_ << "' ..." << flush;
    enumerate();
    cout << " " << alist.size() - base_count  << " action(s)";
    if( alist.size() - base_count == 0 ) cout << " [" << Utils::warning() << "no action instantiated!]";
    cout << endl;
}

void PDDL_Base::Action::emit(Instance &ins) const {
    PDDL_Name name(this, param_, param_.size());
    Instance::Action &act = ins.new_action(new CopyName(name.to_string(true)));
    act.cost_ = 1;
    //cout << "fully instantiated action " << name << endl;
    if( precondition_ != 0 ) {
        precondition_->emit(ins, act.precondition_);
        //cout << "    pre=" << *precondition_ << endl;
    }
    if( effect_ != 0 ) {
        effect_->emit(ins, act.effect_, act.when_);
        //cout << "    eff=" << *effect_ << endl;
    }
    act.comment_ = comment_;
}

void PDDL_Base::Action::process_instance() const {
    Condition *grounded_precondition = 0;
    if( precondition_ != 0 ) {
        grounded_precondition = precondition_->ground();
        if( dynamic_cast<Constant*>(grounded_precondition) != 0 ) {
            Constant *precondition_value = static_cast<Constant*>(grounded_precondition);
            if( !precondition_value->value_ ) {
                delete grounded_precondition;
                return;
            } else {
                grounded_precondition = 0;
            }
        }
    }

    PDDL_Name name(this, param_, param_.size());
    Action *action = new Action(strdup(name.to_string(true).c_str()));
    action->precondition_ = grounded_precondition;
    if( effect_ != 0 ) action->effect_ = effect_->ground();
    if( observe_ != 0 ) action->observe_ = observe_->ground();
    if( sensing_proxy_ != 0 ) action->sensing_ = sensing_proxy_->ground();
    action_list_ptr_->push_back(action);
    //cout << *action;
}

void PDDL_Base::Action::print(ostream &os) const {
    os << "(:action " << print_name_ << endl;

    if( !param_.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param_.size(); ++k )
            os << (k > 0 ? " " : "") << *param_[k];
        os << ")" << endl;
    }

    if( precondition_ != 0 ) os << "    :precondition " << *precondition_ << endl;
    if( effect_ != 0 ) os << "    :effect " << *effect_ << endl;
    if( observe_ != 0 ) os << "    :observe " << *observe_ << endl;
    if( sensing_ != 0 ) os << "    :sensing " << *sensing_ << endl;

    os << ")" << endl;
}

void PDDL_Base::Sensor::instantiate(sensor_list &slist) const {
    size_t base_count = slist.size();
    sensor_list_ptr_ = &slist;
    cout << "instantiating sensor '" << print_name_ << "' ..." << flush;
    enumerate();
    cout << " " << slist.size() - base_count << " sensor(s)";
    if( slist.size() - base_count == 0 ) cout << " [" << Utils::warning() << "no sensor instantiated!]";
    cout << endl;
}

void PDDL_Base::Sensor::emit(Instance &ins) const {
    PDDL_Name name(this, param_, param_.size());
    Instance::Sensor &sensor = ins.new_sensor(new CopyName(name.to_string(true)));
    //cout << "fully instantiated sensor " << name << endl;
    if( condition_ != 0 ) {
        condition_->emit(ins, sensor.condition_);
        //cout << "    :condition " << *condition_ << endl;
    }
    if( sense_ != 0 ) {
        sense_->emit(ins, sensor.sense_);
        //cout << "    :sense " << *sense_ << endl;
    }
}

void PDDL_Base::Sensor::process_instance() const {
    Condition *grounded_condition = 0;
    if( condition_ != 0 ) {
        grounded_condition = condition_->ground();
        if( dynamic_cast<Constant*>(grounded_condition) != 0 ) {
            Constant *condition_value = static_cast<Constant*>(grounded_condition);
            delete grounded_condition;
            if( !condition_value->value_ )
                return;
            else
                grounded_condition = 0;
        }
    }

    PDDL_Name name(this, param_, param_.size());
    Sensor *sensor = new Sensor(strdup(name.to_string(true).c_str()));
    sensor->condition_ = grounded_condition;
    if( sense_ != 0 ) sensor->sense_ = sense_->ground();
    sensor_list_ptr_->push_back(sensor);
}

void PDDL_Base::Sensor::print(ostream &os) const {
    os << "(:sensor " << print_name_ << endl;

    if( !param_.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param_.size(); ++k )
          os << (k > 0 ? " " : "") << *param_[k];
        os << ")" << endl;
    }

    if( condition_ != 0 ) {
        os << "    :condition " << *condition_ << endl;
    }

    assert(sense_ != 0);
    os << "    :sense " << *sense_ << endl
       << ")" << endl;
}

void PDDL_Base::Axiom::instantiate(axiom_list &alist) const {
    size_t base_count = alist.size();
    axiom_list_ptr_ = &alist;
    cout << "instantiating axiom '" << print_name_ << "' ..." << flush;
    enumerate();
    cout << " " << alist.size() - base_count << " axiom(s)";
    if( alist.size() - base_count == 0 ) cout << " [" << Utils::warning() << "no axiom instantiated!]";
    cout << endl;
}

void PDDL_Base::Axiom::emit(Instance &ins) const {
    PDDL_Name name(this, param_, param_.size());
    Instance::Axiom &axiom = ins.new_axiom(new CopyName(name.to_string(true)));
    //cout << "fully instantiated axiom " << name << endl;
    if( body_ != 0 ) {
        body_->emit(ins, axiom.body_);
        //cout << "    :body " << *body_ << endl;
    }
    if( head_ != 0 ) {
        head_->emit(ins, axiom.head_);
        //cout << "    :head " << *head_ << endl;
    }
}

void PDDL_Base::Axiom::process_instance() const {
    Condition *grounded_body = 0;
    if( body_ != 0 ) {
        grounded_body = body_->ground();
        if( dynamic_cast<Constant*>(grounded_body) != 0 ) {
            Constant *body_value = static_cast<Constant*>(grounded_body);
            delete grounded_body;
            if( !body_value->value_ )
                return;
            else
                grounded_body = 0;
        }
    }

    PDDL_Name name(this, param_, param_.size());
    Axiom *axiom = new Axiom(strdup(name.to_string(true).c_str()));
    axiom->body_ = grounded_body;
    if( head_ != 0 ) axiom->head_ = head_->ground();
    axiom_list_ptr_->push_back(axiom);
}

void PDDL_Base::Axiom::print(ostream &os) const {
    os << "(:axiom " << print_name_ << endl;

    if( !param_.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param_.size(); ++k )
          os << (k > 0 ? " " : "") << *param_[k];
        os << ")" << endl;
    }

    assert((body_ != 0) && (head_ != 0));
    os << "    :body " << *body_ << endl
       << "    :head " << *head_ << endl
       << ")" << endl;
}

void PDDL_Base::Observable::instantiate(observable_list &olist) const {
    Observable *grounded = new Observable;
    for( size_t k = 0; k < observables_.size(); ++k )
        grounded->observables_.push_back(observables_[k]->ground());
    olist.push_back(grounded);
}

void PDDL_Base::Observable::emit(Instance &ins) const {
    for( size_t k = 0; k < observables_.size(); ++k ) {
        assert(observables_[k]->is_grounded());
        observables_[k]->emit(ins, ins.given_observables_);
    }
}

void PDDL_Base::Observable::print(ostream &os) const {
    os << "(:observable";
    for( size_t k = 0; k < observables_.size(); ++k )
        os << " " << *observables_[k];
    os << ")";
}

void PDDL_Base::Sticky::instantiate(sticky_list &slist) const {
    Sticky *grounded = new Sticky;
    for( size_t k = 0; k < stickies_.size(); ++k )
        grounded->stickies_.push_back(stickies_[k]->ground());
    slist.push_back(grounded);
}

void PDDL_Base::Sticky::emit(Instance &ins) const {
    for( size_t k = 0; k < stickies_.size(); ++k ) {
        assert(stickies_[k]->is_grounded());
        stickies_[k]->emit(ins, ins.given_stickies_);
    }
}

void PDDL_Base::Sticky::print(ostream &os) const {
    os << "(:sticky" << endl;
    for( size_t k = 0; k < stickies_.size(); ++k )
        os << " " << *stickies_[k];
    os << ")";
}

void PDDL_Base::Variable::instantiate(variable_list &vlist) const {
    size_t base_count = vlist.size();
    variable_list_ptr_ = &vlist;
    cout << "instantiating variable '" << print_name_ << "' ..." << flush;
    enumerate();
    cout << " " << vlist.size() - base_count  << " variable(s)";
    if( vlist.size() - base_count == 0 ) cout << " [" << Utils::warning() << "no variable instantiated!]";
    cout << endl;
}

void PDDL_Base::Variable::process_instance() const {
    Condition *such_that = 0;
    if( such_that_ != 0 ) such_that = such_that_->ground(false, false, true);
    if( (such_that_ == 0) || (dynamic_cast<const Constant*>(such_that) != 0) ) {
        const Constant *constant = static_cast<const Constant*>(such_that);
        if( (such_that_ == 0) || constant->value_ ) {
            string variable_name("(");
            variable_name += print_name_;
            for( size_t k = 0; k < param_.size(); ++k )
                variable_name += " " + param_[k]->to_string();
            variable_name += ")";

            Variable *var = make_instance(strdup(variable_name.c_str()));
            var->grounded_ = true;
            variable_list_ptr_->push_back(var);

            for( size_t k = 0; k < domain_.size(); ++k ) {
                Effect *grounded_value = domain_[k]->ground(true); // clone_variables=true
                if( dynamic_cast<AtomicEffect*>(grounded_value) != 0 ) {
                    var->grounded_domain_.insert(*static_cast<AtomicEffect*>(grounded_value));
                } else if( dynamic_cast<AndEffect*>(grounded_value) != 0 ) {
                    AndEffect &item_list = *static_cast<AndEffect*>(grounded_value);
                    for( size_t i = 0; i < item_list.size(); ++i ) {
                        assert(dynamic_cast<const AtomicEffect*>(item_list[i]) != 0);
                        var->grounded_domain_.insert(*static_cast<const AtomicEffect*>(item_list[i]));
                    }
                } else {
                    cout << *domain_[k] << endl;
                    Effect *e = domain_[k]->ground(true); // clone_variables=true
                    cout << "grounded-ptr=" << e << endl;
                    cout << Utils::error() << "unrecognized format in variable '" << print_name_ << "'" << endl;
                    exit(255);
                }
                delete grounded_value;
            }
        }
    } else if( such_that_ != 0 ) {
        cout << Utils::error() << "condition '" << *such_that_
             << "' in such-that statement must ground to constant value" << endl;
    }
    if( such_that_ != 0 ) delete such_that;
}

string PDDL_Base::StateVariable::to_string(bool only_name, bool mangled) const {
    if( only_name || mangled ) {
        string str;
        if( mangled ) {
            if( print_name_[0] == '(' ) {
                str = string(print_name_).substr(1, strlen(print_name_) - 2);
                size_t pos = str.find(" ");
                while( pos != string::npos ) {
                    str.replace(pos, 1, "_");
                    pos = str.find(" ", pos);
                }
            } else {
                str = print_name_;
                for( size_t k = 0; k < domain_.size(); ++k )
                    str += "_" + domain_[k]->to_string();
            }
        } else {
            if( print_name_[0] == '(' ) {
                str = print_name_;
            } else {
                str = string("(") + print_name_;
                for( size_t k = 0; k < domain_.size(); ++k )
                    str += " " + domain_[k]->to_string();
                str += ")";
            }
        }
        return str;
    } else {
        string str("(:variable ");
        str += print_name_;
        if( such_that_ != 0 )
            str += string(" such-that ") + such_that_->to_string();
        for( size_t k = 0; k < domain_.size(); ++k )
            str += " " + domain_[k]->to_string();
        if( is_observable_ ) str += " :observable";
        return str + ")";
    }
}

string PDDL_Base::ObsVariable::to_string(bool only_name, bool mangled) const {
    if( only_name || mangled ) {
        string str;
        if( mangled ) {
            if( print_name_[0] == '(' ) {
                str = string(print_name_).substr(1, strlen(print_name_) - 2);
                size_t pos = str.find(" ");
                while( pos != string::npos ) {
                    str.replace(pos, 1, "_");
                    pos = str.find(" ", pos);
                }
            } else {
                str = print_name_;
                for( size_t k = 0; k < domain_.size(); ++k )
                    str += "_" + domain_[k]->to_string();
            }
        } else {
            if( print_name_[0] == '(' ) {
                str = print_name_;
            } else {
                str = string("(") + print_name_;
                for( size_t k = 0; k < domain_.size(); ++k )
                    str += " " + domain_[k]->to_string();
                str += ")";
            }
        }
        return str;
    } else {
        string str("(:obs-variable ");
        str += print_name_;
        if( such_that_ != 0 )
            str += string(" such-that ") + such_that_->to_string();
        for( size_t k = 0; k < domain_.size(); ++k )
            str += " " + domain_[k]->to_string();
        return str + ")";
    }
}

PDDL_Base::state_variable_vec* PDDL_Base::SingleStateVariableList::ground(const PDDL_Base *base) const {
    string variable_name("(");
    variable_name += print_name_;
    for( size_t k = 0; k < param_.size(); ++k )
        variable_name += " " + param_[k]->to_string();
    variable_name += ")";

    const Variable *variable = 0;
    for( size_t k = 0; k < base->lw1_variables_.size(); ++k ) {
        const Variable &var = *base->lw1_variables_[k];
        if( var.is_state_variable() && (variable_name == var.print_name_) ) {
            variable = &var;
            break;
        }
    }

    state_variable_vec *result = new state_variable_vec;
    if( variable != 0 ) {
        assert(dynamic_cast<const StateVariable*>(variable) != 0);
        result->push_back(const_cast<StateVariable*>(static_cast<const StateVariable*>(variable)));
    } else {
        cout << Utils::error()
             << "variable groups can only be defined with state variables: discarding variable '"
             << variable_name << "'"
             << endl;
    }
    return result;
}

void PDDL_Base::ForallStateVariableList::process_instance() const {
    Condition *such_that = 0;
    if( such_that_ != 0 ) such_that = such_that_->ground(false, false, true);
    if( (such_that_ == 0) || (dynamic_cast<const Constant*>(such_that) != 0) ) {
        const Constant *constant = static_cast<const Constant*>(such_that);
        if( (such_that_ == 0) || constant->value_ ) {
            for( size_t k = 0; k < group_.size(); ++k ) {
                const StateVariableList &vlist = *group_[k];
                state_variable_vec *vec = vlist.ground(base_stack_.back());
                result_stack_.back()->insert(result_stack_.back()->end(), vec->begin(), vec->end());
                delete vec;
            }
        }
    } else if( such_that_ != 0 ) {
        cout << Utils::error() << "condition '" << *such_that_
             << "' in such-that statement must ground to constant value" << endl;
    }
    if( such_that_ != 0 ) delete such_that;
}

PDDL_Base::state_variable_vec* PDDL_Base::ForallStateVariableList::ground(const PDDL_Base *base) const {
    base_stack_.push_back(base);
    result_stack_.push_back(new state_variable_vec);
    enumerate();
    state_variable_vec *result = result_stack_.back();
    result_stack_.pop_back();
    base_stack_.pop_back();
    return result;
}

void PDDL_Base::VariableGroup::instantiate(const PDDL_Base *base, variable_group_list &vglist) const {
    size_t base_count = vglist.size();
    variable_group_list_ptr_ = &vglist;
    base_ptr_ = base;
    cout << "instantiating variable group '" << print_name_ << "' ..." << flush;
    enumerate();
    cout << " " << vglist.size() - base_count  << " variable group(s)";
    if( vglist.size() - base_count == 0 ) cout << " [" << Utils::warning() << "no variable group instantiated!]";
    cout << endl;
}

void PDDL_Base::VariableGroup::process_instance() const {
    Condition *such_that = 0;
    if( such_that_ != 0 ) such_that = such_that_->ground(false, false, true);
    if( (such_that_ == 0) || (dynamic_cast<const Constant*>(such_that) != 0) ) {
        const Constant *constant = static_cast<const Constant*>(such_that);
        if( (such_that_ == 0) || constant->value_ ) {
            string group_name("(");
            group_name += print_name_;
            for( size_t k = 0; k < param_.size(); ++k )
                group_name += " " + param_[k]->to_string();
            group_name += ")";

            VariableGroup *group = new VariableGroup(strdup(group_name.c_str()));
            group->grounded_ = true;
            variable_group_list_ptr_->push_back(group);

            for( size_t k = 0; k < group_.size(); ++k ) {
                state_variable_vec *grounded_group = group_[k]->ground(base_ptr_);
                for( state_variable_vec::iterator it = grounded_group->begin(); it != grounded_group->end(); it++) {
                    group->grounded_group_.push_back(*it);
                }

                for( int j = 0; j < int(grounded_group->size()); ++j ) {
                    const StateVariable &var = *(*grounded_group)[j];
                    group->grounded_group_str_.insert(string(var.print_name_));
                }
                delete grounded_group;
            }
        }
    } else if( such_that_ != 0 ) {
        cout << Utils::error() << "condition '" << *such_that_
             << "' in such-that statement must ground to constant value" << endl;
    }
    if( such_that_ != 0 ) delete such_that;
}

string PDDL_Base::VariableGroup::to_string() const {
    string str("(var-group ");
    str += string(print_name_);
    for( size_t k = 0; k < grounded_group_.size(); ++k )
        str += string(" ") + grounded_group_[k]->print_name_;
    return str + ")";
}

ostream& operator<<(ostream &os, const PDDL_Base::unsigned_atom_set &atom_set) {
    os << "(and";
    for( PDDL_Base::unsigned_atom_set::const_iterator it = atom_set.begin(); it != atom_set.end(); ++it )
        os << " " << *it;
    os << ")";
    return os;
}

PDDL_Name::PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::symbol_vec &arg, size_t n)
  : negated_(false), sym_(sym), arg_(arg) {
}

PDDL_Name::PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::var_symbol_vec &arg, size_t n)
  : negated_(false), sym_(sym) {
    for( size_t k = 0; k < n; ++k )
        arg_.push_back(arg[k]->value_);
}

void PDDL_Name::add(PDDL_Base::Symbol *s) {
    arg_.push_back(s);
}

string PDDL_Name::to_string(bool mangled) const {
    string str;
    if( mangled ) {
        if( negated_ )
            str += string("not_") + sym_->print_name_;
        else
            str += sym_->print_name_;
        for( size_t k = 0; k < arg_.size(); ++k )
            str += string("_") + arg_[k]->print_name_;
    } else {
        if( negated_ ) str += "(not ";
        str += string("(") + sym_->print_name_;
        for( size_t k = 0; k < arg_.size(); ++k )
            str += string(" ") + arg_[k]->print_name_;
        str += ")";
        if( negated_ ) str += ")";
    }
    return str;
}

