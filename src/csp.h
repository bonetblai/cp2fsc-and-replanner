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

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include "lw1_problem.h"
#include "lw1_state.h"

// Namespaces for CSP construction and resolution via AC3 algorithm
namespace Inference {
  namespace CSP {
    // Atoms: l-atoms are low level literals, h-atoms are k-literals
    inline int get_l_atom(int h_atom) { // returns l_atom associated with h_atom
        return h_atom > 0 ? (h_atom - 1) / 2 : (-h_atom - 1) / 2 + 1;
    }

    // Variable abstract Class used in CSP structure
    class Variable {
      protected:
        std::string name_; // Variable name (debugging)
        std::set<int> original_domain_; // Original (full) domain of variable (it will never change after initialization)
        std::set<int> current_domain_; // Current domain (after deductions) of variable

      public:
        Variable() { }
        Variable(const LW1_Instance::Variable &var);
        virtual ~Variable() { }

        const std::string& name() const {
            return name_;
        }
        std::set<int>& get_original_domain() {
            return original_domain_;
        }
        const std::set<int>& current_domain() const {
            return current_domain_;
        }
        std::set<int>& current_domain() {
            return current_domain_;
        }

        // reset and clear current domain
        void reset_current_domain() {
            current_domain_ = original_domain_;
        }
        void clear_current_domain() {
            current_domain_.clear();
        }

        // intersect current domain with domain
        void intersect_current_domain_with(const std::set<int> &domain) {
            std::set<int>::iterator cdt = current_domain_.begin();
            std::set<int>::const_iterator pdt = domain.begin();
            while( (cdt != current_domain_.end()) && (pdt != domain.end()) ) {
                if( *cdt < *pdt ) {
                    current_domain_.erase(cdt++);
                } else {
                    if( *cdt == *pdt ) cdt++;
                    pdt++;
                }
            }
            current_domain_.erase(cdt, current_domain_.end());
        }

        // returns true if the value of a propositions match the K_literal
        bool evaluate(int value, int h_atom) const {
            return (value == h_atom || (h_atom < 0 && h_atom + value != 0));
        }

        // returns true if it is a binary variable
        virtual bool is_binary() const = 0;

        // Dump info of variable current_domain into info
        // vector. This info corresponds to k_not's associated
        // to erase elements of current domain (if arithmetic),
        // and (if it is the case) the only value that this variable
        // can be
        virtual void dump_into(std::vector<int> &info) const = 0;

        // Reduce current domain given a k_literal.
        //
        // The k_literal represents a unary constraint. If it is possitive,
        // then it is the only possible value for this variable. If it's
        // negative, its value must be erase from current domain.
        void apply_unary_constraint_implied_by_k_literal(int k_literal);

#if 0
        // Just insert value in current_domain
        void add(int i) {
            current_domain_.insert(i);
        }
#endif

        // Print variable info
        virtual void print(std::ostream &os, const Instance &instance, const LW1_State &state) const;
    };

    class BinaryVariable : public Variable {
      public:
        BinaryVariable() { }
        BinaryVariable(const LW1_Instance::Variable &var);
        virtual ~BinaryVariable() { }

        // If variable size is 1, then binary variable has to be that
        // value, so that value is added into info as a constraint.
        // Info vector will have only theses constraints
        virtual void dump_into(std::vector<int> &info) const;

        // It's a binary variable
        virtual bool is_binary() const { return true; }
    };

    class MultiValuedVariable : public Variable {
      public:
        MultiValuedVariable() { }
        MultiValuedVariable(const LW1_Instance::Variable &var) : Variable(var) { }
        virtual ~MultiValuedVariable() { }

        // Add erase elements for domain as k_not_literals to info.
        // Info vector will have only theses constraints
        virtual void dump_into(std::vector<int> &info) const;

        // An arithmetic variables is not binary
        virtual bool is_binary() const { return false; }
    };

    // Variable Group class
    // Implements dump_into method
    class VariableGroup : public MultiValuedVariable {
      private:
        int index_;
        std::map<int, int> var_index_to_pos_;

      public:
        VariableGroup(const std::vector<int> &group, int index);
        virtual ~VariableGroup() { }

        // Returns index_
        int get_index() const { return index_; }

