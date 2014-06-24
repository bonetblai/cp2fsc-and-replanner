#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <deque>
#include <set>
#include <cassert>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

using namespace std;

struct Map {
    int height;
    int width;
    int *map;
    Map(istream &is) : height(0), width(0), map(0) {
        string token;
        is >> token;
        assert(token == "type");
        is >> token >> token;
        assert(token == "height");
        is >> height >> token;
        assert(token == "width");
        is >> width >> token;
        assert(token == "map");
        assert(height > 0);
        assert(width > 0);
        map = new int[height*width];
        for( int y = height-1; y >= 0; --y ) {
            for( int x = 0; x < width; ++x ) {
                char c;
                is >> c;
                map[y*width + x] = c == '.' ? 0 : 1;
            }
        }
    }
    ~Map() { delete map; }
    bool wall(int x, int y) const { return map[y*width + x] == 1; }
};

struct Instance {
    string mapfile;
    string name;
    Map *map;
    int n_xpos;
    int n_ypos;
    int init;
    int wumpus;
    vector<bool> reachable;
    vector<int> reachable_space;
    vector<int> walls;
    vector<int> non_walls;
    Instance(string mfile)
      : mapfile(mfile), map(0), n_xpos(0), n_ypos(0), init(0), wumpus(0) {
        char *fname = strdup(mapfile.c_str()), *str = basename(fname);
        char *ptr = &str[strlen(str)-4];
        *ptr = '\0';
        name = str;

        // read map and calculate basic info
        ifstream is(mapfile.c_str());
        assert(!is.fail());
        map = new Map(is);
        is.close();
        n_xpos = map->width;
        n_ypos = map->height;
        for( int x = 0; x < n_xpos; ++x ) {
            for( int y = 0; y < n_ypos; ++y ) {
                if( wall(x,y) )
                    walls.push_back(x*n_ypos + y);
                else
                    non_walls.push_back(x*n_ypos + y);
            }
        }

        if( non_walls.size() == 0 ) {
            cerr << "Error: " << name << " has no free ground" << endl;
            exit(-1);
        }

        // set initial position and calculate reachable positions
        init = non_walls[lrand48() % non_walls.size()];
        reachable = vector<bool>(n_xpos*n_ypos, false);
        
        deque<int> q;
        q.push_back(init);
        reachable[init] = true;
        reachable_space.push_back(init);
        while( !q.empty() ) {
            int s = q.front(), sx = s / n_ypos, sy = s % n_ypos;
            q.pop_front();
            for( int op = 0; op < 4; ++op ) { // 0=up, 1=right, 2=down, 3=left
                int nx = sx, ny = sy;
                if( op == 0 ) {
                    ny++;
                    if( (ny >= n_ypos) || wall(nx,ny) ) continue;
                } else if( op == 1 ) {
                    nx++;
                    if( (nx >= n_xpos) || wall(nx,ny) ) continue;
                } else if( op == 2 ) {
                    ny--;
                    if( (ny < 0) || wall(nx,ny) ) continue;
                } else {
                    nx--;
                    if( (nx < 0) || wall(nx,ny) ) continue;
                }
                int n = nx*n_ypos + ny;
                if( !reachable[n] ) {
                    q.push_back(n);
                    reachable[n] = true;
                    reachable_space.push_back(n);
                }
            }
        }

        // place wumpus in one of reachable positions except init
        wumpus = init;
        while( wumpus == init )
            wumpus = reachable_space[lrand48() % reachable_space.size()];
    }
    ~Instance() { delete map; }
    bool adj(int p1, int p2) const {
        int x1 = p1 / n_ypos, y1 = p1 % n_ypos;
        int x2 = p2 / n_ypos, y2 = p2 % n_ypos;
        if( (x1 == x2) && ((y1 == y2+1) || (y1 == y2-1)) )
            return true;
        if( ((x1 == x2+1) || (x1 == x2-1)) && (y1 == y2) )
            return true;
        return false;
    }
    bool wall(int x, int y) const { return map->wall(x, y); }
    bool wall(pair<int, int> &p) const { return map->wall(p.first, p.second); }
    void print(ostream &os, bool print_wall = true) const {
        os << ";; dim=(" << n_xpos << "," << n_ypos << ")" << endl;
        os << ";; init=(" << init/n_ypos << "," << init%n_ypos << ")" << endl;
        os << ";; wumpus=(" << wumpus/n_ypos << "," << wumpus%n_ypos << ")" << endl;
        for( int y = n_ypos-1; y >= 0; --y ) {
            os << ";; ";
            for( int x = 0; x < n_xpos; ++x ) {
                int s = x*n_ypos + y;
                if( init == s )
                    os << 'I';
                else if( wumpus == s )
                    os << 'w';
                else {
                    if( print_wall )
                        os << (wall(x,y) ? '@' : '.');
                    else
                        os << '.';
                }
            }
            os << endl;
        }
    }
};

