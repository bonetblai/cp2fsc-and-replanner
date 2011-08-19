#include <stdlib.h>
#include <iostream>

using namespace std;

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

#define FORW  0
#define TURNL 1
#define TURNR 2

#define NOWALL 0
#define WALL   1

const char *aname[] = { "forw", "turn-l", "turn-r" };
const char *oname[] = { "nowall", "wall" };
const char *hname[] = { "north", "east", "south", "west" };

int xdim, ydim;

struct fsc_t {
    int nstates_, nobs_;
    pair<int,int> *table_;
    fsc_t(int nstates, int nobs) : nstates_(nstates), nobs_(nobs), table_(new pair<int,int>[nstates*nobs]) { }
    ~fsc_t() { delete[] table_; }
    pair<int,int>& operator()(int q, int o) { return table_[q*nobs_+o]; }
    const pair<int,int>& operator()(int q, int o) const { return table_[q*nobs_+o]; }
};

struct state_t {
    int x_, y_, h_;
    state_t() : x_(0), y_(0), h_(0) { }
    void apply(int a) {
        if( a == FORW ) {
            switch( h_ ) {
                case NORTH: y_ = y_ < ydim-1 ? y_+1 : y_; break;
                case SOUTH: y_ = y_ > 0 ? y_-1 : y_; break;
                case EAST: x_ = x_ < xdim-1 ? x_+1 : x_; break;
                case WEST: x_ = x_ > 0 ? x_-1 : x_; break;
            }
        } else if( a == TURNR ) {
            h_ = (h_+1)%4;
        } else {
            h_ = (h_+3)%4;
        }
    }
    int obs() const {
        switch( h_ ) {
            case NORTH: if( y_ == ydim-1 ) return 1; break;
            case EAST: if( x_ == xdim-1 ) return 1; break;
            case SOUTH: if( y_ == 0 ) return 1; break;
            case WEST: if( x_ == 0 ) return 1; break;
        }
        return 0;
    }
    void print(ostream &os) const { os << "(" << x_ << "," << y_ << "," << hname[h_] << ")"; }
};

inline ostream& operator<<(ostream &os, const state_t &s) { s.print(os); return os; }

void loop(int q0, state_t s0, const fsc_t &fsc) {
    int q = 0;
    state_t s = s0;
    while( true ) {
        pair<int,int> p = fsc(q,s.obs());
        cout << s << " q" << q << " " << oname[s.obs()] << " " << aname[p.second] << endl;
        q = p.first;
        s.apply(p.second);
    }
}

int main(int argc, char **argv) {
    xdim = atoi(argv[1]);
    ydim = atoi(argv[2]);

    fsc_t fsc(2,2);
    fsc(0,NOWALL) = make_pair(1,TURNR);
    fsc(0,WALL) = make_pair(1,TURNL);
    fsc(1,NOWALL) = make_pair(0,FORW);
    fsc(1,WALL) = make_pair(1,TURNR);

    state_t s0;
    loop(0, s0, fsc);
    return 0;
}

