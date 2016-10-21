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

#ifndef CSP_H
#define CSP_H

#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "lw1_problem.h"
#include "lw1_state.h"

//#define DEBUG

namespace Inference {
  namespace CSP {

    // Atoms: l-atoms are low level literals, h-atoms are k-literals
    inline int get_l_atom(int h_atom) { // returns l_atom associated with h_atom
        // CHECK: this code looks weird. Apparently, h_atom is always positive
        return h_atom > 0 ? (h_atom - 1) / 2 : (-h_atom - 1) / 2 + 1;
    }

    // returns K_not_literal of k_literal
    inline int get_k_not(int k_literal) {
        return 1 + k_literal;
    }

    // return k-literal associated to given literal
    inline int k_literal(int literal) {
        return 1 + 2 * literal;
    }

    // abstract variable class
    class Variable {
      protected:
        std::string name_;
        std::set<int> original_domain_; // original domain of variable (doesn't change after initialization)
        mutable std::set<int> current_domain_; // current domain (after deductions)

      public:
        //Variable() : name_("<unnamed-var>") { }
        Variable() { }
        Variable(const LW1_Instance::Variable &variable)
          : name_(variable.name()) {
            std::vector<int> domain(variable.domain().begin(), variable.domain().end());
            std::transform(domain.begin(), domain.end(), domain.begin(), k_literal);
            original_domain_ = std::set<int>(domain.begin(), domain.end());
            current_domain_ = std::set<int>(domain.begin(), domain.end());
        }
        virtual ~Variable() { }

        const std::string& name() const {
            return name_;
        }
        std::set<int>& current_domain() const {
            return current_domain_;
        }

        // reset and clear current domain
        void reset_current_domain() const {
            current_domain_ = original_domain_;
        }
        void clear_current_domain() const {
            current_domain_.clear();
        }

        // intersect current domain with given domain
        void intersect_current_domain_with(const std::set<int> &domain) const {
            std::set<int>::iterator it = current_domain_.begin();
            std::set<int>::const_iterator jt = domain.begin();
            while( (it != current_domain_.end()) && (jt != domain.end()) ) {
                if( *it < *jt ) {
                    current_domain_.erase(it++);
                } else {
                    if( *it == *jt ) it++;
                    jt++;
                }
            }
            current_domain_.erase(it, current_domain_.end());
        }

        // returns true if the value of a propositions match the K_literal
        bool evaluate(int value, int h_atom) const {
            return (value == h_atom || (h_atom < 0 && h_atom + value != 0));
        }

        // variable types
        virtual std::string type_as_string() const = 0;
        virtual bool is_binary() const = 0;

        // Dump info of variable current_domain into info
        // vector. This info corresponds to k_not's associated
        // to erase elements of current domain (if arithmetic),
        // and (if it is the case) the only value that this variable
        // can be
        virtual void dump_into(std::vector<int> &info) const = 0;

        // Reduce current domain given a k_literal. The k_literal represents
        // a unary constraint. If it is possitive, then it is the only possible
        // value for this variable. If it's negative, its value must be erase
        // from current domain.
        void apply_unary_constraint_implied_by_k_literal(int k_literal) const {
            if( k_literal % 2 == 0 ) {
                // If h_atom is a K_not_atom, remove the K_atom which is K_not_atom - 1
                // CHECK this as it looks wrong
                current_domain_.erase(k_literal - 1);
            } else {
                // if the atom is a K_atom, remove everything else from domain
                current_domain_.clear();
                // CHECK this as it looks wrong
                current_domain_.insert(k_literal);
            }
        }

        virtual void print(std::ostream &os, const LW1_Instance &lw1_instance, const LW1_State &state) const {
            const std::set<int> &od = original_domain_;
            const std::set<int> &cd = current_domain_;
            std::set<int>::const_iterator od_end = od.cend(); --od_end;
            std::set<int>::const_iterator cd_end = cd.cend(); --cd_end;

            os << name_ << "(type=" << type_as_string() << "): ";
            os << "od: {";
            for( std::set<int>::const_iterator it = od.begin(); it != od.end(); it++ ) {
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
        }
    };

