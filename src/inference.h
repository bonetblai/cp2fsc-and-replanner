#ifndef INFERENCE_H
#define INFERENCE_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include "lw1_problem.h"
#include "lw1_state.h"

#define UP

namespace Inference {
    namespace Propositional {
        // iterators typedef
        typedef std::vector<std::vector<int> >::iterator vec_vec_it;
        typedef std::set<int>::iterator set_it;
        typedef std::vector<int>::iterator vec_it;
        typedef std::vector<int>::const_iterator cvec_it;

        // Clause of boolean problem. A clause is a disjunction of literals
        // Example:
        //  Inference::Propositional::Clause cl;
        //  for( int i = 0; i < int(clause.size()); ++i )
        //      cl.push_back(clause[i]);
        //  cnf.push_back(cl);
        class Clause : public std::vector<int> {
          public:
            // Returns an iterator of a element if it's found.
            // Client must no use the iterator once the clause on which the iterator
            // was created has been deleted.
            std::vector<int>::iterator find(int p) {
                std::vector<int>::iterator it = begin();
                for( ; it != end(); it++ ) {
                    if( *it == p ) return it;
                }
                return it;
            }
            // Print clause data
            void print(std::ostream &os);
        };

        // Class CNF. A CNF is a conjunction of clauses
        // Example:
        //  Inference::Propositional::CNF cnf;
        //  ...
        //      Inference::Propositional::Clause cl;
        //      for( int i = 0; i < int(clause.size()); ++i )
        //          cl.push_back(clause[i]);
        //      cnf.push_back(cl);
        class CNF : public std::vector<Clause> {
            typedef CNF::const_iterator const_vec_set_it;

          public:
            // Constructor
            CNF() : std::vector<Clause>() { }
            // Copy constructor
            CNF(const CNF& cnf) : std::vector<Clause>(cnf.begin(), cnf.end()) { }
            // Returns maximum proposition id over all literals
            int calculate_max() const {
                int max_id = 0;
                for( size_t i = 0; i < size(); ++i ) {
                    const Clause &cl = (*this)[i];
                    for( size_t j = 0; j < cl.size(); ++j ) {
                        int id = abs(cl[j]);
                        max_id = std::max<int>(id, max_id);
                    }
                }
                return max_id;
            }
        };

        class UnitPropagation {
          public:
            // PROVISIONAL: This method should make the class abstract,
            // in order to use better and implementations of reduce under
            // classic UP transparently.
            // virtual void solve() = 0;
        };

        // DPLL Algorithm. Class for solving a CNF with DPLL's unit propagation algorithm
        // Example:
        //  ...
        //  Inference::Propositional::CNF new_cnf;
        //  Inference::Propositional::DPLL up;
        //  up.solve(cnf, new_cnf);
        class DPLL : public UnitPropagation {
          public:
            DPLL() { }
            void solve(const CNF &a, CNF &b);
            struct compare {   // Overloading <
                bool operator() (Clause a, Clause b) { return a.size() < b.size(); }
            } compare;
        };

        // Watched Literals Algorithm.
        // Class for solving a CNF with Unit Propagation algorithm
        // Example:
        //  vector<int> assignment;
        //  Inference::Propositional::WatchedLiterals wl;
        //  wl.solve(cnf, assignment);
        class WatchedLiterals : public UnitPropagation {
          private:
            // Map a proposition to a vector the clauses this
            // proposition occurs in axioms
            static std::vector<std::vector<int> > inverted_index_axioms_;
            static int frontier_;
            static int imax_;
            // Watched literals (indexes) for every clause
            static std::vector<std::pair<int, int> > watched;
            // Map a proposition to a vector the clauses this
            // proposition occurs
            std::vector<std::vector<int> > inverted_index;

            // Returns true if a proposition is assigned and true
            bool is_true(int prop, const std::vector<int> &assigned);
            // Returns new watched literal in given clause,
            // after one of the watched literals has changed and evaluates to a non-false
            // value. It is responsability of the client swapping the non-false watched literal
            // into the first watched literal (w1)
            int replace(const CNF &cnf, std::vector<int> &assigned, int clause);
            // Initialize attributes given a cnf
            void initialize(const CNF &cnf);
            // Construct a table of inverted indexes
            void setInvertedIndex(const CNF &cnf, std::vector<std::vector<int> > &mapper);
            // Returns true if a value given is being watched in given clause
            inline bool isWatched(const CNF &cnf, int clause, int value);
            // Returns true if a prop can propagated with
            // new value set in assigned vector.
            // It is client responsability give a proposition (prop > 0)
            virtual bool propagate(const CNF &cnf, std::vector<int> &assigned, int p);
            // Construct the vector of clauses indexes associated to the negative of
            // a proposition prop. Since it is watched literals algorithm,
            // those clauses must watch the value associated with prop.
            // This vector is constructed in cp
            void add_negative_propositions(const CNF &cnf,
                                           const std::vector<std::vector<int> > &inv_index,
                                           int prop,
                                           int value,
                                           std::vector<int> &cp);

          public:
            // Constructor
            WatchedLiterals() { }

            void initialize_axioms(const CNF &cnf);
            // Set propositions assignment into assigned vector.
            // Every proposition id is mapped to assgined indexes.
            void solve(const CNF &cnf, std::vector<int> &assigned);
            // Set new assigned values into assigned vector
            // after apply lookahead algorithm
            void lookahead(const CNF &cnf, std::vector<int> &assigned);
        };
    } // Propositional namespace
} // Inference namespace

#endif

