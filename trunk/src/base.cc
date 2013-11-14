#include <stdlib.h>
#include <iomanip>
#include "base.h"

using namespace std;

bool PDDL_Base::write_warnings = true;
bool PDDL_Base::write_info = true;
Instance::when_vec PDDL_Base::dummy_when_vec;

template <class T>
static void copy_symbol_vec(const vector<T> &src, vector<T> &dst) {
    dst.clear();
    dst.reserve(src.size());
    for( typename vector<T>::const_iterator it = src.begin(); it != src.end(); ++it ) {
        dst.push_back(static_cast<T>((*it)->clone()));
    }
}

PDDL_Base::PDDL_Base(StringTable &t)
  : domain_name(0), problem_name(0),
    tab(t), dom_top_type(0), dom_goal(0),
    disable_actions_atom(0),
    translation(false) {

    // setup predicate for equality
    StringTable::Cell *sc = tab.inserta("object");
    dom_top_type = new TypeSymbol(sc->text);
    sc->val = dom_top_type;
    sc = tab.inserta("=");
    dom_eq_pred = new PredicateSymbol(sc->text);
    sc->val = dom_eq_pred;
    dom_eq_pred->param.push_back(new VariableSymbol("?x"));
    dom_eq_pred->param.push_back(new VariableSymbol("?y"));
    dom_eq_pred->param[0]->sym_type = dom_top_type;
    dom_eq_pred->param[1]->sym_type = dom_top_type;
}

PDDL_Base::~PDDL_Base() { // TODO: implement dtor
    delete dom_eq_pred;
    delete dom_top_type;
    delete dom_goal;

    // TODO: for being able to remove ctions/sensors and other symbols, thesymbols
    // cannot be shared between the parser and *-instances. Probably will need to 
    // a symbol tape to store the symbols for each instance.
    for( size_t k = 0; k < dom_init.size(); ++k )
        delete dom_init[k];
    for( size_t k = 0; k < dom_hidden.size(); ++k ) {
        for( size_t j = 0; j < dom_hidden[k].size(); ++j )
            delete dom_hidden[k][j];
    }
    for( size_t k = 0; k < dom_actions.size(); ++k )
        delete dom_actions[k];
    for( size_t k = 0; k < dom_sensors.size(); ++k )
        delete dom_sensors[k];
    for( size_t k = 0; k < dom_axioms.size(); ++k )
        delete dom_axioms[k];
    for( size_t k = 0; k < dom_observables.size(); ++k )
        delete dom_observables[k];
    for( size_t k = 0; k < dom_stickies.size(); ++k )
        delete dom_stickies[k];

    for( size_t k = 0; k < dom_constants.size(); ++k )
        delete dom_constants[k];
    for( size_t k = 0; k < dom_predicates.size(); ++k )
        delete dom_predicates[k];
    for( size_t k = 0; k < dom_types.size(); ++k )
        delete dom_types[k];
}

void PDDL_Base::set_variable_type(var_symbol_vec &vec, size_t n, TypeSymbol *t) {
    for( size_t k = n; k > 0; k-- ) {
        if( vec[k-1]->sym_type != 0 ) return;
        vec[k-1]->sym_type = t;
    }
}

void PDDL_Base::set_type_type(type_symbol_vec &vec, size_t n, TypeSymbol *t) {
    for( size_t k = vec.size(); k > 0; k-- ) {
        if( vec[k-1]->sym_type != 0 ) return;
        vec[k-1]->sym_type = t;
    }
}

void PDDL_Base::set_constant_type(symbol_vec &vec, size_t n, TypeSymbol *t) {
    for( size_t k = n; k > 0; k-- ) {
        if( vec[k-1]->sym_type != 0 ) return;
        vec[k-1]->sym_type = t;
        t->add_element(vec[k-1]);
    }
}

void PDDL_Base::clear_param(var_symbol_vec &vec, size_t start) {
    for( size_t k = start; k < vec.size(); ++k )
        tab.set(vec[k]->print_name, (void*)0);
}

void PDDL_Base::insert_atom(ptr_table &t, Atom *a) {
    ptr_table *r = &t;
    for( size_t k = 0; k < a->param.size(); ++k )
        r = r->insert_next(a->param[k]);
    r->val = a;
}

