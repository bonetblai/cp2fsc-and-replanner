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
#include <deque>
#include "problem.h"
#include "state.h"
#include "utils.h"

using namespace std;

bool Instance::always_write_parameters_declaration_ = false;
bool Instance::always_write_requirements_declaration_ = false;
bool Instance::always_write_precondition_ = false;
bool Instance::always_write_conjunction_ = false;

#ifndef SMART
#if 0 // NOT USED
Instance::Instance(const Instance& ins)
  : cross_referenced_(false),
    name_(ins.name_),
    atoms_(ins.atoms_),
    actions_(ins.actions_),
    sensors_(ins.sensors_),
    axioms_(ins.axioms_),
    init_(ins.init_),
    hidden_(ins.hidden_),
    goal_literals_(ins.goal_literals_),
    non_primitive_fluents_(ins.non_primitive_fluents_),
    observable_fluents_(ins.observable_fluents_),
    given_observables_(ins.given_observables_),
    given_stickies_(ins.given_stickies_),
    static_atoms_from_base_(ins.static_atoms_from_base_),
    options_(ins.options_) {
}
#endif
#endif

Instance::~Instance() {
    //delete name_;
#ifndef SMART
    for( size_t k = 0; k < actions_.size(); ++k )
        delete actions_[k];
    for( size_t k = 0; k < sensors_.size(); ++k )
        delete sensors_[k];
    for( size_t k = 0; k < axioms_.size(); ++k )
        delete axioms_[k];
    for( size_t k = 0; k < atoms_.size(); ++k )
        delete atoms_[k];
#endif
}

Instance::Atom& Instance::new_atom(const string &name) {
#ifdef SMART
    unique_ptr<Atom> a = make_unique<Atom>(name, atoms_.size());
    atoms_.emplace_back(move(a));
#else
    Atom *a = new Atom(name, atoms_.size());
    atoms_.push_back(a);
#endif
    if( options_.is_enabled("problem:print:atom:creation") )
        cout << "atom " << atoms_.back()->index() << "." << atoms_.back()->name() << " created" << endl;
#ifdef SMART
    return *atoms_.back().get();
#else
    return *a;
#endif
}

Instance::Action& Instance::new_action(const string &name) {
#ifdef SMART
    unique_ptr<Action> a = make_unique<Action>(name, actions_.size());
    actions_.emplace_back(move(a));
#else
    Action *a = new Action(name, actions_.size());
    actions_.push_back(a);
#endif
    if( options_.is_enabled("problem:print:action:creation") )
        cout << "action " << actions_.back()->index() << "." << actions_.back()->name() << " created" << endl;
#ifdef SMART
    return *actions_.back().get();
#else
    return *a;
#endif
}

Instance::Sensor& Instance::new_sensor(const string &name) {
#ifdef SMART
    unique_ptr<Sensor> r = make_unique<Sensor>(name, sensors_.size());
    sensors_.emplace_back(move(r));
#else
    Sensor *r = new Sensor(name, sensors_.size());
    sensors_.push_back(r);
#endif
    if( options_.is_enabled("problem:print:sensor:creation") )
        cout << "sensor " << sensors_.back()->index() << "." << sensors_.back()->name() << " created" << endl;
#ifdef SMART
    return *sensors_.back().get();
#else
    return *r;
#endif
}

Instance::Axiom& Instance::new_axiom(const string &name) {
#ifdef SMART
    unique_ptr<Axiom> r = make_unique<Axiom>(name, axioms_.size());
    axioms_.emplace_back(move(r));
#else
    Axiom *r = new Axiom(name, axioms_.size());
    axioms_.push_back(r);
#endif
    if( options_.is_enabled("problem:print:axiom:creation") )
        cout << "axiom " << axioms_.back()->index() << "." << axioms_.back()->name() << " created" << endl;
#ifdef SMART
    return *axioms_.back().get();
#else
    return *r;
#endif
}

void Instance::remove_unreachable_conditional_effects(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    // compute known literals in init
    bool_vec pos_literal_in_init(n_atoms(), false);
    bool_vec neg_literal_in_init(n_atoms(), false);
    for( index_set::const_iterator it = init_.literals().begin(); it != init_.literals().end(); ++it ) {
        if( *it > 0 )
            pos_literal_in_init[*it - 1] = true;
        else
            neg_literal_in_init[-*it - 1] = true;
    }

    // iterate over actions and their conditional effects.
    for( size_t k = 0; k < actions_.size(); ++k ) {
        Action &act = *actions_[k];

        for( size_t j = 0; j < act.when().size(); ++j ) {
            bool reachable_effect = true;
            for( index_set::const_iterator it = act.when()[j].condition().begin(); it != act.when()[j].condition().end(); ++it ) {
                //if( (*it > 0) && !reachable_atoms[*it-1] ) {
                if( ((*it > 0) && !reachable_atoms[*it-1]) ||
                    ((*it > 0) && static_atoms[*it-1] && neg_literal_in_init[*it-1]) ||
                    ((*it < 0) && static_atoms[-*it-1] && pos_literal_in_init[-*it-1]) ) {
                    reachable_effect = false;
                    //State::print_literal(cout, *it, this);
                    //cout << endl;
                    break;
                }
            }
            if( !reachable_effect ) {
                act.when()[j] = act.when().back();
                act.when().pop_back();
                --j;
            }
        }
    }
}

