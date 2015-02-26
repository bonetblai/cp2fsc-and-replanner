#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string hidden_string(int dim, const vector<pair<int, int> > &wumpus, bool full) {
    ostringstream s;
    s << "(:hidden";
    for( int i = 0; i < wumpus.size(); ++i ) {
        int c = wumpus[i].first, r = wumpus[i].second;
        if( full ) s << " (safe p" << r << "-" << c << ")";
        s << " (wumpus-at p" << c << "-" << r << ")";
        if( full ) {
            for( int dc = -1; dc < 2; ++dc ) {
                for( int dr = -1; dr < 2; ++dr ) {
                    if( (dc == 0) && (dr == 0) ) continue;
                    if( (dc != 0) && (dr != 0) ) continue;
                    if( (c + dc < 1) || (c + dc > dim) ) continue;
                    if( (r + dr < 1) || (r + dr > dim) ) continue;
                    s << " (stench p" << c + dc << "-" << r + dr << ")";
                }
            }
            if( i < wumpus.size() - 1 ) s << endl << "            ";
        }
    }
    s << ")";
    return s.str();
}

vector<pair<int, int> > random_hidden(int dim) {
    vector<pair<int, int> > wumpus;
    wumpus.reserve(dim - 2);
    for( int i = 2; i < dim; ++i ) {
        bool t = (lrand48() % 2) == 0;
        int c = t ? i : i + 1, r = t ? i + 1 : i;
        wumpus.push_back(make_pair(c, r));
    }
    return wumpus;
}

vector<pair<int, int> > hidden(int dim, size_t h) {
    vector<pair<int, int> > wumpus;
    wumpus.reserve(dim - 2);
    ostringstream s;
    for( int i = 2; i < dim; ++i ) {
        bool t = ((h >> (dim - 1 - i)) & 0x1) == 0;
        int c = t ? i : i + 1, r = t ? i + 1 : i;
        wumpus.push_back(make_pair(c, r));
    }
    return wumpus;
}

int main(int argc, const char **argv) {
  int dim = atoi(*++argv);
  int s = atoi(*++argv);
  int n = atoi(*++argv);
  bool full = (argc >= 5) && (atoi(*++argv) == 1) ? true : false;

  unsigned short seeds[3];
  seeds[0] = seeds[1] = seeds[2] = s;
  seed48(seeds);

  cout << "(define (problem wumpus" << dim << ")" << endl;
  if( s >= 0 ) {
      for( int i = 0; i < n; ++i )
          cout << "    " << hidden_string(dim, random_hidden(dim), full) << endl;
  } else {
      int max = 1 << (dim - 2);
      int m = (n == 0) || (n > max) ? max : n;
      for( size_t i = 0; i < m; ++i )
          cout << "    " << hidden_string(dim, hidden(dim, i), full) << endl;
  }
  cout << ")" << endl << endl;
  return 0;
}

