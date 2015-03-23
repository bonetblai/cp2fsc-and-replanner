#ifndef LW1_STATE_H
#define LW1_STATE_H

#include <iostream>
#include <list>
#include <cassert>
#include "state.h"

struct LW1_State : public State {
    typedef std::vector<int> clause_t;
    typedef std::vector<clause_t> cnf_t;

    cnf_t cnf_;

    LW1_State(size_t n = 0) : State(0) { }
    LW1_State(const LW1_State &s) : State(s) { }
    LW1_State(const index_set &s) : State(s) { }
    virtual ~LW1_State() { }

    static void print_clause(std::ostream &os, const clause_t &clause, const Instance *ins = 0) {
        os << "{";
        for( size_t k = 0; k < clause.size(); ++k ) {
            State::print_literal(os, clause[k], ins);
            os << (k + 1 < clause.size() ? "," : "");
        }
        os << "}";
    }
    static void print_cnf(std::ostream &os, const cnf_t &cnf, const Instance *ins = 0) {
        os << "{";
        for( size_t k = 0; k < cnf.size(); ++k ) {
            LW1_State::print_clause(os, cnf[k], ins);
            os << (k + 1 < cnf.size() ? "," : "");
        }
        os << "}";
    }

    void print(std::ostream &os, const Instance *ins = 0) const {
        os << "[s=";
        State::print(os, ins);
        if( !cnf_.empty() ) {
            os << ",cnf=";
            LW1_State::print_cnf(os, cnf_, ins);
        }
        os << "]";
    }
    void print(std::ostream &os, const Instance &ins) const {
        print(os, &ins);
    }
};

inline std::ostream& operator<<(std::ostream &os, const LW1_State &s) {
    s.print(os);
    return os;
}

#endif