void Instance::remove_unreachable_axioms(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    // compute known literals in init
    bool_vec pos_literal_in_init(n_atoms(), false);
    bool_vec neg_literal_in_init(n_atoms(), false);
    for( index_set::const_iterator it = init_.literals().begin(); it != init_.literals().end(); ++it ) {
        if( *it > 0 )
            pos_literal_in_init[*it - 1] = true;
        else
            neg_literal_in_init[-*it - 1] = true;
    }

    // iterate over axioms
    for( size_t k = 0; k < axioms_.size(); ++k ) {
        Axiom &axiom = *axioms_[k];
        bool reachable_axiom = true;
        for( index_set::const_iterator it = axiom.body().begin(); it != axiom.body().end(); ++it ) {
            if( ((*it > 0) && !reachable_atoms[*it-1]) ||
                ((*it > 0) && static_atoms[*it-1] && neg_literal_in_init[*it-1]) ||
                ((*it < 0) && static_atoms[-*it-1] && pos_literal_in_init[-*it-1]) ) {
                reachable_axiom = false;
                break;
            }
        }
        if( !reachable_axiom ) {
            if( options_.is_enabled("problem:print:axiom:removal") )
                cout << "removing axiom " << k << "." << axioms_[k]->name() << endl;
#ifdef SMART
            axioms_[k] = move(axioms_.back());
#else
            delete axioms_[k];
            axioms_[k] = axioms_.back();
#endif
            axioms_.pop_back();
            --k;
        }
    }
}

void Instance::remove_unreachable_sensors(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    // compute known literals in init
    bool_vec pos_literal_in_init(n_atoms(), false);
    bool_vec neg_literal_in_init(n_atoms(), false);
    for( index_set::const_iterator it = init_.literals().begin(); it != init_.literals().end(); ++it ) {
        if( *it > 0 )
            pos_literal_in_init[*it - 1] = true;
        else
            neg_literal_in_init[-*it - 1] = true;
    }

    // iterate over sensors
    for( size_t k = 0; k < sensors_.size(); ++k ) {
        Sensor &sensor = *sensors_[k];
        bool reachable_sensor = true;
        for( index_set::const_iterator it = sensor.condition().begin(); it != sensor.condition().end(); ++it ) {
            if( ((*it > 0) && !reachable_atoms[*it-1]) ||
                ((*it > 0) && static_atoms[*it-1] && neg_literal_in_init[*it-1]) ||
                ((*it < 0) && static_atoms[-*it-1] && pos_literal_in_init[-*it-1]) ) {
                reachable_sensor = false;
                break;
            }
        }
        if( !reachable_sensor ) {
            if( options_.is_enabled("problem:print:sensor:removal") )
                cout << "removing sensor " << k << "." << sensors_[k]->name() << endl;
#ifdef SMART
            sensors_[k] = move(sensors_.back());
#else
            delete sensors_[k];
            sensors_[k] = sensors_.back();
#endif
            sensors_.pop_back();
            --k;
        }
    }
}