    class BinaryVariable : public Variable {
      public:
        BinaryVariable() { }
        BinaryVariable(const LW1_Instance::Variable &variable)
          : Variable(variable) {
            assert(original_domain_.size() == 1);
            assert((original_domain_.size() == 1) && (current_domain_.size() == 1)); // CHECK: remove this?
            original_domain_.insert(get_k_not(*original_domain_.begin()));
            current_domain_.insert(get_k_not(*current_domain_.begin())); // CHECK: remove this?
        }
        virtual ~BinaryVariable() { }

        virtual std::string type_as_string() const {
            return std::string("binary");
        }
        virtual bool is_binary() const {
            return true;
        }

        // If variable size is 1, then binary variable has to be that
        // value, so that value is added into info as a constraint.
        // Info vector will have only theses constraints
        virtual void dump_into(std::vector<int> &info) const {
            info.clear();
            if( current_domain_.size() == 1 )
                info.push_back(*current_domain_.begin());
        }
    };

    class MultiValuedVariable : public Variable {
      public:
        MultiValuedVariable() { }
        MultiValuedVariable(const LW1_Instance::Variable &variable) : Variable(variable) { }
        virtual ~MultiValuedVariable() { }

        virtual std::string type_as_string() const {
            return std::string("multi-valued");
        }
        virtual bool is_binary() const {
            return false;
        }

        // Add erase elements for domain as k_not_literals to info.
        // Info vector will have only theses constraints
        virtual void dump_into(std::vector<int> &info) const {
            info.clear();
            for( std::set<int>::const_iterator it = original_domain_.begin(); it != original_domain_.end(); ++it ) {
                if( current_domain_.find(*it) == current_domain_.end() )
                    info.push_back(get_k_not(*it));
            }
            if( current_domain_.size() == 1 )
                info.push_back(*current_domain_.begin()); // CHECK this
        }
    };

    // Variable Group class
    // Implements dump_into method
    class GroupVariable : public MultiValuedVariable {
      private:
        int index_;
        std::map<int, int> var_index_to_pos_;
        std::vector<int> pos_to_var_index_;

      public:
        GroupVariable(const std::vector<int> &group, int index)
          : index_(index) {
            name_ = std::string("vg_") + std::to_string(index);
            pos_to_var_index_ = std::vector<int>(group.size(), -1);
            for( size_t k = 0; k < group.size(); ++k ) {
                var_index_to_pos_.insert(std::make_pair(group[k], k));
                pos_to_var_index_[k] = group[k];
            }
            for( size_t k = 0; k < (1 << group.size()); ++k )
                original_domain_.insert(k);
        }
        virtual ~GroupVariable() { }

        int get_index() const {
            return index_;
        }
        int get_pos_from_var_index(int var_index) const {
            std::map<int, int>::const_iterator it = var_index_to_pos_.find(var_index);
            return it == var_index_to_pos_.end() ? -1 : it->second;
        }
        int get_var_index_from_pos(int pos) const {
            assert((pos >= 0) && (pos < pos_to_var_index_.size()));
            return pos_to_var_index_[pos];
        }

        virtual std::string type_as_string() const {
            return std::string("group");
        }

        virtual void print(std::ostream &os, const LW1_Instance &lw1_instance, const LW1_State &state) const {
            const std::set<int> &od = original_domain_;
            const std::set<int> &cd = current_domain_;
            std::set<int>::const_iterator od_end = od.cend(); --od_end;
            std::set<int>::const_iterator cd_end = cd.cend(); --cd_end;

            os << name_ << ": ";
            os << "od: {";
            for( std::set<int>::const_iterator it = od.begin(); it != od.end(); it++ ) {
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
            os << "} " << std::endl;
        }
    };

    class Csp {
      protected:
        const LW1_Instance &lw1_instance_;

        std::vector<const Variable*> variables_;
        std::vector<const GroupVariable*> variable_groups_;
        std::vector<std::vector<std::vector<int> > > common_variables_in_groups_;

