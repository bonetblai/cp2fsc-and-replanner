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

#ifndef BASE_DNF_H
#define BASE_DNF_H

#include "base.h"
#include <cassert>
#include <set>
#include <string>

inline PDDL_Base::Condition* distribute_and(const PDDL_Base::Or &dnf1, const PDDL_Base::Or &dnf2) {
    std::set<std::string> included_terms;
    PDDL_Base::Or *result = new PDDL_Base::Or;
    for( size_t k = 0; k < dnf1.size(); ++k ) {
        for( size_t j = 0; j < dnf2.size(); ++j ) {
            PDDL_Base::Condition *term = 0;
            if( (dynamic_cast<const PDDL_Base::Literal*>(dnf1[k]) != 0) && (dynamic_cast<const PDDL_Base::Literal*>(dnf2[j]) != 0) ) {
                if( *static_cast<const PDDL_Base::Literal*>(dnf1[k]) == *static_cast<const PDDL_Base::Literal*>(dnf2[j]) ) {
                    term = dnf1[k]->copy_and_simplify();
                } else {
                    PDDL_Base::And *and_term = new PDDL_Base::And;
                    and_term->push_back(dnf1[k]->copy_and_simplify());
                    and_term->push_back(dnf2[j]->copy_and_simplify());
                    term = and_term;
                }
            } else if( (dynamic_cast<const PDDL_Base::Literal*>(dnf1[k]) != 0) && (dynamic_cast<const PDDL_Base::Literal*>(dnf2[j]) == 0) ) {
                assert(dynamic_cast<const PDDL_Base::And*>(dnf2[j]) != 0);
                const PDDL_Base::And &term2 = *static_cast<const PDDL_Base::And*>(dnf2[j]);
                assert(term2.size() > 1);
                PDDL_Base::Condition *and_term = term2.copy_and_simplify();
                assert(dynamic_cast<PDDL_Base::And*>(and_term) != 0);
                static_cast<PDDL_Base::And*>(and_term)->push_back(dnf1[k]->copy_and_simplify());
                term = and_term;
            } else if( (dynamic_cast<const PDDL_Base::Literal*>(dnf1[k]) == 0) && (dynamic_cast<const PDDL_Base::Literal*>(dnf2[j]) != 0) ) {
                assert(dynamic_cast<const PDDL_Base::And*>(dnf1[k]) != 0);
                const PDDL_Base::And &term1 = *static_cast<const PDDL_Base::And*>(dnf1[k]);
                assert(term1.size() > 1);
                PDDL_Base::Condition *and_term = term1.copy_and_simplify();
                assert(dynamic_cast<PDDL_Base::And*>(and_term) != 0);
                static_cast<PDDL_Base::And*>(and_term)->push_back(dnf2[j]->copy_and_simplify());
                term = and_term;
            } else {
                assert(dynamic_cast<const PDDL_Base::And*>(dnf1[k]) != 0);
                assert(dynamic_cast<const PDDL_Base::And*>(dnf2[j]) != 0);
                const PDDL_Base::And &term1 = *static_cast<const PDDL_Base::And*>(dnf1[k]);
                const PDDL_Base::And &term2 = *static_cast<const PDDL_Base::And*>(dnf2[j]);
                assert((term1.size() > 1) && (term2.size() > 1));
                PDDL_Base::Condition *and_term = term1.copy_and_simplify();
                assert(dynamic_cast<PDDL_Base::And*>(and_term) != 0);
                for( size_t i = 0; i < term2.size(); ++i )
                    static_cast<PDDL_Base::And*>(and_term)->push_back(term2[i]->copy_and_simplify());
                term = and_term;
            }

            assert(term != 0);
            if( true && (included_terms.find(term->to_string()) == included_terms.end()) ) {
                result->push_back(term);
                included_terms.insert(term->to_string());
            } else {
                delete term;
            }
        }
    }

    // simplify disjunction to term if there is just one term
    assert(!result->empty());
    if( result->size() == 1 ) {
        const PDDL_Base::Condition *term = *result->begin();
        result->clear();
        delete result;
        return const_cast<PDDL_Base::Condition*>(term);
    } else {
        return result;
    }
}

inline PDDL_Base::Condition* distribute_and(const PDDL_Base::Or &dnf, const PDDL_Base::And &term) {
    PDDL_Base::Or dnf2;
    dnf2.push_back(&term);
    PDDL_Base::Condition *result = distribute_and(dnf, dnf2);
    dnf2.clear();
    return result;
}