        // Returns fixed position in valuations for a variable given its index var_index
        int get_pos_from_var_index(int var_index) const {
            std::map<int, int>::const_iterator it = var_index_to_pos_.find(var_index);
            return it == var_index_to_pos_.cend() ? -1 : it->second;
        }

        virtual void print(std::ostream &os, const Instance &instance, const LW1_State &state) const;
    };

    // CSP (Constraint Satisfaction Problem)
    // Class for initializing the CSP associated with the LW1 problem
    // Example:
    //  ...
    //  Inference::CSP::Csp csp;
    //  csp.initialize(((LW1_Instance*)kp_instance)->variables_, solver.atoms_to_vars_);
    //  if (((LW1_Instance*)kp_instance)->has_groups()) {
    //      csp.initialize_groups(*kp_instance);
    //      Inference::CSP::AC3 ac3;
    //      ac3.initialize_arcs(*kp_instance, csp);
    //  }
    class Csp {
      // TODO: all these variables should be non-static...
      private:
        // Variable vectors of CSP.
        // Theses variables are state variables
        static std::vector<Inference::CSP::Variable*> variables_;
        // Grouped Variables
        static std::vector<Inference::CSP::VariableGroup*> variable_groups_;
        // Variables in common variable groups
        static std::vector<std::vector<std::vector<int> > > vars_in_common_groups_;
        // Constraints of problem
        std::vector<std::vector<int> > constraints_;
        // Map for finding var_index of l_atom
        static std::map<int, int> atoms_to_var_map_;
        // Returns a mask of impossible and possible values
        // Impossible mask 0010 says that variables in pos 0, 2, 3 are K_not
        // Possible mask 0010 says that only variable in pos 1 is K
        // Note that both masks will be the same when there is no information
        // to be infered
        std::pair<int,int> get_masks(int vg, const std::vector<int> &constraint, const LW1_Instance &lw1_instance);

      public:
        Csp() { }
        ~Csp() { }

        const std::vector<std::vector<int> >& constraints() {
            return constraints_;
        }
        const std::vector<Inference::CSP::Variable*>& variables() {
            return variables_;
        }
        const std::vector<std::vector<std::vector<int> > >& vars_in_common_groups() const {
            return vars_in_common_groups_;
        }

        void add_constraint(std::vector<int> &constraint) {
            constraints_.push_back(constraint);
        }

        // Clear current domains for all variables
        void reset_current_domains() {
            for( size_t k = 0; k < variables_.size(); ++k )
                variables_[k]->reset_current_domain();
        }

        // Returns index of the variable k_literal (h_atom) in variables_,
        // if l_atom exists in atoms_to_var_map_
        int get_var_index(int h_atom) const {
            int atom = abs(h_atom);
            if( atoms_to_var_map_.find(get_l_atom(atom)) != atoms_to_var_map_.end() )
                return atoms_to_var_map_.at(get_l_atom(atom));
            return -1;
        }
        // Returns the variable k_literal (h_atom) associated with h_atom,
        // if l_atom exists in atoms_to_var_map_
        Variable* get_var(int h_atom) const {
            int var_index = get_var_index(h_atom);
            return var_index == -1 ? 0 : variables_[var_index];
        }
        // Returns variable indexed at var_index
        Variable* get_var_from_vars(int var_index) const {
            return variables_[var_index];
        }
        // Returns meta-variable indexed at index
        VariableGroup* get_group_var(int index) const {
            return variable_groups_[index];
        }

        void initialize(const std::vector<LW1_Instance::Variable*> &vars, const std::map<int, int> &map);

        // Creates meta-variables (groups)
        // Creates auxiliary structure vars_in_common_groups. This is a lower
        // triangular matrix of vectors, where vars_in_common_groups[i][j],
        // with i < j, is a vector of common variables (var indexes) for
        // variables with indexes i and j.
        void initialize_groups(const LW1_Instance &lw1_instance);

        // Applies unary constraint represented as one (just one)
        // possible value (h_atom) over every variable
        void prune_domain_of_var(int h_atom);

        // Deletes from group no longer possible valuations
        void prune_valuations_of_groups(int vg,
                                        const std::vector<std::vector<int> > &valuations,
                                        const Instance &kp_instance);

