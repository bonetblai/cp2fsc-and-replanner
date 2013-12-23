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

static void mvv_extend_effect_with_ramifications_on_observables(int index,
                                                                const map<int, set<int> > &beams_for_observable_atoms,
                                                                set<int> &effect) {
    for( map<int, set<int> >::const_iterator it = beams_for_observable_atoms.begin(); it != beams_for_observable_atoms.end(); ++it) {
        int observable_index = it->first;
        const set<int> &beam = it->second;
        if( beam.find(index) != beam.end() ) {
            effect.insert(-(1 + 2*observable_index));
            effect.insert(-(1 + 2*observable_index + 1));
        }
    }
}

KP_Instance::KP_Instance(const Instance &ins, const PDDL_Base::variable_vec &multivalued_variables)
  : Instance(ins.options_), po_instance_(ins),
    n_standard_actions_(0), n_sensor_actions_(0), n_invariant_actions_(0) {

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

    // prepare data for handling problems with multivalued variables
    set<int> observable_atoms;
    map<int, set<int> > beams_for_observable_atoms;
    for( size_t k = 0; k < multivalued_variables.size(); ++k ) {
        const PDDL_Base::Variable &var = *multivalued_variables[k];
        if( var.is_observable_variable() ) {
            for( size_t i = 0; i < var.grounded_values_.size(); ++i ) {
                string atom_name = static_cast<const PDDL_Base::AtomicEffect*>(var.grounded_values_[i])->to_string(true);
                int atom_index = get_atom_index(ins, atom_name);
                if( atom_index != -1 ) {
                    observable_atoms.insert(atom_index);

                    set<int> beam;
                    for( PDDL_Base::unsigned_atom_set::const_iterator it = var.beam_[i].begin(); it != var.beam_[i].end(); ++it ) {
                        int index = get_atom_index(ins, it->to_string(false, true));
                        if( index != -1 ) beam.insert(index);
                    }
                    beams_for_observable_atoms[atom_index] = beam;
                }
            }
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

    // create new goal
    new_goal_ = &new_atom(new CopyName("(new-goal)"));
    goal_literals_.insert(1 + new_goal_->index_);

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
            mvv_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, nact.effect_);
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
                mvv_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, sup_eff.effect_);
                mvv_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, can_eff.effect_);
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
                ostringstream s;
                s << "sensor-" << r.name_->to_string() << "-obs" << obs << "-ver" << n;
                Action &nact = new_action(new CopyName(s.str()));

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
                obs_rules_by_name_[nact.name_->to_string()] = n_actions();
                nact.when_.push_back(c_eff);
                if( options_.is_enabled("kp:print:action:sensor") ) {
                    nact.print(cout, *this);
                }
            }
            ++obs;
        }
    }
    n_sensor_actions_ = n_actions() - n_standard_actions_;

    // create precondition for invariant actions (non-empty only
    // when dealing with CLG syntax)
    index_set precondition;
    if( true && po_instance_.index_for_atom_normal_execution_ >= 0 ) {
        precondition.insert(1 + 2*po_instance_.index_for_atom_normal_execution_ + 1);
    }

    // create invariant rules
    size_t invariant_no = 0;
    for( invariant_vec::const_iterator it = ins.init_.invariants_.begin(); it != ins.init_.invariants_.end(); ++it ) {
        const Invariant &invariant = *it;
        assert(invariant.type_ == Invariant::AT_LEAST_ONE);
        //cout << "processing invariant: "; invariant.write(cout, 0, ins);

        for( size_t k = 0; k < invariant.size(); ++k ) {
            ostringstream s, comment_body, comment_head;
            s << "invariant-" << invariant_no++;
            Action &nact = new_action(new CopyName(s.str()));
            nact.precondition_ = precondition;

            // conditional effects
            When c_eff;
            if( invariant.type_ == Invariant::AT_LEAST_ONE ) {
                for( size_t i = 0; i < invariant.size(); ++i ) {
                    int lit = invariant[i];
                    int idx = lit > 0 ? lit-1 : -lit-1;
                    if( lit > 0 ) {
                        if( i != k ) {
                            c_eff.condition_.insert(1 + 2*idx+1);
                            comment_body << atoms_[2*idx+1]->name_ << " ";
                        } else {
                            c_eff.condition_.insert(-(1 + 2*idx+1)); // TODO: check if necessary
                            c_eff.effect_.insert(1 + 2*idx);
                            comment_head << atoms_[2*idx]->name_;
                        }
                    } else {
                        if( i != k ) {
                            c_eff.condition_.insert(1 + 2*idx);
                            comment_body << atoms_[2*idx]->name_ << " ";
                        } else {
                            c_eff.condition_.insert(-(1 + 2*idx)); // TODO: check if necessary
                            c_eff.effect_.insert(1 + 2*idx+1);
                            comment_head << atoms_[2*idx+1]->name_;
                        }
                    }
                }
            } else {
                cout << Utils::error() << "only AT_LEAST_ONE-type invariants should exist at this stage" << endl;
                exit(255);
            }

            // push conditional effect
            nact.comment_ = comment_body.str() + "==> " + comment_head.str();
            nact.when_.push_back(c_eff);
            if( options_.is_enabled("kp:print:action:invariant") ) {
                nact.print(cout, *this);
            }
        }
    }
    n_invariant_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_;

    // create new goal-achieving actions
    Action &goal_action = new_action(new CopyName("reach_new_goal_through_original_goal__"));
    for( index_set::const_iterator it = ins.goal_literals_.begin(); it != ins.goal_literals_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            goal_action.precondition_.insert(1 + 2*idx);
        else
            goal_action.precondition_.insert(1 + 2*idx+1);
    }
    goal_action.effect_.insert(1 + new_goal_->index_);
    index_for_goal_action_ = goal_action.index_;
    //cout << index_for_goal_action_ << "."; goal_action.print(cout, *this);

    if( options_.is_enabled("kp:subgoaling") ) {
        cout << Utils::error() << "subgoaling feature not yet supported." << endl;
        exit(255);
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
    }
    n_subgoaling_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_ - n_invariant_actions_;
}

KP_Instance::~KP_Instance() {
}

void KP_Instance::cross_reference() {
    n_standard_actions_ = 0;
    n_sensor_actions_ = 0;
    n_invariant_actions_ = 0;
    n_subgoaling_actions_ = 0;

    size_t k = 0;
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 7, "sensor-") == 0) ||
            (aname.compare(0, 10, "invariant-") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_standard_actions_ = k;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 10, "invariant-") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_sensor_actions_ = k - n_standard_actions_;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname == "reach_new_goal_through_original_goal__") ) {
            n_invariant_actions_ = k - n_standard_actions_ - n_sensor_actions_;
            index_for_goal_action_ = k;
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

void KP_Instance::write_problem(ostream &os, const State *state, int indent) const {
    if( options_.is_enabled("kp:subgoaling") ) {
        cout << "XXXXXXXXX" << endl;
    }
    Instance::write_problem(os, state, indent);
    if( options_.is_enabled("kp:subgoaling") ) {
        cout << "XXXXXXXXX" << endl;
    }
}

