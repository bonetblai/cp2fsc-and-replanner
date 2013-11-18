#include <stdlib.h>
#include <iomanip>
#include "base.h"

using namespace std;

bool PDDL_Base::write_warnings_ = true;
bool PDDL_Base::write_info_ = true;
Instance::when_vec PDDL_Base::dummy_when_vec_;

template <class T>
static void copy_symbol_vec(const vector<T> &src, vector<T> &dst) {
    dst.clear();
    dst.reserve(src.size());
    for( typename vector<T>::const_iterator it = src.begin(); it != src.end(); ++it ) {
        dst.push_back(static_cast<T>((*it)->clone()));
    }
}

PDDL_Base::PDDL_Base(StringTable &t)
  : domain_name_(0), problem_name_(0),
    tab_(t), dom_top_type_(0), dom_goal_(0),
    clg_translation_(false),
    disable_actions_atom_(0),
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

    // TODO: for being able to remove ctions/sensors and other symbols, thesymbols
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

void PDDL_Base::calculate_strongly_static_predicates() const {
    cout << "strongly-static predicates:";
    bool some_strongly_static = false;
    for( size_t p = 0; p < dom_predicates_.size(); ++p ) {
        PredicateSymbol &pred = *dom_predicates_[p];
        bool strongly_static = true;

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
        }

        pred.strongly_static_ = strongly_static;
        if( strongly_static ) cout << " '" << pred.print_name_ << "'";
        if( strongly_static ) some_strongly_static = true;
    }
    if( !some_strongly_static ) cout << " <none>";
    cout << endl;
}

void PDDL_Base::declare_clg_translation() {
    if( !clg_translation_ ) cout << "entering (pseudo) CLG-compatibility mode" << endl;
    clg_translation_ = true;
}

void PDDL_Base::map_oneofs_to_invariants() {
    // extract oneofs
    vector<pair<int, InitOneof*> > oneofs;
    for( size_t k = 0; k < dom_init_.size(); ++k ) {
        InitElement *ie = dom_init_[k];
        if( dynamic_cast<InitOneof*>(ie) != 0 ) {
            oneofs.push_back(make_pair(k, static_cast<InitOneof*>(ie)));
            dom_init_[k] = 0;
        }
    }

    // make oneof into exactly-one invariant
    for( size_t k = 0; k < oneofs.size(); ++k ) {
        Invariant invariant(Invariant::EXACTLY_ONE, *oneofs[k].second);
        dom_init_[oneofs[k].first] = new InitInvariant(invariant);
        invariant.clear(); // to avoid destruction of elements
        oneofs[k].second->clear(); // to avoid destruction of elements
        delete oneofs[k].second;
    }
}

void PDDL_Base::translate_observe_effects_into_sensors() {
    if( !clg_translation_ ) return;

    PredicateSymbol *dap = new PredicateSymbol("disable-actions");
    Atom da_pos(dap), da_neg(dap, true);

    set<Action*> fixed_actions;
    cout << "clg-translation: translating observe effects into sensors:";
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        Action *action = dom_actions_[k];
        if( action->observe_ != 0 ) {
            cout << " '" << action->print_name_ << "'";

            // save observations and create (do-post-sense-for-<action> <args>) predicate
            const Effect *observe = action->observe_;
            PredicateSymbol *ps = new PredicateSymbol(strdup((string("do-post-sense-for-") + action->print_name_).c_str()));
            //copy_symbol_vec<VariableSymbol*>(action->param_, ps->param_);
            ps->param_ = action->param_;
            dom_predicates_.push_back(ps);
            //cout << *ps;

            Atom ps_pos(ps), ps_neg(ps, true);
            ps_pos.param_.insert(ps_pos.param_.begin(), ps->param_.begin(), ps->param_.end());
            ps_neg.param_.insert(ps_neg.param_.begin(), ps->param_.begin(), ps->param_.end());
            //cout << ps_pos << " " << ps_neg << endl;

            // Must do 3 things for this action:
            // 1) modify the action to add precondition (not (disable-actions)), and
            //    effects (do-post-sense-for-<action> <args>) and (disable-actions)
            And *new_precondition = dynamic_cast<And*>(const_cast<Condition*>(action->precondition_));
            if( new_precondition == 0 ) {
                new_precondition = new And;
                if( action->precondition_ != 0 ) new_precondition->push_back(action->precondition_);
            }
            new_precondition->push_back(new Literal(da_neg));
            action->precondition_ = new_precondition;

            AndEffect *new_effect = dynamic_cast<AndEffect*>(const_cast<Effect*>(action->effect_));
            if( new_effect == 0 ) {
                new_effect = new AndEffect;
                if( action->effect_ != 0 ) new_effect->push_back(action->effect_);
            }
            new_effect->push_back(new AtomicEffect(da_pos));
            new_effect->push_back(new AtomicEffect(ps_pos));
            action->effect_ = new_effect;
            action->observe_ = 0;
            fixed_actions.insert(action);
            //cout << *action;

            // 2) create sensor sensor-<action> with same arguments, condition
            //    (do-post-sense-for-<action> <args>), and sense <observation>
            Sensor *sensor = new Sensor(strdup((string("sensor-for-") + action->print_name_).c_str()));
            dom_sensors_.push_back(sensor);
            sensor->param_ = action->param_;
            sensor->condition_ = new Literal(ps_pos);
            sensor->sense_ = observe;
            //cout << *sensor;

            // 3) create action (post-sense-<action> <args>) with precondition
            //    (do-post-sense-for-<action> <args>) and effects that remove
            //    precondition and remove (disable-actions)
            AndEffect *post_effect = new AndEffect;
            post_effect->push_back(new AtomicEffect(da_neg));
            post_effect->push_back(new AtomicEffect(ps_neg));

            Action *post_action = new Action(strdup((string("post-sense-for-") + action->print_name_).c_str()));
            dom_actions_.push_back(post_action);
            post_action->param_ = action->param_;
            post_action->precondition_ = new Literal(ps_pos);
            post_action->effect_ = post_effect;
            fixed_actions.insert(post_action);
            //cout << *post_action;
        }
    }

    // if some translation was done, add precondition (not (disable-actions))
    // to all other actions
    if( !fixed_actions.empty() ) {
        disable_actions_atom_ = new Literal(da_pos);
        for( size_t k = 0; k < dom_actions_.size(); ++k ) {
            Action *action = dom_actions_[k];
            if( fixed_actions.find(action) == fixed_actions.end() ) {
                And *new_precondition = dynamic_cast<And*>(const_cast<Condition*>(action->precondition_));
                if( new_precondition == 0 ) {
                    new_precondition = new And;
                    if( action->precondition_ != 0 ) new_precondition->push_back(action->precondition_);
                }
                new_precondition->push_back(new Literal(da_neg));
                action->precondition_ = new_precondition;
                //cout << *action;
            }
        }
        dom_predicates_.push_back(dap);
    } else {
        cout << " <none>";
        delete dap;
    }
    cout << endl;
}

void PDDL_Base::declare_multivalued_variable_translation() {
    if( !multivalued_variable_translation_ )
        cout << "performing multivalued variable (mvv) translation" << endl;
    multivalued_variable_translation_ = true;
}

void PDDL_Base::instantiate_multivalued_variables() {
    if( !multivalued_variable_translation_ ) return;

    // instantiate state and observable variables
    variable_vec grounded_variables;
    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        multivalued_variables_[k]->instantiate(grounded_variables);
        delete multivalued_variables_[k];
    }
    multivalued_variables_ = grounded_variables;
}

