#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

inline bool possible(int dim, int col, int row) {
    return (col == 0) || (col == dim - 1) || (row % 2 == 0);
}

inline bool free_up(int dim, int col, int row) {
    if( row == dim - 1 ) return false;
    if( (col == 0) || (col == dim - 1) ) return true;
    return false;
}

inline bool free_right(int dim, int col, int row) {
    if( col == dim - 1 ) return false;
    if( row % 2 == 1 ) return false;
    return true;
}

inline bool free_down(int dim, int col, int row) {
    if( row == 0 ) return false;
    if( (col == 0) || (col == dim - 1) ) return true;
    return false;
}

inline bool free_left(int dim, int col, int row) {
    if( col == 0 ) return false;
    if( row % 2 == 1 ) return false;
    return true;
}

void emit_domain(ostream &os, int dim) {
    os << "(define (domain localize-" << dim << ")" << endl
       << "    (:requirements :strips :typing)" << endl
       << "    (:types pos)" << endl
       << "    (:predicates (ok) (at ?p - pos) (free-up) (free-down) (free-left) (free-right))" << endl
       << "    (:constants";
    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            os << " p" << 1+col << "-" << 1+row;
        }
    }
    os << " - pos)" << endl << endl;
 
    os << "    (:action move-up" << endl
       << "        :precondition (and (ok) (free-up))" << endl
       << "        :effect" << endl
       << "            (and (not (ok)) (not (free-up)) (not (free-right)) (not (free-down)) (not (free-left))" << endl;

    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) && free_up(dim, col, row) ) {
                os << "                 (when (at p" << 1+col << "-" << 1+row << ") "
                   << "(and (at p" << 1+col << "-" << 2+row << ") (not (at p" << 1+col << "-" << 1+row << "))))" << endl;
            }
        }
    }

#if 0
    // action completion
    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) && (row == 0) ) {
                os << "                 (not (at p" << 1+col << "-" << 1+row << "))" << endl;
            } else if( possible(dim, col, row) && (row < dim - 1) ) {
                bool good = true;
                for( int k = 0; good && (k < row); ++k ) good = good && possible(dim, col, k);
                if( !good ) continue;
                os << "                 (when (and";
                for( int k = 0; k < row; ++k )
                    os << " (not (at p" << 1+col << "-" << 1+k << "))";
                os << ") (not (at p" << 1+col << "-" << 1+row << ")))" << endl;
            }
        }
    }
#endif

    os << "            )" << endl << "    )" << endl << endl;
 
    os << "    (:action move-right" << endl
       << "        :precondition (and (ok) (free-right))" << endl
       << "        :effect" << endl
       << "            (and (not (ok)) (not (free-up)) (not (free-right)) (not (free-down)) (not (free-left))" << endl;

    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) && free_right(dim, col, row) ) {
                os << "                 (when (at p" << 1+col << "-" << 1+row << ") "
                   << "(and (at p" << 2+col << "-" << 1+row << ") (not (at p" << 1+col << "-" << 1+row << "))))" << endl;
            }
        }
    }

#if 0
    // action completion
    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) && (col == 0) ) {
                os << "                 (not (at p" << 1+col << "-" << 1+row << "))" << endl;
            } else if( possible(dim, col, row) && (col < dim - 1) ) {
                bool good = true;
                for( int k = 0; good && (k < col); ++k ) good = good && possible(dim, k, row);
                if( !good ) continue;
                os << "                 (when (and";
                for( int k = 0; k < col; ++k )
                    os << " (not (at p" << 1+k << "-" << 1+row << "))";
                os << ") (not (at p" << 1+col << "-" << 1+row << ")))" << endl;
            }
        }
    }
#endif

    os << "            )" << endl << "    )" << endl << endl;

    os << "    (:action move-down" << endl
       << "        :precondition (and (ok) (free-down))" << endl
       << "        :effect" << endl
       << "            (and (not (ok)) (not (free-up)) (not (free-right)) (not (free-down)) (not (free-left))" << endl;

    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) && free_down(dim, col, row) ) {
                os << "                 (when (at p" << 1+col << "-" << 1+row << ") "
                   << "(and (at p" << 1+col << "-" << 0+row << ") (not (at p" << 1+col << "-" << 1+row << "))))" << endl;
            }
        }
    }

#if 0
    // action completion
    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) && (row == dim - 1) ) {
                os << "                 (not (at p" << 1+col << "-" << 1+row << "))" << endl;
            } else if( possible(dim, col, row) && (row > 0) ) {
                bool good = true;
                for( int k = dim - 1; good && (k > row); --k ) good = good && possible(dim, col, k);
                if( !good ) continue;
                os << "                 (when (and";
                for( int k = dim - 1; k > row; --k )
                    os << " (not (at p" << 1+col << "-" << 1+k << "))";
                os << ") (not (at p" << 1+col << "-" << 1+row << ")))" << endl;
            }
        }
    }
#endif

    os << "            )" << endl << "    )" << endl << endl;

    os << "    (:action move-left" << endl
       << "        :precondition (and (ok) (free-left))" << endl
       << "        :effect" << endl
       << "            (and (not (ok)) (not (free-up)) (not (free-right)) (not (free-down)) (not (free-left))" << endl;

    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) && free_left(dim, col, row) ) {
                os << "                 (when (at p" << 1+col << "-" << 1+row << ") "
                   << "(and (at p" << 0+col << "-" << 1+row << ") (not (at p" << 1+col << "-" << 1+row << "))))" << endl;
            }
        }
    }

