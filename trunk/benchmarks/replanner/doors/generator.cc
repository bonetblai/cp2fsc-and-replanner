#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Instance {
    int n_pos;
    vector<int> doors;
    Instance(int p) : n_pos(p), doors(p, 0) {
        assert(p % 2 == 1);
        for( int p = 1; p < n_pos; p += 2 ) {
            doors[p] = lrand48() % n_pos;
        }
    }
};

void generate_problem(ostream &os, const Instance &ins) {
    int n_pos = ins.n_pos;

    os << "(define (problem n" << n_pos << ")" << endl
       << "    (:domain colored-balls)" << endl;

    // objects
    os << "    (:objects";
    for( int p = 0; p < n_pos; ++p )
        os << " p" << p+1;
    os << " - pos)" << endl;

    // initial situation
    os << "    (:init" << endl
       << "       ";
    for( int p = 0; p < n_pos-1; ++p )
        os << " (suc p" << p+1 << " p" << p+2 << ")";
    os << endl;

    for( int p = 1; p < n_pos; p += 2 ) {
       os << "       ";
       for( int q = 0; q < n_pos; ++q ) {
           os << " (wall p" << p+1 << " p" << q+1 << ")";
       }
       os << endl;
    }

    os << "        (at p1 p" << 1+(n_pos/2) << ")" << endl;

    for( int p = 1; p < n_pos; p += 2 ) {
       os << "        (invariant";
       for( int q = 0; q < n_pos; ++q ) {
           os << " (door p" << p+1 << " p" << q+1 << ")";
       }
       os << ")" << endl;
    }

    os << "    )" << endl;

    // hidden situation
    os << "    (:hidden";
    for( int p = 1; p < n_pos; p += 2 ) {
        os << " (door p" << p+1 << " p" << ins.doors[p]+1 << ")";
    }
    os << ")" << endl;

    // goal situation
    os << "    (:goal (at p" << n_pos << " p" << 1+(n_pos/2) << "))" << endl;

    // end
    os << ")"  << endl;
}

int main(int argc, const char **argv) {
    unsigned short seed[3];
    if( argc != 3 ) {
        cerr << "Usage: generator <seed> <n_pos:odd>" << endl;
        return -1;
    }

    ++argv;
    seed[0] = seed[1] = seed[2] = (unsigned short)atoi(*argv++);
    seed48(seed);

    int n_pos = atoi(*argv++);
    assert(n_pos % 2 == 1);
    Instance ins(n_pos);
    generate_problem(cout, ins);
    return 0;
}

