#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef INFERENCE_H
#define INFERENCE_H

namespace Inference {
    namespace Propositional {
        //iterators typedef
        typedef vector< vector<int> >::iterator vec_vec_it;
        typedef set<int>::iterator set_it;
        typedef vector<int>::iterator vec_it;

        class Clause : public set<int> {
        public:
            void push_back(int e) { insert(e); } // See comment at lw1_solver.cc
            struct compare {   // Overloading <
                bool operator() (Clause a, Clause b) { return a.size() < b.size(); }
            } compare;
        };

        class CNF : public vector<Clause> {
            typedef CNF::const_iterator const_vec_set_it;
        public:
            CNF() : vector<Clause>() { };
            CNF(const CNF& a) : vector<Clause>(a.begin(), a.end()) { };
            int calculate_max() const {
                int imax = 0;
                for (const_vec_set_it it = begin(); it != end(); it++) {
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
        };


        class WatchedLiterals : public UnitPropagation {
        private:
            vector<bool> propagated;
            vector<bool> satisfied;  //satisfied clauses
            vector< vector<int> > inverted_index;
            vector< pair<set_it, set_it> > watched;
            int imax;
            set_it replace(const CNF &a, vector<int> &assigned, int clause);

            void InvertedIndex(const CNF &a);
            virtual bool propagate(const CNF &a, vector<int> &assigned, int p);
        public:
            WatchedLiterals() { };
            void initialize(const CNF &a);
            // PROVISIONAL: This method should make the class abstract,
            // in order to use better and implementations of reduce under
            // classic UP transparently.
            // virtual void reduce() = 0;
            void solve(const CNF &a, vector<int> &assigned);
        };
    } // Propositional namespace
} // Inference namespace

#endif
