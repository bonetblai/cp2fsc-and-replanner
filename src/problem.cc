#include <assert.h>
#include <deque>
#include "problem.h"
#include "state.h"

using namespace std;

bool Instance::always_write_parameters_declaration = false;
bool Instance::always_write_requirements_declaration = false;
bool Instance::always_write_precondition = false;
bool Instance::always_write_conjunction = false;

Instance::Instance(const Instance& ins)
  : cross_referenced(false), name(ins.name), atoms(ins.atoms),
    actions(ins.actions), sensors(ins.sensors), axioms(ins.axioms),
    init(ins.init), hidden(ins.hidden),
    goal_literals(ins.goal_literals),
    non_primitive_fluents(ins.non_primitive_fluents),
    observable_fluents(ins.observable_fluents),
    given_observables(ins.given_observables),
    given_stickies(ins.given_stickies),
    options_(ins.options_) {
}

Instance::Atom& Instance::new_atom(Name *name) {
    Atom *a = new Atom(name, atoms.size());
    atoms.push_back(a);
    if( options_.is_enabled("print:atom:creation") )
        cout << "atom " << a->index << "." << a->name << " created" << endl;
    return *a;
}

Instance::Action& Instance::new_action(Name *name) {
    Action *a = new Action(name, actions.size());
    actions.push_back(a);
    if( options_.is_enabled("print:action:creation") )
        cout << "action " << a->index << "." << a->name << " created" << endl;
    return *a;
}

Instance::Sensor& Instance::new_sensor(Name* name) {
    Sensor *r = new Sensor(name, sensors.size());
    sensors.push_back(r);
    if( options_.is_enabled("print:sensor:creation") )
        cout << "sensor " << r->index << "." << r->name << " created" << endl;
    return *r;
}

Instance::Axiom& Instance::new_axiom(Name* name) {
    Axiom *r = new Axiom(name, axioms.size());
    axioms.push_back(r);
    if( options_.is_enabled("print:axiom:creation") )
        cout << "axiom " << r->index << "." << r->name << " created" << endl;
    return *r;
}

void Instance::cross_reference() {
    if( cross_referenced ) return;
    // cross references should be performed here...
    cross_referenced = true;
}

void Instance::remove_unreachable_conditional_effects(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    for( size_t k = 0; k < actions.size(); ++k ) {
        Action &act = *actions[k];
        for( int j = 0; j < (int)act.when.size(); ++j ) {
            bool reachable = true;
            for( index_set::const_iterator it = act.when[j].condition.begin(); it != act.when[j].condition.end(); ++it ) {
                if( ((*it > 0) && !reachable_atoms[*it-1]) ||
                    ((*it < 0) && reachable_atoms[-*it-1] && static_atoms[-*it-1]) ) {
                    reachable = false;
                    break;
                }
            }
            if( !reachable ) {
                act.when[j] = act.when.back();
                act.when.pop_back();
                --j;
            }
        }
    }
}

void Instance::remove_unreachable_axioms(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    for( int k = 0; k < (int)axioms.size(); ++k ) {
        Axiom &axiom = *axioms[k];
        bool reachable = true;
        for( index_set::const_iterator it = axiom.body.begin(); it != axiom.body.end(); ++it ) {
#if 0
            if( *it < 0 ) cout << "ATOM " << atoms[-*it-1]->name << ":";
            if( (*it < 0) && static_atoms[-*it-1] ) cout << " static";
            if( (*it < 0) && reachable_atoms[-*it-1] ) cout << " reachable";
            if( *it < 0 ) cout << endl;
#endif
            if( ((*it > 0) && !reachable_atoms[*it-1]) ||
                ((*it < 0) && reachable_atoms[-*it-1] && static_atoms[-*it-1]) ) {
#if 0
                cout << "removing axiom " << axiom.name << " because atom ";
                if( *it > 0 )
                    cout << atoms[*it-1]->name << " isn't reachable" << endl;
                else
                    cout << "(not " << atoms[-*it-1]->name << ") is reachable and static" << endl;
#endif
                reachable = false;
                break;
            }
        }
        if( !reachable ) {
            if( options_.is_enabled("print:axiom:removal") )
                cout << "removing axiom " << axioms[k]->name << endl;
            axioms[k] = axioms.back();
            axioms.pop_back();
            --k;
        }
    }
}

