#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int dim = 0;
int nrocks = 0;
unsigned short seed[3];

inline bool adjacent(int p, int q) {
    int cp = p / dim, rp = p % dim, cq = q / dim, rq = q % dim;
    if( (cp == cq) && ((rp == 1 + rq) || (rq == 1 + rp)) )
        return true;
    else if( (rp == rq) && ((cp == 1 + cq) || (cq == 1 + cp)) )
        return true;
    else
        return false;
}

inline bool in_range(int p, int q, int h) {
    int cp = p / dim, rp = p % dim, cq = q / dim, rq = q % dim;
    int dist = abs(cp - cq) + abs(rp - rq);
    return dist <= h;
}

void emit_instance(ostream &os, const vector<int> &placement, const vector<vector<bool> > &goodness) {

    os << endl
       << "(define (problem problem-" << dim << "-" << nrocks << "-" << seed[0] << ")" << endl
       << "    (:domain RockSample)" << endl
       << "    (:objects" << endl;

    os << "        ";
    for( int i = 0; i < dim; ++i ) {
        for( int j = 0; j < dim; ++j )
            os << "p" << i << "-" << j << " ";
    }
    os << "- LOCATION" << endl;
    os << "        ";
    for( int i = 0; i < nrocks; ++i ) {
        os << "r" << i << " ";
    }
    os << "- ROCK" << endl
       << "    )" << endl << endl;


    // adjacencies
    os << "    (:init" << endl
       << "        ;; adjacencies" << endl
       << "       ";
    for( int p = 0; p < dim * dim; ++p ) {
        for( int q = 0; q < dim * dim; ++q ) {
            if( adjacent(p, q) ) {
                os << " (adj p" << p/dim << "-" << (p%dim) << " p" << q/dim << "-" << (q%dim) << ")";
            }
        }
    }
    os << endl << endl;

    // agent configuration
    int c = lrand48() % dim, r = lrand48() % dim;
    os << "        ;; agent configuration" << endl
       << "        (agent-at p" << c << "-" << r << ")" << endl
       << "        (antenna-height h0)" << endl
       << "        (not-sensing)" << endl << endl;

    // rock configuration
    os << "        ;; rock configuration" << endl;
    for( int i = 0; i < nrocks; ++i ) {
        int rc = placement[i] / dim, rr = placement[i] % dim;
        os << "        (rock-at r" << i << " p" << rc << "-" << rr << ")" << endl;
        os << "        (invariant (good r" << i << ") (not (good r" << i << ")))" << endl;
    }
    os << endl;

    // "in-range" atoms
    os << "        ;; range calculation" << endl;
    for( int r = 0; r < nrocks; ++r ) {
        for( int p = 0; p < dim * dim; ++p ) {
            for( int h = 0; h < 3; ++h ) {
                if( in_range(placement[r], p, h) ) {
                    os << "        (in-range r" << r << " p" << (p/dim) << "-" << (p%dim) << " h" << h << ")" << endl;
                }
            }
        }
    }
    os << endl;

    // invariants
    os << "        ;; invariants" << endl;
    for( int r = 0; r < nrocks; ++r ) {
        for( int p = 0; p < dim * dim; ++p ) {
            for( int h = 0; h < 3; ++h ) {
                if( in_range(placement[r], p, h) ) {
                    os << "        (invariant (not (good r" << r << ")) (good-rocks-in-range p" << (p/dim) << "-" << (p%dim) << " h" << h << "))" << endl;
                }
            }
        }
    }
    for( int p = 0; p < dim * dim; ++p ) {
        for( int h = 0; h < 3; ++h ) {
            vector<int> rocks;
            rocks.reserve(nrocks);
            for( int r = 0; r < nrocks; ++r ) {
                if( in_range(placement[r], p, h) )
                    rocks.push_back(r);
            }
            if( !rocks.empty() ) {
                os << "        (invariant (not (good-rocks-in-range p" << (p/dim) << "-" << (p%dim) << " h" << h << "))";
                for( int i = 0; i < rocks.size(); ++i ) {
                    os << " (good r" << rocks[i] << ")";
                }
                os << ")" << endl;
            }
        }
    }
    os << "    )" << endl;

    // hidden state
    for( int i = 0; i < goodness.size(); ++i ) {
        const vector<bool> &good = goodness[i];
        os << "    (:hidden";
        for( int r = 0; r < nrocks; ++r ) {
            if( good[r] ) {
                os << " (good r" << r << ")";
                for( int p = 0; p < dim * dim; ++p ) {
                    for( int h = 0; h < 3; ++h ) {
                        if( in_range(placement[r], p, h) ) {
                            os << " (good-rocks-in-range p" << (p/dim) << "-" << (p%dim) << " h" << h << ")";
                        }
                    }
                }
            }
        }
        os << ")" << endl;
    }

    // goal state
    os << "    (:goal (and";
    for( int i = 0; i < nrocks; ++i )
        os << " (done r" << i << ")";
    os << "))" << endl
       << ")" << endl << endl;
}

int main(int argc, const char **argv) {
    if( argc != 5 ) {
        cerr << "Usage: generator <seed> <dim> <nrocks> <nhidden>" << endl;
        return -1;
    }
    
    seed[0] = seed[1] = seed[2] = (unsigned short)atoi(*++argv);
    seed48(seed);

    dim = atoi(*++argv);
    nrocks = atoi(*++argv);
    int nhidden = atoi(*++argv);

    vector<int> rocks(dim * dim, 0);
    for( int i = 0; i < dim * dim; ++i )
        rocks[i] = i;

    vector<int> placement;
    placement.reserve(nrocks);
    for( int i = 0; i < nrocks; ++i ) {
        int p = lrand48() % rocks.size();
        placement.push_back(rocks[p]);
        rocks[p] = rocks.back();
        rocks.pop_back();
    }

    vector<vector<bool> > goodness;
    goodness.reserve(nhidden);
    for( int i = 0; i < nhidden; ++i ) {
        vector<bool> good;
        good.reserve(nrocks);
        for( int j = 0; j < nrocks; ++j )
            good.push_back(lrand48() % 2 == 0);
        goodness.push_back(good);
    }

    emit_instance(cout, placement, goodness);
    return 0;
}

