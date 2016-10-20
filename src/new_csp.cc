/*
 *  Copyright (C) 2011 - <date> Blai Bonet, Universidad Simon Bolivar
 * 
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 *  Blai Bonet, bonet@ldc.usb.ve, bonetblai@gmail.com
 *
 */

#include <cassert>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "new_csp.h"
#include "utils.h"

using namespace std;

//#define DEBUG

// auxiliary functions
static int k_literal(int literal) {
    return 1 + 2 * literal; // return k-literal associated to given literal
}

static int get_k_not(int k_literal) { // returns K_not_literal of k_literal
    return 1 + k_literal;
}

namespace Inference {
  namespace CSP2 {

    Variable::Variable(const LW1_Instance::Variable &var) : name_(var.name()) {
        vector<int> domain(var.domain().begin(), var.domain().end());
        transform(domain.begin(), domain.end(), domain.begin(), k_literal);
        original_domain_ = set<int>(domain.begin(), domain.end());
        current_domain_ = set<int>(domain.begin(), domain.end());
    }

    void Variable::print(ostream &os, const LW1_Instance &lw1_instance, const LW1_State &state) const {
        const set<int> &od = original_domain_;
        const set<int> &cd = current_domain_;
        set<int>::const_iterator od_end = od.cend(); --od_end;
        set<int>::const_iterator cd_end = cd.cend(); --cd_end;

        os << name_ << ": ";
        os << "od: {";
        for( set<int>::const_iterator it = od.cbegin(); it != od.cend(); it++ ) {
            state.print_literal(os, *it, &lw1_instance);
            os << " [" << *it << "]";
            if( it != od_end ) os << ", ";
        }
        os << "} ";

        os << "cd: {";
        for( auto it = cd.cbegin(); it != cd.cend(); it++ ) {
            state.print_literal(os, *it, &lw1_instance);
            os << " [" << *it << "]";
            if( it != cd_end ) os << ", ";
        }
        os << "} ";

        os << "b? " << (is_binary() ? "yes" : "no") << endl;
    }

    // Reduce current domain given a k_literal.
    // The k_literal represents a unary constraint. If it is possitive,
    // then it is the only possible value for this variable. If it's
    // negative, its value must be erase from current domain.
    void Variable::apply_unary_constraint_implied_by_k_literal(int h_atom) const {
        if( h_atom % 2 == 0 ) {
            // If h_atom is a K_not_atom, remove the K_atom which is K_not_atom - 1
            current_domain_.erase(h_atom - 1);
        } else {
            // if the atom is a K_atom, remove everything else from domain
            current_domain_.clear();
            current_domain_.insert(h_atom);
        }
    }

    BinaryVariable::BinaryVariable(const LW1_Instance::Variable &var) : Variable(var) {
        assert((original_domain_.size() == 1) && (current_domain_.size() == 1));
        original_domain_.insert(get_k_not(*original_domain_.cbegin()));
        current_domain_.insert(get_k_not(*current_domain_.cbegin()));
    }

    // If variable size is 1, then binary variable has to be that
    // value, so that value is added into info as a constraint.
    // Info vector will have only theses constraints
    void BinaryVariable::dump_into(vector<int> &info) const {
        info.clear();
        if( current_domain_.size() == 1 ) {
            info.push_back(*(current_domain_.cbegin()));
        }
    }

    void MultiValuedVariable::dump_into(vector<int> &info) const {
        info.clear();
        for( set<int>::const_iterator o = original_domain_.cbegin(); o != original_domain_.cend(); o++ ) {
            if( current_domain_.find(*o) == current_domain_.end() ) {   // Not found
                info.push_back(get_k_not(*o));
            }
        }
        if( current_domain_.size() == 1 ) {
            info.push_back(*(current_domain_.cbegin()));
        }
    }

    VariableGroup::VariableGroup(const vector<int> &group, int index) : index_(index) {
        name_ = string("vg_") + to_string(index);
        for( size_t i = 0; i < group.size(); ++i )
            var_index_to_pos_.insert(make_pair(group[i], i));
        for( size_t i = 0; i < (1 << group.size()); ++i )
            original_domain_.insert(i);
    }

