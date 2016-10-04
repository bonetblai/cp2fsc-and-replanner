#include <cassert>
#include <cstdlib>
#include "kp_problem.h"
#include "state.h"
#include "utils.h"

using namespace std;

static int get_atom_index(const Instance &ins, string atom_name) {
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        if( atom_name == ins.atoms_[k]->name_->to_string() )
            return k;
    }
    return -1;
}

KP_Instance::KP_Instance(const Options::Mode &options)
  : Instance(options), new_goal_(0), inference_time_(0)  {
}

void KP_Instance::write_problem(ostream &os, const State *state, int indent) const {
    index_vec subgoaling_enablers;
    if( options_.is_enabled("kp:subgoaling") ) {
        enable_subgoaling_actions(*const_cast<State*>(state), subgoaling_enablers);
    }
    Instance::write_problem(os, state, indent);
    if( options_.is_enabled("kp:subgoaling") ) {
        disable_subgoaling_actions(*const_cast<State*>(state), subgoaling_enablers);
    }
}

void KP_Instance::merge_drules() {
    multiset<DRTemplate, DRTemplate>::key_compare comparator = drule_store_.key_comp();
    for( multiset<DRTemplate, DRTemplate>::const_iterator it = drule_store_.begin(); it != drule_store_.end(); ) {
        //string type = it->first.second;
        const DRTemplate &record = *it;
        const Action &drule = *it->action_;
        Action &nact = new_action(new CopyName(drule.name_->to_string()));
        nact.precondition_ = drule.precondition_;
        nact.effect_ = drule.effect_;
        nact.when_ = drule.when_;
        nact.cost_ = drule.cost_;
        nact.comment_ = drule.comment_;
        if( ++it == drule_store_.end() ) {
            if( options_.is_enabled("kp:print:action:drule:sensing") || options_.is_enabled("kp:print:action:drule") )
                nact.print(cout, *this);
            break;
        }

        if( options_.is_enabled("kp:merge-drules") ) {
            while( !comparator(record, *it) ) {
                assert(it != drule_store_.end());
                nact.comment_ = "<merge>";
                delete it->action_;
                if( ++it == drule_store_.end() ) break;
            }
        }

        delete record.action_;
        if( options_.is_enabled("kp:print:action:drule:sensing") || options_.is_enabled("kp:print:action:drule") )
            nact.print(cout, *this);
    }
    drule_store_.clear();
}

void KP_Instance::create_subgoaling_actions(const Instance &ins) {
    // create (new-goal) atom
    new_goal_ = &new_atom(new CopyName("new-goal"));
    goal_literals_.insert(1 + new_goal_->index_);

    // create subgoaling action for original goal
    Action &goal_action = new_action(new CopyName("subgoaling_action_for_original_goal__"));
    for( index_set::const_iterator it = ins.goal_literals_.begin(); it != ins.goal_literals_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            goal_action.precondition_.insert(1 + 2*idx);
        else
            goal_action.precondition_.insert(1 + 2*idx+1);
    }
    goal_action.effect_.insert(1 + new_goal_->index_);
    if( options_.is_enabled("kp:print:action:subgoaling") ) {
        goal_action.print(cout, *this);
    }

    if( options_.is_enabled("kp:subgoaling") ) {
        cout << Utils::magenta()
             << "(kp) creating actions for subgoaling"
             << Utils::normal()
             << endl;
    }

    if( options_.is_enabled("kp:subgoaling:non-reversable-goal-atoms") ) {
        cout << Utils::magenta()
             << "(kp) creating actions for subgoaling:non-reversable-goal-atoms"
             << Utils::normal()
             << endl;
        // Every positive goal atom that once achieved cannot be undone is a potential
        // candidate for new goal. Question is whether such atoms can be serialized in
        // any order. In subgoaling for non-reversable goal atoms, we assume it.
        index_set non_reversable_goal_atoms;
        for( index_set::const_iterator it = ins.goal_literals_.begin(); it != ins.goal_literals_.end(); ++it ) {
            if( *it > 0 ) {
                bool reversable = false;
                for( size_t k = 0; k < ins.n_actions(); ++k ) {
                    const Action &act = *ins.actions_[k];
                    if( act.effect_.contains(-*it) ) {
                        reversable = true;
                        break;
                    }
                }
                if( !reversable ) non_reversable_goal_atoms.insert(*it - 1);
            }
        }
        cout << Utils::magenta()
             << "(kp) non-reversable goal atoms: "
             << Utils::normal();
        ins.write_atom_set(cout, non_reversable_goal_atoms);
        cout << endl;

        if( !non_reversable_goal_atoms.empty() ) {
            for( index_set::const_iterator it = non_reversable_goal_atoms.begin(); it != non_reversable_goal_atoms.end(); ++it ) {
                //cout << "ATOM: index=" << *it << ", name="; State::print_literal(cout, 1 + *it, &ins); cout << endl;
                string action_name = string("subgoaling_action_for_") + Utils::replace_all(Utils::replace_all(State::to_string(1 + *it, &ins), "(", ""), ")", "");
                string enabler_name = string("enable_") + action_name;
                Atom *enabler = &new_atom(new CopyName(enabler_name));
                //cout << Utils::red() << "action-enabler=" << Utils::normal(); State::print_literal(cout, 1 + enabler->index_, this); cout << endl;
                Action &goal_action = new_action(new CopyName(action_name));
                goal_action.precondition_.insert(1 + enabler->index_);
                goal_action.precondition_.insert(1 + 2 * (*it));
                goal_action.effect_.insert(1 + new_goal_->index_);
                enablers_for_non_reversable_goal_atoms_.push_back(make_pair(2 * (*it), enabler->index_));
                if( options_.is_enabled("kp:print:action:subgoaling") ) {
                    goal_action.print(cout, *this);
                }
            }
        }
    }

    if( options_.is_enabled("kp:subgoaling:static-unknowns") ) {
        cout << Utils::error() << "(kp) subgoaling for static unknowns is not yet supported." << endl;
        exit(-1);

        // With these subgoals we make sure that the computed plans achieve new knowledge.
        // We can't guarantee that the knowledge is useful for achieving the goal, but
        // there is monotone information gain

#if 0
        // Other actions are for observable literals that are unknown at initial state
        atoms_for_unknown_observables_at_init_ = vector<Atom*>(ins.n_atoms());
        for( size_t k = 0; k < ins.n_sensors(); ++k ) {
            const Sensor &r = *ins.sensors_[k];
            assert(!r.sense_.empty());

            for( index_set::const_iterator it = r.sense_.begin(); it != r.sense_.end(); ++it ) {
                assert(*it > 0);
                int idx = *it - 1;
                if( atoms_for_unknown_observables_at_init_[idx] == 0 ) {
                    string atom_name("(unknown_");
                    atom_name += ins.atoms_[idx]->name_->to_string() + ")";
                    cout << "ATOM-NAME: " << atom_name << endl;
                    atoms_for_unknown_observables_at_init_[idx] = &new_atom(new CopyName(atom_name));
                    for( int n = 0; n < 2; ++n ) {
                        string action_name("reach_goal_through_knowledge_of_");
                        action_name += ins.atoms_[idx]->name_->to_string() + "_" + (n == 0 ? "0__" : "1__");
                        Action &nact = new_action(new CopyName(action_name));
                        nact.precondition_.insert(1 + atoms_for_unknown_observables_at_init_[idx]->index_);
                        nact.precondition_.insert(1 + 2*idx+n);
                        nact.effect_.insert(1 + new_goal_->index_);
                        cout << nact.index_ << "."; nact.print(cout, *this);
                    }
                }
            }
        }
#endif
    }
}