void Instance::simplify_conditions_and_invariants(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    // compute known literals in init
    bool_vec pos_literal_in_init(n_atoms(), false);
    bool_vec neg_literal_in_init(n_atoms(), false);
    for( index_set::const_iterator it = init_.literals().begin(); it != init_.literals().end(); ++it ) {
        int index = *it > 0 ? *it - 1 : -*it - 1;
        if( *it > 0 )
            pos_literal_in_init[index] = true;
        else
            neg_literal_in_init[index] = true;
    }

    // iterate over actions
    for( size_t k = 0; k < actions_.size(); ++k ) {
        Action &act = *actions_[k];

        // precondition
        for( index_set::const_iterator p = act.precondition().begin(); p != act.precondition().end(); ) {
            int index = *p > 0 ? *p - 1 : -*p - 1;
            if( protected_atoms_.find(index) != protected_atoms_.end() ) {
                ++p;
                continue;
            }
            if( ((*p < 0) && !reachable_atoms[index]) ||
                ((*p > 0) && static_atoms[index] && pos_literal_in_init[index]) ||
                ((*p < 0) && static_atoms[index] && neg_literal_in_init[index]) ) {
#if 0
                cout << "Eliminating ";
                State::print_literal(cout, *p, this);
                cout << " from " << act.name() << endl;
#endif
                act.precondition().erase(p++);
            } else {
                ++p;
            }
        }

        // conditional effects
        for( size_t j = 0; j < act.when().size(); ++j ) {
            When &when = act.when()[j];
            for( index_set::const_iterator p = when.condition().begin(); p != when.condition().end(); ) {
                int index = *p > 0 ? *p - 1 : -*p - 1;
                if( protected_atoms_.find(index) != protected_atoms_.end() ) {
                    ++p;
                    continue;
                }
                if( ((*p < 0) && !reachable_atoms[index]) ||
                    ((*p > 0) && static_atoms[index] && pos_literal_in_init[index]) ||
                    ((*p < 0) && static_atoms[index] && neg_literal_in_init[index]) ) {
#if 0
                    cout << "Eliminating " << flush;
                    State::print_literal(cout, *p, this);
                    cout << " from " << act.name() << endl;
#endif
                    when.condition().erase(p++);
                } else {
                    ++p;
                }
            }

            // If condition becomes empty, make effects unconditional and
            // remove conditional effect
            if( when.condition().empty() ) {
                act.effect().insert(when.effect().begin(), when.effect().end());
                act.when()[j] = act.when().back();
                act.when().pop_back();
                --j;
            }
        }
    }

    // iterate over axioms
    for( size_t k = 0; k < axioms_.size(); ++k ) {
        Axiom &axiom = *axioms_[k];
        for( index_set::const_iterator p = axiom.body().begin(); p != axiom.body().end(); ) {
            int index = *p > 0 ? *p - 1 : -*p - 1;
            if( protected_atoms_.find(index) != protected_atoms_.end() ) {
                ++p;
                continue;
            }
            if( ((*p < 0) && !reachable_atoms[index]) ||
                ((*p > 0) && static_atoms[index] && pos_literal_in_init[index]) ||
                ((*p < 0) && static_atoms[index] && neg_literal_in_init[index]) ) {
                axiom.body().erase(p++);
            } else {
                ++p;
            }
        }
    }

    // iterate over sensors
    for( size_t k = 0; k < sensors_.size(); ++k ) {
        Sensor &sensor = *sensors_[k];
        for( index_set::const_iterator p = sensor.condition().begin(); p != sensor.condition().end(); ) {
            int index = *p > 0 ? *p - 1 : -*p - 1;
            if( protected_atoms_.find(index) != protected_atoms_.end() ) {
                ++p;
                continue;
            }
            if( ((*p < 0) && !reachable_atoms[index]) ||
                ((*p > 0) && static_atoms[index] && pos_literal_in_init[index]) ||
                ((*p < 0) && static_atoms[index] && neg_literal_in_init[index]) ) {
                sensor.condition().erase(p++);
            } else {
                ++p;
            }
        }
    }

    // iterate over invariants: at this stage there should be only
    // AT_LEAST_ONE and AT_MOST_ONE invariants
    for( size_t k = 0; k < init_.invariants().size(); ++k ) {
        Invariant &invariant = init_.invariants()[k];
        //cout << "Processing invariant "; invariant.write(cout, 0, *this);
        assert((invariant.type() == Invariant::AT_LEAST_ONE) || (invariant.type() == Invariant::AT_MOST_ONE));
        index_set completion_for_initial_state;
        bool remove_invariant = false;

        // simplify invariant
        for( size_t i = 0; i < invariant.size(); ++i ) {
            int lit = invariant[i];
            int index = lit > 0 ? lit - 1 : -lit - 1;
            if( protected_atoms_.find(index) != protected_atoms_.end() ) continue;
            if( ((lit > 0) && !reachable_atoms[index]) ||
                ((lit > 0) && static_atoms[index] && neg_literal_in_init[index]) ||
                ((lit < 0) && static_atoms[index] && pos_literal_in_init[index]) ) {
#if 1
                cout << "Dropping ";
                State::print_literal(cout, lit, this);
                cout << " from invariant " << flush;
                invariant.write(cout, 0, *this);
#endif
                invariant[i] = invariant.back();
                invariant.pop_back();
                --i;
            }
            if( ((lit < 0) && !reachable_atoms[index]) ||
                ((lit > 0) && static_atoms[index] && pos_literal_in_init[index]) ||
                ((lit < 0) && static_atoms[index] && neg_literal_in_init[index]) ) {
                remove_invariant = true;
                invariant[i] = invariant.back();
                invariant.pop_back();
#if 1
                cout << "Removing invariant ";
                invariant.write(cout, 0, *this);
#endif
                break;
            }
        }

        // calculate completion of initial state
        if( (invariant.type() == Invariant::AT_LEAST_ONE) && !remove_invariant && (invariant.size() == 1) ) {
            remove_invariant = true;
            completion_for_initial_state.insert(invariant[0]);
        } else if( (invariant.type() == Invariant::AT_MOST_ONE) && remove_invariant ) {
            for( size_t i = 0; i < invariant.size(); ++i )
                completion_for_initial_state.insert(-invariant[i]);
        }

        // complete initial state
        for( index_set::const_iterator it = completion_for_initial_state.begin(); it != completion_for_initial_state.end(); ++it ) {
            if( options_.is_enabled("problem:print:completion:initial-state") ) {
                State::print_literal(cout, *it, this);
                cout << endl;
            }
            init_.literals().insert(*it);
        }

        // Remove invariant and complete initial state
        if( remove_invariant ) {
            if( options_.is_enabled("problem:print:invariant:removal") ) {
                cout << "removing invariant ";
                init_.invariants()[k].write(cout, 0, *this);
            }
            init_.invariants()[k] = init_.invariants().back();
            init_.invariants().pop_back();
            --k;
        }
    }
}

