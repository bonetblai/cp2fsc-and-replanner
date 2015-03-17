#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string hidden(int dim) {
    ostringstream s;
    s << "(:hidden";
    for( int i = 0; i < (dim >> 1); ++i ) {
        int c = 2 + 2*i, r = lrand48() % dim;
        s << " (opened p" << c << "-" << 1 + r << ")";
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

  cout << "(define (problem doors-" << dim << ")" << endl;
  for( int i = 0; i < n; ++i )
      cout << "    " << hidden(dim) << endl;
  cout << ")" << endl << endl;
  return 0;
}

