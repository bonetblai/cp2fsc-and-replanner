#include <stdlib.h>
#include <iomanip>
#include "base.h"

using namespace std;

bool PDDL_Base::write_warnings = true;
bool PDDL_Base::write_info = true;

PDDL_Base::PDDL_Base(StringTable &t)
  : domain_name(0), problem_name(0), tab(t), dom_top_type(0), dom_goal(0) {

    // setup predicate for equality
    StringTable::Cell *sc = tab.inserta("object");
    dom_top_type = new TypeSymbol(sc->text);
    sc->val = dom_top_type;
    sc = tab.inserta("=");
    dom_eq_pred = new PredicateSymbol(sc->text);
    sc->val = dom_eq_pred;
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
    for( size_t k = 0; k < dom_hidden.size(); ++k )
        delete dom_hidden[k];
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

void PDDL_Base::set_variable_type(variable_vec &vec, size_t n, TypeSymbol *t) {
    for( size_t k = n; k > 0; k-- ) {
        if( vec[k-1]->sym_type != 0 ) return;
        vec[k-1]->sym_type = t;
    }
}

void PDDL_Base::set_type_type(type_vec &vec, size_t n, TypeSymbol *t) {
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

void PDDL_Base::clear_param(variable_vec &vec, size_t start) {
    for( size_t k = start; k < vec.size(); ++k )
        tab.set(vec[k]->print_name, (void*)0);
}

void PDDL_Base::TypeSymbol::add_element(Symbol *e) {
    elements.push_back(e);
    if( sym_type != 0 ) ((TypeSymbol*)sym_type)->add_element(e);
}

bool PDDL_Base::Atom::operator==(const Atom &atom) const {
    if( pred != atom.pred ) return false;
    if( param.size() != atom.param.size() ) return false;
    for( size_t k = 0; k < param.size(); k++ )
        if( param[k] != atom.param[k] ) return false;
    return true;
}

Instance::Atom* PDDL_Base::Atom::find_prop(Instance &ins, bool neg, bool create) const {
    ptr_table *r = neg ? &(pred->neg_prop) : &(pred->pos_prop);
    for( size_t k = 0; k < param.size(); k++ ) {
        if( param[k]->sym_class == sym_variable )
            r = r->insert_next(((VariableSymbol*)param[k])->value);
        else
            r = r->insert_next(param[k]);
    }
    if( !r->val ) {
        if( !create ) return 0;
        PDDL_Name a_name(pred, neg);
        for( size_t k = 0; k < param.size(); k++ ) {
            if( param[k]->sym_class == sym_variable )
	        a_name.add(((VariableSymbol*)param[k])->value);
            else
	        a_name.add(param[k]);
        }

        Instance::Atom &p = ins.new_atom(new CopyName(a_name.to_string()));
        r->val = &p;
    }
    return (Instance::Atom*)r->val;
}

void PDDL_Base::insert_atom(ptr_table &t, Atom *a) {
    ptr_table *r = &t;
    for( size_t k = 0; k < a->param.size(); k++ )
        r = r->insert_next(a->param[k]);
    r->val = a;
}

void PDDL_Base::Action::build(Instance &ins, size_t p, int pass) const {
    if( p < param.size() ) {
        TypeSymbol *t = (TypeSymbol*)param[p]->sym_type;
        for( size_t k = 0, ksz = t->elements.size(); k < ksz; ++k ) {
            param[p]->value = t->elements[k];
            // TODO: incremental pruning
            build(ins, p+1, pass);
        }
        param[p]->value = 0;
    } else {
        if( pass == 1 ) {
            PDDL_Name aname(this, param, param.size());
            Instance::Action &act = ins.new_action(new CopyName(aname.to_string()));
            if( precondition != 0 ) precondition->instantiate(ins, act.precondition);
            if( effect != 0 ) effect->instantiate(ins, act.effect, &act);
            assert(observe == 0); // observe effects should had been translated!
            act.cost = 1;
        } else {
            ++action_count_;
        }
    }
}

void PDDL_Base::Action::instantiate(Instance &ins) const {
    size_t base = ins.n_actions();
    cout << "instantiating '" << print_name << "' ..." << flush;
    for( size_t k = 0; k < param.size(); ++k )
        param[k]->value = 0;
    action_count_ = 0;
    build(ins, 0, 0);
    ins.reserve_actions(action_count_);
    cout << " (reserve " << action_count_ << ") ..." << flush;
    build(ins, 0, 1);
    cout << " " << ins.n_actions()-base << " action(s)" << endl;
}

void PDDL_Base::Sensor::build(Instance &ins, size_t p) const {
    if( p < param.size() ) {
        TypeSymbol *t = (TypeSymbol*)param[p]->sym_type;
        for( size_t k = 0; k < t->elements.size(); ++k ) {
            param[p]->value = t->elements[k];
            // TODO: incremental pruning
            build(ins, p+1);
        }
        param[p]->value = 0;
    } else {
        PDDL_Name sname(this, param, param.size());
        Instance::Sensor &sensor = ins.new_sensor(new CopyName(sname.to_string()));
        if( condition != 0 ) condition->instantiate(ins, sensor.condition);
        if( sense != 0 ) sense->instantiate(ins, sensor.sense, 0);
    }
}

void PDDL_Base::Sensor::instantiate(Instance &ins) const {
    size_t base = ins.n_sensors();
    cout << "instantiating '" << print_name << "' ..." << flush;
    for( size_t k = 0; k < param.size(); ++k )
        param[k]->value = 0;
    build(ins, 0);
    cout << " " << ins.n_sensors()-base << " sensor(s)" << endl;
}

void PDDL_Base::Axiom::build(Instance &ins, size_t p) const {
    if( p < param.size() ) {
        TypeSymbol *t = (TypeSymbol*)param[p]->sym_type;
        for( size_t k = 0; k < t->elements.size(); ++k ) {
            param[p]->value = t->elements[k];
            // TODO: incremental pruning
            build(ins, p+1);
        }
        param[p]->value = 0;
    } else {
        PDDL_Name aname(this, param, param.size());
        Instance::Axiom &axiom = ins.new_axiom(new CopyName(aname.to_string()));
        if( body != 0 ) body->instantiate(ins, axiom.body);
        if( head != 0 ) head->instantiate(ins, axiom.head);
    }
}

void PDDL_Base::Axiom::instantiate(Instance &ins) const {
    size_t base = ins.n_axioms();
    cout << "instantiating '" << print_name << "' ..." << flush;
    for( size_t k = 0; k < param.size(); ++k )
        param[k]->value = 0;
    build(ins, 0);
    cout << " " << ins.n_axioms()-base << " axiom(s)" << endl;
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
            strongly_static = act.effect->is_strongly_static(pred);
        }

        pred.strongly_static = strongly_static;
        if( strongly_static ) cout << " " << pred.print_name;
        if( strongly_static ) some_strongly_static = true;
    }
    if( !some_strongly_static ) cout << " <none>";
    cout << endl;
}