void KP_Instance::enable_subgoaling_actions(State &state, index_vec &enablers) const {
    enablers.clear();
    if( options_.is_enabled("kp:subgoaling:non-reversable-goal-atoms") ) {
        for( size_t k = 0; k < enablers_for_non_reversable_goal_atoms_.size(); ++k ) {
            const pair<int, int> &enabler = enablers_for_non_reversable_goal_atoms_[k];
            if( !state.satisfy(enabler.first) ) {
                assert(!state.satisfy(enabler.second));
                enablers.push_back(enabler.second);
                state.add(enabler.second);
            }
        }
    }
    if( options_.is_enabled("kp:subgoaling:static-unknowns") ) {
        cout << Utils::error() << "(kp) subgoaling for static unknowns is not yet supported." << endl;
        exit(-1);
    }
}

void KP_Instance::disable_subgoaling_actions(State &state, const index_vec &enablers) const {
    if( options_.is_enabled("kp:subgoaling:non-reversable-goal-atoms") ) {
        for( size_t k = 0; k < enablers.size(); ++k ) {
            assert(state.satisfy(enablers[k]));
            state.remove(enablers[k]);
        }
    }
    if( options_.is_enabled("kp:subgoaling:static-unknowns") ) {
        cout << Utils::error() << "(kp) subgoaling for static unknowns is not yet supported." << endl;
        exit(-1);
    }
}

// Calculate the assumptions made along a plan from initial to goal state.
// Basically, for a given plan pi=(a0, a1, ..., an), let's define:
//
//     R(pi, -1) = s0
//      R(pi, k) = progress(s0, pi[0:k])
//      A(pi, k) = regress(pi[k], R(pi, k-1), R(pi, k))
//
// where s0 is initial state, progress(s, pi) is the state that results of
// applying the (applicable) plan pi on state s, and regress(a, s, s') is the
// minimum set of assumptions needed for the action a, which is applicable
// at state s, to produce state s'.
//
// CHECK IMPLEMENTATION BELOW (calculation of assumptions)

