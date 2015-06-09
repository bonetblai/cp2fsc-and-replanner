#include <cassert>
#include <cstdlib>
#include "lw1_problem.h"
#include "lw1_state.h"
#include "utils.h"

using namespace std;

static int get_atom_index(const Instance &ins, string atom_name) {
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        if( atom_name == ins.atoms_[k]->name_->to_string() )
            return k;
    }
    cout << Utils::error() << "GET FAILED: name=" << atom_name << endl;
    return -1;
}

static void lw1_extend_effect_with_ramifications_on_observables(int affected_index,
                                                                const map<pair<int, int>, index_set> &beams_for_observable_atoms,
                                                                set<int> &effect) {
    for( map<pair<int, int>, index_set>::const_iterator it = beams_for_observable_atoms.begin(); it != beams_for_observable_atoms.end(); ++it) {
        //int var_index = it->first.first;
        int observable_index = it->first.second;
        const set<int> &beam = it->second;
        if( beam.find(affected_index) != beam.end() ) {
            effect.insert(-(1 + 2*observable_index));
            effect.insert(-(1 + 2*observable_index + 1));
        }
    }
}

void LW1_Instance::Variable::print(ostream &os) const {
    os << "Variable: name=" << name_
       << ", is-state-var=" << is_state_variable_
       << ", is-observable=" << is_observable_
       << ", domain={";
    for( set<int>::const_iterator it = domain_.begin(); it != domain_.end(); ++it )
        os << *it << ",";
    os << "}"
       << ", beams={";
    for( map<int, index_set>::const_iterator it = beams_.begin(); it != beams_.end(); ++it ) {
        os << it->first << "->{";
        for( index_set::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt )
            os << *jt << ",";
        os << "},";
    }
    os << "}";
}

