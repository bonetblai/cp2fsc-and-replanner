#include <algorithm>
#undef NDEBUG // error: the output changes when compiling with -DNDEBUG
#define DEBUG
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include "csp.h"

typedef std::set<int> SI;
typedef SI::iterator SI_I;
typedef std::set<int>::const_iterator SI_CI;

typedef std::vector<int>VI;
typedef std::vector<int>::iterator VI_I;
typedef std::vector<int>::const_iterator VI_CI;

typedef std::vector< VI > VVI;
typedef VVI::iterator VVI_I;
typedef VVI::const_iterator VVI_CI;

typedef std::vector<Inference::CSP::Variable *> V_VAR;
typedef V_VAR::iterator V_VAR_I;
typedef V_VAR::const_iterator V_VAR_CI;

typedef std::map<int, int> MII;

// Static members definitions
V_VAR Inference::CSP::Csp::variables_ = V_VAR();
MII Inference::CSP::Csp::atoms_to_var_map_ = MII();

/************************ Variable Abstract Class  ************************/

Inference::CSP::Variable::Variable(const LW1_Instance::Variable &var): 
    name_(var.name_) {

    VI domain = VI(var.domain_.begin(), var.domain_.end()); 
    transform(domain.begin(), domain.end(), domain.begin(), get_h_atom);
    original_domain_ = SI(domain.begin(), domain.end());
    current_domain_ = SI(domain.begin(), domain.end());
}


/**
  * Print info about a variable (debugging)
  */
void Inference::CSP::Variable::print(std::ostream &os, const Instance *instance, const LW1_State *state) const {
    os << ">>>VARIABLE " << name_ << std::endl;
    const std::set<int> &od = original_domain_;
    const std::set<int> &cd = current_domain_;

    os << ">>>ORIGINAL DOMAIN" << std::endl;
    for (std::set<int>::iterator it = od.cbegin(); it != od.cend(); it++) {
        state->print_literal(os, *it, instance);
        os << " [" << *it << "] , ";
    }
    os << std::endl << ">>>CURRENT DOMAIN" << std::endl;
    for (auto it = cd.cbegin(); it != cd.cend(); it++) {
        state->print_literal(os, *it, instance);
        os << " [" << *it << "] , ";
    }
    os << std::endl;

    os << ">>>BINARY? " << is_binary();

    os << std::endl << std::endl;
}

/************************ Arithmetic Class ************************/

void Inference::CSP::Arithmetic::dump_into(std::vector<int> &info,
                                           const Instance *instance,
                                           const LW1_State *state) const {
    info.clear();
    for (SI_CI o = original_domain_.cbegin(); o != original_domain_.cend(); o++) {
        if (current_domain_.find(*o) == current_domain_.end()) {   // Not found
            info.push_back(get_k_not(*o));
        }
    }
    if (current_domain_.size() == 1) {
        info.push_back(*(current_domain_.cbegin()));
    }
}

/************************ Binary Class ************************/

void Inference::CSP::Binary::dump_into(std::vector<int> &info, const Instance *instance,
                                       const LW1_State *state) const {
    info.clear();
    if (current_domain_.size() == 1) {
        info.push_back(*(current_domain_.cbegin()));
    }
}

/************************ Csp Class ************************/

/**
  *  Initialize the CSP object
  */
void Inference::CSP::Csp::initialize(
        const std::vector<LW1_Instance::Variable *> &vars,
        const std::map<int, int> map) {

    // Fill variables from Instance
    for (auto it = vars.cbegin(); it != vars.cend(); it++) {
        LW1_Instance::Variable *var = *it;
        Inference::CSP::Variable *variable;

        if (var->is_binary()) {
            variable = new Inference::CSP::Binary(*var);
        } else {
            variable = new Inference::CSP::Arithmetic(*var);
        }

        variables_.push_back(variable);
    }

    // Copy atoms to vars
    atoms_to_var_map_ = map;
}

