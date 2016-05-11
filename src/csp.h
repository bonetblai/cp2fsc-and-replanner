#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include "lw1_problem.h"
#include "lw1_state.h"

#ifndef CSP_H
#define CSP_H

// Namespaces for CSP construction and resolution via AC3 algorithm
namespace Inference {
    // typedef shortcut
    typedef std::vector<int> VI;
    typedef int L_ATOM;  // l_atoms are just low level literals
    typedef int H_ATOM;  // h_atoms are k_literals
    namespace CSP {
        // Returns the h_atom associated with l_atom
        int get_h_atom(L_ATOM l_atom);
        // Returns K_not_literal of h_atom
        int get_k_not(H_ATOM h_atom);
        // Returns l_atom associated with h_atom
        int get_l_atom(H_ATOM h_atom);

        // Variable abstract Class used in CSP structure
        class Variable {
          protected:
            std::string name_;  // Variable name (debugging)
            // Original domain (full) of variable
            // This original_domain_ will never change after initialization
            std::set<H_ATOM> original_domain_;
            // Current domain (after deductions) of variable
            std::set<H_ATOM> current_domain_;
          public:
            // Constructors for Variable
            Variable() { };
            // Copy constructors
            Variable(const LW1_Instance::Variable &var);
            // Returns original domain ref
            const std::set<int>& get_original_domain() const {
                return original_domain_;
            }
            // Returns current domain ref
            const std::set<int>& get_current_domain() const {
                return current_domain_;
            }
            // Returns begin of current domain
            std::set<int>::iterator get_current_begin() {
                return current_domain_.begin();
            }
            // Returns end of current domain
            std::set<int>::iterator get_current_end() {
                return current_domain_.end();
            }
            // Erase iterator of current domain
            std::set<int>::iterator erase(std::set<int>::iterator it) {
                return current_domain_.erase(it);
            }
            // Intersect current domain with domain
            void intersect_with(const std::set<int>& domain);
            // Returns number of possible values for this variable
            size_t get_domain_size() const {
                return current_domain_.size();
            }
            // Returns true if the value of a propositions match the K_literal
            bool evaluate(int value, int h_atom) const {
                return (value == h_atom || (h_atom < 0 && h_atom + value != 0));
            }
            // Returns true if it is a binary variable
            virtual bool is_binary() const = 0;
            // Dump info of variable current_domain into info
            // vector. This info corresponds to k_not's associated
            // to erase elements of current domain (if arithmetic),
            // and (if it is the case) the only value that this variable
            // can be 
            virtual void dump_into(std::vector<int>& info) const = 0;

            // Set current_domain_ as original_domain_
            void reset_domain();
            // Erase current_domain 
            void clear_domain();
            // Reduce current domain given a k_literal.
            // This k_literal represents a unary constraint.
            // If k_literal is possitive, then it is the only possible value
            // for this variable. If it's negative, the this value must be erase from
            // current domain.
            void apply_unary_constraint(int k_atom);
            // Just insert value in current_domain
            void add(int i) { current_domain_.insert(i);  }

            // Print variable info (debugging)
            virtual void print(std::ostream &os, const Instance &instance,
                       const LW1_State &state) const;
        };

        // Binary variable class
        // Implements dump_into method
        class Binary : public Variable {
          public:
            // Constructor
            Binary() { };
            // Copy Constructor
            Binary(const LW1_Instance::Variable &var) : Variable(var) {
                original_domain_.insert(get_k_not(*original_domain_.cbegin()));
                current_domain_.insert(get_k_not(*current_domain_.cbegin()));
            };
            // If variable size is 1, then binary variable has to be that
            // value, so that value is added into info as a constraint.
            // Info vector will have only theses constraints
            void dump_into(std::vector<int>& info) const;
            // It's a binary variable
            bool is_binary() const { return true; }
        };

        // Arithmetic variable class
        // Implements dump_into method
        class Arithmetic: public Variable {
          public:
            // Constructor
            Arithmetic() { };
            // Copy Constructor
            Arithmetic(const LW1_Instance::Variable &var) : Variable(var) { };
            // Add erase elements for domain as k_not_literals to info.
            // Info vector will have only theses constraints
            void dump_into(std::vector<int>& info) const;
            // An arithmetic variables is not binary
            bool is_binary() const { return false; }
        };

        // Variable Group class
        // Implements dump_into method
        class VariableGroup : public Arithmetic {
          private:
            int index_;
            std::map<int, int> var_index_to_pos;
          public:
            VariableGroup(const std::vector<int>& group, int index) : index_(index) {
                for( int i = 0; i < int(group.size()); i++ ) {
                    var_index_to_pos[group[i]] = i;
                }
                for( int i = 0; i < (1 << int(group.size())); i++ ) {
                    original_domain_.insert(i);
                    current_domain_.insert(i);
                }
                name_ = "vg_" + std::to_string(index_);
            }

            void print(std::ostream &os, const Instance &instance,
                       const LW1_State &state) const;