bool KP_Instance::calculate_relevant_assumptions(const Plan &plan,
                                                 const State &initial_state,
                                                 const index_set &goal,
                                                 vector<index_set> &assumptions) const {
    assert(!plan.empty());
    //cout << Utils::magenta() << "Calculate relevant assumptions:" << endl;

    // calculate trajectory of states generated by plan
    //cout << Utils::magenta() << "  Progression:" << endl;
    State current_state;
    vector<State> trajectory;
    trajectory.reserve(plan.size());
    current_state = initial_state;
    for( size_t k = 0; k < plan.size(); ++k ) {
        //cout << Utils::red() << "    state=" << Utils::normal();
        //current_state.print(cout, *this);
        //cout << endl;

        trajectory.push_back(current_state);
        const Action &action = *actions_[plan[k]];
        //cout << Utils::yellow() << "    " << action.name_ << Utils::normal() << endl;
        assert(current_state.applicable(action));
        current_state.apply(action);
        //if( current_state == trajectory.back() ) cout << Utils::yellow() << "  Action " << action.name_ << " is useless!" << endl;
    }
    trajectory.push_back(current_state);

    // backchain from goal to identify relevant assumptions in plan
    //cout << Utils::magenta() << "  Back-chaining:" << endl;
    int plan_size = plan.size();
    vector<index_set> condition_vec;         // stores computed assumptions in reverse order
    condition_vec.reserve(plan_size);
    index_set open(goal);                    // signed set of current open conditions
    for( int k = plan_size - 1; k >= 0; --k ) {
        const Action &action = *actions_[plan[k]];

        //string mode = k % 2 == 0 ? Utils::red() : Utils::cyan();
        //cout << mode;
        //cout << "    open="; write_atom_set(cout, open); cout << endl;
        //cout << "    action=" << Utils::yellow() << action.name_ << mode << " is applied at state=" << Utils::normal();
        //trajectory[k].print(cout, *this);
        //cout << endl;
        //for( index_set::const_iterator it = open.begin(); it != open.end(); ++it ) cout << *it << " "; cout << endl;

        // sets of literals to update set of open conditions
        index_set to_be_added, to_be_removed;

        // if action removes an open condition, the removal has to be conditional
        // (otherwise the plan cannot be valid). Thus, add the negated condition
        // to open conditions.
        for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
            if( (*it < 0) && (open.find(-*it) != open.end()) ) {
                cout << Utils::error() << "plan removes the open condition: ";
                State::print_literal(cout, *it, this);
                cout << endl;
                return false;
            }
        }

        for( size_t i = 0; i < action.when_.size(); ++i ) {
            const When &when = action.when_[i];
            for( index_set::const_iterator it = when.effect_.begin(); it != when.effect_.end(); ++it ) {
                if( (*it < 0) && (open.find(-*it) != open.end()) ) {
                    if( when.condition_.size() > 1 ) {
                        cout << Utils::warning()
                             << "conditional effect with more than one literal in condition removes open condition ";
                        State::print_literal(std::cout, *it, this);
                        cout << "." << endl
                             << "Regression may be too strong. Consider removing conditional effect by enlarging precondition."
                             << endl;
                    }
                    for( index_set::const_iterator jt = when.condition_.begin(); jt != when.condition_.end(); ++jt )
                        to_be_added.insert(*jt > 0 ? (*jt % 2 == 0 ? *jt + 1 : *jt - 1) : -*jt);
                }
            }
        }

        // if action achieves any open condition, update set of achieved conditions
        // and update set of conditions to add to open
        for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
            if( (*it > 0) && (open.find(*it) != open.end()) ) {
                to_be_added.insert(action.precondition_.begin(), action.precondition_.end());
                to_be_removed.insert(*it);
            }
        }

        for( size_t i = 0; i < action.when_.size(); ++i ) {
            const When &when = action.when_[i];
            for( index_set::const_iterator it = when.effect_.begin(); it != when.effect_.end(); ++it ) {
                if( trajectory[k].satisfy(when.condition_) && (*it > 0) && (open.find(*it) != open.end()) ) {
                    to_be_added.insert(action.precondition_.begin(), action.precondition_.end());
                    to_be_added.insert(when.condition_.begin(), when.condition_.end());
                    to_be_removed.insert(*it);
                }
            }
        }

        // remove negative literals for condition
        for( index_set::iterator it = to_be_added.begin(); it != to_be_added.end(); ) {
            if( *it < 0 ) {
                int literal = *it++;
                to_be_added.erase(literal);
            } else {
                ++it;
            }
        }
        condition_vec.push_back(to_be_added);
        //cout << Utils::magenta();
        //cout << "    action " << action.name_ << endl;
        //cout << Utils::green();
        //cout << "        to_be_removed="; write_atom_set(cout, to_be_removed); cout << endl;
        //cout << "        to_be_added="; write_atom_set(cout, to_be_added); cout << endl;
        //cout << Utils::normal();

        // update set of open conditions
        for( index_set::const_iterator it = to_be_removed.begin(); it != to_be_removed.end(); ++it )
            open.erase(*it);
        open.insert(to_be_added.begin(), to_be_added.end());
    }
    //cout << Utils::normal();
    //cout << "open="; write_atom_set(cout, open); cout << endl;

    // at the end, the open conditions should be met by initial state
    for( State::const_iterator it = initial_state.begin(); it != initial_state.end(); ++it ) {
        assert(*it >= 0);
        open.erase(1 + *it);
    }
    //cout << "after erasing init: open="; write_atom_set(cout, open); cout << endl;
    assert(open.empty());

    // assumptions is reversed vector of conditions
    assumptions.clear();
    assumptions.reserve(condition_vec.size());
    assumptions.insert(assumptions.end(), condition_vec.rbegin(), condition_vec.rend());
    return true;
}

