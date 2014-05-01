#include <cassert>
#include <cstdlib>
#include "mvv_problem.h"
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

MVV_Instance::MVV_Instance(const Instance &ins,
                           const PDDL_Base::variable_vec &multivalued_variables,
                           const list<const PDDL_Base::Effect*> &sensing_models,
                           const map<PDDL_Base::Atom, PDDL_Base::Atom> &sensing_enablers,
                           const map<PDDL_Base::Atom, set<PDDL_Base::unsigned_atom_set> > &pasive_sensors)
  : KP_Instance(ins.options_),
    n_standard_actions_(0),
    n_sensor_actions_(0),
    n_drule_actions_(0),
    n_drules_for_vars_(0),
    n_drules_for_sensing_models_(0),
    n_subgoaling_actions_(0),
    po_instance_(ins) {

    // set name
    if( dynamic_cast<const InstanceName*>(ins.name_) != 0 ) {
        set_name(new InstanceName(*dynamic_cast<const InstanceName*>(ins.name_)));
    } else {
        set_name(new CopyName(ins.name_->to_string()));
    }

    // extract multivalued variables
    set<int> observable_atoms;
    map<int, set<int> > beams_for_observable_atoms;
    multivalued_variables_.reserve(multivalued_variables.size());
    list<pair<string, set<int> > > multivalued_state_variables;
    list<pair<string, set<int> > > multivalued_observable_variables;;
    for( size_t k = 0; k < multivalued_variables.size(); ++k ) {
        const PDDL_Base::Variable &var = *multivalued_variables[k];
        set<int> values;
        for( PDDL_Base::unsigned_atom_set::const_iterator it = var.grounded_values_.begin(); it != var.grounded_values_.end(); ++it ) {
            assert(!it->negated_);
            string atom_name = it->to_string(false, true);
            int atom_index = get_atom_index(ins, atom_name);
            if( atom_index == -1 ) continue; 
            //if( atom_index == -1 ) cout << "ATOM: name=" << atom_name << endl;
            values.insert(atom_index);
            if( var.is_observable_variable() ) {
                //cout << "obs-variable: atom=" << *it << ", name=" << atom_name << ", index=" << atom_index << endl;
                observable_atoms.insert(atom_index);
                set<int> beam;
                assert(var.beam_.find(*it) != var.beam_.end());
                const PDDL_Base::unsigned_atom_set &var_beam = var.beam_.find(*it)->second;
                for( PDDL_Base::unsigned_atom_set::const_iterator jt = var_beam.begin(); jt != var_beam.end(); ++jt ) {
                    int index = get_atom_index(ins, jt->to_string(jt->negated_, true));
                    assert(index != -1);
                    if( index != -1 ) beam.insert(index);
                }
                beams_for_observable_atoms[atom_index] = beam;
            }
        }

        if( var.is_state_variable() && !var.is_observable_variable() ) {
            multivalued_variables_.push_back(make_pair(var.print_name_, values));
            multivalued_state_variables.push_back(make_pair(var.print_name_, values));
        } else {
            multivalued_variables_.push_back(make_pair(var.print_name_, values));
            multivalued_observable_variables.push_back(make_pair(var.print_name_, values));
        }
    }

    // extract sensing models
    // first: linearize sensing models
cout << "#INPUT SMS=" << sensing_models.size() << endl;
    list<const PDDL_Base::Effect*> linearization;
    for( list<const PDDL_Base::Effect*>::const_iterator it = sensing_models.begin(); it != sensing_models.end(); ++it ) {
        //cout << "PROCESSING: sm=" << **it << endl;
        if( dynamic_cast<const PDDL_Base::AndEffect*>(*it) != 0 ) {
            const PDDL_Base::AndEffect &conjunction = *static_cast<const PDDL_Base::AndEffect*>(*it);
            for( size_t k = 0; k < conjunction.size(); ++k ) {
                if( dynamic_cast<const PDDL_Base::ConditionalEffect*>(conjunction[k]) != 0 ) {
//cout << "PUSHING: sm=" << *conjunction[k] << endl;
                    linearization.push_back(conjunction[k]);
                } else {
                    assert(dynamic_cast<const PDDL_Base::AtomicEffect*>(conjunction[k]) != 0);
                    // nothing to do: see below
                }
            }
        } else if( dynamic_cast<const PDDL_Base::ConditionalEffect*>(*it) != 0 ) {
//cout << "PUSHING: sm=" << **it << endl;
            linearization.push_back(*it);
        } else if( dynamic_cast<const PDDL_Base::AtomicEffect*>(*it) != 0 ) {
            // we only need to generate a simple sensor. This is done below and there
            // there is no need to insert this model into linearization
        } else {
            cout << Utils::error() << "unexpected sensing model when computing linearization" << Utils::normal() << endl;
        }
    }

    // second extract sensing models
    for( list<const PDDL_Base::Effect*>::const_iterator it = linearization.begin(); it != linearization.end(); ++it ) {
        assert(dynamic_cast<const PDDL_Base::AndEffect*>(*it) == 0);
        if( dynamic_cast<const PDDL_Base::ConditionalEffect*>(*it) != 0 ) {
//cout << "EXTRACTING: sm=" << **it << endl;
            const PDDL_Base::ConditionalEffect &conditional = *static_cast<const PDDL_Base::ConditionalEffect*>(*it);
            assert(dynamic_cast<const PDDL_Base::AtomicEffect*>(conditional.effect_) != 0);
            const PDDL_Base::AtomicEffect &head = *static_cast<const PDDL_Base::AtomicEffect*>(conditional.effect_);
            string head_name = static_cast<const PDDL_Base::Atom&>(head).to_string(head.negated_, true);
            int head_index = get_atom_index(ins, head_name);
            assert(head_index != -1);

            set<int> term;
            if( dynamic_cast<const PDDL_Base::Literal*>(conditional.condition_) != 0 ) {
                const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(conditional.condition_);
                string literal_name = literal.to_string(literal.negated_, true);
                int literal_index = get_atom_index(ins, literal_name);
if( literal_index == -1 ) cout << "1: literal=" << (PDDL_Base::Atom&)literal << ", name=" << literal_name << endl;
                if( literal_index == -1 ) {
                    if( !literal.negated_ ) continue;
                } else {
                    term.insert(literal.negated_ ? -(1 + literal_index) : 1 + literal_index);
                }
            } else if( dynamic_cast<const PDDL_Base::And*>(conditional.condition_) != 0 ) {
                const PDDL_Base::And &conjunction = *static_cast<const PDDL_Base::And*>(conditional.condition_);
                bool skip_term = false;
                for( size_t k = 0; !skip_term && (k < conjunction.size()); ++k ) {
                    assert(dynamic_cast<const PDDL_Base::Literal*>(conjunction[k]) != 0);
                    const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(conjunction[k]);
                    string literal_name = literal.to_string(literal.negated_, true);
                    int literal_index = get_atom_index(ins, literal_name);
if( literal_index == -1 ) cout << "2: literal=" << (PDDL_Base::Atom&)literal << ", name=" << literal_name << endl;
                    if( literal_index == -1 ) {
                        skip_term = !literal.negated_;
                        continue;
                    }
                    assert(literal_index != -1);
                    term.insert(literal.negated_ ? -(1 + literal_index) : 1 + literal_index);
                }
                if( skip_term ) { cout << "SKIP" << endl; continue; }
            } else {
                cout << Utils::error() << "unexpected condition in sensing model: " << *conditional.condition_ << Utils::normal() << endl;
            }
            sensing_models_[head.negated_ ? -(1 + head_index) : 1 + head_index].insert(term);
        } else {
            cout << Utils::error() << "unexpected sensing model: " << **it << Utils::normal() << endl;
        }
    }

    // create K0 atoms
    atoms_.reserve(2*ins.n_atoms());
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        string name = ins.atoms_[k]->name_->to_string();
        new_atom(new CopyName("(K_" + name + ")"));      // even-numbered atoms
        new_atom(new CopyName("(K_not_" + name + ")"));  // odd-numbered atoms
    }

    // set initial atoms
    cout << "num=" << ins.init_.literals_.size() << endl;
    for( index_set::const_iterator it = ins.init_.literals_.begin(); it != ins.init_.literals_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 ) {
            cout << "Adding +" << ins.atoms_[idx]->name_ << endl;
            init_.literals_.insert(1 + 2*idx);
        } else {
            cout << "Adding -" << ins.atoms_[idx]->name_ << endl;
            init_.literals_.insert(1 + 2*idx+1);
        }
    }
    cout << "num=" << init_.literals_.size() << endl;

    // add known literals in initial situation