void PDDL_Base::calculate_strongly_static_predicates() const {
    cout << "strongly-static predicates:";
    bool some_strongly_static = false;
    for( size_t p = 0; p < dom_predicates.size(); ++p ) {
        PredicateSymbol &pred = *dom_predicates[p];
        bool strongly_static = true;

        for( size_t k = 0; strongly_static && (k < dom_init.size()); ++k ) {
            const InitElement &ielement = *dom_init[k];
            strongly_static = ielement.is_strongly_static(pred);
        }

        for( size_t k = 0; strongly_static && (k < dom_axioms.size()); ++k ) {
            const Axiom &axiom = *dom_axioms[k];
            strongly_static = axiom.head->is_strongly_static(pred);
        }

        for( size_t k = 0; strongly_static && (k < dom_actions.size()); ++k ) {
            Action &act = *dom_actions[k];
            strongly_static = act.effect == 0 ? true : act.effect->is_strongly_static(pred);
        }

        pred.strongly_static = strongly_static;
        if( strongly_static ) cout << " '" << pred.print_name << "'";
        if( strongly_static ) some_strongly_static = true;
    }
    if( !some_strongly_static ) cout << " <none>";
    cout << endl;
}

void PDDL_Base::map_oneofs_to_invariants() {
    // extract oneofs
    vector<pair<int, InitOneof*> > oneofs;
    for( size_t k = 0; k < dom_init.size(); ++k ) {
        InitElement *ie = dom_init[k];
        if( dynamic_cast<InitOneof*>(ie) != 0 ) {
            oneofs.push_back(make_pair(k, dynamic_cast<InitOneof*>(ie)));
            dom_init[k] = 0;
        }
    }

    // make oneof into exactly-one invariant
    for( size_t k = 0; k < oneofs.size(); ++k ) {
        Invariant invariant(Invariant::EXACTLY_ONE, *oneofs[k].second);
        dom_init[oneofs[k].first] = new InitInvariant(invariant);
        invariant.clear(); // to avoid destruction of elements
        oneofs[k].second->clear(); // to avoid destruction of elements
        delete oneofs[k].second;
    }
}

void PDDL_Base::translate_observe_effects_into_sensors() {
    PredicateSymbol *dap = new PredicateSymbol("disable-actions");
    Atom da_pos(dap), da_neg(dap, true);

    set<Action*> fixed_actions;
    cout << "translating observe effects into sensors:";
    for( size_t k = 0; k < dom_actions.size(); ++k ) {
        Action *action = dom_actions[k];
        if( action->observe != 0 ) {
            cout << " '" << action->print_name << "'";

            // save observations and create (do-post-sense-for-<action> <args>) predicate
            const Effect *observe = action->observe;
            PredicateSymbol *ps = new PredicateSymbol(strdup((string("do-post-sense-for-") + action->print_name).c_str()));
            //copy_symbol_vec<VariableSymbol*>(action->param, ps->param);
            ps->param = action->param;
            dom_predicates.push_back(ps);
            //cout << *ps;

            Atom ps_pos(ps), ps_neg(ps, true);
            ps_pos.param.insert(ps_pos.param.begin(), ps->param.begin(), ps->param.end());
            ps_neg.param.insert(ps_neg.param.begin(), ps->param.begin(), ps->param.end());
            //cout << ps_pos << " " << ps_neg << endl;

            // Must do 3 things for this action:
            // 1) modify the action to add precondition (not (disable-actions)), and
            //    effects (do-post-sense-for-<action> <args>) and (disable-actions)
            And *new_precondition = dynamic_cast<And*>(const_cast<Condition*>(action->precondition));
            if( new_precondition == 0 ) {
                new_precondition = new And;
                if( action->precondition != 0 ) new_precondition->push_back(action->precondition);
            }
            new_precondition->push_back(new Literal(da_neg));
            action->precondition = new_precondition;

            AndEffect *new_effect = dynamic_cast<AndEffect*>(const_cast<Effect*>(action->effect));
            if( new_effect == 0 ) {
                new_effect = new AndEffect;
                if( action->effect != 0 ) new_effect->push_back(action->effect);
            }
            new_effect->push_back(new AtomicEffect(da_pos));
            new_effect->push_back(new AtomicEffect(ps_pos));
            action->effect = new_effect;
            action->observe = 0;
            fixed_actions.insert(action);
            //cout << *action;

            // 2) create sensor sensor-<action> with same arguments, condition
            //    (do-post-sense-for-<action> <args>), and sense <observation>
            Sensor *sensor = new Sensor(strdup((string("sensor-for-") + action->print_name).c_str()));
            dom_sensors.push_back(sensor);
            sensor->param = action->param;
            sensor->condition = new Literal(ps_pos);
            sensor->sense = observe;
            //cout << *sensor;

            // 3) create action (post-sense-<action> <args>) with precondition
            //    (do-post-sense-for-<action> <args>) and effects that remove
            //    precondition and remove (disable-actions)
            AndEffect *post_effect = new AndEffect;
            post_effect->push_back(new AtomicEffect(da_neg));
            post_effect->push_back(new AtomicEffect(ps_neg));

            Action *post_action = new Action(strdup((string("post-sense-for-") + action->print_name).c_str()));
            dom_actions.push_back(post_action);
            post_action->param = action->param;
            post_action->precondition = new Literal(ps_pos);
            post_action->effect = post_effect;
            fixed_actions.insert(post_action);
            //cout << *post_action;
        }
    }

    // if some translation was done, add precondition (not (disable-actions))
    // to all other actions
    if( !fixed_actions.empty() ) {
        disable_actions_atom = new Literal(da_pos);
        for( size_t k = 0; k < dom_actions.size(); ++k ) {
            Action *action = dom_actions[k];
            if( fixed_actions.find(action) == fixed_actions.end() ) {
                And *new_precondition = dynamic_cast<And*>(const_cast<Condition*>(action->precondition));
                if( new_precondition == 0 ) {
                    new_precondition = new And;
                    if( action->precondition != 0 ) new_precondition->push_back(action->precondition);
                }
                new_precondition->push_back(new Literal(da_neg));
                action->precondition = new_precondition;
                //cout << *action;
            }
        }
        dom_predicates.push_back(dap);
    } else {
        cout << " <none>";
        delete dap;
    }
    cout << endl;
}