void Instance::remove_actions(const bool_vec &set, index_vec &map) {
    index_vec rm_map(actions_.size());
    size_t j = 0;

    // mark actions to remove and re-index
    for( size_t k = 0; k < actions_.size(); ++k ) {
        if( !set[k] ) {
            if( j < k ) {
#ifdef SMART
                actions_[j] = move(actions_[k]);
#else
                actions_[j] = actions_[k];
#endif
                actions_[j]->set_index(j);
            }
            rm_map[k] = j;
            ++j;
        } else {
            if( options_.is_enabled("problem:print:action:removal") )
                cout << "removing action " << k << "." << actions_[k]->name() << endl;
#ifndef SMART
            delete actions_[k];
#endif
            rm_map[k] = no_such_index;
        }
    }

    // update cross-reference bit and remove actions
    if( actions_.size() > j ) cross_referenced_ = false;
    while( actions_.size() > j ) actions_.pop_back();

    // update map
    for( size_t k = 0; k < map.size(); ++k ) {
        if( map[k] != no_such_index )
            map[k] = rm_map[map[k]];
    }
}

void Instance::remove_atoms(const bool_vec &set, index_vec &atom_map) {
    index_vec rm_map(atoms_.size());

    // avoid removing protected atoms
    bool_vec new_set(set);
    for( index_set::const_iterator it = protected_atoms_.begin(); it != protected_atoms_.end(); ++it )
        new_set[*it] = false;

    if( options_.is_enabled("problem:print:atom:removal") ) {
        cout << Utils::yellow() << "atoms to remove = ";
        write_atom_set(cout, new_set);
        cout << Utils::normal() << endl;
    }

    // mark atoms to remove and re-index
    size_t j = 0;
    for( size_t k = 0; k < atoms_.size(); ++k ) {
        if( !new_set[k] ) {
            if( j < k ) {
#ifdef SMART
	        atoms_[j] = move(atoms_[k]);
#else
	        atoms_[j] = atoms_[k];
#endif
	        atoms_[j]->set_index(j);
            }
            rm_map[k] = j;
            ++j;
        } else {
#ifndef SMART
            delete atoms_[k];
#endif
            rm_map[k] = no_such_index;
        }
    }

    // remove atoms
    if( atoms_.size() > j ) cross_referenced_ = false;
    while( atoms_.size() > j ) atoms_.pop_back();

    // update actions
    for( size_t k = 0; k < actions_.size(); ++k ) {
        actions_[k]->precondition().signed_remap(rm_map);
        actions_[k]->effect().signed_remap(rm_map);

        // update conditional effects
        for( size_t j = 0; j < actions_[k]->when().size(); ++j ) {
            When &when = actions_[k]->when()[j];
            when.condition().signed_remap(rm_map);
            when.effect().signed_remap(rm_map);

            // if condition becomes empty, effects are unconditional
            if( when.condition().empty() ) {
                actions_[k]->effect().insert(when.effect().begin(), when.effect().end());
                actions_[k]->when()[j] = actions_[k]->when().back();
                actions_[k]->when().pop_back();
                --j;
            }
        }
    }

    // update sensors
    for( size_t k = 0; k < sensors_.size(); ++k ) {
        sensors_[k]->condition().signed_remap(rm_map);
        sensors_[k]->sense().signed_remap(rm_map);
    }

    // update axioms
    for( size_t k = 0; k < axioms_.size(); ++k ) {
        axioms_[k]->body().signed_remap(rm_map);
        axioms_[k]->head().signed_remap(rm_map);
    }

    // update init, hidden, goal, observables and stickies
    init_.literals().signed_remap(rm_map);
    for( size_t k = 0; k < init_.clauses().size(); ++k )
        init_.clauses()[k].signed_remap(rm_map);
    for( size_t k = 0; k < init_.invariants().size(); ++k )
        init_.invariants()[k].signed_remap(rm_map);
    for( size_t k = 0; k < init_.oneofs().size(); ++k )
        init_.oneofs()[k].signed_remap(rm_map);
    for( size_t k = 0; k < hidden_.size(); ++k ) {
        hidden_[k].literals().signed_remap(rm_map);
        assert(hidden_[k].invariants().empty());
        assert(hidden_[k].clauses().empty());
        assert(hidden_[k].oneofs().empty());
    }
    /*
    for( size_t k = 0; k < hidden_.clauses().size(); ++k )
        hidden_.clauses()[k].signed_remap(rm_map);
    for( size_t k = 0; k < hidden_.invariants().size(); ++k )
        hidden_.invariants()[k].signed_remap(rm_map);
    */

    goal_literals_.signed_remap(rm_map);
    given_observables_.signed_remap(rm_map);
    given_stickies_.signed_remap(rm_map);
    static_atoms_from_base_.signed_remap(rm_map);

    // the following remaps are *unsigned*
    non_primitive_fluents_.remap(rm_map);
    observable_fluents_.remap(rm_map);

    // update atom_map
    for( size_t k = 0; k < atom_map.size(); ++k ) {
        if( atom_map[k] != no_such_index )
            atom_map[k] = rm_map[atom_map[k]];
    }
}