            int get_pos_from_var_index(int var_index) const {
                auto it = var_index_to_pos.find(var_index);
                if( it == var_index_to_pos.cend()) return -1;
                return it->second;
            }
            int get_index() const { return index_; }
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
          private:
            // Variable vectors of CSP.
            // Theses variables are state variables
            static std::vector<Inference::CSP::Variable*> variables_;
            // Grouped Variables
            static std::vector<Inference::CSP::VariableGroup*> variable_groups_;
            // Variables in common variable groups
            static std::vector<std::vector<std::vector<int>>> vars_in_common_groups_;
            // Constraints of problem
            std::vector<std::vector<int>> constraints_;
            // Map for finding var_index of l_atom
            static std::map<int, int> atoms_to_var_map_;

            std::pair<int,int> get_masks(int vg, 
                                         const std::vector<int> &constraint,
                                         const LW1_Instance &kp_instance);

          public:
            void initialize(
                    const std::vector<LW1_Instance::Variable *> &vars,
                            const std::map<int, int> map);

            void initialize_groups(const KP_Instance&);

            std::vector<std::vector<int>>& get_constraints_()  {
                return constraints_;
            }

            std::vector<Inference::CSP::Variable*>& get_variables_() {
                return variables_;
            }

            const std::vector<std::vector<std::vector<int>>>& get_vars_in_common_groups() const {
                return vars_in_common_groups_;
            }

            // Add a constraint to constraints_
            void add_constraint(std::vector<int>& c) {
                constraints_.push_back(c);
            };

            void clean_domains();

            void prune_domain_of_var(int h_atom); 
            void prune_valuations_of_groups(int vg,
                                            const std::vector<std::vector<int>> &valuations,
                                            const Instance &kp_instance);
            void intersect_domain_of_var(const std::set<int> &domain);

            // Change (Add to) state relevant information of current csp
            void dump_into(LW1_State &state, const Instance &instance) const;

            int get_var_index(int h_atom) const {
                int atom = abs(h_atom);
                if (atoms_to_var_map_.find(get_l_atom(atom)) != atoms_to_var_map_.end())
                    return atoms_to_var_map_.at(get_l_atom(atom));
                return -1;
            }

            Variable *get_var(int h_atom) const {
                int var_index = get_var_index(h_atom);
                if (var_index == -1) return NULL;
                return variables_[var_index];
            }

            Variable* get_var_from_vars(int var_index) const {
                return variables_[var_index];
            }

            VariableGroup *get_group_var(int index) const {
                return variable_groups_[index];
            }



            // Debugging
            void print(std::ostream& os, const Instance& instance,
                       const LW1_State& state) const; // Print CSP

            //void print_constraint(std::ostream& os,
            //                      const Constraint& constraint,
            //                      const Instance& instance,
            //                      const LW1_State& state) const;
        };

        class Arc : public std::pair<int, int> {
          public:
            bool operator<(const Arc &b) const {
                const Arc& a = *this;
                if (a.first < b.first) return true;
                if (b.first < a.first) return false;
                if (a.second < b.second) return true;
                if (b.second < a.second) return false;

                if (a.is_group()) return true;
                if (a.is_simple()) return false;
                if (a.is_mixed() && b.is_mixed() && a.x_is_group() && b.y_is_group()) 
                    return true;
                return false;
            }

            bool x_is_group_, y_is_group_;
            Arc(int x, int y, bool x_is_group, bool y_is_group)
                    : std::pair<int, int>(x, y), x_is_group_(x_is_group), y_is_group_(y_is_group) { };
            bool x_is_group() const { return x_is_group_; }
            bool y_is_group() const { return y_is_group_; }

            bool is_simple() const { return ! x_is_group_ && ! y_is_group_; }
            bool is_group() const { return x_is_group_ && y_is_group_; }
            bool is_mixed() const { return ! is_simple() &&  ! is_group(); }

            void print(std::ostream &os, const Instance &instance,
                   const LW1_State &state, const Csp& csp) const;
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
          private:
            struct arc_compare {
                bool operator()(const Arc *a, const Arc *b) const {
                    return *a < *b;
                }
            };
            // Arcs: (V, MV), (MV,V), (MV, MV)
            static std::vector<Inference::CSP::Arc*> arcs_;
            // map that associates variables indexes with clauses
            // that involve related atoms
            std::map<int, std::vector<int>> inv_clauses_;
            // Actives Arcs: (V, MV), (MV,V), (MV, MV)
            std::set<Inference::CSP::Arc*, arc_compare> worklist_;

            // Inserts arcs into worklist
            void initialize_worklist();
            // Applies arc consistency over binary arcs
            void apply_constraints(Inference::CSP::Csp& csp, const Instance& instance, const LW1_State& state);
            // Arc Reduce algorithm of AC3
            bool arc_reduce(Inference::CSP::Arc* arc, Inference::CSP::Csp& csp, const Instance& instance,
                                          const LW1_State& state);
            int build_commons_valuation(int val, VariableGroup* x_var, VariableGroup* y_var, const Csp& csp) const;
            bool evaluate(Arc* arc, int x, int y, const Csp& csp) const;
        public:
            // Creates arcs between state variables and meta-variables (groups)
            // and creates arcs between meta-variables
            void initialize_arcs(const KP_Instance& instance, Csp& csp);
            // Applies Arc Consistency over arcs
            void solve_groups(Inference::CSP::Csp& csp,
                              LW1_State& state,
                              const Instance& instance);
            // Debugging
            void print(std::ostream& os, const Instance& instance,
                       Csp& csp, const LW1_State& state) const;
        };
    }

}

#endif
