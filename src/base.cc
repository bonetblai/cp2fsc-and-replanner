#include <stdlib.h>
#include <iomanip>
#include "base.h"
#include "utils.h"

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

static void remap_parameters(PDDL_Base::condition_vec &vec, const PDDL_Base::var_symbol_vec &old_param, const PDDL_Base::var_symbol_vec &new_param) {
    for( size_t k = 0; k < vec.size(); ++k )
        const_cast<PDDL_Base::Condition*>(vec[k])->remap_parameters(old_param, new_param);
}

PDDL_Base::PDDL_Base(StringTable &t, const Options::Mode &options)
  : domain_name_(0), problem_name_(0),
    tab_(t), options_(options),
    dom_top_type_(0), dom_goal_(0),
    normal_execution_(0),
    clg_translation_(false),
    multivalued_variable_translation_(false),
    default_sensing_model_(0) {

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

PDDL_Base::~PDDL_Base() { // TODO: implement dtor
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
    for (size_t k = 0; k < dom_predicates_.size(); ++k) {
        if (dom_predicates_[k]->print_name_ == type_sym->print_name_)
            return dom_predicates_[k];
    }
    cerr << Utils::error() << "no type predicate found for type "
         << type_sym->print_name_ << endl;
    exit(255);
}

void PDDL_Base::calculate_strongly_static_predicates() const {
    cout << "strongly-static predicates:";
    bool some_strongly_static = false;
    for( size_t p = 0; p < dom_predicates_.size(); ++p ) {
        PredicateSymbol &pred = *dom_predicates_[p];
        bool strongly_static = true;

        for( size_t k = 0; strongly_static && (k < multivalued_variables_.size()); ++k ) {
            for( size_t i = 0; strongly_static && (i < multivalued_variables_[k]->values_.size()); ++i )
                strongly_static = multivalued_variables_[k]->values_[i]->is_strongly_static(pred);
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
            strongly_static = strongly_static && (act.sensing_model_ == 0 ? true : act.sensing_model_->is_strongly_static(pred));
        }

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

    // instantiate multivalued variables (only for mvv translation)
    variable_list vlist;
    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        multivalued_variables_[k]->instantiate(vlist);
        delete multivalued_variables_[k];
    }
    multivalued_variables_.clear();
    multivalued_variables_.reserve(vlist.size());
    multivalued_variables_.insert(multivalued_variables_.end(), vlist.begin(), vlist.end());

    if( options_.is_enabled("mvv:print:variables") ) {
        for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
            const Variable &var = *multivalued_variables_[k];
            cout << Utils::cyan() << "variable '" << var.print_name_ << "':";
            for( size_t i = 0; i < var.grounded_values_.size(); ++i )
                cout << " " << *var.grounded_values_[i];
            cout << Utils::normal() << endl;
        }
    }

    // ground sensing model
    if( default_sensing_model_ != 0 ) {
        Effect *grounded_default_sensing_model = default_sensing_model_->ground();
        delete default_sensing_model_;
        default_sensing_model_ = grounded_default_sensing_model;
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

    // replace default-sensing-model into actions' sensing models
    if( default_sensing_model_ != 0 ) {
        for( size_t k = 0; k < dom_actions_.size(); ++k ) {
            if( dom_actions_[k]->sensing_model_ == 0 )
                dom_actions_[k]->sensing_model_ = default_sensing_model_->copy_and_simplify();
        }
        delete default_sensing_model_;
        default_sensing_model_ = 0;
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
        if( action.sensing_model_ != 0 ) {
            action.sensing_model_->extract_atoms(dom_static_atoms_);
            action.sensing_model_->extract_atoms(affected_atoms, true);
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
    for( unsigned_atom_set::iterator it = affected_atoms.begin(); it != affected_atoms.end(); ++it ) {
        dom_static_atoms_.erase(*it);
    }

    if( options_.is_enabled("problem:print:atom:static") ) {
        cout << "static atoms:";
        for( unsigned_atom_set::iterator it = dom_static_atoms_.begin(); it != dom_static_atoms_.end(); ++it ) {
            if( !it->pred_->strongly_static_ )
                cout << " " << *it;
        }
        cout << (dom_static_atoms_.empty() ? " <none>" : "") << endl;
    }
}

bool PDDL_Base::is_static_atom(const Atom &atom) const {
    return atom.pred_->strongly_static_ || (dom_static_atoms_.find(atom) != dom_static_atoms_.end());
}

void PDDL_Base::declare_clg_translation() {
    if( !clg_translation_ )
        cout << Utils::magenta() << "entering (pseudo) CLG-compatibility mode" << Utils::normal() << endl;
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

void PDDL_Base::clg_translate_observe_effects_into_sensors() {
    if( !clg_translation_ ) return;

    PredicateSymbol *execution_status = new PredicateSymbol("normal-execution");
    Atom normal_execution(execution_status);

    And precondition;
    AndEffect effect;

    set<Action*> patched_actions;
    cout << Utils::magenta() << "(clg) translating observe effects into sensors..." << Utils::normal() << endl;
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        Action *action = dom_actions_[k];
        if( action->observe_ != 0 ) {
            // save observations and create (do-post-sense-for-<action> <args>) predicate
            const Effect *observe = action->observe_;
            PredicateSymbol *post_sense_pred = new PredicateSymbol(strdup((string("need-post-for-") + action->print_name_).c_str()));
            post_sense_pred->param_ = action->param_;
            dom_predicates_.push_back(post_sense_pred);
            Atom need_post(post_sense_pred);
            need_post.param_.insert(need_post.param_.begin(), post_sense_pred->param_.begin(), post_sense_pred->param_.end());

            // Must do 3 things for this action:
            // 1) modify the action to add precondition (normal-execution), and
            //    effects (do-post-sense-for-<action> <args>) and (not (normal-execution))

            if( action->precondition_ != 0 ) precondition.push_back(action->precondition_);
            precondition.push_back(Literal(normal_execution).copy());
            assert(precondition.is_grounded());
            action->precondition_ = precondition.copy_and_simplify();
            for( size_t k = 0; k < precondition.size(); ++k )
                delete precondition[k];
            precondition.clear();

            if( action->effect_ != 0 ) effect.push_back(action->effect_);
            effect.push_back(AtomicEffect(normal_execution).negate());
            effect.push_back(AtomicEffect(need_post).copy());
            assert(effect.is_grounded());
            action->effect_ = effect.copy_and_simplify();
            for( size_t k = 0; k < effect.size(); ++k )
                delete effect[k];
            effect.clear();

            action->observe_ = 0;
            patched_actions.insert(action);
            if( options_.is_enabled("clg:print:effect") || options_.is_enabled("clg:print:generated") )
                cout << Utils::cyan() << *action << Utils::normal();

            // 2) create sensor sensor-<action> with same arguments, condition
            //    (do-post-sense-for-<action> <args>), and sense <observation>

            Sensor *sensor = new Sensor(strdup((string(action->print_name_) + "__sensor__").c_str()));
            clone_parameters(action->param_, sensor->param_);
            sensor->condition_ = new Literal(need_post);
            sensor->sense_ = observe;

            // remap parameters and insert
            const_cast<Condition*>(sensor->condition_)->remap_parameters(action->param_, sensor->param_);
            const_cast<Effect*>(sensor->sense_)->remap_parameters(action->param_, sensor->param_);
            assert(!sensor->condition_->has_free_variables(sensor->param_));
            assert(!sensor->sense_->has_free_variables(sensor->param_));
            dom_sensors_.push_back(sensor);
            if( options_.is_enabled("clg:print:sensor") || options_.is_enabled("clg:print:generated") )
                cout << Utils::cyan() << *sensor << Utils::normal();

            // 3) create action (post-sense-<action> <args>) with precondition
            //    (do-post-sense-for-<action> <args>) and effects that remove
            //    precondition and add (normal-execution)

            Action *post_action = new Action(strdup((string(action->print_name_) + "__post__").c_str()));
            clone_parameters(action->param_, post_action->param_);
            post_action->precondition_ = Literal(need_post).copy();
            effect.push_back(AtomicEffect(normal_execution).copy());
            effect.push_back(AtomicEffect(need_post).negate());
            post_action->effect_ = effect.copy_and_simplify();
            delete effect[1];
            delete effect[0];
            effect.clear();

            // remap parameters and insert
            const_cast<Condition*>(post_action->precondition_)->remap_parameters(action->param_, post_action->param_);
            const_cast<Effect*>(post_action->effect_)->remap_parameters(action->param_, post_action->param_);
            assert(!post_action->precondition_->has_free_variables(post_action->param_));
            assert(!post_action->effect_->has_free_variables(post_action->param_));
            dom_actions_.push_back(post_action);
            patched_actions.insert(post_action);
            if( options_.is_enabled("clg:print:post") || options_.is_enabled("clg:print:generated") )
                cout << Utils::cyan() << *post_action << Utils::normal();
        }
    }

    // if some translation was done, extend initial and goal situations
    // with  (normal-execution), and add precondition (normal-execution)
    // to all other actions
    if( !patched_actions.empty() ) {
        normal_execution_ = new Atom(normal_execution);
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

        for( size_t k = 0; k < dom_actions_.size(); ++k ) {
            Action *action = dom_actions_[k];
            if( patched_actions.find(action) == patched_actions.end() ) {
                And *precondition = dynamic_cast<And*>(const_cast<Condition*>(action->precondition_));
                if( precondition == 0 ) {
                    precondition = new And;
                    if( action->precondition_ != 0 ) precondition->push_back(action->precondition_);
                }
                precondition->push_back(Literal(normal_execution).copy());
                action->precondition_ = precondition;
            }
        }
        dom_predicates_.push_back(execution_status);
    } else {
        delete execution_status;
    }
}

void PDDL_Base::declare_multivalued_variable_translation() {
    if( !multivalued_variable_translation_ )
        cout << Utils::blue() << "doing multivalued variable (mvv) translation" << Utils::normal() << endl;
    multivalued_variable_translation_ = true;
}

void PDDL_Base::calculate_atoms_for_state_variables() {
    atoms_for_state_variables_.clear();
    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        const Variable &var = *multivalued_variables_[k];
        if( var.is_state_variable() ) {
            for( size_t i = 0; i < var.grounded_values_.size(); ++i )
                atoms_for_state_variables_.insert(*static_cast<const AtomicEffect*>(var.grounded_values_[i]));
        }
    }

    if( options_.is_enabled("mvv:print:atoms-for-state-variables") ) {
        cout << Utils::cyan() << "atoms for state variables:";
        for( unsigned_atom_set::iterator it = atoms_for_state_variables_.begin(); it != atoms_for_state_variables_.end(); ++it )
            cout << " " << *it;
        cout << Utils::normal() << endl;
    }
}

void PDDL_Base::calculate_observable_atoms() {
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        const Action &action = *dom_actions_[k];
        if( action.sensing_model_ != 0 ) {
            if( dynamic_cast<const AndEffect*>(action.sensing_model_) != 0 ) {
                const AndEffect &sensing_model = *static_cast<const AndEffect*>(action.sensing_model_);
                for( size_t i = 0; i < sensing_model.size(); ++i ) {
                    if( dynamic_cast<const AtomicEffect*>(sensing_model[i]) != 0 )
                        observable_atoms_.insert(*static_cast<const AtomicEffect*>(sensing_model[i]));
                }
            } else if( dynamic_cast<const AtomicEffect*>(action.sensing_model_) != 0 ) {
                observable_atoms_.insert(*static_cast<const AtomicEffect*>(action.sensing_model_));
            }
        }
    }

    if( options_.is_enabled("mvv:print:observable-atoms") ) {
        cout << Utils::cyan() << "observable atoms:";
        for( unsigned_atom_set::iterator it = observable_atoms_.begin(); it != observable_atoms_.end(); ++it )
            cout << " " << *it;
        cout << Utils::normal() << endl;
    }
}

void PDDL_Base::calculate_beams_for_grounded_observable_variables() {
    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        Variable &var = *multivalued_variables_[k];
        if( var.is_observable_variable() ) {
            var.beam_ = vector<unsigned_atom_set>(var.grounded_values_.size());
            calculate_beam_for_grounded_variable(var);

            // print beam (if requested)
            if( options_.is_enabled("mvv:print:beams") ) {
                for( size_t i = 0; i < var.grounded_values_.size(); ++i ) {
                    cout << Utils::cyan() << "beam for "
                         << var.print_name_ << "::" << var.grounded_values_[i]->to_string() << ":";
                    for( unsigned_atom_set::iterator it = var.beam_[i].begin(); it != var.beam_[i].end(); ++it )
                        cout << " " << *it << (is_static_atom(*it) ? "*" : "");
                    cout << Utils::normal() << endl;
                }
            }

            // remove static atoms from beams
            for( size_t i = 0; i < var.grounded_values_.size(); ++i ) {
                unsigned_atom_set reduced_beam;
                for( unsigned_atom_set::iterator it = var.beam_[i].begin(); it != var.beam_[i].end(); ++it ) {
                    if( !is_static_atom(*it) ) reduced_beam.insert(*it);
                }
                var.beam_[i] = reduced_beam;
                if( var.beam_[i].empty() && options_.is_enabled("mvv:compile-static-observables") )
                    compile_static_observable_fluents(*static_cast<const AtomicEffect*>(var.grounded_values_[i]));
            }
        }
    }
}

