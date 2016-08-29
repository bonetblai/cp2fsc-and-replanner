#include <cassert>
#include <list>
#include "cp_problem.h"
#include "state.h"
#include "utils.h"

using namespace std;

// TODO: remove map actions for which there are no act actions

CP_Instance::CP_Instance(const Instance &ins, size_t fsc_states,
                         bool forbid_inconsistent_tuples,
                         bool compound_obs_as_fluents)
  : Instance(ins.options_), fsc_states_(fsc_states),
    forbid_inconsistent_tuples_(forbid_inconsistent_tuples),
    compound_obs_as_fluents_(compound_obs_as_fluents),
    instance_(ins) {

    // set name
    if( dynamic_cast<const InstanceName*>(ins.name_) != 0 ) {
        set_name(new InstanceName(*dynamic_cast<const InstanceName*>(ins.name_)));
    } else {
        set_name(new CopyName(ins.name_->to_string()));
    }

    // set description of init
    init_ = ins.init_;

    // calculate reachable state space
    ins.generate_initial_states(initial_states_);
    for( StateSet::const_iterator it = initial_states_.begin(); it != initial_states_.end(); ++it ) {
        StateSet *space = new StateSet;
        ins.generate_reachable_state_space(**it, *space);
        reachable_space_from_initial_state_.insert(make_pair(*it, space));
        reachable_space_.insert(space->begin(), space->end());
        cout << "# reachable states from "; (*it)->print(cout, ins); cout << " = " << space->size() << endl;
    }
    cout << "# initial states = " << initial_states_.size() << endl;
    cout << "# reachable states = " << reachable_space_.size() << endl;

    // calculate reachable observations
    state_obs_ = vector<int>(reachable_space_.size(), -1);
    int state_idx = 0;
    for( StateSet::const_iterator it = reachable_space_.begin(); it != reachable_space_.end(); ++it ) {
        index_set obs;
        for( index_set::const_iterator jt = ins.observable_fluents_.begin(); jt != ins.observable_fluents_.end(); ++jt ) {
            if( (*it)->satisfy(*jt) ) obs.insert(1 + *jt);
        }
        if( reachable_obs_.find(obs) == reachable_obs_.end() ) {
            // this is a new observation
            reachable_obs_.insert(make_pair(obs, (int)reachable_obs_.size()));
        }
        state_obs_[state_idx++] = reachable_obs_[obs];
    }

    cout << "# reachable obs = " << reachable_obs_.size() << endl;
    for( map<index_set, int>::const_iterator it = reachable_obs_.begin(); it != reachable_obs_.end(); ++it ) {
        for( map<index_set, int>::const_iterator jt = it; jt != reachable_obs_.end(); ++jt ) {
            if( (it != jt) && (it->first.contains(jt->first) || jt->first.contains(it->first)) ) {
                cout << Utils::warning() << "obs ";
                ins.write_atom_set(cout, it->first);
                cout << " and ";
                ins.write_atom_set(cout, jt->first);
                cout << " not disjunct. Translation may be invalid!" << endl;
            }
        }
        cout << "obs" << it->second << ":";
        for( index_set::const_iterator jt = it->first.begin(); jt != it->first.end(); ++jt )
            cout << " " << ins.atoms_[*jt-1]->name_;
        cout << endl;
    }

    // create atoms
    atoms_.reserve(ins.n_atoms() + fsc_states_);
    for( size_t k = 0; k < ins.n_atoms(); ++k )
        new_atom(new CopyName(ins.atoms_[k]->name_->to_string()));

    // fluents for obs
    if( compound_obs_as_fluents_ ) {
        obs0_ = n_atoms();
        for( size_t k = 0; k < reachable_obs_.size(); ++k ) {
            string name = string("(obs") + Utils::to_string(k) + ")";
            new_atom(new CopyName(name));
        }
    }

    // fluents for states
    q0_ = n_atoms();
    for( size_t k = 0; k < fsc_states_; ++k ) {
        string name = string("(q") + Utils::to_string(k) + ")";
        new_atom(new CopyName(name));
    }

    // create fluents to forbid inconsistent tuples
    if( forbid_inconsistent_tuples_ ) {
        n_unused_fluents_ = reachable_obs_.size() * fsc_states_;
        n_mapped_fluents_ = n_unused_fluents_ * ins.n_actions() * fsc_states_;
        unused0_ = n_atoms();
        for( size_t k = 0; k < n_unused_fluents_; ++k ) {
            string name = string("(unused") + Utils::to_string(k) + ")";
            new_atom(new CopyName(name));
        }
        mapped0_ = n_atoms();
        for( size_t k = 0; k < n_mapped_fluents_; ++k ) {
            string name = string("(mapped") + Utils::to_string(k) + ")";
            new_atom(new CopyName(name));
        }
    }

    // add q0 to initial state
    init_.literals_.insert(1 + q0_);
    add_to_initial_states(q0_);

    // extend initial situation with fluents to remove inconsistent tuples
    if( forbid_inconsistent_tuples_ ) {
        for( size_t k = 0; k < n_unused_fluents_; ++k ) {
            init_.literals_.insert(1 + unused0_+k);
            add_to_initial_states(unused0_ + k);
        }
    }

    // set goal atoms
    for( index_set::const_iterator it = ins.goal_literals_.begin(); it != ins.goal_literals_.end(); ++it ) {
        assert(*it > 0);
        goal_literals_.insert(1 + *it-1);
    }

    // create common effect for non-primitive non-sticky and non-observable fluents
    index_set np_ns_effect;
    for( index_set::const_iterator it = ins.non_primitive_fluents_.begin(); it != ins.non_primitive_fluents_.end(); ++it ) {
        if( (ins.given_stickies_.find(*it+1) == ins.given_stickies_.end()) && //) {
            (ins.observable_fluents_.find(*it) == ins.observable_fluents_.end()) ) {
            np_ns_effect.insert(-(1 + *it));
        }
    }

    // create actions for each tuple (o,q,a,q')
    for( map<index_set, int>::const_iterator it = reachable_obs_.begin(); it != reachable_obs_.end(); ++it ) {
        const index_set &obs = it->first;
        int obs_idx = it->second;
        for( size_t q = 0; q < fsc_states_; ++q ) {
            for( size_t k = 0; k < ins.n_actions(); ++k ) {
                const Action &act = *ins.actions_[k];
                for( size_t qp = 0; qp < fsc_states_; ++qp ) {

                    // create map actions if inconsistent tuples must be forbidden
                    size_t unused_fluent = obs_idx*fsc_states_ + q;
                    size_t mapped_fluent = obs_idx*fsc_states_*ins.n_actions()*fsc_states_ +
                                           q*ins.n_actions()*fsc_states_ + k*fsc_states_ + qp;
                    if( forbid_inconsistent_tuples_ ) {
                        string map_act_name = string("map_") + act.name_->to_string() + "_obs" + Utils::to_string(obs_idx) + "_q" + Utils::to_string(q) + "_q" + Utils::to_string(qp);
                        Action &map_act = new_action(new CopyName(map_act_name));
                        map_act.precondition_.insert(1 + unused0_+unused_fluent);
                        map_act.effect_.insert(-(1 + unused0_+unused_fluent));
                        map_act.effect_.insert(1 + mapped0_+mapped_fluent);
                    }

                    string app_act_name = string("app_") + act.name_->to_string() + "_obs" + Utils::to_string(obs_idx) + "_q" + Utils::to_string(q) + "_q" + Utils::to_string(qp);
                    Action &nact = new_action(new CopyName(app_act_name));

                    // the action has precondition if inconsistent tuples are forbidden
                    if( forbid_inconsistent_tuples_ ) {
                        nact.precondition_.insert(1 + mapped0_+mapped_fluent);
                    }

                    // unconditional effects of action
                    if( !act.effect_.empty() ) {
                        When base_c_eff;

                        // condition
                        base_c_eff.condition_.insert(1 + q0_+q);
                        base_c_eff.condition_.insert(obs.begin(), obs.end());

                        // effects
                        base_c_eff.effect_.insert(act.effect_.begin(), act.effect_.end());

                        // effects for non-primitive fluents for base conditional effect
                        base_c_eff.effect_.insert(np_ns_effect.begin(), np_ns_effect.end());

                        // effect for clearing observation
                        for( index_set::const_iterator it = obs.begin(); it != obs.end(); ++it )
                            base_c_eff.effect_.insert(-*it);

                        // effects for changing (FSC) state
                        if( q != qp ) {
                            base_c_eff.effect_.insert(-(1 + q0_+q));
                            base_c_eff.effect_.insert(1 + q0_+qp);
                        }
                        nact.when_.push_back(base_c_eff);
                    }

                    // conditional effects of action
                    for( size_t i = 0; i < act.when_.size(); ++i ) {
                        const When &w = act.when_[i];
                        if( consistent_with_obs(obs_idx, w.condition_) ) {
                            When c_eff;

                            // condition
                            c_eff.condition_.insert(1 + q0_+q);
                            c_eff.condition_.insert(obs.begin(), obs.end());
                            c_eff.condition_.insert(w.condition_.begin(), w.condition_.end());

                            // effects
                            c_eff.effect_.insert(w.effect_.begin(), w.effect_.end());
                            c_eff.effect_.insert(np_ns_effect.begin(), np_ns_effect.end());

                            // effect for clearing observation
                            for( index_set::const_iterator it = obs.begin(); it != obs.end(); ++it )
                                c_eff.effect_.insert(-*it);

                            // effects for changing (FSC) state
                            if( q != qp ) {
                                c_eff.effect_.insert(-(1 + q0_+q));
                                c_eff.effect_.insert(1 + q0_+qp);
                            }

                            // add conditional effect to new action
                            nact.when_.push_back(c_eff);
                        }
                    }
                }
            }
        }
    }

    // create ramification action
    Action &ramif = new_action(new CopyName("ramification"));
    for( size_t k = 0; k < ins.n_axioms(); ++k ) {
        Axiom &axiom = *ins.axioms_[k];
        When eff;
        eff.condition_ = axiom.body_;
        eff.effect_ = axiom.head_;
        ramif.when_.push_back(eff);
    }
}

