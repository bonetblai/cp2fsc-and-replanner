#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>

#ifndef INFERENCE_H
#define INFERENCE_H
#define UP

using namespace std;

// PROVISIONAL: Create classes necessary for expanding the Inference
// and Propositional choices. These tangled namespaces are provisional.
namespace Inference {
    namespace Propositional {
        class Clause : public set<int> {
        public:
            void push_back(int e); // See comment at lw1_solver.cc
        };

        class CNF : public vector<Clause> {
        public:
            CNF() : vector<Clause>() { };
            CNF(const CNF& a) : vector<Clause>(a.begin(), a.end()) { };
            int calculate_max();
        };

        class UnitPropagation {
        public:
            struct compare {
                bool operator() (Clause a, Clause b) { return a.size() < b.size(); }
            } compare;

            UnitPropagation() { };
            // PROVISIONAL: This method should make the class abstract,
            // in order to use better and implementations of reduce under
            // classic UP transparently.
            // virtual void reduce() = 0;
            virtual void reduce(const CNF& a, CNF& b);
        };
    } // Propositional namespace
} // Inference namespace

#endif