        // Map for finding var_index of l_atom
        const std::map<int, int> *atoms_to_var_map_;

        // Returns a mask of impossible and possible values. Impossible mask 0010 says
        // that variables in pos 0, 2, 3 are K_not. Possible mask 0010 says that only
        // variable in pos 1 is K. Note that both masks will be the same when there is
        // no information to be inferred
        std::pair<int, int> get_masks(int group_index, const std::vector<int> &constraint) const {
            int possibles = 0;
            int impossibles = 0;
            for( size_t i = 0; i < constraint.size(); ++i ) {
                int k_atom = constraint[i];
                int var_index = get_var_index(k_atom);
                const std::vector<int> &group = lw1_instance_.vars_for_variable_groups_[group_index];
                for( size_t k = 0; k < group.size(); ++k ) {  // finding var_index possition in valuation!
                    if( group[k] == var_index ) {
                        if( k_atom % 2 == 0 )
                            impossibles |= (1 << k); // k_not !
                        else
                            possibles |= (1 << k); //k !
                    }
                }
            }
            return std::make_pair(~impossibles, possibles);
        }

      public:
        Csp(const LW1_Instance &lw1_instance)
          : lw1_instance_(lw1_instance), atoms_to_var_map_(0) {
            for( size_t k = 0; k < lw1_instance_.variables_.size(); ++k ) {
                const LW1_Instance::Variable &lw1_variable = *lw1_instance_.variables_[k];
                const Variable *variable = 0;
                if( lw1_variable.is_binary() )
                    variable = new BinaryVariable(lw1_variable);
                else
                    variable = new MultiValuedVariable(lw1_variable);
                variables_.push_back(variable);
            }

            for( size_t k = 0; k < lw1_instance_.vars_for_variable_groups_.size(); ++k ) {
                const GroupVariable *group = new GroupVariable(lw1_instance_.vars_for_variable_groups_[k], k);
                variable_groups_.push_back(group);
            }
        }
        virtual ~Csp() {
            for( size_t k = 0; k < variable_groups_.size(); ++k )
                delete variable_groups_[k];
            for( size_t k = 0; k < variables_.size(); ++k )
                delete variables_[k];
        }

        const std::vector<const Variable*>& variables() const {
            return variables_;
        }
        const std::vector<std::vector<std::vector<int> > >& common_variables_in_groups() const {
            return common_variables_in_groups_;
        }

        // Clear current domains of variables
        void reset_current_domains() const {
            for( size_t k = 0; k < variables_.size(); ++k )
                variables_[k]->reset_current_domain();
        }
        void reset_current_domains_for_variable_groups() const {
            for( size_t k = 0; k < variable_groups_.size(); ++k )
                variable_groups_[k]->reset_current_domain();
        }

        // Returns index of the variable k_literal (h_atom) in variables_,
        // if l_atom exists in atoms_to_var_map_
        int get_var_index(int h_atom) const {
            assert(atoms_to_var_map_ != 0);
            int atom = abs(h_atom);
            std::map<int, int>::const_iterator it = atoms_to_var_map_->find(get_l_atom(atom));
            return it != atoms_to_var_map_->end() ? it->second : -1;
        }
        // Returns the variable k_literal (h_atom) associated with h_atom,
        // if l_atom exists in atoms_to_var_map_
        const Variable* get_var(int h_atom) const {
            int var_index = get_var_index(h_atom);
            return var_index == -1 ? 0 : variables_[var_index];
        }
        // Returns variable indexed at var_index
        const Variable* get_var_from_vars(int var_index) const {
            return variables_[var_index];
        }
        // Returns meta-variable indexed at index
        const GroupVariable* get_group_var(int index) const {
            return variable_groups_[index];
        }

        void set_atoms_to_var_map(const std::map<int, int> &atoms_to_var_map) {
            atoms_to_var_map_ = &atoms_to_var_map;
        }