LW1_Instance::LW1_Instance(const Instance &ins,
                           const PDDL_Base::variable_vec &variables,
                           const list<pair<const PDDL_Base::Action*, const PDDL_Base::Sensing*> > &sensing_models,
                           const map<string, set<string> > &accepted_literals_for_observables)
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

    // there should be no invariants
    if( !ins.init_.invariants_.empty() ) {
        cout << Utils::warning()
             << "LW1 problem has invariants; ignoring them..."
             << Utils::normal() << endl;
    }

    // create K0 atoms and special atoms
    normal_execution_atom_ = -1;
    atoms_.reserve(2*ins.n_atoms());
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        string name = ins.atoms_[k]->name_->to_string();
        //cout << "NAME=" << name << ": " << flush;
        if( name.compare(0, 16, "normal-execution") == 0 ) {
            assert(options_.is_enabled("lw1:aaai") || options_.is_enabled("lw1:boost:enable-post-actions"));
            new_atom(new CopyName(name));                  // even-numbered atoms
            new_atom(new CopyName(name + "_UNUSED"));      // odd-numbered atoms
            normal_execution_atom_ = k;
            //cout << "type=normal-execution, index=" << k << ", k-indices=" << 2*k << "," << 2*k+1 << endl;
        } else if( name.compare(0, 16, "last-action-was-") == 0 ) {
            assert(!options_.is_enabled("lw1:boost:enable-post-actions"));
            new_atom(new CopyName(name));                  // even-numbered atoms
            new_atom(new CopyName(name + "_UNUSED"));      // odd-numbered atoms
            last_action_atoms_.insert(k);
            //cout << "type=last-action, index=" << k << ", k-indices=" << 2*k << "," << 2*k+1 << endl;
        } else if( name.compare(0, 19, "enable-sensing-for-") == 0 ) {
            assert(options_.is_enabled("lw1:aaai") || options_.is_enabled("lw1:boost:enable-post-actions")); // CHECK
            new_atom(new CopyName(name));                  // even-numbered atoms
            new_atom(new CopyName(name + "_UNUSED"));      // odd-numbered atoms
            sensing_enabler_atoms_.insert(k);
            //cout << "type=enabler, index=" << k << ", k-indices=" << 2*k << "," << 2*k+1 << endl;
        } else {
            new_atom(new CopyName("K_" + name));           // even-numbered atoms
            new_atom(new CopyName("K_not_" + name));       // odd-numbered atoms
            //cout << "type=regular, index=" << k << ", k-indices=" << 2*k << "," << 2*k+1 << endl;
        }
    }

    // create (new-goal) atom
    new_goal_ = &new_atom(new CopyName("new-goal"));
    goal_literals_.insert(1 + new_goal_->index_);

    // extract variables
    variables_.reserve(variables.size());
    for( size_t k = 0; k < variables.size(); ++k ) {
        const PDDL_Base::Variable &var = *variables[k];

        set<int> domain;
        map<int, index_set> beams;
        int var_index = variables_.size();
        varmap_.insert(make_pair(var.to_string(false, true), var_index));

        for( PDDL_Base::unsigned_atom_set::const_iterator it = var.grounded_domain_.begin(); it != var.grounded_domain_.end(); ++it ) {
            assert(!it->negated_);
            string atom_name = it->to_string(false, true);
            int atom_index = get_atom_index(ins, atom_name);
            if( atom_index == -1 ) {
                cout << Utils::warning() << "no index for value '"
                     << var.print_name_ << ":" << atom_name
                     << "'. Continuing..." << endl;
                continue;
            } 

            // insert value into variable's domain
            domain.insert(atom_index);
            variables_for_atom_[atom_index].push_back(var_index);

            // fill beam for value
            if( var.is_observable_variable() ) {
                observable_atoms_.insert(atom_index);
                index_set beam;
                if( var.beam_.find(*it) == var.beam_.end() ) continue;
                const PDDL_Base::unsigned_atom_set &var_beam = var.beam_.find(*it)->second;
                for( PDDL_Base::unsigned_atom_set::const_iterator jt = var_beam.begin(); jt != var_beam.end(); ++jt ) {
                    int index = get_atom_index(ins, jt->to_string(jt->negated_, true));
                    assert(index != -1);
                    beam.insert(index);
                }
                beams_for_observable_atoms_[make_pair(var_index, atom_index)] = beam;
                beams[atom_index] = beam;
            }
        }
        variables_.push_back(new Variable(var.to_string(false, true), var.is_observable_variable(), var.is_state_variable(), domain, beams));
        //variables_.back()->print(cout); cout << endl;
    }

    // store accepted literals for observables
    if( options_.is_enabled("lw1:boost:literals-for-observables") ) {
        for( map<string, set<string> >::const_iterator it = accepted_literals_for_observables.begin(); it != accepted_literals_for_observables.end(); ++it ) {
            const string &var_name = it->first;
            assert(varmap_.find(var_name) != varmap_.end());
            for( set<string>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
                const string &value_name = *jt;
                if( value_name.substr(0, 4) != "not_" ) {
                    int index = get_atom_index(ins, value_name);
                    atoms_for_observables_[var_name].insert(index);
                    //cout << "Literals for observables: variable=" << var_name << ", value=" << value_name << ", index=" << index << endl;
                }
            }
        }
    }

    // extract sensing models into dnf and (complemented and into K-rules) cnf
    for( list<pair<const PDDL_Base::Action*, const PDDL_Base::Sensing*> >::const_iterator it = sensing_models.begin(); it != sensing_models.end(); ++it ) {
        const PDDL_Base::Action &action = *it->first;
        const PDDL_Base::Sensing &sensing = *it->second;
        for( size_t k = 0; k < sensing.size(); ++k ) {
            if( dynamic_cast<const PDDL_Base::SensingModelForObservableVariable*>(sensing[k]) != 0 ) {
                const PDDL_Base::SensingModelForObservableVariable &model = *static_cast<const PDDL_Base::SensingModelForObservableVariable*>(sensing[k]);
                assert(model.variable_ != 0);
                string var_name = model.variable_->to_string(false, true);
                assert(varmap_.find(var_name) != varmap_.end());
                int var_index = varmap_[var_name];
                string atom_name = model.literal_->to_string(model.literal_->negated_, true);
                int atom_index = get_atom_index(ins, atom_name);
                if( atom_index == -1 ) {
                    cout << Utils::warning() << "no index for value '"
                         << var_name << ":" << atom_name
                         << "'. Continuing..." << endl;
                    continue;
                }

                // setup keys for accessing data structures
                string action_key = action.print_name_;
                int var_key = var_index;
                int value_key = (model.literal_->negated_ ? -1 : 1) * (atom_index + 1);
                vars_sensed_by_action_[action_key].insert(var_key);

                assert(model.dnf_ != 0);
                if( dynamic_cast<const PDDL_Base::Or*>(model.dnf_) != 0 ) {
                    const PDDL_Base::Or &disjunction = *static_cast<const PDDL_Base::Or*>(model.dnf_);
                    //cout << "dnf is disjunction=" << disjunction << ":" << endl;
                    for( size_t j = 0; j < disjunction.size(); ++j ) {
                        assert(disjunction[j] != 0);

                        if( dynamic_cast<const PDDL_Base::And*>(disjunction[j]) != 0 ) {
                            const PDDL_Base::And &term = *static_cast<const PDDL_Base::And*>(disjunction[j]);
                            //cout << "  term is conjunction=" << term << ":" << endl;

                            // verify term
                            bool verified = true;
                            for( size_t i = 0; i < term.size(); ++i ) {
                                if( dynamic_cast<const PDDL_Base::Literal*>(term[i]) == 0 ) {
                                    cout << Utils::error() << "formula '" << *term[i]
                                         << "' for model of '" << var_name << ":" << atom_name
                                         << "' isn't a literal!" << endl;
                                    verified = false;
                                    break;
                                }
                            }
                            if( !verified ) continue;

                            // generate K-clauses
                            vector<int> term_for_dnf;
                            for( size_t i = 0; i < term.size(); ++i ) {
                                const PDDL_Base::Literal &head = *static_cast<const PDDL_Base::Literal*>(term[i]);
                                //cout << "  rule for head " << *(const PDDL_Base::Atom*)&head << ": " << flush;
                                string head_name = head.to_string(head.negated_, true);
                                int head_index = get_atom_index(ins, head_name);
                                assert(head_index != -1);
                                int k_head_index = 2*head_index + (head.negated_ ? 0 : 1);
                                term_for_dnf.push_back(head.negated_ ? -(1 + head_index) : 1 + head_index);
                                //cout << atoms_[k_head_index]->name_ << flush << " <==" << flush;

                                // fill clause
                                vector<int> k_clause(1, 1 + k_head_index);
                                for( size_t l = 0; l < term.size(); ++l ) {
                                    if( l == i ) continue;
                                    const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(term[l]);
                                    string name = literal.to_string(literal.negated_, true);
                                    int index = get_atom_index(ins, name);
                                    assert(index != -1);
                                    int k_index = 2*index + (literal.negated_ ? 1 : 0);
                                    //cout << " " << atoms_[k_index]->name_ << flush;
                                    k_clause.push_back(-(1 + k_index));
                                }
                                //cout << endl;

                                // insert clause
                                assert(k_clause.size() == term.size());
                                sensing_models_as_k_cnf_[action_key][var_key][value_key].push_back(k_clause);
                                //cout << "INSERT: k-clause="; LW1_State::print_clause(cout, k_clause, this); cout << endl;
                                //cout << "INSERT: model for action-key=" << action_key << ", var-key=" << var_key << ", value-key=" << value_key << endl;
                            }
                            sensing_models_as_dnf_[action_key][var_key][value_key].push_back(term_for_dnf);
                        } else if( dynamic_cast<const PDDL_Base::Literal*>(disjunction[j]) != 0 ) {
                            const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(disjunction[j]);
                            //cout << "  term is single literal=" << *(const PDDL_Base::Atom*)&literal << ": " << flush;
                            string name = literal.to_string(literal.negated_, true);
                            int index = get_atom_index(ins, name);
                            assert(index != -1);
                            int k_index = 2*index + (literal.negated_ ? 0 : 1);
                            //cout << atoms_[k_index]->name_ << " <== true" << endl;

                            // fill and insert unit-term
                            vector<int> unit_term;
                            unit_term.push_back(literal.negated_ ? -(1 + index) : 1 + index);
                            sensing_models_as_dnf_[action_key][var_key][value_key].push_back(unit_term);

                            // fill and insert unit K-clause
                            vector<int> unit_k_clause(1, 1 + k_index);
                            assert(unit_k_clause.size() == 1);
                            sensing_models_as_k_cnf_[action_key][var_key][value_key].push_back(unit_k_clause);
                            //cout << "INSERT: model for action-key=" << action_key << ", var-key=" << var_key << ", value-key=" << value_key << endl;
                        } else {
                            cout << Utils::error() << "formula '" << *disjunction[j]
                                 << "' for model of '" << var_name << ":" << atom_name
                                 << "' isn't a term!" << endl;
                            continue;
                        }
                    }
                } else if( dynamic_cast<const PDDL_Base::And*>(model.dnf_) != 0 ) {
                    const PDDL_Base::And &term = *static_cast<const PDDL_Base::And*>(model.dnf_);
                    //cout << "dnf is single term=" << term << ":" << endl;

                    // verify term
                    bool verified = true;
                    for( size_t j = 0; j < term.size(); ++j ) {
                        if( dynamic_cast<const PDDL_Base::Literal*>(term[j]) == 0 ) {
                            cout << Utils::error() << "formula '" << *term[j]
                                 << "' for model of '" << var_name << ":" << atom_name
                                 << "' isn't a literal!" << endl;
                            verified = false;
                            break;
                        }
                    }
                    if( !verified ) continue;

                    // generate K-clauses
                    vector<int> term_for_dnf;
                    for( size_t j = 0; j < term.size(); ++j ) {
                        const PDDL_Base::Literal &head = *static_cast<const PDDL_Base::Literal*>(term[j]);
                        //cout << "  rule for head " << *(const PDDL_Base::Atom*)&head << ": " << flush;
                        string head_name = head.to_string(head.negated_, true);
                        int head_index = get_atom_index(ins, head_name);
                        assert(head_index != -1);
                        int k_head_index = 2*head_index + (head.negated_ ? 0 : 1);
                        term_for_dnf.push_back(head.negated_ ? -(1 + head_index) : 1 + head_index);
                        //cout << atoms_[k_head_index]->name_ << flush << " <==" << flush;

                        // fill clause
                        vector<int> k_clause(1, 1 + k_head_index);
                        for( size_t i = 0; i < term.size(); ++i ) {
                            if( i == j ) continue;
                            const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(term[i]);
                            string name = literal.to_string(literal.negated_, true);
                            int index = get_atom_index(ins, name);
                            assert(index != -1);
                            int k_index = 2*index + (literal.negated_ ? 1 : 0);
                            //cout << " " << atoms_[k_index]->name_ << flush;
                            k_clause.push_back(-(1 + k_index));
                        }
                        //cout << endl;

                        // insert clause
                        assert(k_clause.size() == term.size());
                        sensing_models_as_k_cnf_[action_key][var_key][value_key].push_back(k_clause);
                        //cout << "INSERT: k-clause="; LW1_State::print_clause(cout, k_clause, this); cout << endl;
                        //cout << "INSERT: model for action-key=" << action_key << ", var-key=" << var_key << ", value-key=" << value_key << endl;
                    }
                    sensing_models_as_dnf_[action_key][var_key][value_key].push_back(term_for_dnf);
                } else if( dynamic_cast<const PDDL_Base::Literal*>(model.dnf_) != 0 ) {
                    const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(model.dnf_);
                    //cout << "dnf is single literal=" << *(const PDDL_Base::Atom*)&literal << ": " << flush;
                    string name = literal.to_string(literal.negated_, true);
                    int index = get_atom_index(ins, name);
                    assert(index != -1);
                    int k_index = 2*index + (literal.negated_ ? 0 : 1);
                    //cout << atoms_[k_index]->name_ << " <== true" << endl;

                    // fill and insert unit-term
                    vector<int> unit_term;
                    unit_term.push_back(literal.negated_ ? -(1 + index) : 1 + index);
                    sensing_models_as_dnf_[action_key][var_key][value_key].push_back(unit_term);

                    // fill and insert unit K-clause
                    vector<int> unit_k_clause(1, 1 + k_index);
                    assert(unit_k_clause.size() == 1);
                    sensing_models_as_k_cnf_[action_key][var_key][value_key].push_back(unit_k_clause);
                    //cout << "INSERT: model for action-key=" << action_key << ", var-key=" << var_key << ", value-key=" << value_key << endl;
                } else if( dynamic_cast<const PDDL_Base::Constant*>(model.dnf_) != 0 ) {
                    //cout << "dnf is constant: " << *model.dnf_ << endl;
                    // nothing to do. Obviate formula
                } else {
                    cout << Utils::error() << "formula '" << *model.dnf_
                         << "' for model of '" << var_name << ":" << atom_name
                         << "' isn't dnf!" << endl;
                    continue;
                }
            } else if( dynamic_cast<const PDDL_Base::SensingModelForStateVariable*>(sensing[k]) != 0 ) {
                const PDDL_Base::SensingModelForStateVariable &model = *static_cast<const PDDL_Base::SensingModelForStateVariable*>(sensing[k]);
                assert(model.variable_ != 0);
                string var_name = model.variable_->to_string(false, true);
                assert(varmap_.find(var_name) != varmap_.end());
                vars_sensed_by_action_[action.print_name_].insert(varmap_[var_name]);
            }
        }
    }

    // set initial atoms
    for( index_set::const_iterator it = ins.init_.literals_.begin(); it != ins.init_.literals_.end(); ++it ) {
        int index = *it > 0 ? *it-1 : -*it-1;
        init_.literals_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
    }

    // add known literals in initial situation
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        //const Atom &atom = *ins.atoms_[k];
        if( (init_.literals_.find(1 + 2*k) == init_.literals_.end()) &&
            (init_.literals_.find(1 + 2*k+1) == init_.literals_.end()) ) {
            cout << Utils::red()
                 << "XXXXXX COMPLETION OF INIT:"
                 << Utils::normal()
                 << " status=off, literal=";
            State::print_literal(cout, 1 + 2*k + 1, this);
            cout << endl; 
            //init_.literals_.insert(1 + 2*k+1);
            if( options_.is_enabled("kp:print:atom:init") ) {
                cout << "Atom " << atoms_[2*k+1]->name_ << " added to init" << endl;
            }
        }
    }

    // create K-actions
    remap_ = vector<int>(ins.n_actions(),-1);
    for( size_t k = 0; k < ins.n_actions(); ++k ) {
        const Action &act = *ins.actions_[k];
        if( act.name_->to_string().compare(0, 6, "drule-") != 0 )
            create_regular_action(act, k, observable_atoms_, beams_for_observable_atoms_);
    }

    // fix decision rules for variables
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

    // fix decision rules for atoms (only present with type3 drules for sensing)
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

    if( options_.is_enabled("lw1:inference:up") ) {
        // create fixed set of clauses (variable domain axioms) for UP inference
        for( size_t k = 0; k < variables_.size(); ++k ) {
            const Variable &var = *variables_[k];
            if( var.is_state_variable_ && !var.is_binary() ) {
                // for binary variables, nothing to add because all clauses are tautological
                const set<int> &domain = var.domain_;

                // for each value x, Kx <= [K-x_i for all i with x_i != x]
                for( set<int>::const_iterator it = domain.begin(); it != domain.end(); ++it ) {
                    vector<int> clause;
                    clause.reserve(domain.size());
                    clause.push_back(1 + 2**it);
                    for( set<int>::const_iterator jt = domain.begin(); jt != domain.end(); ++jt ) {
                        if( it != jt ) clause.push_back(-(1 + 2**jt+1));
                    }
                    clauses_for_axioms_.push_back(clause);
                    //cout << "CLAUSE0: "; LW1_State::print_clause(cout, clause, this); cout << endl;
                }

                // for each pair of values x and x', Kx => K-x'
                for( set<int>::const_iterator it = domain.begin(); it != domain.end(); ++it ) {
                    for( set<int>::const_iterator jt = it; jt != domain.end(); ++jt ) {
                        if( it != jt ) {
                            vector<int> clause;
                            clause.reserve(2);
                            clause.push_back(-(1 + 2**it));
                            clause.push_back(1 + 2**jt+1);
                            clauses_for_axioms_.push_back(clause);
                            //cout << "CLAUSE1: "; LW1_State::print_clause(cout, clause, this); cout << endl;
                        }
                    }
                }
            }
        }

        // create clauses for type5 sensing drules
        if( options_.is_enabled("lw1:boost:literals-for-observables") ) {
            for( size_t k = 0; k < ins.n_actions(); ++k ) {
                const Action &act = *ins.actions_[k];
                if( act.name_->to_string().compare(0, 20, "drule-sensing-type5-") == 0 ) {
                    assert(act.effect_.size() == 1);
                    assert(act.when_.empty());

                    vector<int> clause;
                    clause.reserve(act.precondition_.size() + 1);

                    // preconditions and effects
                    for( index_set::const_iterator it = act.precondition_.begin(); it != act.precondition_.end(); ++it ) {
                        int index = *it > 0 ? *it - 1 : -*it - 1;
                        clause.push_back(*it > 0 ? -(1 + 2*index) : -(1 + 2*index + 1));
                    }
                    int single_effect_index = *act.effect_.begin() > 0 ? *act.effect_.begin() - 1 : -*act.effect_.begin() - 1;
                    clause.push_back(*act.effect_.begin() > 0 ? 1 + 2*single_effect_index : 1 + 2*single_effect_index + 1);
                    clauses_for_axioms_.push_back(clause);
                    //cout << "CLAUSE2: "; LW1_State::print_clause(cout, clause, this); cout << endl;
                }
            }
        }

        // create clauses for type3 sensing drules
        if( options_.is_enabled("lw1:boost:drule:sensing:type3") ) {
            for( size_t k = 0; k < ins.n_actions(); ++k ) {
                const Action &act = *ins.actions_[k];
                if( (act.name_->to_string().compare(0, 11, "drule-atom-") == 0) ||
                    (act.name_->to_string().compare(0, 20, "drule-sensing-type3-") == 0) ) {

                    for( index_set::const_iterator it = act.effect_.begin(); it != act.effect_.end(); ++it ) {
                        vector<int> clause;
                        clause.reserve(1 + act.precondition_.size());

                        int index = *it > 0 ? *it - 1 : -*it - 1;
                        clause.push_back(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
                        for( index_set::const_iterator jt = act.precondition_.begin(); jt != act.precondition_.end(); ++jt ) {
                            int index = *jt > 0 ? *jt - 1 : -*jt - 1;
                            clause.push_back(*jt > 0 ? -(1 + 2*index) : -(1 + 2*index + 1));
                        }
                        clauses_for_axioms_.push_back(clause);
                        //cout << "CLAUSE3: "; LW1_State::print_clause(cout, clause, this); cout << endl;
                        //act.print(cout, ins);
                    }
                }
            }
        }

        // add K-tautological clauses Kp => -K-P and define set of
        // literals that forbid clauses to enter the augmented state
        if( options_.is_enabled("lw1:inference:up:enhanced") ) {
            assert(0); // CHECK: NEED TO FiX THIS

            // Need to correctly identify literals/clauses that can be added to state after
            // inference. Every state literal should be ok. For observable literals, only
            // those that are statically defined in a unique way unless dynamic option
            // is enabled. Clauses: only for static literals. No clause for dynamic
            // literals should be added

            // create K-tautological clauses
            for( size_t k = 0; k < ins.n_atoms(); ++k ) {
                vector<int> clause;
                clause.reserve(2);
                clause.push_back(-(1 + 2*k));
                clause.push_back(-(1 + 2*k + 1));
                clauses_for_axioms_.push_back(clause);
                //cout << "CLAUSE4: " << flush; LW1_State::print_clause(cout, clause, this); cout << endl;
            }

            // literals that forbid clauses to enter augmented state are observable
            // non-state literals defined by non-static sensing models
            for( size_t k = 0; k < variables_.size(); ++k ) {
                const Variable &var = *variables_[k];
                if( var.is_state_variable_ ) continue;
                for( set<int>::const_iterator it = var.domain_.begin(); it != var.domain_.end(); ++it ) {
                    int value = *it;
                    assert(var.beams_.find(value) != var.beams_.end());
                    const index_set &beam = var.beams_.find(value)->second;
                    if( !beam.empty() ) {
                        clause_forbidding_literals_.insert(1 + 2*value);
                        clause_forbidding_literals_.insert(1 + 2*value + 1);
                        cout << "Add clause-forbidding literal: ";
                        LW1_State::print_literal(cout, 1 + 2*value, this);
                        cout << " ";
                        LW1_State::print_literal(cout, 1 + 2*value + 1, this);
                        cout << endl;
                    }
                }
            }

            // literals from type3 sensing drules
            for( size_t k = 0; k < ins.n_actions(); ++k ) {
                const Action &act = *ins.actions_[k];
                if( act.name_->to_string().compare(0, 11, "drule-atom-") == 0 ) {
                    assert(act.effect_.size() == 1);
                    int literal = *act.effect_.begin();
                    assert(literal > 0);
                    --literal;
                    clause_forbidding_literals_.insert(1 + 2*literal);
                    clause_forbidding_literals_.insert(1 + 2*literal + 1);
                    cout << "Add clause-forbidding literal: ";
                    LW1_State::print_literal(cout, 1 + 2*literal, this);
                    cout << " ";
                    LW1_State::print_literal(cout, 1 + 2*literal + 1, this);
                    cout << endl;
                }
            }
        }
    }

    // cross reference instance to compute how many rules of each type
    cross_reference();
}