void PDDL_Base::translate_actions_for_multivalued_variable_formulation() {
    if( !multivalued_variable_translation_ ) return;

    // compute actions that need translation
    action_vec actions_to_translate;
    for( size_t k = 0; k < dom_actions_.size(); ++k ) {
        if( (dom_actions_[k]->sensing_model_ != 0) || (default_sensing_model_ != 0) ) {
            if( dom_actions_[k]->sensing_model_ == 0 )
                dom_actions_[k]->sensing_model_ = default_sensing_model_->ground();
            actions_to_translate.push_back(dom_actions_[k]);
            dom_actions_[k] = dom_actions_.back();
            dom_actions_.pop_back();
            --k;
        }
    }

    // create unique sensor and atoms need in translation
    if( !actions_to_translate.empty() ) {
        PredicateSymbol *execution_status = new PredicateSymbol("normal-execution");
        dom_predicates_.push_back(execution_status);
        normal_execution_.first = new Atom(execution_status);
        normal_execution_.second = new Atom(execution_status, true);

        // extend initial and goal situations with (normal-execution)
        dom_init_.push_back(new InitLiteral(*normal_execution_.first));
        if( dom_goal_ == 0 ) {
            dom_goal_ = new And;
        } else if( dynamic_cast<const And*>(dom_goal_) == 0 ) {
            And *new_goal = new And;
            new_goal->push_back(dom_goal_->ground());
            delete dom_goal_;
            dom_goal_ = new_goal;
        }
        static_cast<And*>(const_cast<Condition*>(dom_goal_))->push_back(new Literal(*normal_execution_.first));

        // create atoms for sensing
        PredicateSymbol *sensing_status = new PredicateSymbol("sensing-is-on");
        dom_predicates_.push_back(sensing_status);
        sensing_.first = new Atom(sensing_status);
        sensing_.second = new Atom(sensing_status, true);

        // create sensor (unique)
        Sensor *sensor = new Sensor(strdup("unique_sensor"));
        sensor->condition_ = new Literal(*sensing_.first);                // (sensing-is-on)
        AndEffect *sense = new AndEffect;
        for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
            Variable &var = *multivalued_variables_[k];
            if( var.is_observable() ) {
                for( size_t i = 0; i < var.grounded_values_.size(); ++i )
                    sense->push_back(new AtomicEffect(*dynamic_cast<const AtomicEffect*>(var.grounded_values_[i])));
            }
        }
        sensor->sense_ = sense;
        dom_sensors_.push_back(sensor);
        cout << *sensor;

        // create needed atoms for each action
        for( size_t k = 0; k < actions_to_translate.size(); ++k ) {
            Action &action = *actions_to_translate[k];
            if( action.effect_ != 0 ) {
                string predicate_name = string("need-set-sensing-for-") + action.print_name_;
                PredicateSymbol *sense = new PredicateSymbol(strdup(predicate_name.c_str()));
                sense->param_ = action.param_;
                dom_predicates_.push_back(sense);
                need_sense_.push_back(make_pair(new Atom(sense), new Atom(sense, true)));
                need_sense_.back().first->param_.insert(need_sense_.back().first->param_.begin(),
                                                        sense->param_.begin(),
                                                        sense->param_.end());
                need_sense_.back().second->param_.insert(need_sense_.back().second->param_.begin(),
                                                         sense->param_.begin(),
                                                         sense->param_.end());
            } else {
                need_sense_.push_back(make_pair(static_cast<Atom*>(0), static_cast<Atom*>(0)));
            }

            string predicate_name = string("need-post-for-") + action.print_name_;
            PredicateSymbol *post = new PredicateSymbol(strdup(predicate_name.c_str()));
            post->param_ = action.param_;
            dom_predicates_.push_back(post);
            need_post_.push_back(make_pair(new Atom(post), new Atom(post, true)));
            need_post_.back().first->param_.insert(need_post_.back().first->param_.begin(),
                                                   post->param_.begin(),
                                                   post->param_.end());
            need_post_.back().second->param_.insert(need_post_.back().second->param_.begin(),
                                                    post->param_.begin(),
                                                    post->param_.end());
        }

        // extend preconditions of other actions with (normal-execution). In
        // a pure multivalued setting, there should be none of such actions
        cout << "mvv-translation: extending preconditions with '(normal-execution)' for "
             << dom_actions_.size() << " action(s)" << endl;
        for( size_t k = 0; k < dom_actions_.size(); ++k ) {
            Action &action = *dom_actions_[k];
            And *precondition = new And;
            precondition->push_back(action.precondition_);
            precondition->push_back(new Literal(*normal_execution_.first));
            action.precondition_ = precondition->ground();
            delete precondition;
        }
    }

    // translate actions
    for( size_t k = 0; k < actions_to_translate.size(); ++k ) {
        Action *action = actions_to_translate[k];
        Effect *grounded_sensing_model = action->sensing_model_->ground();
        delete action->sensing_model_;
        action->sensing_model_ = grounded_sensing_model;
        translation_for_multivalued_variable_formulation(*action, k);
        //delete action; // NEED FIX: guess: delete params that are needed in sensing model (invariants)
    }
}

static void clone_parameters(const PDDL_Base::var_symbol_vec &param, PDDL_Base::var_symbol_vec &clone) {
    clone.clear();
    clone.reserve(param.size());
    for( size_t k = 0; k < param.size(); ++k ) {
        clone.push_back(dynamic_cast<PDDL_Base::VariableSymbol*>(param[k]->clone()));
        if( clone.back() == 0 ) {
            cout << "error: parameter conversion failed for " << *param[k] << endl;
            exit(255);
        }
    }
}

static void remap_parameters(PDDL_Base::condition_vec &vec, const PDDL_Base::var_symbol_vec &old_param, const PDDL_Base::var_symbol_vec &new_param) {
    for( size_t k = 0; k < vec.size(); ++k )
        const_cast<PDDL_Base::Condition*>(vec[k])->remap_parameters(old_param, new_param);
}