template <class T>
void PDDL_Base::copy_symbol_vec(const vector<T> &src, vector<T> &dst) {
    dst.clear();
    dst.reserve(src.size());
    //cout << "sz=" << src.size() << ", src=" << &src << ", dst=" << &dst << endl;
    for( typename vector<T>::const_iterator it = src.begin(); it != src.end(); ++it ) {
        //cout << (*it)->print_name << "=" << flush;
        //(*it)->print(cout); cout << endl;
        dst.push_back(static_cast<T>((*it)->clone()));
    }
}

void PDDL_Base::translate_observe_effects_into_sensors() {
    PredicateSymbol *da = new PredicateSymbol("disable-actions");
    Atom da_pos(da), da_neg(da, true);

    set<Action*> fixed_actions;
    cout << "translating observe effects into sensors:";
    for( size_t k = 0; k < dom_actions.size(); ++k ) {
        Action *action = dom_actions[k];
        if( action->observe != 0 ) {
            cout << " '" << action->print_name << "'" << flush;

            // save observations and create (do-post-sense-for-<action> <args>) predicate
            const Effect *observe = action->observe;
            PredicateSymbol *ps = new PredicateSymbol(strdup((string("do-post-sense-for-") + action->print_name).c_str()));
            //cout << action->param.size() << flush << " " << ps->param.size() << endl;
            //copy_symbol_vec<VariableSymbol*>(action->param, ps->param);
            //cout << action->param.size() << flush << " " << ps->param.size() << endl;
            ps->param = action->param;
            dom_predicates.push_back(ps);
            //ps->print(cout);

            Atom ps_pos(ps), ps_neg(ps, true);
            ps_pos.param.insert(ps_pos.param.begin(), ps->param.begin(), ps->param.end());
            ps_neg.param.insert(ps_neg.param.begin(), ps->param.begin(), ps->param.end());
            //ps_pos.print(cout); ps_neg.print(cout); cout << endl;

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
            //action->print(cout);

            // 2) create sensor sensor-<action> with same arguments, condition
            //    (do-post-sense-for-<action> <args>), and sense <observation>
            Sensor *sensor = new Sensor(strdup((string("sensor-for-") + action->print_name).c_str()));
            dom_sensors.push_back(sensor);
            sensor->param = action->param;
            sensor->condition = new Literal(ps_pos);
            sensor->sense = observe;
            //sensor->print(cout);

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
            //post_action->print(cout);
        }
    }
    cout << endl;

    // if some translation was done, add precondition (not (disable-actions))
    // to all other actions
    if( !fixed_actions.empty() ) {
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
                //action->print(cout);
            }
        }
        dom_predicates.push_back(da);
    } else {
        delete da;
    }
}