void PDDL_Base::do_translation() {
    if( !translation ) return;

    // instantiate state and observable variables
    dom_var_values.resize(dom_variables.size());
    for( size_t k = 0; k < dom_variables.size(); ++k ) {
        effect_vec grounded_values;
        grounded_values.reserve(dom_variables[k]->values.size());
        for( size_t i = 0; i < dom_variables[k]->values.size(); ++i ) {
            Effect *tmp = dom_variables[k]->values[i]->ground();
            if( dynamic_cast<AtomicEffect*>(tmp) != 0 )
                grounded_values.push_back(tmp);
            else if( dynamic_cast<AndEffect*>(tmp) != 0 ) {
                AndEffect &item_list = *dynamic_cast<AndEffect*>(tmp);
                grounded_values.reserve(grounded_values.capacity() + item_list.size());
                for( size_t j = 0; j < item_list.size(); ++j )
                    grounded_values.push_back(item_list[j]);
            } else {
                cout << "error: unrecognized format in variable '" << dom_variables[k]->print_name << "'" << endl;
                break;
            }
            delete dom_variables[k]->values[i];
        }
        dom_variables[k]->values = grounded_values;
        cout << "variable '" << dom_variables[k]->print_name << "':";
        for( size_t i = 0; i < dom_variables[k]->values.size(); ++i )
            cout << " " << *dom_variables[k]->values[i];
        cout << endl;
    }

    // partially ground sensing models in each action
    for( size_t k = 0; k < dom_actions.size(); ++k ) {
        Action &action = *dom_actions[k];
        if( action.sensing_model != 0 ) {
            Effect *grounded = action.sensing_model->ground();
            delete action.sensing_model;
            action.sensing_model = grounded;
        }
        //if( action.effect != 0 ) {
        //    Effect *p = action.effect->ground();
        //    cout << *p << endl;
        //}
    }
}

void PDDL_Base::instantiate(Instance &ins) const {

    // calculate strongly-static predicates. Used to instantiate
    // actions more efficiently by not generating those
    // with false static preconditions.
    calculate_strongly_static_predicates();

    // create instance
    const char *dn = tab.table_char_map().strdup(domain_name ? domain_name : "??");
    const char *pn = tab.table_char_map().strdup(problem_name ? problem_name : "??");
    ins.name = new InstanceName(dn, pn);
    delete[] dn;
    delete[] pn;

    // set atom (disable-actions) (only when processing CLG syntax)
    if( disable_actions_atom != 0 ) {
        Instance::Atom *p = disable_actions_atom->find_prop(ins, false, true);
        ins.disable_actions_atom_index = p->index;
    }

    // instantiate initial situation.
    for( size_t k = 0; k < dom_init.size(); ++k )
        dom_init[k]->instantiate(ins, ins.init);

    // instantiate hidden initial situation
    cout << "instantiating " << dom_hidden.size() << " hidden state(s)" << endl;
    ins.hidden.resize(dom_hidden.size());
    for( size_t k = 0; k < dom_hidden.size(); ++k ) {
        for( size_t j = 0; j < dom_hidden[k].size(); ++j )
            dom_hidden[k][j]->instantiate(ins, ins.hidden[k]);
    }

    // instantiate goal situation
    if( dom_goal != 0 )
        dom_goal->instantiate(ins, ins.goal_literals);

    // instantiate actions
    for( size_t k = 0; k < dom_actions.size(); ++k )
        dom_actions[k]->instantiate(ins);

    // instantiate sensors
    for( size_t k = 0; k < dom_sensors.size(); ++k )
        dom_sensors[k]->instantiate(ins);

    // instantiate axioms
    for( size_t k = 0; k < dom_axioms.size(); ++k )
        dom_axioms[k]->instantiate(ins);

    // instantiate observables
    for( size_t k = 0; k < dom_observables.size(); ++k )
        dom_observables[k]->instantiate(ins);

    // instantiate sticky
    for( size_t k = 0; k < dom_stickies.size(); ++k )
        dom_stickies[k]->instantiate(ins);
}

