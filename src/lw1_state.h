/*
 *  Copyright (C) 2011 - <date> Blai Bonet, Universidad Simon Bolivar
 * 
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 *  Blai Bonet, bonet@ldc.usb.ve, bonetblai@gmail.com
 *
 */

#ifndef LW1_STATE_H
#define LW1_STATE_H

#include "state.h"
#include <cassert>
#include <iostream>
#include <list>

struct LW1_State : public State {
    typedef std::vector<int> clause_t;
    typedef std::vector<clause_t> cnf_t;

    cnf_t cnf_;

    LW1_State(size_t n = 0) : State(0) { }
    LW1_State(const LW1_State &s) : State(s) { }
    LW1_State(const index_set &s) : State(s) { }
    virtual ~LW1_State() { }

    static void print_clause_or_term(std::ostream &os, const clause_t &clause_or_term, const Instance *ins = 0) {
        os << "{";
        for( size_t k = 0; k < clause_or_term.size(); ++k ) {
            State::print_literal(os, clause_or_term[k], ins);
            os << (k + 1 < clause_or_term.size() ? "," : "");
        }
        os << "}";
    }
    static void print_cnf_or_dnf(std::ostream &os, const cnf_t &cnf_or_dnf, const Instance *ins = 0) {
        os << "{";
        for( size_t k = 0; k < cnf_or_dnf.size(); ++k ) {
            LW1_State::print_clause_or_term(os, cnf_or_dnf[k], ins);
            os << (k + 1 < cnf_or_dnf.size() ? "," : "");
        }
        os << "}";
    }

    void print(std::ostream &os, const Instance *ins = 0) const {
        os << "[s=";
        State::print(os, ins);
        if( !cnf_.empty() ) {
            os << ",cnf=";
            LW1_State::print_cnf_or_dnf(os, cnf_, ins);
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

