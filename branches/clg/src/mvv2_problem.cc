#include <cassert>
#include <cstdlib>
#include "mvv2_problem.h"
#include "state.h"
#include "utils.h"

using namespace std;

static int get_atom_index(const Instance &ins, string atom_name) {
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        if( atom_name == ins.atoms_[k]->name_->to_string() )
            return k;
    }
    cout << "GET FAILED: name=" << atom_name << endl;
    return -1;
}

static void mvv_extend_effect_with_ramifications_on_observables(int index,
                                                                const map<int, index_set> &beams_for_observable_atoms,
                                                                set<int> &effect) {
    for( map<int, index_set>::const_iterator it = beams_for_observable_atoms.begin(); it != beams_for_observable_atoms.end(); ++it) {
        int observable_index = it->first;
        const set<int> &beam = it->second;
        if( beam.find(index) != beam.end() ) {
            effect.insert(-(1 + 2*observable_index));
            effect.insert(-(1 + 2*observable_index + 1));
        }
    }
}

#if 0
static void calculate_completion_with_variable(int literal, vector<int> &completion, const set<int> &var, const Instance &ins) {
    if( var.find(literal) != var.end() ) {
        //cout << "completion for literal=" << ins.atoms_[literal]->name_ << endl;
        for( index_set::const_iterator it = var.begin(); it != var.end(); ++it )
            if( literal != *it ) completion.push_back(*it);
    }
}

static void calculate_completion(int literal, vector<int> &completion, const vector<set<int> > &multivalued_variables, const Instance &ins) {
    for( size_t k = 0; k < multivalued_variables.size(); ++k )
        calculate_completion_with_variable(literal, completion, multivalued_variables[k], ins);
}
#endif

MVV2_Instance::MVV2_Instance(const Instance &ins, const PDDL_Base::variable_vec &multivalued_variables)
  : KP_Instance(ins.options_),
    n_standard_actions_(0),
    n_sensor_actions_(0),
    n_drule_actions_(0),
    n_drules_for_vars_(0),
    n_drules_for_sensing_(0),
    n_drules_for_atoms_(0),
    n_subgoaling_actions_(0),
    po_instance_(ins) {

    // set intance name
    if( dynamic_cast<const InstanceName*>(ins.name_) != 0 )
        set_name(new InstanceName(*dynamic_cast<const InstanceName*>(ins.name_)));
    else
        set_name(new CopyName(ins.name_->to_string()));

    // there should not be any invariants
    if( !ins.init_.invariants_.empty() )
        cout << Utils::warning() << "problem has invariants; ignoring them..." << Utils::normal() << endl;

    // extract multivalued variables
    multivalued_variables_.reserve(multivalued_variables.size());
    //list<pair<string, set<int> > > multivalued_state_variables;
    //list<pair<string, set<int> > > multivalued_observable_variables;;
    for( size_t k = 0; k < multivalued_variables.size(); ++k ) {
        const PDDL_Base::Variable &var = *multivalued_variables[k];
        set<int> values;
        for( PDDL_Base::unsigned_atom_set::const_iterator it = var.grounded_values_.begin(); it != var.grounded_values_.end(); ++it ) {
            assert(!it->negated_);
            string atom_name = it->to_string(false, true);
            int atom_index = get_atom_index(ins, atom_name);
if( atom_index == -1 ) continue;
            assert(atom_index != -1);
            values.insert(atom_index);
            if( var.is_observable_variable() ) {
//cout << "obs-variable: atom=" << *it << ", name=" << atom_name << ", index=" << atom_index << endl;
                observable_atoms_.insert(atom_index);
                index_set beam;
//if( var.beam_.find(*it) == var.beam_.end() ) continue;
                assert(var.beam_.find(*it) != var.beam_.end());
                const PDDL_Base::unsigned_atom_set &var_beam = var.beam_.find(*it)->second;
//cout << "Beam for " << atom_name << ":";
                for( PDDL_Base::unsigned_atom_set::const_iterator jt = var_beam.begin(); jt != var_beam.end(); ++jt ) {
                    int index = get_atom_index(ins, jt->to_string(jt->negated_, true));
                    assert(index != -1);
                    beam.insert(index);
//cout << " " << *ins.atoms_[index]->name_;
                }
//cout << endl;
                beams_for_observable_atoms_[atom_index] = beam;
            }
        }
        multivalued_variables_.push_back(make_pair(var.print_name_, values));
#if 0
        if( var.is_state_variable() && !var.is_observable_variable() )
            multivalued_state_variables.push_back(make_pair(var.print_name_, values));
        else
            multivalued_observable_variables.push_back(make_pair(var.print_name_, values));
#endif
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
        const Action &act = *ins.actions_[k];
        if( act.name_->to_string().compare(0, 6, "drule-") != 0 )
            create_regular_action(act, k, observable_atoms_, beams_for_observable_atoms_);
    }

    // fix decision rules for multivalued variables
    for( size_t k = 0; k < ins.n_actions(); ++k ) {
        const Action &act = *ins.actions_[k];
        if( act.name_->to_string().compare(0, 10, "drule-var-") == 0 )
            create_drule_for_var(act);
    }

    // fix decision rules for sensing. First, create and store actions. Then,
    // if requested, merge actions and insert them into problem.
    for( size_t k = 0; k < ins.n_actions(); ++k ) {
        const Action &act = *ins.actions_[k];
        if( act.name_->to_string().compare(0, 14, "drule-sensing-") == 0 )
            create_drule_for_sensing(act);
    }
    merge_drules();

    // fix decision rules for atoms (only present with type-3 drules for sensing)
    for( size_t k = 0; k < ins.n_actions(); ++k ) {
        const Action &act = *ins.actions_[k];
        if( act.name_->to_string().compare(0, 11, "drule-atom-") == 0 )
            create_drule_for_atom(act);
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
    print_stats(cout);
}

MVV2_Instance::~MVV2_Instance() {
}

void MVV2_Instance::create_regular_action(const Action &action,
                                          int action_index,
                                          const index_set &observable_atoms,
                                          const map<int, index_set> &beams_for_observable_atoms) {
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
        mvv_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, nact.effect_);
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

    if( options_.is_enabled("kp:print:action:regular") )
        nact.print(cout, *this);
}