PDDL_Base::PredicateSymbol* PDDL_Base::find_type_predicate(Symbol *type_sym) {
    for (size_t k = 0; k < dom_predicates.size(); ++k) {
        if (dom_predicates[k]->print_name == type_sym->print_name)
            return dom_predicates[k];
    }
    cerr << "error: no type predicate found for type "
         << type_sym->print_name << endl;
    exit(255);
}

void PDDL_Base::print(ostream &os) const {
    os << "[PDDL_Base::print() not yet implemented]" << endl;
}


PDDL_Base::Symbol* PDDL_Base::Symbol::clone() const {
    Symbol *cl = new Symbol(strdup(print_name), sym_class);
    cl->sym_type = sym_type;
    return cl;
}

void PDDL_Base::TypeSymbol::add_element(Symbol *e) {
    elements.push_back(e);
    if( sym_type != 0 ) static_cast<TypeSymbol*>(sym_type)->add_element(e);
}

void PDDL_Base::TypeSymbol::print(ostream &os) const {
    os << "(:type " << print_name;
    if( sym_type ) os << " - " << sym_type->print_name;
    os << "): {";
    for( size_t k = 0; k < elements.size(); ++k )
        os << *elements[k] << ",";
    os << "}" << endl;
}

PDDL_Base::Symbol* PDDL_Base::TypeSymbol::clone() const {
    TypeSymbol *cl = new TypeSymbol(strdup(print_name));
    cl->sym_type = sym_type;
    copy_symbol_vec<Symbol*>(elements, cl->elements);
    return cl;
}
 
PDDL_Base::Symbol* PDDL_Base::VariableSymbol::clone() const {
    //std::cout << "clone vsym: this=" << this << std::endl;
    VariableSymbol *cl = new VariableSymbol(strdup(print_name));
    cl->sym_type = sym_type;
    //cl->sym_type = sym_type != 0 ? sym_type->clone() : 0;
    cl->value = value != 0 ? value->clone() : 0;
    return cl;
}

void PDDL_Base::VariableSymbol::print(std::ostream &os) const {
    if( value == 0 ) {
        os << print_name;
        if( sym_type ) os << " - " << sym_type->print_name;
    } else
        os << *value;
}
 
PDDL_Base::Symbol* PDDL_Base::PredicateSymbol::clone() const {
    PredicateSymbol *cl = new PredicateSymbol(strdup(print_name));
    cl->sym_type = sym_type;
    cl->strongly_static = strongly_static;
    copy_symbol_vec<VariableSymbol*>(param, cl->param);
    return cl;
}

void PDDL_Base::PredicateSymbol::print(ostream &os) const {
    os << "(:predicate " << print_name;
    for( size_t k = 0; k < param.size(); ++k )
        os << " " << *param[k];
    os << ")" << endl;
}

void PDDL_Base::Schema::enumerate(bool only_count) const {
    count = 0;
    for( size_t k = 0; k < param.size(); ++k )
        param[k]->value = 0;
    rec_enumerate(0, only_count);
}

void PDDL_Base::Schema::rec_enumerate(size_t p, bool only_count) const {
    if( p < param.size() ) {
        TypeSymbol *t = static_cast<TypeSymbol*>(param[p]->sym_type);
        for( size_t k = 0; k < t->elements.size(); ++k ) {
            param[p]->value = t->elements[k];
            // TODO: incremental pruning
            rec_enumerate(p+1, only_count);
        }
        param[p]->value = 0;
    } else {
        if( only_count )
            ++count;
        else
            process_instance();
    }
}

bool PDDL_Base::Atom::operator==(const Atom &atom) const {
    if( pred != atom.pred ) return false;
    if( param.size() != atom.param.size() ) return false;
    for( size_t k = 0; k < param.size(); ++k )
        if( param[k] != atom.param[k] ) return false;
    return true;
}

Instance::Atom* PDDL_Base::Atom::find_prop(Instance &ins, bool neg, bool create) const {
    ptr_table *r = neg ? &(pred->neg_prop) : &(pred->pos_prop);
    for( size_t k = 0; k < param.size(); ++k ) {
        if( param[k]->sym_class == sym_variable )
            r = r->insert_next(static_cast<VariableSymbol*>(param[k])->value);
        else
            r = r->insert_next(param[k]);
    }
    if( !r->val ) {
        if( !create ) return 0;
        PDDL_Name a_name(pred, neg);
        for( size_t k = 0; k < param.size(); ++k ) {
            if( param[k]->sym_class == sym_variable )
	        a_name.add(static_cast<VariableSymbol*>(param[k])->value);
            else
	        a_name.add(param[k]);
        }
        Instance::Atom &p = ins.new_atom(new CopyName(a_name.to_string()));
        r->val = &p;
    }
    return static_cast<Instance::Atom*>(r->val);
}