void PDDL_Base::calculate_beam_for_grounded_variable(Variable &var) {
    if( var.is_state_variable() ) {
        for( size_t k = 0; k < var.grounded_values_.size(); ++k ) {
            assert(dynamic_cast<const AtomicEffect*>(var.grounded_values_[k]) != 0);
            var.beam_[k].insert(*static_cast<const AtomicEffect*>(var.grounded_values_[k]));
        }
    } else {
        for( size_t k = 0; k < dom_actions_.size(); ++k ) {
            const Action &action = *dom_actions_[k];
            if( action.sensing_model_ != 0 ) {
                unsigned_atom_vec context;
                action.sensing_model_->calculate_beam_for_grounded_variable(var, context);
            }
        }
    }
}

void PDDL_Base::translate_actions_for_multivalued_variable_formulation() {
    if( !multivalued_variable_translation_ ) return;

    // compute actions that need translation
    action_vec actions_to_translate;
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        if( dom_actions_[k]->sensing_model_ != 0 ) {
            actions_to_translate.push_back(dom_actions_[k]);
            dom_actions_[k] = dom_actions_.back();
            dom_actions_.pop_back();
            --k;
        }
    }

    // create atoms need in translation
    if( !actions_to_translate.empty() ) {
        PredicateSymbol *execution_status = new PredicateSymbol("normal-execution");
        dom_predicates_.push_back(execution_status);
        normal_execution_ = new Atom(execution_status);

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

        // create need_set_sensing and need_post atoms for each action
#if 0
        for( size_t k = 0; k < actions_to_translate.size(); ++k ) {
            Action &action = *actions_to_translate[k];
            if( action.effect_ != 0 ) {
                string predicate_name = string("need-set-sensing-for-") + action.print_name_;
                PredicateSymbol *sense = new PredicateSymbol(strdup(predicate_name.c_str()));
                sense->param_ = action.param_;
                dom_predicates_.push_back(sense);
                Atom *need_sense_atom = new Atom(sense);
                need_sense_atom->param_.insert(need_sense_atom->param_.begin(),
                                               sense->param_.begin(),
                                               sense->param_.end());
                need_sense_.push_back(need_sense_atom);
            } else {
                need_sense_.push_back(static_cast<Atom*>(0));
            }

            string predicate_name = string("need-post-for-") + action.print_name_;
            PredicateSymbol *post = new PredicateSymbol(strdup(predicate_name.c_str()));
            post->param_ = action.param_;
            dom_predicates_.push_back(post);
            Atom *need_post_atom = new Atom(post);
            need_post_atom->param_.insert(need_post_atom->param_.begin(),
                                          post->param_.begin(),
                                          post->param_.end());
            need_post_.push_back(need_post_atom);
        }
#endif

        // extend preconditions of other actions with (normal-execution). In a pure
        // multivalued setting, there should be none of such actions
        if( !dom_actions_.empty() ) {
            cout << Utils::blue() << "(mvv) extending preconditions with '(normal-execution)' for "
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
        assert(action->sensing_model_->is_grounded());
        translation_for_multivalued_variable_formulation(*action);
        //delete action; // NEED FIX: guess: delete params that are needed in sensing model (invariants)
    }
}

