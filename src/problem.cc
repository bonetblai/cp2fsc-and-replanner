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
    options_(ins.options_) {
}

Instance::~Instance() {
    delete name_;
    for( size_t k = 0; k < actions_.size(); ++k )
        delete actions_[k];
    for( size_t k = 0; k < sensors_.size(); ++k )
        delete sensors_[k];
    for( size_t k = 0; k < axioms_.size(); ++k )
        delete axioms_[k];
    for( size_t k = 0; k < atoms_.size(); ++k )
        delete atoms_[k];
}

Instance::Atom& Instance::new_atom(Name *name) {
    Atom *a = new Atom(name, atoms_.size());
    atoms_.push_back(a);
    if( options_.is_enabled("problem:print:atom:creation") )
        cout << "atom " << a->index_ << "." << a->name_ << " created" << endl;
    return *a;
}

Instance::Action& Instance::new_action(Name *name) {
    Action *a = new Action(name, actions_.size());
    actions_.push_back(a);
    if( options_.is_enabled("problem:print:action:creation") )
        cout << "action " << a->index_ << "." << a->name_ << " created" << endl;
    return *a;
}

Instance::Sensor& Instance::new_sensor(Name* name) {
    Sensor *r = new Sensor(name, sensors_.size());
    sensors_.push_back(r);
    if( options_.is_enabled("problem:print:sensor:creation") )
        cout << "sensor " << r->index_ << "." << r->name_ << " created" << endl;
    return *r;
}

Instance::Axiom& Instance::new_axiom(Name* name) {
    Axiom *r = new Axiom(name, axioms_.size());
    axioms_.push_back(r);
    if( options_.is_enabled("problem:print:axiom:creation") )
        cout << "axiom " << r->index_ << "." << r->name_ << " created" << endl;
    return *r;
}

void Instance::remove_unreachable_conditional_effects(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    // compute known literals in init
    bool_vec pos_literal_in_init(n_atoms(), false);
    bool_vec neg_literal_in_init(n_atoms(), false);
    for( index_set::const_iterator it = init_.literals_.begin(); it != init_.literals_.end(); ++it ) {
        if( *it > 0 )
            pos_literal_in_init[*it - 1] = true;
        else
            neg_literal_in_init[-*it - 1] = true;
    }

    // iterate over actions and their conditional effects.
    for( size_t k = 0; k < actions_.size(); ++k ) {
        Action &act = *actions_[k];

        for( int j = 0; j < (int)act.when_.size(); ++j ) {
            bool reachable_effect = true;
            for( index_set::const_iterator it = act.when_[j].condition_.begin(); it != act.when_[j].condition_.end(); ++it ) {
                //if( (*it > 0) && !reachable_atoms[*it-1] ) {
                if( ((*it > 0) && !reachable_atoms[*it-1]) ||
                    ((*it > 0) && static_atoms[*it-1] && neg_literal_in_init[*it-1]) ||
                    ((*it < 0) && static_atoms[-*it-1] && pos_literal_in_init[-*it-1]) ) {
                    reachable_effect = false;
#if 0
                    if( *it > 0 )
                        cout << "positive atom " << atoms_[*it - 1]->name_ << endl;
                    else
                        cout << "negative atom " << atoms_[-*it - 1]->name_ << endl;
#endif
                    break;
                }
            }
            if( !reachable_effect ) {
                act.when_[j] = act.when_.back();
                act.when_.pop_back();
                --j;
            }
        }
    }
}

void Instance::remove_unreachable_axioms(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    // compute known literals in init
    bool_vec pos_literal_in_init(n_atoms(), false);
    bool_vec neg_literal_in_init(n_atoms(), false);
    for( index_set::const_iterator it = init_.literals_.begin(); it != init_.literals_.end(); ++it ) {
        if( *it > 0 )
            pos_literal_in_init[*it - 1] = true;
        else
            neg_literal_in_init[-*it - 1] = true;
    }

    // iterate over axioms
    for( int k = 0; k < (int)axioms_.size(); ++k ) {
        Axiom &axiom = *axioms_[k];
        bool reachable_axiom = true;
        for( index_set::const_iterator it = axiom.body_.begin(); it != axiom.body_.end(); ++it ) {
            if( ((*it > 0) && !reachable_atoms[*it-1]) ||
                ((*it > 0) && static_atoms[*it-1] && neg_literal_in_init[*it-1]) ||
                ((*it < 0) && static_atoms[-*it-1] && pos_literal_in_init[-*it-1]) ) {
                reachable_axiom = false;
                break;
            }
        }
        if( !reachable_axiom ) {
            if( options_.is_enabled("problem:print:axiom:removal") )
                cout << "removing axiom " << k << "." << axioms_[k]->name_ << endl;
            delete axioms_[k];
            axioms_[k] = axioms_.back();
            axioms_.pop_back();
            --k;
        }
    }
}

