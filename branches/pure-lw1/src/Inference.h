#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

#define UP

using namespace std;

#ifndef INFERENCE_H
#define INFERENCE_H

namespace Inference {
    namespace Propositional {
        //iterators typedef
        typedef vector< vector<int> >::iterator vec_vec_it;
        typedef set<int>::iterator set_it;
        typedef vector<int>::iterator vec_it;
        typedef vector<int>::const_iterator cvec_it;

        // Class for clause of boolean sat problem
        class Clause : public vector<int> {
        public:
            // void push_back(int e) { insert(e); } // See comment at lw1_solver.cc
            vector<int>::const_iterator find(int p) const {
                vector<int>::const_iterator it = cbegin();
                for (; it != end(); it++)
                    if (*it == p) return it;
                return it;
            }
        };

        class CNF : public vector<Clause> {
            typedef CNF::const_iterator const_vec_set_it;
        public:
            CNF() : vector<Clause>() { };
            CNF(const CNF& cnf) : vector<Clause>(cnf.begin(), cnf.end()) { };
            int calculate_max() const {
                int imax = 0;
                for (auto it = begin(); it != end(); it++) {
                    int L1 =  abs(*(it->begin()));
                    int L2 =  abs(*(it->rbegin()));
                    imax = max(L1, max(L2, imax));
                }
                return imax;
            }
        };

        class UnitPropagation {
        public:
            // PROVISIONAL: This method should make the class abstract,
            // in order to use better and implementations of reduce under
            // classic UP transparently.
            // virtual void solve() = 0;
        };

        class DPLL: public UnitPropagation {
            public:
            DPLL() { };
            void solve(const CNF &a, CNF &b);
            struct compare {   // Overloading <
                bool operator() (Clause a, Clause b) { return a.size() < b.size(); }
            } compare;

        };


        class WatchedLiterals : public UnitPropagation {
        private:
            vector<bool> propagated;
            vector<bool> satisfied;  //satisfied clauses
            vector< vector<int> > inverted_index;
            vector< pair<cvec_it, cvec_it> > watched;
            int imax;
            cvec_it replace(const CNF &cnf, vector<int> &assigned, int clause);

            void InvertedIndex(const CNF &cnf);
            virtual bool propagate(const CNF &cnf, vector<int> &assigned, int p);
        public:
            WatchedLiterals() { };
            void initialize(const CNF &cnf);
            // PROVISIONAL: This method should make the class abstract,
            // in order to use better and implementations of reduce under
            // classic UP transparently.
            // virtual void reduce() = 0;
            void solve(const CNF &cnf, vector<int> &assigned);
            void lookahead(const CNF &cnf, vector<int> &assigned);
        };
    } // Propositional namespace
} // Inference namespace

#endif