void PDDL_Base::translation_for_multivalued_variable_formulation(Action &action) {
    assert(action.param_.empty()); // action must be instantiated

    And precondition;
    AndEffect effect;

    unsigned_atom_set atoms_to_remove(atoms_for_state_variables_);
    atoms_to_remove.insert(static_observable_atoms_.begin(), static_observable_atoms_.end());
    Effect *reduced_sensing_model = action.sensing_model_->reduce_sensing_model(atoms_to_remove);
    bool need_effect_action = action.effect_ != 0;
    bool need_set_sensing_action = reduced_sensing_model != 0;

    // calculate sensed atoms
    unsigned_atom_set sensed_atoms;
    action.sensing_model_->extract_atoms(sensed_atoms, true);

    // fetch (create) (need-post) atoms
    const Atom &need_post = *fetch_need_post_atom(sensed_atoms);

    // create __effect__ action (if needed)
    if( need_effect_action ) {
        // Action that execute only the effects on state variables (i.e. no sensing model involved)
        Action *effect_action = new Action(strdup((string(action.print_name_) + "__effect__").c_str()));

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
            const Atom& need_set_sensing = *fetch_need_set_sensing_atom(action);
            effect.push_back(AtomicEffect(need_set_sensing).copy());      // (need-set-sensing <param>)
        } else {
            effect.push_back(AtomicEffect(need_post).copy());             // (need-post <param>)
            for( unsigned_atom_set::const_iterator it = sensed_atoms.begin(); it != sensed_atoms.end(); ++it ) {
                const Atom& sensing_atom = *fetch_sensing_atom(*it);
                effect.push_back(AtomicEffect(sensing_atom).copy());      // (sensing-<atom>)
            }
        }
        assert(effect.is_grounded());
        effect_action->effect_ = effect.copy_and_simplify();
        delete effect[2];
        delete effect[1];
        effect.clear();

        // insert action
        dom_actions_.push_back(effect_action);
        if( options_.is_enabled("mvv:print:effect") || options_.is_enabled("mvv:print:generated") )
            cout << Utils::cyan() << *effect_action << Utils::normal();
    }

    if( need_set_sensing_action ) {
        // Action that computes the effects on observables (i.e. sensing model)
        Action *set_sensing_action = new Action(strdup((string(action.print_name_) + "__set_sensing__").c_str()));

        // precondition
        if( need_effect_action ) {
            const Atom& need_set_sensing = *fetch_need_set_sensing_atom(action);
            precondition.push_back(Literal(need_set_sensing).copy());     // (need-set-sensing <param>)
        } else {
            if( action.precondition_ != 0 ) precondition.push_back(action.precondition_);
            precondition.push_back(Literal(*normal_execution_).copy());   // (normal-execution)
        }
        assert(precondition.is_grounded());
        set_sensing_action->precondition_ = precondition.copy_and_simplify();
        delete precondition.back();
        precondition.clear();

        // effects
        effect.push_back(reduced_sensing_model);
        effect.push_back(AtomicEffect(need_post).copy());                 // (need-post <param>)
        for( unsigned_atom_set::const_iterator it = sensed_atoms.begin(); it != sensed_atoms.end(); ++it ) {
            const Atom& sensing_atom = *fetch_sensing_atom(*it);
            effect.push_back(AtomicEffect(sensing_atom).copy());          // (sensing-<atom>)
        }
        if( need_effect_action ) {
            const Atom& need_set_sensing = *fetch_need_set_sensing_atom(action);
            effect.push_back(AtomicEffect(need_set_sensing).negate());    // (not (need-set-sensing <param>))
        } else {
            effect.push_back(AtomicEffect(*normal_execution_).negate());  // (not (normal-execution))
        }
        assert(effect.is_grounded());
        set_sensing_action->effect_ = effect.copy_and_simplify();
        delete effect[2];
        delete effect[1];
        delete effect[0];
        effect.clear();

        // insert action
        dom_actions_.push_back(set_sensing_action);
        if( options_.is_enabled("mvv:print:set-sensing") || options_.is_enabled("mvv:print:generated") )
            cout << Utils::cyan() << *set_sensing_action << Utils::normal();

        // store sensing model for generating invariants later
        sensing_models_.push_back(make_pair(new var_symbol_vec(action.param_), action.sensing_model_->copy_and_simplify()));
    }

    if( !need_effect_action && !need_set_sensing_action ) {
        // Action that only turns on the sensor
        Action *turn_on_sensor_action = new Action(strdup((string(action.print_name_) + "__turn_on_sensor__").c_str()));

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
            const Atom& sensing_atom = *fetch_sensing_atom(*it);
            effect.push_back(AtomicEffect(sensing_atom).copy());          // (sensing-<atom>)
        }
        turn_on_sensor_action->effect_ = effect.copy_and_simplify();
        delete effect[1];
        delete effect[0];
        effect.clear();

        // insert action
        dom_actions_.push_back(turn_on_sensor_action);
        if( options_.is_enabled("mvv:print:turn-on-sensor") || options_.is_enabled("mvv:print:generated") )
            cout << Utils::cyan() << *turn_on_sensor_action << Utils::normal();
    }

    // Sensors for this action
    create_sensors_for_atoms(sensed_atoms);

    // Post action that re-establish normal execution
    create_post_action(sensed_atoms);
}

void PDDL_Base::create_sensors_for_atoms(const unsigned_atom_set &atoms) {
    for( unsigned_atom_set::const_iterator it = atoms.begin(); it != atoms.end(); ++it ) {
        const Atom &atom = *it;
        if( sensors_for_multivalued_variable_translation_.find(atom.to_string(atom.negated_, true)) == sensors_for_multivalued_variable_translation_.end() ) {
            Sensor *sensor = new Sensor(strdup((string("sensor-for-") + atom.to_string(atom.negated_, true)).c_str()));

            // condition
            const Atom& sensing_atom = *fetch_sensing_atom(atom);
            sensor->condition_ = Literal(sensing_atom).copy();

            // sensed atom
            sensor->sense_ = AtomicEffect(atom, atom.negated_).copy();

            // insert sensor
            sensors_for_multivalued_variable_translation_.insert(make_pair(atom.to_string(atom.negated_, true), sensor));
            dom_sensors_.push_back(sensor);
            if( options_.is_enabled("mvv:print:sensor") || options_.is_enabled("mvv:print:generated") )
                cout << Utils::cyan() << *sensor << Utils::normal();
        }
    }
}

