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

    // returns K_not_literal of k_literal (only used in dump_k_literals)
    // CHECK: should reformulate this when making dump_k_literals general for binary variables
    inline int get_k_not_literal_from_k_literal(int k_literal) {
        //assert(k_literal % 2 == 0); // CHECK: see below about removing 1+. In such case, assertion should be valid!
        return 1 + k_literal; // CHECK: s
    }

    // k-literals associated with given literal (only used in ctors for variables)
    inline int get_k_literal_from_literal(int literal) {
        assert(literal > 0);
        return 1 + 2 * literal; // CHECK: should we remove the 1+?
    }
    inline int get_k_not_literal_from_literal(int literal) {
        assert(literal > 0);
        return 1 + 2 * literal + 1; // CHECK: should we remove the 1+?
    }

    // Abstract variable class. Domains store k-literals associated to values
    // of the variable. Original domain refer to all possible values while
    // current domain only the values that are deemed possible at some moment.
    // The values in the domain of an LW1_Instance::Variable are indices into
    // the po_instance_. Such values need to be mapped into k-literals when
    // constructing a variable from an LW1_Instance::Variable. The mapping
    // between literals and k-literals is done with the (inline) method
    // get_k_literal_from_literal() and get_k_not_literal_from_literal().
    // The latter is only used when constructing binary variables as for
    // those variables the domain for the LW1_Instance::Variable only 
    // contains one value (the positive value)
    class Variable {
      protected:
        int var_index_;
        std::string name_;
        std::set<int> original_domain_; // original domain of variable (doesn't change after initialization)
        mutable std::set<int> current_domain_; // current domain (after deductions)

      public:
        Variable(int var_index)
          : var_index_(var_index) {
        }
        Variable(const LW1_Instance::Variable &variable, int var_index)
          : var_index_(var_index), name_(variable.name()) {
            std::vector<int> domain(variable.domain().begin(), variable.domain().end());
            std::transform(domain.begin(), domain.end(), domain.begin(), get_k_literal_from_literal);
            original_domain_ = std::set<int>(domain.begin(), domain.end());
        }
        virtual ~Variable() { }

        int var_index() const {
            return var_index_;
        }
        const std::string& name() const {
            return name_;
        }
        const std::set<int>& original_domain() const {
            return original_domain_;
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

        // variable types
        virtual std::string type_as_string() const = 0;
        virtual bool is_binary() const = 0;
        virtual bool is_group_variable() const = 0;

        // Dump current domains as k-literals. If there is just one *current*
        // possible value (i.e. current_domain_.size() == 1), dump k-literal
        // expressing that such value is known. For each *current* impossible
        // value, dump k-literal expressing knowledge about impossibility of
        // such value (i.e. dump K-not- literal)
        void dump_as_k_literals(std::vector<int> &k_literals) const {
            assert(!is_group_variable());
            //std::cout << "Variable::dump_as_k_literals: ";
            //print(std::cout);
            k_literals.clear();
            if( !is_binary() ) { // CHECK: once we remove the 1+ shift on indices, this can be adapted to work for binary variables as well!
                for( std::set<int>::const_iterator it = original_domain_.begin(); it != original_domain_.end(); ++it ) {
                    if( current_domain_.find(*it) == current_domain_.end() )
                        k_literals.push_back(get_k_not_literal_from_k_literal(*it));
                }
            }
            if( current_domain_.size() == 1 )
                k_literals.push_back(*current_domain_.begin());
            //std::cout << ", k-literals=";
            //print(std::cout, k_literals, 0, 0, false);
            //std::cout << std::endl;
        }

        // Reduce current domain given a k_literal. The k_literal represents a unary constraint.
        // If it is possitive, then it is the only possible value for this variable. If it is
        // negative, it must be erased from the current possible values
        void filter_current_domain_with_k_literal(int k_literal) const {
            //std::cout << "Filtering current domain of variable " << name_ << ": cd=";
            //print(std::cout, current_domain_, 0);
            //std::cout << std::endl;
            assert(k_literal >= 0);
            if( k_literal % 2 == 0 ) {
                current_domain_.clear();
                current_domain_.insert(1 + k_literal); // CHECK: fix this when dealing with 1+shit
            } else {
                current_domain_.erase(k_literal); // CHECK: fix this when dealing with 1+shift
            }
            //std::cout << "filtered cd=";
            //print(std::cout, current_domain_, 0);
            //std::cout << std::endl;
        }

        static void print(std::ostream &os, const std::vector<int> &values, const LW1_Instance *lw1_instance) {
            os << "{";
            for( size_t k = 0; k < values.size(); ++k ) {
                int literal = values[k];
                if( lw1_instance != 0 ) State::print_literal(os, literal, lw1_instance); // CHECK: fix 1+shift
                //os << "[" << literal - 1 << "*], "; // CHECK: fix 1+shift
                os << "[" << literal << "], "; // CHECK: fix 1+shift (there is no shift for groups!)
            }
            os << "}";
        }
        static void print(std::ostream &os, const std::set<int> &values, const LW1_Instance *lw1_instance) {
            Variable::print(os, std::vector<int>(values.begin(), values.end()), lw1_instance);
        }

        virtual void print(std::ostream &os, const LW1_Instance *lw1_instance = 0) const {
            os << (name_ == "" ? std::string("<unnamed-var>") : name_)
               << "(type=" << type_as_string() << "):"
               << " od: ";
            Variable::print(os, original_domain_, lw1_instance);
            os << " cd: ";
            Variable::print(os, current_domain_, lw1_instance);
        }
    };

    class BinaryVariable : public Variable {
      public:
        BinaryVariable(int var_index)
          : Variable(var_index) {
        }
        BinaryVariable(const LW1_Instance::Variable &variable, int var_index)
          : Variable(variable, var_index) {
            assert(variable.is_binary());
            assert(variable.domain().size() == 1);
            assert(original_domain_.size() == 1);
            original_domain_.insert(get_k_not_literal_from_literal(*variable.domain().begin()));
        }
        virtual ~BinaryVariable() { }

        virtual std::string type_as_string() const {
            return std::string("binary");
        }
        virtual bool is_binary() const {
            return true;
        }
        virtual bool is_group_variable() const {
            return false;
        }
    };

    class MultiValuedVariable : public Variable {
      public:
        MultiValuedVariable(int var_index)
          : Variable(var_index) {
        }
        MultiValuedVariable(const LW1_Instance::Variable &variable, int var_index)
          : Variable(variable, var_index) {
        }
        virtual ~MultiValuedVariable() { }

        virtual std::string type_as_string() const {
            return std::string("multi-valued");
        }
        virtual bool is_binary() const {
            return false;
        }
        virtual bool is_group_variable() const {
            return false;
        }
    };

    class GroupVariable : public MultiValuedVariable {
      protected:
        std::map<int, int> var_index_to_pos_;
        std::vector<int> pos_to_var_index_;

        // a joint valuation is vector of dimension pos_to_var_index_.size()
        // the entry at position k is a value for the variable pos_to_var_index_[k]
        std::vector<std::vector<int> > joint_valuations_;

        void create_joint_valuations(const std::vector<int> &group,
                                     int group_index,
                                     const std::vector<const Variable*> &variables,
                                     std::vector<int> &joint_valuation) {
            if( group_index == group.size() ) {
                joint_valuations_.push_back(joint_valuation);
            } else {
                assert(group.size() == joint_valuation.size());
                assert((group_index >= 0) && (group_index < group.size()));
                int var_index = group[group_index];
                assert((var_index >= 0) && (var_index < variables.size()));
                const Variable &variable = *variables[var_index];
                for( std::set<int>::const_iterator it = variable.original_domain().begin();  it != variable.original_domain().end(); ++it ) {
                    joint_valuation[group_index] = *it;
                    create_joint_valuations(group, 1 + group_index, variables, joint_valuation);
                }
            }
        }

      public:
        GroupVariable(const std::vector<int> &group, int var_index, const std::vector<const Variable*> &variables)
          : MultiValuedVariable(var_index) {
            name_ = std::string("vg_") + std::to_string(var_index_);

            // create indexation cross references
            pos_to_var_index_ = std::vector<int>(group.size(), -1);
            for( size_t k = 0; k < group.size(); ++k ) {
                var_index_to_pos_.insert(std::make_pair(group[k], k));
                pos_to_var_index_[k] = group[k];
            }

            // create joint valuations for group variable
            std::vector<int> joint_valuation(group.size(), -1);
            create_joint_valuations(group, 0, variables, joint_valuation);

            // create original domain
            assert(joint_valuations_.size() == (1 << group.size())); // CHECK: remove when restriction on binary variables is removed!
            for( size_t k = 0; k < joint_valuations_.size(); ++k )
                original_domain_.insert(k);
        }
        virtual ~GroupVariable() { }

        int get_pos_from_var_index(int var_index) const {
            std::map<int, int>::const_iterator it = var_index_to_pos_.find(var_index);
            return it == var_index_to_pos_.end() ? -1 : it->second;
        }
        int get_var_index_from_pos(int pos) const {
            assert((pos >= 0) && (pos < pos_to_var_index_.size()));
            return pos_to_var_index_[pos];
        }

        bool is_consistent_with(const std::vector<int> &joint_valuation, int k_literal) const {
            assert(0);
        }
        bool is_consistent_with(const std::vector<int> &joint_valuation, const std::vector<int> &k_term) const {
            for( size_t k = 0; k < k_term.size(); ++k ) {
                if( !is_consistent_with(joint_valuation, k_term[k]) )
                    return false;
            }
            return true;
        }
        bool is_consistent_with(const std::vector<int> &joint_valuation, const std::vector<std::vector<int> > &k_dnf) const {
            for( size_t k = 0; k < k_dnf.size(); ++k ) {
                if( is_consistent_with(joint_valuation, k_dnf[k]) )
                    return true;
            }
            return false;
        }

        void filter_current_domain_with_k_dnf(const std::vector<std::vector<int> > &k_dnf) const {
            // iterate over current values and erase those inconsistent with k_dnf
            for( std::set<int>::iterator it = current_domain_.begin(); it != current_domain_.end(); ) {
                assert((*it >= 0) && (*it < joint_valuations_.size()));
                const std::vector<int> &joint_valuation = joint_valuations_[*it];
                if( !is_consistent_with(joint_valuation, k_dnf) )
                    current_domain_.erase(it);
                else
                    ++it;
            }
        }

        virtual std::string type_as_string() const {
            return std::string("group");
        }
        virtual bool is_group_variable() const {
            return true;
        }

        virtual void print(std::ostream &os, const LW1_Instance *lw1_instance = 0) const {
            // force lw1_instance to null as there are no k-literals
            // associated to the values of group variables
            Variable::print(os, 0);
        }
    };

    class Csp {
      protected:
        const LW1_Instance &lw1_instance_;

        std::vector<const Variable*> variables_;
        std::vector<const GroupVariable*> variable_groups_;
        std::vector<std::vector<std::vector<int> > > common_variables_in_groups_; // CHECK

        // Map for finding var_index of l_atom
        const std::map<int, int> *atoms_to_var_map_; // CHECK

        // Returns a mask of impossible and possible values. Impossible mask 0010 says
        // that variables in pos 0, 2, 3 are K_not. Possible mask 0010 says that only
        // variable in pos 1 is K. Note that both masks will be the same when there is
        // no information to be inferred
        std::pair<int, int> get_masks(int group_index, const std::vector<int> &constraint) const { // CHECK
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
                    variable = new BinaryVariable(lw1_variable, k);
                else
                    variable = new MultiValuedVariable(lw1_variable, k);
                variables_.push_back(variable);
                assert(variable->var_index() == k);
            }
            for( size_t k = 0; k < lw1_instance_.vars_for_variable_groups_.size(); ++k ) {
                const GroupVariable *group = new GroupVariable(lw1_instance_.vars_for_variable_groups_[k], k, variables_);
                variable_groups_.push_back(group);
                assert(group->var_index() == k);
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
        const Variable& variable(int var_index) const {
            assert((var_index >= 0) && (var_index < variables_.size()));
            return *variables_[var_index];
        }
        const std::vector<const GroupVariable*>& variable_groups() const {
            return variable_groups_;
        }
        const GroupVariable& variable_group(int var_index) const {
            assert((var_index >= 0) && (var_index < variable_groups_.size()));
            return *variable_groups_[var_index];
        }

        const std::vector<std::vector<std::vector<int> > >& common_variables_in_groups() const { // CHECK
            return common_variables_in_groups_;
        }

        // clear current domains of variables
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
        int get_var_index(int h_atom) const { // CHECK
            assert(atoms_to_var_map_ != 0);
            int atom = abs(h_atom);
            std::map<int, int>::const_iterator it = atoms_to_var_map_->find(get_l_atom(atom));
            return it != atoms_to_var_map_->end() ? it->second : -1;
        }

        void set_atoms_to_var_map(const std::map<int, int> &atoms_to_var_map) { // CHECK
            atoms_to_var_map_ = &atoms_to_var_map;
        }

        // Fills in auxiliary structure common_variables_in_groups_ which
        // is a lower triangular matrix of vectors where, for i < j,
        // common_variables_in_groups_[i][j] is a vector containing
        // the indices for the variables common to groups i and j.
        void calculate_common_variables_in_groups() { // CHECK
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

        void filter_variable_with_k_literal(int k_literal) const {
            int var_index = get_var_index(1 + k_literal); // CHECK: fix this when dealing with 1+shift
            if( var_index != -1 )
                variables_[var_index]->filter_current_domain_with_k_literal(k_literal);
        }

        // Deletes from group no longer possible valuations
        void filter_group_with_k_dnf(int group_index, const std::vector<std::vector<int> > &k_dnf) const { // CHECK
            assert((group_index >= 0) && (group_index < variable_groups_.size()));
            const GroupVariable &group = *variable_groups_[group_index];
#if 0//def DEBUG // CHECK
            std::cout << "vg=" << group_index << ", cd=";
            Variable::print(std::cout, group.current_domain(), 0);
            std::cout << std::endl;
            for( size_t k = 0; k < k_dnf.size(); ++k ) {
                std::cout << "[";
                for( size_t j = 0; j < k_dnf[k].size(); ++j )
                    std::cout << " " << k_dnf[k][j];
                std::cout << " ]" << std::endl;
            }
#endif


#if 1
            std::set<int> possible_domain;
            for( size_t k = 0; k < k_dnf.size(); ++k ) {
                const std::vector<int> &k_term = k_dnf[k];
                std::pair<int, int> masks = get_masks(group_index, k_term);
                int impossibles = masks.first;
                int possibles = masks.second;
                const std::vector<int> &group = lw1_instance_.vars_for_variable_groups_[group_index];
                for( size_t value = 0; value < (1 << group.size()); ++value )
                    possible_domain.insert((value & impossibles) | possibles);
            }
#if 1//def DEBUG
                std::cout << "INTERSECTING vg=" << group_index << " with d=";
                Variable::print(std::cout, possible_domain, 0);
                std::cout << std::endl;
#endif
            group.intersect_current_domain_with(possible_domain);
#else
            group.filter_current_domain_with_k_dnf(k_dnf);
#endif


#if 0
            std::cout << "after filter: vg=" << group_index << ", cd=";
            Variable::print(std::cout, group.current_domain(), 0);
            std::cout << std::endl;
#endif
        }

        // Find variable associated with domain and then calls intersect_with
        void intersect_domain_of_variable(const std::set<int> &domain) const { // CHECK: in the only call made to this method, domain.size() == 1
            assert(!domain.empty());
            int var_index = get_var_index(*domain.begin());
            assert(var_index != -1);
            variables_[var_index]->intersect_current_domain_with(domain);
        }

        // Change (add to) state relevant information of current csp
        void update_state(LW1_State &state) const {
            for( size_t k = 0; k < variables_.size(); ++k ) {
                const Variable &variable = *variables_[k];
                std::vector<int> k_literals;
                variable.dump_as_k_literals(k_literals); // CHECK: 1+shift
                for( size_t j = 0; j < k_literals.size(); ++j ) {
#ifdef DEBUG
                    std::cout << Utils::yellow() << "[CSP] Added literal into state: ";
                    State::print_literal(std::cout, k_literals[j], &lw1_instance_); // CHECK: 1+shift
                    std::cout << Utils::normal() << std::endl;
#endif
                    state.add(k_literals[j] - 1); // CHECK: 1+shift
                }
            }
        }

        void print(std::ostream &os, const LW1_State &state) const {
            assert(0);
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

        const Variable& variable_x(const Csp &csp) const {
            return x_is_group() ? csp.variable_group(first) : csp.variable(first);
        }
        const Variable& variable_y(const Csp &csp) const {
            return y_is_group() ? csp.variable_group(second) : csp.variable(second);
        }

        void print(std::ostream &os, const LW1_Instance &lw1_instance, const Csp &csp) const { // CHECK
            const Variable &var_x = variable_x(csp);
            const Variable &var_y = variable_y(csp);
            var_x.print(os, &lw1_instance);
            var_y.print(os, &lw1_instance);
        }
    };

    class AC3 {
      protected:
        const LW1_Instance &lw1_instance_;
        std::vector<const Arc*> arcs_; // arcs are of types: (V, MV), (MV, V), and (MV, MV)
        mutable std::set<const Arc*> worklist_; // CHECK: should it be a set?

        void initialize_worklist() const { // CHECK
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
                    return false; // reached inconsistency
                } else if( p.second ) {
                    // some value_x was deleted
                    const Variable *var_x = &arc.variable_x(csp);
                    const Variable *var_y = &arc.variable_y(csp);
                    for( size_t k = 0; k < arcs_.size(); ++k ) {
                        assert(arcs_[k] != 0);
                        const Arc &tmp = *arcs_[k];
                        const Variable *tmp_z = &tmp.variable_x(csp);
                        const Variable *tmp_x = &tmp.variable_y(csp);
                        if( (tmp_x == var_x) && (tmp_z != var_y) )
                            worklist_.insert(&tmp);
                    }
                }
            }
            return true;
        }

        // first tells whether inconsistency detected while second whether
        // some value in domain of var_x is erased
        std::pair<bool, bool> arc_reduce(const Arc &arc, const Csp &csp) const {
            const Variable &var_x = arc.variable_x(csp);
            const Variable &var_y = arc.variable_y(csp);
            assert(!var_x.current_domain().empty() && !var_y.current_domain().empty());

            bool change = false;
            for( std::set<int>::iterator it = var_x.current_domain().begin(); it != var_x.current_domain().end(); ) {
                int value_x = *it;
                bool found = false;
                for( std::set<int>::const_iterator jt = var_y.current_domain().begin(); jt != var_y.current_domain().end(); ++jt ) {
                    int value_y = *jt;
                    if( consistent(var_x, value_x, var_y, value_y, csp) ) {
                        found = true;
                        break;
                    }
                }
                if( !found ) {
                    // no value_y consistent with value_x found, erase value_x
                    it = var_x.current_domain().erase(it);
                    change = true;
                    if( var_x.current_domain().empty() )
                        return std::make_pair(false, true); // reached incosistency
                } else {
                    it++;
                }
            }
            return std::make_pair(true, change);
        }

        // CHECK: simplify comment
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
        bool consistent(const Variable &var_x, int value_x, const Variable &var_y, int value_y, const Csp &csp) const {
            assert(var_x.is_group_variable() || var_y.is_group_variable());
            if( var_x.is_group_variable() && var_y.is_group_variable() ) {
                const GroupVariable &group_x = static_cast<const GroupVariable&>(var_x);
                const GroupVariable &group_y = static_cast<const GroupVariable&>(var_y);
                // CHECK: we are assuming that all variables in group are binary!
                // CHECK: we are assuming that a joint valuation of common variables fits an integer
                return build_common_valuation(value_x, group_x, group_y, csp) == build_common_valuation(value_y, group_y, group_x, csp); // CHECK
            } else if( var_x.is_group_variable() ) {
                const GroupVariable &group_x = static_cast<const GroupVariable&>(var_x);
                int var_y_index = var_y.var_index();
                int pos_in_group_x_for_var_y = group_x.get_pos_from_var_index(var_y_index);
                int bit = (value_y % 2) << pos_in_group_x_for_var_y; // CHECK
                return (value_x & (1 << pos_in_group_x_for_var_y)) == bit; // CHECK
            } else {
                assert(var_y.is_group_variable());
                const GroupVariable &group_y = static_cast<const GroupVariable&>(var_y);
                int var_x_index = var_x.var_index();
                int pos_in_group_y_for_var_x = group_y.get_pos_from_var_index(var_x_index);
                int bit = (value_x % 2) << pos_in_group_y_for_var_x; // CHECK
                return (value_y & (1 << pos_in_group_y_for_var_x)) == bit; // CHECK
            }
        }

        // CHECK: simplify comment
        // Returns an int that represents a valuation of common
        // variables x_var and y_var
        // This is done by using an auxiliary structure (common_vars), where
        // for each var_index 'i' and 'j', common_vars[i][j] is the vector
        // of var_index for common variables
        int build_common_valuation(int value_x, const GroupVariable &group_x, const GroupVariable &group_y, const Csp &csp) const { // CHECK
            int min_index = std::min<int>(group_x.var_index(), group_y.var_index());
            int max_index = std::max<int>(group_x.var_index(), group_y.var_index());

            // since ector<vector<vector<int> > > is lower triangular matrix, we need to
            // index first with min and then max
            const std::vector<int> &common_vars = csp.common_variables_in_groups()[min_index][max_index];

            int common_valuation = 0;
            for( size_t k = 0; k < common_vars.size(); ++k ) {
                int var_index_for_common_var = common_vars[k];
                int pos = group_x.get_pos_from_var_index(var_index_for_common_var);
                assert(pos != -1);
                // value of common var in value_x
                int value = (value_x & (1 << pos)) >= 1;
                common_valuation |= (value << k);
            }
            return common_valuation;
        }

      public:
        AC3(const LW1_Instance &lw1_instance)
          : lw1_instance_(lw1_instance) {
        }
        virtual ~AC3() {
            clear_arcs();
        }

        void clear_arcs() { // CHECK: see below
            for( size_t k = 0; k < arcs_.size(); ++k )
                delete arcs_[k];
            arcs_.clear();
        }
        void calculate_arcs(const Csp &csp) { // CHECK: arcs should be stored in adjacency lists
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

        void print(std::ostream &os, const Csp &csp) const { // CHECK
            assert(0);
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