Standard_KP_Instance::Standard_KP_Instance(const Instance &ins, const PDDL_Base::variable_vec &variables)
  : KP_Instance(ins.options_),
    n_standard_actions_(0),
    n_sensor_actions_(0),
    n_invariant_actions_(0),
    n_subgoaling_actions_(0),
    po_instance_(ins) {

    cout << Utils::internal_error() << "ctor for Standard_KP_Instance shouldn't be called" << endl;
    exit(-1);

    // set name
    if( dynamic_cast<const InstanceName*>(ins.name_) != 0 ) {
        set_name(new InstanceName(*dynamic_cast<const InstanceName*>(ins.name_)));
    } else {
        set_name(new CopyName(ins.name_->to_string()));
    }

    // create K0 atoms
    atoms_.reserve(2*ins.n_atoms());
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        string name = ins.atoms_[k]->name_->to_string();
        new_atom(new CopyName("(K_" + name + ")"));      // even-numbered atoms
        new_atom(new CopyName("(K_not_" + name + ")"));  // odd-numbered atoms
    }

    // prepare data for handling problems with variables
    set<int> observable_atoms;
    map<int, set<int> > beams_for_observable_atoms;
    vector<set<int > > state_variables;
    for( size_t k = 0; k < variables.size(); ++k ) {
        const PDDL_Base::Variable &var = *variables[k];
        if( var.is_observable_variable() ) {
            for( PDDL_Base::unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it ) {
                string atom_name = it->to_string(false, true);
                int atom_index = get_atom_index(ins, atom_name);
                //cout << "obs-variable: atom=" << *it << ", name=" << atom_name << ", index=" << atom_index << endl;
                assert(atom_index != -1);
                observable_atoms.insert(atom_index);
                set<int> beam;
                const PDDL_Base::unsigned_atom_set &var_beam = var.beam_.at(*it);
                for( PDDL_Base::unsigned_atom_set::const_iterator jt = var_beam.begin(); jt != var_beam.end(); ++jt ) {
                    int index = get_atom_index(ins, jt->to_string(false, true));
                    if( index != -1 ) beam.insert(index);
                }
                beams_for_observable_atoms[atom_index] = beam;
            }
        } else{
            set<int> values;
            for( PDDL_Base::unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it ) {
                string atom_name = it->to_string(false, true);
                int atom_index = get_atom_index(ins, atom_name);
                //cout << "state-variable: atom=" << *it << ", name=" << atom_name << ", index=" << atom_index << endl;
                if( atom_index == -1 ) cout << atom_name << endl;
                assert(atom_index != -1);
                values.insert(atom_index);
            }
            state_variables.push_back(values);
        }
    }

    // set initial atoms
    for( index_set::const_iterator it = ins.init_.literals_.begin(); it != ins.init_.literals_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            init_.literals_.insert(1 + 2*idx);
        else
            init_.literals_.insert(1 + 2*idx+1);
    }

    // add known literals in initial situation
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        const Atom &atom = *ins.atoms_[k];
        if( (init_.literals_.find(1 + 2*k) == init_.literals_.end()) &&
            (init_.literals_.find(1 + 2*k+1) == init_.literals_.end()) ) {
            // check that atom does not appear in invariants
            bool in_invariant = false;
            for( size_t i = 0; !in_invariant && (i < ins.init_.invariants_.size()); ++i ) {
                for( size_t j = 0; j < ins.init_.invariants_[i].size(); ++j ) {
                    int lit = ins.init_.invariants_[i][j];
                    if( (lit > 0) && ((int)atom.index_ == lit-1) ) {
                        in_invariant = true;
                        break;
                    }
                }
            }

            // if not in some invariant, add K_not_<atom> to init
            if( !in_invariant ) {
                init_.literals_.insert(1 + 2*k+1);
                if( options_.is_enabled("kp:print:atom:init") ) {
                    cout << "Atom " << atoms_[2*k+1]->name_ << " added to init" << endl;
                }
            }
        }
    }

    // create K-actions
    remap_ = vector<int>(ins.n_actions(),-1);
    for( size_t k = 0; k < ins.n_actions(); ++k ) {
        const Action &act = *ins.actions_[k];
        Action &nact = new_action(new CopyName(act.name_->to_string()));
        remap_[k] = k;

        // preconditions
        for( index_set::const_iterator it = act.precondition_.begin(); it != act.precondition_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                nact.precondition_.insert(1 + 2*idx);
            else
                nact.precondition_.insert(1 + 2*idx+1);
        }

        // support rules for unconditional effects (no cancellation rules for unconditial effects)
        for( index_set::const_iterator it = act.effect_.begin(); it != act.effect_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 ) {
                nact.effect_.insert(1 + 2*idx);
                nact.effect_.insert(-(1 + 2*idx+1));
            } else {
                nact.effect_.insert(1 + 2*idx+1);
                nact.effect_.insert(-(1 + 2*idx));
            }
        }

        // support and cancellation rules for conditional effects
        for( size_t i = 0; i < act.when_.size(); ++i ) {
            const When &when = act.when_[i];
            When sup_eff, can_eff;
            for( index_set::const_iterator it = when.condition_.begin(); it != when.condition_.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 ) {
                    sup_eff.condition_.insert(1 + 2*idx);
                    can_eff.condition_.insert(-(1 + 2*idx+1));
                } else {
                    sup_eff.condition_.insert(1 + 2*idx+1);
                    can_eff.condition_.insert(-(1 + 2*idx));
                }
            }
            for( index_set::const_iterator it = when.effect_.begin(); it != when.effect_.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 ) {
                    sup_eff.effect_.insert(1 + 2*idx);
                    if( observable_atoms.find(idx) == observable_atoms.end() )
                        can_eff.effect_.insert(-(1 + 2*idx+1));
                } else {
                    sup_eff.effect_.insert(1 + 2*idx+1);
                    if( observable_atoms.find(idx) == observable_atoms.end() )
                        can_eff.effect_.insert(-(1 + 2*idx));
                }
            }
            nact.when_.push_back(sup_eff);
            if( !can_eff.effect_.empty() ) nact.when_.push_back(can_eff);
        }

        if( options_.is_enabled("kp:print:action:regular") ) {
            nact.print(cout, *this);
        }
    }
    n_standard_actions_ = n_actions();

    // create sensor rules
    for( size_t k = 0; k < ins.n_sensors(); ++k ) {
        const Sensor &r = *ins.sensors_[k];
        assert(!r.sense_.empty());

        // create common condition
        index_set common_condition;
        for( index_set::const_iterator it = r.condition_.begin(); it != r.condition_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                common_condition.insert(1 + 2*idx);
            else
                common_condition.insert(1 + 2*idx+1);
        }

        // generate different rule for every sensed fluent
        int obs = 0;
        for( index_set::const_iterator it = r.sense_.begin(); it != r.sense_.end(); ++it ) {
            assert(*it > 0);
            int idx = *it-1;
            for( size_t n = 0; n < 2; ++n ) {
                string name = string("sensor-") + r.name_->to_string() + "-obs" + Utils::to_string(obs) + "-ver" + Utils::to_string(n);
                Action &nact = new_action(new CopyName(name));

                // conditional effect
                When c_eff;
                c_eff.condition_.insert(common_condition.begin(), common_condition.end());
                c_eff.condition_.insert(-(1 + 2*idx));
                c_eff.condition_.insert(-(1 + 2*idx+1));
                if( n == 0 ) {
                    c_eff.effect_.insert(1 + 2*idx);
                } else {
                    c_eff.effect_.insert(1 + 2*idx+1);
                }

                // add conditional effect to rule
                //obs_rules_by_name_[nact.name_->to_string()] = n_actions();
                nact.when_.push_back(c_eff);
                if( options_.is_enabled("kp:print:action:sensor") )
                    nact.print(cout, *this);
            }
            ++obs;
        }
    }
    n_sensor_actions_ = n_actions() - n_standard_actions_;

    // create invariant rules
    size_t invariant_no = 0;
    multimap<index_set, const Action*> invariant_actions;
    for( invariant_vec::const_iterator it = ins.init_.invariants_.begin(); it != ins.init_.invariants_.end(); ++it ) {
        const Invariant &invariant = *it;
        assert((invariant.type_ == Invariant::AT_LEAST_ONE) || (invariant.type_ == Invariant::AT_MOST_ONE));

        // if trivial invariant, skip it
        if( (invariant.size() == 2) && (invariant[0] == -invariant[1]) ) continue;

        //cout << "Processing invariant "; invariant.write(cout, 0, ins);
        for( size_t k = 0; k < invariant.size(); ++k ) {
            string name = string("invariant-") + (invariant.type_ == Invariant::AT_LEAST_ONE ? "at-least-one" : "at-most-one") + "-" + Utils::to_string(invariant_no++);
            Action *nact = new Action(new CopyName(name));
            vector<int> completion;

            // setup precondition
            assert(invariant.Xprecondition_.empty());
            for( index_set::const_iterator it = invariant.Xprecondition_.begin(); it != invariant.Xprecondition_.end(); ++it ) {
                int lit = *it;
                int idx = lit > 0 ? lit-1 : -lit-1;
                if( lit > 0 )
                    nact->precondition_.insert(1 + 2*idx);
                else
                    nact->precondition_.insert(1 + 2*idx+1);
            }

            // effects
            string comment_body, comment_head;
            if( invariant.type_ == Invariant::AT_LEAST_ONE ) {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k ) {
                            nact->precondition_.insert(1 + 2*idx+1);
                            comment_body += atoms_[2*idx+1]->name_->to_string() + " ";
                        } else {
                            nact->precondition_.insert(-(1 + 2*idx+1));
                            nact->effect_.insert(1 + 2*idx);
                        }
                    } else {
                        if( i != k ) {
                            nact->precondition_.insert(1 + 2*idx);
                            comment_body += atoms_[2*idx]->name_->to_string() + " ";
                        } else {
                            nact->precondition_.insert(-(1 + 2*idx));
                            nact->effect_.insert(1 + 2*idx+1);
                        }
                    }
                }
            } else {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k ) {
                            nact->effect_.insert(1 + 2*idx+1);
                            comment_head += atoms_[2*idx+1]->name_->to_string() + " ";
                        } else {
                            nact->precondition_.insert(1 + 2*idx);
                            comment_body += atoms_[2*idx]->name_->to_string();
                        }
                    } else {
                        if( i != k ) {
                            nact->effect_.insert(1 + 2*idx);
                            comment_head += atoms_[2*idx]->name_->to_string() + " ";
                        } else {
                            nact->precondition_.insert(1 + 2*idx+1);
                            comment_body += atoms_[2*idx+1]->name_->to_string();
                        }
                    }
                }
            }

            // set comment
            nact->comment_ = comment_body + " ==> " + comment_head;

            // store invariant action
            invariant_actions.insert(make_pair(nact->precondition_, nact));
        }
    }

    // insert invariant rules into instance (merging similar actions if option is enabled)
    multimap<index_set, const Action*>::key_compare comparator = invariant_actions.key_comp();
    for( multimap<index_set, const Action*>::const_iterator it = invariant_actions.begin(); it != invariant_actions.end(); ) {
        const Action &invariant = *it->second;
        Action &nact = new_action(new CopyName(invariant.name_->to_string()));
        nact.precondition_ = invariant.precondition_;
        nact.effect_ = invariant.effect_;
        nact.when_ = invariant.when_;
        nact.cost_ = invariant.cost_;
        nact.comment_ = invariant.comment_;
        delete it->second;
        if( ++it == invariant_actions.end() ) break;

        if( options_.is_enabled("kp:merge-invariants") ) {
            if( !comparator(nact.precondition_, it->first) ) nact.comment_ = "<omitted>";
            set<When> included_when_effects;
            included_when_effects.insert(nact.when_.begin(), nact.when_.end());
            while( !comparator(nact.precondition_, it->first) ) {
                assert(it != invariant_actions.end());
                nact.effect_.insert(it->second->effect_.begin(), it->second->effect_.end());
                nact.when_.insert(nact.when_.end(), it->second->when_.begin(), it->second->when_.end());
#if 0
                for( when_vec::const_iterator jt = it->second->when_.begin(); jt != it->second->when_.end(); ++jt ) {
                    if( included_when_effects.find(*jt) == included_when_effects.end() ) {
                        included_when_effects.insert(*jt);
                        nact.when_.push_back(*jt);
                    }
                }
#endif
                delete it->second;
                if( ++it == invariant_actions.end() ) break;
            }
        }

        if( options_.is_enabled("kp:print:action:invariant") ) {
            nact.print(cout, *this);
        }
    }