void PDDL_Base::instantiate(Instance &ins) const {

    // calculate strongly-static predicates. Used to instantiate
    // actions more efficiently by not generating those
    // with false static preconditions.
    calculate_strongly_static_predicates();

#if 0 // TODO: fix initialization of EQ predicate

    // set up interpretation of equality
    for( size_t k = 0; k < dom_constants.size(); k++ ) {
        Atom *a = new Atom(dom_eq_pred);
        a->param.push_back(dom_constants[k]);
        a->param.push_back(dom_constants[k]);
    }

#endif

    // create instance
    const char *dn = tab.table_char_map().strdup(domain_name ? domain_name : "??");
    const char *pn = tab.table_char_map().strdup(problem_name ? problem_name : "??");
    ins.name = new InstanceName(dn, pn);
    delete[] dn;
    delete[] pn;

    // instantiate initial situation.
    for( size_t k = 0; k < dom_init.size(); k++ )
        dom_init[k]->instantiate(ins, ins.init);

    // instantiate hidden initial situation
    for( size_t k = 0; k < dom_hidden.size(); k++ )
        dom_hidden[k]->instantiate(ins, ins.hidden);

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

PDDL_Base::PredicateSymbol*
PDDL_Base::find_type_predicate(Symbol *type_sym) {
    for (size_t k = 0; k < dom_predicates.size(); k++) {
        if (dom_predicates[k]->print_name == type_sym->print_name)
            return dom_predicates[k];
    }
    cerr << "error: no type predicate found for type "
         << type_sym->print_name << endl;
    exit(255);
}

void PDDL_Base::TypeSymbol::print(ostream &os) const {
    os << "(:type " << print_name;
    if( sym_type ) os << " - " << sym_type->print_name;
    os << "): {";
    for( size_t k = 0; k < elements.size(); k++ ) {
        elements[k]->print(os);
        if( k < elements.size() - 1 ) os << ", ";
    }
    os << "}" << endl;
}

void PDDL_Base::PredicateSymbol::print(ostream &os) const {
    os << "(:predicate " << print_name;
    for( size_t k = 0; k < param.size(); k++ ) {
        os << " ";
        param[k]->print(os);
    }
    os << ")" << endl;
}

#if 0

void PDDL_Base::OneOf::print(ostream &os, size_t i) const {
    os << "(oneof";
    for( size_t k = 0; k < adds.size(); ++k ) {
        os << " ";
        adds[k]->print(os);
    }
    for( size_t k = 0; k < dels.size(); ++k ) {
        os << " (not ";
        dels[k]->print(os);
        os << ")";
    }
    os << ")" << endl;
}

void PDDL_Base::Clause::print(ostream &os, size_t i) const {
    os << "(or";
    for( size_t k = 0; k < neg_atm.size(); ++k ) {
        os << " (not ";
        neg_atm[k]->print(os);
        os << ")";
    }
    for( size_t k = 0; k < pos_atm.size(); ++k ) {
        os << " ";
        pos_atm[k]->print(os);
    }
    os << ")" << endl;;
}

void PDDL_Base::Complex::print(ostream &os, size_t i) const {
    os << setw(i) << "" << "(:complex" << endl;
    os << setw(i) << "" << "  :parameters (";
    for( size_t k = 0; k < param.size(); k++ ) {
        if( k > 0 ) os << ' ';
        param[k]->print(os);
    }
    os << ")" << endl;
    os << setw(i) << "" << "  :pos_prec (";
    for( size_t k = 0; k < pos_atm.size(); k++ ) {
        pos_atm[k]->print(os);
        if( k < pos_atm.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << setw(i) << "" << "  :neg_prec (";
    for( size_t k = 0; k < neg_atm.size(); k++ ) {
        neg_atm[k]->print(os);
        if( k < neg_atm.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << setw(i) << "" << "  :add (";
    for( size_t k = 0; k < adds.size(); k++ ) {
        adds[k]->print(os);
        if( k < adds.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << setw(i) << "" << "  :del (";
    for( size_t k = 0; k < dels.size(); k++ ) {
        dels[k]->print(os);
        if( k < dels.size() - 1 ) os << " ";
    }
    os << ")" << endl;
#if 0
    os << setw(i) << "" << "  :clauses (";
    for( size_t k = 0; k < clauses.size(); k++ ) {
        clauses[k]->print(os);
        if( k < clauses.size() - 1 ) os << " ";
    }
    os << ")" << endl;
#endif
    os << setw(i) << "" << ")" << endl;
}
 
void PDDL_Base::ActionSymbol::print(ostream &os) const {
    os << "(:action " << print_name << endl;
    os << "  :parameters (";
    for( size_t k = 0; k < param.size(); k++ ) {
      if (k > 0) os << ' ';
      param[k]->print(os);
    }
    os << ")" << endl;
    os << "  :pos_prec (";
    for( size_t k = 0; k < pos_atm.size(); k++ ) {
        pos_atm[k]->print(os);
        if( k < pos_atm.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << "  :neg_prec (";
    for( size_t k = 0; k < neg_atm.size(); k++ ) {
        neg_atm[k]->print(os);
        if( k < neg_atm.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << "  :add (";
    for( size_t k = 0; k < adds.size(); k++ ) {
        adds[k]->print(os);
        if( k < adds.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << "  :del (";
    for( size_t k = 0; k < dels.size(); k++ ) {
        dels[k]->print(os);
        if( k < dels.size() - 1 ) os << " ";
    }
    os << ")" << endl;
#if 0
    os << "  :clauses (";
    for( size_t k = 0; k < clauses.size(); k++ ) {
        clauses[k]->print(os);
        if( k < clauses.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << "  :oneof (";
    for( size_t k = 0; k < oneof.size(); k++ ) {
        oneof[k]->print(os);
        if( k < oneof.size() - 1 ) os << " ";
    }
    os << ")" << endl;
#endif
    for( size_t k = 0; k < complex.size(); ++k )
        complex[k]->print(os, 2);
    os << ")" << endl;
}

#endif

void PDDL_Base::Action::print(ostream &os) const {
    os << "(:action " << print_name << endl;

    if( !param.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param.size(); k++ ) {
            if (k > 0) os << ' ';
            param[k]->print(os);
        }
        os << ")" << endl;
    }

    if( precondition != 0 ) {
        os << "    :precondition ";
        precondition->print(os);
        os << endl;
    }

    if( effect != 0 ) {
        os << "    :effect ";
        effect->print(os);
        os << endl;
    }

    if( observe != 0 ) {
        os << "    :observe ";
        observe->print(os);
        os << endl;
    }

#if 0
    os << "  :pos_prec (";
    for( size_t k = 0; k < pos_atm.size(); k++ ) {
        pos_atm[k]->print(os);
        if( k < pos_atm.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << "  :neg_prec (";
    for( size_t k = 0; k < neg_atm.size(); k++ ) {
        neg_atm[k]->print(os);
        if( k < neg_atm.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << "  :add (";
    for( size_t k = 0; k < adds.size(); k++ ) {
        adds[k]->print(os);
        if( k < adds.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << "  :del (";
    for( size_t k = 0; k < dels.size(); k++ ) {
        dels[k]->print(os);
        if( k < dels.size() - 1 ) os << " ";
    }
    os << ")" << endl;
#if 0
    os << "  :clauses (";
    for( size_t k = 0; k < clauses.size(); k++ ) {
        clauses[k]->print(os);
        if( k < clauses.size() - 1 ) os << " ";
    }
    os << ")" << endl;
    os << "  :oneof (";
    for( size_t k = 0; k < oneof.size(); k++ ) {
        oneof[k]->print(os);
        if( k < oneof.size() - 1 ) os << " ";
    }
    os << ")" << endl;
#endif
    for( size_t k = 0; k < complex.size(); ++k )
        complex[k]->print(os, 2);
#endif
    os << ")" << endl;
}

void PDDL_Base::Sensor::print(ostream &os) const {
    os << "(:sensor " << print_name << endl;

    if( !param.empty() ) {
        os << "    :parameters (";
        for( size_t k = 0; k < param.size(); k++ ) {
          if (k > 0) os << ' ';
          param[k]->print(os);
        }
        os << ")" << endl;
    }

    if( condition != 0 ) {
        os << "    :condition ";
        condition->print(os);
        os << endl;
    }

    assert(sense != 0);
    os << "    :sense ";
    sense->print(os);
    os << endl;
    os << ")" << endl;
}

void PDDL_Base::Atom::print(ostream &os, bool extra_neg) const {
    extra_neg = extra_neg ? !neg : neg;
    if( extra_neg ) os << "(not ";
    os << "(" << pred->print_name;
    for (size_t k = 0; k < param.size(); k++)
        param[k]->print(os << ' ');
    os << ")";
    if( extra_neg ) os << ")";
}

void PDDL_Base::print(ostream &os) const { // TODO: fix this
#if 0
    os << "domain: " << (domain_name ? domain_name : "<not defined>") << endl;
    os << "problem: " << (problem_name ? problem_name : "<not defined>") << endl;
    os << "<" << dom_predicates.size() << "," << dom_actions.size() << ">" << endl;

    dom_top_type->print(os);
    for( size_t k = 0; k < dom_types.size(); k++ )
        dom_types[k]->print(os);
    for( size_t k = 0; k < dom_predicates.size(); k++ )
        dom_predicates[k]->print(os);
    for( size_t k = 0; k < dom_actions.size(); k++ )
        dom_actions[k]->print(os);
    for( size_t k = 0; k < dom_init_oneof.size(); k++ )
        dom_init_oneof[k]->print(os);
    for( size_t k = 0; k < dom_init_cls.size(); k++ )
        dom_init_cls[k]->print(os);

    os << "(:pos_goals";
    for( size_t k = 0; k < dom_goal_pos.size(); k++ ) {
        os << " ";
        dom_goal_pos[k]->print(os);
    }
    os << ")" << endl;
    os << "(:neg_goals";
    for( size_t k = 0; k < dom_goal_neg.size(); k++ ) {
        os << " ";
        dom_goal_neg[k]->print(os);
    }
    os << ")" << endl;
#endif
}

PDDL_Name::PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::symbol_vec &arg, size_t n)
  : _neg(false), _sym(sym), _arg(arg) {
}

PDDL_Name::PDDL_Name(const PDDL_Base::Symbol *sym, const PDDL_Base::variable_vec &arg, size_t n)
  : _neg(false), _sym(sym) {
    for( size_t k = 0; k < n; k++ )
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
        for( size_t k = 0; k < _arg.size(); k++ )
            os << '_' << _arg[k]->print_name;
    } else {
        if (_neg) os << "(not ";
        os << '(' << _sym->print_name;
        for( size_t k = 0; k < _arg.size(); k++ )
            os << ' ' << _arg[k]->print_name;
        os << ')';
        if (_neg) os << ')';
    }
}

void PDDL_Base::Literal::instantiate(Instance &ins, index_set &condition) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !neg )
        condition.insert(1 + p->index);
    else
        condition.insert(-(1 + p->index));
}

void PDDL_Base::EQ::instantiate(Instance &ins, index_set &condition) const {
}

void PDDL_Base::And::instantiate(Instance &ins, index_set &condition) const {
    for( size_t k = 0; k < size(); ++k ) {
        (*this)[k]->instantiate(ins, condition);
    }
}

void PDDL_Base::AtomicEffect::instantiate(Instance &ins, index_set &eff, Instance::Action*) const {
    Instance::Atom *p = find_prop(ins, false, true);
    if( !neg )
        eff.insert(1 + p->index);
    else
        eff.insert(-(1 + p->index));
}

bool PDDL_Base::AtomicEffect::is_strongly_static(const PredicateSymbol &p) const {
    assert((pred->print_name != p.print_name) || (pred == &p));
    assert((pred->print_name == p.print_name) || (pred != &p));
    return pred != &p;
}

void PDDL_Base::AndEffect::instantiate(Instance &ins, index_set &eff, Instance::Action *act) const {
    for( size_t k = 0; k < size(); ++k ) {
        (*this)[k]->instantiate(ins, eff, act);
    }
}

bool PDDL_Base::AndEffect::is_strongly_static(const PredicateSymbol &p) const {
    bool strongly_static = true;
    for( size_t k = 0; strongly_static && (k < size()); ++k )
        strongly_static = (*this)[k]->is_strongly_static(p);
    return strongly_static;
}

void PDDL_Base::ConditionalEffect::instantiate(Instance &ins, index_set &eff, Instance::Action *act) const {
    assert(act != 0);
    Instance::When when;
    condition->instantiate(ins, when.condition);
    effect->instantiate(ins, when.effect, act);
    act->when.push_back(when);
}

bool PDDL_Base::ConditionalEffect::is_strongly_static(const PredicateSymbol &p) const {
    return effect->is_strongly_static(p);
}

void PDDL_Base::ForallEffect::instantiate(Instance &ins, index_set &eff, Instance::Action *act) const {
    for( size_t k = 0; k < param.size(); ++k )
        param[k]->value = 0;
    build(ins, 0, eff, act);
}

bool PDDL_Base::ForallEffect::is_strongly_static(const PredicateSymbol &p) const {
    return effect->is_strongly_static(p);
}

void PDDL_Base::ForallEffect::build(Instance &ins, size_t p, index_set &eff, Instance::Action *act) const {
    if( p < param.size() ) {
        TypeSymbol *t = (TypeSymbol*)param[p]->sym_type;
        for( size_t k = 0, ksz = t->elements.size(); k < ksz; ++k ) {
            param[p]->value = t->elements[k];
            // TODO: incremental pruning
            build(ins, p+1, eff, act);
        }
        param[p]->value = 0;
    } else {
        effect->instantiate(ins, eff, act);
    }
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


void PDDL_Base::Observable::instantiate(Instance &ins) const {
    cout << "instantiating observable ..." << flush;
    for( size_t k = 0; k < param.size(); ++k )
        param[k]->value = 0;
    build(ins, 0);
    cout << " ok" << endl;
}

void PDDL_Base::Observable::print(std::ostream &os) const {
    // TODO
}

void PDDL_Base::Observable::build(Instance &ins, size_t p) const {
    if( p < param.size() ) {
        TypeSymbol *t = (TypeSymbol*)param[p]->sym_type;
        for( size_t k = 0, ksz = t->elements.size(); k < ksz; ++k ) {
            param[p]->value = t->elements[k];
            build(ins, p+1);
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
    build(ins, 0);
    cout << " ok" << endl;
}

void PDDL_Base::Sticky::print(std::ostream &os) const {
    // TODO
}

void PDDL_Base::Sticky::build(Instance &ins, size_t p) const {
    if( p < param.size() ) {
        TypeSymbol *t = (TypeSymbol*)param[p]->sym_type;
        for( size_t k = 0, ksz = t->elements.size(); k < ksz; ++k ) {
            param[p]->value = t->elements[k];
            build(ins, p+1);
        }
        param[p]->value = 0;
    } else {
        if( stickies != 0 ) stickies->instantiate(ins, ins.given_stickies);
        // TODO
    }
}