PDDL_Base::Atom* PDDL_Base::Atom::ground() const {
    Atom *result = new Atom(*this);
    for( size_t k = 0; k < result->param.size(); ++k ) {
        if( (result->param[k]->sym_class == sym_variable) &&
            (static_cast<VariableSymbol*>(result->param[k])->value != 0) ) {
            VariableSymbol *new_var = new VariableSymbol("?x");
            new_var->value = static_cast<VariableSymbol*>(result->param[k])->value;
            result->param[k] = new_var;
        }
    }
    return result;
}

void PDDL_Base::Atom::instantiate(Instance &ins, index_set &atoms) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !neg )
        atoms.insert(1 + p->index);
    else
        atoms.insert(-(1 + p->index));
}

void PDDL_Base::Atom::print(ostream &os, bool extra_neg) const {
    extra_neg = extra_neg ? !neg : neg;
    if( extra_neg ) os << "(not ";
    os << "(" << pred->print_name;
    for (size_t k = 0; k < param.size(); ++k) {
        if( (param[k]->sym_class == sym_variable) && (static_cast<VariableSymbol*>(param[k])->value != 0) )
            os << " " << *static_cast<VariableSymbol*>(param[k])->value;
        else
            os << " " << *param[k];
    }
    os << ")";
    if( extra_neg ) os << ")";
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

PDDL_Base::Condition* PDDL_Base::EQ::ground() const {
    EQ *result = new EQ(first, second, neg);
    if( (first->sym_class == sym_variable) && (first->value != 0) ) {
        VariableSymbol *new_var = new VariableSymbol("?x");
        new_var->value = first->value;
        result->first = new_var;
    }
    if( (second->sym_class == sym_variable) && (second->value != 0) ) {
        VariableSymbol *new_var = new VariableSymbol("?x");
        new_var->value = second->value;
        result->second = new_var;
    }

    // check if result can be reduced to a boolean constant
    if( (first->value == 0) || (second->value == 0) ) {
        return result;
    } else {
        bool value = result->first->value == result->second->value;
        value = neg ? !value : value;
        if( result->first != first ) delete result->first;
        if( result->second != second ) delete result->second;
        delete result;
        return new Constant(value);
    }
}

void PDDL_Base::EQ::print(std::ostream &os) const {
    if( neg ) os << "(not ";
    os << "(= " << *first << " " << *second << ")";
    if( neg ) os << ")";
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
            Constant &constant = *dynamic_cast<Constant*>(item);
            if( constant.value ) {
                delete item;
            } else {
                delete item;
                delete result;
                return new Constant(false);
            }
        } else if( dynamic_cast<And*>(item) != 0 ) {
            And &item_list = *dynamic_cast<And*>(item);
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
    assert((pred->print_name != p.print_name) || (pred == &p));
    assert((pred->print_name == p.print_name) || (pred != &p));
    return pred != &p;
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
            AndEffect &item_list = *dynamic_cast<AndEffect*>(item);
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

void PDDL_Base::ConditionalEffect::instantiate(Instance &ins, index_set &eff, Instance::when_vec &when) const {
    Instance::When single_when;
    condition->instantiate(ins, single_when.condition);
    effect->instantiate(ins, single_when.effect, when);
    when.push_back(single_when);
}

PDDL_Base::Effect* PDDL_Base::ConditionalEffect::ground() const {
    //return new ConditionalEffect(condition->ground(), effect->ground());
#if 1
    Effect *eff = effect->ground();
    if( dynamic_cast<NullEffect*>(eff) != 0 ) {
        return eff;
    } else {
        Condition *cond = condition->ground();
        if( dynamic_cast<Constant*>(cond) != 0 ) {
            Constant &constant = *dynamic_cast<Constant*>(cond);
            if( constant.value ) {
                delete cond;
                return eff;
            } else {
                delete cond;
                delete eff;
                return new NullEffect;
            }
        } else {
            return new ConditionalEffect(cond, eff);
        }
    }
#endif
}

bool PDDL_Base::ConditionalEffect::is_strongly_static(const PredicateSymbol &p) const {
    return effect->is_strongly_static(p);
}

void PDDL_Base::ConditionalEffect::print(std::ostream &os) const {
    os << "(when " << *condition << " " << *effect << ")";
}

void PDDL_Base::ForallEffect::instantiate(Instance &ins, index_set &eff, Instance::when_vec &when) const {
    cout << "error: instantiate() should not be called on ForallEffect: first ground the effect!" << endl;
    assert(0);
}

PDDL_Base::Effect* PDDL_Base::ForallEffect::ground() const {
    result_stack.push_back(new AndEffect);
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
    Effect *item = effect->ground();
    if( dynamic_cast<NullEffect*>(item) != 0 ) {
        delete item;
    } else if( dynamic_cast<AndEffect*>(item) != 0 ) {
        AndEffect &item_list = *dynamic_cast<AndEffect*>(item);
        for( size_t i = 0; i < item_list.size(); ++i)
            result_stack.back()->push_back(item_list[i]);
        item_list.clear();
        delete item;
    } else
        result_stack.back()->push_back(item);
}

bool PDDL_Base::ForallEffect::is_strongly_static(const PredicateSymbol &p) const {
    return effect->is_strongly_static(p);
}

void PDDL_Base::ForallEffect::print(std::ostream &os) const {
    os << "(forall (";
    for( size_t k = 0; k < param.size(); ++k )
        os << (k > 0 ? " " : "") << *param[k];
    os << ") " << *effect << ")";
}

void PDDL_Base::Invariant::instantiate(Instance &ins, Instance::Invariant &invariant) const {
    invariant.type = type;
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        Instance::Atom *p = lit->find_prop(ins, false, true);
        if( !lit->neg )
            invariant.push_back(1 + p->index);
        else
            invariant.push_back(-(1 + p->index));
    }
}

void PDDL_Base::Invariant::print(std::ostream &os) const {
    if( type == AT_LEAST_ONE ) os << "(at-least-one";
    else if( type == AT_MOST_ONE ) os << "(at-most-one";
    else os << "(exactly-one";
    for( size_t k = 0; k < size(); ++k )
        os << " " << *(*this)[k];
    os << ")";
}

void PDDL_Base::Clause::instantiate(Instance &ins, Instance::Clause &clause) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        Instance::Atom *p = lit->find_prop(ins, false, true);
        if( !lit->neg )
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
        if( !lit->neg )
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

void PDDL_Base::InitLiteral::instantiate(Instance &ins, Instance::Init &init) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !neg ) {
        init.literals.insert(1 + p->index);
    } else {
        init.literals.insert(-(1 + p->index));
    }
}

