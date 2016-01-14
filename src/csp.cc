#include <algorithm>
#undef NDEBUG // error: the output changes when compiling with -DNDEBUG
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include "csp.h"


typedef std::set<int>::iterator SI_I;
typedef std::set<int>::const_iterator SI_CI;

typedef std::vector<int>::iterator VI_I;
typedef std::vector<int>::const_iterator VI_CI;

typedef std::vector< std::vector<int> >::iterator VVI_I;
typedef std::vector< std::vector<int> >::const_iterator VVI_CI;

typedef std::vector<Inference::CSP::Variable *>::iterator V_VAR_I;
typedef std::vector<Inference::CSP::Variable *>::const_iterator V_VAR_CI;


/************************ Variable Abstract Class  ************************/

Inference::CSP::Variable::Variable(const LW1_Instance::Variable &var):
    name_(var.name_),
    original_domain_(var.domain_), 
    current_domain_(var.domain_) 
{ 
}


/**
  * Print info about a variable (debugging)
  */
void Inference::CSP::Variable::print(std::ostream &os) const {
    os << "Name of variable " << name_ << std::endl;
    os << "Original domain" << std::endl;
    const std::set<int> &od = original_domain_;
    const std::set<int> &cd = original_domain_;
    for (std::set<int>::iterator it = od.cbegin(); it != od.cend(); it++) {
        os << *it << ", ";
    }
    os << std::endl << "Current domain" << std::endl;
    for (auto it = cd.cbegin(); it != cd.cend(); it++) {
        os << *it << ", ";
    }
    os << std::endl;
}

/************************ Arithmetic Class ************************/

void Inference::CSP::Arithmetic::dump_into(std::vector<int> &info) const {
    info.clear();
    for (SI_CI o = original_domain_.cbegin(); o != original_domain_.cend(); o++) {
        if (current_domain_.find(*o) == current_domain_.end()) {   // Not found
            info.push_back(negate(*o));
        }
    }
    if (current_domain_.size() == 1) {
        info.push_back(*(current_domain_.cbegin()));
    }
}

/************************ Binary Class ************************/

void Inference::CSP::Binary::dump_into(std::vector<int> &info) const {
    info.clear();
    if (current_domain_.size() == 1) {
        info.push_back(*(current_domain_.cbegin()));
    }
}

/************************ Csp Class ************************/

/**
  * Dump information into state
  * This function is idempotent over state
  */
void Inference::CSP::Csp::dump_into(LW1_State &state) const {
    for (V_VAR_CI var = variables_.begin(); var != variables_.end(); var++) {
        std::vector<int> info; (*var)->dump_into(info);
        for (VI_CI st = info.begin(); st != info.end(); st++) {
            state.add(*st);
        }
    }
}

/**
  *  Print CSP  (debugging)
  */
void Inference::CSP::Csp::print(std::ostream &os) const {
    os << "CSP:" << std::endl;
    os << "Variables: " << std::endl;
    for (int i = 0; i < variables_.size(); i++) {
        variables_[i]->print(os);
    }
    os << "Constraints: " << std::endl;
    for (VVI_CI it = constraints_.cbegin(); 
                             it != constraints_.cend(); 
                             it++) {

        const std::vector<int> &cl = *it;
        for (VI_CI it2 = cl.cbegin(); it2 != cl.cend(); it2++) {
            os << *it2 << ", ";
        }
        os << std::endl;
    }
}