void Instance::simplify_conditional_effects(const bool_vec &static_atoms) {
    // TODO: implement something; remove effects whose condition contains
    // a negative static fluent that is true at init. Apply similar rule
    // to prune axioms.
}

void Instance::remove_actions(const bool_vec &set, index_vec &map) {
    index_vec rm_map(actions.size());
    size_t j = 0;

    // mark actions to remove and re-index
    for( size_t k = 0; k < actions.size(); ++k ) {
        if( !set[k] ) {
            if( j < k ) {
                actions[j] = actions[k];
                actions[j]->index = j;
            }
            rm_map[k] = j;
            ++j;
        } else {
            if( options_.is_enabled("print:action:removal") )
                cout << "removing action " << actions[k]->name << endl;
            rm_map[k] = no_such_index;
        }
    }

    // update cross-reference bit and remove actions
    if( actions.size() > j ) cross_referenced = false;
    while( actions.size() > j ) actions.pop_back();

    // update map
    for( size_t k = 0; k < map.size(); ++k ) {
        if( map[k] != no_such_index )
            map[k] = rm_map[map[k]];
    }
}

void Instance::remove_sensors(const bool_vec &set, index_vec &map) {
    index_vec rm_map(sensors.size());
    size_t j = 0;

    // mark sensors to remove and re-index
    for( size_t k = 0; k < sensors.size(); ++k ) {
        if( !set[k] ) {
            if( j < k ) {
                sensors[j] = sensors[k];
                sensors[j]->index = (int)j;
            }
            rm_map[k] = j;
            ++j;
        } else {
            if( options_.is_enabled("print:sensor:removal") )
                cout << "removing sensor " << sensors[k]->name << endl;
            rm_map[k] = no_such_index;
        }
    }

    // update cross-reference bit and remove sensors
    if( sensors.size() > j ) cross_referenced = false;
    while( sensors.size() > j ) sensors.pop_back();

    // update map
    for( size_t k = 0; k < map.size(); ++k ) {
        if( map[k] != no_such_index )
            map[k] = rm_map[map[k]];
    }
}

void Instance::remove_axioms(const bool_vec &set, index_vec &map) {
    index_vec rm_map(axioms.size());
    size_t j = 0;

    // mark axioms to remove and re-index
    for( size_t k = 0; k < axioms.size(); ++k ) {
        if( !set[k] ) {
            if( j < k ) {
                axioms[j] = axioms[k];
                axioms[j]->index = j;
            }
            rm_map[k] = j;
            ++j;
        } else {
            if( options_.is_enabled("print:axiom:removal") )
                cout << "removing axiom " << axioms[k]->name << endl;
            rm_map[k] = no_such_index;
        }
    }

    // update cross-reference bit and remove axioms
    if( axioms.size() > j ) cross_referenced = false;
    while( axioms.size() > j ) axioms.pop_back();

    // update map
    for( size_t k = 0; k < map.size(); ++k ) {
        if( map[k] != no_such_index )
            map[k] = rm_map[map[k]];
    }
}