        // Fills in auxiliary structure common_variables_in_groups_ which
        // is a lower triangular matrix of vectors where, for i < j,
        // common_variables_in_groups_[i][j] is a vector containing
        // the indices for the variables common to groups i and j.
        void calculate_common_variables_in_groups() {
            common_variables_in_groups_.assign(variable_groups_.size(), std::vector<std::vector<int> >());
            for( size_t k = 0; k < variable_groups_.size(); ++k )
                common_variables_in_groups_[k].assign(variable_groups_.size(), std::vector<int>());

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
        void prune_domain_of_var(int h_atom) const { // CHECK: change name
            int var_index = get_var_index(h_atom);
            if( var_index != -1 )
                variables_[var_index]->apply_unary_constraint_implied_by_k_literal(h_atom);
        }

        // Deletes from group no longer possible valuations
        void prune_valuations_of_groups(int group_index, const std::vector<std::vector<int> > &valuations) const {
#ifdef DEBUG
            for( size_t k = 0; k < valuations.size(); ++k ) {
                std::cout << "[";
                for( size_t j = 0; j < valuations[k].size(); ++j )
                    std::cout << " " << valuations[k][j];
                std::cout << " ]" << std::endl;
            }
#endif
            std::set<int> possible_domain;
            for( size_t k = 0; k < int(valuations.size()); ++k ) {
                std::pair<int, int> masks = get_masks(group_index, valuations[k]);
                int impossibles = masks.first;
                int possibles = masks.second;
#ifdef DEBUG
                std::cout << "INTERSECTING group_index=" << group_index << std::endl;
#endif
                const std::vector<int> &group = lw1_instance_.vars_for_variable_groups_[group_index];
                for( int value = 0; value < (1 << int(group.size())); ++value )
                    possible_domain.insert((value & impossibles) | possibles);
            }
            variable_groups_[group_index]->intersect_current_domain_with(possible_domain);
        }

        // Find variable associated with domain and then calls intersect_with
        void intersect_domain_of_var(const std::set<int> &domain) const { // CHECK: change name
            assert(!domain.empty());
            int var_index = get_var_index(*domain.begin());
            assert(var_index != -1);
            variables_[var_index]->intersect_current_domain_with(domain);
        }

        // Change (add to) state relevant information of current csp
        void update_state(LW1_State &state) const {
            for( size_t k = 0; k < variables_.size(); ++k ) {
                const Variable &variable = *variables_[k];
                std::vector<int> info;
                variable.dump_into(info);
                for( size_t j = 0; j < info.size(); ++j ) {
#ifdef DEBUG
                    std::cout << Utils::yellow() << "[CSP] Added literal into state: ";
                    state.print_literal(std::cout, info[j], &lw1_instance_);
                    std::cout << Utils::normal() << std::endl;
#endif
                    state.add(info[j] - 1);
                }
            }
        }

        void print(std::ostream &os, const LW1_State &state) const {
            os << ">>>CSP" << std::endl
               << ">>>VARIABLES" << std::endl;
            for( size_t i = 0; i < variables_.size(); i++ )
                variables_[i]->print(os, lw1_instance_, state);
        }
    };

    class Arc : public std::pair<int, int> {
      protected:
        bool x_is_group_;
        bool y_is_group_;

      public:
        Arc(int x, int y, bool x_is_group, bool y_is_group)
          : std::pair<int, int>(x, y), x_is_group_(x_is_group), y_is_group_(y_is_group) {
        }

        bool x_is_group() const { return x_is_group_; }
        bool y_is_group() const { return y_is_group_; }
        bool is_simple() const { return !x_is_group_ && !y_is_group_; }
        bool is_group() const { return x_is_group_ && y_is_group_; }
        bool is_mixed() const { return !is_simple() && !is_group(); }

        void print(std::ostream &os, const LW1_Instance &lw1_instance, const LW1_State &state, const Csp &csp) const {
            const Variable &var_x = *(x_is_group() ? csp.get_group_var(first) : csp.get_var_from_vars(first));
            const Variable &var_y = *(y_is_group() ? csp.get_group_var(second) : csp.get_var_from_vars(second));
            var_x.print(os, lw1_instance, state);
            var_y.print(os, lw1_instance, state);
        }
    };

