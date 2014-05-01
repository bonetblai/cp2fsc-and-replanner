#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
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
    pair<int,int> init;
    pair<int,int> goal;
    vector<pair<int,int> > walls;
    vector<pair<int,int> > non_walls;
    Instance(string mfile)
      : mapfile(mfile), map(0), n_xpos(0), n_ypos(0), init(0,0), goal(0,0) {
        char *fname = strdup(mapfile.c_str()), *str = basename(fname);
        char *ptr = &str[strlen(str)-4];
        *ptr = '\0';
        name = str;

        ifstream is(mapfile.c_str());
        assert(!is.fail());
        map = new Map(is);
        is.close();
        n_xpos = map->width;
        n_ypos = map->height;
        for( int x = 0; x < n_xpos; ++x ) {
            for( int y = 0; y < n_ypos; ++y ) {
                if( map->wall(x,y) )
                    walls.push_back(make_pair(x,y));
                else
                    non_walls.push_back(make_pair(x,y));
            }
        }
        if( non_walls.size() == 0 ) {
            cerr << "Error: " << name << " has no free ground" << endl;
            exit(-1);
        }
        init = non_walls[lrand48() % non_walls.size()];
        goal = init;
        while( goal == init )
            goal = non_walls[lrand48() % non_walls.size()];
    }
    ~Instance() { delete map; }
    void print(ostream &os) const {
        cout << ";; dim=(" << n_xpos << "," << n_ypos << ")" << endl;
        cout << ";; init=(" << init.first+1 << "," << init.second+1 << ")" << endl;
        cout << ";; goal=(" << goal.first+1 << "," << goal.second+1 << ")" << endl;
        for( int y = n_ypos-1; y >= 0; --y ) {
            os << ";; ";
            for( int x = 0; x < n_xpos; ++x ) {
                if( init == make_pair(x,y) )
                    os << "I";
                else if( goal == make_pair(x,y) )
                    os << "G";
                else
                    os << (map->wall(x,y) ? '@' : '.');
            }
            os << endl;
        }
    }
};

void generate_problem(ostream &os, const Instance &ins) {
    int n_xpos = ins.n_xpos, n_ypos = ins.n_ypos;

    ins.print(os);
    os << endl;

    os << "(define (problem map-" << ins.name << ")" << endl
       << "    (:domain freespace)" << endl;

    // objects
    os << "    (:objects" << endl
       << "       ";
    for( int x = 0; x < n_xpos; ++x )
        os << " x" << x+1;
    os << " - xpos" << endl
       << "       ";
    for( int y = 0; y < n_ypos; ++y )
        os << " y" << y+1;
    os << " - ypos)" << endl;

    // initial situation
    os << "    (:init" << endl
       << "       ";
    for( int x = 0; x < n_xpos-1; ++x )
        os << " (suc-x x" << x+1 << " x" << x+2 << ")";
    os << endl
       << "       ";
    for( int y = 0; y < n_ypos-1; ++y )
        os << " (suc-y y" << y+1 << " y" << y+2 << ")";
    os << endl;

    os << "       (at x" << ins.init.first+1 << " y" << ins.init.second+1 << ")" << endl;

    for( int x = 0; x < n_xpos; ++x ) {
        for( int y = 0; y < n_ypos; ++y ) {
            os << "       "
               << "(invariant (wall x" << x+1 << " y" << y+1 << ")"
               << " (not (wall x" << x+1 << " y" << y+1 << ")))" << endl;
        }
    }

    os << "    )" << endl;

    // hidden situation
    bool nline = false;
    os << "    (:hidden" << endl;
    for( int i = 0; i < ins.walls.size(); ++i ) {
        int x = ins.walls[i].first, y = ins.walls[i].second;
        if( i%6 == 0 ) os << "      ";
        os << " (wall x" << x+1 << " y" << y+1 << ")";
        if( i%6 == 5 ) {
            nline = true;
            os << endl;
        }
    }
    os << (nline ? "    " : "") << ")" << endl;

    // goal situation
    os << "    (:goal (at x" << ins.goal.first+1 << " y" << ins.goal.second+1 << "))" << endl;

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