#if 0
    // create invariant rules
    //size_t invariant_no = 0;
    for( invariant_vec::const_iterator it = ins.init_.invariants_.begin(); it != ins.init_.invariants_.end(); ++it ) {
        const Invariant &invariant = *it;
        assert((invariant.type_ == Invariant::AT_LEAST_ONE) || (invariant.type_ == Invariant::AT_MOST_ONE));

        // if trivial invariant, skip it
        if( (invariant.size() == 2) && (invariant[0] == -invariant[1]) ) continue;

        //cout << "Processing invariant "; invariant.write(cout, 0, ins);
        for( size_t k = 0; k < invariant.size(); ++k ) {
            string name = string("invariant-") + (invariant.type_ == Invariant::AT_LEAST_ONE ? "at-least-one" : "at-most-one") + "-" + Utils::to_string(invariant_no++);
            Action &nact = new_action(new CopyName(name));
            vector<int> completion;

            // setup precondition
            assert(invariant.Xprecondition_.empty());
            for( index_set::const_iterator it = invariant.Xprecondition_.begin(); it != invariant.Xprecondition_.end(); ++it ) {
                int lit = *it;
                int idx = lit > 0 ? lit-1 : -lit-1;
                if( lit > 0 )
                    nact.precondition_.insert(1 + 2*idx);
                else
                    nact.precondition_.insert(1 + 2*idx+1);
            }

            // effects
            string comment_body, comment_head;
            if( invariant.type_ == Invariant::AT_LEAST_ONE ) {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k ) {
                            nact.precondition_.insert(1 + 2*idx+1);
                            comment_body += atoms_[2*idx+1]->name_->to_string() + " ";
                        } else {
                            nact.precondition_.insert(-(1 + 2*idx+1));
                            nact.effect_.insert(1 + 2*idx);
                            comment_head += atoms_[2*idx]->name_->to_string();
                        }
                    } else {
                        if( i != k ) {
                            nact.precondition_.insert(1 + 2*idx);
                            comment_body += atoms_[2*idx]->name_->to_string() + " ";
                        } else {
                            nact.precondition_.insert(-(1 + 2*idx));
                            nact.effect_.insert(1 + 2*idx+1);
                            comment_head += atoms_[2*idx+1]->name_->to_string();
                        }
                    }
                }
            } else {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k ) {
                            nact.effect_.insert(1 + 2*idx+1);
                            comment_head += atoms_[2*idx+1]->name_->to_string() + " ";
                        } else {
                            nact.precondition_.insert(1 + 2*idx);
                            comment_body += atoms_[2*idx]->name_->to_string();
                        }
                    } else {
                        if( i != k ) {
                            nact.effect_.insert(1 + 2*idx);
                            comment_head += atoms_[2*idx]->name_->to_string() + " ";
                        } else {
                            nact.precondition_.insert(1 + 2*idx+1);
                            comment_body += atoms_[2*idx+1]->name_->to_string();
                        }
                    }
                }
            }

            // set comment
            nact.comment_ = comment_body + " ==> " + comment_head;

            // perform effect completion (if enabled)
            if( do_effect_completion ) {
                for( size_t i = 0; i < completion.size(); ++i ) {
                    int klit = 1 + 2*completion[i] + 1;
                    if( nact.precondition_.find(klit) == nact.precondition_.end() )
                        nact.effect_.insert(klit);
                }
            }

            if( options_.is_enabled("kp:print:action:invariant") ) {
                nact.print(cout, *this);
            }
        }
    }