void Instance::remove_atoms(const bool_vec &set, index_vec &map) {
    index_vec rm_map(atoms.size());

    // mark atoms to remove and re-index
    size_t j = 0;
    for( size_t k = 0; k < atoms.size(); ++k ) {
        if( !set[k] ) {
            if( j < k ) {
	        atoms[j] = atoms[k];
	        atoms[j]->index = j;
            }
            rm_map[k] = j;
            ++j;
        } else
            rm_map[k] = no_such_index;
    }

    // remove atoms
    if( atoms.size() > j ) cross_referenced = false;
    while( atoms.size() > j ) atoms.pop_back();

    // update actions
    for( size_t k = 0; k < actions.size(); ++k ) {
        actions[k]->precondition.signed_remap(rm_map);
        actions[k]->effect.signed_remap(rm_map);

        // update conditional effects
        for( size_t j = 0; j < actions[k]->when.size(); ++j ) {
            When &when = actions[k]->when[j];
            when.condition.signed_remap(rm_map);
            when.effect.signed_remap(rm_map);

            // if condition becomes empty, effects are unconditional
            if( when.condition.empty() ) {
                actions[k]->effect.insert(when.effect.begin(), when.effect.end());
                actions[k]->when[j] = actions[k]->when.back();
                actions[k]->when.pop_back();
                --j;
            }
        }
    }

    // update sensors
    for( size_t k = 0; k < sensors.size(); ++k ) {
        sensors[k]->condition.signed_remap(rm_map);
        sensors[k]->sensed.signed_remap(rm_map);
    }

    // update axioms
    for( size_t k = 0; k < axioms.size(); ++k ) {
        axioms[k]->body.signed_remap(rm_map);
        axioms[k]->head.signed_remap(rm_map);
    }

    // update init, hidden, goal, observables and stickies
    init.literals.signed_remap(rm_map);
    for( size_t k = 0; k < init.clauses.size(); ++k )
        init.clauses[k].signed_remap(rm_map);
    for( size_t k = 0; k < init.invariants.size(); ++k )
        init.invariants[k].signed_remap(rm_map);
    for( size_t k = 0; k < init.oneofs.size(); ++k )
        init.oneofs[k].signed_remap(rm_map);

    hidden.literals.signed_remap(rm_map);
    for( size_t k = 0; k < hidden.clauses.size(); ++k )
        hidden.clauses[k].signed_remap(rm_map);
    for( size_t k = 0; k < hidden.invariants.size(); ++k )
        hidden.invariants[k].signed_remap(rm_map);

    goal_literals.signed_remap(rm_map);
    given_observables.signed_remap(rm_map);
    given_stickies.signed_remap(rm_map);

    // the following remaps are *unsigned*
    non_primitive_fluents.remap(rm_map);
    observable_fluents.remap(rm_map);

    // update map
    for( size_t k = 0; k < map.size(); ++k ) {
        if( map[k] != no_such_index )
            map[k] = rm_map[map[k]];
    }
}

void Instance::set_non_primitive_and_observable_fluents() {
    non_primitive_fluents.clear();
    for( size_t k = 0; k < n_axioms(); ++k ) {
        const Axiom &axiom = *axioms[k];
        for( index_set::const_iterator it = axiom.head.begin(); it != axiom.head.end(); ++it ) {
            assert(*it > 0);
            non_primitive_fluents.insert(*it-1);
        }
    }
    observable_fluents.clear();
    for( size_t k = 0; k < n_sensors(); ++k ) {
        const Sensor &sensor = *sensors[k];
        for( index_set::const_iterator it = sensor.sensed.begin(); it != sensor.sensed.end(); ++it ) {
            assert(*it > 0);
            observable_fluents.insert(*it-1);
        }
    }
    for( index_set::const_iterator it = given_observables.begin(); it != given_observables.end(); ++it ) {
        assert(*it > 0);
        if( non_primitive_fluents.find(*it-1) == non_primitive_fluents.end() ) {
            cout << "warning: observable fluent '"
                 << atoms[*it-1]->name
                 << "' isn't non-primitive. Removing..." << endl;
            continue;
        }
        observable_fluents.insert(*it-1);
    }
}

void Instance::set_initial_state(State &state) const {
    for( index_set::const_iterator it = init.literals.begin(); it != init.literals.end(); ++it ) {
        if( *it > 0 )
            state.add(*it-1);
    }
    state.apply_axioms(*this);
}

void Instance::set_hidden_state(State &state) const {
    set_initial_state(state);
    for( index_set::const_iterator it = hidden.literals.begin(); it != hidden.literals.end(); ++it ) {
        if( *it > 0 )
            state.add(*it-1);
    }
    state.apply_axioms(*this);
}