void PDDL_Base::translation_for_multivalued_variable_formulation(Action &action, size_t index) {
    And precondition;
    AndEffect effect;

    if( action.effect_ != 0 ) {
        // Action that execute only the effects on state variables (i.e. no sensing model involved)
        Action *effect_action = new Action(strdup((string(action.print_name_) + "__effect__").c_str()));
        clone_parameters(action.param_, effect_action->param_);

        // precondition
        if( action.precondition_ != 0 ) precondition.push_back(action.precondition_);
        precondition.push_back(new Literal(*normal_execution_.first));  // (normal-execution)
        effect_action->precondition_ = precondition.ground();
        delete precondition.back();
        precondition.clear();

        // effect
        effect.push_back(action.effect_);
        effect.push_back(new AtomicEffect(*normal_execution_.second));  // (not (normal-execution))
        effect.push_back(new AtomicEffect(*need_sense_[index].first));  // (need-set-sense <param>)
        effect_action->effect_ = effect.ground();
        delete effect[2];
        delete effect[1];
        effect.clear();

        // remap parameters and insert
        const_cast<Condition*>(effect_action->precondition_)->remap_parameters(action.param_, effect_action->param_);
        const_cast<Effect*>(effect_action->effect_)->remap_parameters(action.param_, effect_action->param_);
        dom_actions_.push_back(effect_action);
        cout << *effect_action;

        // Action that computes the effects on observables (i.e. sensing model)
        Action *set_sensing_action = new Action(strdup((string(action.print_name_) + "__set_sensing__").c_str()));
        clone_parameters(action.param_, set_sensing_action->param_);

        // precondition
        precondition.push_back(new Literal(*need_sense_[index].first)); // (need-set-sense <param>)
        set_sensing_action->precondition_ = precondition.ground();
        delete precondition[0];
        precondition.clear();

        // effect
        effect.push_back(action.sensing_model_);
        effect.push_back(new AtomicEffect(*sensing_.first));            // (sensing-is-on)
        effect.push_back(new AtomicEffect(*need_post_[index].first));   // (need-post <param>)
        effect.push_back(new AtomicEffect(*need_sense_[index].second)); // (not (need-set-sense <param>))
        set_sensing_action->effect_ = effect.ground();
        delete effect[3];
        delete effect[2];
        delete effect[1];
        effect.clear();

        // remap parameters and insert
        const_cast<Condition*>(set_sensing_action->precondition_)->remap_parameters(action.param_, set_sensing_action->param_);
        const_cast<Effect*>(set_sensing_action->effect_)->remap_parameters(action.param_, set_sensing_action->param_);
        dom_actions_.push_back(set_sensing_action);
        //Effect *remaped_sensing_model = action.sensing_model_->ground();
        //remaped_sensing_model->remap_parameters(action.param_, set_sensing_action->param_);
        sensing_models_.push_back(make_pair(make_pair(new var_symbol_vec(action.param_), action.sensing_model_->ground()), index));
        cout << *set_sensing_action;

        // Post action that re-establish normal execution
        Action *post_action = new Action(strdup((string(action.print_name_) + "__post__").c_str()));
        clone_parameters(action.param_, post_action->param_);

        // precondition
        precondition.push_back(new Literal(*need_post_[index].first));  // (need-post <param>)
        post_action->precondition_ = precondition.ground();
        delete precondition[0];
        precondition.clear();

        // effect
        effect.push_back(new AtomicEffect(*normal_execution_.first));   // (normal-execution)
        effect.push_back(new AtomicEffect(*sensing_.second));           // (not (sensing-is-on))
        effect.push_back(new AtomicEffect(*need_post_[index].second));  // (not (need-post <param))
        post_action->effect_ = effect.ground();
        delete effect[2];
        delete effect[1];
        delete effect[0];
        effect.clear();

        // remap parameters and insert
        const_cast<Condition*>(post_action->precondition_)->remap_parameters(action.param_, post_action->param_);
        const_cast<Effect*>(post_action->effect_)->remap_parameters(action.param_, post_action->param_);
        dom_actions_.push_back(post_action);
        cout << *post_action;
    } else {
        // Action that computes the effects on observables (i.e. sensing model)
        Action *set_sensing_action = new Action(strdup((string(action.print_name_) + "__set_sensing__").c_str()));
        clone_parameters(action.param_, set_sensing_action->param_);

        // precondition
        if( action.precondition_ != 0 ) precondition.push_back(action.precondition_);
        precondition.push_back(new Literal(*normal_execution_.first));  // (normal-execution)
        set_sensing_action->precondition_ = precondition.ground();
        delete precondition.back();
        precondition.clear();

        // effect
        effect.push_back(action.sensing_model_);
        effect.push_back(new AtomicEffect(*normal_execution_.second));  // (not (normal-execution))
        effect.push_back(new AtomicEffect(*sensing_.first));            // (sensing-is-on)
        effect.push_back(new AtomicEffect(*need_post_[index].first));   // (need-post <param>)
        set_sensing_action->effect_ = effect.ground();
        delete effect[3];
        delete effect[2];
        delete effect[1];
        effect.clear();

        // remap parameters and insert
        const_cast<Condition*>(set_sensing_action->precondition_)->remap_parameters(action.param_, set_sensing_action->param_);
        const_cast<Effect*>(set_sensing_action->effect_)->remap_parameters(action.param_, set_sensing_action->param_);
        dom_actions_.push_back(set_sensing_action);
        //Effect *remaped_sensing_model = action.sensing_model_->ground();
        //remaped_sensing_model->remap_parameters(action.param_, set_sensing_action->param_);
        sensing_models_.push_back(make_pair(make_pair(new var_symbol_vec(action.param_), action.sensing_model_->ground()), index));
        cout << *set_sensing_action;

        // Post action that re-establish normal execution
        Action *post_action = new Action(strdup((string(action.print_name_) + "__post__").c_str()));
        clone_parameters(action.param_, post_action->param_);

        // precondition
        precondition.push_back(new Literal(*need_post_[index].first));  // (need-post <param>)
        post_action->precondition_ = precondition.ground();
        delete precondition[0];
        precondition.clear();

        // effect
        effect.push_back(new AtomicEffect(*normal_execution_.first));   // (normal-execution)
        effect.push_back(new AtomicEffect(*sensing_.second));           // (not (sensing-is-on))
        effect.push_back(new AtomicEffect(*need_post_[index].second));  // (not (need-post <param))
        post_action->effect_ = effect.ground();
        delete effect[2];
        delete effect[1];
        delete effect[0];
        effect.clear();

        // remap parameters and insert
        const_cast<Condition*>(post_action->precondition_)->remap_parameters(action.param_, post_action->param_);
        const_cast<Effect*>(post_action->effect_)->remap_parameters(action.param_, post_action->param_);
        dom_actions_.push_back(post_action);
        cout << *post_action;
    }
}

void PDDL_Base::create_invariants_for_multivalued_variables() {
    if( !multivalued_variable_translation_ ) return;
    cout << "mvv-translation: creating invariants for multivalued variables..." << endl;

    Invariant exactly_one(Invariant::EXACTLY_ONE);
    Invariant at_least_one(Invariant::AT_LEAST_ONE);

    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        if( dynamic_cast<StateVariable*>(multivalued_variables_[k]) != 0 ) {
            // for each state variable with domain size > 1, generate (exactly-one <values>)
            StateVariable &var = *static_cast<StateVariable*>(multivalued_variables_[k]);
            if( var.grounded_values_.size() > 1 ) {
                exactly_one.reserve(var.grounded_values_.size());
                clone_parameters(var.param_, exactly_one.param_);
                for( size_t i = 0; i < var.grounded_values_.size(); ++i )
                    exactly_one.push_back(new Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[i])));
                remap_parameters(exactly_one, var.param_, exactly_one.param_);
                dom_init_.push_back(new InitInvariant(exactly_one));
                cout << "invariant1 for var (ptr=" << dom_init_.back() << "): " << exactly_one << endl;
                //cout << "variable '" << var.print_name_ << "': " << exactly_one << endl;
                exactly_one.clear();
            } else {
                at_least_one.reserve(2);
                clone_parameters(var.param_, at_least_one.param_);
                Literal *literal = new Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[0]));
                at_least_one.push_back(literal);
                literal = new Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[0]));
                literal->negated_ = true;
                at_least_one.push_back(literal);
                remap_parameters(at_least_one, var.param_, at_least_one.param_);
                dom_init_.push_back(new InitInvariant(at_least_one));
                cout << "invariant2 for var (ptr=" << dom_init_.back() << "): " << at_least_one << endl;
                //cout << "variable '" << var.print_name_ << "': " << at_least_one << endl;
                at_least_one.clear();
            }
        } else {
            // for each observable variable, and values <value-i> and <value-j>
            // generate (at-least-one (not (sensing-is-on)) (not <value-i>) (not <value-j>))
            ObsVariable &var = *static_cast<ObsVariable*>(multivalued_variables_[k]);
            if( var.grounded_values_.size() > 1 ) {
                for( size_t i = 0; i < var.grounded_values_.size(); ++i ) {
                    for( size_t j = i + 1; j < var.grounded_values_.size(); ++j ) {
                        at_least_one.reserve(3);
                        clone_parameters(var.param_, at_least_one.param_);
                        at_least_one.push_back(new Literal(*sensing_.second));
                        Literal *literal = new Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[i]));
                        literal->negated_ = true;
                        at_least_one.push_back(literal);
                        literal = new Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[j]));
                        literal->negated_ = true;
                        at_least_one.push_back(literal);
                        remap_parameters(at_least_one, var.param_, at_least_one.param_);
                        dom_init_.push_back(new InitInvariant(at_least_one));
                        cout << "invariant3 for var (ptr=" << dom_init_.back() << "): " << at_least_one << endl;
                        //cout << "variable '" << var.print_name_ << "': " << at_least_one << endl;
                        at_least_one.clear();
                    }
                }
            } else {
                at_least_one.reserve(2);
                clone_parameters(var.param_, at_least_one.param_);
                Literal *literal = new Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[0]));
                at_least_one.push_back(literal);
                literal = new Literal(*static_cast<const AtomicEffect*>(var.grounded_values_[0]));
                literal->negated_ = true;
                at_least_one.push_back(literal);
                remap_parameters(at_least_one, var.param_, at_least_one.param_);
                dom_init_.push_back(new InitInvariant(at_least_one));
                cout << "invariant4 for var (ptr=" << dom_init_.back() << "): " << at_least_one << endl;
                //cout << "variable '" << var.print_name_ << "': " << at_least_one << endl;
                at_least_one.clear();
            }
        }
    }
}

