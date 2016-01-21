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
    typedef std::vector< VI > VVI;

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

            std::set<int> get_original_domain() const {
                return original_domain_;
            }

            std::set<int> get_current_domain() const {
                return current_domain_;
            }

            size_t get_domain_size() const {
                return current_domain_.size();
            }

            bool evaluate(int value, int h_atom) const {
                if (value == h_atom) return true;
                if (h_atom < 0 && h_atom + value != 0) return true;
                return false;
            }
            //virtual void eval() = 0;  // Evaluation method
            virtual bool is_binary() const = 0;
            virtual void dump_into(std::vector<int> &info,
                                   const Instance *instance,
                                   const LW1_State *state) const = 0;

            void clean_domain();
            void apply_unary_constraint(int k_atom);

            // Debugging
            void print(std::ostream &os, const Instance *instance,
                       const LW1_State *state) const;
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
            void dump_into(std::vector<int> &info, const Instance *instance,
                           const LW1_State *state) const;
            // An arithmetic variables is not binary
            bool is_binary() const { return false; }
        };

        class Constraint : public std::vector<int> {
          private:
            bool active_;
            int v1_, v2_, undeterm_;
          public:
            Constraint() : active_(false), v1_(-1), v2_(-1), undeterm_(-1) {};
            Constraint(const VI& cl) : VI(cl.cbegin(), cl.cend()),
                                       active_(false), v1_(-1), v2_(-1),
                                       undeterm_(-1) {};
            bool is_active() const { return active_; };
            void set_active(bool b) { active_ = b; };
            int get_v1() { return v1_; };
            int get_v2() { return v2_; };
            void set_v1(int v) { v1_ = v; };
            void set_v2(int v) { v2_ = v; };
            int get_undeterm() { return undeterm_; };
            void set_undeterm(int u) { undeterm_ = u; };
        };

        /**
          * Class Csp (Constraint Satisfaction Problem)
          */
        class Csp {
          private:
            // State Variables
            static std::vector<Inference::CSP::Variable *> variables_;
            // Constraints of problem
            std::vector<Inference::CSP::Constraint> constraints_;
            // Map for finding var_index of l_atom
            static std::map<int, int> atoms_to_var_map_;
          public:
            Csp() { };
            void initialize(
                    const std::vector<LW1_Instance::Variable *> &vars,
                    const std::map<int, int> map);

            std::vector<Constraint> get_constraints_() const {
                return constraints_;
            }

            std::vector<Inference::CSP::Variable *> get_variables_() const {
                return variables_;
            }

            // Add a constraint to constraints_
            void add_constraint(std::vector<int>& c) {
                constraints_.push_back(c);
            };

            void clean_domains();

            // Change (Add to) state relevant information of current csp
            void dump_into(LW1_State &state, const Instance &instance) const;

            int get_var_index(int h_atom) const {
                if (atoms_to_var_map_.find(get_l_atom(h_atom)) != atoms_to_var_map_.end())
                    return atoms_to_var_map_.at(get_l_atom(h_atom));
                return -1;
            }

            Variable *get_var(int h_atom) const {
                int var_index = get_var_index(abs(h_atom));
                if (var_index == -1) return NULL;
                return variables_[var_index];
            }

            // Debugging
            void print(std::ostream &os, const Instance *instance,
                       const LW1_State *state) const; // Print CSP
        };

        /**
          * AC3 Algorithm for solvign CSP
          */
        class AC3 {
          private:
            // map that associates variables indexes with clauses
            // that involve related atoms
            std::map<int, std::vector<int>> inv_clauses_;

            // Reduce domains by applying constraints
            // CSP has to be consistent
            void apply_unary_constraints(Csp &csp, const Instance *instance,
                                         const LW1_State *state) const;
            // Apply unary constrains
            void apply_binary_constraints(Csp &csp) const;

            void prepare_constraints(Csp &csp);

            void fill_watchlist(const std::vector<Constraint> constraints_,
                                VVI watchlist, const Csp &csp) const;

            bool arc_reduce(const Csp &csp, const VI &clause) const;
          public:
            void solve(Csp &csp, LW1_State &state, const Instance &instance);
            void print(std::ostream &os, const Instance *instance,
                       const Csp &csp, LW1_State *state) const;
        };
    }

}

#endif
