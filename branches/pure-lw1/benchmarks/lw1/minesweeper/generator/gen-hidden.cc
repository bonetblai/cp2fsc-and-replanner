#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

int nrows = 0;
int ncols = 0;
int dim = 0;

inline int col(int p) { return 1 + (p % ncols); }
inline int row(int p) { return 1 + (p / ncols); }
inline int relative_position_from(int p, int dir) {
    int r = row(p) - 1, c = col(p) - 1, dr = 0, dc = 0;
    if( dir == 4 ) return -1;
    if( dir < 3 ) dr = -1;
    if( dir > 5 ) dr = 1;
    if( dir % 3 == 0 ) dc = -1;
    if( dir % 3 == 2 ) dc = 1;
    int q = (r + dr) * ncols + (c + dc);
    if( (dir == 4) || (r + dr < 0) || (r + dr >= nrows) || (c + dc < 0) || (c + dc >= ncols) )
        return -1;
    else
        return q;
}

void read_minefield(vector<int> &minefield, const char *str) {
    stringstream ss(str);
    minefield.clear();
    minefield.reserve(dim);
    for( int i = 0; i < dim; ++i ) {
        string e;
        ss >> e;
        minefield.push_back(e == "*" ? -1 : atoi(e.c_str()));
    }
}

void print_minefield(ostream &os, const vector<int> &minefield) {
    //os << ";; Minefield:" << endl;
    for( int p = 0; p < dim; ++p ) {
        if( p % ncols == 0 ) os << "    ;;";
        if( minefield[p] == -1 )
            os << " *";
        else
            os << " " << minefield[p];
        if( p % ncols == ncols - 1 ) os << "     row=" << row(p) << endl;
    }
}

void read_execution(vector<pair<int, int> > &execution, const char *str) {
    stringstream ss(str);
    execution.clear();
    execution.reserve(dim);
    for( int i = 0; i < dim; ++i ) {
        string action, dummy;
        int row, col, obs;
        ss >> action >> col >> row >> dummy >> obs;
        assert((action == "open") || (action == "flag"));
        assert(dummy == "obs");
        assert((action == "open") || (obs == -1));
        int pos = row * ncols + col;
        //cout << "PUSH: " << action << " " << col << " " << row << " " << dummy << " " << obs << " " << pos << endl;
        execution.push_back(make_pair(pos, obs));
    }
}

void emit_hidden(ostream &os, const vector<int> &minefield, const vector<pair<int, int> > &execution) {
    //print_minefield(os, minefield);
    //os << endl;

    int first_pos = execution[0].first, first_obs = execution[0].second;
    assert(first_obs == 0);

    os << "    (:hidden (first-move p" << col(first_pos) << "-" << row(first_pos) << ")";

    for( int p = 0; p < dim; ++p ) {
        if( minefield[p] == -1 ) {
            os << " (mine-at p" << col(p) << "-" << row(p) << ")";
        } 
#if 0
        int mine_count = 0;
        for( int d = 0; d < 9; ++d ) {
            int q = relative_position_from(p, d);
            if( (q != -1) && (minefield[q] == -1) ) ++mine_count;
        }
        os << "        (obs" << mine_count << "-at p" << col(p) << "-" << row(p) << ")" << endl;
#endif
    }

    os << ")" << endl;
}

void usage(ostream &os) {
    os << "Usage: gen-hidden <execution-file>" << endl;
    exit(255);
}

int main(int argc, const char **argv) {
    vector<int> minefield;
    vector<pair<int, int> > execution;

    if( argc < 2 ) usage(cerr);

    char buff[102400];
    ifstream is(*++argv);
    int nrecords = 0;
    is >> ncols >> nrows >> nrecords;
    dim = ncols * nrows;

    cout << "(define (problem h" << ncols << "x" << nrows << ")" << endl;

    is.getline(buff, 102400);
    for( int i = 0; i < nrecords; ++i ) {
        is.getline(buff, 102400);
        assert(is.gcount() < 102400);
        cout << "    ; " << buff << endl;
        read_minefield(minefield, &buff[strlen("minefield: ")]);
        is.getline(buff, 102400);
        assert(is.gcount() < 102400);
        read_execution(execution, &buff[strlen("execution: ")]);
        emit_hidden(cout, minefield, execution);
    }
    is.close();

    cout << ")" << endl << endl;

    return 0;
}

