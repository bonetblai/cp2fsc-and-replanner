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

typedef std::map<int, std::vector<int>> MIVI;
typedef std::map<int, std::vector<int>>::const_iterator MIVI_CI;

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
void Inference::CSP::Variable::print(std::ostream &os, const Instance *instance,
                                     const LW1_State *state) const {
    const std::set<int> &od = original_domain_;
    const std::set<int> &cd = current_domain_;
    std::set<int>::const_iterator od_end = od.cend(); --od_end;
    std::set<int>::const_iterator cd_end = cd.cend(); --cd_end;

    os << name_ << ": ";
    os << "od: {";
    for (SI::const_iterator it = od.cbegin(); it != od.cend(); it++) {
        state->print_literal(os, *it, instance);
        os << " [" << *it << "]";
        if (it != od_end) os << ", ";
    }
    os << "} ";

    os << "cd: {";
    for (auto it = cd.cbegin(); it != cd.cend(); it++) {
        state->print_literal(os, *it, instance);
        os << " [" << *it << "]";
        if (it != cd_end) os << ", ";
    }
    os << "} ";

    os << "b? " << (is_binary() ? "yes" : "no") << std::endl;
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

void Inference::CSP::Binary::dump_into(std::vector<int> &info,
                                       const Instance *instance,
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
void Inference::CSP::Csp::print(std::ostream &os, const Instance *instance,
                                const LW1_State *state) const {
    os << ">>>CSP" << std::endl;
    os << ">>>VARIABLES" << std::endl;
    for (int i = 0; i < variables_.size(); i++) {
        variables_[i]->print(os, instance, state);
    }
    os << ">>>CONSTRAINTS" << std::endl;
    for (auto it = constraints_.cbegin(); it != constraints_.cend(); it++) {

        const std::vector<int> &cl = *it;
        state->print_clause(os, cl, instance);
        for (VI_CI it2 = cl.cbegin(); it2 != cl.cend(); it2++) {
            os << *it2 << ", ";
        }
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

void Inference::CSP::AC3::apply_unary_constraints(Csp &csp,
                                                  const Instance *instance,
                                                  const LW1_State *state) const {
    csp.clean_domains();
    auto constraints_ = csp.get_constraints_();
    V_VAR variables_ = csp.get_variables_();

    for (auto it = constraints_.begin(); it != constraints_.end();) {
        VI cl = *it;
        if (cl.size() == 1) {  // Unary constraint (vector<h_atom>)
            int index = csp.get_var_index(cl[0]);
            if (index != -1)
                variables_[index]->apply_unary_constraint(cl[0]);
            it = constraints_.erase(it);
        } else {
            it++;
        }
    }
}

void Inference::CSP::AC3::prepare_constraints(Csp &csp) {
    auto constraints = csp.get_constraints_();

    // Build inverted index table and fill activeness info for constraints
    for (size_t i = 0; i < constraints.size(); i++) {
        bool active = true;
        int counter = 0;
        std::vector<int> deter_indexes;

        for (size_t j = 0; j < constraints[i].size(); j++) {
            int var_index = csp.get_var_index(j);
            if (var_index == -1) continue;

            // Fill info on inverted indexes
            MIVI_CI jt = inv_clauses_.find(var_index);
            if (jt == inv_clauses_.cend())
                inv_clauses_[var_index] = std::vector<int>();
            inv_clauses_[var_index].push_back(i);

            // Fill info of activeness
            Variable *var = csp.get_var(j);
            if (var->get_domain_size() > 1) {
                counter++;
            } else {
                deter_indexes.push_back(j);
            }
            if (counter > 2) active = false;
        }

        if (active) {
            constraints[i].set_v1(deter_indexes[0]);
            if (counter == 2) constraints[i].set_v2(deter_indexes[1]);
        }
        constraints[i].set_active(active);
        constraints[i].set_undeterm(counter);
    }
}

void Inference::CSP::AC3::apply_binary_constraints(Csp &csp) const {
    auto constraints = csp.get_constraints_();
    VVI watchlist;
    fill_watchlist(constraints, watchlist, csp);

    while (! watchlist.empty()) {
        std::vector<int> clause = watchlist.back();
        watchlist.pop_back();
        if (arc_reduce(csp, clause)) {
            std::cout << "[DEBUG] REDUCED" << std::endl;
            // add constraints (clause[0], clause[1]') clause[0] when
            // clause'[1] != clause[1])
        }
    } 
}

bool Inference::CSP::AC3::arc_reduce(const Csp &csp, const VI &clause) const {
    if (clause.size() != 2) return false;
    const Variable *x = csp.get_var(clause[0]), *y = csp.get_var(clause[1]);
    SI dx = x->get_current_domain(), dy = y->get_current_domain();    
    bool change = false; // An element has been erase from dx ?

    for (SI_I vx = dx.begin(); vx != dx.end(); vx++) {
        if (x->evaluate(*vx, clause[0])) continue; // If constraint is already satisfied
        bool found = false;
        for (SI_I vy = dy.begin(); vy != dy.end(); vy++) {
            if (y->evaluate(*vy, clause[1])) { 
                found = true;
                break;
            }
        }
        // Erase from domain, and set iterator before next element
        if (!found) {
            vx = dx.erase(vx);
            vx--;
        }
    }
    return change;
}

void Inference::CSP::AC3::solve(Csp &csp, LW1_State &state,
                                const Instance &instance) {
    apply_unary_constraints(csp, &instance, &state);
    prepare_constraints(csp);
    apply_binary_constraints(csp);
    csp.dump_into(state, instance);
}

void Inference::CSP::AC3::print(std::ostream &os, const Instance *instance,
                                const Csp &csp, LW1_State *state) const {
    os << "[AC3] Inverted index table" << std::endl;
    V_VAR variables = csp.get_variables_();
    auto constraints = csp.get_constraints_();

    for (MIVI_CI it = inv_clauses_.cbegin();
         it != inv_clauses_.cend(); it++) {
        os << "[AC3] Variable: " << std::endl;
        variables[it->first]->print(os, instance, state);
        os << "[AC3] Constraints: " << std::endl;
        VI constraint = it->second;
        for (VI_CI vit = constraint.cbegin(); vit != constraint.cend(); vit++) {
            state->print_clause(os, constraints[*vit], instance);
            os << std::endl;
        }
    }
    os << "END OF AC3" << std::endl;
}

void Inference::CSP::AC3::fill_watchlist(
        const std::vector<Constraint> constraints, VVI watchlist,
        const Csp &csp) const {
    for (auto ci = constraints.cbegin(); ci != constraints.cend(); ci++)
        if ((*ci).size() > 1 && (*ci).is_active()) watchlist.push_back(*ci);
}