LW1_Instance::~LW1_Instance() {
}

bool LW1_Instance::is_forbidden(int literal) const {
    return clause_forbidding_literals_.find(literal) != clause_forbidding_literals_.end();
}

bool LW1_Instance::is_forbidden(const vector<int> &clause) const {
    for( size_t k = 0; k < clause.size(); ++k ) {
        if( clause_forbidding_literals_.find(clause[k]) != clause_forbidding_literals_.end() )
            return true;
        if( clause_forbidding_literals_.find(-clause[k]) != clause_forbidding_literals_.end() )
            return true;
    }
    return false;
}

void LW1_Instance::create_regular_action(const Action &action,
                                         int action_index,
                                         const index_set &observable_atoms,
                                         const map<pair<int, int>, index_set> &beams_for_observable_atoms) {
    string action_name = action.name_->to_string();
    assert(action_name.compare(0, 6, "drule-") != 0);

    // create new action
    Action &nact = new_action(new CopyName(action_name));
    remap_[action_index] = action_index;

    // preconditions
    for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( (normal_execution_atom_ != idx) &&
            (last_action_atoms_.find(idx) == last_action_atoms_.end()) &&
            (sensing_enabler_atoms_.find(idx) == sensing_enabler_atoms_.end()) ) {
            nact.precondition_.insert(*it > 0 ? 1 + 2*idx : 1 + 2*idx + 1);
        } else {
            nact.precondition_.insert(*it > 0 ? 1 + 2*idx : -(1 + 2*idx));
        }
    }

    // support and cancellation rules for unconditional effects
    for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( (normal_execution_atom_ != idx) &&
            (last_action_atoms_.find(idx) == last_action_atoms_.end()) &&
            (sensing_enabler_atoms_.find(idx) == sensing_enabler_atoms_.end()) ) {
            if( *it > 0 ) {
                nact.effect_.insert(1 + 2*idx);
                nact.effect_.insert(-(1 + 2*idx+1));
            } else {
                nact.effect_.insert(1 + 2*idx+1);
                nact.effect_.insert(-(1 + 2*idx));
            }
        } else {
            nact.effect_.insert(*it > 0 ? 1 + 2*idx : -(1 + 2*idx));
        }
        if( !options_.is_enabled("lw1:strict") || options_.is_enabled("lw1:boost:literals-for-observables:dynamic") ) {
            lw1_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, nact.effect_);
        }
    }

    // support and cancellation rules for conditional effects
    for( size_t i = 0; i < action.when_.size(); ++i ) {
        const When &when = action.when_[i];
        When sup_eff, can_eff;
        for( index_set::const_iterator it = when.condition_.begin(); it != when.condition_.end(); ++it ) {
            int idx = *it > 0 ? *it-1 : -*it-1;
            assert(normal_execution_atom_ != idx);
            assert(last_action_atoms_.find(idx) == last_action_atoms_.end());
            assert(sensing_enabler_atoms_.find(idx) == sensing_enabler_atoms_.end());
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
            assert(normal_execution_atom_ != idx);
            assert(last_action_atoms_.find(idx) == last_action_atoms_.end());
            assert(sensing_enabler_atoms_.find(idx) == sensing_enabler_atoms_.end());
            if( *it > 0 ) {
                sup_eff.effect_.insert(1 + 2*idx);
                if( observable_atoms.find(idx) == observable_atoms.end() )
                    can_eff.effect_.insert(-(1 + 2*idx+1));
            } else {
                sup_eff.effect_.insert(1 + 2*idx+1);
                if( observable_atoms.find(idx) == observable_atoms.end() )
                    can_eff.effect_.insert(-(1 + 2*idx));
            }
            if( !options_.is_enabled("lw1:strict") || options_.is_enabled("lw1:boost:literals-for-observables:dynamic") ) {
                lw1_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, sup_eff.effect_);
                lw1_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, can_eff.effect_);
            }
        }
        nact.when_.push_back(sup_eff);
        if( !can_eff.effect_.empty() ) nact.when_.push_back(can_eff);
    }

    if( options_.is_enabled("kp:print:action:regular") )
        nact.print(cout, *this);
}