void Instance::clear_cross_reference() {
    cross_referenced = false;
}

void Instance::write_atom_set(ostream &os, const index_set &set) const {
    os << '{';
    for( index_set::const_iterator it = set.begin(); it != set.end(); ++it ) {
        if( it != set.begin() ) os << ',';
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            os << atoms[idx]->name;
        else
            os << "(not " << atoms[idx]->name << ")";
    }
    os << '}';
}

void Instance::write_atom_set(ostream &os, const bool *set) const {
    os << '{';
    bool need_comma = false;
    for( size_t k = 0; k < n_atoms(); k++ ) {
        if( set[k] ) {
            if( need_comma ) os << ',';
            os << atoms[k]->name;
            need_comma = true;
        }
    }
    os << '}';
}

void Instance::write_atom_set(ostream &os, const bool_vec &set) const {
    os << '{';
    bool need_comma = false;
    for( size_t k = 0; k < n_atoms(); k++ ) {
        if( set[k] ) {
            if( need_comma ) os << ',';
            os << atoms[k]->name;
            need_comma = true;
        }
    }
    os << '}';
}

void Instance::write_atom_sets(ostream &os, const index_set_vec &sets) const {
    os << '{';
    for( size_t k = 0; k < sets.size(); k++ ) {
        if( k > 0 ) os << ',';
        write_atom_set(os, sets[k]);
    }
    os << '}';
}

void Instance::write_action_set(ostream &os, const index_vec &set) const {
    os << '{';
    for( size_t k = 0; k < set.size(); k++ ) {
        if( k > 0 ) os << ',';
        os << actions[set[k]]->name;
    }
    os << '}';
}

void Instance::write_action_set(ostream &os, const bool *set) const {
    os << '{';
    bool need_comma = false;
    for( size_t k = 0; k < n_actions(); k++ ) {
        if( set[k] ) {
            if (need_comma) os << ',';
            os << actions[k]->name;
            need_comma = true;
        }
    }
    os << '}';
}

void Instance::write_action_set(ostream &os, const bool_vec &set) const {
    os << '{';
    bool need_comma = false;
    for( size_t k = 0; k < n_actions(); k++ ) {
        if (set[k]) {
            if (need_comma) os << ',';
            os << actions[k]->name;
            need_comma = true;
        }
    }
    os << '}';
}