#endif
    n_invariant_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_;

    // do subgoaling
    create_subgoaling_actions(ins);
    n_subgoaling_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_ - n_invariant_actions_;
}


Standard_KP_Instance::Standard_KP_Instance(const Instance &ins)
  : KP_Instance(ins.options_), po_instance_(ins) {

    // set name
    if( dynamic_cast<const InstanceName*>(ins.name_) != 0 ) {
        set_name(new InstanceName(*dynamic_cast<const InstanceName*>(ins.name_)));
    } else {
        set_name(new CopyName(ins.name_->to_string()));
    }

    // create K0 atoms
    atoms_.reserve(2*ins.n_atoms());
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        string name = ins.atoms_[k]->name_->to_string();
        new_atom(new CopyName("(K_" + name + ")"));      // even-numbered atoms
        new_atom(new CopyName("(K_not_" + name + ")"));  // odd-numbered atoms
    }

    // set initial atoms
    for( index_set::const_iterator it = ins.init_.literals_.begin(); it != ins.init_.literals_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            init_.literals_.insert(1 + 2*idx);
        else
            init_.literals_.insert(1 + 2*idx+1);
    }

    // add known literals in initial situation
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        const Atom &atom = *ins.atoms_[k];
        if( (init_.literals_.find(1 + 2*k) == init_.literals_.end()) &&
            (init_.literals_.find(1 + 2*k+1) == init_.literals_.end()) ) {
            // check that atom does not appear in invariants
            bool in_invariant = false;
            for( size_t i = 0; !in_invariant && (i < ins.init_.invariants_.size()); ++i ) {
                for( size_t j = 0; j < ins.init_.invariants_[i].size(); ++j ) {
                    int lit = ins.init_.invariants_[i][j];
                    if( (lit > 0) && ((int)atom.index_ == lit-1) ) {
                        in_invariant = true;
                        break;
                    }
                }
            }

            // if not in some invariant, add K_not_<atom> to init
            if( !in_invariant ) {
                init_.literals_.insert(1 + 2*k+1);
                if( options_.is_enabled("kp:print:atom:init") ) {
                    cout << "Atom " << atoms_[2*k+1]->name_ << " added to init" << endl;
                }
            }
        }
    }

    // create K-actions
    remap_ = vector<int>(ins.n_actions(),-1);
    for( size_t k = 0; k < ins.n_actions(); ++k ) {
        const Action &act = *ins.actions_[k];
        Action &nact = new_action(new CopyName(act.name_->to_string()));
        remap_[k] = k;

        // preconditions
        for( index_set::const_iterator it = act.precondition_.begin(); it != act.precondition_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                nact.precondition_.insert(1 + 2*idx);
            else
                nact.precondition_.insert(1 + 2*idx+1);
        }

        // support rules for unconditional effects (no cancellation rules for unconditial effects)
        for( index_set::const_iterator it = act.effect_.begin(); it != act.effect_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 ) {
                nact.effect_.insert(1 + 2*idx);
                nact.effect_.insert(-(1 + 2*idx+1));
            } else {
                nact.effect_.insert(1 + 2*idx+1);
                nact.effect_.insert(-(1 + 2*idx));
            }
        }

        // support and cancellation rules for conditional effects
        for( size_t i = 0; i < act.when_.size(); ++i ) {
            const When &when = act.when_[i];
            When sup_eff, can_eff;
            for( index_set::const_iterator it = when.condition_.begin(); it != when.condition_.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 ) {
                    sup_eff.condition_.insert(1 + 2*idx);
                    can_eff.condition_.insert(-(1 + 2*idx+1));
                } else {
                    sup_eff.condition_.insert(1 + 2*idx+1);
                    can_eff.condition_.insert(-(1 + 2*idx));
                }
            }
            for( index_set::const_iterator it = when.effect_.begin(); it != when.effect_.end(); ++it ) {
                int idx = *it > 0 ? *it-1 : -*it-1;
                if( *it > 0 ) {
                    sup_eff.effect_.insert(1 + 2*idx);
                    can_eff.effect_.insert(-(1 + 2*idx+1));
                } else {
                    sup_eff.effect_.insert(1 + 2*idx+1);
                    can_eff.effect_.insert(-(1 + 2*idx));
                }
            }
            nact.when_.push_back(sup_eff);
            if( !can_eff.effect_.empty() ) nact.when_.push_back(can_eff);
        }

        if( options_.is_enabled("kp:print:action:regular") ) {
            nact.print(cout, *this);
        }
    }
    n_standard_actions_ = n_actions();

    // create sensor rules
    for( size_t k = 0; k < ins.n_sensors(); ++k ) {
        const Sensor &r = *ins.sensors_[k];
        assert(!r.sense_.empty());

        // create common condition
        index_set common_condition;
        for( index_set::const_iterator it = r.condition_.begin(); it != r.condition_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            if( *it > 0 )
                common_condition.insert(1 + 2*idx);
            else
                common_condition.insert(1 + 2*idx+1);
        }

        // generate different rule for every sensed fluent
        int obs = 0;
        for( index_set::const_iterator it = r.sense_.begin(); it != r.sense_.end(); ++it ) {
            assert(*it > 0);
            int idx = *it-1;
            for( size_t n = 0; n < 2; ++n ) {
                string name = string("sensor-") + r.name_->to_string() + "-obs" + Utils::to_string(obs) + "-ver" + Utils::to_string(n);
                Action &nact = new_action(new CopyName(name));

                // conditional effect
                When c_eff;
                c_eff.condition_.insert(common_condition.begin(), common_condition.end());
                c_eff.condition_.insert(-(1 + 2*idx));
                c_eff.condition_.insert(-(1 + 2*idx+1));
                if( n == 0 ) {
                    c_eff.effect_.insert(1 + 2*idx);
                } else {
                    c_eff.effect_.insert(1 + 2*idx+1);
                }

                // add conditional effect to rule
                //obs_rules_by_name_[nact.name_->to_string()] = n_actions();
                nact.when_.push_back(c_eff);
                if( options_.is_enabled("kp:print:action:sensor") ) {
                    nact.print(cout, *this);
                }
            }
            ++obs;
        }
    }
    n_sensor_actions_ = n_actions() - n_standard_actions_;

    // create invariant rules
    size_t invariant_no = 0;
    multimap<index_set, const Action*> invariant_actions;
    for( invariant_vec::const_iterator it = ins.init_.invariants_.begin(); it != ins.init_.invariants_.end(); ++it ) {
        const Invariant &invariant = *it;
        assert((invariant.type_ == Invariant::AT_LEAST_ONE) || (invariant.type_ == Invariant::AT_MOST_ONE));

        // if trivial invariant, skip it
        if( (invariant.size() == 2) && (invariant[0] == -invariant[1]) ) continue;

        //cout << "Processing invariant "; invariant.write(cout, 0, ins);
        for( size_t k = 0; k < invariant.size(); ++k ) {
            string name = string("invariant-") + (invariant.type_ == Invariant::AT_LEAST_ONE ? "at-least-one" : "at-most-one") + "-" + Utils::to_string(invariant_no++);
            Action *nact = new Action(new CopyName(name));
            vector<int> completion;

            // setup precondition
            assert(invariant.Xprecondition_.empty());
            for( index_set::const_iterator it = invariant.Xprecondition_.begin(); it != invariant.Xprecondition_.end(); ++it ) {
                int lit = *it;
                int idx = lit > 0 ? lit-1 : -lit-1;
                if( lit > 0 )
                    nact->precondition_.insert(1 + 2*idx);
                else
                    nact->precondition_.insert(1 + 2*idx+1);
            }

            // effects
            string comment_body, comment_head;
            if( invariant.type_ == Invariant::AT_LEAST_ONE ) {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k ) {
                            nact->precondition_.insert(1 + 2*idx+1);
                            comment_body += atoms_[2*idx+1]->name_->to_string() + " ";
                        } else {
                            nact->precondition_.insert(-(1 + 2*idx+1));
                            nact->effect_.insert(1 + 2*idx);
                        }
                    } else {
                        if( i != k ) {
                            nact->precondition_.insert(1 + 2*idx);
                            comment_body += atoms_[2*idx]->name_->to_string() + " ";
                        } else {
                            nact->precondition_.insert(-(1 + 2*idx));
                            nact->effect_.insert(1 + 2*idx+1);
                        }
                    }
                }
            } else {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k ) {
                            nact->effect_.insert(1 + 2*idx+1);
                            comment_head += atoms_[2*idx+1]->name_->to_string() + " ";
                        } else {
                            nact->precondition_.insert(1 + 2*idx);
                            comment_body += atoms_[2*idx]->name_->to_string();
                        }
                    } else {
                        if( i != k ) {
                            nact->effect_.insert(1 + 2*idx);
                            comment_head += atoms_[2*idx]->name_->to_string() + " ";
                        } else {
                            nact->precondition_.insert(1 + 2*idx+1);
                            comment_body += atoms_[2*idx+1]->name_->to_string();
                        }
                    }
                }
            }

            // set comment
            nact->comment_ = comment_body + " ==> " + comment_head;

            // store invariant action
            invariant_actions.insert(make_pair(nact->precondition_, nact));
        }
    }

    // insert invariant rules into instance (merging similar actions if option is enabled)
    multimap<index_set, const Action*>::key_compare comparator = invariant_actions.key_comp();
    for( multimap<index_set, const Action*>::const_iterator it = invariant_actions.begin(); it != invariant_actions.end(); ) {
        const Action &invariant = *it->second;
        Action &nact = new_action(new CopyName(invariant.name_->to_string()));
        nact.precondition_ = invariant.precondition_;
        nact.effect_ = invariant.effect_;
        nact.when_ = invariant.when_;
        nact.cost_ = invariant.cost_;
        nact.comment_ = invariant.comment_;
        delete it->second;
        if( ++it == invariant_actions.end() ) break;

        if( options_.is_enabled("kp:merge-invariants") ) {
            if( !comparator(nact.precondition_, it->first) ) nact.comment_ = "<omitted>";
            set<When> included_when_effects;
            included_when_effects.insert(nact.when_.begin(), nact.when_.end());
            while( !comparator(nact.precondition_, it->first) ) {
                assert(it != invariant_actions.end());
                nact.effect_.insert(it->second->effect_.begin(), it->second->effect_.end());
                nact.when_.insert(nact.when_.end(), it->second->when_.begin(), it->second->when_.end());
#if 0
                for( when_vec::const_iterator jt = it->second->when_.begin(); jt != it->second->when_.end(); ++jt ) {
                    if( included_when_effects.find(*jt) == included_when_effects.end() ) {
                        included_when_effects.insert(*jt);
                        nact.when_.push_back(*jt);
                    }
                }
#endif
                delete it->second;
                if( ++it == invariant_actions.end() ) break;
            }
        }

        if( options_.is_enabled("kp:print:action:invariant") ) {
            nact.print(cout, *this);
        }
    }

