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

static void lw1_extend_effect_with_ramifications_on_observables(int index,
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
                           const PDDL_Base::variable_vec &multivalued_variables,
                           const std::list<std::pair<const PDDL_Base::Action*, const PDDL_Base::Sensing*> > &sensing_models)
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

    // create K0 atoms
    atoms_.reserve(2*ins.n_atoms());
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        string name = ins.atoms_[k]->name_->to_string();
        new_atom(new CopyName("(K_" + name + ")"));      // even-numbered atoms
        new_atom(new CopyName("(K_not_" + name + ")"));  // odd-numbered atoms
    }

    // extract multivalued variables
    multivalued_variables_.reserve(multivalued_variables.size());
    for( size_t k = 0; k < multivalued_variables.size(); ++k ) {
        const PDDL_Base::Variable &var = *multivalued_variables[k];

        set<int> domain;
        map<int, index_set> beams;
        int var_index = multivalued_variables_.size();
        varmap_.insert(make_pair(var.print_name_, var_index));

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
                beams_for_observable_atoms_[atom_index] = beam;
                beams[atom_index] = beam;
            }
        }
        multivalued_variables_.push_back(new Variable(var.print_name_, var.is_observable_variable(), var.is_state_variable(), domain, beams));
        //multivalued_variables_.back()->print(cout); cout << endl;
    }

    // extract sensing models
    for( list<pair<const PDDL_Base::Action*, const PDDL_Base::Sensing*> >::const_iterator it = sensing_models.begin(); it != sensing_models.end(); ++it ) {
        const PDDL_Base::Action &action = *it->first;
        const PDDL_Base::Sensing &sensing = *it->second;
        for( size_t k = 0; k < sensing.size(); ++k ) {
            if( dynamic_cast<const PDDL_Base::SensingModelForObservableVariable*>(sensing[k]) != 0 ) {
                const PDDL_Base::SensingModelForObservableVariable &model = *static_cast<const PDDL_Base::SensingModelForObservableVariable*>(sensing[k]);
                assert(model.variable_ != 0);
                string var_name = model.variable_->print_name_;
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

                            // generate K clauses
                            for( size_t i = 0; i < term.size(); ++i ) {
                                const PDDL_Base::Literal &head = *static_cast<const PDDL_Base::Literal*>(term[i]);
                                //cout << "  rule for head " << *(const PDDL_Base::Atom*)&head << ": " << flush;
                                string head_name = head.to_string(head.negated_, true);
                                int head_index = get_atom_index(ins, head_name);
                                assert(head_index != -1);
                                int k_head_index = 2*head_index + (head.negated_ ? 0 : 1);
                                //cout << atoms_[k_head_index]->name_ << flush << " <==" << flush;

                                // fill clause
                                vector<int> clause(1, 1 + k_head_index);
                                for( size_t l = 0; l < term.size(); ++l ) {
                                    if( l == i ) continue;
                                    const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(term[l]);
                                    string name = literal.to_string(literal.negated_, true);
                                    int index = get_atom_index(ins, name);
                                    assert(index != -1);
                                    int k_index = 2*index + (literal.negated_ ? 1 : 0);
                                    //cout << " " << atoms_[k_index]->name_ << flush;
                                    clause.push_back(-(1 + k_index));
                                }
                                //cout << endl;

                                // insert clause
                                assert(clause.size() == term.size());
                                sensing_models_[action_key][var_key][value_key].push_back(clause);
                                //cout << "INSERT: clause="; LW1_State::print_clause(cout, clause, this); cout << endl;
                                //cout << "INSERT: model for action-key=" << action_key << ", var-key=" << var_key << ", value-key=" << value_key << endl;
                                //assert(0);
                            }
                        } else if( dynamic_cast<const PDDL_Base::Literal*>(disjunction[j]) != 0 ) {
                            const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(disjunction[j]);
                            //cout << "  term is single literal=" << *(const PDDL_Base::Atom*)&literal << ": " << flush;
                            string name = literal.to_string(literal.negated_, true);
                            int index = get_atom_index(ins, name);
                            assert(index != -1);
                            int k_index = 2*index + (literal.negated_ ? 0 : 1);
                            //cout << atoms_[k_index]->name_ << " <== true" << endl;

                            // fill and insert unit clause
                            vector<int> unit_clause(1, 1 + k_index);
                            assert(unit_clause.size() == 1);
                            sensing_models_[action_key][var_key][value_key].push_back(unit_clause);
                            //cout << "INSERT: model for action-key=" << action_key << ", var-key=" << var_key << ", value-key=" << value_key << endl;
                            //assert(0);
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
                    for( size_t j = 0; j < term.size(); ++j ) {
                        const PDDL_Base::Literal &head = *static_cast<const PDDL_Base::Literal*>(term[j]);
                        //cout << "  rule for head " << *(const PDDL_Base::Atom*)&head << ": " << flush;
                        string head_name = head.to_string(head.negated_, true);
                        int head_index = get_atom_index(ins, head_name);
                        assert(head_index != -1);
                        int k_head_index = 2*head_index + (head.negated_ ? 0 : 1);
                        //cout << atoms_[k_head_index]->name_ << flush << " <==" << flush;

                        // fill clause
                        vector<int> clause(1, 1 + k_head_index);
                        for( size_t i = 0; i < term.size(); ++i ) {
                            if( i == j ) continue;
                            const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(term[i]);
                            string name = literal.to_string(literal.negated_, true);
                            int index = get_atom_index(ins, name);
                            assert(index != -1);
                            int k_index = 2*index + (literal.negated_ ? 1 : 0);
                            //cout << " " << atoms_[k_index]->name_ << flush;
                            clause.push_back(-(1 + k_index));
                        }
                        //cout << endl;

                        // insert clause
                        assert(clause.size() == term.size());
                        sensing_models_[action_key][var_key][value_key].push_back(clause);
                        //cout << "INSERT: clause="; LW1_State::print_clause(cout, clause, this); cout << endl;
                        //cout << "INSERT: model for action-key=" << action_key << ", var-key=" << var_key << ", value-key=" << value_key << endl;
                        //assert(0);
                    }
                } else if( dynamic_cast<const PDDL_Base::Literal*>(model.dnf_) != 0 ) {
                    const PDDL_Base::Literal &literal = *static_cast<const PDDL_Base::Literal*>(model.dnf_);
                    //cout << "dnf is single literal=" << *(const PDDL_Base::Atom*)&literal << ": " << flush;
                    string name = literal.to_string(literal.negated_, true);
                    int index = get_atom_index(ins, name);
                    assert(index != -1);
                    int k_index = 2*index + (literal.negated_ ? 0 : 1);
                    //cout << atoms_[k_index]->name_ << " <== true" << endl;

                    // fill and insert unit clause
                    vector<int> unit_clause(1, 1 + k_index);
                    assert(unit_clause.size() == 1);
                    sensing_models_[action_key][var_key][value_key].push_back(unit_clause);
                    //cout << "INSERT: model for action-key=" << action_key << ", var-key=" << var_key << ", value-key=" << value_key << endl;
                    //assert(0);
                } else if( dynamic_cast<const PDDL_Base::Constant*>(model.dnf_) != 0 ) {
                    //cout << "dnf is constant: " << *model.dnf_ << endl;
                    // nothing to do. Obviate formula
                    //assert(0);
                } else {
                    cout << Utils::error() << "formula '" << *model.dnf_
                         << "' for model of '" << var_name << ":" << atom_name
                         << "' isn't dnf!" << endl;
                    continue;
                }
            }
        }
    }

    // set initial atoms
    for( index_set::const_iterator it = ins.init_.literals_.begin(); it != ins.init_.literals_.end(); ++it ) {
        int idx = *it > 0 ? *it-1 : -*it-1;
        if( *it > 0 ) {
            init_.literals_.insert(1 + 2*idx);
        } else {
            init_.literals_.insert(1 + 2*idx+1);
        }
    }

    // add known literals in initial situation
    for( size_t k = 0; k < ins.n_atoms(); ++k ) {
        //const Atom &atom = *ins.atoms_[k];
        if( (init_.literals_.find(1 + 2*k) == init_.literals_.end()) &&
            (init_.literals_.find(1 + 2*k+1) == init_.literals_.end()) ) {
            cout << Utils::red() << "XXXXXX COMPLETION OF INIT is off!" << Utils::normal() << endl;
            //init_.literals_.insert(1 + 2*k+1);
            if( options_.is_enabled("kp:print:atom:init") ) {
                cout << "Atom " << atoms_[2*k+1]->name_ << " added to init" << endl;
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
        for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
            const Variable &var = *multivalued_variables_[k];
            if( var.is_state_variable_ ) {
                const set<int> &domain = var.domain_;
                if( domain.size() == 1 ) {
                    // nothing to add because all clauses are tautological
                } else {
                    // for each value x, Kx <= [K-x_i for all i with x_i != x]
                    for( set<int>::const_iterator it = domain.begin(); it != domain.end(); ++it ) {
                        vector<int> clause;
                        clause.reserve(domain.size());
                        clause.push_back(1 + 2**it);
                        for( set<int>::const_iterator jt = domain.begin(); jt != domain.end(); ++jt ) {
                            if( it != jt ) clause.push_back(-(1 + 2**jt+1));
                        }
                        clauses_for_axioms_.push_back(clause);
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
                            }
                        }
                    }
                }
            }
        }

        // create clauses for type3 sensing drules
        if( options_.is_enabled("lw1:drule:sensing:type3") ) {
            for( size_t k = 0; k < ins.n_actions(); ++k ) {
                const Action &act = *ins.actions_[k];
                if( (act.name_->to_string().compare(0, 11, "drule-atom-") == 0) ||
                    (act.name_->to_string().compare(0, 20, "drule-sensing-type3-") == 0) ) {

                    for( index_set::const_iterator it = act.effect_.begin(); it != act.effect_.end(); ++it ) {
                        vector<int> clause;
                        clause.reserve(1 + act.precondition_.size());

                        int index = *it > 0 ? *it - 1 : -*it - 1;
                        clause.push_back(1 + (*it > 0 ? 2*index : 2*index+1));
                        for( index_set::const_iterator it = act.precondition_.begin(); it != act.precondition_.end(); ++it ) {
                            int index = *it > 0 ? *it - 1 : -*it - 1;
                            clause.push_back(-(1 + (*it > 0 ? 2*index : 2*index+1)));
                        }
                        //cout << "CLAUSE: "; LW1_State::print_clause(cout, clause, this); cout << endl;
                        clauses_for_axioms_.push_back(clause);
                    }
                }
            }
        }

        // add K-tautological clauses Kp => -K-P and define set of
        // literals that forbid clauses to enter the augmented state
        if( options_.is_enabled("lw1:inference:up:enhanced") ) {
            // create K-tautological clauses
            for( size_t k = 0; k < ins.n_atoms(); ++k ) {
                vector<int> clause;
                clause.reserve(2);
                clause.push_back(-(1 + 2*k));
                clause.push_back(-(1 + 2*k + 1));
                clauses_for_axioms_.push_back(clause);
                //cout << "CLAUSE: " << flush; LW1_State::print_clause(cout, clause, this); cout << endl;
            }

            // observable literals
            for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
                const Variable &var = *multivalued_variables_[k];
                if( !var.is_observable_ ) continue;
                for( set<int>::const_iterator it = var.domain_.begin(); it != var.domain_.end(); ++it ) {
                    int value = *it;
                    bool is_also_value_for_static_var = false;
                    for( size_t j = 0; j < multivalued_variables_.size(); ++j ) {
                        const Variable &other_var = *multivalued_variables_[j];
                        if( var.is_observable_ ) continue;
                        if( other_var.domain_.find(value) != other_var.domain_.end() ) {
                            is_also_value_for_static_var = true;
                            break;
                        }
                    }

                    if( !is_also_value_for_static_var ) {
                        clause_forbidden_literals_.insert(1 + 2*value);
                        clause_forbidden_literals_.insert(1 + 2*value + 1);
                        //cout << "Add clause-forbidden literals: ";
                        //LW1_State::print_literal(cout, 1 + 2*value, this);
                        //cout << " ";
                        //LW1_State::print_literal(cout, 1 + 2*value + 1, this);
                        //cout << endl;
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
                    clause_forbidden_literals_.insert(1 + 2*literal);
                    clause_forbidden_literals_.insert(1 + 2*literal + 1);
                    //cout << "Add clause-forbidden literals: ";
                    //LW1_State::print_literal(cout, 1 + 2*literal, this);
                    //cout << " ";
                    //LW1_State::print_literal(cout, 1 + 2*literal + 1, this);
                    //cout << endl;
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
    return clause_forbidden_literals_.find(literal) != clause_forbidden_literals_.end();
}

bool LW1_Instance::is_forbidden(const vector<int> &clause) const {
    for( size_t k = 0; k < clause.size(); ++k ) {
        if( clause_forbidden_literals_.find(clause[k]) != clause_forbidden_literals_.end() )
            return true;
        if( clause_forbidden_literals_.find(-clause[k]) != clause_forbidden_literals_.end() )
            return true;
    }
    return false;
}

void LW1_Instance::create_regular_action(const Action &action,
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
        lw1_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, nact.effect_);
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
            lw1_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, sup_eff.effect_);
            lw1_extend_effect_with_ramifications_on_observables(idx, beams_for_observable_atoms, can_eff.effect_);
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

void LW1_Instance::merge_drules() {
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

    drule_store_.insert(make_pair(nact->precondition_, nact));
}

void LW1_Instance::create_sensor(const Sensor &sensor) {
    assert(!sensor.sense_.empty());
    assert(sensor.sense_.size() == 1);

    int sensed = *sensor.sense_.begin();
    int sensed_index = sensed > 0 ? sensed - 1 : -sensed - 1;

    int varid = -1;
    for( size_t k = 0; k < multivalued_variables_.size(); ++k ) {
        const Variable &var = *multivalued_variables_[k];
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
        const Variable &var = *multivalued_variables_[varid];
        for( set<int>::const_iterator it = var.domain_.begin(); it != var.domain_.end(); ++it ) {
            if( *it != sensed_index ) nact.precondition_.insert(-(1 + 2**it));
        }
    }

    if( options_.is_enabled("kp:print:action:sensor") )
        nact.print(cout, *this);
}

void LW1_Instance::perform_subgoaling() {
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
       << ", #dules-for-vars=" << n_drules_for_vars_
       << ", #dules-for-sensing=" << n_drules_for_sensing_
       << ", #dules-for-atoms=" << n_drules_for_atoms_
       << ", #subgoaling-actions=" << n_subgoaling_actions_
       << ", #clauses-for-axioms=" << clauses_for_axioms_.size()
       << endl;
}