void PDDL_Base::create_post_action(const unsigned_atom_set &atoms) {
    map<unsigned_atom_set, const Action*>::const_iterator it = post_actions_for_multivalued_variable_translation_.find(atoms);
    if( it == post_actions_for_multivalued_variable_translation_.end() ) {
        ostringstream s;
        s << "post-action-" << post_actions_for_multivalued_variable_translation_.size();
        Action *post_action = new Action(strdup(s.str().c_str()));

        // precondition
        const Atom &need_post = *fetch_need_post_atom(atoms);
        post_action->precondition_ = Literal(need_post).copy();

        // effect
        AndEffect effect;
        effect.push_back(AtomicEffect(*normal_execution_).copy());
        effect.push_back(AtomicEffect(need_post).negate());
        for( unsigned_atom_set::const_iterator it = atoms.begin(); it != atoms.end(); ++it ) {
            const Atom& atom = *fetch_sensing_atom(*it);
            effect.push_back(AtomicEffect(atom).negate());
        }
        post_action->effect_ = effect.copy_and_simplify();
        delete effect[1];
        delete effect[0];
        effect.clear();

        // insert action
        post_actions_for_multivalued_variable_translation_.insert(make_pair(atoms, post_action));
        dom_actions_.push_back(post_action);
        if( options_.is_enabled("mvv:print:post") || options_.is_enabled("mvv:print:generated") )
            cout << Utils::cyan() << *post_action << Utils::normal();
    }
}

void PDDL_Base::create_invariants_for_multivalued_variables() {
    if( !multivalued_variable_translation_ ) return;
    cout << Utils::blue() << "(mvv) creating invariants for multivalued variables..." << Utils::normal() << endl;

    Invariant exactly_one(Invariant::EXACTLY_ONE);
    Invariant at_least_one(Invariant::AT_LEAST_ONE);

    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        Variable &var = *multivalued_variables_[k];
        if( var.is_state_variable() ) {
            // for each state variable with domain size > 1, generate (exactly-one <values>)
            if( var.grounded_values_.size() > 1 ) {
                exactly_one.reserve(var.grounded_values_.size());
                // BLAI: check precondition
                //exactly_one.Xprecondition_ = Literal(*normal_execution_).copy();
                for( size_t i = 0; i < var.grounded_values_.size(); ++i )
                    exactly_one.push_back(Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[i])).copy());
                clone_parameters(var.param_, exactly_one.param_);
                remap_parameters(exactly_one, var.param_, exactly_one.param_);
                assert(!exactly_one.has_free_variables());
                dom_init_.push_back(new InitInvariant(exactly_one));
                exactly_one.clear();
                if( options_.is_enabled("mvv:print:invariants") || options_.is_enabled("mvv:print:invariants:var") )
                    cout << Utils::cyan()
                         << "invariant for variable '" << var.print_name_ << "': " << *dom_init_.back()
                         << Utils::normal() << endl;
            } else {
                // BLAI
                // NOTE: should remove this later when preprocessing is fixed. This is only
                // here to avoid preprocessing to mark the variable as 'static'
                at_least_one.reserve(2);
                at_least_one.push_back(Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[0])).copy());
                at_least_one.push_back(Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[0])).negate());
                clone_parameters(var.param_, at_least_one.param_);
                remap_parameters(at_least_one, var.param_, at_least_one.param_);
                assert(!at_least_one.has_free_variables());
                dom_init_.push_back(new InitInvariant(at_least_one));
                at_least_one.clear();
                if( options_.is_enabled("mvv:print:invariants") || options_.is_enabled("mvv:print:invariants:var") )
                    cout << Utils::cyan()
                         << "invariant for variable '" << var.print_name_ << "': " << *dom_init_.back()
                         << Utils::normal() << endl;
            }
        } else {
            // BLAI: (not (sensing-is-one)) should be precondition of invariant!
            // for each observable variable, and values <value-i> and <value-j>
            // generate (at-least-one (not (sensing-is-on)) (not <value-i>) (not <value-j>))
            if( var.grounded_values_.size() > 1 ) {
                for( size_t i = 0; i < var.grounded_values_.size(); ++i ) {
                    for( size_t j = i + 1; j < var.grounded_values_.size(); ++j ) {
                        at_least_one.reserve(3);
                        // BLAI: check precondition
                        //at_least_one.Xprecondition_ = Literal(*normal_execution_).copy();
                        //at_least_one.push_back(Literal(*sensing_.first).negate());`
                        at_least_one.push_back(Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[i])).negate());
                        at_least_one.push_back(Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[j])).negate());
                        clone_parameters(var.param_, at_least_one.param_);
                        remap_parameters(at_least_one, var.param_, at_least_one.param_);
                        assert(!at_least_one.has_free_variables());
                        dom_init_.push_back(new InitInvariant(at_least_one));
                        at_least_one.clear();
                        if( options_.is_enabled("mvv:print:invariants") || options_.is_enabled("mvv:print:invariants:var") )
                            cout << Utils::cyan()
                                 << "invariant for variable '" << var.print_name_ << "': " << *dom_init_.back()
                                 << Utils::normal() << endl;
                    }
                }
            } else {
                // NOTE: should remove this later when preprocessing is fixed. This is only
                // here to avoid preprocessing to mark the variable as 'static'
                at_least_one.reserve(2);
                at_least_one.push_back(Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[0])).copy());
                at_least_one.push_back(Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[0])).negate());
                clone_parameters(var.param_, at_least_one.param_);
                remap_parameters(at_least_one, var.param_, at_least_one.param_);
                assert(!at_least_one.has_free_variables());
                dom_init_.push_back(new InitInvariant(at_least_one));
                at_least_one.clear();
                if( options_.is_enabled("mvv:print:invariants") || options_.is_enabled("mvv:print:invariants:var") )
                    cout << Utils::cyan()
                         << "invariant for variable '" << var.print_name_ << "': " << *dom_init_.back()
                         << Utils::normal() << endl;
            }
        }
    }
}