#if 0
    // create invariant rules
    //size_t invariant_no = 0;
    for( invariant_vec::const_iterator it = ins.init_.invariants_.begin(); it != ins.init_.invariants_.end(); ++it ) {
        const Invariant &invariant = *it;
        assert((invariant.type_ == Invariant::AT_LEAST_ONE) || (invariant.type_ == Invariant::AT_MOST_ONE));

        // if trivial invariant, skip it
        if( (invariant.size() == 2) && (invariant[0] == -invariant[1]) ) continue;

        //cout << "Processing invariant "; invariant.write(cout, 0, ins);
        for( size_t k = 0; k < invariant.size(); ++k ) {
            string name = string("invariant-") + (invariant.type_ == Invariant::AT_LEAST_ONE ? "at-least-one" : "at-most-one") + "-" + Utils::to_string(invariant_no++);
            Action &nact = new_action(new CopyName(name));
            vector<int> completion;

            // setup precondition
            assert(invariant.Xprecondition_.empty());
            for( index_set::const_iterator it = invariant.Xprecondition_.begin(); it != invariant.Xprecondition_.end(); ++it ) {
                int lit = *it;
                int idx = lit > 0 ? lit-1 : -lit-1;
                if( lit > 0 )
                    nact.precondition_.insert(1 + 2*idx);
                else
                    nact.precondition_.insert(1 + 2*idx+1);
            }

            // effects
            string comment_body, comment_head;
            if( invariant.type_ == Invariant::AT_LEAST_ONE ) {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k ) {
                            nact.precondition_.insert(1 + 2*idx+1);
                            comment_body += atoms_[2*idx+1]->name_->to_string() + " ";
                        } else {
                            nact.precondition_.insert(-(1 + 2*idx+1));
                            nact.effect_.insert(1 + 2*idx);
                        }
                    } else {
                        if( i != k ) {
                            nact.precondition_.insert(1 + 2*idx);
                        } else {
                            nact.precondition_.insert(-(1 + 2*idx));
                            nact.effect_.insert(1 + 2*idx+1);
                        }
                    }
                }
            } else {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k ) {
                            nact.effect_.insert(1 + 2*idx+1);
                            comment_head += atoms_[2*idx+1]->name_->to_string() + " ";
                        } else {
                            nact.precondition_.insert(1 + 2*idx);
                            comment_body += atoms_[2*idx]->name_->to_string();
                        }
                    } else {
                        if( i != k ) {
                            nact.effect_.insert(1 + 2*idx);
                            comment_head += atoms_[2*idx]->name_->to_string() + " ";
                        } else {
                            nact.precondition_.insert(1 + 2*idx+1);
                            comment_body += atoms_[2*idx+1]->name_->to_string();
                        }
                    }
                }
            }

            // set comment
            nact.comment_ = comment_body + " ==> " + comment_head;

            if( options_.is_enabled("kp:print:action:invariant") ) {
                nact.print(cout, *this);
            }
        }
    }