size_t BLAI = 0;
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
cout << "XXXXXX COMPLETION OF INIT is on!" << endl;
                //if( BLAI++ < 12 ) init_.literals_.insert(1 + 2*k+1);
                init_.literals_.insert(1 + 2*k+1);
                if( true || options_.is_enabled("kp:print:atom:init") ) {
                    cout << "Atom " << atoms_[2*k+1]->name_ << " added to init" << endl;
                }
            }
        }
    }
    cout << "num=" << init_.literals_.size() << endl;

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

        if( options_.is_enabled("kp:print:action:regular") )
            nact.print(cout, *this);
    }

    // create sensor rules. First, compute set of sensed atoms and enablers for sensing
    // for non-static observables (pasive sensors)
    set<int> sensed_atoms; 
    cout << "NUM SMS-1=" << sensing_models.size() << endl;
    for( list<const PDDL_Base::Effect*>::const_iterator it = sensing_models.begin(); it != sensing_models.end(); ++it ) {
        //cout << "PROCESSING: sm=" << **it << endl;
        PDDL_Base::unsigned_atom_set sensed_literals;
        (*it)->extract_atoms(sensed_literals, true);
        for( PDDL_Base::unsigned_atom_set::const_iterator jt = sensed_literals.begin(); jt != sensed_literals.end(); ++jt ) {
            cout << "Sensed: literal=" << *jt << ", sensing=" << flush;
            assert(0);if(true) {//BLAIif( pasive_sensors.find(*jt) == pasive_sensors.end() ) {
                cout << "ACTIVE" << endl;
                const PDDL_Base::Atom &sensed_literal = *jt;
                string sensed_name = sensed_literal.to_string(sensed_literal.negated_, true);
                int sensed_index = get_atom_index(ins, sensed_name);
                assert(sensed_index != -1);
cout << "INSERTING-1: " << sensed_index << "=" << ins.atoms_[sensed_index]->name_ << endl;
                sensed_atoms.insert(sensed_index);
                map<PDDL_Base::Atom, PDDL_Base::Atom>::const_iterator kt;assert(0);//BLAI = sensing_enablers.find(sensed_literal);
                assert(kt != sensing_enablers.end());
                const PDDL_Base::Atom &literal = kt->second;
                assert(!literal.negated_);
                string literal_name = literal.to_string(false, true);
                int literal_index = get_atom_index(ins, literal_name);
                assert(literal_index != -1);

                set<int> enabler;
                enabler.insert(1 + literal_index);
                enablers_for_sensing_[sensed_index].insert(enabler);
            } else {
                cout << "PASIVE" << endl;
            }
        }
    }

    // Second, compute sensed atoms and enablers for static observables
    cout << "NUM SMS-2=" << pasive_sensors.size() << endl;
    for( map<PDDL_Base::Atom, set<PDDL_Base::unsigned_atom_set> >::const_iterator it = pasive_sensors.begin(); it != pasive_sensors.end(); ++it ) {
        const PDDL_Base::Atom &sensed_atom = it->first;
        const set<PDDL_Base::unsigned_atom_set> &post_conditions = it->second;

        string sensed_name = sensed_atom.to_string(sensed_atom.negated_, true);
        int sensed_index = get_atom_index(ins, sensed_name);
        assert(sensed_index != -1);
cout << "INSERTING-2: " << sensed_index << "=" << ins.atoms_[sensed_index]->name_ << endl;
        sensed_atoms.insert(sensed_index);
        cout << "Creating sensors for static observable " << sensed_name << endl;

        // create enablers
        assert(!post_conditions.empty());
        for( set<PDDL_Base::unsigned_atom_set>::const_iterator jt = post_conditions.begin(); jt != post_conditions.end(); ++jt ) {
            if( jt->size() > 2 ) continue; // THIS HACK SHOULD BE RESOLVED WHEN FIXING test_on_actions....
            cout << "    post-condition=" << *jt << endl;
            set<int> enabler;
            for( PDDL_Base::unsigned_atom_set::const_iterator kt = jt->begin(); kt != jt->end(); ++kt ) {
                const PDDL_Base::Atom &literal = *kt;
                string literal_name = literal.to_string(literal.negated_, true);
                int literal_index = get_atom_index(ins, literal_name);
                assert(literal_index != -1);
                enabler.insert(literal.negated_ ? -(1 + literal_index) : 1 + literal_index);
            }
            enablers_for_sensing_[sensed_index].insert(enabler);
        }
    }

    // Third, for each sensed atom, create sensor with respect to its variable
    for( set<int>::const_iterator it = sensed_atoms.begin(); it != sensed_atoms.end(); ++it ) {
        create_sensor(*it);
    }

    // create invariants for multivalued variables
    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        const pair<string, set<int> > &var = multivalued_variables_[k];
        const string &var_name = var.first;
        const set<int> &var_values = var.second;
        if( var_values.size() == 1 ) continue;

        size_t i = 0;
        for( set<int>::const_iterator it = var_values.begin(); it != var_values.end(); ++it, ++i ) {
            ostringstream s;
            s << "drule-var-" << var_name << "-type1-" << i;
            Action &nact = new_action(new CopyName(s.str()));
            for( set<int>::const_iterator jt = var_values.begin(); jt != var_values.end(); ++jt ) {
                if( jt != it ) {
                    nact.precondition_.insert(1 + 2**jt + 1); 
                } else {
                    nact.precondition_.insert(-(1 + 2**jt + 1)); 
                    nact.effect_.insert(1 + 2**jt);
                }
            }

            if( options_.is_enabled("mvv:print:drule:var") || options_.is_enabled("mvv:print:drule") )
                nact.print(cout, *this);
        }

        i = 0;
        for( set<int>::const_iterator it = var_values.begin(); it != var_values.end(); ++it, ++i ) {
            ostringstream s;
            s << "drule-var-" << var_name << "-type2-" << i;
            Action &nact = new_action(new CopyName(s.str()));
            for( set<int>::const_iterator jt = var_values.begin(); jt != var_values.end(); ++jt ) {
                if( jt != it ) {
                    When effect;
                    effect.condition_.insert(-(1 + 2**jt));
                    effect.effect_.insert(1 + 2**jt + 1);
                    nact.when_.push_back(effect);
                }
                else {
                    nact.precondition_.insert(1 + 2**jt);
                }
            }

            if( options_.is_enabled("mvv:drule:var") || options_.is_enabled("mvv:print:drule") )
                nact.print(cout, *this);
        }

    }

    // create invariants for sensing models. First, generate invariants and
    // store them before inserting the actions in the problem. Later, merge
    // invariants with same precondition.
    multimap<index_set, const Action*> invariant_store;
    for( map<int, set<set<int> > >::const_iterator sm = sensing_models_.begin(); sm != sensing_models_.end(); ++sm ) {
        int obs = sm->first;
        int obs_index = obs > 0 ? obs - 1 : -obs - 1;
        string obs_name = (obs > 0 ? "" : "not_") + ins.atoms_[obs_index]->name_->to_string();
        const set<set<int> > &dnf = sm->second;
        size_t type1_num = 0;
        for( set<set<int> >::const_iterator term = dnf.begin(); term != dnf.end(); ++term, ++type1_num ) {

            // if empty term, sensed obs can be added to init as we know
            // it will be always true
            if( term->empty() ) {
                cout << "XXXXXX ADDING literal=" << obs_name << " to init" << endl;
                init_.literals_.insert(obs > 0 ? 1 + 2*obs : 1 + 2*obs + 1);
                break;
            }

            // type1 invariants: C -> sensed-literal
            ostringstream s;
            s << "drule-sensing-" << obs_name << "-type1-" << type1_num;
            Action *nact = new Action(new CopyName(s.str()));
            for( set<int>::const_iterator it = term->begin(); it != term->end(); ++it ) {
                int index = *it > 0 ? *it - 1 : -*it - 1;
                nact->precondition_.insert(1 + (*it > 0 ? 2*index : 2*index + 1));
            }
            nact->effect_.insert(1 + (obs > 0 ? 2*obs_index : 2*obs_index + 1));
            invariant_store.insert(make_pair(nact->precondition_, nact));

            // type2 invariants: -sensed-literal, C' -> K-L   where  C = {C', L}
            size_t type2_num = 0;
            for( set<int>::const_iterator it = term->begin(); it != term->end(); ++it, ++type2_num ) {
                int head = *it;
                int head_index = head > 0 ? head - 1 : -head - 1;
                string head_name = ins.atoms_[head_index]->name_->to_string();
                ostringstream s;
                s << "drule-sensing-" << obs_name << "-type2-" << type1_num << "-" << type2_num;
                Action *nact = new Action(new CopyName(s.str()));
                //nact->precondition_.insert(-(1 + (head > 0 ? 2*head_index : 2*head_index + 1)));
                for( set<int>::const_iterator jt = term->begin(); jt != term->end(); ++jt ) {
                    int index = *jt > 0 ? *jt - 1 : -*jt - 1;
                    if( jt != it )
                        nact->precondition_.insert(1 + (*jt > 0 ? 2*index : 2*index + 1));
                    else
                        nact->effect_.insert(1 + (*jt > 0 ? 2*index + 1 : 2*index));
                }
                nact->precondition_.insert(1 + (obs > 0 ? 2*obs_index + 1 : 2*obs_index));
                invariant_store.insert(make_pair(nact->precondition_, nact));
            }
        }
    }

    // Move invariants from store into problem, merging those with same precondition
    multimap<index_set, const Action*>::key_compare comparator = invariant_store.key_comp();
    for( multimap<index_set, const Action*>::const_iterator it = invariant_store.begin(); it != invariant_store.end(); ) {
        const Action &invariant = *it->second;
        Action &nact = new_action(new CopyName(invariant.name_->to_string()));
        nact.precondition_ = invariant.precondition_;
        nact.effect_ = invariant.effect_;
        nact.when_ = invariant.when_;
        nact.cost_ = invariant.cost_;
        nact.comment_ = invariant.comment_;
        delete it->second;
        if( ++it == invariant_store.end() ) {
            if( options_.is_enabled("mvv:print:drule:sensing") || options_.is_enabled("mvv:print:drule") )
                nact.print(cout, *this);
            break;
        }

        if( options_.is_enabled("kp:merge-invariants") ) {
            if( !comparator(nact.precondition_, it->first) ) nact.comment_ = "<merge>";
            set<When> included_when_effects;
            included_when_effects.insert(nact.when_.begin(), nact.when_.end());
            while( !comparator(nact.precondition_, it->first) ) {
                assert(it != invariant_store.end());
                nact.effect_.insert(it->second->effect_.begin(), it->second->effect_.end());
                nact.when_.insert(nact.when_.end(), it->second->when_.begin(), it->second->when_.end());
                delete it->second;
                if( ++it == invariant_store.end() ) break;
            }
        }

        if( options_.is_enabled("mvv:print:drule:sensing") || options_.is_enabled("mvv:print:drule") )
            nact.print(cout, *this);
    }

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

    // cross reference instance to compute how rules of each type
    cross_reference();
    print_stats(cout);
}

