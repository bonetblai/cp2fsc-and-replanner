#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include "Inference.h"
using namespace std;

typedef Inference::Propositional::CNF::const_iterator const_vec_set_it;
typedef vector< vector<int> >::iterator vec_vec_it;
typedef set<int>::iterator set_it;
typedef vector<int>::iterator vec_it;

void Inference::Propositional::DPLL::solve(const CNF &a, CNF &b) {
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


void Inference::Propositional::WatchedLiterals::InvertedIndex(const CNF &a) {
    inverted_index.assign(imax + 1, vector<int>());
    int clause = 0;
    for (const_vec_set_it it = a.begin(); it != a.end(); it++) {
        for (set_it s_it = it->begin(); s_it != it->end(); s_it++) {
            inverted_index[ abs(*s_it) ].push_back(clause);
        }
        clause++;
    }
}

void Inference::Propositional::WatchedLiterals::initialize(const CNF &a) {
    imax = a.calculate_max();
    satisfied.assign(a.size(), false);
    propagated.assign(imax + 1, false); //anything has been propagated
    InvertedIndex(a);

    //watch first (0) and last (size - 1) element
    for (int i = 0; i < a.size(); i++)
        watched.push_back(pair<set_it, set_it>(a[i].begin(),
                                               --a[i].end()));
};


void Inference::Propositional::WatchedLiterals::solve(const CNF &a,
                                                      vector<int> &assigned) {
    initialize(a);
    assigned.assign(imax + 1, -1);      //initially, every proposition is unassigned
    for (const_vec_set_it it = a.begin(); it != a.end(); it++) {
        int p = *(it->begin());
        if ( (it->size() == 1) && !propagated[ abs(p) ] ) {
            assigned[ abs(p) ] = p > 0 ? 1 : 0;
            assert(propagate(a, assigned, abs(p)));
            propagated[ abs(p) ] = true;
        }
    }
}

set_it Inference::Propositional::WatchedLiterals::replace(const CNF &a,
                                                          vector<int> &assigned,
                                                          int clause) {
    set_it w1 = a[clause].begin(), w2 = watched[clause].second;
    for (; w1 != a[clause].end(); w1++)
        if (assigned[ abs(*w1) ] == -1 && w1 != w2) break;
    return w1;
}

bool Inference::Propositional::WatchedLiterals::propagate(const CNF &a,
                                                          vector<int> &assigned,
                                                          int prop) {
    bool no_conflict = true;
    assert(prop > 0);
    vector<int> cp = vector<int>(); //index of clauses where not p exist
    int value = assigned[prop] ? prop : -prop;
    //adding clauses with negative watched literals associated with p
    for (int i = 0; i < inverted_index[prop].size(); i++) {
        int clause = inverted_index[prop][i];
        set_it w1 = watched[clause].first, w2 = watched[clause].second;
        bool is_watched = value == -1 * (* w1) || value == -1 * (* w2);

        if (is_watched && !satisfied[clause])
            cp.push_back(clause);
    }

    for (int i = 0; i < cp.size(); i++) {
        int clause = cp[i];
        if (*(watched[clause].first) != -1 * value)
            swap(watched[clause].first, watched[clause].second);

        set_it w1 = replace(a, assigned, clause), w2 = watched[clause].second;
        // If w1 cannot be replaced and w2 is unnassigned, recursive call

        int new_prop = *w2;
        if (w1 != a[clause].end()) {
            watched[clause].first = w1;
        } else if (assigned[ abs(new_prop) ] == -1) {
            assigned[ abs(new_prop) ] = new_prop > 0 ? 1 : 0;
            if (!propagate(a, assigned, abs(new_prop)))
                no_conflict = false;
            // propagated[ abs(p1) ] = true;
        } else if ((assigned[ abs(new_prop) ] ? 1 : -1) * (new_prop) < 0) {
            // If w1 cannot be replaced and w2 is false there's conflict
            no_conflict = false;
        }
    }
    return no_conflict;
}

void Inference::Propositional::WatchedLiterals::lookahead(const CNF &a,
                                                        vector<int> &assigned) {

    vector<int> assigned_cp;
    for (int i = 1; i < assigned.size(); ++i) {
        assigned_cp = vector<int>(assigned);

        if (assigned[i] == -1) {   //not assigned yet
            assigned_cp[i] = 1;
            if (! propagate(a, assigned_cp, i)) {
                assigned[i] = 0;
                /////////////////////
                //Testing purposes //
                /////////////////////
                assigned_cp = vector<int>(assigned);
                assigned_cp[i] = 0;
                assert(propagate(a, assigned_cp, i));
                /////////////////////
                //Testing purposes //
                /////////////////////
            } else {
                assigned_cp = vector<int>(assigned);
                assigned_cp[i] = 0;
                if(!propagate(a, assigned_cp, i)) {
                    assigned[i] = 1;
                }
            }
        }
    }
}
