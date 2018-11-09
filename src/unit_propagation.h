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

    class Clause : public std::vector<int> {
      public:
        std::vector<int>::iterator find(int p) {
            for( std::vector<int>::iterator it = begin(); it != end(); ++it ) {
                if( *it == p )
                    return it;
            }
            return end();
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

    class CNF : public std::vector<Clause> {
      public:
        CNF() : std::vector<Clause>() { }
        CNF(const CNF& cnf) : std::vector<Clause>(cnf.begin(), cnf.end()) { }

        int calculate_max_var_index(size_t start = 0) const {
            int max_var_index = 0;
            for( size_t i = start; i < size(); ++i ) {
                const Clause &cl = (*this)[i];
                for( size_t j = 0; j < cl.size(); ++j ) {
                    int index = abs(cl[j]);
                    max_var_index = std::max<int>(index, max_var_index);
                }
            }
            return max_var_index;;
        }
    };

    // inefficient UP: time for each iteration inside main loop of solve is O(n^2 x m)
    // where n is number of clauses and m is maximum size of clause
    class StandardUP {
      protected:
        struct compare_t { // compare clasues by size, smaller clauses are preferred
            bool operator() (const Clause &a, const Clause &b) const {
                return a.size() < b.size();
            }
        };

      public:
        StandardUP() { }
        virtual ~StandardUP() { }

        bool solve(const CNF &cnf, CNF &reduced_cnf) const {
#ifdef DEBUG
            std::cout << Utils::green() << "USING STANDARD METHOD" << Utils::normal() << std::endl;
#endif
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
                            } else {
                                Clause::iterator kt = jt->find(-literal);
                                if( kt != jt->end() ) {
                                    jt->erase(kt);
                                    change = true;
                                    if( jt->empty() )
                                        return false; // indicates that the CNF is inconsistent
                                }
                                ++jt;
                            }
                        }
                    } else {
                        break;
                    }
                }
            }
            return true; // indicates no inconsistency found
        }
    };

    class WatchedLiteralsUP {
      protected:
        int max_var_index_;
        std::vector<std::vector<int> > var_to_clauses_map_;
        std::vector<std::pair<int, int> > watched_;

        // true if literal is assigned and true
        bool is_true(int literal, const std::vector<int> &assigned) const {
            assert(assigned[abs(literal)] != -1);
            return ((assigned[abs(literal)] ? 1 : -1) * literal) > 0;
        }

        // true if given value is being watched in given clause
        bool is_watched(const CNF &cnf, int clause, int value) const {
            return (value == cnf[clause][watched_[clause].first]) || (value == cnf[clause][watched_[clause].second]);
        }

        // Returns new watched literal in given clause, after one of the watched
        // literals has changed and evaluates to a non-false value. It is
        // responsability of the caller to swap the non-false watched literal
        // into the first watched literal (w1)
        int replace(const CNF &cnf, std::vector<int> &assigned, int clause) {
            for( int w1 = 0, w2 = watched_[clause].second; w1 < int(cnf[clause].size()); w1++ ) {
                if( ((assigned[abs(cnf[clause][w1])] == -1) || is_true(cnf[clause][w1], assigned)) && (w1 != w2) )
                    return w1;
            }
            return -1;
        }

        // Construct the vector of clauses indexes associated to the negative of
        // a proposition prop. Since it is watched literals algorithm, those clauses
        // must watch the value associated with prop.
        void add_negative_propositions(const CNF &cnf, int var, int value, std::vector<int> &cp) const {
            assert(cp.empty());
            assert((var > 0) && (var < int(var_to_clauses_map_.size())));
            for( size_t k = 0; k < var_to_clauses_map_[var].size(); ++k ) {
                int clause = var_to_clauses_map_[var][k];
                if( is_watched(cnf, clause, -value) )
                    cp.push_back(clause);
            }
        }

        // Returns true if a prop can be propagated with new value set in assigned vector.
        // It is caller's responsability to give a proposition (prop > 0)
        virtual bool propagate(const CNF &cnf, std::vector<int> &assigned, int var) {
            assert((var > 0) && (var < int(assigned.size())));
            assert(assigned[var] != -1);
            int value = assigned[var] ? var : -var;

            // clauses where not var appears
            std::vector<int> cp;
            add_negative_propositions(cnf, var, value, cp);

            bool no_conflict = true;
            for( size_t k = 0; k < cp.size(); ++k ) {
                int clause = cp[k];
                assert((clause >= 0) && (clause < int(cnf.size())));
                assert((clause >= 0) && (clause < int(watched_.size())));
                assert(watched_[clause].first < int(cnf[clause].size()));

                if( cnf[clause][watched_[clause].first] != -value )
                    std::swap(watched_[clause].first, watched_[clause].second);
                assert(cnf[clause][watched_[clause].first] == -value);

                int w1 = replace(cnf, assigned, clause);
                int w2 = watched_[clause].second;

                // if w1 cannot be replaced and w2 is unnassigned, recursive call
                int new_prop = cnf[clause][w2];
                if( w1 != -1 ) {
                    watched_[clause].first = w1; // update new watched literal
                } else if( assigned[abs(new_prop)] == -1 ) {
                    assigned[abs(new_prop)] = new_prop > 0 ? 1 : 0;
                    if( !propagate(cnf, assigned, abs(new_prop)) )
                        no_conflict = false;
                } else if( !is_true(new_prop, assigned) ) {
                    // if w1 cannot be replaced and w2 is false there's conflict
                    no_conflict = false;
                }
            }
            return no_conflict;
        }

      public:
        WatchedLiteralsUP() : max_var_index_(0) { }
        virtual ~WatchedLiteralsUP() { }

        bool empty() const {
            return watched_.empty();
        }
        int size() const {
            return watched_.size();
        }

        void extend_var_to_clauses_map(const CNF &cnf, size_t start) {
            max_var_index_ = std::max<int>(max_var_index_, cnf.calculate_max_var_index(start));
            var_to_clauses_map_.resize(1 + max_var_index_);
            for( size_t k = start; k < cnf.size(); ++k ) {
                const Clause &clause = cnf[k];
                for( size_t j = 0; j < clause.size(); ++j ) {
                    int literal = clause[j];
                    assert(abs(literal) <= max_var_index_);
                    var_to_clauses_map_[abs(literal)].push_back(k);
                }
            }
        }

        void print_var_to_clauses_map(std::ostream &os) const {
            for( size_t k = 0; k < var_to_clauses_map_.size(); ++k ) {
                os << k << " ->";
                const std::vector<int> &map = var_to_clauses_map_[k];
                for( size_t j = 0; j < map.size(); ++j )
                    os << " " << map[j];
                os << std::endl;
            }
        }

        void restore(size_t start) {
            watched_.erase(watched_.begin() + start, watched_.end());

            // remove references to removed clauses
            for( size_t k = 0; k < var_to_clauses_map_.size(); ++k ) {
                std::vector<int> &map = var_to_clauses_map_[k];
                for( size_t j = 0; j < map.size(); ++j ) {
                    if( map[j] >= int(start) ) {
                        map[j] = map.back();
                        map.pop_back();
                        --j;
                    }
                }
            }
        }

        void initialize(const CNF &cnf, size_t start) {
            extend_var_to_clauses_map(cnf, start);
            for( size_t k = start; k < cnf.size(); ++k ) {
                assert(!cnf[k].empty());
                watched_.push_back(std::make_pair(0, cnf[k].size() - 1));
            }
        }

        bool solve(const CNF &cnf, size_t start, std::vector<int> &assigned) {
#ifdef DEBUG
            std::cout << Utils::green() << "USING WATCHED LITERALS" << Utils::normal() << std::endl;
#endif
            initialize(cnf, start);

            // mark every variable as unassigned
            assigned.assign(1 + max_var_index_, -1);

            for( size_t k = 0; k < cnf.size(); ++k ) {
                const Clause &clause = cnf[k];
                assert(!clause.empty());
                int literal = clause[0];
                int var = abs(literal);
                if( (clause.size() == 1) && (assigned[var] == -1) ) {
                    assigned[var] = literal > 0 ? 1 : 0;
                    if( !propagate(cnf, assigned, var) )
                        return false; // indicates that the CNF is inconsistent
                }
            }
            return true; // indicates no inconsistency found
        }

        bool lookahead(const CNF &cnf, std::vector<int> &assigned) {
            std::vector<int> copy;
            for( size_t var = 1; var < assigned.size(); ++var ) {
                if( assigned[var] != -1 ) continue; // var is already assigned
                copy = assigned;
                copy[var] = 1; // try UP with var = true
                if( !propagate(cnf, copy, var) ) { // propagating with copy
                    assigned[var] = 0; // because var = true results in inconsistent theory
                    if( !propagate(cnf, assigned, var) )
                        return false; // indicates that the CNF is inconsistent
                } else {
                    copy = assigned;  // getting back original assigned
                    copy[var] = 0; // try UP with var = false
                    if( !propagate(cnf, copy, var) ) {
                        assigned[var] = 1; // because var = false results in inconsistent theory
                        if( !propagate(cnf, assigned, var) )
                            return false; // indicates that the CNF is inconsistent
                    }
                }
            }
            return true; // indicates no inconsistency found
        }
    };

  } // namespace Propositional
} // namespace Inference

#undef DEBUG

#endif