void PDDL_Base::create_invariants_for_sensing_model() {
    if( !multivalued_variable_translation_ ) return;
    cout << "mvv-translation: creating invariants for sensing model" << endl;

    for( size_t k = 0; k < sensing_models_.size(); ++k ) {
        if( dynamic_cast<const AndEffect*>(sensing_models_[k].first.second) == 0 ) {
            AndEffect *effect = new AndEffect;
            effect->push_back(sensing_models_[k].first.second);
            sensing_models_[k].first.second = effect;
        }

        const var_symbol_vec &parameters = *sensing_models_[k].first.first;
        const AndEffect &effect = *static_cast<const AndEffect*>(sensing_models_[k].first.second);
        size_t index = sensing_models_[k].second;

        // collect conditions for each observable literal (in head of conditional effects)
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
                        sensing_map[h->print_name()].push_back(conditional_effect.condition_->ground());
                        sensed_literal[h->print_name()] = static_cast<AtomicEffect*>(h->ground());
                    }
                } else {
                    assert(dynamic_cast<const AtomicEffect*>(conditional_effect.effect_) != 0);
                    const AtomicEffect &head = *static_cast<const AtomicEffect*>(conditional_effect.effect_);
                    sensing_map[head.print_name()].push_back(conditional_effect.condition_->ground());
                    sensed_literal[head.print_name()] = static_cast<AtomicEffect*>(head.ground());
                }
            } else {
                assert(dynamic_cast<const AtomicEffect*>(effect[i]) != 0);
                //const AtomicEffect &atomic_effect = *static_cast<const AtomicEffect*>(effect[i]);
                cout << "WARNING-1: unconditional sensing for " << *effect[i] << endl;
                exit(255);
            }
        }

        // for each observable literal L with rules C1 => L, ..., Cn => L:
        //
        // 1) create (invariant (not (need-post <param>)) ~L C1 C2 .. Cn) representing
        //    the implication L => C1 v C2 v ... v Cn
        //
        // 2) create (invariant (not (need-post <param>)) L ~Ci), for each i, representing
        //    the implication ~L => ~Ci

        Invariant invariant1(Invariant::AT_LEAST_ONE);
        for( map<string, condition_vec>::iterator it = sensing_map.begin(); it != sensing_map.end(); ++it ) {
            bool invariant1_is_good = true;
            clone_parameters(parameters, invariant1.param_);
            invariant1.push_back(new Literal(*need_post_[index].second));
            Literal *literal = new Literal(*sensed_literal[it->first]);
            literal->negated_ = !literal->negated_;
            invariant1.push_back(literal);
            for( size_t i = 0; i < it->second.size(); ++i ) {
                if( dynamic_cast<const Literal*>(it->second[i]) != 0 ) {
                    const Literal &single_condition = *static_cast<const Literal*>(it->second[i]);
                    invariant1.push_back(new Literal(single_condition));

                    Invariant invariant2(Invariant::AT_LEAST_ONE);
                    clone_parameters(parameters, invariant2.param_);
                    invariant2.push_back(new Literal(*need_post_[index].second));
                    invariant2.push_back(new Literal(*sensed_literal[it->first]));
                    Literal *literal = new Literal(single_condition);
                    literal->negated_ = !literal->negated_;
                    invariant2.push_back(literal);
                    remap_parameters(invariant2, parameters, invariant2.param_);
                    dom_init_.push_back(new InitInvariant(invariant2));
                    //cout << "invariant1 for literal " << it->first << ": " << invariant2 << endl;
                    cout << "inv1 (ptr=" << dom_init_.back() << "): " << invariant2 << endl;
                    invariant2.clear();
                } else {
                    invariant1_is_good = false;
                    assert(static_cast<const And*>(it->second[i]) != 0);
                    const And &condition = *static_cast<const And*>(it->second[i]);

                    //cout << "WARNING: condition '" << condition << "' is not a single literal" << endl
                    //     << "         generating only invariants of type ~L => ~Ci" << endl;

                    Invariant invariant2(Invariant::AT_LEAST_ONE);
                    clone_parameters(parameters, invariant2.param_);
                    invariant2.push_back(new Literal(*need_post_[index].second));
                    invariant2.push_back(new Literal(*sensed_literal[it->first]));
                    for( size_t j = 0; j < condition.size(); ++j ) {
                        assert(dynamic_cast<const Literal*>(condition[j]) != 0);
                        const Literal &single_condition = *static_cast<const Literal*>(condition[j]);
                        Literal *literal = new Literal(single_condition);
                        literal->negated_ = !literal->negated_;
                        invariant2.push_back(literal);
                    }
                    remap_parameters(invariant2, parameters, invariant2.param_);
                    dom_init_.push_back(new InitInvariant(invariant2));
                    cout << "inv2 (ptr=" << dom_init_.back() << "): " << invariant2 << endl;
                    invariant2.clear();
                    //exit(255);
                }
            }
            if( invariant1_is_good ) {
                remap_parameters(invariant1, parameters, invariant1.param_);
                dom_init_.push_back(new InitInvariant(invariant1));
                cout << "inv3 (ptr=" << dom_init_.back() << "): " << invariant1 << endl;
            } else {
                for( size_t i = 0; i < invariant1.size(); ++i )
                    ;//delete invariant1[i];
            }
            invariant1.clear();
        }
    }
}

