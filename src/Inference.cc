#include "Inference.h"

void Inference::Propositional::Clause::push_back(int e) {
    insert(e); // See comment in lw1_solver.cc
}

int Inference::Propositional::CNF::calculate_max() {
   int imax = 0;
    for (CNF::const_iterator it = begin(); it != end(); it++) {
        int L1 =  abs(*(it->begin()));
        int L2 =  abs(*(it->rbegin()));
        imax = max(L1, max(L2, imax));
    }
    return imax;
}

void Inference::Propositional::UnitPropagation::reduce(const CNF &a, CNF &b) {
    b = CNF(a);

    bool change = true;
    while (change) {
        change = false;
        sort(b.begin(), b.end(), this->compare);
        for (CNF::iterator it = b.begin(); it != b.end(); it++) {
            if (it->size() == 1) {
                int L = *(it->begin());
                for (CNF::iterator clause = it + 1; clause != b.end(); clause++) {
                    if (it == clause) continue;
                    if (clause->find(L) != clause->end()) {
                        b.erase(clause);
                        clause--;
                        change = true;
                    } else if (clause->find(-L) != clause->end()) {
                        clause->erase(-L);
                        change = true;
                    }
                }
            }
        }
    }
}
