#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include "inference.h"
#include "utils.h"
#include "lw1_state.h"

#define DEBUG

using namespace std;

typedef vector<LW1_Instance::Variable*> var_vec;
typedef Inference::Propositional::CNF::const_iterator const_vec_set_it;
typedef vector<Inference::Propositional::Clause> cl_t;
typedef vector< vector<int> >::iterator vec_vec_it;
typedef set<int>::iterator set_it;
typedef vector<int>::iterator vec_it;
typedef vector<int>::const_iterator cvec_it;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector< pair< cvec_it, cvec_it> > vpit;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int>  av_map;


// Static members definitions
// CNF and WL
int Inference::Propositional::WatchedLiterals::frontier_ = 0;
vvi Inference::Propositional::WatchedLiterals::inverted_index_axioms_ = vvi();
int Inference::Propositional::WatchedLiterals::imax_ = 0;
vii Inference::Propositional::WatchedLiterals::watched = vii();

void Inference::Propositional::DPLL::solve(const CNF &a, CNF &b) {
    b = CNF(a);
    bool change = true;
    while( change ) {
        change = false;
        sort(b.begin(), b.end(), this->compare);
        for( CNF::iterator it = b.begin(); it != b.end(); it++ ) {
            if( it->size() == 1 ) {
                int L = *(it->begin());
                for( CNF::iterator clause = it + 1; clause != b.end(); clause++ ) {
                    if( it == clause ) continue;
                    if( clause->find(L) != clause->end() ) {
                        b.erase(clause);
                        clause--;
                        change = true;
                    } else if( clause->find(-L) != clause->end() ) {
                        clause->erase(clause->find(-L));
                        change = true;
                    }
                }
            }
        }
    }
}

// Construct a table of inverted indexes
void Inference::Propositional::WatchedLiterals::setInvertedIndex(const CNF &cnf, vector< vector<int> > &mapper) {
    imax_ = cnf.calculate_max();  // max literate number
    mapper.assign(imax_ + 1, vector<int>());
    int clause = frontier_;
    for( auto it = cnf.begin() + frontier_; it != cnf.end(); it++ ) {
        for( auto s_it = it->begin(); s_it != it->end(); s_it++ ) {
            assert(abs(*s_it) <= imax_);
            mapper[abs(*s_it)].push_back(clause);
        }
        clause++;
    }
}

void Inference::Propositional::WatchedLiterals::initialize_axioms(const CNF &axioms) {
    frontier_ = 0;
    setInvertedIndex(axioms, inverted_index_axioms_);
    frontier_ = axioms.size();

    //watch first (0) and last (size - 1) element
    watched = vii();
    for( int i = 0; i < axioms.size(); i++ )
        watched.push_back(make_pair(0, axioms[i].size() -1 ));

};

// Initialize attributes given a cnf
void Inference::Propositional::WatchedLiterals::initialize(const CNF &cnf) {
    setInvertedIndex(cnf, inverted_index);

    //watch first (0) and last (size - 1) element
    for( int i = frontier_; i < cnf.size(); i++ )
        watched.push_back(make_pair(0, cnf[i].size() -1 ));
};

// Set propositions assignment into assigned vector.
// Every proposition id is mapped to assgined indexes.
void Inference::Propositional::WatchedLiterals::solve(const CNF &cnf, vector<int> &assigned) {
    initialize(cnf);
    assigned.assign(imax_ + 1, -1);      //initially, every proposition is unassigned
    for( auto it = cnf.cbegin(); it != cnf.cend(); it++ ) {
        int p = *(it->begin());
        if( (it->size() == 1) && assigned[abs(p)] == -1 ) {
            assigned[abs(p)] = p > 0 ? 1 : 0;
            if( !propagate(cnf, assigned, abs(p)) ) assert(false);
        }
    }

    // cleaning up clauses after axiom clauses
    watched.erase(watched.begin() + frontier_, watched.end());
}

// Returns true if a proposition is assigned and true
bool Inference::Propositional::WatchedLiterals::is_true(int prop, const vector<int> &assigned) {
    assert(assigned[abs(prop)] != -1);
    return ((assigned[abs(prop)] ? 1 : -1) * prop) > 0;
}

// Returns new watched literal in given clause,
// after one of the watched literals has changed and evaluates to a non-false
// value. It is responsability of the client swapping the non-false watched literal
// into the first watched literal (w1)
int Inference::Propositional::WatchedLiterals::replace(const CNF &cnf, vector<int> &assigned, int clause) {
    for( int w1 = 0, w2 = watched[clause].second; w1 < cnf[clause].size(); w1++ ) {
        if( ((assigned[abs(cnf[clause][w1])] == -1) || is_true(cnf[clause][w1], assigned)) && (w1 != w2) )
            return w1;
    }
    return -1;
}

