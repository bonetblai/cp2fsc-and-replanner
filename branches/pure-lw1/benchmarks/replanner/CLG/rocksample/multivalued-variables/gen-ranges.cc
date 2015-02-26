#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;

int main(int argc, const char **argv) {
    int dim = atoi(*++argv);
    int nh = atoi(*++argv);

    for( int c = 0; c < dim; ++c ) {
        for( int r = 0; r < dim; ++r ) {
            for( int dc = 0; dc <= 1; ++dc ) {
                int nc = c + dc;
                if( (nc < 0) || (nc >= dim) ) continue;
                for( int dr = 0; dr <= 1; ++dr ) {
                    int nr = r + dr;
                    if( (nr < 0) || (nr >= dim) ) continue;
                    if( abs(dc) + abs(dr) > 1 ) continue;
                    if( abs(dc) + abs(dr) == 0 ) continue;
                    cout << "        (adj p" << 1+c << "-" << 1+r << " p" << 1+nc << "-" << 1+nr << ")"
                         << " (adj p" << 1+nc << "-" << 1+nr << " p" << 1+c << "-" << 1+r << ")" << endl;
                }
            }
        }
    }

    cout << endl;

    for( int h = 0; h < nh; ++h ) {
        for( int c = 0; c < dim; ++c ) {
            for( int r = 0; r < dim; ++r ) {
                for( int dc =-h; dc <= h; ++dc ) {
                    int nc = c + dc;
                    if( (nc < 0) || (nc >= dim) ) continue;
                    for( int dr =-h; dr <= h; ++dr ) {
                        int nr = r + dr;
                        if( (nr < 0) || (nr >= dim) ) continue;
                        if( abs(dc) + abs(dr) > h ) continue;
                        cout << "        (in-sensing-range h" << h << " p" << 1+c << "-" << 1+r << " p" << 1+nc << "-" << 1+nr << ")" << endl;
                    }
                }
            }
        }
    }

    return 0;
}