void PDDL_Base::instantiate(Instance &ins) const {

    // create instance
    const char *dn = tab_.table_char_map().strdup(domain_name_ ? domain_name_ : "??");
    const char *pn = tab_.table_char_map().strdup(problem_name_ ? problem_name_ : "??");
    ins.name = new InstanceName(dn, pn);
    delete[] dn;
    delete[] pn;

    // calculate strongly-static predicates. Used to instantiate
    // actions more efficiently by not generating those
    // with false static preconditions.
    calculate_strongly_static_predicates();

    // set atom (disable-actions) (only when processing CLG syntax)
    if( disable_actions_atom_ != 0 ) {
        Instance::Atom *p = disable_actions_atom_->find_prop(ins, false, true);
        ins.disable_actions_atom_index = p->index;
    }

    // instantiate initial situation.
    for( size_t k = 0; k < dom_init_.size(); ++k )
        dom_init_[k]->instantiate(ins);

    // instantiate hidden initial situation
    cout << "instantiating " << dom_hidden_.size() << " hidden state(s)" << endl;
    ins.hidden.resize(dom_hidden_.size());
    for( size_t k = 0; k < dom_hidden_.size(); ++k ) {
        for( size_t j = 0; j < dom_hidden_[k].size(); ++j ) {
            assert(dynamic_cast<const InitLiteral*>(dom_hidden_[k][j]) != 0);
            static_cast<const InitLiteral*>(dom_hidden_[k][j])->instantiate(ins, ins.hidden[k]);
        }
    }

    // instantiate goal situation
    if( dom_goal_ != 0 )
        dom_goal_->instantiate(ins, ins.goal_literals);

    // instantiate actions
    for( size_t k = 0; k < dom_actions_.size(); ++k )
        dom_actions_[k]->instantiate(ins);

    // instantiate sensors
    for( size_t k = 0; k < dom_sensors_.size(); ++k )
        dom_sensors_[k]->instantiate(ins);

    // instantiate axioms
    for( size_t k = 0; k < dom_axioms_.size(); ++k )
        dom_axioms_[k]->instantiate(ins);

    // instantiate observables
    for( size_t k = 0; k < dom_observables_.size(); ++k )
        dom_observables_[k]->instantiate(ins);

    // instantiate sticky
    for( size_t k = 0; k < dom_stickies_.size(); ++k )
        dom_stickies_[k]->instantiate(ins);
}

PDDL_Base::PredicateSymbol* PDDL_Base::find_type_predicate(Symbol *type_sym) {
    for (size_t k = 0; k < dom_predicates_.size(); ++k) {
        if (dom_predicates_[k]->print_name_ == type_sym->print_name_)
            return dom_predicates_[k];
    }
    cerr << "error: no type predicate found for type "
         << type_sym->print_name_ << endl;
    exit(255);
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

void PDDL_Base::TypeSymbol::print(ostream &os) const {
    os << "(:type " << print_name_;
    if( sym_type_ ) os << " - " << sym_type_->print_name_;
    os << "): {";
    for( size_t k = 0; k < elements_.size(); ++k )
        os << *elements_[k] << ",";
    os << "}";
}

PDDL_Base::Symbol* PDDL_Base::TypeSymbol::clone() const {
    TypeSymbol *cl = new TypeSymbol(strdup(print_name_));
    cl->sym_type_ = sym_type_;
    copy_symbol_vec<Symbol*>(elements_, cl->elements_);
    return cl;
}
 
PDDL_Base::Symbol* PDDL_Base::VariableSymbol::clone() const {
    //std::cout << "clone vsym: this=" << this << std::endl;
    VariableSymbol *cl = new VariableSymbol(strdup(print_name_));
    cl->sym_type_ = sym_type_;
    cl->value_ = value_;
    //cl->sym_type_ = sym_type_ != 0 ? sym_type_->clone() : 0;
    //cl->value_ = value_ != 0 ? value_->clone() : 0;
    return cl;
}

void PDDL_Base::VariableSymbol::print(std::ostream &os) const {
    if( value_ == 0 ) {
        os << print_name_;
        if( sym_type_ ) os << " - " << sym_type_->print_name_;
    } else
        os << *value_;
}
 
PDDL_Base::Symbol* PDDL_Base::PredicateSymbol::clone() const {
    PredicateSymbol *cl = new PredicateSymbol(strdup(print_name_));
    cl->sym_type_ = sym_type_;
    cl->strongly_static_ = strongly_static_;
    copy_symbol_vec<VariableSymbol*>(param_, cl->param_);
    return cl;
}

void PDDL_Base::PredicateSymbol::print(ostream &os) const {
    os << "(:predicate " << print_name_;
    for( size_t k = 0; k < param_.size(); ++k )
        os << " " << *param_[k];
    os << ")";
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

void PDDL_Base::Atom::remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
#if 0
    for( size_t k = 0; k < param_.size(); ++k ) {
        for( size_t i = 0; i < old_param.size(); ++i ) {
            if( param_[k] == old_param[i] ) {
                param_[k] = new_param[i];
                break;
            }
        }
    }
#endif
}

bool PDDL_Base::Atom::operator==(const Atom &atom) const {
    if( pred_ != atom.pred_ ) return false;
    if( param_.size() != atom.param_.size() ) return false;
    for( size_t k = 0; k < param_.size(); ++k )
        if( param_[k] != atom.param_[k] ) return false;
    return true;
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
        Instance::Atom &p = ins.new_atom(new CopyName(a_name.to_string()));
        r->val = &p;
    }
    return static_cast<Instance::Atom*>(r->val);
}

PDDL_Base::Atom* PDDL_Base::Atom::ground() const {
    Atom *result = new Atom(*this);
    for( size_t k = 0; k < result->param_.size(); ++k ) {
        if( (result->param_[k]->sym_class_ == sym_variable) &&
            (static_cast<VariableSymbol*>(result->param_[k])->value_ != 0) ) {
            VariableSymbol *new_var = new VariableSymbol("?x");
            new_var->value_ = static_cast<VariableSymbol*>(result->param_[k])->value_;
            result->param_[k] = new_var;
        }
    }
    return result;
}

void PDDL_Base::Atom::instantiate(Instance &ins, index_set &atoms) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !negated_ )
        atoms.insert(1 + p->index);
    else
        atoms.insert(-(1 + p->index));
}

string PDDL_Base::Atom::print_name(bool extra_neg) const {
    ostringstream name;
    extra_neg = extra_neg ? !negated_ : negated_;
    if( extra_neg ) name << "(not ";
    name << "(" << pred_->print_name_;
    for (size_t k = 0; k < param_.size(); ++k) {
        if( (param_[k]->sym_class_ == sym_variable) && (static_cast<VariableSymbol*>(param_[k])->value_ != 0) )
            name << " " << *static_cast<VariableSymbol*>(param_[k])->value_;
        else
            name << " " << *param_[k];
    }
    name << ")";
    if( extra_neg ) name << ")";
    return name.str();
}

void PDDL_Base::Atom::print(ostream &os, bool extra_neg) const {
    os << print_name(extra_neg);
}

void PDDL_Base::Literal::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    Atom::remap_parameters(old_param, new_param);
}

void PDDL_Base::Literal::remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    Atom::remap_parameters_by_name(old_param, new_param);
}

void PDDL_Base::Literal::instantiate(Instance &ins, index_set &condition) const {
    Atom::instantiate(ins, condition);
}

PDDL_Base::Condition* PDDL_Base::Literal::ground() const {
    Atom *atom = Atom::ground();
    Literal *result = new Literal(*atom);
    delete atom;
    return result;
}

void PDDL_Base::EQ::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < old_param.size(); ++k ) {
        if( first == old_param[k] ) {
            first = dynamic_cast<const VariableSymbol*>(new_param[k]);
            if( first == 0 ) {
                cout << "error: type conversion error in " << *this
                     << " for " << *old_param[k] << endl;
                exit(255);
            }
            break;
        }
    }
    for( size_t k = 0; k < old_param.size(); ++k ) {
        if( second == old_param[k] ) {
            second = dynamic_cast<const VariableSymbol*>(new_param[k]);
            if( second == 0 ) {
                cout << "error: type conversion error in " << *this
                     << " for " << *old_param[k] << endl;
                exit(255);
            }
            break;
        }
    }
}