void Instance::write_domain(ostream &os, int indent) const {
    // setup indentation string
    char *istr = new char[indent+1];
    for( int i = 0; i < indent; ++i ) istr[i] = ' ';
    istr[indent] = '\0';

    // name of domain
    if( name ) {
        Name::domain_name_only = true;
        os << "(define (domain " << name << ")" << endl;
        Name::domain_name_only = false;
    } else {
        os << "(define (domain NONAME)" << endl;
    }

    // requirements
    if( always_write_requirements_declaration ) {
        os << istr << "(:requirements :strips :conditional-effects)" << endl;
    }

    // predicates
    if( n_atoms() > 0 ) {
        os << istr << "(:predicates" << endl;
        for( size_t k = 0; k < n_atoms(); k++ )
            os << istr << istr << atoms[k]->name << endl;
        os << istr << ")" << endl;
    }

    // actions
    for( size_t k = 0; k < n_actions(); k++ ) {
        const Action *act = actions[k];

        // name and parameters
        os << istr << "(:action " << act->name->to_string() << endl;
        if( always_write_parameters_declaration )
            os << istr << istr << ":parameters ()" << endl;

        // precondition
        if( act->precondition.size() > 0 ) {
            os << istr << istr << ":precondition";
            if( (act->precondition.size() > 1) || always_write_conjunction ) os << " (and";
            for( index_set::const_iterator p = act->precondition.begin(); p != act->precondition.end(); ++p ) {
                int idx = (*p < 0 ? -*p : *p) - 1;
                if( *p < 0  )
                    os << " (not " << atoms[idx]->name << ")";
                else
                    os << " " << atoms[idx]->name;
            }
            if( (act->precondition.size() > 1) || always_write_conjunction ) os << ")";
            os << endl;
        } else if( always_write_precondition ) {
            if( always_write_conjunction )
                os << istr << istr << ":precondition (and)" << endl;
            else
                os << istr << istr << ":precondition ()" << endl;
        }

        // effects
        int n_effects = act->effect.size() + act->when.size();
        if( n_effects > 0 ) {
            os << istr << istr << ":effect";
            if( n_effects > 1 ) os << " (and";

            // add and del effects
            for( index_set::const_iterator p = act->effect.begin(); p != act->effect.end(); ++p ) {
                int idx = (*p < 0 ? -*p : *p) - 1;
                if( *p > 0 )
                    os << " " << atoms[idx]->name;
                else
                    os << " (not " << atoms[idx]->name << ")";
            }

            // conditional effects
            for( size_t i = 0; i < act->when.size(); ++i ) {
                const When &w = act->when[i];
                int n_ceffects = w.effect.size();
                if( n_ceffects > 0 ) {
                    assert(!w.condition.empty());
                    if( (i > 0) || (act->effect.size() > 0) )
                        os << endl << istr << istr << "            ";
                    os << " (when";

                    // condition
                    if( (w.condition.size() > 1) || always_write_conjunction ) os << " (and";
                    for( index_set::const_iterator p = w.condition.begin(); p != w.condition.end(); ++p ) {
                        int idx = (*p < 0 ? -*p : *p) - 1;
                        if( *p > 0 )
                            os << " " << atoms[idx]->name;
                        else
                            os << " (not " << atoms[idx]->name << ")";
                    }
                    if( (w.condition.size() > 1) || always_write_conjunction ) os << ")";

                    // effects
                    if( n_ceffects > 1 ) os << " (and";
                    for( index_set::const_iterator p = w.effect.begin(); p != w.effect.end(); ++p ) {
                        int idx = (*p < 0 ? -*p : *p) - 1;
                        if( *p > 0 )
                            os << " " << atoms[idx]->name;
                        else
                            os << " (not " << atoms[idx]->name << ")";
                    }
                    if( n_ceffects > 1 ) os << ")";

                    os << ")"; // close (when ....)
                }
            }

            if( n_effects > 1 ) os << ")";
        }
        os << ")" << endl;
    }

    // axioms
    for( size_t k = 0; k < n_axioms(); k++ ) {
        const Axiom *axiom = axioms[k];

        // name and parameters
        os << istr << "(:axiom " << axiom->name->to_string() << endl;
        if( always_write_parameters_declaration )
            os << istr << istr << ":parameters ()" << endl;

        // body
        if( axiom->body.size() > 0 ) {
            os << istr << istr << ":body";
            if( (axiom->body.size() > 1) || always_write_conjunction ) os << " (and";
            for( index_set::const_iterator p = axiom->body.begin(); p != axiom->body.end(); ++p ) {
                int idx = (*p < 0 ? -*p : *p) - 1;
                if( *p < 0  )
                    os << " (not " << atoms[idx]->name << ")";
                else
                    os << " " << atoms[idx]->name;
            }
            if( (axiom->body.size() > 1) || always_write_conjunction ) os << ")";
            os << endl;
        } else if( always_write_precondition ) {
            if( always_write_conjunction )
                os << istr << istr << ":body (and)" << endl;
            else
                os << istr << istr << ":body ()" << endl;
        }

        // head
        int n_heads = axiom->head.size();
        if( n_heads > 0 ) {
            os << istr << istr << ":head";
            if( n_heads > 1 ) os << " (and";
            for( index_set::const_iterator p = axiom->head.begin(); p != axiom->head.end(); ++p ) {
                assert(*p > 0);
                int idx = *p - 1;
                 os << " " << atoms[idx]->name;
            }
            if( n_heads > 1 ) os << ")";
        }
        os << ")" << endl;
    }

    os << ")" << endl;
    delete[] istr;
}