void Instance::calculate_non_primitive_and_observable_fluents() {
    non_primitive_fluents_.clear();
    for( size_t k = 0; k < n_axioms(); ++k ) {
        const Axiom &axiom = *axioms_[k];
        for( index_set::const_iterator it = axiom.head().begin(); it != axiom.head().end(); ++it ) {
            assert(*it > 0);
            non_primitive_fluents_.insert(*it-1);
        }
    }
    observable_fluents_.clear();
    for( size_t k = 0; k < n_sensors(); ++k ) {
        const Sensor &sensor = *sensors_[k];
        for( index_set::const_iterator it = sensor.sense().begin(); it != sensor.sense().end(); ++it )
            observable_fluents_.insert(*it > 0 ? *it - 1 : -*it - 1);
    }
    for( index_set::const_iterator it = given_observables_.begin(); it != given_observables_.end(); ++it ) {
        assert(*it > 0);
        if( non_primitive_fluents_.find(*it-1) == non_primitive_fluents_.end() ) {
            cout << Utils::warning() << "observable fluent '";
            State::print_literal(cout, *it, this);
            cout << "' isn't non-primitive. Removing..." << endl;
            continue;
        }
        observable_fluents_.insert(*it-1);
    }
}

void Instance::set_state(const Init &init, State &state, bool apply_axioms) const {
    for( index_set::const_iterator it = init.literals().begin(); it != init.literals().end(); ++it ) {
        if( *it > 0 ) state.add(*it - 1);
    }
    if( apply_axioms ) state.apply_axioms(*this);
}

void Instance::set_initial_state(State &state, bool apply_axioms) const {
    set_state(init_, state, apply_axioms);
}

void Instance::set_hidden_state(int k, State &state) const {
    set_initial_state(state, false);
    set_state(hidden_[k], state, false);
    // close initial hidden state with axioms. Axioms in k-replanner
    // only appear in translations of lw1 problems.
    // (See explanation in solver.cc and generation of axioms in base.cc).
    state.apply_axioms(*this);
}

void Instance::clear_cross_reference() {
    cross_referenced_ = false;
}

void Instance::cross_reference() {
    cross_referenced_ = true;
}

void Instance::write_atom_set(ostream &os, const index_set &set) const {
    os << '{';
    for( index_set::const_iterator it = set.begin(); it != set.end(); ++it ) {
        if( it != set.begin() ) os << ',';
        State::print_literal(os, *it, this);
    }
    os << '}';
}

void Instance::write_atom_set(ostream &os, const bool *set) const {
    os << '{';
    bool need_comma = false;
    for( size_t k = 0; k < n_atoms(); k++ ) {
        if( set[k] ) {
            if( need_comma ) os << ',';
            State::print_literal(os, 1 + k, this);
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
            State::print_literal(os, 1 + k, this);
            need_comma = true;
        }
    }
    os << '}';
}

void Instance::write_atom_sets(ostream &os, const vector<index_set> &sets) const {
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
        os << actions_[set[k]]->name();
    }
    os << '}';
}

void Instance::write_action_set(ostream &os, const bool *set) const {
    os << '{';
    bool need_comma = false;
    for( size_t k = 0; k < n_actions(); k++ ) {
        if( set[k] ) {
            if (need_comma) os << ',';
            os << actions_[k]->name();
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
            os << actions_[k]->name();
            need_comma = true;
        }
    }
    os << '}';
}

void Instance::write_domain(ostream &os, int indent) const {
    // name of domain
    if( domain_name_ != "" )
        os << "(define (domain " << domain_name_ << ")" << endl;
    else
        os << "(define (domain NONAME)" << endl;

    // requirements
    if( always_write_requirements_declaration_ ) {
        os << string(indent, ' ') << "(:requirements :strips :conditional-effects)" << endl;
    }

    // predicates
    if( n_atoms() > 0 ) {
        os << string(indent, ' ') << "(:predicates" << endl;
        for( size_t k = 0; k < n_atoms(); k++ ) {
            os << string(2 * indent, ' ');
            State::print_literal(os, 1 + k, this);
            os << endl;
        }
        os << string(indent, ' ') << ")" << endl;
    }

    // actions
    for( size_t k = 0; k < n_actions(); k++ ) {
        const Action &act = *actions_[k];
        if( act.effect().size() + act.when().size() > 0 )
            act.write(os, indent, *this);
    }

    // axioms
    for( size_t k = 0; k < n_axioms(); k++ ) {
        axioms_[k]->write(os, indent, *this);
    }

    // sensors
    for( size_t k = 0; k < n_sensors(); k++ ) {
        sensors_[k]->write(os, indent, *this);
    }

    // write additional elements (virtual function call)
    write_domain_additional(os, indent);

    os << ")" << endl;
}

void Instance::write_problem(ostream &os, const State *state, int indent) const {
    // name of problem
    if( problem_name_ != "")
        os << "(define (problem " << problem_name_ << ")" << endl;
    else
        os << "(define (problem NONAME)" << endl;

    // name of domain
    if( domain_name_ != "")
        os << string(indent, ' ') << "(:domain " << domain_name_ << ")" << endl;
    else
        os << string(indent, ' ') << "(:domain NONAME)" << endl;

    // initial situation
    if( (state == 0) && !init_.literals().empty() ) {
        os << string(indent, ' ') << "(:init";
        for( index_set::const_iterator it = init_.literals().begin(); it != init_.literals().end(); ++it ) {
            os << " ";
            State::print_literal(os, *it, this);
        }
        os << ")" << endl;
    } else if( state != 0 ) {
        os << string(indent, ' ') << "(:init";
        for( State::const_iterator it = state->begin(); it != state->end(); ++it ) {
            os << " ";
            State::print_literal(os, 1 + *it, this);
        }
        os << ")" << endl;
    }

    // goal situation
    if( !goal_literals_.empty() ) {
        os << string(indent, ' ') << "(:goal";
        if( goal_literals_.size() > 1 ) os << " (and";
        for( index_set::const_iterator it = goal_literals_.begin(); it != goal_literals_.end(); ++it ) {
            os << " ";
            State::print_literal(os, *it, this);
        }
        if( goal_literals_.size() > 1 ) os << ")";
        os << ")" << endl;
    }

    // write additional elements (virtual function call)
    write_problem_additional(os, state, indent);

    os << ")" << endl;
}