void PDDL_Base::EQ::remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
}

PDDL_Base::Condition* PDDL_Base::EQ::ground() const {
    EQ *result = new EQ(first, second, negated_);
    if( (first->sym_class_ == sym_variable) && (first->value_ != 0) ) {
        VariableSymbol *new_var = new VariableSymbol("?x");
        new_var->value_ = first->value_;
        result->first = new_var;
    }
    if( (second->sym_class_ == sym_variable) && (second->value_ != 0) ) {
        VariableSymbol *new_var = new VariableSymbol("?x");
        new_var->value_ = second->value_;
        result->second = new_var;
    }

    // check if result can be reduced to a boolean constant
    if( (first->value_ == 0) || (second->value_ == 0) ) {
        return result;
    } else {
        bool value = result->first->value_ == result->second->value_;
        value = negated_ ? !value : value;
        if( result->first != first ) delete result->first;
        if( result->second != second ) delete result->second;
        delete result;
        return new Constant(value);
    }
}

void PDDL_Base::EQ::print(std::ostream &os) const {
    if( negated_ ) os << "(not ";
    os << "(= " << *first << " " << *second << ")";
    if( negated_ ) os << ")";
}
 
void PDDL_Base::And::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < size(); ++k )
        const_cast<Condition*>((*this)[k])->remap_parameters(old_param, new_param);
}

void PDDL_Base::And::remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < size(); ++k )
        const_cast<Condition*>((*this)[k])->remap_parameters_by_name(old_param, new_param);
}

void PDDL_Base::And::instantiate(Instance &ins, index_set &condition) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->instantiate(ins, condition);
}

PDDL_Base::Condition* PDDL_Base::And::ground() const {
    And *result = new And;
    for( size_t k = 0; k < size(); ++k ) {
        Condition *item = (*this)[k]->ground();
        if( dynamic_cast<Constant*>(item) != 0 ) {
            Constant &constant = *static_cast<Constant*>(item);
            if( constant.value_ ) {
                delete item;
            } else {
                delete item;
                delete result;
                return new Constant(false);
            }
        } else if( dynamic_cast<And*>(item) != 0 ) {
            And &item_list = *static_cast<And*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                result->push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else {
            result->push_back(item);
        }
    }

    // check if result can be reduced to constant or single condition
    if( result->empty() ) {
        delete result;
        return new Constant(true);
    } else if( result->size() == 1 ) {
        Condition *single = const_cast<Condition*>((*result)[0]);
        result->clear();
        delete result;
        return single;
    } else {
        return result;
    }
}

void PDDL_Base::And::print(std::ostream &os) const {
    os << "(and";
    for( size_t k = 0; k < size(); ++k )
        os << " " << *(*this)[k];
    os << ")";
}

void PDDL_Base::AtomicEffect::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    Atom::remap_parameters(old_param, new_param);
}

void PDDL_Base::AtomicEffect::remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    Atom::remap_parameters_by_name(old_param, new_param);
}

void PDDL_Base::AtomicEffect::instantiate(Instance &ins, index_set &eff, Instance::when_vec&) const {
    Atom::instantiate(ins, eff);
}

PDDL_Base::Effect* PDDL_Base::AtomicEffect::ground() const {
    Atom *atom = Atom::ground();
    AtomicEffect *result = new AtomicEffect(*atom);
    delete atom;
    return result;
}

bool PDDL_Base::AtomicEffect::is_strongly_static(const PredicateSymbol &p) const {
    assert((pred_->print_name_ != p.print_name_) || (pred_ == &p));
    assert((pred_->print_name_ == p.print_name_) || (pred_ != &p));
    return pred_ != &p;
}

void PDDL_Base::AndEffect::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < size(); ++k )
        const_cast<Effect*>((*this)[k])->remap_parameters(old_param, new_param);
}

void PDDL_Base::AndEffect::remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    for( size_t k = 0; k < size(); ++k )
        const_cast<Effect*>((*this)[k])->remap_parameters_by_name(old_param, new_param);
}

void PDDL_Base::AndEffect::instantiate(Instance &ins, index_set &eff, Instance::when_vec &when) const {
    for( size_t k = 0; k < size(); ++k )
        (*this)[k]->instantiate(ins, eff, when);
}

PDDL_Base::Effect* PDDL_Base::AndEffect::ground() const {
    AndEffect *result = new AndEffect;
    for( size_t k = 0; k < size(); ++k ) {
        Effect *item = (*this)[k]->ground();
        if( dynamic_cast<NullEffect*>(item) != 0 ) {
            delete item;
        } else if( dynamic_cast<AndEffect*>(item) != 0 ) {
            AndEffect &item_list = *static_cast<AndEffect*>(item);
            for( size_t i = 0; i < item_list.size(); ++i)
                result->push_back(item_list[i]);
            item_list.clear();
            delete item;
        } else {
            result->push_back(item);
        }
    }

    // check if result can be reduced to null or single effect
    if( result->empty() ) {
        delete result;
        return new NullEffect;
    } else if( result->size() == 1 ) {
        Effect *single = const_cast<Effect*>((*result)[0]);
        result->clear();
        delete result;
        return single;
    } else {
        return result;
    }
}

bool PDDL_Base::AndEffect::is_strongly_static(const PredicateSymbol &p) const {
    bool strongly_static = true;
    for( size_t k = 0; strongly_static && (k < size()); ++k )
        strongly_static = (*this)[k]->is_strongly_static(p);
    return strongly_static;
}
void PDDL_Base::AndEffect::print(std::ostream &os) const {
    os << "(and";
    for( size_t k = 0; k < size(); ++k )
        os << " " << *(*this)[k];
    os << ")";
}

void PDDL_Base::ConditionalEffect::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    const_cast<Condition*>(condition_)->remap_parameters(old_param, new_param);
    const_cast<Effect*>(effect_)->remap_parameters(old_param, new_param);
}

void PDDL_Base::ConditionalEffect::remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    const_cast<Condition*>(condition_)->remap_parameters_by_name(old_param, new_param);
    const_cast<Effect*>(effect_)->remap_parameters_by_name(old_param, new_param);
}

void PDDL_Base::ConditionalEffect::instantiate(Instance &ins, index_set &eff, Instance::when_vec &when) const {
    Instance::When single_when;
    condition_->instantiate(ins, single_when.condition);
    effect_->instantiate(ins, single_when.effect, when);
    when.push_back(single_when);
}

PDDL_Base::Effect* PDDL_Base::ConditionalEffect::ground() const {
    Effect *grounded_effect = effect_->ground();
    if( dynamic_cast<NullEffect*>(grounded_effect) != 0 ) {
        return grounded_effect;
    } else {
        Condition *grounded_condition = condition_->ground();
        if( dynamic_cast<Constant*>(grounded_condition) != 0 ) {
            Constant &constant = *static_cast<Constant*>(grounded_condition);
            if( constant.value_ ) {
                delete grounded_condition;
                return grounded_effect;
            } else {
                delete grounded_condition;
                delete grounded_effect;
                return new NullEffect;
            }
        } else {
            return new ConditionalEffect(grounded_condition, grounded_effect);
        }
    }
}

bool PDDL_Base::ConditionalEffect::is_strongly_static(const PredicateSymbol &p) const {
    return effect_->is_strongly_static(p);
}

void PDDL_Base::ConditionalEffect::print(std::ostream &os) const {
    os << "(when " << *condition_ << " " << *effect_ << ")";
}