void Instance::write_problem(ostream &os, const State *state, int indent) const {
    // setup indentation string
    char *istr = new char[indent+1];
    for( int i = 0; i < indent; ++i ) istr[i] = ' ';
    istr[indent] = '\0';

    // name of domain
    if( name ) {
        Name::problem_name_only = true;
        os << "(define (problem " << name << ")" << endl;
        Name::problem_name_only = false;
        Name::domain_name_only = true;
        os << istr << "(:domain " << name << ")" << endl;
        Name::domain_name_only = false;
    } else {
        os << "(define (problem NONAME)" << endl;
        os << istr << "(:domain NONAME)" << endl;
    }

    // initial situation
    if( (state == 0) && !init.literals.empty() ) {
        os << istr << "(:init";
        for( index_set::const_iterator it = init.literals.begin(); it != init.literals.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << atoms[idx]->name;
            else
                os << " (not " << atoms[idx]->name << ")";
        }
        os << ")" << endl;
    } else if( state != 0 ) {
        os << istr << "(:init";
        for( State::const_iterator it = state->begin(); it != state->end(); ++it ) {
            os << " " << atoms[*it]->name;
        }
        os << ")" << endl;
    }

    // goal situation
    if( !goal_literals.empty() ) {
        os << istr << "(:goal";
        if( goal_literals.size() > 1 ) os << " (and";
        for( index_set::const_iterator it = goal_literals.begin(); it != goal_literals.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << atoms[idx]->name;
            else
                os << " (not " << atoms[idx]->name << ")";
        }
        if( goal_literals.size() > 1 ) os << ")";
        os << ")" << endl;
    }

    os << ")" << endl;
    delete[] istr;
}

void Instance::print(ostream &os) const {
    print_atoms(os);
    print_actions(os);
    print_sensors(os);
    print_axioms(os);
    os << "goal: ";
    write_atom_set(os, goal_literals);
    os << endl;
}

void Instance::print_atoms(ostream &os) const {
    for( size_t k = 0; k < n_atoms(); ++k )
        os << k << ". " << atoms[k]->name << endl;
}

void Instance::Action::print(ostream &os, const Instance &i) const {
    os << name << ":" << endl;
    if( precondition.size() > 0 ) {
        os << "  pre:";
        for( index_set::const_iterator it = precondition.begin(); it != precondition.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << idx << '.' << i.atoms[idx]->name;
            else
                os << " -" << idx << '.' << i.atoms[idx]->name;
        }
        os << endl;
    }
    if( effect.size() > 0 ) {
        os << "  eff:";
        for( index_set::const_iterator it = effect.begin(); it != effect.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << idx << '.' << i.atoms[idx]->name;
            else
                os << " -" << idx << '.' << i.atoms[idx]->name;
        }
        os << endl;
    }
    if( when.size() > 0 ) {
        os << "  when:";
        for( when_vec::const_iterator wi = when.begin(); wi != when.end(); ++wi ) {
            for( index_set::const_iterator it = wi->condition.begin(); it != wi->condition.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 )
                    os << " " << idx << '.' << i.atoms[idx]->name;
                else
                    os << " -" << idx << '.' << i.atoms[idx]->name;
            }
            os << " ==> :effect";
            for( index_set::const_iterator it = wi->effect.begin(); it != wi->effect.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 )
                    os << " " << idx << '.' << i.atoms[idx]->name;
                else
                    os << " -" << idx << '.' << i.atoms[idx]->name;
            }
            os << endl;
        }
    }
    if( cost != 1 ) os << "  cost: " << cost << endl;
}

void Instance::Sensor::print(ostream &os, const Instance &i) const {
    os << name << ":" << endl;
    if( condition.size() > 0 ) {
        os << "  condition:";
        for( index_set::const_iterator it = condition.begin(); it != condition.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << idx << '.' << i.atoms[idx]->name;
            else
                os << " -" << idx << '.' << i.atoms[idx]->name;
        }
        os << endl;
    }
    assert(!sensed.empty());
    os << "  sensed:";
    for( index_set::const_iterator it = sensed.begin(); it != sensed.end(); ++it ) {
        assert(*it >= 0);
        os << " " << *it-1 << '.' << i.atoms[*it-1]->name;
    }
    os << endl;
}

