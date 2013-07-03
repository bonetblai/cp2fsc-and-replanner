#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Instance {
    int n_pos;
    int n_balls;
    vector<int> balls;
    Instance(int p, int b) : n_pos(p), n_balls(b) {
        // place balls
        for( int b = 0; b < n_balls; ++b ) {
            int p = lrand48() % n_pos, q = lrand48() % n_pos;
            balls.push_back(q*n_pos + p);
        }
    }
};

void generate_problem(ostream &os, const Instance &ins) {
    int n_pos = ins.n_pos, n_balls = ins.n_balls;

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
    os << "    (:hidden";
    for( int b = 0; b < n_balls; ++b ) {
        int pos = ins.balls[b], p = pos % n_pos, q = pos / n_pos;
        os << " (ball-at b" << b+1 << " p" << p+1 << " p" << q+1 << ")";
    }
    os << ")" << endl;

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
    if( argc != 4 ) {
        cerr << "Usage: generator <seed> <n_pos> <n-balls>" << endl;
        return -1;
    }

    ++argv;
    seed[0] = seed[1] = seed[2] = (unsigned short)atoi(*argv++);
    seed48(seed);

    int n_pos = atoi(*argv++);
    int n_balls = atoi(*argv++);
    Instance ins(n_pos, n_balls);
    generate_problem(cout, ins);
    return 0;
}