bool PDDL_Base::InitLiteral::is_strongly_static(const PredicateSymbol &p) const {
    return true;
}

void PDDL_Base::InitInvariant::instantiate(Instance &ins, Instance::Init &init) const {
    Instance::Invariant invariant;
    Invariant::instantiate(ins, invariant);

    // If invariant is of type AT_MOST_ONE or EXACTLY_ONE,
    // generate implied invatiants of type AT_LEAST_ONE
    if( invariant.type != AT_LEAST_ONE ) {
        for( size_t i = 0; i < invariant.size(); ++i ) {
            for( size_t j = 1 + i; j < invariant.size(); ++j ) {
                Instance::Invariant implied_invariant;
                implied_invariant.type = AT_LEAST_ONE;
                implied_invariant.push_back(-invariant[i]);
                implied_invariant.push_back(-invariant[j]);
                init.invariants.push_back(implied_invariant);
            }
        }
    }

    // If invariant is of type AT_LEAST_ONE or EXACTLY_ONE,
    // insert invariant.
    if( invariant.type != AT_MOST_ONE ) {
        invariant.type = AT_LEAST_ONE;
        init.invariants.push_back(invariant);
    }
}

// TODO: fix strongly-static detection. It seems that only need to be checked
// for oneofs because invariants should not define initial states and clauses
// only filter states generated by oneofs.
bool PDDL_Base::InitInvariant::is_strongly_static(const PredicateSymbol &p) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        assert((lit->pred->print_name != p.print_name) || (lit->pred == &p));
        assert((lit->pred->print_name == p.print_name) || (lit->pred != &p));
        if( lit->pred == &p ) return false;
    }
    return true;
}

void PDDL_Base::InitClause::instantiate(Instance &ins, Instance::Init &init) const {
    Instance::Clause clause;
    Clause::instantiate(ins, clause);
    init.clauses.push_back(clause);
}

bool PDDL_Base::InitClause::is_strongly_static(const PredicateSymbol &p) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        assert((lit->pred->print_name != p.print_name) || (lit->pred == &p));
        assert((lit->pred->print_name == p.print_name) || (lit->pred != &p));
        if( lit->pred == &p ) return false;
    }
    return true;
}

void PDDL_Base::InitOneof::instantiate(Instance &ins, Instance::Init &init) const {
    Instance::Oneof oneof;
    Oneof::instantiate(ins, oneof);
    init.oneofs.push_back(oneof);
}