void MVV_Instance::create_sensor(int sensed_index) {
    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        const pair<string, set<int> > &var = multivalued_variables_[k];
        if( var.second.find(sensed_index) != var.second.end() ) {
            if( false ) { //&& !var.is_observable() ) 
                cout << Utils::error() << "variable " << var.first
                     << " isn't observable but its value v" << sensed_index << " is sensed"
                     << Utils::normal() << endl;
                continue;
            }

            // fetch enablers for sensing
            map<int, set<set<int> > >::const_iterator it = enablers_for_sensing_.find(sensed_index);
            assert(it != enablers_for_sensing_.end());
            const set<set<int> > &enablers = it->second;
            assert(!enablers.empty());

            // create sensor for each enabler
            size_t enabler_id = 0;
            for( set<set<int> >::const_iterator it = enablers.begin(); it != enablers.end(); ++it, ++enabler_id) {
                const set<int> &enabler = *it;

                ostringstream s;
                if( enablers.size() == 1 )
                    s << "sensor-for-" << var.first << "-v" << sensed_index;
                else
                    s << "sensor-for-" << var.first << "-v" << sensed_index << "-enabler-" << enabler_id;

                Action &nact = new_action(new CopyName(s.str() + "-true"));

                // precondition of sensor is enabler plus conditions on other values of sensor
                for( set<int>::const_iterator jt = enabler.begin(); jt != enabler.end(); ++jt ) {
                    int literal = *jt, index = literal > 0 ? literal - 1 : -literal - 1;
                    nact.precondition_.insert(literal > 0 ? 1 + 2*index : 1 + 2*index + 1);
                }
                nact.precondition_.insert(-(1 + 2*sensed_index + 1));
                for( set<int>::const_iterator jt = var.second.begin(); jt != var.second.end(); ++jt ) {
                    if( *jt != sensed_index ) nact.precondition_.insert(-(1 + 2**jt));
                }

                // effect of sensor is to set value to true
                nact.effect_.insert(1 + 2*sensed_index);

                if( options_.is_enabled("mvv:print:sensors") )
                    nact.print(cout, *this);

                // if this is a singleton variable, create a copy that sets values to false
                if( var.second.size() == 1 ) {
                    Action &nact = new_action(new CopyName(s.str() + "-false"));
                    for( set<int>::const_iterator jt = enabler.begin(); jt != enabler.end(); ++jt ) {
                        int literal = *jt, index = literal > 0 ? literal - 1 : -literal - 1;
                        nact.precondition_.insert(literal > 0 ? 1 + 2*index : 1 + 2*index + 1);
                    }
                    nact.precondition_.insert(-(1 + 2*sensed_index));
                    nact.effect_.insert(1 + 2*sensed_index + 1);

                    if( options_.is_enabled("mvv:print:sensors") )
                        nact.print(cout, *this);
                }
            }
        }
    }
}

