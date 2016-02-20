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

namespace Inference {

    typedef std::vector<int>VI;

    namespace CSP {

        int get_h_atom(int l_atom);

        // Get K_not_literal of h_atom
        int get_k_not(int h_atom);

        int get_l_atom(int h_atom);

        /**
          *  Variable, Abstract Class used in CSP structure
          */
        class Variable {
          protected:
            std::string name_;
            std::set<int> original_domain_;  // High level atoms
            std::set<int> current_domain_;   // High level atoms
          public:
            /* Constructors for Variable */
            Variable() { };
            Variable(const LW1_Instance::Variable &var);

            const std::set<int>& get_original_domain() const {
                return original_domain_;
            }

            const std::set<int>& get_current_domain() const {
                return current_domain_;
            }

            std::set<int>::iterator get_current_begin() {
                return current_domain_.begin();
            }

            std::set<int>::iterator get_current_end() {
                return current_domain_.end();
            }

            std::set<int>::iterator erase(std::set<int>::iterator it) {
                return current_domain_.erase(it);
            }

            void intersect_with(const std::set<int>& domain);

            size_t get_domain_size() const {
                return current_domain_.size();
            }

            bool evaluate(int value, int h_atom) const {
                return (value == h_atom || (h_atom < 0 && h_atom + value != 0));
            }
            //virtual void eval() = 0;  // Evaluation method
            virtual bool is_binary() const = 0;
            virtual void dump_into(std::vector<int>& info) const = 0;

            void reset_domain();
            void clear_domain();
            void apply_unary_constraint(int k_atom);
            void add(int i) { current_domain_.insert(i);  }

            // Debugging
            virtual void print(std::ostream &os, const Instance &instance,
                       const LW1_State &state) const;
        };

        /**
          *  Binary Variable Class
          */
        class Binary : public Variable {
          public:
            Binary() { };
            Binary(const LW1_Instance::Variable &var) : Variable(var) {
                original_domain_.insert(get_k_not(*original_domain_.cbegin()));
                current_domain_.insert(get_k_not(*current_domain_.cbegin()));
            };
            // Implementation of pure virtual method
            void dump_into(std::vector<int>& info) const;
            // It's a binary variable
            bool is_binary() const { return true; }
        };

        /**
          *  Arithmetic Variable Class
          */
        class Arithmetic: public Variable {
          public:
            Arithmetic() { };
            Arithmetic(const LW1_Instance::Variable &var) : Variable(var) { };
            // Implementation of pure virtual method
            void dump_into(std::vector<int>& info) const;
            // An arithmetic variables is not binary
            bool is_binary() const { return false; }
        };

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
        };

        /**
          * Csp class (Constraint Satisfaction Problem)
          */
        class Csp {
          private:
            // State Variables
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

//        class GroupArc : public Arc {
//          public:
//            GroupArc(int x, int y, bool p) : Arc(x, y, p) { };
//            bool x_is_group() const { return x_is_group_; }
//            void print(std::ostream &os, const Instance &instance,
//                               const LW1_State &state, const Csp& csp) const;
//        };

        /**
          * AC3 Algorithm for solvign CSP
          */
        class AC3 {
          private:
            struct arc_compare {
                bool operator()(const Arc* a, const Arc* b) const {
                    if (a->first < b->first) return true;
                    if (b->first < a->first) return false;
                    if (a->second < b->second) return true;
                    if (b->second < a->second) return false;
                    return (a->x_is_group_);
                }
            };
            // Arcs
            static std::vector<Inference::CSP::Arc*> arcs_;
            // map that associates variables indexes with clauses
            // that involve related atoms
            std::map<int, std::vector<int>> inv_clauses_;
            std::vector<Inference::CSP::Arc*> worklist_;
            std::set<Inference::CSP::Arc*, arc_compare> worklist_2_;

            // Reduce domains by applying constraints
            // CSP has to be consistent
            void apply_unary_constraints(Csp& csp) const;
            // Apply unary constrains
            void apply_binary_constraints(Csp& csp,
                                          const Instance& instance,
                                          const LW1_State& state);

            void initialize(Csp& csp,
                            const Instance& instance,
                            const LW1_State& state);
            void initialize_worklist();
            void apply_constraints(Inference::CSP::Csp& csp, const Instance& instance, const LW1_State& state);
            bool arc_reduce(Csp& csp,
                            const std::pair<int,int>& arc,
                            const Instance& instance,
                            const LW1_State& state) const;
            bool arc_reduce_2(Inference::CSP::Arc* arc, Inference::CSP::Csp& csp, const Instance& instance,
                                          const LW1_State& state);
            bool evaluate(Arc* arc, int x, int y, const Csp& csp) const;
        public:
            void initialize_arcs(const KP_Instance& instance, Csp& csp);
            void solve(Csp &csp, LW1_State &state, const Instance &instance);
            void solve_groups(Inference::CSP::Csp& csp,
                              LW1_State& state,
                              const Instance& instance);
            void print(std::ostream& os, const Instance& instance,
                       Csp& csp, const LW1_State& state) const;
        };
    }

}

#endif