        // Find variable associated with domain and then calls intersect_with
        void intersect_domain_of_var(const std::set<int> &domain);

        // Change (Add to) state relevant information of current csp
        void dump_into(LW1_State &state, const Instance &instance) const;

        void print(std::ostream &os, const Instance &instance, const LW1_State &state) const;
    };

    class Arc : public std::pair<int, int> {
      protected:
        bool x_is_group_;
        bool y_is_group_;

      public:
        Arc(int x, int y, bool x_is_group, bool y_is_group)
          : std::pair<int, int>(x, y), x_is_group_(x_is_group), y_is_group_(y_is_group) {
        }

        // Returns true if x is a group
        bool x_is_group() const { return x_is_group_; }
        // Returns true if y is a group
        bool y_is_group() const { return y_is_group_; }

        // Returns true if arc is between two states variables
        bool is_simple() const { return !x_is_group_ && !y_is_group_; }
        // Returns true if arc is between two meta-variables
        bool is_group() const { return x_is_group_ && y_is_group_; }
        // Returns true if arc is between a state variable and meta-variable
        bool is_mixed() const { return !is_simple() && !is_group(); }

        bool operator<(const Arc &b) const {
            const Arc &a = *this;
            if( a.first < b.first ) return true;
            if( b.first < a.first ) return false;
            if( a.second < b.second ) return true;
            if( b.second < a.second ) return false;
            if( a.is_group() ) return true;
            if( a.is_simple() ) return false;
            if( a.is_mixed() && b.is_mixed() && a.x_is_group() && b.y_is_group() )
                return true;
            return false;
        }

        void print(std::ostream &os, const Instance &instance, const LW1_State &state, const Csp &csp) const;
    };

    // AC3 Algorithm for solvign CSP
    // Class for AC3 algorithm
    // Example:
    //  ...
    //  Inference::CSP::AC3 ac3;
    //  ac3.initialize_arcs(*kp_instance, csp);
    //  ...
    //  ac3.solve_groups(csp, state, kp_instance_);
    class AC3 {
      protected:
        struct arc_compare_t {
            bool operator()(const Arc *a, const Arc *b) const {
                return *a < *b;
            }
        };

      // TODO: all these variables should be non-static...
      protected:
        // Arcs: (V, MV), (MV,V), (MV, MV)
        static std::vector<Inference::CSP::Arc*> arcs_;

        // map that associates variables indexes with clauses that involve related atoms
        std::map<int, std::vector<int> > inv_clauses_;
        // Actives Arcs: (V, MV), (MV,V), (MV, MV)
        std::set<Inference::CSP::Arc*, arc_compare_t> worklist_;

        // Inserts arcs into worklist
        void initialize_worklist() {
            worklist_.clear();
            for( size_t k = 0; k < arcs_.size(); ++k )
                worklist_.insert(arcs_[k]);
        }

        // Applies arc consistency over binary arcs
        void apply_constraints(Inference::CSP::Csp &csp, const Instance &instance, const LW1_State &state);

        // Arc Reduce algorithm of AC3
        bool arc_reduce(Inference::CSP::Arc *arc, Inference::CSP::Csp &csp, const Instance &instance, const LW1_State &state);

        // Returns an int that represents a valuation of common
        // variables x_var and y_var
        // This is done by using an auxiliary structure (common_vars), where
        // for each var_index 'i' and 'j', common_vars[i][j] is the vector
        // of var_index for common variables
        int build_commons_valuation(int val, VariableGroup *x_var, VariableGroup *y_var, const Csp &csp) const;

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
        bool evaluate(Arc *arc, int x, int y, const Csp &csp) const;

      public:
        AC3() { }
        ~AC3() { }

        // Creates arcs between state variables and meta-variables (groups)
        // and creates arcs between meta-variables
        void initialize_arcs(const KP_Instance &instance, Csp &csp);
        // Applies Arc Consistency over arcs
        void solve_groups(Inference::CSP::Csp &csp, LW1_State &state, const Instance &instance);

        void print(std::ostream &os, const Instance &instance, Csp &csp, const LW1_State &state) const;
    };
  } // namespace CSP
} // namespace Inference

#endif

