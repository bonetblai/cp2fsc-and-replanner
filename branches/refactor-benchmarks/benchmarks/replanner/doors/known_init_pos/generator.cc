#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Instance {
    int n_pos_;
    int n_instances_;
    vector<vector<int> > instances_;
    Instance(int p, int n) : n_pos_(p), n_instances_(n) {
        assert(p % 2 == 1);
        instances_.reserve(n_instances_);
        for( int i = 0; i < n_instances_; ++i ) {
            vector<int> instance(n_pos_, 0);
            for( int p = 1; p < n_pos_; p += 2 )
                instance[p] = lrand48() % n_pos_;
            instances_.push_back(instance);
        }
    }
};

void generate_problem(ostream &os, const Instance &ins) {
    int n_pos = ins.n_pos_, n_instances = ins.n_instances_;

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
    for( int i = 0; i < n_instances; ++i ) {
        const vector<int> &instance = ins.instances_[i];
        os << "    (:hidden";
        for( int p = 1; p < n_pos; p += 2 ) {
            os << " (door p" << p+1 << " p" << instance[p]+1 << ")";
        }
        os << ")" << endl;
    }

    // goal situation
    os << "    (:goal (at p" << n_pos << " p" << 1+(n_pos/2) << "))" << endl;

    // end
    os << ")"  << endl;
}

int main(int argc, const char **argv) {
    unsigned short seed[3];
    if( argc != 4 ) {
        cerr << "Usage: generator <seed> <n_pos:odd> <n_instances>" << endl;
        return -1;
    }

    ++argv;
    seed[0] = seed[1] = seed[2] = (unsigned short)atoi(*argv++);
    seed48(seed);

    int n_pos = atoi(*argv++);
    int n_instances = atoi(*argv++);
    assert(n_pos % 2 == 1);
    Instance ins(n_pos, n_instances);
    generate_problem(cout, ins);
    return 0;
}