#endif
    n_invariant_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_;

    // do subgoaling
    create_subgoaling_actions(ins);
    n_subgoaling_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_ - n_invariant_actions_;
}

Standard_KP_Instance::~Standard_KP_Instance() {
}

void Standard_KP_Instance::cross_reference() {
    n_standard_actions_ = 0;
    n_sensor_actions_ = 0;
    n_invariant_actions_ = 0;
    n_subgoaling_actions_ = 0;

    size_t k = 0;
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 7, "sensor-") == 0) ||
            (aname.compare(0, 10, "invariant-") == 0) ||
            (aname.compare(0, 22, "subgoaling_action_for_") == 0) ) {
            n_standard_actions_ = k;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 10, "invariant-") == 0) ||
            (aname.compare(0, 22, "subgoaling_action_for_") == 0) ) {
            n_sensor_actions_ = k - n_standard_actions_;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( aname.compare(0, 22, "subgoaling_action_for_") == 0 ) {
            n_invariant_actions_ = k - n_standard_actions_ - n_sensor_actions_;
            break;
        }
        ++k;
    }
    n_subgoaling_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_ - n_invariant_actions_;

    // remap actions into po instance
    for( size_t k = 0; k < n_standard_actions_; ++k ) {
        remap_[k] = -1;
        for( size_t j = 0; j < po_instance_.n_actions(); ++j ) {
            if( actions_[k]->name_->to_string() == po_instance_.actions_[j]->name_->to_string() ) {
                remap_[k] = j;
                break;
            }
        }
    }

    Instance::cross_referenced_ = true;
}

void Standard_KP_Instance::get_goal_condition(index_set &condition) const {
    condition.clear();
    condition.insert(1 + new_goal_->index_);
}

void Standard_KP_Instance::print_stats(ostream &os) const {
    os << "kp-instance (type=standard):"
       << " #standard-actions=" << n_standard_actions_
       << ", #sensor-actions=" << n_sensor_actions_
       << ", #invariant-actions=" << n_invariant_actions_
       << ", #subgoaling-actions=" << n_subgoaling_actions_
       << endl;
}

#if 0
// This function apply given plan at given initial state and returns the final
// state and the assumptions made by the plan. If plan is applicable, returns
// true. Otherwise, returns false.
bool KP_Instance::apply_plan(const Plan &plan, const State &initial_state, State &final_state, vector<State> &assumption_vec) const {
    assumption_vec.clear();
    vector<State> support_vec;

    final_state = initial_state;
    for( size_t k = 0; k < plan.size(); ++k ) {
        const Instance::Action &act = *actions_[plan[k]];
        assert(final_state.applicable(act));

        // check that preconditions hold at current state (final_state)
        if( !final_state.satisfy(act.precondition_) ) return false;

        State assumption;
        State support;

        // add positive preconditions to support
        for( index_set::const_iterator it = act.precondition_.begin(); it != act.precondition_.end(); ++it ) {
            if( *it > 0 ) {
                support.add(*it - 1);
            }
        }

        // add positive conditions of triggered conditional effects to support and
        // the assumptions made with observations rules
        for( size_t i = 0; i < act.when_.size(); ++i ) {
            const Instance::When &w = act.when_[i];
            if( final_state.satisfy(w.condition_) ) {
                for( index_set::const_iterator it = w.condition_.begin(); it != w.condition_.end(); ++it ) {
                    if( *it > 0 ) {
                        support.add(*it - 1);
                    }
                }
                if( is_obs_rule(plan[k]) ) {
                    for( index_set::const_iterator it = w.effect_.begin(); it != w.effect_.end(); ++it ) {
                        assert(*it > 0);
                        if( !final_state.satisfy(*it - 1) ) {
                            assumption.add(*it - 1);
                        }
                    }
                }
            }
        }
        cout << "support="; support.print(cout, *this);  cout << endl;
        cout << "assumption ="; assumption.print(cout, *this);  cout << endl;
        support_vec.push_back(support);
        assumption_vec.push_back(assumption);

        // apply action to state
        final_state.apply(act);
    }

    // calculate and consolidate the relevant assumptions
    assert(support_vec.size() == assumption_vec.size());
    State relevant, support;
    for( int i = assumption_vec.size() - 1; i >= 0; --i ) {
        support.add(support_vec[i]);
        for( State::const_iterator it = assumption_vec[i].begin(); it != assumption_vec[i].end(); ++it ) {
            if( support.satisfy(*it) ) {
                relevant.add(*it);
            }
        }
        assumption_vec[i] = relevant;
    }

    return true;
}
#endif