void LW1_Instance::create_drule_for_var(const Action &action) {
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
        assert(action_name.compare(0, 16, "drule-var-type2-") == 0);
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

void LW1_Instance::create_drule_for_sensing(const Action &action) {
    string action_name = action.name_->to_string();
    if( options_.is_enabled("lw1:strict") ) {
        assert((action_name.compare(0, 20, "drule-sensing-type3-") == 0) || (action_name.compare(0, 19, "drule-sensing-type4") == 0) || (action_name.compare(0, 20, "drule-sensing-type5-") == 0));
        assert(options_.is_enabled("lw1:boost:literals-for-observables") || (action_name.compare(0, 20, "drule-sensing-type5-") != 0));
        assert(options_.is_enabled("lw1:boost:drule:sensing:type3") || (action_name.compare(0, 20, "drule-sensing-type3-") != 0));

        if( action_name.compare(0, 20, "drule-sensing-type3-") == 0 ) {
            Action *nact = new Action(new CopyName(action_name));
            for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
                int index = *it > 0 ? *it - 1 : -*it - 1;
                nact->precondition_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
            }
            for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
                int index = *it > 0 ? *it - 1 : -*it - 1;
                nact->effect_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
            }
            drule_store_.insert(DRTemplate(nact));
        } else if( action_name.compare(0, 25, "drule-sensing-type4state-") == 0 ) {
            Action *nact = new Action(new CopyName(action_name));

            assert(action.precondition_.size() == 1);
            assert(action.effect_.size() == 1);
            assert(action.when_.empty());

            // variable
            assert(action.comment_ != "");
            string var_name = action.comment_;
            assert(varmap_.find(var_name) != varmap_.end());
            int var_index = varmap_[var_name];
            const Variable &variable = *variables_[var_index];
            assert(variable.is_observable_);
            assert(variable.is_state_variable_);

            // index for precondition and effect
            assert(*action.precondition_.begin() > 0);
            int index_for_enabler = *action.precondition_.begin() - 1;
            int literal_for_value = *action.effect_.begin();
            int index_for_value = literal_for_value > 0 ? literal_for_value - 1 : -literal_for_value - 1;
            assert((literal_for_value > 0) || variable.is_binary());

            // precondition for sensing enabler
            if( options_.is_enabled("lw1:boost:enable-post-actions") ) {
                assert(sensing_enabler_atoms_.find(index_for_enabler) != sensing_enabler_atoms_.end());
                nact->precondition_.insert(1 + 2*index_for_enabler);
            } else {
                assert(last_action_atoms_.find(index_for_enabler) != last_action_atoms_.end());
                nact->precondition_.insert(1 + 2*index_for_enabler);
            }

            // other preconditions for action for literal KX=x
            //
            // For binary variable, -KX=x, -KX!=x
            // For non-binary variable, -KX!=x, -KX=x' for *all* values x' of X
            if( variable.is_binary() ) {
                nact->precondition_.insert(-(1 + 2*index_for_value));
                nact->precondition_.insert(-(1 + 2*index_for_value + 1));
            } else {
                nact->precondition_.insert(-(1 + 2*index_for_value + 1));
                for( set<int>::const_iterator it = variable.domain_.begin(); it != variable.domain_.end(); ++it )
                    nact->precondition_.insert(-(1 + 2**it));
            }

            // main effect: KX=x
            nact->effect_.insert(literal_for_value > 0 ? 1 + 2*index_for_value : 1 + 2*index_for_value + 1);

            // ramifications on other values of variable: for non-binary variables, KX!=x' for all values x' != x
            if( !variable.is_binary() && options_.is_enabled("lw1:boost:complete-effects:type4:state") )
                complete_effect(nact->effect_, literal_for_value, variable);

            //nact->print(cout, *this);
            drule_store_.insert(DRTemplate(nact));
        } else if( action_name.compare(0, 29, "drule-sensing-type4obs-boost-") == 0 ) {
            assert(!options_.is_enabled("lw1:boost:literals-for-observables"));
            assert(action.when_.empty());

            Action *nact = new Action(new CopyName(action_name));

            // obtain variable
            assert(action.comment_ != "");
            size_t blank_pos = action.comment_.find(" ");
            string var_name(action.comment_, 0, blank_pos);
            assert(varmap_.find(var_name) != varmap_.end());
            int var_index = varmap_[var_name];
            const Variable &variable = *variables_[var_index];
            string value_name(action.comment_, 1 + blank_pos);

            assert(variable.is_observable_);
            assert(!variable.is_state_variable_);

            // read preconditions
            vector<int> sensing_enablers;
            int index_for_last_action_atom = -1;
            vector<pair<int, int> > other_preconditions;
            for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
                int index = *it > 0 ? *it - 1 : -*it - 1;
                if( last_action_atoms_.find(index) != last_action_atoms_.end() ) {
                    assert(*it > 0);
                    index_for_last_action_atom = index;
                } else if( sensing_enabler_atoms_.find(index) != sensing_enabler_atoms_.end() ) {
                    assert(*it > 0);
                    sensing_enablers.push_back(index);
                } else {
                    other_preconditions.push_back(make_pair(*it, index));
                }
            }
            assert(!other_preconditions.empty());
            assert(other_preconditions.size() == action.effect_.size());

            // add as precondition the sensing enablers
            if( options_.is_enabled("lw1:boost:enable-post-actions") ) {
                assert(!sensing_enablers.empty());
                for( size_t k = 0; k < sensing_enablers.size(); ++k ) {
                    nact->precondition_.insert(1 + 2*sensing_enablers[k]);
                    nact->effect_.insert(-(1 + 2*sensing_enablers[k]));
                }
            } else {
                assert(index_for_last_action_atom != -1);
                nact->precondition_.insert(1 + 2*index_for_last_action_atom);
            }

            // add the other preconditions
            for( size_t k = 0; k < other_preconditions.size(); ++k ) {
                int literal = other_preconditions[k].first;
                int index = other_preconditions[k].second;
                nact->precondition_.insert(literal > 0 ? -(1 + 2*index) : -(1 + 2*index + 1));
            }

            // add the effects (unconditional)
            for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
                int index = *it > 0 ? *it - 1 : -*it - 1;
                nact->effect_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
            }

            //nact->print(cout, *this);
            drule_store_.insert(DRTemplate(nact));
        } else if( action_name.compare(0, 23, "drule-sensing-type4obs-") == 0 ) {
            Action *nact = new Action(new CopyName(action_name));
            assert(action.precondition_.size() == 1);

            // obtain variable
            assert(action.comment_ != "");
            size_t blank_pos = action.comment_.find(" ");
            string var_name(action.comment_, 0, blank_pos);
            assert(varmap_.find(var_name) != varmap_.end());
            int var_index = varmap_[var_name];
            const Variable &variable = *variables_[var_index];
            string value_name(action.comment_, 1 + blank_pos);

            assert(variable.is_observable_);
            assert(!variable.is_state_variable_);

            // precondition for sensing enablers
            vector<int> sensing_enablers;
            int index_for_last_action_atom = -1;
            for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
                int index = *it > 0 ? *it - 1 : -*it - 1;
                if( last_action_atoms_.find(index) != last_action_atoms_.end() ) {
                    assert(*it > 0);
                    index_for_last_action_atom = index;
                } else if( sensing_enabler_atoms_.find(index) != sensing_enabler_atoms_.end() ) {
                    assert(*it > 0);
                    sensing_enablers.push_back(index);
                } else {
                    assert(0);
                }
            }

            // add as precondition the sensing enablers
            if( options_.is_enabled("lw1:boost:enable-post-actions") ) {
                assert(!sensing_enablers.empty());
                for( size_t k = 0; k < sensing_enablers.size(); ++k ) {
                    nact->precondition_.insert(1 + 2*sensing_enablers[k]);
                    nact->effect_.insert(-(1 + 2*sensing_enablers[k]));
                }
            } else {
                assert(index_for_last_action_atom != -1);
                nact->precondition_.insert(1 + 2*index_for_last_action_atom);
            }

            // If lw1:boost:literals-for-observables is enabled, add the literal -KY!=y
            // when the sensed literal is Y=y or -KY=y when the sensed literal is Y!=y
            if( options_.is_enabled("lw1:boost:literals-for-observables") ) {
                assert(0); // index_for_value must be calculate when decoding comment
                //nact->precondition_.insert(literal_for_value > 0 ? -(1 + 2*index_for_value + 1) : -(1 + 2*index_for_value));
            }

            // if lw1:boost:literals-for-observables is enabled, add preconditions -KY=y' for *all*
            // values y' of sensed observable var Y. Special handling when Y is binary variable.
            if( options_.is_enabled("lw1:boost:literals-for-observables") ) {
                assert(0); // index_for_value must be calculate when decoding comment
                for( set<int>::const_iterator jt = variable.domain_.begin(); jt != variable.domain_.end(); ++jt ) {
                    //int index_for_value = *jt;
                    //assert(index_for_value >= 0);
                    //nact->precondition_.insert(-(1 + 2*index_for_value));
                }
                //if( variable.is_binary() ) nact->precondition_.insert(-(1 + 2*index_for_value + 1));
            }

            // effects for observable literals
            if( options_.is_enabled("lw1:boost:literals-for-observables") ) {
                assert(0); // index_for_value must be calculate when decoding comment
                //nact->effect_.insert(literal_for_value > 0 ? 1 + 2*index_for_value : 1 + 2*index_for_value + 1);
            }

            // each unconditional effect L becomes conditional of form: -K-L => KL
            for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
                int index = *it > 0 ? *it - 1 : -*it - 1;
                When w;
                w.condition_.insert(*it > 0 ? -(1 + 2*index + 1) : -(1 + 2*index));
                w.effect_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
                if( options_.is_enabled("lw1:boost:complete-effects:type4:obs") ) complete_effect(w.effect_, *it); // CHECK
                nact->when_.push_back(w);
            }

            // each conditional effect C => L becomes: KC, -K-L => KL
            for( size_t k = 0; k < action.when_.size(); ++k ) {
                const When &when = action.when_[k];
                assert(when.effect_.size() == 1);
                int head = *when.effect_.begin();
                int head_index = head > 0 ? head - 1 : -head - 1;
                When w;
                w.effect_.insert(head > 0 ? 1 + 2*head_index : 1 + 2*head_index + 1);
                w.condition_.insert(head > 0 ? -(1 + 2*head_index + 1) : -(1 + 2*head_index));
                for( index_set::const_iterator it = when.condition_.begin(); it != when.condition_.end(); ++it ) {
                    int index = *it > 0 ? *it - 1 : -*it - 1;
                    w.condition_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
                }
                if( options_.is_enabled("lw1:boost:complete-effects:type4:obs") ) complete_effect(w.effect_, head); // CHECK
                nact->when_.push_back(w);
            }

            //nact->print(cout, *this);
            drule_store_.insert(DRTemplate(nact));
        } else {
            // skip sensing drules of type5 as they are not passed to classical problem
            assert(action_name.compare(0, 20, "drule-sensing-type5-") == 0);
#if 0
            // CHECK: type5 rules make planner run slower for unknown reason
            Action *nact = new Action(new CopyName(action_name));
            for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
                int index = *it > 0 ? *it - 1 : -*it - 1;
                nact->precondition_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
            }
            for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
                int index = *it > 0 ? *it - 1 : -*it - 1;
                nact->effect_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
            }
            drule_store_.insert(DRTemplate(nact));
