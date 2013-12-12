#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string random_hidden(int dim) {
    ostringstream s;
    s << "(:hidden";
    for( int i = 2; i < dim; ++i ) {
        bool t = (lrand48() % 2) == 0;
        int c = t ? i : i + 1, r = t ? i + 1 : i;
        s << " (wumpus-at p" << c << "-" << r << ")";
    }
    s << ")";
    return s.str();
}

string hidden(int dim, size_t h) {
    ostringstream s;
    s << "(:hidden";
    for( int i = 2; i < dim; ++i ) {
        bool t = ((h >> (dim - 1 - i)) & 0x1) == 0;
        int c = t ? i : i + 1, r = t ? i + 1 : i;
        s << " (wumpus-at p" << c << "-" << r << ")";
    }
    s << ")";
    return s.str();
}

int main(int argc, const char **argv) {
  int dim = atoi(*++argv);
  int s = atoi(*++argv);
  int n = atoi(*++argv);

  unsigned short seeds[3];
  seeds[0] = seeds[1] = seeds[2] = s;
  seed48(seeds);

  cout << "(define (problem wumpus" << dim << ")" << endl;
  if( s >= 0 ) {
      for( int i = 0; i < n; ++i )
          cout << "    " << random_hidden(dim) << endl;
  } else {
      int max = 1 << (dim - 2);
      int m = (n == 0) || (n > max) ? max : n;
      for( size_t i = 0; i < m; ++i )
          cout << "    " << hidden(dim, i) << endl;
  }
  cout << ")" << endl << endl;
  return 0;
}

