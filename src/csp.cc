#include <algorithm>
#undef NDEBUG // error: the output changes when compiling with -DNDEBUG
#define DEBUG
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
void Inference::CSP::Variable::print(std::ostream& os, const Instance& instance,
                                     const LW1_State& state) const {
    const std::set<int> &od = original_domain_;
    const std::set<int> &cd = current_domain_;
    std::set<int>::const_iterator od_end = od.cend(); --od_end;
    std::set<int>::const_iterator cd_end = cd.cend(); --cd_end;

    os << name_ << ": ";
    os << "od: {";
    for (SI::const_iterator it = od.cbegin(); it != od.cend(); it++) {
        state.print_literal(os, *it, &instance);
        os << " [" << *it << "]";
        if (it != od_end) os << ", ";
    }
    os << "} ";

    os << "cd: {";
    for (auto it = cd.cbegin(); it != cd.cend(); it++) {
        state.print_literal(os, *it, &instance);
        os << " [" << *it << "]";
        if (it != cd_end) os << ", ";
    }
    os << "} ";

    os << "b? " << (is_binary() ? "yes" : "no") << std::endl;
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

void Inference::CSP::Variable::reset_domain() {
    current_domain_ = SI(original_domain_);
}

void Inference::CSP::Variable::clear_domain() {
    current_domain_ = SI();
}

/************************ Arithmetic Class ************************/

void Inference::CSP::Arithmetic::dump_into(std::vector<int>& info) const {
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

void Inference::CSP::Binary::dump_into(std::vector<int>& info) const {
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
            variable = new Binary(*var);
        } else {
            variable = new Arithmetic(*var);
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
        (*var)->dump_into(info);
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

void Inference::CSP::Csp::clean_domains() {
    for (V_VAR_I it = variables_.begin(); it != variables_.end(); it++) {
        (*it)->reset_domain();
    }
}

/**
  *  Print CSP  (debugging)
  */
void Inference::CSP::Csp::print(std::ostream& os, const Instance& instance,
                                const LW1_State& state) const {
    os << ">>>CSP" << std::endl;
    os << ">>>VARIABLES" << std::endl;
    for (int i = 0; i < variables_.size(); i++) {
        variables_[i]->print(os, instance, state);
    }
    os << ">>>CONSTRAINTS" << std::endl;
    for (auto it = constraints_.cbegin(); it != constraints_.cend(); it++) {

        const std::vector<int> &cl = *it;
        state.print_clause(os, cl, &instance);
        for (VI_CI it2 = cl.cbegin(); it2 != cl.cend(); it2++) {
            os << *it2 << ", ";
        }
        os << std::endl;
    }
}

void Inference::CSP::Csp::print_constraint(std::ostream& os,
                                           const Inference::CSP::Constraint& constraint,
                                           const Instance& instance,
                                           const LW1_State& state) const {
    state.print_clause(os, constraint, &instance);
    os << std::endl;
    for (auto cn = constraint.cbegin(); cn != constraint.cend(); cn++) {
        Variable* var = get_var(*cn);
        var->print(os, instance, state);
    }

    os << "active? ";
    if (constraint.is_active()) os << "yes" << std::endl;
    else os << "no" << std::endl;
}

int Inference::CSP::get_h_atom(int l_atom) { return l_atom * 2 + 1; }

// Get K_not_literal of h_atom
int Inference::CSP::get_k_not(int h_atom) { return h_atom + 1; }

int Inference::CSP::get_l_atom(int h_atom) {
    return h_atom > 0 ? (h_atom - 1) / 2 : (-h_atom - 1) / 2 + 1;
}

/************************ AC3 Class ************************/

void Inference::CSP::AC3::apply_unary_constraints(Csp& csp) const {
    csp.clean_domains();
    std::vector<Constraint>& constraints_ = csp.get_constraints_();
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

void Inference::CSP::AC3::prepare_constraints(Csp& csp,
                                              const Instance& instance,
                                              const LW1_State& state) {
    std::vector<Constraint>& constraints = csp.get_constraints_();

    // The list of constraints must be reduced discarding satisfied and
    // unnecessary variables.
    for (size_t i = 0; i < constraints.size(); i++) {
        bool satisfied = false;

        // We don't need the unary ones from this point on.
        if (constraints[i].size() == 1) {
            std::cout << "[AC3] Unary constraint removed." << std::endl;
            constraints.erase(constraints.begin() + i);
            continue;
        }

        // Every atom of the constraint (clause) must be evaluated.
        // If its domain is unary and if it satisfies the constraint, the whole
        // constraint is eliminated.
        //
        // If its domain is unary and it doesn't satisfy the constraint, the
        // atom must be eliminated.
        for (size_t j = 0; j < constraints[i].size(); j++) {
            int var_index = csp.get_var_index(constraints[i][j]);
            if (var_index == -1) continue;

            Variable *var = csp.get_var(constraints[i][j]);

            if (var->get_domain_size() == 1) {
                int value = *(var->get_current_domain().begin());
                // If the value does not satisfy, it's useless and the
                // constraint is reduced
                if (! var->evaluate(value, j)) {
                    constraints[i].erase(constraints[i].begin() + j);
                    j--;
                    continue;
                }
                satisfied = true;
                break;
            }

            // Fill info on inverted indexes
            MIVI_CI jt = inv_clauses_.find(var_index);
            if (jt == inv_clauses_.cend())
                inv_clauses_[var_index] = std::vector<int>();
            inv_clauses_[var_index].push_back(i);
        }

        // A constraint can be already satisfied, in which case it's
        // useless for the CSP.
        if (satisfied) {
            std::cout << "[AC3] N-ary constraint removed." << std::endl;
            constraints.erase(constraints.begin() + i);
            continue;
        }
        constraints[i].set_active(constraints[i].size() <= 2);

        // DEBUG
        std::cout << Utils::magenta() << "[DEBUG AC3] Constraint after prepare: " << std::endl;
        csp.print_constraint(std::cout, constraints[i], instance, state);
        std::cout << Utils::normal() << std::endl;
    }
}

void Inference::CSP::AC3::apply_binary_constraints(Csp& csp,
                                                   const Instance& instance,
                                                   const LW1_State& state) const {
    std::vector<Constraint>& constraints = csp.get_constraints_();
    std::vector<Constraint> watchlist;
    fill_watchlist(constraints, watchlist, csp, instance, state);

    while (! watchlist.empty()) {
        Constraint constraint = watchlist.back();
        watchlist.pop_back();
        if (arc_reduce(csp, constraint, instance, state)) {
            std::cout << "[DEBUG] REDUCED" << std::endl;
            int var_index = csp.get_var_index(constraint[0]);
            std::vector<int> related = inv_clauses_.at(var_index);

            std::cout << "[DEBUG] Back into watchlist" << std::endl;
            for (auto it = related.cbegin(); it != related.cend(); it++) {
                csp.print_constraint(std::cout, constraints[*it], instance,
                                     state);
            }
            // add constraints (clause[0], clause[1]') clause[0] when
            // clause'[1] != clause[1])
        }
    } 
}

bool Inference::CSP::AC3::arc_reduce(Csp& csp,
                                     const Constraint& constraint,
                                     const Instance& instance,
                                     const LW1_State& state) const {
    Variable* x = csp.get_var(constraint[0]);

    if (constraint.size() == 1) {
        if (x->get_domain_size() == 1) return false;
        int val = 0;
        for (auto it = x->get_current_begin();
             it != x->get_current_end(); it++) {
            if (x->evaluate(*it, constraint[0])) {
                val = *it;
                break;
            }
        }
        x->clear_domain();
        x->add(val);

        return true;
    }

    Variable* y = csp.get_var(constraint[1]);

    // If one of the clauses has determined value, we could know the value
    // of the other one.
    // TODO: Make this a function to avoid repeated code.
    if (x->get_domain_size() == 1) {
        for (SI_I vy = y->get_current_begin();
             vy != y->get_current_end(); vy++) {
            int yval = *vy;
            if (y->evaluate(yval, constraint[1])) {
                y->clear_domain();
                y->add(yval);
                return true;
            }
        }
    }

    bool change = false; // An element has been erase from dx ?

    for (SI_I vx = x->get_current_begin(); vx != x->get_current_end();) {
        // If constraint is already satisfied (this check should be unnecessary)
        int xval = *vx;
        if (x->evaluate(xval, constraint[0])) {
            vx++;
            continue;
        }
        bool found = false;
        for (SI_I vy = y->get_current_begin();
             vy != y->get_current_end(); vy++) {
            int yval = *vy;
            if (y->evaluate(yval, constraint[1])) {
                found = true;
                break;
            }
        }
        // Erase from domain, and set iterator before next element
        if (!found) {
            vx = x->erase(vx);
            change = true;
        } else {
            vx++;
        }
    }
    return change;
}

void Inference::CSP::AC3::solve(Csp &csp, LW1_State &state,
                                const Instance &instance) {
    apply_unary_constraints(csp);
    prepare_constraints(csp, instance, state);
    apply_binary_constraints(csp, instance, state);
    csp.dump_into(state, instance);
}

void Inference::CSP::AC3::print(std::ostream& os, const Instance& instance,
                                Csp& csp, LW1_State& state) const {
    os << "[AC3] Inverted index table" << std::endl;
    V_VAR variables = csp.get_variables_();
    std::vector<Constraint>& constraints = csp.get_constraints_();

    for (MIVI_CI it = inv_clauses_.cbegin();
         it != inv_clauses_.cend(); it++) {
        os << "[AC3] Variable: " << std::endl;
        variables[it->first]->print(os, instance, state);
        os << "[AC3] Constraints: " << std::endl;
        VI constraint = it->second;
        for (VI_CI vit = constraint.cbegin(); vit != constraint.cend(); vit++) {
            state.print_clause(os, constraints[*vit], &instance);
            os << std::endl;
        }
    }
    os << "END OF AC3" << std::endl;
}

void Inference::CSP::AC3::fill_watchlist(
        const std::vector<Constraint>& constraints,
        std::vector<Constraint>& watchlist, const Csp& csp,
        const Instance& instance, const LW1_State& state) const {

    for (std::vector<Constraint>::const_iterator ci = constraints.cbegin();
         ci != constraints.cend(); ci++) {
        Constraint constraint = *ci;
        if (constraint.is_active()) {
            std::cout << Utils:: magenta() << "[DEBUG AC3] Added to watchlist: " << std::endl;
            csp.print_constraint(std::cout, constraint, instance, state);
            std::cout << Utils:: normal();
            watchlist.push_back(constraint);

            // If (x,y) is being added, (y,x) needs to be added as well.
            if (constraint.size() > 1) {
                Constraint inverted(constraint);
                std::iter_swap(inverted.begin(), inverted.begin() + 1);

                std::cout << Utils:: magenta() << "[DEBUG AC3] Added to watchlist: " << std::endl;
                csp.print_constraint(std::cout, inverted, instance, state);
                std::cout << Utils:: normal();

                watchlist.push_back(inverted);
            }
        }
    }
}