void Instance::print(ostream &os) const {
    print_atoms(os);
    print_actions(os);
    print_sensors(os);
    print_axioms(os);
    os << "goal: ";
    write_atom_set(os, goal_literals_);
    os << endl;
}

void Instance::print_atoms(ostream &os) const {
    for( size_t k = 0; k < n_atoms(); ++k ) {
        os << k << ". ";
        State::print_literal(os, 1 + k, this);
        os << endl;
    }
}

void Instance::Action::print(ostream &os, const Instance &i) const {
    os << name_ << ":";
    if( comment_ != "" ) os << "    ; " << comment_;
    os << endl;

    if( precondition_.size() > 0 ) {
        os << "  pre:";
        for( index_set::const_iterator it = precondition_.begin(); it != precondition_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            os << (*it > 0 ? " " : " -") << idx << ".";
            State::print_literal(os, 1 + idx, &i);
        }
        os << endl;
    }
    if( effect_.size() > 0 ) {
        os << "  eff:";
        for( index_set::const_iterator it = effect_.begin(); it != effect_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            os << (*it > 0 ? " " : " -") << idx << ".";
            State::print_literal(os, 1 + idx, &i);
        }
        os << endl;
    }
    if( when().size() > 0 ) {
        os << "  when:";
        for( when_vec::const_iterator wi = when().begin(); wi != when().end(); ++wi ) {
            for( index_set::const_iterator it = wi->condition().begin(); it != wi->condition().end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                os << (*it > 0 ? " " : " -") << idx << ".";
                State::print_literal(os, 1 + idx, &i);
            }
            os << " ==> :effect";
            for( index_set::const_iterator it = wi->effect().begin(); it != wi->effect().end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                os << (*it > 0 ? " " : " -") << idx << ".";
                State::print_literal(os, 1 + idx, &i);
            }
            os << endl;
        }
    }
    if( cost_ != 1 ) os << "  cost: " << cost_ << endl;
}

void Instance::Action::write(ostream &os, int indent, const Instance &instance) const {
    // name and parameters
    os << string(indent, ' ') << "(:action " << name_;
    if( comment_ != "" ) os << "    ; " << comment_;
    os << endl;
    if( always_write_parameters_declaration_ )
        os << string(2 * indent, ' ') << ":parameters ()" << endl;

    // precondition
    if( precondition_.size() > 0 ) {
        os << string(2 * indent, ' ') << ":precondition";
        if( (precondition_.size() > 1) || always_write_conjunction_ ) os << " (and";
        for( index_set::const_iterator p = precondition_.begin(); p != precondition_.end(); ++p ) {
            os << " ";
            State::print_literal(os, *p, &instance);
        }
        if( (precondition_.size() > 1) || always_write_conjunction_ ) os << ")";
        os << endl;
    } else if( always_write_precondition_ ) {
        if( always_write_conjunction_ )
            os << string(2 * indent, ' ') << ":precondition (and)" << endl;
        else
            os << string(2 * indent, ' ') << ":precondition ()" << endl;
    }

    // effects
    int n_effects = effect_.size() + when().size();
    if( n_effects > 0 ) {
        os << string(2 * indent, ' ') << ":effect";
        if( n_effects > 1 ) os << " (and";

        // add and del effects
        for( index_set::const_iterator p = effect_.begin(); p != effect_.end(); ++p ) {
            os << " ";
            State::print_literal(os, *p, &instance);
        }

        // conditional effects
        for( size_t i = 0; i < when().size(); ++i ) {
            const When &w = when()[i];
            int n_ceffects = w.effect().size();
            if( n_ceffects > 0 ) {
                assert(!w.condition().empty());
                if( (i > 0) || (effect_.size() > 0) )
                    os << endl << string(2 * indent, ' ') << "            ";
                os << " (when";

                // condition
                if( (w.condition().size() > 1) || always_write_conjunction_ ) os << " (and";
                for( index_set::const_iterator p = w.condition().begin(); p != w.condition().end(); ++p ) {
                    os << " ";
                    State::print_literal(os, *p, &instance);
                }
                if( (w.condition().size() > 1) || always_write_conjunction_ ) os << ")";

                // effects
                if( n_ceffects > 1 ) os << " (and";
                for( index_set::const_iterator p = w.effect().begin(); p != w.effect().end(); ++p ) {
                    os << " ";
                    State::print_literal(os, *p, &instance);
                }
                if( n_ceffects > 1 ) os << ")";

                os << ")"; // close (when ....)
            }
        }

        if( n_effects > 1 ) os << ")";
    }
    os << ")" << endl;
}

