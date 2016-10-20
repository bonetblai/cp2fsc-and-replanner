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

#ifndef UNIT_PROPAGATION_H
#define UNIT_PROPAGATION_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

#include "lw1_state.h"
#include "lw1_problem.h"

//#define DEBUG

namespace Inference {
  namespace Propositional {

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

        void print(std::ostream &os) const {
            os << "{";
            for( size_t k = 0; k < size(); ++k ) {
                os << (*this)[k];
                if( 1 + k < size() ) os << ",";
            }
            os << "}" << std::flush;
        }
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
      public:
        CNF() : std::vector<Clause>() { }
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

    // inefficient UP: time for each iteration inside main loop of solve is O(n^2 x m)
    // where n is number of clauses and m is maximum size of clause
    class Standard : public UnitPropagation {
      protected:
        struct compare_t { // compare clasues by size, smaller clauses are preferred
            bool operator() (const Clause &a, const Clause &b) const {
                return a.size() < b.size();
            }
        };

      public:
        Standard() { }
        virtual ~Standard() { }

        void solve(const CNF &cnf, CNF &reduced_cnf) const {
            std::cout << Utils::green() << "USING STANDARD METHOD" << Utils::normal() << std::endl;
            reduced_cnf = CNF(cnf);

            bool change = true;
            while( change ) {
                change = false;

                // order clasues by size so that units appear first
                sort(reduced_cnf.begin(), reduced_cnf.end(), compare_t());

                for( CNF::iterator it = reduced_cnf.begin(); it != reduced_cnf.end(); ++it ) {
                    if( it->size() == 1 ) {
                        const Clause &unit = *it;
                        int literal = unit[0];
                        for( CNF::iterator jt = it + 1; jt != reduced_cnf.end(); ) {
                            if( jt->find(literal) != jt->end() ) {
                                reduced_cnf.erase(jt);
                                change = true;
                            } else {
                                Clause::iterator kt = jt->find(-literal);
                                if( kt != jt->end() ) {
                                    jt->erase(kt);
                                    change = true;
                                }
                                ++jt;
                            }
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    };

    // Watched Literals Algorithm.
    // Class for solving a CNF with Unit Propagation algorithm
    // Example:
    //  vector<int> assignment;
    //  Inference::Propositional::WatchedLiterals wl;
    //  wl.solve(cnf, assignment);
    class WatchedLiterals : public UnitPropagation {
      protected:
        // Map a proposition to a vector the clauses this
        // proposition occurs in axioms
        static std::vector<std::vector<int> > inverted_index_axioms_;
        static int frontier_;
        static int imax_;
        // Watched literals (indexes) for every clause
        static std::vector<std::pair<int, int> > watched_;
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
        WatchedLiterals() { }
        virtual ~WatchedLiterals() { }

        void initialize_axioms(const CNF &cnf);
        // Set propositions assignment into assigned vector.
        // Every proposition id is mapped to assgined indexes.
        void solve(const CNF &cnf, std::vector<int> &assigned);
        // Set new assigned values into assigned vector
        // after apply lookahead algorithm
        void lookahead(const CNF &cnf, std::vector<int> &assigned);
    };

  } // namespace Propositional
} // namespace Inference

#undef DEBUG

#endif