    void VariableGroup::print(ostream &os, const LW1_Instance &lw1_instance, const LW1_State &state) const {
        const set<int> &od = original_domain_;
        const set<int> &cd = current_domain_;
        set<int>::const_iterator od_end = od.cend(); --od_end;
        set<int>::const_iterator cd_end = cd.cend(); --cd_end;

        os << name_ << ": ";
        os << "od: {";
        for( set<int>::const_iterator it = od.cbegin(); it != od.cend(); it++ ) {
            //state.print_literal(os, *it, &instance);
            os << *it;
            if( it != od_end ) os << ", ";
        }
        os << "} ";

        os << "cd: {";
        for( auto it = cd.cbegin(); it != cd.cend(); it++ ) {
            //state.print_literal(os, *it, &instance);
            os << *it;
            if( it != cd_end ) os << ", ";
        }
        os << "} ";
        os << endl;
    }

    // Returns a mask of impossible and possible values
    // Impossible mask 0010 says that variables in pos 0, 2, 3 are K_not
    // Possible mask 0010 says that only variable in pos 1 is K
    // Note that both masks will be the same when there is no information
    // to be infered
    pair<int, int> Csp::get_masks(int vg, const vector<int> &constraint) const {
        int impossibles = 0, possibles = 0;
        for( size_t i = 0; i < constraint.size(); ++i ) {
            int k_atom = constraint[i];
            int var_index = get_var_index(k_atom);
            const vector<int> &group = lw1_instance_.vars_for_variable_groups_[vg];
            for( size_t k = 0; k < group.size(); ++k ) {  // finding var_index possition in valuation!
                if( group[k] == var_index ) {
                    if( k_atom % 2 == 0 )
                        impossibles |= (1 << k); // k_not !
                    else
                        possibles |= (1 << k); //k !
                }
            }
        }
        return make_pair(~impossibles, possibles);
    }

    void Csp::set_atoms_to_var_map(const map<int, int> &atoms_to_var_map) {
        atoms_to_var_map_ = &atoms_to_var_map;
    }

    // Creates meta-variables (groups)
    // Creates auxiliary structure common_variables_in_groups_
    // common_variables_in_groups_ is a lower triangular matrix of vectors,
    // where common_variables_in_groups_[i][j] (i < j) is a vector
    // of common variables (var indexes) for variables with indexes
    // i and j.
    void Csp::calculate_common_variables_in_groups() {
        // Building vars in common groups matrix
        common_variables_in_groups_.assign(variable_groups_.size(), vector<vector<int> >());
        for( size_t k = 0; k < variable_groups_.size(); ++k )
            common_variables_in_groups_[k].assign(variable_groups_.size(), vector<int>());

        for( size_t i = 0; i < variable_groups_.size(); ++i ) {
            for( size_t j = i + 1; j < variable_groups_.size(); ++j ) {
                for( size_t k = 0; k < lw1_instance_.vars_for_variable_groups_[i].size(); ++k ) {
                    int var_index = lw1_instance_.vars_for_variable_groups_[i][k];
                    if( variable_groups_[j]->get_pos_from_var_index(var_index) != -1 )
                        common_variables_in_groups_[i][j].push_back(var_index);
                }
            }
        }
    }

    // Applies unary constraint represented as one (just one)
    // possible value (h_atom) over every variable
    void Csp::prune_domain_of_var(int h_atom) const {
        int var_index = get_var_index(h_atom);
        if( var_index != -1 )
            variables_[var_index]->apply_unary_constraint_implied_by_k_literal(h_atom);
    }

    // Deletes from group no longer possible valuations
    void Csp::prune_valuations_of_groups(int vg, const vector<vector<int> > &valuations) const {
#ifdef DEBUG
        for( int i = 0; i < valuations.size(); i++ ) {
            cout << "[ ";
            for( int j = 0; j < valuations[i].size(); j++ ) {
                cout << valuations[i][j] << " ";
            }
            cout << " ]";
            cout << endl;
        }
#endif

        set<int> possible_domain;
        for( int i = 0; i < int(valuations.size()); i++ ) {
            pair<int, int> masks = get_masks(vg, valuations[i]);
            int impossibles = masks.first, possibles = masks.second;
#ifdef DEBUG
            cout << "INTERSECTING vg = " << vg << endl;
#endif
            const vector<int> &group = lw1_instance_.vars_for_variable_groups_[vg];

            for( int value = 0; value < (1 << int(group.size())); value++ )
                possible_domain.insert((value & impossibles) | possibles);
        }
        variable_groups_[vg]->intersect_current_domain_with(possible_domain);
    }

    // Find variable associated with domain and then calls intersect_with
    void Csp::intersect_domain_of_var(const set<int> &domain) const {
        assert(domain.size());
        int var_index = get_var_index(*domain.begin());
        assert(var_index != -1);
        variables_[var_index]->intersect_current_domain_with(domain);
    }

