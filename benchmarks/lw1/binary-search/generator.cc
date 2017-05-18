/*
 *  Copyright (C) 2011 - <date> Blai Bonet, Universidad Simon Bolivar
 *
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 *  Blai Bonet, bonet@ldc.usb.ve, bonetblai@gmail.com
 *
 */

#include <iostream>

using namespace std;

void generate_problem(ostream &os, int num_states) {
    os << "(define (problem bs-p" << num_states << ")" << endl
       << "    (:domain binary-search)" << endl
       << "    (:objects";
    for( int i = 0; i < num_states; ++i )
        os << " p" << i;
    os << " - state)" << endl
       << "    (:init" << endl
       << "        (discover-not-yet-attempted)" << endl;
    for( int i = 0; i < num_states - 1; ++i ) {
        os << "        ";
        for( int j = i + 1; j < num_states; ++j ) {
            if( j > i + 1 ) os << " ";
            os << "(lt p" << i << " p" << j << ")";
        }
        os << endl;
    }
    os << "    )" << endl
       << "    (:goal (finish))" << endl
       << ")" << endl << endl;
}

void generate_hidden(ostream &os, int num_states) {
    os << "(define (problem bs-p" << num_states << ")" << endl;
    for( int i = 0; i < num_states; ++i )
        os << "    (:hidden (secret p" << i << "))" << endl;
    os << ")" << endl << endl;
}

int main(int argc, const char **argv) {
    --argc;
    ++argv;
    if( argc < 1 ) {
        cout << "generator <num-states>" << endl;
        return -1;
    }
    --argc;
    int num_states = atoi(*argv++);

    generate_problem(cout, num_states);
    return 0;
}

