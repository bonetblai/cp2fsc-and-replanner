#include <iostream>
#include <stdlib.h>
#include <set>
#include <vector>

using namespace std;

void sensing_model(int max_obs, const int *dir) {
    int last_dir = 8;
    for( int i = 0; i < 8; ++i ) {
        if( dir[i] ) last_dir = i;
    }
    ++last_dir;

    for( int n = 0; n <= max_obs; ++n ) {
        set<int> valid;
        for( int k = 0; k < 256; ++k ) {
            int m = k;
            int bit_count = 0;
            for( int i = 0; i < 8; ++i ) {
                bit_count += dir[i] && ((k >> i) & 0x1) ? 1 : 0;
                if( !dir[i] ) m = m & ~(1 << i);
            }
            if( bit_count == n ) valid.insert(m);
        }

        cout << "            (:model-for (obs-at ?p) (obs" << n << "-at ?p)";
        if( valid.empty() ) {
            cout << " false)" << endl;
        } else {
            cout << endl << "                        ";
            if( valid.size() > 1 ) cout << "(or ";
        }

        for( set<int>::const_iterator it = valid.begin(); it != valid.end(); ++it ) {
            if( it != valid.begin() ) cout << "                            ";
            int k = *it;
            cout << "(and ";
            bool first_conjunct = true;
            for( int i = 0; i < 8; ++i ) {
                if( dir[i] ) {
                    if( !first_conjunct ) {
                        if( valid.size() > 1 ) cout << "    ";
                        cout << "                             ";
                    }
                    cout << "(forall (?q - pos) (or (not (d" << i << " ?p ?q)) ";
                    if( (k >> i) & 0x1 )
                        cout << "(mine-at ?q)))";
                    else
                        cout << "(not (mine-at ?q))))";
                    first_conjunct = false;
                    if( i < last_dir - 1 ) cout << endl;
                }
            }
            cout << ")" << endl;
        }

        if( !valid.empty() ) {
            if( valid.size() > 1 ) cout << "                        )" << endl;
            cout << "            )" << endl;
        }
    }
}

void open_generic(int max_obs, const int *dir, const char *name) {
    cout << "    (:action open-" << name << endl
         << "        :parameters (?p - pos)" << endl
         << "        :precondition (and (" << name << " ?p) (not (mine-at ?p)) (not (done-with ?p)) (not (need-set-first-move)))" << endl
         << "        :effect (done-with ?p)" << endl
         << "        :sensing" << endl;
    sensing_model(max_obs, dir);
    cout << "    )" << endl;
}

void open_corner_ul(int max_obs) {
    int corner_ul_dir[] = { 0, 0, 0, 0, 4, 0, 6, 7 };
    open_generic(max_obs, corner_ul_dir, "corner-ul");
}

void open_corner_ur(int max_obs) {
    int corner_ur_dir[] = { 0, 0, 0, 3, 0, 5, 6, 0 };
    open_generic(max_obs, corner_ur_dir, "corner-ur");
}

void open_corner_ll(int max_obs) {
    int corner_ll_dir[] = { 0, 1, 2, 0, 4, 0, 0, 0 };
    open_generic(max_obs, corner_ll_dir, "corner-ll");
}

void open_corner_lr(int max_obs) {
    int corner_lr_dir[] = { 1, 1, 0, 3, 0, 0, 0, 0 };
    open_generic(max_obs, corner_lr_dir, "corner-lr");
}

void open_edge_n(int max_obs) {
    int edge_n_dir[] = { 0, 0, 0, 3, 4, 5, 6, 7 };
    open_generic(max_obs, edge_n_dir, "edge-n");
}

void open_edge_e(int max_obs) {
    int edge_e_dir[] = { 1, 1, 0, 3, 0, 5, 6, 0 };
    open_generic(max_obs, edge_e_dir, "edge-e");
}

void open_edge_s(int max_obs) {
    int edge_s_dir[] = { 1, 1, 2, 3, 4, 0, 0, 0 };
    open_generic(max_obs, edge_s_dir, "edge-s");
}

