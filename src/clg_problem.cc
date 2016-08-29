#include <cassert>
#include <cstdlib>
#include "clg_problem.h"
#include "state.h"
#include "utils.h"

using namespace std;

CLG_Instance::CLG_Instance(const Instance &ins)
  : KP_Instance(ins.options_),
    n_standard_actions_(0),
    n_sensor_actions_(0),
    n_drule_actions_(0),
    n_subgoaling_actions_(0),
    po_instance_(ins) {

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
        if( *it > 0 ) {
            //cout << "Adding +" << ins.atoms_[idx]->name_ << endl;
            init_.literals_.insert(1 + 2*idx);
        } else {
            //cout << "Adding -" << ins.atoms_[idx]->name_ << endl;
            init_.literals_.insert(1 + 2*idx+1);
        }
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
                //cout << "XXXXXX COMPLETION OF INIT is off!" << endl;
                //init_.literals_.insert(1 + 2*k+1);
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
        const Action &action = *ins.actions_[k];
        if( action.name_->to_string().compare(0, 6, "drule-") != 0 )
            create_regular_action(action, k);//, observable_atoms_, beams_for_observable_atoms_);
    }

    // create deductive rules from invariants
    for( invariant_vec::const_iterator it = ins.init_.invariants_.begin(); it != ins.init_.invariants_.end(); ++it ) {
        const Invariant &invariant = *it;
        create_drules_from_invariant(invariant);
    }
    merge_drules();

    // create actions for sensors
    for( size_t k = 0; k < ins.n_sensors(); ++k )
        create_sensor(*ins.sensors_[k]);

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

    // do subgoaling
    perform_subgoaling();

    // cross reference instance to compute how rules of each type
    cross_reference();
    //cout << index_for_goal_action_ << "."; goal_action.print(cout, *this);
}

CLG_Instance::~CLG_Instance() {
}

void CLG_Instance::create_regular_action(const Action &action, int action_index) {
    string action_name = action.name_->to_string();
    assert(action_name.compare(0, 6, "drule-") != 0);

    // create new action
    Action &nact = new_action(new CopyName(action_name));
    remap_[action_index] = action_index;

    // preconditions
    for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 )
            nact.precondition_.insert(1 + 2*idx);
        else
            nact.precondition_.insert(1 + 2*idx+1);
    }

    // support and cancellation rules for unconditional effects
    for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
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
    for( size_t i = 0; i < action.when_.size(); ++i ) {
        const When &when = action.when_[i];
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

    if( options_.is_enabled("kp:print:action:regular") )
        nact.print(cout, *this);
}

void CLG_Instance::create_drules_from_invariant(const Invariant &invariant) {
    assert((invariant.type_ == Invariant::AT_LEAST_ONE) || (invariant.type_ == Invariant::AT_MOST_ONE));

    // if trivial invariant, skip it
    if( (invariant.size() == 2) && (invariant[0] == -invariant[1]) ) return;

    for( size_t k = 0; k < invariant.size(); ++k ) {
        string name = string("drule-invariant-") + (invariant.type_ == Invariant::AT_LEAST_ONE ? "alo-" : "amo-") + Utils::to_string(drule_store_.size());
        Action *nact = new Action(new CopyName(name));

        // setup precondition
        assert(invariant.Xprecondition_.empty());

        // effects
        if( invariant.type_ == Invariant::AT_LEAST_ONE ) {
            for( size_t i = 0; i < invariant.size(); ++i ) {
                int lit = invariant[i];
                int idx = lit > 0 ? lit - 1 : -lit - 1;
                if( lit > 0 ) {
                    if( i != k ) {
                        nact->precondition_.insert(1 + 2*idx + 1);
                    } else {
                        nact->precondition_.insert(-(1 + 2*idx + 1));
                        nact->effect_.insert(1 + 2*idx);
                    }
                } else {
                    if( i != k ) {
                        nact->precondition_.insert(1 + 2*idx);
                    } else {
                        nact->precondition_.insert(-(1 + 2*idx));
                        nact->effect_.insert(1 + 2*idx + 1);
                    }
                }
            }
        } else {
            for( size_t i = 0; i < invariant.size(); ++i ) {
                int lit = invariant[i];
                int idx = lit > 0 ? lit - 1 : -lit - 1;
                if( lit > 0 ) {
                    if( i != k )
                        nact->effect_.insert(1 + 2*idx + 1);
                    else
                        nact->precondition_.insert(1 + 2*idx);
                } else {
                    if( i != k )
                        nact->effect_.insert(1 + 2*idx);
                    else
                        nact->precondition_.insert(1 + 2*idx + 1);
                }
            }
        }

        // store invariant action
        drule_store_.insert(make_pair(nact->precondition_, nact));
    }
}

