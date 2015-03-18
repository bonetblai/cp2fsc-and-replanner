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

    void print_cnf(std::ostream &os, const Instance &ins) const {
        os << "{";
        for( size_t k = 0; k < cnf_.size(); ++k ) {
            os << "{";
            for( size_t j = 0; j < cnf_[k].size(); ++j ) {
                int lit = cnf_[k][j];
                os << (lit < 0 ? "(not " : "")
                   << ins.atoms_[lit < 0 ? -lit - 1 : lit - 1]
                   << (lit < 0 ? ")" : "")
                   << (j + 1 < cnf_[k].size() ? "," : "");
            }
            os << "}" << (k + 1 < cnf_.size() ? "," : "");
        }
        os << "}";
    }
    void print(std::ostream &os, const Instance &ins) const {
        os << "[s=";
        State::print(os, ins);
        os << ",cnf=";
        print_cnf(os, ins);
        os << "]";
    }

    void write_cnf(std::ostream &os) const {
        os << "{";
        for( size_t k = 0; k < cnf_.size(); ++k ) {
            os << "{";
            for( size_t j = 0; j < cnf_[k].size(); ++j ) {
                int lit = cnf_[k][j];
                os << lit << (j + 1 < cnf_[k].size() ? "," : "");
            }
            os << "}" << (k + 1 < cnf_.size() ? "," : "");
        }
        os << "}";
    }
    void write(std::ostream &os) const {
        os << "[s=";
        State::write(os);
        os << ",cnf=";
        write_cnf(os);
        os << "]";
    }
};

inline std::ostream& operator<<(std::ostream &os, const LW1_State &s) {
    s.write(os);
    return os;
}

#endif

