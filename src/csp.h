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
                virtual void dump_into(std::vector<int> &info) const = 0;
                
                // Debugging
                void print(std::ostream &os) const;
        };

        /**
          *  Binary Variable Class
          */
        class Binary : public Variable {
            public:
                Binary() { };
                Binary(const LW1_Instance::Variable &var) : Variable(var) { };
                // Implementation of pure virtual method
                void dump_into(std::vector<int> &info) const;
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
                void dump_into(std::vector<int> &info) const;
                // An arithmetic variables is not binary
                bool is_binary() const { return false; }
                // Get negate K_not_literal of literal 
                int negate(int k) const; 
        };

        /**
          * Class Csp (Constraint Satisfaction Problem)
          */
        class Csp {
            private:
                // State Variables
                static std::vector<Inference::CSP::Variable *> variables_;
                // Constraints of problem
                static std::vector< std::vector<int> > constraints_;
                // Map for finding var_index of l_atom
                static std::map<int, int> atoms_to_var_map_;
            public:
                Csp() { };
                void initialize(const std::vector<LW1_Instance::Variable*> &vars);

                // Add a constraint to constraints_
                void add_constraint(std::vector<int> &c) { 
                    constraints_.push_back(c); 
                };  

                // Reduce domains by applying constraints
                // CSP has to be consistent 
                void apply_unary_constraints(LW1_State *state); 

                // Change (Add to) state relevant information of current csp
                void dump_into(LW1_State &state) const;

                // Debugging
                void print(std::ostream &os) const; // Print CSP

                //int get_l_atom(int h_atom);
                //int get_h_atom(int l_atom);
        };

        /**
          * AC3 Algorithm for solvign CSP
          */
        class AC3 {
            private: 
                void unary_constraints(Csp &csp); // Apply unary constrains
            public:
                void solve(Csp &csp);
        };
    }
}

#endif
