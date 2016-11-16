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
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "lw1_problem.h"
#include "lw1_state.h"

//#define DEBUG

namespace Inference {
  namespace CSP {

    // k-atoms associated with given atoms (only used in ctors for variables)
    inline int get_k_atom_from_atom(int atom) {
        assert(atom >= 0);
        return 2 * atom;
    }
    inline int get_k_not_atom_from_atom(int atom) {
        return 1 + get_k_atom_from_atom(atom);
    }

    // complement k-atom
    inline int get_complemented_k_atom(int k_atom) {
        assert(k_atom >= 0);
        return k_atom % 2 == 0 ? 1 + k_atom : k_atom - 1;
    }

    // Abstract variable class. Domains store k-literals associated to values
    // of the variable. Original domain refer to all possible values while
    // current domain only the values that are deemed possible at some moment.
    // The values in the domain of an LW1_Instance::Variable are indices into
    // the po_instance_. Such values need to be mapped into k-literals when
    // constructing a variable from an LW1_Instance::Variable. The mapping
    // between atom and k-atom is done with the (inline) method
    // get_k_atom_from_atom() and get_k_not_atom_from_atom().
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
            std::transform(domain.begin(), domain.end(), domain.begin(), get_k_atom_from_atom);
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
        bool is_current_domain_empty() const {
            return current_domain_.empty();
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
                    it = current_domain_.erase(it);
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
        void dump_as_k_atoms(std::vector<int> &k_atoms) const {
            assert(!is_group_variable());
            k_atoms.clear();
            for( std::set<int>::const_iterator it = original_domain_.begin(); it != original_domain_.end(); ++it ) {
                if( current_domain_.find(*it) == current_domain_.end() )
                    k_atoms.push_back(get_complemented_k_atom(*it));
            }
            if( current_domain_.size() == 1 )
                k_atoms.push_back(*current_domain_.begin());
        }

        // Reduce current domain given a k_atom. The k_atom represents a unary constraint.
        // If it is possitive, then it is the only possible value for this variable. If it is
        // negative, it must be erased from the current possible values
        void filter_current_domain_with_k_atom(int k_atom) const {
            assert(k_atom >= 0);
            if( k_atom % 2 == 0 ) {
                current_domain_.clear();
                current_domain_.insert(k_atom);
            } else {
                current_domain_.erase(k_atom - 1);
            }
        }

        static void print(std::ostream &os, const std::vector<int> &values, const LW1_Instance *lw1_instance) {
            os << "{";
            for( size_t k = 0; k < values.size(); ++k ) {
                int k_atom = values[k];
                if( lw1_instance != 0 ) State::print_literal(os, 1 + k_atom, lw1_instance);
                os << "[" << k_atom << "], ";
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
            original_domain_.insert(get_k_not_atom_from_atom(*variable.domain().begin()));
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

  } // namespace CSP
} // namespace Inference

inline std::ostream& operator<<(std::ostream &os, const Inference::CSP::Variable &var) {
    var.print(os);
    return os;
}

namespace Inference {
  namespace CSP {

    class Csp;
    class GroupVariable : public MultiValuedVariable {
      protected:
        std::vector<int> var_index_to_pos_;
        std::vector<std::pair<int, const Variable*> > pos_to_var_index_;

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

            // calculate max var_index in group
            int max_var_index = 0;
            for( size_t k = 0; k < group.size(); ++k )
                max_var_index = std::max<int>(max_var_index, group[k]);

            // create indexation cross references
            var_index_to_pos_ = std::vector<int>(1 + max_var_index, -1);
            pos_to_var_index_ = std::vector<std::pair<int, const Variable*> >(group.size(), std::pair<int, const Variable*>(-1, 0));
            for( size_t k = 0; k < group.size(); ++k ) {
                assert((group[k] >= 0) && (group[k] < var_index_to_pos_.size()));
                var_index_to_pos_[group[k]] = k;
                pos_to_var_index_[k] = std::make_pair(group[k], variables[group[k]]);
            }

            // create joint valuations for group variable
            std::vector<int> joint_valuation(group.size(), -1);
            create_joint_valuations(group, 0, variables, joint_valuation);

            // create original domain
            for( size_t k = 0; k < joint_valuations_.size(); ++k )
                original_domain_.insert(k);
        }
        virtual ~GroupVariable() { }

        int get_pos_from_var_index(int var_index) const {
            assert(var_index >= 0);
            return var_index >= var_index_to_pos_.size() ? -1 : var_index_to_pos_[var_index];
        }
        int get_var_index_from_pos(int pos) const {
            assert((pos >= 0) && (pos < pos_to_var_index_.size()));
            return pos_to_var_index_[pos].first;
        }
        const std::vector<int>& joint_valuation(int index) const {
            assert((index >= 0) && (index < joint_valuations_.size()));
            return joint_valuations_[index];
        }

        bool is_consistent_with(const std::vector<int> &joint_valuation, int k_literal, const Csp &csp) const;
        bool is_consistent_with(const std::vector<int> &joint_valuation, const std::vector<int> &k_term, const Csp &csp) const {
            for( size_t k = 0; k < k_term.size(); ++k ) {
                if( !is_consistent_with(joint_valuation, k_term[k], csp) )
                    return false;
            }
            return true;
        }
        bool is_consistent_with(const std::vector<int> &joint_valuation, const std::vector<std::vector<int> > &k_dnf, const Csp &csp) const {
            for( size_t k = 0; k < k_dnf.size(); ++k ) {
                if( is_consistent_with(joint_valuation, k_dnf[k], csp) )
                    return true;
            }
            return false;
        }

        void filter_current_domain_with_k_dnf(const std::vector<std::vector<int> > &k_dnf, const Csp &csp) const {
            // iterate over current values and erase those inconsistent with k_dnf
            for( std::set<int>::iterator it = current_domain_.begin(); it != current_domain_.end(); ) {
                assert((*it >= 0) && (*it < joint_valuations_.size()));
                const std::vector<int> &joint_valuation = joint_valuations_[*it];
                if( !is_consistent_with(joint_valuation, k_dnf, csp) )
                    it = current_domain_.erase(it);
                else
                    ++it;
            }
        }

        void print(std::ostream &os, const std::vector<int> &joint_valuation, const Csp &csp) const;
        void print(std::ostream &os, const std::set<int> &valuations, const Csp &csp) const {
            for( std::set<int>::const_iterator it = valuations.begin(); it != valuations.end(); ++it ) {
                assert((*it >= 0) && (*it < joint_valuations_.size()));
                const std::vector<int> &joint_valuation = joint_valuations_[*it];
                print(os, joint_valuation, csp);
                os << std::endl;
            }
        }
        void print_current_domain(std::ostream &os, const Csp &csp) const {
            print(os, current_domain_, csp);
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
            os << (name_ == "" ? std::string("<unnamed-group>") : name_)
               << "(type=" << type_as_string() << "):"
               << " group={";
            for( size_t k = 0; k < pos_to_var_index_.size(); ++k ) {
                const Variable *variable = pos_to_var_index_[k].second;
                os << variable->name();
                if( 1 + k < pos_to_var_index_.size() ) os << ",";
            }
            os << "}" << " od-size=" << original_domain_.size()
               << " cd-size=" << current_domain_.size() << std::flush;
        }
    };

    class Csp {
      protected:
        const LW1_Instance &lw1_instance_;

        std::vector<const Variable*> variables_;
        std::vector<const GroupVariable*> variable_groups_;
        std::vector<std::vector<std::vector<int> > > common_variables_in_groups_;

        std::vector<int> atoms_to_var_map_;

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

        const LW1_Instance& lw1_instance() const {
            return lw1_instance_;
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

        const std::vector<std::vector<std::vector<int> > >& common_variables_in_groups() const {
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

        int get_var_index(int atom) const {
            assert(atom >= 0);
            return atom >= atoms_to_var_map_.size() ? -1 : atoms_to_var_map_[atom];
        }

        void set_atoms_to_var_map(const std::map<int, int> &atoms_to_var_map) {
            // calculate max atom index
            int max_atom = 0;
            for( std::map<int, int>::const_iterator it = atoms_to_var_map.begin(); it != atoms_to_var_map.end(); ++it )
                max_atom = std::max<int>(max_atom, it->first);

            // create O(1)-time map
            atoms_to_var_map_ = std::vector<int>(1 + max_atom, -1);
            for( std::map<int, int>::const_iterator it = atoms_to_var_map.begin(); it != atoms_to_var_map.end(); ++it ) {
                assert((it->first >= 0) && (it->first < atoms_to_var_map_.size()));
                atoms_to_var_map_[it->first] = it->second;
             }
        }

        // fills in auxiliary structure common_variables_in_groups_ which is a lower
        // triangular matrix of vectors where, for i < j, common_variables_in_groups_[i][j]
        // is a vector containing the indices for the variables common to groups i and j
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

        void filter_variable_with_k_atom(int k_atom) const {
            assert(k_atom >= 0);
            int var_index = get_var_index(k_atom >> 1);
            if( var_index != -1 )
                variables_[var_index]->filter_current_domain_with_k_atom(k_atom);
        }

        // Deletes from group no longer possible valuations
        void filter_group_with_k_dnf(int group_index, const std::vector<std::vector<int> > &k_dnf) const {
            assert((group_index >= 0) && (group_index < variable_groups_.size()));
            const GroupVariable &group = *variable_groups_[group_index];
            group.filter_current_domain_with_k_dnf(k_dnf, *this);
        }

        // update (add to) state relevant information from current csp
        void update_state(LW1_State &state) const {
            for( size_t k = 0; k < variables_.size(); ++k ) {
                const Variable &variable = *variables_[k];
                std::vector<int> k_atoms;
                variable.dump_as_k_atoms(k_atoms);
                for( size_t j = 0; j < k_atoms.size(); ++j ) {
#ifdef DEBUG
                    std::cout << Utils::yellow() << "[CSP] Added atom into state: ";
                    State::print_literal(std::cout, 1 + k_atoms[j], &lw1_instance_);
                    std::cout << Utils::normal() << std::endl;
#endif
                    state.add(k_atoms[j]);
                }
            }
        }

        bool is_1consistent() const {
            for( size_t k = 0; k < variables_.size(); ++k ) {
                if( variables_[k]->is_current_domain_empty() )
                    return false;
            }
            for( size_t k = 0; k < variable_groups_.size(); ++k ) {
                if( variable_groups_[k]->is_current_domain_empty() )
                    return false;
            }
            return true;
        }

        void print(std::ostream &os, const LW1_State &state) const {
            assert(0);
        }
    };

    inline bool GroupVariable::is_consistent_with(const std::vector<int> &joint_valuation, int k_literal, const Csp &csp) const {
#if 1
        assert(k_literal > 0);
        int k_atom = k_literal - 1;
        bool k_not = k_atom % 2 == 1;
        int var_index = csp.get_var_index(k_atom >> 1);
        assert(var_index != -1);
        const Variable &var = csp.variable(var_index);
        int pos = get_pos_from_var_index(var_index);
        assert((pos >= 0) && (pos < joint_valuation.size()));
        return var.is_binary() || !k_not ? joint_valuation[pos] == k_atom : joint_valuation[pos] != k_atom - 1;
#else // DEPRECATED
        assert(k_literal != 0);
        int atom = k_literal > 0 ? (k_literal - 1) >> 1 : (-k_literal - 1) >> 1;
        int var_index = csp.get_var_index(atom);
        assert(var_index != -1);
        int pos = get_pos_from_var_index(var_index);
        assert((pos >= 0) && (pos < joint_valuation.size()));
        return joint_valuation[pos] == k_literal - 1;
#endif
    }

    inline void GroupVariable::print(std::ostream &os, const std::vector<int> &joint_valuation, const Csp &csp) const {
        os << "[";
        for( size_t k = 0; k < joint_valuation.size(); ++k ) {
            int value = joint_valuation[k];
            int var_index = get_var_index_from_pos(k);
            os << csp.variable(var_index).name() << "=";
            State::print_literal(os, 1 + value, &csp.lw1_instance());
            os << "[" << value << "]";
            if( 1 + k < joint_valuation.size() ) os << ",";
        }
        os << "]" << std::flush;
    }

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

        void print(std::ostream &os, const LW1_Instance &lw1_instance, const Csp &csp) const {
            const Variable &var_x = variable_x(csp);
            const Variable &var_y = variable_y(csp);
            var_x.print(os, &lw1_instance);
            var_y.print(os, &lw1_instance);
        }
    };

    template<typename T>
    class Digraph {
      public:
        struct Edge {
            int src_;
            int dst_;
            T label_;
            Edge(int src, int dst, const T label)
              : src_(src), dst_(dst), label_(label) {
            }
        };

      protected:
        int num_vertices_;
        std::vector<std::vector<int> > alists_; // edges that *enter* given edge
        std::vector<Edge> edges_;

      public:
        Digraph(int num_vertices = 0)
          : num_vertices_(num_vertices) {
            alists_ = std::vector<std::vector<int> >(num_vertices_, std::vector<int>());
        }
        virtual ~Digraph() { }

        const std::vector<Edge>& edges() const {
            return edges_;
        }
        const Edge& edge(int edge_index) const {
            assert((edge_index >= 0) && (edge_index < edges_.size()));
            return edges_[edge_index];
        }
        const std::vector<int>& alist(int vertex) const {
            assert((vertex >= 0) && (vertex < alists_.size()));
            return alists_[vertex];
        }
        void add_edge(int i, int j, const T &label) {
            alists_[j].push_back(edges_.size());
            edges_.push_back(Edge(i, j, label));
        }
    };

    class AC3 {
      protected:
        const Csp &csp_;
        Digraph<Arc> digraph_;
        mutable std::deque<int> worklist_;

        void initialize_worklist() const {
            worklist_.clear();
            for( size_t k = 0; k < digraph_.edges().size(); ++k )
                worklist_.push_back(k);
        }

        bool run_ac3() const {
            while( !worklist_.empty() ) {
                int edge_index = worklist_.front();
                worklist_.pop_front();
                assert((edge_index >= 0) && (edge_index < digraph_.edges().size()));
                const Digraph<Arc>::Edge &edge = digraph_.edge(edge_index);
                const Arc &arc = edge.label_;
                std::pair<bool, bool> p = reduce(arc);
                if( !p.first ) {
                    return false; // reached inconsistency
                } else if( p.second ) {
                    // some value of var_x was deleted, add all edges that enter var_x
                    const std::vector<int> &alist = digraph_.alist(edge.src_);
                    for( size_t k = 0; k < alist.size(); ++k )
                        worklist_.push_back(alist[k]);
                }
            }
            return true;
        }

        std::pair<bool, bool> reduce(const Arc &arc) const {
            const Variable &var_x = arc.variable_x(csp_);
            const Variable &var_y = arc.variable_y(csp_);
            assert(!var_x.current_domain().empty() && !var_y.current_domain().empty());

            bool change = false;
            for( std::set<int>::iterator it = var_x.current_domain().begin(); it != var_x.current_domain().end(); ) {
                int value_x = *it;
                bool found = false;
                for( std::set<int>::const_iterator jt = var_y.current_domain().begin(); jt != var_y.current_domain().end(); ++jt ) {
                    int value_y = *jt;
                    if( consistent(var_x, value_x, var_y, value_y) ) {
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

        bool consistent(const GroupVariable &group,
                        const std::vector<int> &joint_valuation,
                        const Variable &var,
                        int value) const {
            assert(!var.is_group_variable());
            int var_index = var.var_index();
            int pos = group.get_pos_from_var_index(var_index);
            assert(pos != -1);
            return joint_valuation[pos] == value;
        }
        bool consistent(const GroupVariable &group_x,
                        const std::vector<int> &joint_valuation_x,
                        const GroupVariable &group_y,
                        const std::vector<int> &joint_valuation_y) const {
            int min_index = std::min<int>(group_x.var_index(), group_y.var_index());
            int max_index = std::max<int>(group_x.var_index(), group_y.var_index());
            const std::vector<int> &common_vars = csp_.common_variables_in_groups()[min_index][max_index];
            for( size_t k = 0; k < common_vars.size(); ++k ) {
                int var_index_for_common_var = common_vars[k];
                int pos_x = group_x.get_pos_from_var_index(var_index_for_common_var);
                int pos_y = group_y.get_pos_from_var_index(var_index_for_common_var);
                assert((pos_x >= 0) && (pos_x < joint_valuation_x.size()));
                assert((pos_y >= 0) && (pos_y < joint_valuation_y.size()));
                if( joint_valuation_x[pos_x] != joint_valuation_y[pos_y] )
                    return false;
            }
            return true;
        }
        bool consistent(const Variable &var_x, int value_x, const Variable &var_y, int value_y) const {
            assert(var_x.is_group_variable() || var_y.is_group_variable());
            if( var_x.is_group_variable() && var_y.is_group_variable() ) {
                const GroupVariable &group_x = static_cast<const GroupVariable&>(var_x);
                const GroupVariable &group_y = static_cast<const GroupVariable&>(var_y);
                const std::vector<int> &joint_valuation_x = group_x.joint_valuation(value_x);
                const std::vector<int> &joint_valuation_y = group_y.joint_valuation(value_y);
                return consistent(group_x, joint_valuation_x, group_y, joint_valuation_y);
            } else if( var_x.is_group_variable() ) {
                const GroupVariable &group_x = static_cast<const GroupVariable&>(var_x);
                const std::vector<int> &joint_valuation_x = group_x.joint_valuation(value_x);
                return consistent(group_x, joint_valuation_x, var_y, value_y);
            } else if( var_y.is_group_variable() ) {
                const GroupVariable &group_y = static_cast<const GroupVariable&>(var_y);
                const std::vector<int> &joint_valuation_y = group_y.joint_valuation(value_y);
                return consistent(group_y, joint_valuation_y, var_x, value_x);
            } else {
                assert(&var_x == &var_y);
                return value_x == value_y;
            }
        }

      public:
        AC3(const Csp &csp) : csp_(csp) { }
        virtual ~AC3() { }

        void calculate_arcs() {
            int num_simple_variables = csp_.variables().size();
            int num_group_variables = csp_.variable_groups().size();
            digraph_ = Digraph<Arc>(num_simple_variables + num_group_variables);

            // build mixed arcs
            for( size_t k = 0; k < csp_.lw1_instance().vars_for_variable_groups_.size(); ++k ) {
                for( size_t j = 0; j < csp_.lw1_instance().vars_for_variable_groups_[k].size(); ++j ) {
                    int var_index = csp_.lw1_instance().vars_for_variable_groups_[k][j];
                    int src = num_simple_variables + k;
                    int dst = var_index;
                    digraph_.add_edge(src, dst, Arc(k, var_index, true, false));
                    digraph_.add_edge(dst, src, Arc(var_index, k, false, true));
                }
            }

            // build group to group arcs
            const std::vector<std::vector<std::vector<int> > > &common_variables_in_groups = csp_.common_variables_in_groups();
            for( size_t k = 0; k < common_variables_in_groups.size(); ++k ) {
                for( size_t j = 0; j < common_variables_in_groups[k].size(); ++j ) {
                    if( !common_variables_in_groups[k][j].empty() ) {
                        int src = num_simple_variables + k;
                        int dst = num_simple_variables + j;
                        digraph_.add_edge(src, dst, Arc(k, j, true, true));
                        digraph_.add_edge(dst, src, Arc(j, k, true, true));
                    }
                }
            }
        }

        bool solve(LW1_State &state) const {
            if( !csp_.is_1consistent() )
                return false;

            initialize_worklist();
            bool status = run_ac3();
            if( !status )
                return false; // indicates an incosistency is found

            // Update state using information in CSP. For each value x that is pruned in domain of
            // CSP variable X corresponding to state variable X, add literal K_not_X=x. For each value
            // z that is pruned in domain of CSP variable Z corresponding to variable group Z, add
            // literal K_not_vg_Z_z
            csp_.update_state(state);
            return true; // indicates no incosistency found
        }
    };

  } // namespace CSP
} // namespace Inference

#undef DEBUG

#endif