void PDDL_Base::ForallEffect::remap_parameters(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    const_cast<Effect*>(effect_)->remap_parameters(old_param, new_param);
}

void PDDL_Base::ForallEffect::remap_parameters_by_name(const var_symbol_vec &old_param, const var_symbol_vec &new_param) {
    const_cast<Effect*>(effect_)->remap_parameters_by_name(old_param, new_param);
}

void PDDL_Base::ForallEffect::instantiate(Instance &ins, index_set &eff, Instance::when_vec &when) const {
    cout << "error: instantiate() should not be called on ForallEffect: first ground the effect!" << endl;
    exit(255);
}

PDDL_Base::Effect* PDDL_Base::ForallEffect::ground() const {
    result_stack.push_back(new AndEffect);
    enumerate(true);
    result_stack.back()->reserve(count_);
    enumerate();
    AndEffect *result = result_stack.back();
    result_stack.pop_back();

    // check if result can be reduced to null or single effect
    if( result->empty() ) {
        delete result;
        return new NullEffect;
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
    Effect *item = effect_->ground();
    if( dynamic_cast<NullEffect*>(item) != 0 ) {
        delete item;
    } else if( dynamic_cast<AndEffect*>(item) != 0 ) {
        AndEffect &item_list = *static_cast<AndEffect*>(item);
        for( size_t i = 0; i < item_list.size(); ++i)
            result_stack.back()->push_back(item_list[i]);
        item_list.clear();
        delete item;
    } else
        result_stack.back()->push_back(item);
}

bool PDDL_Base::ForallEffect::is_strongly_static(const PredicateSymbol &p) const {
    return effect_->is_strongly_static(p);
}

void PDDL_Base::ForallEffect::print(std::ostream &os) const {
    os << "(forall (";
    for( size_t k = 0; k < param_.size(); ++k )
        os << (k > 0 ? " " : "") << *param_[k];
    os << ") " << *effect_ << ")";
}

void PDDL_Base::Invariant::process_instance() const {
    Instance::Invariant invariant(type_);
    for( size_t k = 0; k < size(); ++k ) {
        assert(dynamic_cast<const Literal*>((*this)[k]) != 0);
        const Literal *literal = static_cast<const Literal*>((*this)[k]->ground());
        Instance::Atom *p = literal->find_prop(*instance_ptr_, false, true);
        if( !literal->negated_ )
            invariant.push_back(1 + p->index);
        else
            invariant.push_back(-(1 + p->index));
    }
    invariant_vec_ptr_->push_back(invariant);
}

void PDDL_Base::Invariant::print(std::ostream &os) const {
    if( type_ == AT_LEAST_ONE ) os << "(at-least-one";
    else if( type_ == AT_MOST_ONE ) os << "(at-most-one";
    else os << "(exactly-one";

    if( !param_.empty() ) {
        os << " (";
        for( size_t k = 0; k < param_.size(); ++k )
            os << (k > 0 ? " " : "") << *param_[k];
        os << ")";
    }

    for( size_t k = 0; k < size(); ++k )
        os << " " << *(*this)[k];
    os << ")";
}

void PDDL_Base::Clause::instantiate(Instance &ins, Instance::Clause &clause) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        Instance::Atom *p = lit->find_prop(ins, false, true);
        if( !lit->negated_ )
            clause.push_back(1 + p->index);
        else
            clause.push_back(-(1 + p->index));
    }
}

void PDDL_Base::Clause::print(std::ostream &os) const {
    os << "(or";
    for( size_t k = 0; k < size(); ++k )
        os << " " << *(*this)[k];
    os << ")";
}
 
void PDDL_Base::Oneof::instantiate(Instance &ins, Instance::Oneof &oneof) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        Instance::Atom *p = lit->find_prop(ins, false, true);
        if( !lit->negated_ )
            oneof.push_back(1 + p->index);
        else
            oneof.push_back(-(1 + p->index));
    }
}

void PDDL_Base::Oneof::print(std::ostream &os) const {
    os << "(oneof";
    for( size_t k = 0; k < size(); ++k )
        os << " " << *(*this)[k];
    os << ")";
}

void PDDL_Base::InitLiteral::instantiate(Instance &ins, Instance::Init &state) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !negated_ ) {
        state.literals.insert(1 + p->index);
    } else {
        state.literals.insert(-(1 + p->index));
    }
}

void PDDL_Base::InitLiteral::instantiate(Instance &ins) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !negated_ ) {
        ins.init.literals.insert(1 + p->index);
    } else {
        ins.init.literals.insert(-(1 + p->index));
    }
}

bool PDDL_Base::InitLiteral::is_strongly_static(const PredicateSymbol &p) const {
    return true;
}