    class AC3 {
      protected:
        const LW1_Instance &lw1_instance_;
        std::vector<const Arc*> arcs_; // arcs are of types: (V, MV), (MV, V), and (MV, MV)
        std::map<int, std::vector<int> > inv_clauses_; // associates variables indexes with clauses that involve related atoms

        mutable std::set<const Arc*> worklist_;

        void initialize_worklist() const {
            worklist_.clear();
            for( size_t k = 0; k < arcs_.size(); ++k )
                worklist_.insert(arcs_[k]);
        }

        // CHECK: make this more efficient: need to maintain explicit graph with adjacency lists
        // CHECK: it is also not clear why worklist is a set instead of a queue
        bool run_ac3(const Csp &csp) const {
            while( !worklist_.empty() ) {
                const Arc &arc = **worklist_.begin();
                worklist_.erase(worklist_.begin());
                std::pair<bool, bool> p = arc_reduce(arc, csp);
                if( !p.first ) {
                    // reached inconsistency
                    return false;
                } else if( p.second ) {
                    // some value was deleted
                    const Variable *x = arc.x_is_group() ? csp.get_group_var(arc.first) : csp.get_var_from_vars(arc.first);
                    const Variable *y = arc.y_is_group() ? csp.get_group_var(arc.second) : csp.get_var_from_vars(arc.second);
                    for( size_t k = 0; k < arcs_.size(); ++k ) {
                        assert(arcs_[k] != 0);
                        const Arc &tmp = *arcs_[k];
                        const Variable *tmp_z = tmp.x_is_group() ? csp.get_group_var(tmp.first) : csp.get_var_from_vars(tmp.first);
                        const Variable *tmp_x = tmp.y_is_group() ? csp.get_group_var(tmp.second) : csp.get_var_from_vars(tmp.second);
                        if( (tmp_x == x) && (tmp_z != y) )
                            worklist_.insert(&tmp);
                    }
                }
            }
            return true;
        }

        std::pair<bool, bool> arc_reduce(const Arc &arc, const Csp &csp) const {
            const Variable *x = arc.x_is_group() ? csp.get_group_var(arc.first) : csp.get_var_from_vars(arc.first);
            const Variable *y = arc.y_is_group() ? csp.get_group_var(arc.second) : csp.get_var_from_vars(arc.second);

            bool change = false; // An element has been erase from dx ?
            assert(!x->current_domain().empty() && !y->current_domain().empty());
            for( std::set<int>::iterator vx = x->current_domain().begin(); vx != x->current_domain().end(); ) {
                // If arc is already satisfied (this check should be unnecessary)
                int xval = *vx;
                bool found = false;
                for( std::set<int>::iterator vy = y->current_domain().begin(); vy != y->current_domain().end(); vy++ ) {
                    int yval = *vy;
                    if( evaluate(arc, xval, yval, csp) ) {
                        found = true;
                        break;
                    }
                }
                // Erase from domain, and set iterator before next element
                if( !found ) {
                    vx = x->current_domain().erase(vx);
                    change = true;
                    if( x->current_domain().empty() ) {
                        // reached an incosistency
                        return std::make_pair(false, true);
                    }
                } else {
                    vx++;
                }
            }
            return std::make_pair(true, change);
        }