CP_Instance::~CP_Instance() {
    for( StateSet::const_iterator it = initial_states_.begin(); it != initial_states_.end(); ++it )
        delete *it;

    for( map<const State*, const StateSet*>::iterator it = reachable_space_from_initial_state_.begin(); it != reachable_space_from_initial_state_.end(); ++it ) {
        for( StateSet::const_iterator jt = it->second->begin(); jt != it->second->end(); ++jt )
            delete *jt;
        delete it->second;
    }
}

void CP_Instance::add_to_initial_states(int fluent) {
    for( StateSet::iterator it = initial_states_.begin(); it != initial_states_.end(); ++it ) {
        const_cast<State*>(*it)->add(fluent);
    }
}

bool CP_Instance::consistent_with_obs(int obs_idx, const index_set &condition) const {
    int state_idx = 0;
    for( StateSet::const_iterator it = reachable_space_.begin(); it != reachable_space_.end(); ++it ) {
        // if state generates this observation, check condition in state
        if( (state_obs_[state_idx] == obs_idx) && (*it)->satisfy(condition) )
            return true;
        ++state_idx;
    }
    return false;
}

void CP_Instance::remove_atoms(const bool_vec &set, index_vec &map) {
    index_vec rm_map(atoms_.size());

    // mark atoms to remove and re-index
    size_t j = 0;
    for( size_t k = 0; k < atoms_.size(); ++k ) {
        if( !set[k] ) {
            rm_map[k] = j;
            ++j;
        } else {
            rm_map[k] = no_such_index;
        }
    }

    // remap atoms in initial states
    StateSet remaped_initial_states;
    StateSet remaped_reachable_space;
    std::map<const State*, const StateSet*> remaped_reachable_space_from_initial_state;
    for( StateSet::const_iterator it = initial_states_.begin(); it != initial_states_.end(); ++it ) {
        State *state = new State;
        (*it)->remap(*state, rm_map);
        remaped_initial_states.insert(state);
        //cout << "ISTATE:old = " << **it << endl;
        //cout << "ISTATE:new = " << *state << endl;

        // remap atoms in reachable space from initial state
        StateSet *space = new StateSet;
        std::map<const State*, const StateSet*>::const_iterator jt = reachable_space_from_initial_state_.find(*it);
        assert(jt != reachable_space_from_initial_state_.end());
        for( StateSet::const_iterator kt = jt->second->begin(); kt != jt->second->end(); ++kt ) {
            State *st = new State;
            (*kt)->remap(*st, rm_map);
            space->insert(st);
            //cout << "ISTATE:old = " << **kt << endl;
            //cout << "ISTATE:new = " << *st << endl;
        }

        remaped_reachable_space_from_initial_state.insert(make_pair(state, space));
        remaped_reachable_space.insert(space->begin(), space->end());
    }
    initial_states_ = remaped_initial_states;
    reachable_space_ = remaped_reachable_space;
    reachable_space_from_initial_state_ = remaped_reachable_space_from_initial_state;

    // calls Instance::remove_atoms() to finish the job!
    Instance::remove_atoms(set, map);

    // re-calculate reachable observations
    reachable_obs_.clear();
    state_obs_ = vector<int>(reachable_space_.size(), -1);
    int state_idx = 0;
    for( StateSet::const_iterator it = reachable_space_.begin(); it != reachable_space_.end(); ++it ) {
        index_set obs;
        for( index_set::const_iterator jt = instance_.observable_fluents_.begin(); jt != instance_.observable_fluents_.end(); ++jt ) {
            if( (*it)->satisfy(*jt) ) obs.insert(1 + *jt);
        }
        if( reachable_obs_.find(obs) == reachable_obs_.end() ) {
            // this is a new observation
            reachable_obs_.insert(make_pair(obs, (int)reachable_obs_.size()));
        }
        state_obs_[state_idx++] = reachable_obs_[obs];
    }

    /*
    cout << "# reachable obs = " << reachable_obs_.size() << endl;
    for( std::map<index_set, int>::const_iterator it = reachable_obs_.begin(); it != reachable_obs_.end(); ++it ) {
        for( std::map<index_set, int>::const_iterator jt = it; jt != reachable_obs_.end(); ++jt ) {
            if( (it != jt) && (it->first.contains(jt->first) || jt->first.contains(it->first)) ) {
                cout << Utils::warning() << "obs ";
                write_atom_set(cout, it->first);
                cout << " and ";
                write_atom_set(cout, jt->first);
                cout << " not disjunct. Translation may be invalid!" << endl;
            }
        }
        cout << "obs" << it->second << ":";
        for( index_set::const_iterator jt = it->first.begin(); jt != it->first.end(); ++jt )
            cout << " " << atoms[*jt-1]->name_;
        cout << endl;
    }
    */
}