void PDDL_Base::InitInvariant::instantiate(Instance &ins) const {
    ins.init.invariants.reserve(800000);
    cout << "About to instantiate invariant (" << this << "): " << *(const Invariant*)this << endl;
    Instance::invariant_vec instantiated_invariants;
    enumerate(true);
    instantiated_invariants.reserve(count_);
    invariant_vec_ptr_ = &instantiated_invariants;
    instance_ptr_ = &ins;
    enumerate();

    // convert all instantiated invariants to AT_LEAST_ONE type: first
    // count how many there will be to reserve space, and then do the
    // conversion.
    size_t count = 0;
    for( int pass = 0; pass < 2; ++pass ) {
        for( size_t k = 0; k < instantiated_invariants.size(); ++k ) {
            Instance::Invariant &invariant = instantiated_invariants[k];
            if( invariant.type != AT_LEAST_ONE ) {
                if( pass == 0 ) {
                    size_t n = invariant.size() * (invariant.size() - 1);
                    count += n >> 1;
                } else {
                    for( size_t i = 0; i < invariant.size(); ++i ) {
                        for( size_t j = 1 + i; j < invariant.size(); ++j ) {
                            Instance::Invariant implied_invariant;
                            implied_invariant.type = AT_LEAST_ONE;
                            implied_invariant.push_back(-invariant[i]);
                            implied_invariant.push_back(-invariant[j]);
                            ins.init.invariants.push_back(implied_invariant);
                        }
                    }
                }
            }
            if( invariant.type != AT_MOST_ONE ) {
                if( pass == 0 ) {
                    ++count;
                } else {
                    invariant.type = AT_LEAST_ONE;
                    ins.init.invariants.push_back(invariant);
                }
            }
        }

        // if pass == 0, reserve space as next iteration creates the
        // invariants
        if( pass == 0 ) ins.init.invariants.reserve(ins.init.invariants.size() + count);
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

void PDDL_Base::InitClause::instantiate(Instance &ins) const {
    Instance::Clause clause;
    Clause::instantiate(ins, clause);
    ins.init.clauses.push_back(clause);
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

void PDDL_Base::InitOneof::instantiate(Instance &ins) const {
    Instance::Oneof oneof;
    Oneof::instantiate(ins, oneof);
    ins.init.oneofs.push_back(oneof);
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

void PDDL_Base::Action::instantiate(Instance &ins) const {
    size_t base = ins.n_actions();
    instance_ptr_ = &ins;
    cout << "instantiating '" << print_name_ << "' ..." << flush;
    enumerate(true);
    cout << " (reserve " << count_ << ") ..." << flush;
    ins.reserve_actions(base + count_);
    enumerate();
    cout << " " << ins.n_actions()-base << " action(s)" << endl;
}

void PDDL_Base::Action::process_instance() const {
    Condition *grounded_precondition = 0;
    if( precondition_ != 0 ) {
        grounded_precondition = precondition_->ground();
        if( dynamic_cast<Constant*>(grounded_precondition) != 0 ) {
            Constant *precondition_value = static_cast<Constant*>(grounded_precondition);
            if( !precondition_value->value_ ) return;
        }
    }

    PDDL_Name name(this, param_, param_.size());
    Instance::Action &act = instance_ptr_->new_action(new CopyName(name.to_string()));
    act.cost = 1;
    //cout << "fully instantiated action " << name << endl;

    if( grounded_precondition != 0 ) {
        grounded_precondition->instantiate(*instance_ptr_, act.precondition);
        //cout << "    pre=" << *grounded_precondition << endl;
        delete grounded_precondition;
    }
    if( effect_ != 0 ) {
        Effect *grounded_effect = effect_->ground();
        grounded_effect->instantiate(*instance_ptr_, act.effect, act.when);
        //cout << "    eff=" << *grounded_effect << endl;
        delete grounded_effect;
    }
    if( observe_ != 0 ) {
        Effect *grounded_observe = observe_->ground();
        //cout << "    obs=" << *grounded_observe << endl;
        delete grounded_observe;
    }
    if( sensing_model_ != 0 ) {
        Effect *grounded_sensing_model = sensing_model_->ground();
        grounded_sensing_model->instantiate(*instance_ptr_, act.effect, act.when);
        //cout << "    sen=" << *grounded_sensing_model << endl;
        delete grounded_sensing_model;
    }
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

void PDDL_Base::Sensor::instantiate(Instance &ins) const {
    size_t base = ins.n_sensors();
    instance_ptr_ = &ins;
    cout << "instantiating '" << print_name_ << "' ..." << flush;
    enumerate(true);
    ins.reserve_sensors(base + count_);
    enumerate();
    cout << " " << ins.n_sensors()-base << " sensor(s)" << endl;
}

void PDDL_Base::Sensor::process_instance() const {
    PDDL_Name name(this, param_, param_.size());
    Instance::Sensor &sensor = instance_ptr_->new_sensor(new CopyName(name.to_string()));
    //cout << "fully instantiated sensor " << name << endl;
    if( condition_ != 0 ) {
        Condition *grounded_condition = condition_->ground();
        grounded_condition->instantiate(*instance_ptr_, sensor.condition);
        //cout << "    :condition " << *grounded_condition << endl;
        delete grounded_condition;
    }
    if( sense_ != 0 ) {
        Effect *grounded_sense = sense_->ground();
        grounded_sense->instantiate(*instance_ptr_, sensor.sense);
        //cout << "    :sense " << *grounded_sense << endl;
        delete grounded_sense;
    }
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

void PDDL_Base::Axiom::instantiate(Instance &ins) const {
    size_t base = ins.n_axioms();
    instance_ptr_ = &ins;
    cout << "instantiating '" << print_name_ << "' ..." << flush;
    enumerate(true);
    ins.reserve_axioms(base + count_);
    enumerate();
    cout << " " << ins.n_axioms()-base << " axiom(s)" << endl;
}

void PDDL_Base::Axiom::process_instance() const {
    PDDL_Name name(this, param_, param_.size());
    Instance::Axiom &axiom = instance_ptr_->new_axiom(new CopyName(name.to_string()));
    //cout << "fully instantiated axiom " << name << endl;
    if( body_ != 0 ) {
        Condition *grounded_body = body_->ground();
        grounded_body->instantiate(*instance_ptr_, axiom.body);
        //cout << "    :body " << *grounded_body << endl;
        delete grounded_body;
    }
    if( head_ != 0 ) {
        Effect *grounded_head = head_->ground();
        grounded_head->instantiate(*instance_ptr_, axiom.head);
        //cout << "    :head " << *grounded_head << endl;
        delete grounded_head;
    }
}

void PDDL_Base::Axiom::print(std::ostream &os) const {
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

void PDDL_Base::Observable::instantiate(Instance &ins) const {
    cout << "instantiating observable ..." << flush;
    for( size_t k = 0; k < observables_.size(); ++k ) {
        Effect *grounded_observable = observables_[k]->ground();
        grounded_observable->instantiate(ins, ins.given_observables);
        delete grounded_observable;
    }
    cout << " ok" << endl;
}


void PDDL_Base::Observable::print(std::ostream &os) const {
    os << "(:observable";
    for( size_t k = 0; k < observables_.size(); ++k )
        os << " " << *observables_[k];
    os << ")";
}

void PDDL_Base::Sticky::instantiate(Instance &ins) const {
    cout << "instantiating sticky ..." << flush;
    for( size_t k = 0; k < stickies_.size(); ++k ) {
        Effect *grounded_sticky = stickies_[k]->ground();
        grounded_sticky->instantiate(ins, ins.given_stickies);
        delete grounded_sticky;
    }
    cout << " ok" << endl;
}

void PDDL_Base::Sticky::print(std::ostream &os) const {
    os << "(:sticky" << endl;
    for( size_t k = 0; k < stickies_.size(); ++k )
        os << " " << *stickies_[k];
    os << ")";
}

void PDDL_Base::Variable::instantiate(vector<Variable*> &grounded_variables) const {
    enumerate(true);
    grounded_variables.reserve(grounded_variables.size() + count_);
    grounded_variables_ptr_ = &grounded_variables;
    enumerate();
}

void PDDL_Base::Variable::process_instance() const {
    PDDL_Name name(this, param_, param_.size());
    Variable *var = make_instance(strdup(name.to_string().c_str()));
    grounded_variables_ptr_->push_back(var);

    for( size_t k = 0; k < values_.size(); ++k ) {
        Effect *grounded_value = values_[k]->ground();
        if( dynamic_cast<AtomicEffect*>(grounded_value) != 0 )
            var->grounded_values_.push_back(grounded_value);
        else if( dynamic_cast<AndEffect*>(grounded_value) != 0 ) {
            AndEffect &item_list = *static_cast<AndEffect*>(grounded_value);
            var->grounded_values_.reserve(var->grounded_values_.size() + item_list.size());
            for( size_t i = 0; i < item_list.size(); ++i )
                var->grounded_values_.push_back(item_list[i]);
        } else {
            cout << "error: unrecognized format in variable '"
                 << print_name_ << "'" << endl;
            exit(255);
        }
    }

    cout << "mvv-translation: create variable '" << var->print_name_ << "':";
    for( size_t k = 0; k < var->grounded_values_.size(); ++k )
        cout << " " << *var->grounded_values_[k];
    cout << endl;
}

void PDDL_Base::StateVariable::print(std::ostream &os) const {
    os << "(:variable " << print_name_;
    for( size_t k = 0; k < values_.size(); ++k )
          os << " " << *values_[k];
    os << (is_observable_ ? " :observable" : "") << ")";
}

void PDDL_Base::ObsVariable::print(std::ostream &os) const {
    os << "(:obs-variable " << print_name_;
    for( size_t k = 0; k < values_.size(); ++k )
          os << " " << *values_[k];
    os << ")";
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

void PDDL_Name::write(ostream &os, bool cat) const {
    if( cat ) {
        if( negated_ )
            os << "not_" << sym_->print_name_;
        else
            os << sym_->print_name_;
        for( size_t k = 0; k < arg_.size(); ++k )
            os << '_' << arg_[k]->print_name_;
    } else {
        if( negated_ ) os << "(not ";
        os << '(' << sym_->print_name_;
        for( size_t k = 0; k < arg_.size(); ++k )
            os << ' ' << arg_[k]->print_name_;
        os << ')';
        if( negated_ ) os << ')';
    }
}