    // Change (add to) state relevant information of current CSP
    void Csp::update_state(LW1_State &state) const {
        for( vector<const Variable*>::const_iterator var = variables_.begin(); var != variables_.end(); var++ ) {
            vector<int> info;
            (*var)->dump_into(info);
            for( vector<int>::const_iterator st = info.begin(); st != info.end(); st++ ) {
#ifdef DEBUG
                cout << Utils::yellow() << "[CSP] Added literal into state: ";
                state.print_literal(cout, *st, &lw1_instance);
                cout << Utils::normal() << endl;
#endif
                state.add(*st - 1);
            }
        }
    }

    void Csp::print(ostream &os, const LW1_State &state) const {
        os << ">>>CSP" << endl;
        os << ">>>VARIABLES" << endl;
        for( size_t i = 0; i < variables_.size(); i++ )
            variables_[i]->print(os, lw1_instance_, state);
    }

    void Arc::print(ostream &os, const LW1_Instance &lw1_instance, const LW1_State &state, const Csp &csp) const {
        const Variable *var_x = x_is_group() ? csp.get_group_var(first) : csp.get_var_from_vars(first);
        const Variable *var_y = y_is_group() ? csp.get_group_var(second) : csp.get_var_from_vars(second);
        var_x->print(os, lw1_instance, state);
        var_y->print(os, lw1_instance, state);
    }

    // Applies arc consistency over binary arcs
    void AC3::run_ac3(const Csp &csp) const {
        while( !worklist_.empty() ) {
            const Arc *arc = *worklist_.begin();
            worklist_.erase(worklist_.begin());
            if( arc_reduce(arc, csp) ) {
                const Variable *x = arc->x_is_group() ? csp.get_group_var(arc->first) : csp.get_var_from_vars(arc->first);
                const Variable *y = arc->y_is_group() ? csp.get_group_var(arc->second) : csp.get_var_from_vars(arc->second);
                for( auto it = arcs_.cbegin(); it != arcs_.cend(); it++ ) {
                    const Arc *tmp = *it;
                    const Variable *tmp_z = tmp->x_is_group() ? csp.get_group_var(tmp->first) : csp.get_var_from_vars(tmp->first);
                    const Variable *tmp_x = tmp->y_is_group() ? csp.get_group_var(tmp->second) : csp.get_var_from_vars(tmp->second);
                    if( (tmp_x == x) && (tmp_z != y) )
                        worklist_.insert(tmp);
                }
            }
        }
    }

    // Arc Reduce algorithm of AC3
    bool AC3::arc_reduce(const Arc *arc, const Csp &csp) const {
        const Variable *x = arc->x_is_group() ? csp.get_group_var(arc->first) : csp.get_var_from_vars(arc->first);
        const Variable *y = arc->y_is_group() ? csp.get_group_var(arc->second) : csp.get_var_from_vars(arc->second);

        bool change = false; // An element has been erase from dx ?
        assert(!x->current_domain().empty() && !y->current_domain().empty());
        for( set<int>::iterator vx = x->current_domain().begin(); vx != x->current_domain().end(); ) {
            // If arc is already satisfied (this check should be unnecessary)
            int xval = *vx;
            bool found = false;
            for( set<int>::iterator vy = y->current_domain().begin(); vy != y->current_domain().end(); vy++ ) {
                int yval = *vy;
                if( evaluate(arc, xval, yval, csp) ) {
                    found = true;
                    break;
                }
            }
            // Erase from domain, and set iterator before next element
            if( ! found ) {
                vx = x->current_domain().erase(vx);
                change = true;
            } else {
                vx++;
            }
        }
        return change;
    }

    // Returns an int that represents a valuation of common variables x_var and y_var
    // This is done by using an auxiliary structure (common_vars), where for each
    // var_index 'i' and 'j', common_vars[i][j] is the vector of var_index for common
    // variables
    int AC3::build_common_valuation(int valuation, const VariableGroup *x_var, const VariableGroup *y_var, const Csp &csp) const {
        // Because vector<vector<vector<int> > > is lower triangular matrix
        int i = min(x_var->get_index(), y_var->get_index());
        int j = max(x_var->get_index(), y_var->get_index());

        const vector<vector<vector<int> > > &common_vars = csp.common_variables_in_groups();
        int common_valuation = 0;
        for( int t = 0; t < common_vars[i][j].size(); t++ ) {
            int common_var = common_vars[i][j][t];
            int pos_var = x_var->get_pos_from_var_index(common_var);
            // value of common var in valuation
            int value = (valuation & (1 << pos_var)) >= 1;
            common_valuation |= (value << t);
        }
        return common_valuation;
    }