void MVV2_Instance::create_drule_for_var(const Action &action) {
    string action_name = action.name_->to_string();
    assert(action_name.compare(0, 10, "drule-var-") == 0);

    Action &nact = new_action(new CopyName(action_name));
    if( action_name.compare(0, 16, "drule-var-type1-") == 0 ) {
        assert(action.effect_.size() == 1);
        int eff = *action.effect_.begin();
        assert(eff > 0);
        nact.effect_.insert(1 + 2*(eff - 1));
        for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
            assert(*it < 0);
            int index = -*it - 1;
            nact.precondition_.insert(1 + 2*index + 1);
        }
        nact.precondition_.insert(-(1 + 2*(eff - 1) + 1));
    } else {
        assert(action.precondition_.size() == 1);
        int pre = *action.precondition_.begin();
        assert(pre > 0);
        nact.precondition_.insert(1 + 2*(pre - 1));
        for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
            assert(*it < 0);
            int index = -*it - 1;
            //When when;
            //when.condition_.insert(-(1 + 2*index));
            //when.effect_.insert(1 + 2*index + 1);
            //nact.when_.push_back(when);
            nact.effect_.insert(1 + 2*index + 1);
        }
    }

    if( options_.is_enabled("kp:print:action:drule:var") || options_.is_enabled("kp:print:action:drule") )
        nact.print(cout, *this);
}

void MVV2_Instance::create_drule_for_sensing(const Action &action) {
    string action_name = action.name_->to_string();
    assert(action_name.compare(0, 14, "drule-sensing-") == 0);

    Action *nact = new Action(new CopyName(action_name));
    for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
        int index = *it > 0 ? *it - 1 : -*it - 1;
        nact->precondition_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
    }

    for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
        int index = *it > 0 ? *it - 1 : -*it - 1;
        nact->effect_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
    }

    drule_store_.insert(make_pair(nact->precondition_, nact));
}

void MVV2_Instance::merge_drules() {
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
    drule_store_.clear();
}