void open_edge_w(int max_obs) {
    int edge_w_dir[] = { 0, 1, 2, 0, 4, 0, 6, 7 };
    open_generic(max_obs, edge_w_dir, "edge-w");
}

void open_middle(int max_obs) {
    int middle_dir[] = { 1, 1, 2, 3, 4, 5, 6, 7 };
    open_generic(max_obs, middle_dir, "middle");
}

void usage(ostream &os) {
    os << "usage: gen-domain <n>" << endl;
}

int main(int argc, const char **argv) {
    if( argc < 2 ) {
        usage(cout);
        exit(255);
    }

    int max_obs = atoi(*++argv);

    cout << "(define (domain mines" << max_obs << "obs)" << endl
         << "    (:types pos)" << endl
         << "    (:predicates" << endl
         << "        (d0 ?p ?q - pos)" << endl
         << "        (d1 ?p ?q - pos)" << endl
         << "        (d2 ?p ?q - pos)" << endl
         << "        (d3 ?p ?q - pos)" << endl
         << "        (d4 ?p ?q - pos)" << endl
         << "        (d5 ?p ?q - pos)" << endl
         << "        (d6 ?p ?q - pos)" << endl
         << "        (d7 ?p ?q - pos)" << endl
         << endl
         << "        (corner-ul ?p - pos)" << endl
         << "        (corner-ur ?p - pos)" << endl
         << "        (corner-ll ?p - pos)" << endl
         << "        (corner-lr ?p - pos)" << endl
         << "        (edge-n ?p - pos)" << endl
         << "        (edge-e ?p - pos)" << endl
         << "        (edge-s ?p - pos)" << endl
         << "        (edge-w ?p - pos)" << endl
         << "        (middle ?p - pos)" << endl
         << endl
         << "        (need-start)" << endl
         << "        (need-set-first-move)" << endl
         << "        (first-move ?p - pos)" << endl
         << "        (mine-at ?p - pos)" << endl
         << "        (done-with ?p - pos)" << endl
         << endl
         << "        (obs-first-move ?p - pos)" << endl;
    for( int n = 0; n <= max_obs; ++n )
         cout << "        (obs" << n << "-at ?p - pos)" << endl;
    cout << "    )" << endl
         << endl;

    cout << "    (:variable first-movement (forall (?p - pos) (first-move ?p)))" << endl
         << "    (:obs-variable obs-for-first-movement (forall (?p - pos) (obs-first-move ?p)))" << endl
         << "    (:obs-variable (obs-at ?p - pos)";
    for( int n = 0; n <= max_obs; ++n )
        cout << " (obs" << n << "-at ?p)";
    cout << ")" << endl
         << endl;

    cout << "    (:action start-action" << endl
         << "        :precondition (need-start)" << endl
         << "        :effect (and (not (need-start)) (need-set-first-move))" << endl
         << "        :sensing (forall (?p - pos) (:model-for obs-for-first-movement (obs-first-move ?p) (first-move ?p)))" << endl
         << "    )" << endl
         << "    (:action set-first-movement" << endl
         << "        :parameters (?p - pos)" << endl
         << "        :precondition (and (first-move ?p) (need-set-first-move))" << endl
         << "        :effect (and (not (mine-at ?p)) (not (need-set-first-move)))" << endl
         << "    )" << endl
         << endl;

    open_corner_ul(max_obs);
    cout << endl;
    open_corner_ur(max_obs);
    cout << endl;
    open_corner_ll(max_obs);
    cout << endl;
    open_corner_lr(max_obs);
    cout << endl;
    open_edge_n(max_obs);
    cout << endl;
    open_edge_e(max_obs);
    cout << endl;
    open_edge_s(max_obs);
    cout << endl;
    open_edge_w(max_obs);
    cout << endl;
    open_middle(max_obs);
    cout << endl;

    cout << "    (:action put-flag" << endl
         << "        :parameters (?p - pos)" << endl
         << "        :precondition (and (mine-at ?p) (not (done-with ?p)) (not (need-set-first-move)))" << endl
         << "        :effect (done-with ?p)" << endl
         << "    )" << endl;

    cout << ")" << endl
         << endl;

    return 0;
}