#endif
        }
    } else {
        assert(action_name.compare(0, 14, "drule-sensing-") == 0);
        Action *nact = new Action(new CopyName(action_name));
        for( index_set::const_iterator it = action.precondition_.begin(); it != action.precondition_.end(); ++it ) {
            int index = *it > 0 ? *it - 1 : -*it - 1;
            nact->precondition_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
        }
        for( index_set::const_iterator it = action.effect_.begin(); it != action.effect_.end(); ++it ) {
            int index = *it > 0 ? *it - 1 : -*it - 1;
            nact->effect_.insert(*it > 0 ? 1 + 2*index : 1 + 2*index + 1);
            nact->precondition_.insert(*it > 0 ? -(1 + 2*index + 1) : -(1 + 2*index)); // CHECK: is this necessary?
        }
        drule_store_.insert(DRTemplate(nact));
    }
}

void LW1_Instance::complete_effect(index_set &effect, int literal, const Variable &variable) const {
    assert(variable.is_state_variable_ && !variable.is_binary());
    int index = literal > 0 ? literal - 1 : -literal - 1;
    if( (literal > 0) && (variable.domain_.find(index) != variable.domain_.end()) ) {
        for( set<int>::const_iterator it = variable.domain_.begin(); it != variable.domain_.end(); ++it )
            if( index != *it ) effect.insert(1 + 2**it + 1);
    }
}