void Instance::Axiom::print(ostream &os, const Instance &i) const {
    os << name << ":" << endl;
    if( body.size() > 0 ) {
        os << "  body:";
        for( index_set::const_iterator it = body.begin(); it != body.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << idx << '.' << i.atoms[idx]->name;
            else
                os << " -" << idx << '.' << i.atoms[idx]->name;
        }
        os << endl;
    }
    assert(!head.empty());
    os << "  head:";
    for( index_set::const_iterator it = head.begin(); it != head.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            os << " " << idx << '.' << i.atoms[idx]->name;
        else
            os << " -" << idx << '.' << i.atoms[idx]->name;
    }
    os << endl;
}

void Instance::print_actions(ostream &os) const {
    for( size_t k = 0; k < n_actions(); k++ ) {
        os << k << ". ";
        actions[k]->print(os, *this);
    }
}

void Instance::print_sensors(ostream &os) const {
    for (size_t k = 0; k < n_sensors(); k++) {
        os << k << ". ";
        sensors[k]->print(os, *this);
    }
}

void Instance::print_axioms(ostream &os) const {
    for (size_t k = 0; k < n_axioms(); k++) {
        os << k << ". ";
        axioms[k]->print(os, *this);
    }
}

void Instance::generate_reachable_state_space(StateSet &hash) const {
    State state;
    set_initial_state(state);
    generate_reachable_state_space(state, hash);
}

void Instance::generate_reachable_state_space(const State &state, StateSet &hash) const {
    deque<const State*> queue;
    State *seed = new State(state);
    queue.push_back(seed);
    hash.insert(seed);
    while( !queue.empty() ) {
        const State *s = queue.front();
        //cout << "current state = "; s->print(cout, *this); cout << endl;
        queue.pop_front();
        for( size_t k = 0; k < n_actions(); ++k ) {
            Action &act = *actions[k];
            if( s->applicable(act) ) {
                State *t = new State(*s);
                t->apply(act, *this);
                //cout << "   next state = "; t->print(cout, *this); cout << " : " << flush;
                pair<StateSet::iterator, bool> p = hash.insert(t);
                if( p.second ) {
                    //cout << "enqueued!" << endl;
                    queue.push_back(t);
                } else {
                    //cout << "deleted!" << endl;
                    delete t;
                }
            }
        }
    }
}

void Instance::generate_initial_states(StateSet &initial_states) const {
    static State t;
    set_initial_state(t);

    int i = 0, j = 0;
    std::vector<int> stack, restore;
    while( true ) {
        assert(stack.size() == restore.size());
        if( i == (int)init.oneofs.size() ) {
            if( t.satisfy(init.clauses) ) {
                State *s = new State(t);
                s->clear_non_primitive_fluents(*this);
                s->apply_axioms(*this);
                initial_states.insert(s);
            }
            if( i == 0 ) break;
            int l = restore.back(), p = l < 0 ? -l : l;
            j = stack.back();
            if( l != INT_MAX ) t.apply(p-1, p!=l);
            restore.pop_back();
            stack.pop_back();
            --i;
            continue;
        }
        if( j == (int)init.oneofs[i].size() ) {
            if( i == 0 ) break;
            int l = restore.back(), p = l < 0 ? -l : l;
            j = stack.back();
            if( l != INT_MAX ) t.apply(p-1, p!=l);
            restore.pop_back();
            stack.pop_back();
            --i;
            continue;
        }
        int l = init.oneofs[i][j], p = l < 0? -l : l;
        restore.push_back(t.satisfy(p-1,p==l) ? -l : INT_MAX);
        t.apply(p-1, p!=l);
        stack.push_back(1+j);
        ++i;
        j = 0;
    }
}