/**
  * Dump information into state
  * This function is idempotent over state
  */
void Inference::CSP::Csp::dump_into(LW1_State &state, const Instance &instance) const {
    for (V_VAR_CI var = variables_.begin(); var != variables_.end(); var++) {
        std::vector<int> info;
        (*var)->dump_into(info, &instance, &state);
        for (VI_CI st = info.begin(); st != info.end(); st++) {
#ifdef DEBUG
            std::cout << Utils::yellow() << "[CSP] Added literal into state: ";
            state.print_literal(std::cout, *st, &instance);
            std::cout << Utils::normal() << std::endl;
#endif
            state.add(*st - 1);

        }
    }
}

/**
  *  Print CSP  (debugging)
  */
void Inference::CSP::Csp::print(std::ostream &os, const Instance *instance, const LW1_State *state) const {
    os << ">>>CSP" << std::endl;
    os << ">>>VARIABLES" << std::endl;
    for (int i = 0; i < variables_.size(); i++) {
        variables_[i]->print(os, instance, state);
    }
    os << ">>>CONSTRAINTS" << std::endl;
    for (VVI_CI it = constraints_.cbegin(); 
                             it != constraints_.cend(); 
                             it++) {

        const std::vector<int> &cl = *it;
        state->print_clause(os, cl, instance);
//        for (VI_CI it2 = cl.cbegin(); it2 != cl.cend(); it2++) {
//            os << *it2 << ", ";
//        }
        os << std::endl;
    }
}

void Inference::CSP::Variable::clean_domain() {
    current_domain_ = SI(original_domain_);
}

void Inference::CSP::Csp::clean_domains() {
    for (V_VAR_I it = variables_.begin(); it != variables_.end(); it++) {
        (*it)->clean_domain();
    }
}

void Inference::CSP::Variable::apply_unary_constraint(int h_atom) {
    if (h_atom % 2 == 0) { 
        // If h_atom is a K_not_atom, remove the K_atom which is K_not_atom - 1
        current_domain_.erase(h_atom - 1);
    } else {
        // if the atom is a K_atom, remove everything else from domain
        current_domain_.clear();
        current_domain_.insert(h_atom);
    }
}

int Inference::CSP::get_h_atom(int l_atom) { return l_atom * 2 + 1; }

// Get K_not_literal of h_atom
int Inference::CSP::get_k_not(int h_atom) { return h_atom + 1; }

int Inference::CSP::get_l_atom(int h_atom) {
    return h_atom > 0 ? (h_atom - 1) / 2 : (-h_atom - 1) / 2 + 1;
}

void Inference::CSP::AC3::apply_binary_constraints(Csp &csp, 
                                                   const Instance *instance,
                                                   const LW1_State *state) const {
    std::cout << Utils::cyan();
    std::cout << "XXX BINARY CONSTRAINTS PRINT XXX";
    csp.print(std::cout, instance, state);
    std::cout << Utils::normal() << std::endl;

    return;
}

void Inference::CSP::AC3::apply_unary_constraints(Csp &csp, const Instance *instance, const LW1_State *state) const {
    csp.clean_domains();
    const VVI &constraints_ = csp.get_constraints_();
    V_VAR variables_ = csp.get_variables_(); 
    for (VVI_CI it = constraints_.cbegin(); it != constraints_.cend(); it++) {
        VI cl = *it;
        if (cl.size() == 1) {  // Unary constraint (vector<h_atom>)
            int index = csp.get_var_index(cl[0]);
            if (index != -1)
                variables_[index]->apply_unary_constraint(cl[0]);
        }
    }
}

void Inference::CSP::AC3::solve(Csp &csp, LW1_State &state,
                                const Instance &instance) {

    apply_unary_constraints(csp, &instance, &state);
    //apply_binary_constraints(csp, &instance, &state);

    csp.dump_into(state, instance);
    return;
}


