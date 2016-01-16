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

                std::set<int> get_original_domain() { return original_domain_; }
                std::set<int> get_current_domain() { return current_domain_; }

                //virtual void eval() = 0;  // Evaluation method
                virtual bool is_binary() const = 0;
                virtual void dump_into(std::vector<int> &info,
                                                       const Instance *instance,
                                                       const LW1_State *state) const = 0;


                void clean_domain();
                void apply_unary_constraint(int k_atom);

                // Debugging
                void print(std::ostream &os, const Instance *instance, const LW1_State *state) const;
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
            void dump_into(std::vector<int> &info, const Instance *instance,
                           const LW1_State *state) const;
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
                void dump_into(std::vector<int> &info,
                               const Instance *instance,
                               const LW1_State *state) const;
                // An arithmetic variables is not binary
                bool is_binary() const { return false; }
        };

        /**
          * Class Csp (Constraint Satisfaction Problem)
          */
        class Csp {
            private:
                // State Variables
                static std::vector<Inference::CSP::Variable *> variables_;
                // Constraints of problem
                std::vector< std::vector<int> > constraints_;
                // Map for finding var_index of l_atom
                static std::map<int, int> atoms_to_var_map_;
            public:
                Csp() { };
                void initialize(
                        const std::vector<LW1_Instance::Variable *> &vars,
                        const std::map<int, int> map);

                // Apply unary constraints
                void apply_unary_constraints(const Instance *instance, const LW1_State *state);

                // Add a constraint to constraints_
                void add_constraint(std::vector<int> &c) { 
                    constraints_.push_back(c);
                };

                void clean_domains();

                // Change (Add to) state relevant information of current csp
                void dump_into(LW1_State &state, const Instance &instance) const;

                int get_var_index(int h_atom) {
                    if (atoms_to_var_map_.find(get_l_atom(h_atom)) != atoms_to_var_map_.end())
                        return atoms_to_var_map_.at(get_l_atom(h_atom));
                    return -1;
                }

                // Debugging
                void print(std::ostream &os, const Instance *instance, const LW1_State *state) const; // Print CSP

                void solve(LW1_State *state, const Instance *instance);
        };

        /**
          * AC3 Algorithm for solvign CSP
          */
        class AC3 {
            private:
                // Reduce domains by applying constraints
                // CSP has to be consistent
                void unary_constraints(Csp &csp); // Apply unary constrains
            public:
                void solve(Csp &csp, LW1_State &state, const Instance &instance);
        };
    }
}

#endif