void CLG_Instance::merge_drules() {
    multimap<index_set, const Action*>::key_compare comparator = drule_store_.key_comp();
    for( multimap<index_set, const Action*>::const_iterator it = drule_store_.begin(); it != drule_store_.end(); ) {
        const Action &drule = *it->second;
        Action &nact = new_action(new CopyName(drule.name_->to_string()));
        nact.precondition_ = drule.precondition_;
        nact.effect_ = drule.effect_;
        nact.when_ = drule.when_;
        nact.cost_ = drule.cost_;
        nact.comment_ = drule.comment_;
        delete it->second;
        if( ++it == drule_store_.end() ) {
            if( options_.is_enabled("kp:print:action:drule:sensing") || options_.is_enabled("kp:print:action:drule") )
                nact.print(cout, *this);
            break;
        }

        if( options_.is_enabled("kp:merge-drules") ) {
            if( !comparator(nact.precondition_, it->first) ) nact.comment_ = "<merge>";
            set<When> included_when_effects;
            included_when_effects.insert(nact.when_.begin(), nact.when_.end());
            while( !comparator(nact.precondition_, it->first) ) {
                assert(it != drule_store_.end());
                nact.effect_.insert(it->second->effect_.begin(), it->second->effect_.end());
                nact.when_.insert(nact.when_.end(), it->second->when_.begin(), it->second->when_.end());
                delete it->second;
                if( ++it == drule_store_.end() ) break;
            }
        }

        if( options_.is_enabled("kp:print:action:drule:sensing") || options_.is_enabled("kp:print:action:drule") )
            nact.print(cout, *this);
    }
}

void CLG_Instance::create_sensor(const Sensor &sensor) {
    assert(!sensor.sense_.empty());

    // create common condition
    index_set common_condition;
    for( index_set::const_iterator it = sensor.condition_.begin(); it != sensor.condition_.end(); ++it ) {
        int idx = *it > 0 ? *it - 1 : -*it - 1;
        if( *it > 0 )
            common_condition.insert(1 + 2*idx);
        else
            common_condition.insert(1 + 2*idx + 1);
    }

    // generate different rule for every sensed fluent
    int obs = 0;
    for( index_set::const_iterator it = sensor.sense_.begin(); it != sensor.sense_.end(); ++it ) {
        assert(*it > 0);
        int idx = *it - 1;
        for( size_t n = 0; n < 2; ++n ) {
            string name = sensor.name_->to_string() + "-obs" + Utils::to_string(obs) + "-ver" + Utils::to_string(n);
            Action &nact = new_action(new CopyName(name));

            // precondition
            nact.precondition_.insert(common_condition.begin(), common_condition.end());
            nact.precondition_.insert(-(1 + 2*idx));
            nact.precondition_.insert(-(1 + 2*idx + 1));

            // effect
            if( n == 0 )
                nact.effect_.insert(1 + 2*idx);
            else
                nact.effect_.insert(1 + 2*idx + 1);

            if( options_.is_enabled("kp:print:action:sensor") )
                nact.print(cout, *this);
        }
        ++obs;
    }
}

void CLG_Instance::perform_subgoaling() {
    if( options_.is_enabled("kp:subgoaling") ) {
        cout << Utils::error() << "subgoaling feature not yet supported." << endl;
        exit(255);
    }
}

void CLG_Instance::cross_reference() {
    n_standard_actions_ = 0;
    n_sensor_actions_ = 0;
    n_drule_actions_ = 0;
    n_subgoaling_actions_ = 0;

    size_t k = 0;
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 6, "drule-") == 0) ||
            (aname.compare(0, 7, "sensor-") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_standard_actions_ = k;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 7, "sensor-") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_drule_actions_ = k - n_standard_actions_;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname == "reach_new_goal_through_original_goal__") ) {
            n_sensor_actions_ = k - n_standard_actions_ - n_drule_actions_;
            index_for_goal_action_ = k;
            break;
        }
        ++k;
    }
    n_subgoaling_actions_ = n_actions() - n_standard_actions_ - n_sensor_actions_ - n_drule_actions_;

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

void CLG_Instance::set_goal_condition(index_set &condition) const {
    condition.clear();
    condition.insert(1 + new_goal_->index_);
}

void CLG_Instance::print_stats(ostream &os) const {
    os << "kp-instance: source=clg-translation"
       << ", #standard-actions=" << n_standard_actions_
       << ", #sensor-actions=" << n_sensor_actions_
       << ", #dules-for-sensing=" << n_drule_actions_
       << ", #subgoaling-actions=" << n_subgoaling_actions_
       << endl;
}