void MVV2_Instance::create_drule_for_atom(const Action &action) {
    string action_name = action.name_->to_string();
    assert(action_name.compare(0, 11, "drule-atom-") == 0);

    Action *nact = new Action(new CopyName(action_name));
    for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
        int index = *it > 0 ? *it - 1 : -*it - 1;
        nact->precondition_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
    }

    for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
        int index = *it > 0 ? *it - 1 : -*it - 1;
        nact->effect_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
    }

    drule_store_.insert(make_pair(nact->precondition_, nact));
}

void MVV2_Instance::create_sensor(const Sensor &sensor) {
    assert(!sensor.sense_.empty());
    assert(sensor.sense_.size() == 1);

    int sensed = *sensor.sense_.begin();
    int sensed_index = sensed > 0 ? sensed - 1 : -sensed - 1;

    int varid = -1;
    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        const pair<string, set<int> > &var = multivalued_variables_[k];
        if( var.second.find(sensed_index) != var.second.end() ) {
            varid = k;
            break;
        }
    }
    if( varid == -1 ) {
        cout << Utils::warning()
             << "sensed value for '" << *sensor.name_ << "' doesn't correspond to any value"
             << Utils::normal() << endl;
    }

    Action &nact = new_action(new CopyName(strdup(sensor.name_->to_string().c_str())));
    nact.effect_.insert(sensed > 0 ? 1 + 2*sensed_index : 1 + 2*sensed_index + 1);
    for( index_set::const_iterator it = sensor.condition_.begin(); it != sensor.condition_.end(); ++it ) {
        int index = *it > 0 ? *it - 1 : -*it - 1;
        nact.precondition_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
    }
    nact.precondition_.insert(sensed > 0 ? -(1 + 2*sensed_index + 1) : -(1 + 2*sensed_index));

    // complete condition with conditions on other values of the variable (if applicable)
    if( (sensed > 0) && (varid != -1) ) {
        const pair<string, set<int> > &var = multivalued_variables_[varid];
        for( set<int>::const_iterator it = var.second.begin(); it != var.second.end(); ++it ) {
            if( *it != sensed_index ) nact.precondition_.insert(-(1 + 2**it));
        }
    }

    if( options_.is_enabled("kp:print:action:sensor") )
        nact.print(cout, *this);
}

void MVV2_Instance::perform_subgoaling() {
    if( options_.is_enabled("kp:subgoaling") ) {
        cout << Utils::error() << "subgoaling feature not yet supported." << endl;
        exit(255);
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

void MVV2_Instance::cross_reference() {
    n_standard_actions_ = 0;
    n_sensor_actions_ = 0;
    n_drule_actions_ = 0;
    n_drules_for_vars_ = 0;
    n_drules_for_sensing_ = 0;
    n_drules_for_atoms_ = 0;
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
        if( (aname.compare(0, 14, "drule-sensing-") == 0) ||
            (aname.compare(0, 11, "drule-atom-") == 0) ||
            (aname.compare(0, 7, "sensor-") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_drules_for_vars_ = k - n_standard_actions_;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 11, "drule-atom-") == 0) ||
            (aname.compare(0, 7, "sensor-") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_drules_for_sensing_ = k - n_standard_actions_ - n_drules_for_vars_;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 7, "sensor-") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_drules_for_atoms_ = k - n_standard_actions_ - n_drules_for_vars_ - n_drules_for_sensing_;
            n_drule_actions_ = k - n_standard_actions_;
            assert(n_drule_actions_ == n_drules_for_vars_ + n_drules_for_sensing_ + n_drules_for_atoms_);
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

void MVV2_Instance::set_goal_condition(index_set &condition) const {
    condition.clear();
    condition.insert(1 + new_goal_->index_);
}

void MVV2_Instance::print_stats(ostream &os) const {
    os << "kp-instance: source=mvv-translation"
       << ", #standard-actions=" << n_standard_actions_
       << ", #sensor-actions=" << n_sensor_actions_
       << ", #dules-for-vars=" << n_drules_for_vars_
       << ", #dules-for-sensing=" << n_drules_for_sensing_
       << ", #dules-for-atoms=" << n_drules_for_atoms_
       << ", #subgoaling-actions=" << n_subgoaling_actions_
       << endl;
}