void Instance::remove_unreachable_sensors(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    // compute known literals in init
    bool_vec pos_literal_in_init(n_atoms(), false);
    bool_vec neg_literal_in_init(n_atoms(), false);
    for( index_set::const_iterator it = init_.literals_.begin(); it != init_.literals_.end(); ++it ) {
        if( *it > 0 )
            pos_literal_in_init[*it - 1] = true;
        else
            neg_literal_in_init[-*it - 1] = true;
    }

    // iterate over sensors
    for( int k = 0; k < (int)sensors_.size(); ++k ) {
        Sensor &sensor = *sensors_[k];
        bool reachable_sensor = true;
        for( index_set::const_iterator it = sensor.condition_.begin(); it != sensor.condition_.end(); ++it ) {
            if( ((*it > 0) && !reachable_atoms[*it-1]) ||
                ((*it > 0) && static_atoms[*it-1] && neg_literal_in_init[*it-1]) ||
                ((*it < 0) && static_atoms[-*it-1] && pos_literal_in_init[-*it-1]) ) {
                reachable_sensor = false;
                break;
            }
        }
        if( !reachable_sensor ) {
            if( options_.is_enabled("problem:print:sensor:removal") )
                cout << "removing sensor " << k << "." << sensors_[k]->name_ << endl;
            delete sensors_[k];
            sensors_[k] = sensors_.back();
            sensors_.pop_back();
            --k;
        }
    }
}