void generate_problem(ostream &os, const Instance &ins) {
    int n_xpos = ins.n_xpos, n_ypos = ins.n_ypos;

    ins.print(os);
    os << endl;

    os << "(define (problem " << ins.name << ")" << endl
       << "    (:domain kill-wumpus)" << endl;

    // objects
    os << "    (:objects";
    for( int x = 0; x < n_xpos; ++x ) {
        for( int y = 0; y < n_ypos; ++y ) {
            int p = x*n_ypos + y;
            if( ins.reachable[p] )
                os << " p" << p;
        }
    }
    os << " - pos)" << endl;

    // initial situation
    os << "    (:init" << endl;

    // adjacency
    for( int p = 0; p < n_xpos*n_ypos; ++p ) {
        if( ins.reachable[p] ) {
            int x = p / n_ypos, y = p % n_ypos;
            if( (y+1 < n_ypos) && ins.reachable[x*n_ypos + y+1] )
                os << "       (adj p" << p << " p" << x*n_ypos+y+1 << ")" << endl;
            if( (x+1 < n_xpos) && ins.reachable[(x+1)*n_ypos + y] )
                os << "       (adj p" << p << " p" << (x+1)*n_ypos+y << ")" << endl;
            if( (y-1 >= 0) && ins.reachable[x*n_ypos + y-1] )
                os << "       (adj p" << p << " p" << x*n_ypos+y-1 << ")" << endl;
            if( (x-1 >= 0) && ins.reachable[(x-1)*n_ypos + y] )
                os << "       (adj p" << p << " p" << (x-1)*n_ypos+y << ")" << endl;
        }
    }
    os << endl;

    // initial position
    assert(ins.reachable[ins.init]);
    os << "       (at p" << ins.init << ")" << endl
       << "       (not (stench p" << ins.init << "))" << endl
       << "       (not (wumpus p" << ins.init << "))" << endl;

    // Invariants: (or wumpus(p) -wumpus(p))
    os << endl << "       ; Invariants: (or wumpus(p) -wumpus(p))" << endl;
    for( int i = 0; i < ins.reachable_space.size(); ++i ) {
        int p = ins.reachable_space[i];
        os << "       "
           << "(invariant (wumpus p" << p << ") (not (wumpus p" << p << ")))"
           << endl;
    }

    // Invariants: (or stench(p) -stench(p))
    os << endl << "       ; Invariants: (or stench(p) -stench(p))" << endl;
    for( int i = 0; i < ins.reachable_space.size(); ++i ) {
        int p = ins.reachable_space[i];
        os << "       "
           << "(invariant (stench p" << p << ") (not (stench p" << p << ")))"
           << endl;
    }

    // Invariants: (or -stench(p) wumpus(p1) ... wumpus(p4)) where adj(p,pi)
    os << endl << "       ; Invariants: (or -stench(p) wumpus(p1) .. wumpus(p4))" << endl;
    for( int i = 0; i < ins.reachable_space.size(); ++i ) {
        int p = ins.reachable_space[i];
        os << "       "
           << "(invariant (not (stench p" << p << "))";
        for( int j = 0; j < ins.reachable_space.size(); ++j ) {
            int q = ins.reachable_space[j];
            if( ins.adj(p,q) )
                os << " (wumpus p" << q << ")";
        }
        os << ")" << endl;
    }

    // Invariants: (or stench(p) -wumpus(p')) where adj(p,p')
    os << endl << "       ; Invariants: (or stench(p) -wumpus(p'))" << endl;
    for( int i = 0; i < ins.reachable_space.size(); ++i ) {
        int p = ins.reachable_space[i];
        for( int j = 0; j < ins.reachable_space.size(); ++j ) {
            int q = ins.reachable_space[j];
            if( ins.adj(p,q) ) {
                os << "       "
                   << "(invariant (stench p" << p << ") (not (wumpus p" << q << ")))" << endl;
            }
        }
    }

    // Invariants: (or -wumpus(p) -wumpus(p')) where -adj(p,p')
    os << endl << "       ; Invariants: (or -wumpus(p) -wumpus(p'))" << endl;
    for( int i = 0; i < ins.reachable_space.size(); ++i ) {
        int p = ins.reachable_space[i];
        for( int j = 0; j < ins.reachable_space.size(); ++j ) {
            int q = ins.reachable_space[j];
            if( (p != q) && !ins.adj(p,q) ) {
                os << "       "
                   << "(invariant (not (wumpus p" << p << ")) (not (wumpus p" << q << ")))" << endl;
            }
        }
    }

    // end of initial situation
    os << "    )" << endl;

    // hidden situation
    bool nline = false;
    os << "    (:hidden" << endl;
    int x = ins.wumpus / n_ypos, y = ins.wumpus % n_ypos;
    os << "       (wumpus p" << ins.wumpus << ")";
    if( (y+1 < n_ypos) && ins.reachable[x*n_ypos + y+1] )
        os << " (stench p" << x*n_ypos + y+1 << ")";
    if( (x+1 < n_xpos) && ins.reachable[(x+1)*n_ypos + y] )
        os << " (stench p" << (x+1)*n_ypos + y << ")";
    if( (y-1 >= 0) && ins.reachable[x*n_ypos + y-1] )
        os << " (stench p" << x*n_ypos + y-1 << ")";
    if( (x-1 >= 0) && ins.reachable[(x-1)*n_ypos + y] )
        os << " (stench p" << (x-1)*n_ypos + y << ")";
    os << endl << "    )" << endl;

    // goal situation
    os << "    (:goal (killed))" << endl;

    // end
    os << ")"  << endl;
}

int main(int argc, const char **argv) {
    unsigned short seed[3];
    if( argc != 3 ) {
        cerr << "Usage: generator <seed> <mapfilen>" << endl;
        return -1;
    }

    ++argv;
    seed[0] = seed[1] = seed[2] = (unsigned short)atoi(*argv++);
    seed48(seed);

    string mapfile = *argv++;
    Instance ins(mapfile);
    generate_problem(cout, ins);
    return 0;
}