void LW1_Instance::complete_effect(index_set &effect, int literal) const {
    for( size_t k = 0; k < variables_.size(); ++k ) {
        const Variable &variable = *variables_[k];
        if( variable.is_state_variable_ && !variable.is_binary() ) complete_effect(effect, literal, variable);
    }
}

void LW1_Instance::create_drule_for_atom(const Action &action) {
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
    drule_store_.insert(DRTemplate(nact));
}

void LW1_Instance::create_sensor(const Sensor &sensor) {
    assert(!sensor.sense_.empty());
    assert(sensor.sense_.size() == 1);

    int sensed = *sensor.sense_.begin();
    int sensed_index = sensed > 0 ? sensed - 1 : -sensed - 1;

    int varid = -1;
    for( size_t k = 0; k < variables_.size(); ++k ) {
        const Variable &var = *variables_[k];
        if( var.domain_.find(sensed_index) != var.domain_.end() ) {
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
        const Variable &var = *variables_[varid];
        for( set<int>::const_iterator it = var.domain_.begin(); it != var.domain_.end(); ++it ) {
            if( *it != sensed_index ) nact.precondition_.insert(-(1 + 2**it));
        }
    }

    if( options_.is_enabled("kp:print:action:sensor") )
        nact.print(cout, *this);
}

void LW1_Instance::cross_reference() {
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

void LW1_Instance::set_goal_condition(index_set &condition) const {
    condition.clear();
    condition.insert(1 + new_goal_->index_);
}

void LW1_Instance::print_stats(ostream &os) const {
    os << "kp-instance: source=lw1-translation"
       << ", #standard-actions=" << n_standard_actions_
       << ", #sensor-actions=" << n_sensor_actions_
       << ", #drules-for-vars=" << n_drules_for_vars_
       << ", #drules-for-sensing=" << n_drules_for_sensing_
       << ", #drules-for-atoms=" << n_drules_for_atoms_
       << ", #subgoaling-actions=" << n_subgoaling_actions_
       << ", #clauses-for-axioms=" << clauses_for_axioms_.size();

    if( options_.is_enabled("lw1:boost:literals-for-observables" ) ) {
        int num_atoms_for_observables = 0;
        for( map<string, set<int> >::const_iterator it = atoms_for_observables_.begin(); it != atoms_for_observables_.end(); ++it )
            num_atoms_for_observables += it->second.size();
        os << ", #num-atoms-for-observables=" << num_atoms_for_observables;
    }

    os << endl;
}