bool PDDL_Base::InitOneof::is_strongly_static(const PredicateSymbol &p) const {
    for( size_t k = 0; k < size(); ++k ) {
        const Literal *lit = dynamic_cast<const Literal*>((*this)[k]);
        assert(lit != 0);
        assert((lit->pred->print_name != p.print_name) || (lit->pred == &p));
        assert((lit->pred->print_name == p.print_name) || (lit->pred != &p));
        if( lit->pred == &p ) return false;
    }
    return true;
}

void PDDL_Base::Action::instantiate(Instance &ins) const {
    size_t base = ins.n_actions();
    cout << "instantiating '" << print_name << "' ..." << flush;
    enumerate(true);
    cout << " (reserve " << count << ") ..." << flush;
    ins.reserve_actions(count);
    ins_ptr = &ins;
    enumerate();
    cout << " " << ins.n_actions()-base << " action(s)" << endl;
}

void PDDL_Base::Action::process_instance() const {
    PDDL_Name name(this, param, param.size());
    Instance::Action &act = ins_ptr->new_action(new CopyName(name.to_string()));
    act.cost = 1;

    cout << "fully instantiated action " << name << endl;
    if( precondition != 0 ) {
        Condition *c = precondition->ground();
        c->instantiate(*ins_ptr, act.precondition);
        cout << "    pre=" << *c << endl;
    }
    if( effect != 0 ) {
        Effect *e = effect->ground();
        e->instantiate(*ins_ptr, act.effect, act.when);
        cout << "    eff=" << *e << endl;
    }
    if( observe != 0 ) {
        Effect *e = observe->ground();
        cout << "    obs=" << *e << endl;
    }
    if( sensing_model != 0 ) {
        Effect *e = sensing_model->ground();
        e->instantiate(*ins_ptr, act.effect, act.when);
        cout << "    sen=" << *e << endl;
    }
}

void PDDL_Base::Action::print(ostream &os) const {
    os << "(:action " << print_name << endl;

    if( !param.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param.size(); ++k )
            os << (k > 0 ? " " : "") << *param[k];
        os << ")" << endl;
    }

    if( precondition != 0 ) {
        os << "    :precondition " << *precondition << endl;
    }

    if( effect != 0 ) {
        os << "    :effect " << *effect << endl;
    }

    if( observe != 0 ) {
        os << "    :observe " << *observe << endl;
    }

    os << ")" << endl;
}

void PDDL_Base::Sensor::instantiate(Instance &ins) const {
    size_t base = ins.n_sensors();
    cout << "instantiating '" << print_name << "' ..." << flush;
    ins_ptr = &ins;
    enumerate();
    cout << " " << ins.n_sensors()-base << " sensor(s)" << endl;
}

void PDDL_Base::Sensor::process_instance() const {
    PDDL_Name name(this, param, param.size());
    Instance::Sensor &sensor = ins_ptr->new_sensor(new CopyName(name.to_string()));
    cout << "fully instantiated sensor " << name << endl;
    if( condition != 0 ) {
        Condition *c = condition->ground();
        c->instantiate(*ins_ptr, sensor.condition);
        cout << "    :condition " << *c << endl;
    }
    if( sense != 0 ) {
        Effect *e = sense->ground();
        e->instantiate(*ins_ptr, sensor.sense);
        cout << "    :sense " << *e << endl;
    }
}

void PDDL_Base::Sensor::print(ostream &os) const {
    os << "(:sensor " << print_name << endl;

    if( !param.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param.size(); ++k )
          os << (k > 0 ? " " : "") << *param[k];
        os << ")" << endl;
    }

    if( condition != 0 ) {
        os << "    :condition " << *condition << endl;
    }

    assert(sense != 0);
    os << "    :sense " << *sense << endl
       << ")" << endl;
}

void PDDL_Base::Axiom::instantiate(Instance &ins) const {
    size_t base = ins.n_axioms();
    cout << "instantiating '" << print_name << "' ..." << flush;
    ins_ptr = &ins;
    enumerate();
    cout << " " << ins.n_axioms()-base << " axiom(s)" << endl;
}

void PDDL_Base::Axiom::process_instance() const {
    PDDL_Name name(this, param, param.size());
    Instance::Axiom &axiom = ins_ptr->new_axiom(new CopyName(name.to_string()));
    cout << "fully instantiated axiom " << name << endl;
    if( body != 0 ) {
        Condition *c = body->ground();
        c->instantiate(*ins_ptr, axiom.body);
        cout << "    :body " << *c << endl;
    }
    if( head != 0 ) {
        Effect *e = head->ground();
        e->instantiate(*ins_ptr, axiom.head);
        cout << "    :head " << *e << endl;
    }
}

void PDDL_Base::Axiom::print(std::ostream &os) const {
    os << "(:axiom " << print_name << endl;

    if( !param.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param.size(); ++k )
          os << (k > 0 ? " " : "") << *param[k];
        os << ")" << endl;
    }

    assert((body != 0) && (head != 0));
    os << "    :body " << *body << endl
       << "    :head " << *head << endl
       << ")" << endl;
}