void Instance::Sensor::print(ostream &os, const Instance &i) const {
    os << name_ << ":" << endl;
    if( condition_.size() > 0 ) {
        os << "  condition:";
        for( index_set::const_iterator it = condition_.begin(); it != condition_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            os << (*it > 0 ? " " : " -") << idx << ".";
            State::print_literal(os, 1 + idx, &i);
        }
        os << endl;
    }
    assert(!sense_.empty());
    os << "  sense:";
    for( index_set::const_iterator it = sense_.begin(); it != sense_.end(); ++it ) {
        int index = *it > 0 ? *it-1 : -*it - 1;
        os << (*it > 0 ? " " : " -") << index << ".";
        State::print_literal(os, 1 + index, &i);
    }
    os << endl;
}

void Instance::Sensor::write(ostream &os, int indent, const Instance &instance) const {
    // name and parameters
    os << string(indent, ' ') << "(:sensor " << name_ << endl;
    if( always_write_parameters_declaration_ )
        os << string(2 * indent, ' ') << ":parameters ()" << endl;

    // condition
    if( condition_.size() > 0 ) {
        os << string(2 * indent, ' ') << ":condition";
        if( (condition_.size() > 1) || always_write_conjunction_ ) os << " (and";
        for( index_set::const_iterator p = condition_.begin(); p != condition_.end(); ++p ) {
            os << " ";
            State::print_literal(os, *p, &instance);
        }
        if( (condition_.size() > 1) || always_write_conjunction_ ) os << ")";
        os << endl;
    } else if( always_write_precondition_ ) {
        if( always_write_conjunction_ )
            os << string(2 * indent, ' ') << ":condition (and)" << endl;
        else
            os << string(2 * indent, ' ') << ":condition ()" << endl;
    }

    // sense
    assert(!sense_.empty());
    os << string(2 * indent, ' ') << ":sense";
    for( index_set::const_iterator it = sense_.begin(); it != sense_.end(); ++it ) {
        int index = *it > 0 ? *it-1 : -*it - 1;
        os << (*it > 0 ? " " : " -") << index << ".";
        State::print_literal(os, 1 + index, &instance);
    }
    os << ")" << endl;
}

void Instance::Axiom::print(ostream &os, const Instance &i) const {
    os << name_ << ":" << endl;
    if( body_.size() > 0 ) {
        os << "  body:";
        for( index_set::const_iterator it = body_.begin(); it != body_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            os << (*it > 0 ? " " : " -") << idx << ".";
            State::print_literal(os, 1 + idx, &i);
        }
        os << endl;
    }
    assert(!head_.empty());
    os << "  head:";
    for( index_set::const_iterator it = head_.begin(); it != head_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        os << (*it > 0 ? " " : " -") << idx << ".";
        State::print_literal(os, 1 + idx, &i);
    }
    os << endl;
}

void Instance::Axiom::write(ostream &os, int indent, const Instance &instance) const {
    // name and parameters
    os << string(indent, ' ') << "(:axiom " << name_ << endl;
    if( always_write_parameters_declaration_ )
        os << string(2 * indent, ' ') << ":parameters ()" << endl;

    // body
    if( body_.size() > 0 ) {
        os << string(2 * indent, ' ') << ":body";
        if( (body_.size() > 1) || always_write_conjunction_ ) os << " (and";
        for( index_set::const_iterator p = body_.begin(); p != body_.end(); ++p ) {
            os << " ";
            State::print_literal(os, *p, &instance);
        }
        if( (body_.size() > 1) || always_write_conjunction_ ) os << ")";
        os << endl;
    } else if( always_write_precondition_ ) {
        if( always_write_conjunction_ )
            os << string(2 * indent, ' ') << ":body (and)" << endl;
        else
            os << string(2 * indent, ' ') << ":body ()" << endl;
    }

    // head
    int n_heads = head_.size();
    if( n_heads > 0 ) {
        os << string(2 * indent, ' ') << ":head";
        if( n_heads > 1 ) os << " (and";
        for( index_set::const_iterator p = head_.begin(); p != head_.end(); ++p ) {
            assert(*p > 0);
            os << " ";
            State::print_literal(os, *p, &instance);
        }
        if( n_heads > 1 ) os << ")";
    }
    os << ")" << endl;
}

void Instance::Invariant::write(ostream &os, int indent, const Instance &instance) const {
    os << string(indent, ' ') << "(";
    assert((type() == AT_LEAST_ONE) || (type() == AT_MOST_ONE));
    if( type() == AT_LEAST_ONE )
        os << "at-least-one";
    else
        os << "at-most-one";

    if( !Xprecondition_.empty() ) {
        os << " (:precondition";
        for( index_set::const_iterator it = Xprecondition_.begin(); it != Xprecondition_.end(); ++it ) {
            os << " ";
            State::print_literal(os, *it, &instance);
        }
        os << ")";
    }

    for( size_t i = 0; i < size(); ++i ) {
        os << " ";
        State::print_literal(os, (*this)[i], &instance);
    }
    os << ")" << endl;
}

void Instance::print_actions(ostream &os) const {
    for( size_t k = 0; k < n_actions(); k++ ) {
        os << k << ". ";
        actions_[k]->print(os, *this);
    }
}

