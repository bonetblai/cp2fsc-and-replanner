#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Instance {
    int n_pos_;
    int n_balls_;
    int n_placements_;
    vector<vector<int> > placements_;
    Instance(int p, int b, int n) : n_pos_(p), n_balls_(b), n_placements_(n) {
        // place balls
        placements_.reserve(n);
        for( int i = 0; i < n_placements_; ++i ) {
            vector<int> placement(n_balls_, 0);
            for( int b = 0; b < n_balls_; ++b ) {
                int p = lrand48() % n_pos_, q = lrand48() % n_pos_;
                placement[b] = q*n_pos_ + p;
            }
            placements_.push_back(placement);
        }
    }
};

void generate_problem(ostream &os, const Instance &ins) {
    int n_pos = ins.n_pos_, n_balls = ins.n_balls_, n_placements = ins.n_placements_;

    os << "(define (problem n" << n_pos << "-b" << n_balls << ")" << endl
       << "    (:domain balls)" << endl;

    // objects
    os << "    (:objects" << endl
       << "       ";
    for( int p = 0; p < n_pos; ++p )
        os << " p" << p+1;
    os << " - pos" << endl
       << "       ";
    for( int b = 0; b < n_balls; ++b )
        os << " b" << b+1;
    os << " - ball)" << endl;

    // initial situation
    os << "    (:init" << endl
       << "       ";
    for( int p = 0; p < n_pos-1; ++p )
        os << " (suc p" << p+1 << " p" << p+2 << ")";
    os << endl
       << "        (at p1 p1)" << endl;

    for( int b = 0; b < n_balls; ++b )
        os  << "        (not (ball-in-bag b" << b+1 << "))" << endl;

    for( int b = 0; b < n_balls; ++b ) {
        os << "        (invariant (ball-in-bag b" << b+1 << ")";
        for( int p = 0; p < n_pos; ++p ) {
            os << endl << "                  ";
            for( int q = 0; q < n_pos; ++q )
                os << " (ball-at b" << b+1 << " p" << p+1 << " p" << q+1 << ")";
        }
        os << ")" << endl;
    }

    os << "    )" << endl;

    // hidden situation
    for( int i = 0; i < n_placements; ++i ) {
        const vector<int> &placement = ins.placements_[i];
        assert(placement.size() == n_balls);
        os << "    (:hidden";
        for( int b = 0; b < n_balls; ++b ) {
            int pos = placement[b], p = pos % n_pos, q = pos / n_pos;
            os << " (ball-at b" << b+1 << " p" << p+1 << " p" << q+1 << ")";
        }
        os << ")" << endl;
    }

    // goal situation
    os << "    (:goal (and";
    for( int b = 0; b < n_balls; ++b )
        os << " (ball-in-bag b" << b+1 << ")";
    os << "))" << endl;

    // end
    os << ")"  << endl;
}

int main(int argc, const char **argv) {
    unsigned short seed[3];
    if( argc != 5 ) {
        cerr << "Usage: generator <seed> <n_pos> <n-balls> <n-placements>" << endl;
        return -1;
    }

    ++argv;
    seed[0] = seed[1] = seed[2] = (unsigned short)atoi(*argv++);
    seed48(seed);

    int n_pos = atoi(*argv++);
    int n_balls = atoi(*argv++);
    int n_placements = atoi(*argv++);
    Instance ins(n_pos, n_balls, n_placements);
    generate_problem(cout, ins);
    return 0;
}