    // Retunrs true if arc is satisfiable with values x, y
    // This is done by considering different cases for Arc.
    //
    // If Arc is between to meta-vars (groups), then, it's enough
    // to construct common valuations for both variables, and
    // check their equality
    //
    // If Arc is mixed, then, we have one meta-var (group) and one var.
    // For example, let's suppose mixed arc (x_var, y_var)
    // where x_var is a meta-var, and y_var is variable (binary)
    // First we need to find the position of this y_var into the
    // valuations in x_var. Then, we just need to check if the bit
    // corresponding to y_var is the same as the value that y_var
    // is taking.
    //
    // Simple Arc is not considered (not using this in this AC3!)
    bool AC3::evaluate(const Arc *arc, int x, int y, const Csp &csp) const {
        assert(!arc->is_simple());
        assert((x >= 0) && (y >= 0));
        if( arc->is_mixed() ) {
            if( arc->x_is_group() ) {
                int var_index = csp.get_var_index(y);
                const VariableGroup *group = csp.get_group_var(arc->first);
                int pos = group->get_pos_from_var_index(var_index);
                int bit = (y % 2) << pos;
                return (x & (1 << pos)) == bit;
            }
            const VariableGroup *group = csp.get_group_var(arc->second);
            int var_index = csp.get_var_index(x);
            int pos = group->get_pos_from_var_index(var_index);
            int bit = (x % 2) << pos;
            return (y & (1 << pos)) == bit;
        } else {
            const VariableGroup *x_var = csp.get_group_var(arc->first);
            const VariableGroup *y_var = csp.get_group_var(arc->second);
            return build_common_valuation(x, x_var, y_var, csp) == build_common_valuation(y, y_var, x_var, csp);
        }
    }

    void AC3::clear_arcs() {
        for( size_t k = 0; k < arcs_.size(); ++k )
            delete arcs_[k];
        arcs_.clear();
    }

    // Creates arcs between state variables and meta-variables (groups)
    // and creates arcs between meta-variables
    void AC3::calculate_arcs(const Csp &csp) {
        clear_arcs();

        // Building mixed arcs
        for( size_t i = 0; i < lw1_instance_.vars_for_variable_groups_.size(); i++ ) {
            for( size_t j = 0; j < lw1_instance_.vars_for_variable_groups_[i].size(); j++ ) {
                int var_index = lw1_instance_.vars_for_variable_groups_[i][j];
                arcs_.push_back(new Arc(i, var_index, true, false));
                arcs_.push_back(new Arc(var_index, i, false, true));
            }
        }

        // Build group to group arcs
        const vector<vector<vector<int> > > &common_variables_in_groups = csp.common_variables_in_groups();
        for( size_t i = 0; i < common_variables_in_groups.size(); i++ ) {
            for( size_t j = 0; j < common_variables_in_groups[i].size(); j++ ) {
                if( !common_variables_in_groups[i][j].empty() ) {
                    arcs_.push_back(new Arc(i, j, true, true));
                    arcs_.push_back(new Arc(j, i, true, true));
                }
            }
        }
    }

    // Applies Arc Consistency over arcs
    void AC3::solve(const Csp &csp, LW1_State &state) const {
        initialize_worklist();
        run_ac3(csp);

        // Update state using information in CSP. For each value x that is pruned in domain of
        // CSP variable X corresponding to state variable X, add literal K_not_X=x. For each value
        // z that is pruned in domain of CSP variable Z corresponding to variable group Z, add
        // literal K_not_vg_Z_z
        csp.update_state(state);
    }

    void AC3::print(ostream &os, const Csp &csp, const LW1_State &state) const {
#if 0
        os << "[AC3] Inverted index table" << endl;
        const vector<Variable*> &variables = csp.variables();

        //const vector<vector<int> > &constraints = csp.constraints();

        for( map<int, vector<int> >::const_iterator it = inv_clauses_.cbegin(); it != inv_clauses_.cend(); it++ ) {
            os << "[AC3] Variable: " << endl;
            variables[it->first]->print(os, lw1_instance_, state);
            os << "[AC3] Related constraints: " << endl;
            const vector<int> &constraint = it->second;
#if 0
            for( vector<int>::const_iterator vit = constraint.cbegin(); vit != constraint.cend(); vit++ ) {
                state.print_clause_or_term(os, constraints[*vit], &lw1_instance_);
                os << endl;
            }
#endif
        }
        os << "END OF AC3" << endl;
#endif
    }

  } // namespace CSP2
} // namespace Inference

#undef DEBUG