void Instance::print_sensors(ostream &os) const {
    for( size_t k = 0; k < n_sensors(); ++k ) {
        os << k << ". ";
        sensors_[k]->print(os, *this);
    }
}

void Instance::print_axioms(ostream &os) const {
    for( size_t k = 0; k < n_axioms(); ++k ) {
        os << k << ". ";
        axioms_[k]->print(os, *this);
    }
}

void Instance::generate_reachable_state_space(StateSet &hash, size_t bounded_reachability, bool verbose) const {
    State state;
    set_initial_state(state);
    generate_reachable_state_space(state, hash, bounded_reachability, verbose);
}

void Instance::generate_reachable_state_space(const State &state, StateSet &hash, size_t bounded_reachability, bool verbose) const {
    deque<const State*> queue;
    State *seed = new State(state);
    queue.push_back(seed);
    hash.insert(seed);
    while( !queue.empty() && (hash.size() < bounded_reachability) ) {
        const State *s = queue.front();
        if( verbose ) {
            cout << "current state = ";
            s->print(cout, *this);
            cout << endl;
        }
        queue.pop_front();
        for( size_t k = 0; k < n_actions(); ++k ) {
            Action &act = *actions_[k];
            if( s->applicable(act) ) {
                State *t = new State(*s);
                t->apply(act, *this);
                if( verbose ) {
                    cout << "   next state = ";
                    t->print(cout, *this);
                    cout << " : " << flush;
                }
                pair<StateSet::iterator, bool> p = hash.insert(t);
                if( p.second ) {
                    if( verbose ) cout << "enqueued!" << endl;
                    queue.push_back(t);
                } else {
                    if( verbose ) cout << "deleted!" << endl;
                    delete t;
                }
            }
        }
    }

    // empty queue
    while( !queue.empty() ) queue.pop_front();
}

void Instance::generate_initial_states(StateSet &initial_states, bool verbose) const {
    static State t;
    set_initial_state(t);

    int i = 0, j = 0;
    vector<int> stack, restore;
    while( true ) {
        assert(stack.size() == restore.size());
        if( i == (int)init_.oneofs().size() ) {
            if( t.satisfy(init_.clauses()) ) {
                State *s = new State(t);
                s->clear_non_primitive_fluents(*this);
                s->apply_axioms(*this);
                if( verbose ) {
                    cout << "new initial state = ";
                    s->print(cout, *this);
                    cout << endl;
                }
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
        if( j == (int)init_.oneofs()[i].size() ) {
            if( i == 0 ) break;
            int l = restore.back(), p = l < 0 ? -l : l;
            j = stack.back();
            if( l != INT_MAX ) t.apply(p-1, p!=l);
            restore.pop_back();
            stack.pop_back();
            --i;
            continue;
        }
        int l = init_.oneofs()[i][j], p = l < 0? -l : l;
        restore.push_back(t.satisfy(p-1,p==l) ? -l : INT_MAX);
        t.apply(p-1, p!=l);
        stack.push_back(1+j);
        ++i;
        j = 0;
    }
}

void Instance::create_deductive_rules() {
    // This is pretty much the same as for invariant actions for KP.
    // The difference is that this rule apply at the atom level and
    // not at the KP-atom level. We call the generated rules, the
    // deductive rules.
    for( invariant_vec::const_iterator it = init_.invariants().begin(); it != init_.invariants().end(); ++it ) {
        const Invariant &invariant = *it;
        assert(invariant.type() == Invariant::AT_LEAST_ONE);

        for( size_t k = 0; k < invariant.size(); ++k ) {
            string name = string("deductive-rule-") + Utils::to_string(deductive_rules_.size());
#ifdef SMART
            unique_ptr<Action> rule = make_unique<Action>(name, deductive_rules_.size());
#else
            Action *rule = new Action(name, deductive_rules_.size());
#endif

            // conditional effects
            When c_eff;
            if( invariant.type() == Invariant::AT_LEAST_ONE ) {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    if( i != k ) {
                        c_eff.condition().insert(-lit);
                        if( c_eff.effect().contains(-lit) )
                           c_eff.effect().clear();
                    } else {
                        if( !c_eff.condition().contains(lit) )
                            c_eff.effect().insert(lit);
                    }
                }
            } else {
                // This should be dead code.
                assert(invariant.type() == Invariant::AT_MOST_ONE);
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    if( i == k ) {
                        c_eff.condition().insert(lit);
                    } else {
                        c_eff.effect().insert(-lit);
                    }
                }
            }

            // push conditional effect
            if( !c_eff.effect().empty() ) {
                rule->when().push_back(c_eff);
#ifdef SMART
                deductive_rules_.emplace_back(move(rule));
#else
                deductive_rules_.push_back(rule);
#endif
                if( options_.is_enabled("problem:print:deductive-rule:creation") ) {
                    rule->print(cout, *this);
                }
            } else {
#ifndef SMART
                delete rule;
#endif
            }
        }
    }
}

void Instance::apply_deductive_rules(State &state) const {
    // compute the deductive closure with respect to the invariants
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        State old_state(state);
        for( size_t k = 0; k < deductive_rules_.size(); ++k ) {
            const Action &act = *deductive_rules_[k];
            if( state.applicable(act) ) {
                state.apply(act);
            }
        }
        fix_point_reached = old_state == state;
    }
}