MVV_Instance::~MVV_Instance() {
}

void MVV_Instance::cross_reference() {
    n_standard_actions_ = 0;
    n_sensor_actions_ = 0;
    n_drule_actions_ = 0;
    n_drules_for_vars_ = 0;
    n_drules_for_sensing_models_ = 0;
    n_subgoaling_actions_ = 0;
    for( size_t k = 0; k < n_actions(); ++k ) cout << actions_[k]->name_->to_string() << endl;

    size_t k = 0;
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 7, "sensor-") == 0) ||
            (aname.compare(0, 6, "drule-") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_standard_actions_ = k;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 6, "drule-") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_sensor_actions_ = k - n_standard_actions_;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname.compare(0, 8, "drule-sensing") == 0) ||
            (aname == "reach_new_goal_through_original_goal__") ) {
            n_drules_for_vars_ = k - n_standard_actions_ - n_sensor_actions_;
            break;
        }
        ++k;
    }
    while( k < n_actions() ) {
        string aname = actions_[k]->name_->to_string();
        if( (aname == "reach_new_goal_through_original_goal__") ) {
            n_drules_for_sensing_models_ = k - n_standard_actions_ - n_sensor_actions_ - n_drules_for_vars_;
            n_drule_actions_ = k - n_standard_actions_ - n_sensor_actions_;
            assert(n_drule_actions_ == n_drules_for_vars_ + n_drules_for_sensing_models_);
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

void MVV_Instance::set_goal_condition(index_set &condition) const {
    condition.clear();
    condition.insert(1 + new_goal_->index_);
}

void MVV_Instance::print_stats(ostream &os) const {
    os << "kp-instance: source=mvv-translation"
       << ", #standard-actions=" << n_standard_actions_
       << ", #sensor-actions=" << n_sensor_actions_
       << ", #dules-for-vars=" << n_drules_for_vars_
       << ", #dules-for-sensing-models=" << n_drules_for_sensing_models_
       << ", #subgoaling-actions=" << n_subgoaling_actions_
       << endl;
}

