#include <iostream>
#include <stdlib.h>

using namespace std;

void usage(ostream &os) {
    os << "usage: gen-problem <ncols> <nrows>" << endl;
}

int main(int argc, const char **argv) {
    if( argc < 3 ) {
        usage(cout);
        exit(255);
    }

    int ncols = atoi(*++argv);
    int nrows = atoi(*++argv);

    cout << "(define (problem p" << ncols << "x" << nrows << ")" << endl
         << "    (:domain mines)" << endl
         << "    (:objects" << endl;

    for( int r = 0; r < nrows; ++r ) {
        cout << "       ";
        for( int c = 0; c < ncols; ++c )
            cout << " p" << 1+c << "-" << 1+r;
        cout << (r == nrows - 1 ? " - pos" : "") << endl;
    }

    cout << "    )" << endl
         << "    (:init" << endl
         << "        (need-start)" << endl
         << endl;

    for( int r = 0; r < nrows; ++r ) {
        for( int c = 0; c < ncols; ++c ) {
            for( int d = 0; d < 8; ++d ) {
                int nr = r, nc = c;
                if( (d == 0) || (d == 3) || (d == 5) ) --nc;
                if( (d == 2) || (d == 4) || (d == 7) ) ++nc;
                if( (d == 0) || (d == 1) || (d == 2) ) --nr;
                if( (d == 5) || (d == 6) || (d == 7) ) ++nr;
                if( (nc < 0) || (nc >= ncols) ) continue;
                if( (nr < 0) || (nr >= nrows) ) continue;
                cout << "        (d" << d << " p" << 1+c << "-" << 1+r << " p" << 1+nc << "-" << 1+nr << ")" << endl;
            }
        }
    }
    cout << endl;

    for( int r = 0; r < nrows; ++r ) {
        for( int c = 0; c < ncols; ++c ) {
            if( (r == 0) && (c == 0) )
                cout << "        (corner-ul p" << 1+c << "-" << 1+r << ")" << endl;
            else if( (r == 0) && (c == ncols - 1) )
                cout << "        (corner-ur p" << 1+c << "-" << 1+r << ")" << endl;
            else if( (r == nrows - 1) && (c == 0) )
                cout << "        (corner-ll p" << 1+c << "-" << 1+r << ")" << endl;
            else if( (r == nrows - 1) && (c == ncols - 1) )
                cout << "        (corner-lr p" << 1+c << "-" << 1+r << ")" << endl;
            else if( r == 0 )
                cout << "        (edge-n p" << 1+c << "-" << 1+r << ")" << endl;
            else if( r == nrows - 1 )
                cout << "        (edge-s p" << 1+c << "-" << 1+r << ")" << endl;
            else if( c == 0 )
                cout << "        (edge-w p" << 1+c << "-" << 1+r << ")" << endl;
            else if( c == ncols - 1 )
                cout << "        (edge-e p" << 1+c << "-" << 1+r << ")" << endl;
            else
                cout << "        (middle p" << 1+c << "-" << 1+r << ")" << endl;
        }
    }
    cout << endl;

    for( int r = 0; r < nrows; ++r ) {
        for( int c = 0; c < ncols; ++c )
            cout << "        (not (done-with p" << 1+c << "-" << 1+r << "))" << endl;
    }
    cout << "    )" << endl;

    cout << "    (:goal (and";
    for( int r = 0; r < nrows; ++r ) {
        for( int c = 0; c < ncols; ++c )
            cout << " (done-with p" << 1+c << "-" << 1+r << ")";
    }
    cout << "))" << endl
         << ")" << endl
         << endl;

    return 0;
}