void PDDL_Base::create_invariants_for_sensing_model() {
    if( !multivalued_variable_translation_ ) return;
    cout << Utils::blue() << "(mvv) creating invariants for sensing model..." << Utils::normal() << endl;

    set<string> generated_invariants;
    for( size_t k = 0; k < sensing_models_.size(); ++k ) {
        if( dynamic_cast<const AndEffect*>(sensing_models_[k].second) == 0 ) {
            AndEffect *effect = new AndEffect;
            effect->push_back(sensing_models_[k].second);
            sensing_models_[k].second = effect;
        }

        const var_symbol_vec &parameters = *sensing_models_[k].first;
        const AndEffect &effect = *static_cast<const AndEffect*>(sensing_models_[k].second);

        // collect conditions for each observable literal (head of conditional effect)
        map<string, condition_vec> sensing_map;
        map<string, const AtomicEffect*> sensed_literal;
        for( size_t i = 0; i < effect.size(); ++i ) {
            if( dynamic_cast<const ConditionalEffect*>(effect[i]) != 0 ) {
                const ConditionalEffect &conditional_effect = *static_cast<const ConditionalEffect*>(effect[i]);
                if( dynamic_cast<const AndEffect*>(conditional_effect.effect_) != 0 ) {
                    const AndEffect &head = *static_cast<const AndEffect*>(conditional_effect.effect_);
                    for( size_t j = 0; j < head.size(); ++j ) {
                        assert(dynamic_cast<const AtomicEffect*>(head[j]) != 0);
                        const AtomicEffect *h = static_cast<const AtomicEffect*>(head[j]);
                        sensing_map[h->to_string()].push_back(conditional_effect.condition_->copy_and_simplify());
                        sensed_literal[h->to_string()] = static_cast<AtomicEffect*>(h->copy());
                    }
                } else {
                    assert(dynamic_cast<const AtomicEffect*>(conditional_effect.effect_) != 0);
                    const AtomicEffect &head = *static_cast<const AtomicEffect*>(conditional_effect.effect_);
                    sensing_map[head.to_string()].push_back(conditional_effect.condition_->copy_and_simplify());
                    sensed_literal[head.to_string()] = static_cast<AtomicEffect*>(head.copy());
                }
            } else {
                assert(dynamic_cast<const AtomicEffect*>(effect[i]) != 0);
                //const AtomicEffect &observable_atom = *static_cast<const AtomicEffect*>(effect[i]);
                //assert(observable_atoms_.find(observable_atom) != observable_atoms_.end());
                //cout << "WARNING_TEXT: unconditional sensing for " << *effect[i] << endl;
                //exit(255);
            }
        }

        // BLAI: do we need precndition for these invariants?
        // for each observable literal L with rules C1 => L, ..., Cn => L:
        //
        // 1) create (invariant ~L C1 C2 .. Cn) representing L => C1 v C2 v ... v Cn
        //
        // 2) create (invariant L ~Ci), for each i, representing ~L => ~Ci

        Invariant invariant1(Invariant::AT_LEAST_ONE);
        Invariant invariant2(Invariant::AT_LEAST_ONE);
        for( map<string, condition_vec>::iterator it = sensing_map.begin(); it != sensing_map.end(); ++it ) {
            invariant1.push_back(Literal(*sensed_literal[it->first]).negate());
            for( size_t i = 0; i < it->second.size(); ++i ) {
                invariant1.push_back(it->second[i]->copy_and_simplify());
                invariant2.push_back(Literal(*sensed_literal[it->first]).copy());
                Condition *c = it->second[i]->negate_and_simplify();
                if( dynamic_cast<Or*>(c) != 0 ) {
                    Or *or_condition = static_cast<Or*>(c);
                    for( size_t j = 0; j < or_condition->size(); ++j )
                        invariant2.push_back((*or_condition)[j]);
                    or_condition->clear();
                    delete or_condition;
                } else {
                    invariant2.push_back(c);
                }

                bool invariant2_is_good = invariant2.reduce();
                if( invariant2_is_good && (generated_invariants.find(invariant2.to_string()) == generated_invariants.end()) ) {
                    clone_parameters(parameters, invariant2.param_);
                    remap_parameters(invariant2, parameters, invariant2.param_);
                    assert(!invariant2.has_free_variables());
                    dom_init_.push_back(new InitInvariant(invariant2));
                    generated_invariants.insert(invariant2.to_string());
                    if( options_.is_enabled("mvv:print:invariants") || options_.is_enabled("mvv:print:invariants:sensing") )
                        cout << Utils::cyan() << "invariant: " << *dom_init_.back() << Utils::normal() << endl;
                } else {
                    for( size_t i = 0; i < invariant2.size(); ++i )
                        delete invariant2[i];
                }
                invariant2.clear();
            }

            bool invariant1_is_good = invariant1.reduce();
            if( invariant1_is_good && (generated_invariants.find(invariant1.to_string()) == generated_invariants.end()) ) {
                clone_parameters(parameters, invariant1.param_);
                remap_parameters(invariant1, parameters, invariant1.param_);
                assert(!invariant1.has_free_variables());
                dom_init_.push_back(new InitInvariant(invariant1));
                generated_invariants.insert(invariant1.to_string());
                if( options_.is_enabled("mvv:print:invariants") || options_.is_enabled("mvv:print:invariants:sensing") )
                    cout << Utils::cyan() << "invariant: " << *dom_init_.back() << Utils::normal() << endl;
            } else {
                for( size_t i = 0; i < invariant1.size(); ++i )
                    delete invariant1[i];
            }
            invariant1.clear();
        }
    }
}

void PDDL_Base::calculate_post_condition(const Condition *precondition, const Effect *effect, unsigned_atom_set &post_condition) const {
    post_condition.clear();

    // calculate literals in precondition
    if( dynamic_cast<const And*>(precondition) != 0 ) {
        const And &and_precondition = *static_cast<const And*>(precondition);
        for( size_t k = 0; k < and_precondition.size(); ++k ) {
            assert(dynamic_cast<const Literal*>(and_precondition[k]) != 0);
            post_condition.insert(*static_cast<const Literal*>(and_precondition[k]));
        }
    } else if( dynamic_cast<const Literal*>(precondition) != 0 ) {
        post_condition.insert(*static_cast<const Literal*>(precondition));
    }
    
    // calculate post condition (this works because sets are unsigned)
    if( dynamic_cast<const AndEffect*>(effect) != 0 ) {
        const AndEffect &and_effect = *static_cast<const AndEffect*>(effect);
        for( size_t k = 0; k < and_effect.size(); ++k ) {
            assert(dynamic_cast<const AtomicEffect*>(and_effect[k]) != 0);
            post_condition.erase(*static_cast<const AtomicEffect*>(and_effect[k]));
            post_condition.insert(*static_cast<const AtomicEffect*>(and_effect[k]));
        }
    } else if( dynamic_cast<const AtomicEffect*>(effect) != 0 ) {
        post_condition.erase(*static_cast<const AtomicEffect*>(effect));
        post_condition.insert(*static_cast<const AtomicEffect*>(effect));
    }
}

