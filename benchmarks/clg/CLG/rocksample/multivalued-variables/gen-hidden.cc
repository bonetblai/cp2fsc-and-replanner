#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, const char **argv) {
    int d = atoi(*++argv);
    int n = atoi(*++argv);

    cout << "(define (problem RockSample" << d << "-" << n << ")" << endl;
    for( int k = 0; k < (1 << n); ++k ) {
        cout << "    (:hidden";
        for( int i = 0; i < n; ++i ) {
            if( (k >> i) & 0x1 ) cout << " (good r" << i << ")";
        }
        cout << ")" << endl;
    }
    cout << ")" << endl << endl;

    return 0;
}