inline PDDL_Base::Condition* distribute_and(const PDDL_Base::Or &dnf, const PDDL_Base::Literal &literal) {
    PDDL_Base::Or dnf2;
    dnf2.push_back(&literal);
    PDDL_Base::Condition *result = distribute_and(dnf, dnf2);
    dnf2.clear();
    return result;
}

inline PDDL_Base::Condition* distribute_and(const PDDL_Base::And &dnf1, const PDDL_Base::And &dnf2) {
    PDDL_Base::Or dnf;
    dnf.push_back(&dnf1);
    PDDL_Base::Condition *result = distribute_and(dnf, dnf2);
    dnf.clear();
    return result;
}

inline PDDL_Base::Condition* distribute_and(const PDDL_Base::And &dnf1, const PDDL_Base::Literal &dnf2) {
    PDDL_Base::Or dnf;
    dnf.push_back(&dnf1);
    PDDL_Base::Condition *result = distribute_and(dnf, dnf2);
    dnf.clear();
    return result;
}

inline PDDL_Base::Condition* distribute_and(const PDDL_Base::Literal &dnf1, const PDDL_Base::Literal &dnf2) {
    PDDL_Base::Or dnf;
    dnf.push_back(&dnf1);
    PDDL_Base::Condition *result = distribute_and(dnf, dnf2);
    dnf.clear();
    return result;
}

inline PDDL_Base::Condition* distribute_or(const PDDL_Base::Or &dnf1, const PDDL_Base::Or &dnf2) {
    std::set<std::string> included_terms;
    PDDL_Base::Or *result = new PDDL_Base::Or;

    for( size_t k = 0; k < dnf1.size(); ++k ) {
        if( true && included_terms.find(dnf1[k]->to_string()) == included_terms.end() ) {
            result->push_back(dnf1[k]->copy_and_simplify());
            included_terms.insert(dnf1[k]->to_string());
        }
    }

    for( size_t k = 0; k < dnf2.size(); ++k ) {
        if( true && included_terms.find(dnf2[k]->to_string()) == included_terms.end() ) {
            result->push_back(dnf2[k]->copy_and_simplify());
            included_terms.insert(dnf2[k]->to_string());
        }
    }

    // simplify disjunction to term if there is just one term
    assert(!result->empty());
    if( result->size() == 1 ) {
        const PDDL_Base::Condition *term = *result->begin();
        result->clear();
        delete result;
        return const_cast<PDDL_Base::Condition*>(term);
    } else {
        return result;
    }
}

inline PDDL_Base::Condition* distribute_or(const PDDL_Base::Or &dnf1, const PDDL_Base::And &dnf2) {
    PDDL_Base::Or dnf;
    dnf.push_back(&dnf2);
    PDDL_Base::Condition *result = distribute_or(dnf1, dnf);
    dnf.clear();
    return result;
}

inline PDDL_Base::Condition* distribute_or(const PDDL_Base::Or &dnf1, const PDDL_Base::Literal &dnf2) {
    PDDL_Base::Or dnf;
    dnf.push_back(&dnf2);
    PDDL_Base::Condition *result = distribute_or(dnf1, dnf);
    dnf.clear();
    return result;
}

inline PDDL_Base::Condition* distribute_or(const PDDL_Base::And &dnf1, const PDDL_Base::And &dnf2) {
    PDDL_Base::Or dnf;
    dnf.push_back(&dnf1);
    PDDL_Base::Condition *result = distribute_or(dnf, dnf2);
    dnf.clear();
    return result;
}

inline PDDL_Base::Condition* distribute_or(const PDDL_Base::And &dnf1, const PDDL_Base::Literal &dnf2) {
    PDDL_Base::Or dnf;
    dnf.push_back(&dnf1);
    PDDL_Base::Condition *result = distribute_or(dnf, dnf2);
    dnf.clear();
    return result;
}

inline PDDL_Base::Condition* distribute_or(const PDDL_Base::Literal &dnf1, const PDDL_Base::Literal &dnf2) {
    PDDL_Base::Or dnf;
    dnf.push_back(&dnf1);
    PDDL_Base::Condition *result = distribute_or(dnf, dnf2);
    dnf.clear();
    return result;
}

#endif