void PDDL_Base::simplify_post_condition(unsigned_atom_set &post_condition) const {
    vector<const Atom*> literals;
    literals.reserve(post_condition.size());
    for( unsigned_atom_set::const_iterator it = post_condition.begin(); it != post_condition.end(); ++it )
        literals.push_back(new Atom(*it));

    // simplify
    size_t k = 0;
    while( k < literals.size() ) {
        const Atom *lit = literals[k];
        literals[k] = literals.back();
        literals.pop_back();
        if( !is_literal_implied(lit, literals) ) {
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

bool PDDL_Base::is_literal_implied(const Atom *lit, const vector<const Atom*> &literals) const {
    if( lit->negated_ ) {
        for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
            const Variable &var = *multivalued_variables_[k];
            if( var.is_state_variable() ) {
                for( size_t i = 0; i < var.grounded_values_.size(); ++i ) {
                    if( *lit == *static_cast<const AtomicEffect*>(var.grounded_values_[i]) ) {
                        for( size_t j = 0; j < literals.size(); ++j ) {
                            if( !literals[j]->negated_ ) {
                                for( size_t l = 0; l < var.grounded_values_.size(); ++l ) {
                                    if( *literals[j] == *static_cast<const AtomicEffect*>(var.grounded_values_[l]) )
                                        return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool PDDL_Base::s0_test(const unsigned_atom_set &condition) const {
    cout << Utils::warning() << "default implementation for 's0_test()'" << endl;
    return true;
}

bool PDDL_Base::action_test(const unsigned_atom_set &condition) const {
    cout << Utils::warning() << "default implementation for 'action_test()'" << endl;
    return true;
}

void PDDL_Base::remove_subsumed_conditions(std::set<unsigned_atom_set> &conditions) const {
    cout << Utils::warning() << "default implementation for 'remove_subsumed_conditions()'" << endl;
}

PDDL_Base::Condition* PDDL_Base::create_condition(const unsigned_atom_set &condition) const {
    if( condition.empty() ) {
        return new Constant(true);
    } else {
        And *and_condition = new And;
        for( unsigned_atom_set::const_iterator it = condition.begin(); it != condition.end(); ++it )
            and_condition->push_back(Literal(*it).copy());
        return and_condition;
    }
}

void PDDL_Base::compile_static_observable_fluents(const Atom &atom) {
    cout << Utils::blue() << "(mvv) compiling static observable '" << atom << "'"
         << Utils::normal() << endl;

    // iterate over all sensing models extracting those relevant to atom
    effect_list sensing_models;
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        const Action &action = *dom_actions_[k];
        if( action.sensing_model_ != 0 )
            action.sensing_model_->extract_sensing_model_for_atom(atom, sensing_models);
    }

    // remove duplicate sensing models
    set<string> sensing_models_str;
    for( effect_list::iterator it = sensing_models.begin(); it != sensing_models.end(); ++it ) {
        string str = (*it)->to_string();
        if( sensing_models_str.find(str) == sensing_models_str.end() ) {
            sensing_models_str.insert(str);
        } else {
            delete *it;
            it = --sensing_models.erase(it);
        }
    }

    // print sensing models
    if( options_.is_enabled("mvv:print:compiled-sensing-models") ) {
        cout << Utils::cyan() << "sensing models for '" << atom << "':" << endl;
        for( effect_list::iterator it = sensing_models.begin(); it != sensing_models.end(); ++it )
            cout << "    " << **it << endl;
        cout << Utils::normal();
    }

    // generate axioms and invariants for filtered sensing models
    for( effect_list::iterator it = sensing_models.begin(); it != sensing_models.end(); ++it ) {
        assert(dynamic_cast<const ConditionalEffect*>(*it) != 0);
        const ConditionalEffect *effect = static_cast<const ConditionalEffect*>(*it);
        assert(dynamic_cast<const AtomicEffect*>(effect->effect_) != 0);
        const AtomicEffect *head = static_cast<const AtomicEffect*>(effect->effect_);
        const Condition *condition = effect->condition_;
        assert((dynamic_cast<const Literal*>(condition) != 0) || (dynamic_cast<const And*>(condition) != 0));
        const_cast<ConditionalEffect*>(effect)->effect_ = 0;
        const_cast<ConditionalEffect*>(effect)->condition_ = 0;
        delete effect;

        // axioms are used to complete initial hidden states with the static observable
        // fluents. Hence, only generate axioms for positive heads as the static fluents
        // for observables are assumed to be false by default.
        if( !head->negated_ ) {
            Axiom *axiom = new Axiom(strdup("[compiled]"));
            axiom->body_ = condition;
            axiom->head_ = head;
            dom_axioms_.push_back(axiom);
            if( options_.is_enabled("mvv:print:axioms") )
                cout << Utils::cyan() << *axiom << Utils::normal();
        }

        // invariant
        // BLAI: check precondtion
        Invariant invariant(Invariant::AT_LEAST_ONE);
        Condition *negated_condition = condition->negate_and_simplify();
        if( dynamic_cast<Literal*>(negated_condition) != 0 ) {
            invariant.push_back(negated_condition);
        } else {
            Or &or_condition = *static_cast<Or*>(negated_condition);
            for( size_t k = 0; k < or_condition.size(); ++k )
                invariant.push_back(or_condition[k]);
            or_condition.clear();
            delete negated_condition;
        }
        invariant.push_back(Literal(*head).copy());
        dom_init_.push_back(new InitInvariant(invariant));
        invariant.clear();
        if( options_.is_enabled("mvv:print:invariants") || options_.is_enabled("mvv:print:invariants:compilation") )
            cout << Utils::cyan()
                 << "invariant for compiled sensing model: " << *dom_init_.back()
                 << Utils::normal() << endl;
    }

    // insert atom into set of static observable atoms
    static_observable_atoms_.insert(atom);

    // calculate prime implicant for conditions on observable atom
    cout << Utils::red() << "calculating prime implicant for conditions on observable atom: " << atom << Utils::normal() << endl; 
    set<unsigned_atom_set> candidate_post_conditions;
    unsigned_atom_set atoms_to_remove;
    atoms_to_remove.insert(atom);

    vector<bool> affected_action(dom_actions_.size(), false);
    vector<Effect*> reduced_sensing_model(dom_actions_.size(), 0);
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        Action &action = *dom_actions_[k];
        if( action.sensing_model_ != 0 ) {
            Effect *reduced_model = action.sensing_model_->reduce_sensing_model(atoms_to_remove);
            if( (reduced_model == 0) || (reduced_model->to_string() != action.sensing_model_->to_string()) ) {
                affected_action[k] = true;
                reduced_sensing_model[k] = reduced_model;
                unsigned_atom_set post_condition;
                //cout << "action=" << action.print_name_;
                //if( action.precondition_ != 0 ) cout << ", pre=" << *action.precondition_;
                //if( action.effect_ != 0 ) cout << ", eff=" << *action.effect_;
                calculate_post_condition(action.precondition_, action.effect_, post_condition);
                simplify_post_condition(post_condition);
                //cout << ", post=" << post_condition << endl;
                candidate_post_conditions.insert(post_condition);
            } else {
                delete reduced_model;
            }
        }
    }

    // apply test and filter candiate conditions
    set<unsigned_atom_set> post_conditions;
    for( set<unsigned_atom_set>::const_iterator it = candidate_post_conditions.begin(); it != candidate_post_conditions.end(); ++it ) {
        if( s0_test(*it) && action_test(*it) )
            post_conditions.insert(*it);
    }
    remove_subsumed_conditions(post_conditions);

    // modify sensing models of actions: if pasive sensor for atom cannot be created,
    // reduce sensing model and insert atom, otherwise remove atom and reduce model.
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        if( affected_action[k] ) {
            Action &action = *dom_actions_[k];
            Effect *reduced_model = reduced_sensing_model[k];
            if( post_conditions.empty() ) {
                if( reduced_model == 0 ) {
                    reduced_model = AtomicEffect(atom).copy();
                } else {
                    if( dynamic_cast<AndEffect*>(reduced_model) == 0 ) {
                        AndEffect *and_effect = new AndEffect;
                        and_effect->push_back(reduced_model);
                        reduced_model = and_effect;
                    }
                    static_cast<AndEffect*>(reduced_model)->push_back(AtomicEffect(atom).copy());
                }
            }
            assert(action.sensing_model_ != 0);
            delete action.sensing_model_;
            action.sensing_model_ = reduced_model;
            reduced_sensing_model[k] = 0;
        }
    }

#if 0
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        Action &action = *dom_actions_[k];
        if( action.sensing_model_ != 0 ) {
            Effect *reduced_model = action.sensing_model_->reduce_sensing_model(atoms_to_remove);
            if( (reduced_model == 0) || (reduced_model->to_string() != action.sensing_model_->to_string()) ) {
                if( reduced_model == 0 ) {
                    reduced_model = AtomicEffect(atom).copy();
                } else {
                    if( dynamic_cast<AndEffect*>(reduced_model) == 0 ) {
                        AndEffect *and_effect = new AndEffect;
                        and_effect->push_back(reduced_model);
                        reduced_model = and_effect;
                    }
                    static_cast<AndEffect*>(reduced_model)->push_back(AtomicEffect(atom).copy());
                }
                delete action.sensing_model_;
                action.sensing_model_ = reduced_model;
            } else {
                delete reduced_model;
            }
        }
    }
#endif

    if( !post_conditions.empty() ) {
        // for each condition, create a pasive sensor
        for( set<unsigned_atom_set>::const_iterator it = post_conditions.begin(); it != post_conditions.end(); ++it ) {
            if( it->size() > 2 ) continue;
            //cout << "condition=" << *it << endl;
            Sensor *sensor = new Sensor(strdup((string("pasive-sensor-for-") + atom.to_string(atom.negated_, true)).c_str()));
            sensor->condition_ = create_condition(*it);
            sensor->sense_ = AtomicEffect(atom, atom.negated_).copy();
            dom_sensors_.push_back(sensor);
            if( true || options_.is_enabled("mvv:print:sensor") || options_.is_enabled("mvv:print:generated") )
                cout << Utils::cyan() << *sensor << Utils::normal();
        }
    }
}

const PDDL_Base::Atom* PDDL_Base::fetch_need_set_sensing_atom(const Action &action) {
    const map<string, const Atom*>::const_iterator it = need_set_sensing_atoms_.find(action.print_name_);
    if( it == need_set_sensing_atoms_.end() ) {
        string predicate_name = string("need-set-sensing-for-") + action.print_name_;
        PredicateSymbol *predicate = new PredicateSymbol(strdup(predicate_name.c_str()));
        dom_predicates_.push_back(predicate);
        Atom *new_atom = new Atom(predicate);
        need_set_sensing_atoms_.insert(make_pair(action.print_name_, new_atom));
        //cout << "Atom " << *new_atom << " created!" << endl;
        return new_atom;
    } else {
        return it->second;
    }
}

const PDDL_Base::Atom* PDDL_Base::fetch_need_post_atom(const unsigned_atom_set &atoms) {
    const map<unsigned_atom_set, const Atom*>::const_iterator it = need_post_atoms_.find(atoms);
    if( it == need_post_atoms_.end() ) {
        ostringstream s;
        s << "need-post-atom-" << need_post_atoms_.size();
        PredicateSymbol *predicate = new PredicateSymbol(strdup(s.str().c_str()));
        dom_predicates_.push_back(predicate);
        Atom *new_atom = new Atom(predicate);
        need_post_atoms_.insert(make_pair(atoms, new_atom));
        //cout << "Atom " << *new_atom << " created!" << endl;
        return new_atom;
    } else {
        return it->second;
    }
}

const PDDL_Base::Atom* PDDL_Base::fetch_sensing_atom(const Atom &atom) {
    const map<string, const Atom*>::const_iterator it = sensing_atoms_.find(atom.to_string(atom.negated_, true));
    if( it == sensing_atoms_.end() ) {
        string predicate_name = string("sensing-for-") + atom.to_string(atom.negated_, true);
        PredicateSymbol *predicate = new PredicateSymbol(strdup(predicate_name.c_str()));
        dom_predicates_.push_back(predicate);
        Atom *new_atom = new Atom(predicate);
        sensing_atoms_.insert(make_pair(atom.to_string(atom.negated_, true), new_atom));
        //cout << "Atom " << *new_atom << " created!" << endl;
        return new_atom;
    } else {
        return it->second;
    }
}

void PDDL_Base::do_translations(variable_vec &multivalued_variables) {
    instantiate_elements();

    // translate oneofs into invariants and observe effects in actions (CLG-compatibility mode)
    if( clg_translation_ ) {
        clg_translate_observe_effects_into_sensors(); // don't change order: first sts normal_execution_
        clg_map_oneofs_and_clauses_to_invariants();   // that is required by second
    }

    // translate multivalued variable formulations
    if( multivalued_variable_translation_ ) {
        calculate_atoms_for_state_variables();
        //calculate_observable_atoms();
        calculate_beams_for_grounded_observable_variables();
        translate_actions_for_multivalued_variable_formulation();
        create_invariants_for_multivalued_variables();
        create_invariants_for_sensing_model();
        multivalued_variables = multivalued_variables_;
    }
}

void PDDL_Base::emit_instance(Instance &ins) const {
    const char *dname = tab_.table_char_map().strdup(domain_name_ ? domain_name_ : "??");
    const char *pname = tab_.table_char_map().strdup(problem_name_ ? problem_name_ : "??");
    ins.name_ = new InstanceName(dname, pname);
    delete[] dname;
    delete[] pname;

#if 0
    // set atom (normal-execution) (only when processing CLG syntax)
    if( clg_translation_ && (normal_execution_ != 0) ) {
        Instance::Atom *p = normal_execution_->find_prop(ins, false, true);
        ins.index_for_atom_normal_execution_ = p->index_;
    }
#endif

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
    assert(param_.size() == atom.param_.size());
    for( size_t k = 0; k < param_.size(); ++k )
        if( param_[k] != atom.param_[k] ) return false;
    return true;
}

bool PDDL_Base::Atom::operator<(const Atom &atom) const {
    if( pred_ < atom.pred_ ) return true;
    if( pred_ > atom.pred_ ) return false;
    assert(param_.size() == atom.param_.size());
    for( size_t k = 0; k < param_.size(); ++k ) {
        if( param_[k] < atom.param_[k] ) return true;
        if( param_[k] > atom.param_[k] ) return false;
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
    for (size_t k = 0; k < param_.size(); ++k) {
        if( (param_[k]->sym_class_ == sym_variable) && (static_cast<VariableSymbol*>(param_[k])->value_ != 0) )
            str += sep + static_cast<VariableSymbol*>(param_[k])->value_->to_string();
        else
            str += sep + param_[k]->to_string();
    }
    str += end;
    if( extra_neg ) str += end;
    return str;
}

PDDL_Base::Condition* PDDL_Base::Constant::ground(bool clone_variables, bool negate, bool replace_static_values) const {
    return new Constant(negate ? !value_ : value_);
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

string PDDL_Base::ForallCondition::to_string() const {
    string str("(forall (");
    for( size_t k = 0; k < param_.size(); ++k )
        str += (k > 0 ? " " : "") + param_[k]->to_string();
    str += ") " + condition_->to_string() + ")";
    return str;
}

void PDDL_Base::ExistCondition::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    const_cast<Condition*>(condition_)->remap_parameters(old_param, new_param);
}

void PDDL_Base::ExistCondition::emit(Instance &ins, index_set &condition) const {
    cout << Utils::error() << "'ExistCondition' should have dissapeared before instantiating: " << *this << endl;
    exit(255);
}

PDDL_Base::Condition* PDDL_Base::ExistCondition::ground(bool clone_variables, bool negate, bool replace_static_values) const {
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

void PDDL_Base::ExistCondition::process_instance() const {
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

bool PDDL_Base::ExistCondition::has_free_variables(const var_symbol_vec &param, bool dont_extend) const {
    var_symbol_vec nparam(param);
    if( !dont_extend ) nparam.insert(nparam.end(), param_.begin(), param_.end());
    return condition_->has_free_variables(nparam, dont_extend);
}

void PDDL_Base::ExistCondition::extract_atoms(unsigned_atom_set &atoms) const {
    cout << Utils::error() << "extract_atoms() should not be called on ExistCondition: first ground the condition!" << endl;
    exit(255);
}

string PDDL_Base::ExistCondition::to_string() const {
    string str("(exist (");
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
    assert((pred_->print_name_ != p.print_name_) || (pred_ == &p));
    assert((pred_->print_name_ == p.print_name_) || (pred_ != &p));
    return pred_ != &p;
}

void PDDL_Base::AtomicEffect::calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const {
    // determine if variable is affected
    int variable_is_affected = -1;
    string string_rep = Atom::to_string(negated_, false);
    for( size_t k = 0; k < var.grounded_values_.size(); ++k ) {
        const AtomicEffect *value = dynamic_cast<const AtomicEffect*>(var.grounded_values_[k]);
        assert((value != 0) && !value->negated_);
        if( string_rep == value->to_string() ) {
            variable_is_affected = k;
            break;
        }
    }

    // if affected, insert all atoms in context into beam
    if( variable_is_affected >= 0 ) {
        var.beam_[variable_is_affected].insert(context.begin(), context.end());
    }
}

void PDDL_Base::AtomicEffect::extract_atoms(unsigned_atom_set &atoms, bool only_affected) const {
    atoms.insert(*this);
}

PDDL_Base::Effect* PDDL_Base::AtomicEffect::reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const {
    assert(is_grounded());
    return atoms_to_remove.find(*this) != atoms_to_remove.end() ? 0 : copy();
}

void PDDL_Base::AtomicEffect::extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const {
    if( atom == *this ) sensing_models.push_back(copy());
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

void PDDL_Base::AndEffect::calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->calculate_beam_for_grounded_variable(var, context);
}

void PDDL_Base::AndEffect::extract_atoms(unsigned_atom_set &atoms, bool only_affected) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->extract_atoms(atoms, only_affected);
}

PDDL_Base::Effect* PDDL_Base::AndEffect::reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const {
    effect_vec effects;
    for( size_t k = 0; k < size(); ++k ) {
        Effect *reduced = (*this)[k]->reduce_sensing_model(atoms_to_remove);
        if( reduced != 0 ) effects.push_back(reduced);
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

void PDDL_Base::AndEffect::extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->extract_sensing_model_for_atom(atom, sensing_models);
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

void PDDL_Base::ConditionalEffect::calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const {
    assert((condition_ != 0) && (effect_ != 0));
    unsigned_atom_vec ncontext(context);
    if( dynamic_cast<const Literal*>(condition_) != 0 ) {
        const Literal *literal = static_cast<const Literal*>(condition_);
        ncontext.push_back(*literal);
    } else {
        assert(dynamic_cast<const And*>(condition_) != 0);
        const And &and_condition = *static_cast<const And*>(condition_);
        for( size_t k = 0; k < and_condition.size(); ++k ) {
            assert(dynamic_cast<const Literal*>(and_condition[k]) != 0);
            const Literal *literal = static_cast<const Literal*>(and_condition[k]);
            ncontext.push_back(*literal);
        }
    }
    effect_->calculate_beam_for_grounded_variable(var, ncontext);
}

void PDDL_Base::ConditionalEffect::extract_atoms(unsigned_atom_set &atoms, bool only_affected) const {
    if( !only_affected ) condition_->extract_atoms(atoms);
    effect_->extract_atoms(atoms, only_affected);
}

PDDL_Base::Effect* PDDL_Base::ConditionalEffect::reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const {
    assert(condition_->is_grounded() && effect_->is_grounded());
    Effect *effect = effect_->reduce_sensing_model(atoms_to_remove);
    return effect == 0 ? 0 : new ConditionalEffect(condition_->copy_and_simplify(), effect); // COPY
}

void PDDL_Base::ConditionalEffect::extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const {
    effect_list smodels;
    effect_->extract_sensing_model_for_atom(atom, smodels);
    if( !smodels.empty() ) {
        assert(smodels.size() == 1);
        const Effect *effect = *smodels.begin();
        sensing_models.push_back(new ConditionalEffect(condition_->copy_and_simplify(), effect->copy_and_simplify()));
        delete effect;
    }
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

bool PDDL_Base::ForallEffect::has_free_variables(const var_symbol_vec &param, bool dont_extend) const {
    var_symbol_vec nparam(param);
    if( !dont_extend ) nparam.insert(nparam.end(), param_.begin(), param_.end());
    return effect_->has_free_variables(nparam, dont_extend);
}

bool PDDL_Base::ForallEffect::is_strongly_static(const PredicateSymbol &p) const {
    return effect_->is_strongly_static(p);
}

void PDDL_Base::ForallEffect::calculate_beam_for_grounded_variable(Variable &var, const unsigned_atom_vec &context) const {
    cout << Utils::error() << "calculate_beam() should not be called on ForallEffect: first ground the effect!" << endl;
    exit(255);
}

void PDDL_Base::ForallEffect::extract_atoms(unsigned_atom_set &atoms, bool only_affected) const {
    cout << Utils::error() << "extract_atoms() should not be called on ForallEffect: first ground the effect!" << endl;
    exit(255);
}

PDDL_Base::Effect* PDDL_Base::ForallEffect::reduce_sensing_model(const unsigned_atom_set &atoms_to_remove) const {
    cout << Utils::error() << "reduce_sensing_model() should not be called on ForallEffect: first ground the effect!" << endl;
    exit(255);
}

void PDDL_Base::ForallEffect::extract_sensing_model_for_atom(const Atom &atom, effect_list &sensing_models) const {
    cout << Utils::error() << "extract_sensing_model() should not be called on ForallEffect: first ground the effect!" << endl;
    exit(255);
}

string PDDL_Base::ForallEffect::to_string() const {
    string str("(forall (");
    for( size_t k = 0; k < param_.size(); ++k )
        str += (k > 0 ? " " : "") + param_[k]->to_string();
    return str + ") " + effect_->to_string() + ")";
}

void PDDL_Base::Invariant::process_instance() const {
    Invariant invariant(type_);
    invariant.reserve(size());
    for( size_t k = 0; k < size(); ++k )
        invariant.push_back((*this)[k]->ground());

    if( invariant.reduce() ) {
        invariant_list_ptr_->push_back(new Invariant(invariant));
        invariant.clear();
    }
}

void PDDL_Base::Invariant::clear() {
    condition_vec::clear();
    Xprecondition_ = 0;
}

bool PDDL_Base::Invariant::reduce() {
    condition_vec to_remove;
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
        } else {
            cout << Utils::warning() << "invariant must be clause at time of instantiation (skipping): got " << *condition << endl;
            remove_invariant = true;
            to_remove.push_back(condition);
            //exit(255);
        }
    }
    clear();
    if( !remove_invariant ) {
        *this = reduced_invariant;
        reduced_invariant.clear();
    }
    return !remove_invariant;
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
    cout << Utils::error() << "feature not yet supported" << endl;
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
    cout << Utils::error() << "feature not yet supported" << endl;
    exit(255);
}

void PDDL_Base::InitUnknown::emit(Instance &ins) const {
    cout << Utils::error() << "feature not yet supported" << endl;
    exit(255);
}

bool PDDL_Base::InitUnknown::is_strongly_static(const PredicateSymbol &p) const {
    cout << Utils::error() << "feature not yet supported" << endl;
    exit(255);
}

void PDDL_Base::InitUnknown::extract_atoms(unsigned_atom_set &atoms) const {
    cout << Utils::error() << "feature not yet supported" << endl;
    exit(255);
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
    if( sensing_model_ != 0 ) {
        sensing_model_->emit(ins, act.effect_, act.when_);
        //cout << "    sen=" << *sensing_model_ << endl;
    }
}

void PDDL_Base::Action::process_instance() const {
    Condition *grounded_precondition = 0;
    if( precondition_ != 0 ) {
        grounded_precondition = precondition_->ground();
        if( dynamic_cast<Constant*>(grounded_precondition) != 0 ) {
            Constant *precondition_value = static_cast<Constant*>(grounded_precondition);
            delete grounded_precondition;
            if( !precondition_value->value_ )
                return;
            else
                grounded_precondition = 0;
        }
    }

    PDDL_Name name(this, param_, param_.size());
    Action *action = new Action(strdup(name.to_string(true).c_str()));
    action->precondition_ = grounded_precondition;
    if( effect_ != 0 ) action->effect_ = effect_->ground();
    if( observe_ != 0 ) action->observe_ = observe_->ground();
    if( sensing_model_ != 0 ) action->sensing_model_ = sensing_model_->ground();
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
    if( sensing_model_ != 0 ) os << "    :sensing-model " << *sensing_model_ << endl;

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
    PDDL_Name name(this, param_, param_.size());
    Variable *var = make_instance(strdup(name.to_string(true).c_str()));
    var->grounded_ = true;
    variable_list_ptr_->push_back(var);

    for( size_t k = 0; k < values_.size(); ++k ) {
        Effect *grounded_value = values_[k]->ground(true); // clone_variables=true
        if( dynamic_cast<AtomicEffect*>(grounded_value) != 0 ) {
            var->grounded_values_.push_back(grounded_value);
        } else if( dynamic_cast<AndEffect*>(grounded_value) != 0 ) {
            AndEffect &item_list = *static_cast<AndEffect*>(grounded_value);
            var->grounded_values_.reserve(var->grounded_values_.size() + item_list.size());
            for( size_t i = 0; i < item_list.size(); ++i )
                var->grounded_values_.push_back(item_list[i]);
            item_list.clear();
            delete grounded_value;
        } else {
            cout << *values_[k] << endl;
            Effect *e = values_[k]->ground(true); // clone_variables=true
            cout << "gdd-ptr=" << e << endl;
            cout << Utils::error() << "unrecognized format in variable '"
                 << print_name_ << "'" << endl;
            exit(255);
        }
    }
}

void PDDL_Base::StateVariable::print(ostream &os) const {
    os << "(:variable " << print_name_;
    for( size_t k = 0; k < values_.size(); ++k )
          os << " " << *values_[k];
    os << (is_observable_ ? " :observable" : "") << ")";
}

void PDDL_Base::ObsVariable::print(ostream &os) const {
    os << "(:obs-variable " << print_name_;
    for( size_t k = 0; k < values_.size(); ++k )
          os << " " << *values_[k];
    os << ")";
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

string PDDL_Name::to_string(bool cat) const {
    string str;
    if( cat ) {
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

