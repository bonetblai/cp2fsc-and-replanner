#include <stdlib.h>
#include <cassert>
#include "ks0_problem.h"

using namespace std;

KS0_Instance::KS0_Instance(const CP_Instance &instance, bool tag_all_literals) : Instance(instance.options_) {
    // set name
    if( dynamic_cast<const InstanceName*>(instance.name) != 0 ) {
        set_name(new InstanceName(*dynamic_cast<const InstanceName*>(instance.name)));
    } else {
        set_name(new CopyName(instance.name->to_string()));
    }

    // set number of tags; tag0 is the empty tag
    n_tags_ = instance.initial_states_.size();
    if( n_tags_ > 1 ) ++n_tags_;
    tag0_ = 0;

    // initialize tag map
    size_t ins_n_fluents = instance.n_atoms();
    tagged_ = vector<bool>(ins_n_fluents, false);
    tag_map_ = vector<int>(n_tags_*ins_n_fluents, -1);

    // calculate literals that must be tagged because they appear in conditional effects
    for( size_t k = 0; k < instance.n_actions(); ++k ) {
        const Action &act = *instance.actions[k];
        for( size_t i = 0; i < act.when.size(); ++i ) {
            const When &when = act.when[i];
            for( index_set::const_iterator it = when.condition.begin(); it != when.condition.end(); ++it ) {
                int idx = *it < 0 ? -*it-1 : *it-1;
                tagged_[idx] = true;
            }
            for( index_set::const_iterator it = when.effect.begin(); it != when.effect.end(); ++it ) {
                int idx = *it < 0 ? -*it-1 : *it-1;
                tagged_[idx] = true;
            }
        }
    }

    if( options_.is_enabled("print:ks0-translation:tag:must") ) {
        cout << "literals that *must* be tagged =";
        for( size_t k = 0; k < ins_n_fluents; ++k ) {
            if( tagged_[k] )
                cout << " " << k << "." << instance.atoms[k]->name;
        }
        cout << endl;
    }

    // collect literals reachable from each initial state (tag)
    vector<index_set> reachable_literals;
    for( StateSet::const_iterator it = instance.initial_states_.begin(); it != instance.initial_states_.end(); ++it ) {
        map<const State*, const StateSet*>::const_iterator jt = instance.reachable_space_from_initial_state_.find(*it);
        assert(jt != instance.reachable_space_from_initial_state_.end());

        // collect all literals from states reachable from this initial state
        index_set literals;
        for( StateSet::const_iterator kt = jt->second->begin(); kt != jt->second->end(); ++kt ) {
            for( State::const_iterator si = (*kt)->begin(); si != (*kt)->end(); ++si ) {
                literals.insert(1+*si);
            }
        }

        // extend literals with fsc states
        for( size_t q = 0; q < instance.fsc_states_; ++q ) {
            literals.insert(1 + instance.q0_ + q);
        }

        // store reachable literals
        reachable_literals.push_back(literals);

        if( options_.is_enabled("print:ks0-translation:reachable") ) {
            cout << "reachable literals = ";
            instance.write_atom_set(cout, literals);
            cout << endl;
        }
    }

    // create fluents (one copy for each tag). In the K_S0 translation,
    // it is enough to generate K-fluents only for positive literals.

    // first generate untagged and tag0 literals
    for( size_t k = 0; k < ins_n_fluents; ++k ) {
        const Atom &atom = *instance.atoms[k];
        ostringstream lit_name;
        char *dup = strdup(atom.name->to_string().c_str()), *aux = 0;
        if( *dup == '(' ) {
            aux = dup;
            dup = &dup[1];
            dup[strlen(dup)-1] = '\0';
        }
        char *t = strtok(dup, " ");
        lit_name << "(K_" << t;
        if( tagged_[k] && (n_tags_ > 1) ) lit_name << "__tag" << tag0_;
        while( (t = strtok(0, " ")) ) {
            lit_name << " " << t;
        }
        lit_name << ")";
        free(aux == 0 ? dup : aux);

        tag_map_[tag0_*ins_n_fluents + k] = n_atoms();
        new_atom(new CopyName(lit_name.str()));

        if( options_.is_enabled("print:ks0-translation:tag:atom:creation") )
            cout << "atom " << n_atoms()-1 << "." << lit_name.str() << " created" << endl;
    }

    // now, generate tagged literals
    if( tag_all_literals ) {
        for( size_t tag = 1; tag < n_tags_; ++tag ) {
            for( size_t k = 0; k < ins_n_fluents; ++k ) {
                if( tagged_[k] ) {
                    const Atom &atom = *instance.atoms[k];
                    ostringstream lit_name;
                    char *dup = strdup(atom.name->to_string().c_str()), *aux = 0;
                    if( *dup == '(' ) {
                        aux = dup;
                        dup = &dup[1];
                        dup[strlen(dup)-1] = '\0';
                    }
                    char *t = strtok(dup, " ");
                    lit_name << "(K_" << t << "__tag" << tag;
                    while( (t = strtok(0, " ")) ) {
                        lit_name << " " << t;
                    }
                    lit_name << ")";
                    free(aux == 0 ? dup : aux);

                    tag_map_[tag*ins_n_fluents + k] = n_atoms();
                    new_atom(new CopyName(lit_name.str()));

                    if( options_.is_enabled("print:ks0-translation:tag:atom:creation") )
                        cout << "atom " << n_atoms()-1 << "." << lit_name.str() << " created" << endl;
                }
            }
        }
    } else {
        for( size_t tag = 1; tag < n_tags_; ++tag ) {
            const index_set &literals = reachable_literals[tag-1];
            for( index_set::const_iterator it = literals.begin(); it != literals.end(); ++it ) {
                assert(*it > 0);
                const Atom &atom = *instance.atoms[*it-1];
                if( tagged_[*it-1] ) {
                    ostringstream lit_name;
                    char *dup = strdup(atom.name->to_string().c_str()), *aux = 0;
                    if( *dup == '(' ) {
                        aux = dup;
                        dup = &dup[1];
                        dup[strlen(dup)-1] = '\0';
                    }
                    char *t = strtok(dup, " ");
                    lit_name << "(K_" << t << "__tag" << tag;
                    while( (t = strtok(0, " ")) ) {
                        lit_name << " " << t;
                    }
                    lit_name << ")";
                    free(aux == 0 ? dup : aux);

                    tag_map_[tag*ins_n_fluents + *it-1] = n_atoms();
                    new_atom(new CopyName(lit_name.str()));

                    if( options_.is_enabled("print:ks0-translation:tag:atom:creation") )
                        cout << "atom " << n_atoms()-1 << "." << lit_name.str() << " created" << endl;
                }
            }
        }
    }

    // set initial situation
    for( size_t k = 0; k < ins_n_fluents; ++k ) {
        bool known_pos = true;
        bool known_neg = true;
        int tag = n_tags_ > 1 ? 1 : 0;
        for( StateSet::const_iterator it = instance.initial_states_.begin(); it != instance.initial_states_.end(); ++it, ++tag ) {
            int tidx = tag_map_[tag*ins_n_fluents + k];
            if( (*it)->satisfy(k) ) {
                known_neg = false;
                if( tidx != -1 ) init.literals.insert(1 + tidx);
            } else {
                known_pos = false;
            }
        }

        int tidx = tag_map_[tag0_*ins_n_fluents + k];
        assert(tidx != -1);
        if( known_pos ) {
            init.literals.insert(1 + tidx);
        }
    }

    // set goal situation
    for( index_set::const_iterator it = instance.goal_literals.begin(); it != instance.goal_literals.end(); ++it ) {
        assert(*it > 0);
        int tidx = tag_map_[tag0_*ins_n_fluents + (*it-1)];
        goal_literals.insert(1 + tidx);
    }

    // create actions
    for( size_t k = 0; k < instance.n_actions(); ++k ) {
        const Action &act = *instance.actions[k];
        Action &nact = new_action(new CopyName(act.name->to_string()));

        // setup precondition
        for( index_set::const_iterator it = act.precondition.begin(); it != act.precondition.end(); ++it ) {
            int tidx = tag_map_[tag0_*ins_n_fluents + (*it > 0 ? *it-1 : -*it-1)];
            assert(tidx != -1);
            if( *it > 0 )
                nact.precondition.insert(1 + tidx);
            else
                nact.precondition.insert(-(1 + tidx));
        }

        // unconditional effects: add support and cancellation literals
        for( index_set::const_iterator it = act.effect.begin(); it != act.effect.end(); ++it ) {
            int idx = *it < 0 ? -*it-1 : *it-1;
            for( size_t tag = 0; tag < n_tags_; ++tag ) {
                int tidx = tag_map_[tag*ins_n_fluents + idx];
                assert(tidx != -1);
                if( *it > 0 ) {
                    nact.effect.insert(1 + tidx);
                } else {
                    nact.effect.insert(-(1 + tidx));
                }
                if( !tagged_[idx] ) break;
            }
        }

        // conditional effects: add support and cancellation rules
        for( size_t i = 0; i < act.when.size(); ++i ) {
            const When &when = act.when[i];

            // add a conditional effect for each tag
            size_t first_tag = n_tags_ == 1 ? 0 : 1;
            size_t last_tag = n_tags_ == 1 ? 1 : n_tags_;
            for( size_t tag = first_tag; tag < last_tag; ++tag ) {
                When eff;
                bool safe = true;

                // condition
                for( index_set::const_iterator it = when.condition.begin(); it != when.condition.end(); ++it ) {
                    int idx = *it < 0 ? -*it-1 : *it-1;
                    int tidx = tag_map_[tag*ins_n_fluents + idx];
                    if( (tidx == -1) && (*it > 0) ) { safe = false; break; }
                    if( tidx == -1 ) continue;
                    if( *it > 0 ) {
                        eff.condition.insert(1 + tidx);
                    } else {
                        eff.condition.insert(-(1 + tidx));
                    }
                }
                if( !safe ) continue;

                // effects
                for( index_set::const_iterator it = when.effect.begin(); it != when.effect.end(); ++it ) {
                    int idx = *it < 0 ? -*it-1 : *it-1;
                    int tidx = tag_map_[tag*ins_n_fluents + idx];
                    if( (tidx == -1) && (*it > 0) ) { safe = false; break; }
                    if( tidx == -1 ) continue;
                    if( *it > 0 ) {
                        eff.effect.insert(1 + tidx);
                    } else {
                        eff.effect.insert(-(1 + tidx));
                    }
                }
                if( !safe ) continue;

                // add conditional effects to action
                nact.when.push_back(eff);
            }

        }

        if( options_.is_enabled("print:ks0-translation:action") )
            nact.print(cout, *this);
    }

    // calculate merge literals; i.e., those that appear as precondition or goal.
    set<int> merge_lits;
    for( size_t k = 0; k < instance.n_actions(); ++k ) {
        const Action &act = *instance.actions[k];
        for( index_set::const_iterator it = act.precondition.begin(); it != act.precondition.end(); ++it ) {
            int idx = *it < 0 ? -*it-1 : *it-1;
            if( tagged_[idx] ) merge_lits.insert(idx);
        }
    }
    for( index_set::const_iterator it = instance.goal_literals.begin(); it != instance.goal_literals.end(); ++it ) {
        assert(*it > 0);
        if( tagged_[*it-1] ) merge_lits.insert(*it-1);
    }

    if( options_.is_enabled("print:ks0-translation:merge:literals") ) {
        cout << "merge literals =";
        for( set<int>::const_iterator it = merge_lits.begin(); it != merge_lits.end(); ++it ) {
            cout << " " << instance.atoms[*it]->name;
        }
        cout << endl;
    }

    // create merge actions
    if( n_tags_ > 1 ) {
        Action &merge = new_action(new CopyName("merge"));
        for( set<int>::const_iterator it = merge_lits.begin(); it != merge_lits.end(); ++it ) {
            When merge_eff;
            assert(*it >= 0);
            assert(tagged_[*it]);
            for( size_t tag = 1; tag < n_tags_; ++tag ) {
                int tidx = tag_map_[tag*ins_n_fluents + *it];
                assert(tidx != -1);
                merge_eff.condition.insert(1 + tidx);
            }
            int tidx = tag_map_[tag0_*ins_n_fluents + *it];
            merge_eff.effect.insert(1 + tidx);
            merge.when.push_back(merge_eff);
        }

        if( options_.is_enabled("print:ks0-translation:action") ||
            options_.is_enabled("print:ks0-translation:merge:action") )
            merge.print(cout, *this);
    }
}

KS0_Instance::~KS0_Instance() {
}

