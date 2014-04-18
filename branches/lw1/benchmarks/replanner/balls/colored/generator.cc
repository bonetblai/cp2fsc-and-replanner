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
    int n_cols;
    vector<int> colored_spots;
    vector<vector<int> > colored_balls;
    Instance(int p, int b, int c)
      : n_pos(p), n_balls(b), n_cols(c) {

        // place spots: one for each color
        for( int c = 0; c < n_cols; ++c ) {
            int p = lrand48() % n_pos, q = lrand48() % n_pos;
            colored_spots.push_back(q*n_pos + p);
            //cout << "spot(" << p+1 << "," << q+1 << "," << c+1 << ")" << endl;
        }

        // calculate number of balls for each color
        vector<int> num(n_cols, 0);
        int budget = n_balls;
        for( int c = 0; c < n_cols-1; ++c ) {
            num[c] = lrand48() % budget;
            budget -= num[c];
        }
        num[n_cols-1] = budget;

        // place balls
        for( int c = 0; c < n_cols; ++c ) {
            vector<int> balls(num[c], 0);
            for( int i = 0; i < num[c]; ++i ) {
                int p = lrand48() % n_pos, q = lrand48() % n_pos;
                balls[i] = q*n_pos + p;
                //cout << "ball(" << p+1 << "," << q+1 << "," << c+1 << ")" << endl;
            }
            colored_balls.push_back(balls);
        }

    }
};

void generate_problem(ostream &os, const Instance &ins) {
    int n_pos = ins.n_pos, n_balls = ins.n_balls, n_cols = ins.n_cols;

    os << "(define (problem n" << n_pos << "-b" << n_balls << "-c" << n_cols << ")" << endl
       << "    (:domain colored-balls)" << endl;

    // objects
    os << "    (:objects" << endl
       << "       ";
    for( int p = 0; p < n_pos; ++p )
        os << " p" << p+1;
    os << " - pos" << endl
       << "       ";
    for( int b = 0; b < n_balls; ++b )
        os << " b" << b+1;
    os << " - ball" << endl
       << "       ";
    for( int c = 0; c < n_cols; ++c )
        os << " c" << c+1;
    os << " - color)" << endl;

    // initial situation
    os << "    (:init" << endl
       << "       ";
    for( int p = 0; p < n_pos-1; ++p )
        os << " (suc p" << p+1 << " p" << p+2 << ")";
    os << endl
       << "        (at p1 p1)" << endl
       << "        (empty-arm)" << endl;

    for( int c = 0; c < n_cols; ++c ) {
        int spot = ins.colored_spots[c], p = spot % n_pos, q = spot / n_pos;
        os << "        (spot p" << p+1 << " p" << q+1 << " c" << c+1 << ")" << endl;
    }

    for( int b = 0; b < n_balls; ++b )
        os << "        (not (ball-at-spot b" << b+1 << "))" << endl;

    for( int b = 0; b < n_balls; ++b ) {
        os << "        (invariant";
        for( int c = 0; c < n_cols; ++c )
            os << " (ball-color b" << b+1 << " c" << c+1 << ")";
        os << ")" << endl;
    }

    for( int b = 0; b < n_balls; ++b ) {
        os << "        (invariant (ball-at-spot b" << b+1 << ")";
        for( int p = 0; p < n_pos; ++p ) {
            os << endl << "                  ";
            for( int q = 0; q < n_pos; ++q )
                os << " (ball-pos b" << b+1 << " p" << p+1 << " p" << q+1 << ")";
        }
        os << ")" << endl;
    }

    os << "    )" << endl;

    // hidden situation
    os << "    (:hidden" << endl;
    int b = 0;
    for( int c = 0; c < n_cols; ++c ) {
        for( int i = 0; i < ins.colored_balls[c].size(); ++i, ++b ) {
            int pos = ins.colored_balls[c][i], p = pos % n_pos, q = pos / n_pos;
            os << "        " << "(ball-pos b" << b+1 << " p" << p+1 << " p" << q+1 << ")"
               << " (ball-color b" << b+1 << " c" << c+1 << ")" << endl;
        }
    }
    assert(b == n_balls);
    os << "    )" << endl;

    // goal situation
    os << "    (:goal (and";
    for( int b = 0; b < n_balls; ++b )
        os << " (ball-at-spot b" << b+1 << ")";
    os << "))" << endl;

    // end
    os << ")"  << endl;
}

int main(int argc, const char **argv) {
    unsigned short seed[3];
    if( argc != 5 ) {
        cerr << "Usage: generator <seed> <n_pos> <n-balls> <n-cols>" << endl;
        return -1;
    }

    ++argv;
    seed[0] = seed[1] = seed[2] = (unsigned short)atoi(*argv++);
    seed48(seed);

    int n_pos = atoi(*argv++);
    int n_balls = atoi(*argv++);
    int n_cols = atoi(*argv++);
    Instance ins(n_pos, n_balls, n_cols);
    generate_problem(cout, ins);
    return 0;
}

