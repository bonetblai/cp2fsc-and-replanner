#include <iostream>
#include <cassert>
#include <set>
#include <vector>
#include <stdlib.h>

using namespace std;

const char* color_names[] = { "red", "blue", "green", "purple" };
size_t index = 0;
size_t generated = 0;
size_t to_generate = 0;

void recursive_generation(int dim, int nballs, const set<size_t> &sample, int b, int flag, vector<pair<int, int> > &position, vector<int> &color) {
    if( generated >= to_generate ) return;
    if( b == nballs ) {
        if( sample.find(index) != sample.end() ) {
            cout << "    (:hidden";
            for( int i = 0; i < nballs; ++i ) {
                int col = 1 + position[i].first;
                int row = 1 + position[i].second;
                cout << " (obj-at o" << 1+i << " p" << col << "-" << row << ")"
                     << " (color o" << 1+i << " " << color_names[color[i]] << ")";
            }
            cout << ")" << endl;
        }
        ++index;
    } else {
        if( flag == 0 ) {
            for( int col = 0; col < dim; ++col ) {
                for( int row = 0; row < dim; ++row ) {
                    if( (col == 0) && (row == 0) ) continue;
                    if( (col == 0) && (row == dim - 1) ) continue;
                    if( (col == dim - 1) && (row == 0) ) continue;
                    if( (col == dim - 1) && (row == dim - 1) ) continue;
                    position[b] = make_pair(col, row);
                    recursive_generation(dim, nballs, sample, b, 1, position, color);
                }
            }
        } else {
            for( int c = 0; c < 4; ++c ) {
                color[b] = c;
                recursive_generation(dim, nballs, sample, 1+b, 0, position, color);
            }
        }
    }
}

int main(int argc, const char **argv) {
    assert(argc > 3);
    int dim = atoi(*++argv);
    int nballs = atoi(*++argv);
    size_t sample_size = atoi(*++argv);

    size_t nhidden = 1;
    for( size_t b = 0; b < nballs; ++b ) {
        nhidden *= 4; // 4 colors per ball
        nhidden *= dim * dim - 4; // this number of positions per ball
    }

    to_generate = nhidden > sample_size ? sample_size : nhidden;
    if( to_generate == nhidden ) {
        cerr << "dim=" << dim << ", nballs=" << nballs
             << ": generating " << to_generate << " hidden state(s)" << endl;
    } else {
        cerr << "dim=" << dim << ", nballs=" << nballs
             << ": generating " << to_generate << " random hidden state(s) out of " << nhidden << endl;
    }

    set<size_t> sample;
    if( to_generate == nhidden ) {
        for( size_t s = 0; s < nhidden; ++s ) sample.insert(s);
    } else {
        while( sample.size() < to_generate ) {
            size_t s = lrand48() % nhidden;
            sample.insert(s);
        }
    }

    vector<pair<int, int> > position(nballs);
    vector<int> color(nballs);

    cout << "(define (problem colorballs-" << dim << "-" << nballs << ")" << endl;
    recursive_generation(dim, nballs, sample, 0, 0, position, color);
    cout << ")" << endl << endl;
    return 0;
}