#if 0
    // action completion
    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) && (col == dim - 1) ) {
                os << "                 (not (at p" << 1+col << "-" << 1+row << "))" << endl;
            } else if( possible(dim, col, row) && (col > 0) ) {
                bool good = true;
                for( int k = dim - 1; good && (k > col); --k ) good = good && possible(dim, k, row);
                if( !good ) continue;
                os << "                 (when (and";
                for( int k = dim - 1; k > col; --k )
                    os << " (not (at p" << 1+k << "-" << 1+row << "))";
                os << ") (not (at p" << 1+col << "-" << 1+row << ")))" << endl;
            }
        }
    }
#endif

    os << "            )" << endl << "    )" << endl << endl;

    os << "    (:action checking" << endl
       << "        :precondition (not (ok))" << endl
       << "        :effect" << endl
       << "            (and (ok)" << endl;
    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) ) {
                os << "                 (when (at p" << 1+col << "-" << 1+row << ") (and "
                   << (free_up(dim, col, row) ? "(free-up)" : "(not (free-up))") << " "
                   << (free_right(dim, col, row) ? "(free-right)" : "(not (free-right))") << " "
                   << (free_down(dim, col, row) ? "(free-down)" : "(not (free-down))") << " "
                   << (free_left(dim, col, row) ? "(free-left)" : "(not (free-left))")
                   << "))" << endl;
            }
        }
    }
    os << "            )" << endl
       << "    )" << endl << endl;

    os << "    (:sensor sense" << endl
       << "        :sensed (free-up) (free-right) (free-down) (free-left)" << endl
       << "    )" << endl;

    os << ")" << endl << endl;
}

void emit_instance(ostream &os, int dim, int n, int irow, int icol) {
    os << endl
       << "(define (problem problem-" << dim << "-" << n << ")" << endl
       << "    (:domain localize-" << dim << ")" << endl;

    // init
    os << "    (:init" << endl;

    os << "        ; possible initial locations" << endl
       << "        (invariant";
    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) )
                os << " (at p" << 1+col << "-" << 1+row << ")";
        }
    }
    os << ")" << endl << endl;

    // invariants
    os << "        ; invariants" << endl;
    for( int col = 0; col < dim; ++col ) {
        for( int row = 0; row < dim; ++row ) {
            if( possible(dim, col, row) ) {
                os << "        (invariant (not (ok)) "
                   << (free_up(dim, col, row) ? "(free-up)" : "(not (free-up))")
                   << " (not (at p" << 1+col << "-" << 1+row << ")))" << endl;
                os << "        (invariant (not (ok)) "
                   << (free_right(dim, col, row) ? "(free-right)" : "(not (free-right))")
                   << " (not (at p" << 1+col << "-" << 1+row << ")))" << endl;
                os << "        (invariant (not (ok)) "
                   << (free_down(dim, col, row) ? "(free-down)" : "(not (free-down))")
                   << " (not (at p" << 1+col << "-" << 1+row << ")))" << endl;
                os << "        (invariant (not (ok)) "
                   << (free_left(dim, col, row) ? "(free-left)" : "(not (free-left))")
                   << " (not (at p" << 1+col << "-" << 1+row << ")))" << endl;
            }
        }
    }
    os << "    )" << endl;

    // hidden state
    os << "    (:hidden (at p" << 1+icol << "-" << 1+irow << ")";
    if( free_up(dim, icol, irow) ) os << " (free-up)";
    if( free_right(dim, icol, irow) ) os << " (free-right)";
    if( free_down(dim, icol, irow) ) os << " (free-down)";
    if( free_left(dim, icol, irow) ) os << " (free-left)";
    os << ")" << endl;

    // goal state
    os << "    (:goal (at p" << dim << "-" << dim << "))" << endl;
    os << ")" << endl << endl;
}

int main(int argc, const char **argv) {
    if( argc != 4 ) {
        cerr << "Usage: generator [d|p] <dim> <n>" << endl;
        return -1;
    }
   
    char emit = **++argv; 
    int dim = atoi(*++argv);
    int n = atoi(*++argv);

    if( dim % 2 == 0 ) {
        cerr << "error: dimension must be odd." << endl;
        exit(1);
    }

    int d = dim >> 1;
    if( (n < 0) || (n >= dim*(d + 1) + 2*d) ) {
        cerr << "error: n must be in [0, dim(d + 1) + 2d) where dim = 2d + 1." << endl;
        exit(1);
    }

    int irow = 0, icol = 0;
    if( n < dim*(d + 1) ) {
        icol = n % dim;
        irow = 2 * (n / dim);
    } else {
        int m = n - dim*(d + 1);
        icol = m % 2 == 0 ? 0 : dim - 1;
        irow = 1 + (m % 2 == 0 ? m : m - 1);
    }

    if( emit == 'd' ) emit_domain(cout, dim);
    if( emit == 'p' ) emit_instance(cout, dim, n, irow, icol);
    return 0;
}