        // Returns an int that represents a valuation of common
        // variables x_var and y_var
        // This is done by using an auxiliary structure (common_vars), where
        // for each var_index 'i' and 'j', common_vars[i][j] is the vector
        // of var_index for common variables
        int build_common_valuation(int valuation, const GroupVariable *x_var, const GroupVariable *y_var, const Csp &csp) const {
            // Because vector<vector<vector<int> > > is lower triangular matrix
            int i = std::min<int>(x_var->get_index(), y_var->get_index());
            int j = std::max<int>(x_var->get_index(), y_var->get_index());

            const std::vector<std::vector<std::vector<int> > > &common_vars = csp.common_variables_in_groups();
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
        bool evaluate(const Arc &arc, int x, int y, const Csp &csp) const {
            assert(!arc.is_simple());
            assert((x >= 0) && (y >= 0));
            if( arc.is_mixed() ) {
                if( arc.x_is_group() ) {
                    int var_index = csp.get_var_index(y);
                    const GroupVariable *group = csp.get_group_var(arc.first);
                    int pos = group->get_pos_from_var_index(var_index);
                    int bit = (y % 2) << pos;
                    return (x & (1 << pos)) == bit;
                }
                const GroupVariable *group = csp.get_group_var(arc.second);
                int var_index = csp.get_var_index(x);
                int pos = group->get_pos_from_var_index(var_index);
                int bit = (x % 2) << pos;
                return (y & (1 << pos)) == bit;
            } else {
                const GroupVariable *x_var = csp.get_group_var(arc.first);
                const GroupVariable *y_var = csp.get_group_var(arc.second);
                return build_common_valuation(x, x_var, y_var, csp) == build_common_valuation(y, y_var, x_var, csp);
            }
        }

      public:
        AC3(const LW1_Instance &lw1_instance)
          : lw1_instance_(lw1_instance) {
        }
        virtual ~AC3() {
            clear_arcs();
        }

        void clear_arcs() {
            for( size_t k = 0; k < arcs_.size(); ++k )
                delete arcs_[k];
            arcs_.clear();
        }
        void calculate_arcs(const Csp &csp) {
            clear_arcs();

            // build mixed arcs
            for( size_t k = 0; k < lw1_instance_.vars_for_variable_groups_.size(); ++k ) {
                for( size_t j = 0; j < lw1_instance_.vars_for_variable_groups_[k].size(); ++j ) {
                    int var_index = lw1_instance_.vars_for_variable_groups_[k][j];
                    arcs_.push_back(new Arc(k, var_index, true, false));
                    arcs_.push_back(new Arc(var_index, k, false, true));
                }
            }

            // build group to group arcs
            const std::vector<std::vector<std::vector<int> > > &common_variables_in_groups = csp.common_variables_in_groups();
            for( size_t k = 0; k < common_variables_in_groups.size(); ++k ) {
                for( size_t j = 0; j < common_variables_in_groups[k].size(); ++j ) {
                    if( !common_variables_in_groups[k][j].empty() ) {
                        arcs_.push_back(new Arc(k, j, true, true));
                        arcs_.push_back(new Arc(j, k, true, true));
                    }
                }
            }
        }

        bool solve(const Csp &csp, LW1_State &state) const {
            initialize_worklist();
            bool status = run_ac3(csp);
            if( !status )
                return false; // indicates an incosistency is found

            // Update state using information in CSP. For each value x that is pruned in domain of
            // CSP variable X corresponding to state variable X, add literal K_not_X=x. For each value
            // z that is pruned in domain of CSP variable Z corresponding to variable group Z, add
            // literal K_not_vg_Z_z
            csp.update_state(state);
            return true; // indicates no incosistency found
        }

        void print(std::ostream &os, const Csp &csp, const LW1_State &state) const {
#if 0
            os << "[AC3] Inverted index table" << endl;
            const vector<Variable*> &variables = csp.variables();

            //const vector<vector<int> > &constraints = csp.constraints();

            for( map<int, vector<int> >::const_iterator it = inv_clauses_.begin(); it != inv_clauses_.end(); it++ ) {
                os << "[AC3] Variable: " << endl;
                variables[it->first]->print(os, lw1_instance_, state);
                os << "[AC3] Related constraints: " << endl;
                const vector<int> &constraint = it->second;
#if 0
                for( vector<int>::const_iterator vit = constraint.begin(); vit != constraint.end(); vit++ ) {
                    state.print_clause_or_term(os, constraints[*vit], &lw1_instance_);
                    os << endl;
                }
#endif
            }
            os << "END OF AC3" << endl;
#endif
        }
    };
  } // namespace CSP
} // namespace Inference

#undef DEBUG

#endif