void PDDL_Base::Observable::instantiate(Instance &ins) const {
    cout << "instantiating observable ..." << flush;
    for( size_t k = 0; k < param.size(); ++k )
        param[k]->value = 0;
    rec_enumerate_for_instantiate(ins, 0);
    cout << " ok" << endl;
}

void PDDL_Base::Observable::print(std::ostream &os) const {
    os << "(:observable" << endl;

    if( !param.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param.size(); ++k )
          os << (k > 0 ? " " : "") << *param[k];
        os << ")" << endl;
    }

    assert(observables != 0);
    os << "    :fluents " << *observables << endl
       << ")" << endl;
}

void PDDL_Base::Observable::rec_enumerate_for_instantiate(Instance &ins, size_t p) const {
    if( p < param.size() ) {
        TypeSymbol *t = static_cast<TypeSymbol*>(param[p]->sym_type);
        for( size_t k = 0, ksz = t->elements.size(); k < ksz; ++k ) {
            param[p]->value = t->elements[k];
            rec_enumerate_for_instantiate(ins, p+1);
        }
        param[p]->value = 0;
    } else {
        if( observables != 0 ) observables->instantiate(ins, ins.given_observables);
    }
}

void PDDL_Base::Sticky::instantiate(Instance &ins) const {
    cout << "instantiating sticky ..." << flush;
    for( size_t k = 0; k < param.size(); ++k )
        param[k]->value = 0;
    rec_enumerate_for_instantiate(ins, 0);
    cout << " ok" << endl;
}

void PDDL_Base::Sticky::rec_enumerate_for_instantiate(Instance &ins, size_t p) const {
    if( p < param.size() ) {
        TypeSymbol *t = static_cast<TypeSymbol*>(param[p]->sym_type);
        for( size_t k = 0, ksz = t->elements.size(); k < ksz; ++k ) {
            param[p]->value = t->elements[k];
            rec_enumerate_for_instantiate(ins, p+1);
        }
        param[p]->value = 0;
    } else {
        if( stickies != 0 ) stickies->instantiate(ins, ins.given_stickies);
    }
}

void PDDL_Base::Sticky::print(std::ostream &os) const {
    os << "(:sticky" << endl;

    if( !param.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param.size(); ++k )
          os << (k > 0 ? " " : "") << *param[k];
        os << ")" << endl;
    }

    assert(stickies != 0);
    os << "    :fluents " << *stickies << endl
       << ")" << endl;
}

void PDDL_Base::StateVariable::instantiate(Instance &ins, index_set &var_values) const {
    cout << "instantiating variable '" << print_name << "' ..." << flush;
    var_values.clear();
    for( size_t k = 0; k < values.size(); ++k )
        values[k]->instantiate(ins, var_values);
    cout << " " << var_values.size() << " value(s)" << endl;
}

void PDDL_Base::StateVariable::print(std::ostream &os) const {
    os << "(:variable " << print_name;
    for( size_t k = 0; k < values.size(); ++k )
          os << " " << *values[k];
    os << (is_observable ? " :observable" : "") << ")";
}

void PDDL_Base::ObsVariable::instantiate(Instance &ins, index_set &var_values) const {
    cout << "instantiating variable '" << print_name << "' ..." << flush;
    var_values.clear();
    for( size_t k = 0; k < values.size(); ++k )
        values[k]->instantiate(ins, var_values);
    cout << " " << var_values.size() << " value(s)" << endl;
}

void PDDL_Base::ObsVariable::print(std::ostream &os) const {
    os << "(:obs-variable " << print_name;
    for( size_t k = 0; k < values.size(); ++k )
          os << " " << *values[k];
    os << ")";
}



PDDL_Name::PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::symbol_vec &arg, size_t n)
  : _neg(false), _sym(sym), _arg(arg) {
}

PDDL_Name::PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::var_symbol_vec &arg, size_t n)
  : _neg(false), _sym(sym) {
    for( size_t k = 0; k < n; ++k )
        _arg.push_back(arg[k]->value);
}

void PDDL_Name::add(PDDL_Base::Symbol *s) {
    _arg.push_back(s);
}

void PDDL_Name::write(ostream &os, bool cat) const {
    if (cat) {
        if (_neg)
            os << "not_" << _sym->print_name;
        else
            os << _sym->print_name;
        for( size_t k = 0; k < _arg.size(); ++k )
            os << '_' << _arg[k]->print_name;
    } else {
        if (_neg) os << "(not ";
        os << '(' << _sym->print_name;
        for( size_t k = 0; k < _arg.size(); ++k )
            os << ' ' << _arg[k]->print_name;
        os << ')';
        if (_neg) os << ')';
    }
}