// Returns true if a value given is being watched in given clause
inline bool Inference::Propositional::WatchedLiterals::isWatched(const CNF &cnf, int clause, int value) {
    return (value == cnf[clause][watched[clause].first]) || (value == cnf[clause][watched[clause].second]);
}

// Construct the vector of clauses indexes associated to the negative of
// a proposition prop. Since it is watched literals algorithm,
// those clauses must watch the value associated with prop.
// This vector is constructed in cp
void Inference::Propositional::WatchedLiterals::add_negative_propositions(const CNF &cnf,
                                                                          const vector<vector<int> > &inv_index,
                                                                          int prop,
                                                                          int value,
                                                                          vector<int> &cp) {
    assert(prop > 0);
    for( int i = 0; i < inv_index[prop].size(); i++ ) {
        int clause = inv_index[prop][i];
        if( isWatched(cnf, clause, -1 * value) ) cp.push_back(clause);
    }
}

// Returns true if a prop can propagated with
// new value set in assigned vector.
// It is client responsability give a proposition (prop > 0)
bool Inference::Propositional::WatchedLiterals::propagate(const CNF &cnf, vector<int> &assigned, int prop) {
    assert(prop > 0);
    bool no_conflict = true;
    vector<int> cp = vector<int>(); //index of clauses where not p exist
    int value = assigned[prop] ? prop : -1 * prop;

    //adding clauses with negative watched literals associated with p
    add_negative_propositions(cnf, inverted_index, prop, value, cp);
    if( prop < inverted_index_axioms_.size() )
        add_negative_propositions(cnf, inverted_index_axioms_, prop, value, cp);

    //for( size_t i = 0; i < inverted_index[prop].size(); i++ ) {
    //    int clause = inverted_index[prop][i];
    //    int w1 = watched[clause].first, w2 = watched[clause].second;
    //    bool is_watched = isWatched(cnf, clause, -1 * value);
    //    if( isWatched(cnf, clause, value) ) cp.push_back(clause);
    //}

    //if( prop < inverted_index_axioms_.size() ) {
    //    for( size_t i = 0; i < inverted_index_axioms_[prop].size(); i++ ) {
    //        int clause = inverted_index_axioms_[prop][i];
    //        cvec_it w1 = watched[clause].first, w2 = watched[clause].second;
    //        bool is_watched = value == -1 * (* w1) || value == -1 * (* w2);
    //        if( is_watched ) cp.push_back(clause);
    //    }
    //}

    for( size_t i = 0; i < cp.size(); i++ ) {
        int clause = cp[i];
        if( (cnf[clause][watched[clause].first]) != -1 * value )
            swap(watched[clause].first, watched[clause].second);

        assert(cnf[clause][watched[clause].first] == -1 * value);

        int w1 = replace(cnf, assigned, clause);
        int w2 = watched[clause].second;
        // If w1 cannot be replaced and w2 is unnassigned, recursive call

        int new_prop = cnf[clause][w2];
        if( w1 != -1 ) {
            watched[clause].first = w1;   // update new watched literal
        } else if( assigned[abs(new_prop)] == -1 ) {
            assigned[abs(new_prop)] = new_prop > 0 ? 1 : 0;
            if( !propagate(cnf, assigned, abs(new_prop)) )
                no_conflict = false;
            // propagated[abs(p1)] = true;
        //} else if( (assigned[abs(new_prop)] ? 1 : -1) * (new_prop) < 0 ) {
        } else if( !is_true(new_prop, assigned) ) {
            // If w1 cannot be replaced and w2 is false there's conflict
            no_conflict = false;
        }
    }
    return no_conflict;
}

// Set new assigned values into assigned vector after apply lookahead algorithm
void Inference::Propositional::WatchedLiterals::lookahead(const CNF &cnf, vector<int> &assigned) {
    vector<int> copy;
    for( size_t i = 1; i < assigned.size(); ++i ) {
        if( assigned[i] != -1 ) continue; // already assigned
        copy = assigned;
        copy[i] = 1;
        if( !propagate(cnf, copy, i) ) { // propagating with copy
            // no other assignment is possible
            assigned[i] = 0;
            if( !propagate(cnf, assigned, i) ) {
                cout << Utils::internal_error() << "fatal error in lw1:inference:up:lookahead" << endl;
                exit(-1);
            }
        } else {
            vector<int> tmp = copy;
            copy = assigned;  // getting back original assigned
            copy[i] = 0;
            // no other assignment is possible and assigned[i] = 1 !
            if( !propagate(cnf, copy, i) ) {
#ifdef DEBUG
                cout << "LOOKAHEAD POSITIVO" << endl;
#endif
                assigned = tmp;
            }
        }
    }
}

// Print clause data
void Inference::Propositional::Clause::print(ostream &os) {
    os << "{ ";
    for( Clause::const_iterator it = cbegin(); it != cend(); it++ )
        os << *it << ", ";
    os << " }";
}

#undef DEBUG