void Instance::simplify_conditions_and_invariants(const bool_vec &reachable_atoms, const bool_vec &static_atoms) {
    // compute known literals in init
    bool_vec pos_literal_in_init(n_atoms(), false);
    bool_vec neg_literal_in_init(n_atoms(), false);
    for( index_set::const_iterator it = init_.literals_.begin(); it != init_.literals_.end(); ++it ) {
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
        for( index_set::const_iterator p = act.precondition_.begin(); p != act.precondition_.end(); ) {
            int index = *p > 0 ? *p - 1 : -*p - 1;
            if( ((*p < 0) && !reachable_atoms[index]) ||
                ((*p > 0) && static_atoms[index] && pos_literal_in_init[index]) ||
                ((*p < 0) && static_atoms[index] && neg_literal_in_init[index]) ) {
#if 0
                cout << "Eliminating ";
                if( *p > 0 )
                    cout << atoms_[*p-1]->name_;
                else
                    cout << "(not " << atoms_[-*p-1]->name_ << ")";
                cout << " from " << act.name_ << endl;
#endif
                act.precondition_.erase(p++);
            } else {
                ++p;
            }
        }

        // conditional effects
        for( int j = 0; j < (int)act.when_.size(); ++j ) {
            When &when = act.when_[j];
            for( index_set::const_iterator p = when.condition_.begin(); p != when.condition_.end(); ) {
                int index = *p > 0 ? *p - 1 : -*p - 1;
                if( ((*p < 0) && !reachable_atoms[index]) ||
                    ((*p > 0) && static_atoms[index] && pos_literal_in_init[index]) ||
                    ((*p < 0) && static_atoms[index] && neg_literal_in_init[index]) ) {
#if 0
                    cout << "Eliminating " << flush;
                    if( *p > 0 )
                        cout << atoms_[*p-1]->name_ << flush;
                    else
                        cout << "(not " << atoms_[-*p-1]->name_ << ")" << flush;
                    cout << " from " << act.name_ << endl;
#endif
                    when.condition_.erase(p++);
                } else {
                    ++p;
                }
            }

            // If condition becomes empty, make effects unconditional and
            // remove conditional effect
            if( when.condition_.empty() ) {
                act.effect_.insert(when.effect_.begin(), when.effect_.end());
                act.when_[j] = act.when_.back();
                act.when_.pop_back();
                --j;
            }
        }
    }

    // iterate over axioms
    for( size_t k = 0; k < axioms_.size(); ++k ) {
        Axiom &axiom = *axioms_[k];
        for( index_set::const_iterator p = axiom.body_.begin(); p != axiom.body_.end(); ) {
            int index = *p > 0 ? *p - 1 : -*p - 1;
            if( ((*p < 0) && !reachable_atoms[index]) ||
                ((*p > 0) && static_atoms[index] && pos_literal_in_init[index]) ||
                ((*p < 0) && static_atoms[index] && neg_literal_in_init[index]) ) {
                axiom.body_.erase(p++);
            } else {
                ++p;
            }
        }
    }

    // iterate over sensors
    for( size_t k = 0; k < sensors_.size(); ++k ) {
        Sensor &sensor = *sensors_[k];
        for( index_set::const_iterator p = sensor.condition_.begin(); p != sensor.condition_.end(); ) {
            int index = *p > 0 ? *p - 1 : -*p - 1;
            if( ((*p < 0) && !reachable_atoms[index]) ||
                ((*p > 0) && static_atoms[index] && pos_literal_in_init[index]) ||
                ((*p < 0) && static_atoms[index] && neg_literal_in_init[index]) ) {
                sensor.condition_.erase(p++);
            } else {
                ++p;
            }
        }
    }

    // iterate over invariants: at this stage there should be only 
    // AT_LEAST_ONE and AT_MOST_ONE invariants
    for( int k = 0; k < (int)init_.invariants_.size(); ++k ) {
        Invariant &invariant = init_.invariants_[k];
        //cout << "Processing invariant "; invariant.write(cout, 0, *this);
        assert((invariant.type_ == Invariant::AT_LEAST_ONE) || (invariant.type_ == Invariant::AT_MOST_ONE));
        index_set completion_for_initial_state;
        bool remove_invariant = false;

        // simplify invariant
        for( int i = 0; i < (int)invariant.size(); ++i ) {
            int lit = invariant[i];
            int index = lit > 0 ? lit - 1 : -lit - 1;
            if( ((lit > 0) && !reachable_atoms[index]) ||
                ((lit > 0) && static_atoms[index] && neg_literal_in_init[index]) ||
                ((lit < 0) && static_atoms[index] && pos_literal_in_init[index]) ) {
#if 1
                cout << "Dropping ";
                if( lit > 0 )
                    cout << atoms_[lit-1]->name_->to_string();
                else
                    cout << "(not " << atoms_[-lit-1]->name_->to_string() << ")";
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
        if( (invariant.type_ == Invariant::AT_LEAST_ONE) && !remove_invariant && (invariant.size() == 1) ) {
            remove_invariant = true;
            completion_for_initial_state.insert(invariant[0]);
        } else if( (invariant.type_ == Invariant::AT_MOST_ONE) && remove_invariant ) {
            for( int i = 0; i < (int)invariant.size(); ++i )
                completion_for_initial_state.insert(-invariant[i]);
        }
 
        // complete initial state
        for( index_set::const_iterator it = completion_for_initial_state.begin(); it != completion_for_initial_state.end(); ++it ) {
            if( options_.is_enabled("problem:print:completion:initial-state") ) {
                int lit = *it;
                if( lit > 0 )
                    cout << atoms_[lit-1]->name_->to_string() << endl;
                else
                    cout << "(not " << atoms_[-lit-1]->name_->to_string() << ")" << endl;
            }
            init_.literals_.insert(*it);
        }

        // Remove invariant and complete initial state
        if( remove_invariant ) {
            if( options_.is_enabled("problem:print:invariant:removal") ) {
                cout << "removing invariant ";
                init_.invariants_[k].write(cout, 0, *this);
            }
            init_.invariants_[k] = init_.invariants_.back();
            init_.invariants_.pop_back();
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
                actions_[j] = actions_[k];
                actions_[j]->index_ = j;
            }
            rm_map[k] = j;
            ++j;
        } else {
            if( options_.is_enabled("problem:print:action:removal") )
                cout << "removing action " << k << "." << actions_[k]->name_ << endl;
            delete actions_[k];
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

void Instance::remove_atoms(const bool_vec &set, index_vec &map) {
    index_vec rm_map(atoms_.size());

    // mark atoms to remove and re-index
    size_t j = 0;
    for( size_t k = 0; k < atoms_.size(); ++k ) {
        if( !set[k] ) {
            if( j < k ) {
	        atoms_[j] = atoms_[k];
	        atoms_[j]->index_ = j;
            }
            rm_map[k] = j;
            ++j;
        } else {
            delete atoms_[k];
            rm_map[k] = no_such_index;
        }
    }

    // remove atoms
    if( atoms_.size() > j ) cross_referenced_ = false;
    while( atoms_.size() > j ) atoms_.pop_back();

    // update actions
    for( size_t k = 0; k < actions_.size(); ++k ) {
        actions_[k]->precondition_.signed_remap(rm_map);
        actions_[k]->effect_.signed_remap(rm_map);

        // update conditional effects
        for( int j = 0; j < (int)actions_[k]->when_.size(); ++j ) {
            When &when = actions_[k]->when_[j];
            when.condition_.signed_remap(rm_map);
            when.effect_.signed_remap(rm_map);

            // if condition becomes empty, effects are unconditional
            if( when.condition_.empty() ) {
                actions_[k]->effect_.insert(when.effect_.begin(), when.effect_.end());
                actions_[k]->when_[j] = actions_[k]->when_.back();
                actions_[k]->when_.pop_back();
                --j;
            }
        }
    }

    // update sensors
    for( size_t k = 0; k < sensors_.size(); ++k ) {
        sensors_[k]->condition_.signed_remap(rm_map);
        sensors_[k]->sense_.signed_remap(rm_map);
    }

    // update axioms
    for( size_t k = 0; k < axioms_.size(); ++k ) {
        axioms_[k]->body_.signed_remap(rm_map);
        axioms_[k]->head_.signed_remap(rm_map);
    }

    // update init, hidden, goal, observables and stickies
    init_.literals_.signed_remap(rm_map);
    for( size_t k = 0; k < init_.clauses_.size(); ++k )
        init_.clauses_[k].signed_remap(rm_map);
    for( size_t k = 0; k < init_.invariants_.size(); ++k )
        init_.invariants_[k].signed_remap(rm_map);
    for( size_t k = 0; k < init_.oneofs_.size(); ++k )
        init_.oneofs_[k].signed_remap(rm_map);
    for( size_t k = 0; k < hidden_.size(); ++k ) {
        hidden_[k].literals_.signed_remap(rm_map);
        assert(hidden_[k].invariants_.empty());
        assert(hidden_[k].clauses_.empty());
        assert(hidden_[k].oneofs_.empty());
    }
    /*
    for( size_t k = 0; k < hidden_.clauses_.size(); ++k )
        hidden_.clauses_[k].signed_remap(rm_map);
    for( size_t k = 0; k < hidden_.invariants_.size(); ++k )
        hidden_.invariants_[k].signed_remap(rm_map);
    */

    goal_literals_.signed_remap(rm_map);
    given_observables_.signed_remap(rm_map);
    given_stickies_.signed_remap(rm_map);

    // the following remaps are *unsigned*
    non_primitive_fluents_.remap(rm_map);
    observable_fluents_.remap(rm_map);

    // update map
    for( size_t k = 0; k < map.size(); ++k ) {
        if( map[k] != no_such_index )
            map[k] = rm_map[map[k]];
    }
}

void Instance::calculate_non_primitive_and_observable_fluents() {
    non_primitive_fluents_.clear();
    for( size_t k = 0; k < n_axioms(); ++k ) {
        const Axiom &axiom = *axioms_[k];
        for( index_set::const_iterator it = axiom.head_.begin(); it != axiom.head_.end(); ++it ) {
            assert(*it > 0);
            non_primitive_fluents_.insert(*it-1);
        }
    }
    observable_fluents_.clear();
    for( size_t k = 0; k < n_sensors(); ++k ) {
        const Sensor &sensor = *sensors_[k];
        for( index_set::const_iterator it = sensor.sense_.begin(); it != sensor.sense_.end(); ++it )
            observable_fluents_.insert(*it > 0 ? *it - 1 : -*it - 1);
    }
    for( index_set::const_iterator it = given_observables_.begin(); it != given_observables_.end(); ++it ) {
        assert(*it > 0);
        if( non_primitive_fluents_.find(*it-1) == non_primitive_fluents_.end() ) {
            cout << Utils::warning() << "observable fluent '"
                 << atoms_[*it-1]->name_
                 << "' isn't non-primitive. Removing..." << endl;
            continue;
        }
        observable_fluents_.insert(*it-1);
    }
}

void Instance::set_initial_state(State &state, bool apply_axioms) const {
    for( index_set::const_iterator it = init_.literals_.begin(); it != init_.literals_.end(); ++it ) {
        if( *it > 0 )
            state.add(*it-1);
    }
    if( apply_axioms ) state.apply_axioms(*this);
}

void Instance::set_hidden_state(int k, State &state) const {
    set_initial_state(state, false);
    for( index_set::const_iterator it = hidden_[k].literals_.begin(); it != hidden_[k].literals_.end(); ++it ) {
        if( *it > 0 )
            state.add(*it-1);
    }
    // close initial hidden state with axioms. Axioms in k-replanner
    // only appear in translations of multivalued variable problems.
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
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            os << atoms_[idx]->name_;
        else
            os << "(not " << atoms_[idx]->name_ << ")";
    }
    os << '}';
}

void Instance::write_atom_set(ostream &os, const bool *set) const {
    os << '{';
    bool need_comma = false;
    for( size_t k = 0; k < n_atoms(); k++ ) {
        if( set[k] ) {
            if( need_comma ) os << ',';
            os << atoms_[k]->name_;
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
            os << atoms_[k]->name_;
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
        os << actions_[set[k]]->name_;
    }
    os << '}';
}

void Instance::write_action_set(ostream &os, const bool *set) const {
    os << '{';
    bool need_comma = false;
    for( size_t k = 0; k < n_actions(); k++ ) {
        if( set[k] ) {
            if (need_comma) os << ',';
            os << actions_[k]->name_;
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
            os << actions_[k]->name_;
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
    if( name_ ) {
        Name::domain_name_only = true;
        os << "(define (domain " << name_ << ")" << endl;
        Name::domain_name_only = false;
    } else {
        os << "(define (domain NONAME)" << endl;
    }

    // requirements
    if( always_write_requirements_declaration_ ) {
        os << istr << "(:requirements :strips :conditional-effects)" << endl;
    }

    // predicates
    if( n_atoms() > 0 ) {
        os << istr << "(:predicates" << endl;
        for( size_t k = 0; k < n_atoms(); k++ ) {
            os << istr << istr << atoms_[k]->name_ << endl;
        }
        os << istr << ")" << endl;
    }

    // actions
    for( size_t k = 0; k < n_actions(); k++ ) {
        const Action &act = *actions_[k];
        if( act.effect_.size() + act.when_.size() > 0 )
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

    os << ")" << endl;
    delete[] istr;
}

void Instance::write_problem(ostream &os, const State *state, int indent) const {
    // setup indentation string
    char *istr = new char[indent+1];
    for( int i = 0; i < indent; ++i ) istr[i] = ' ';
    istr[indent] = '\0';

    // name of domain
    if( name_ ) {
        Name::problem_name_only = true;
        os << "(define (problem " << name_ << ")" << endl;
        Name::problem_name_only = false;
        Name::domain_name_only = true;
        os << istr << "(:domain " << name_ << ")" << endl;
        Name::domain_name_only = false;
    } else {
        os << "(define (problem NONAME)" << endl;
        os << istr << "(:domain NONAME)" << endl;
    }

    // initial situation
    if( (state == 0) && !init_.literals_.empty() ) {
        os << istr << "(:init";
        for( index_set::const_iterator it = init_.literals_.begin(); it != init_.literals_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << atoms_[idx]->name_;
            else
                os << " (not " << atoms_[idx]->name_ << ")";
        }
        os << ")" << endl;
    } else if( state != 0 ) {
        os << istr << "(:init";
        for( State::const_iterator it = state->begin(); it != state->end(); ++it ) {
            os << " " << atoms_[*it]->name_;
        }
        os << ")" << endl;
    }

    // goal situation
    if( !goal_literals_.empty() ) {
        os << istr << "(:goal";
        if( goal_literals_.size() > 1 ) os << " (and";
        for( index_set::const_iterator it = goal_literals_.begin(); it != goal_literals_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << atoms_[idx]->name_;
            else
                os << " (not " << atoms_[idx]->name_ << ")";
        }
        if( goal_literals_.size() > 1 ) os << ")";
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
    write_atom_set(os, goal_literals_);
    os << endl;
}

void Instance::print_atoms(ostream &os) const {
    for( size_t k = 0; k < n_atoms(); ++k ) {
        os << k << ". " << atoms_[k]->name_ << endl;
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
            if( *it > 0 )
                os << " " << idx << '.' << i.atoms_[idx]->name_;
            else
                os << " -" << idx << '.' << i.atoms_[idx]->name_;
        }
        os << endl;
    }
    if( effect_.size() > 0 ) {
        os << "  eff:";
        for( index_set::const_iterator it = effect_.begin(); it != effect_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << idx << '.' << i.atoms_[idx]->name_;
            else
                os << " -" << idx << '.' << i.atoms_[idx]->name_;
        }
        os << endl;
    }
    if( when_.size() > 0 ) {
        os << "  when:";
        for( when_vec::const_iterator wi = when_.begin(); wi != when_.end(); ++wi ) {
            for( index_set::const_iterator it = wi->condition_.begin(); it != wi->condition_.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 )
                    os << " " << idx << '.' << i.atoms_[idx]->name_;
                else
                    os << " -" << idx << '.' << i.atoms_[idx]->name_;
            }
            os << " ==> :effect";
            for( index_set::const_iterator it = wi->effect_.begin(); it != wi->effect_.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 )
                    os << " " << idx << '.' << i.atoms_[idx]->name_;
                else
                    os << " -" << idx << '.' << i.atoms_[idx]->name_;
            }
            os << endl;
        }
    }
    if( cost_ != 1 ) os << "  cost: " << cost_ << endl;
}

void Instance::Action::write(ostream &os, int indent, const Instance &instance) const {
    // setup indentation string
    char *istr = new char[indent+1];
    for( int i = 0; i < indent; ++i ) istr[i] = ' ';
    istr[indent] = '\0';

    // name and parameters
    os << istr << "(:action " << name_->to_string();
    if( comment_ != "" ) os << "    ; " << comment_;
    os << endl;
    if( always_write_parameters_declaration_ )
        os << istr << istr << ":parameters ()" << endl;

    // precondition
    if( precondition_.size() > 0 ) {
        os << istr << istr << ":precondition";
        if( (precondition_.size() > 1) || always_write_conjunction_ ) os << " (and";
        for( index_set::const_iterator p = precondition_.begin(); p != precondition_.end(); ++p ) {
            int idx = (*p < 0 ? -*p : *p) - 1;
            if( *p < 0  )
                os << " (not " << instance.atoms_[idx]->name_ << ")";
            else
                os << " " << instance.atoms_[idx]->name_;
        }
        if( (precondition_.size() > 1) || always_write_conjunction_ ) os << ")";
        os << endl;
    } else if( always_write_precondition_ ) {
        if( always_write_conjunction_ )
            os << istr << istr << ":precondition (and)" << endl;
        else
            os << istr << istr << ":precondition ()" << endl;
    }

    // effects
    int n_effects = effect_.size() + when_.size();
    if( n_effects > 0 ) {
        os << istr << istr << ":effect";
        if( n_effects > 1 ) os << " (and";

        // add and del effects
        for( index_set::const_iterator p = effect_.begin(); p != effect_.end(); ++p ) {
            int idx = (*p < 0 ? -*p : *p) - 1;
            if( *p > 0 )
                os << " " << instance.atoms_[idx]->name_;
            else
                os << " (not " << instance.atoms_[idx]->name_ << ")";
        }

        // conditional effects
        for( size_t i = 0; i < when_.size(); ++i ) {
            const When &w = when_[i];
            int n_ceffects = w.effect_.size();
            if( n_ceffects > 0 ) {
                assert(!w.condition_.empty());
                if( (i > 0) || (effect_.size() > 0) )
                    os << endl << istr << istr << "            ";
                os << " (when";

                // condition
                if( (w.condition_.size() > 1) || always_write_conjunction_ ) os << " (and";
                for( index_set::const_iterator p = w.condition_.begin(); p != w.condition_.end(); ++p ) {
                    int idx = (*p < 0 ? -*p : *p) - 1;
                    if( *p > 0 )
                        os << " " << instance.atoms_[idx]->name_;
                    else
                        os << " (not " << instance.atoms_[idx]->name_ << ")";
                }
                if( (w.condition_.size() > 1) || always_write_conjunction_ ) os << ")";

                // effects
                if( n_ceffects > 1 ) os << " (and";
                for( index_set::const_iterator p = w.effect_.begin(); p != w.effect_.end(); ++p ) {
                    int idx = (*p < 0 ? -*p : *p) - 1;
                    if( *p > 0 )
                        os << " " << instance.atoms_[idx]->name_;
                    else
                        os << " (not " << instance.atoms_[idx]->name_ << ")";
                }
                if( n_ceffects > 1 ) os << ")";

                os << ")"; // close (when ....)
            }
        }

        if( n_effects > 1 ) os << ")";
    }
    os << ")" << endl;
    delete[] istr;
}

void Instance::Sensor::print(ostream &os, const Instance &i) const {
    os << name_ << ":" << endl;
    if( condition_.size() > 0 ) {
        os << "  condition:";
        for( index_set::const_iterator it = condition_.begin(); it != condition_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << idx << '.' << i.atoms_[idx]->name_;
            else
                os << " -" << idx << '.' << i.atoms_[idx]->name_;
        }
        os << endl;
    }
    assert(!sense_.empty());
    os << "  sense:";
    for( index_set::const_iterator it = sense_.begin(); it != sense_.end(); ++it ) {
        assert(*it >= 0);
        os << " " << *it-1 << '.' << i.atoms_[*it-1]->name_;
    }
    os << endl;
}

void Instance::Sensor::write(ostream &os, int indent, const Instance &instance) const {
    // setup indentation string
    char *istr = new char[indent+1];
    for( int i = 0; i < indent; ++i ) istr[i] = ' ';
    istr[indent] = '\0';

    // name and parameters
    os << istr << "(:sensor " << name_->to_string() << endl;
    if( always_write_parameters_declaration_ )
        os << istr << istr << ":parameters ()" << endl;

    // condition
    if( condition_.size() > 0 ) {
        os << istr << istr << ":condition";
        if( (condition_.size() > 1) || always_write_conjunction_ ) os << " (and";
        for( index_set::const_iterator p = condition_.begin(); p != condition_.end(); ++p ) {
            int idx = (*p < 0 ? -*p : *p) - 1;
            if( *p < 0  )
                os << " (not " << instance.atoms_[idx]->name_ << ")";
            else
                os << " " << instance.atoms_[idx]->name_;
        }
        if( (condition_.size() > 1) || always_write_conjunction_ ) os << ")";
        os << endl;
    } else if( always_write_precondition_ ) {
        if( always_write_conjunction_ )
            os << istr << istr << ":condition (and)" << endl;
        else
            os << istr << istr << ":condition ()" << endl;
    }

    // sense
    assert(!sense_.empty());
    os << istr << istr << ":sense";
    for( index_set::const_iterator it = sense_.begin(); it != sense_.end(); ++it ) {
        assert(*it > 0);
        os << " " << instance.atoms_[*it-1]->name_;
    }
    os << ")" << endl;
    delete[] istr;
}

void Instance::Axiom::print(ostream &os, const Instance &i) const {
    os << name_ << ":" << endl;
    if( body_.size() > 0 ) {
        os << "  body:";
        for( index_set::const_iterator it = body_.begin(); it != body_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                os << " " << idx << '.' << i.atoms_[idx]->name_;
            else
                os << " -" << idx << '.' << i.atoms_[idx]->name_;
        }
        os << endl;
    }
    assert(!head_.empty());
    os << "  head:";
    for( index_set::const_iterator it = head_.begin(); it != head_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            os << " " << idx << '.' << i.atoms_[idx]->name_;
        else
            os << " -" << idx << '.' << i.atoms_[idx]->name_;
    }
    os << endl;
}

void Instance::Axiom::write(ostream &os, int indent, const Instance &instance) const {
    // setup indentation string
    char *istr = new char[indent+1];
    for( int i = 0; i < indent; ++i ) istr[i] = ' ';
    istr[indent] = '\0';

    // name and parameters
    os << istr << "(:axiom " << name_->to_string() << endl;
    if( always_write_parameters_declaration_ )
        os << istr << istr << ":parameters ()" << endl;

    // body
    if( body_.size() > 0 ) {
        os << istr << istr << ":body";
        if( (body_.size() > 1) || always_write_conjunction_ ) os << " (and";
        for( index_set::const_iterator p = body_.begin(); p != body_.end(); ++p ) {
            int idx = (*p < 0 ? -*p : *p) - 1;
            if( *p < 0  )
                os << " (not " << instance.atoms_[idx]->name_ << ")";
            else
                os << " " << instance.atoms_[idx]->name_;
        }
        if( (body_.size() > 1) || always_write_conjunction_ ) os << ")";
        os << endl;
    } else if( always_write_precondition_ ) {
        if( always_write_conjunction_ )
            os << istr << istr << ":body (and)" << endl;
        else
            os << istr << istr << ":body ()" << endl;
    }

    // head
    int n_heads = head_.size();
    if( n_heads > 0 ) {
        os << istr << istr << ":head";
        if( n_heads > 1 ) os << " (and";
        for( index_set::const_iterator p = head_.begin(); p != head_.end(); ++p ) {
            assert(*p > 0);
            os << " " << instance.atoms_[*p-1]->name_;
        }
        if( n_heads > 1 ) os << ")";
    }
    os << ")" << endl;
    delete[] istr;
}

void Instance::Invariant::write(ostream &os, int indent, const Instance &instance) const {
    // setup indentation string
    char *istr = new char[indent+1];
    for( int i = 0; i < indent; ++i ) istr[i] = ' ';
    istr[indent] = '\0';
    os << istr << "(";

    assert((type_ == AT_LEAST_ONE) || (type_ == AT_MOST_ONE));
    if( type_ == AT_LEAST_ONE )
        os << "at-least-one";
    else
        os << "at-most-one";

    if( !Xprecondition_.empty() ) {
        os << " (:precondition";
        for( index_set::const_iterator it = Xprecondition_.begin(); it != Xprecondition_.end(); ++it ) {
            if( *it > 0 )
                os << " " << instance.atoms_[*it-1]->name_;
            else
                os << " (not " << instance.atoms_[-*it-1]->name_ << ")";
        }
        os << ")";
    }

    for( size_t i = 0; i < size(); ++i ) {
        int lit = (*this)[i];
        if( lit > 0 )
            os << " " << instance.atoms_[lit-1]->name_;
        else
            os << " (not " << instance.atoms_[-lit-1]->name_ << ")";
    }
    os << ")" << endl;
    delete[] istr;
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
            Action &act = *actions_[k];
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
        if( i == (int)init_.oneofs_.size() ) {
            if( t.satisfy(init_.clauses_) ) {
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
        if( j == (int)init_.oneofs_[i].size() ) {
            if( i == 0 ) break;
            int l = restore.back(), p = l < 0 ? -l : l;
            j = stack.back();
            if( l != INT_MAX ) t.apply(p-1, p!=l);
            restore.pop_back();
            stack.pop_back();
            --i;
            continue;
        }
        int l = init_.oneofs_[i][j], p = l < 0? -l : l;
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
    for( invariant_vec::const_iterator it = init_.invariants_.begin(); it != init_.invariants_.end(); ++it ) {
        const Invariant &invariant = *it;
        assert(invariant.type_ == Invariant::AT_LEAST_ONE);

        for( size_t k = 0; k < invariant.size(); ++k ) {
            string name = string("deductive-rule-") + Utils::to_string(deductive_rules_.size());
            Action *rule = new Action(new CopyName(name), deductive_rules_.size());

            // conditional effects
            When c_eff;
            if( invariant.type_ == Invariant::AT_LEAST_ONE ) {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    if( i != k ) {
                        c_eff.condition_.insert(-lit);
                        if( c_eff.effect_.contains(-lit) )
                           c_eff.effect_.clear();
                    } else {
                        if( !c_eff.condition_.contains(lit) )
                            c_eff.effect_.insert(lit);
                    }
                }
            } else {
                // This should be dead code.
                assert(invariant.type_ == Invariant::AT_MOST_ONE);
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    if( i == k ) {
                        c_eff.condition_.insert(lit);
                    } else {
                        c_eff.effect_.insert(-lit);
                    }
                }
            }

            // push conditional effect
            if( !c_eff.effect_.empty() ) {
                rule->when_.push_back(c_eff);
                deductive_rules_.push_back(rule);
                if( options_.is_enabled("problem:print:deductive-rule:creation") ) {
                    rule->print(cout, *this);
                }
            } else {
                delete rule;
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

