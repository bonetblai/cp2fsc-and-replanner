#include <algorithm>
#undef NDEBUG // error: the output changes when compiling with -DNDEBUG
#include <iostream>
#include <queue>
#include <set>
#include "csp.h"

//#define DEBUG

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

typedef std::pair<int,int> ARC_T;

typedef std::map<int, int> MII;

typedef std::map<int, std::vector<int>> MIVI;
typedef std::map<int, std::vector<int>>::const_iterator MIVI_CI;

typedef std::vector<Inference::CSP::VariableGroup*> VVG;
typedef std::vector<Inference::CSP::Arc*> VA;
typedef std::vector<std::vector<std::vector<int>>> V3D;

// Static members definitions
V_VAR Inference::CSP::Csp::variables_ = V_VAR();
MII Inference::CSP::Csp::atoms_to_var_map_ = MII();
VVG Inference::CSP::Csp::variable_groups_ = VVG();
VA Inference::CSP::AC3::arcs_ = VA();
V3D Inference::CSP::Csp::vars_in_common_groups_  = V3D();

/************************ Variable Abstract Class  ************************/
Inference::CSP::Variable::Variable(const LW1_Instance::Variable &var): 
    name_(var.name_) {

    VI domain = VI(var.domain_.begin(), var.domain_.end()); 
    transform(domain.begin(), domain.end(), domain.begin(), get_h_atom);
    original_domain_ = SI(domain.begin(), domain.end());
    current_domain_ = SI(domain.begin(), domain.end());
}
// Debugging
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
// Debugging
void Inference::CSP::VariableGroup::print(std::ostream& os, const Instance& instance,
                                          const LW1_State& state) const {
    const std::set<int> &od = original_domain_;
    const std::set<int> &cd = current_domain_;
    std::set<int>::const_iterator od_end = od.cend(); --od_end;
    std::set<int>::const_iterator cd_end = cd.cend(); --cd_end;

    os << name_ << ": ";
    os << "od: {";
    for (SI::const_iterator it = od.cbegin(); it != od.cend(); it++) {
//        state.print_literal(os, *it, &instance);
        os << *it;
        if (it != od_end) os << ", ";
    }
    os << "} ";

    os << "cd: {";
    for (auto it = cd.cbegin(); it != cd.cend(); it++) {
//        state.print_literal(os, *it, &instance);
        os << *it;
        if (it != cd_end) os << ", ";
    }
    os << "} ";
    os << std::endl;
}
// Reduce current domain given a k_literal.
// This k_literal represents a unary constraint.
// If k_literal is possitive, then it is the only possible value
// for this variable. If it's negative, the this value must be erase from
// current domain.
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
// Set current_domain_ as original_domain_
void Inference::CSP::Variable::reset_domain() {
    current_domain_ = SI(original_domain_);
}
// Erase current_domain 
void Inference::CSP::Variable::clear_domain() {
    current_domain_ = SI();
}
/************************ Arithmetic Class ************************/
// Add erase elements for domain as k_not_literals to info.
// Info vector will have only theses constraints
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
// If variable size is 1, then binary variable has to be that
// value, so that value is added into info as a constraint.
// Info vector will have only theses constraints
void Inference::CSP::Binary::dump_into(std::vector<int>& info) const {
    info.clear();
    if (current_domain_.size() == 1) {
        info.push_back(*(current_domain_.cbegin()));
    }
}
/************************ Csp Class ************************/
// Initialize CSP
void Inference::CSP::Csp::initialize(
        const std::vector<LW1_Instance::Variable *> &vars,
        const std::map<int, int> map) {

    // Fill variables from Instance
    variables_.clear();
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
    atoms_to_var_map_.clear();
    atoms_to_var_map_ = map;
}
// Creates meta-variables (groups)
// Creates auxiliary structure vars_in_common_groups
// vars_in_common_groups is a lower triangular matrix of vectors,
// where vars_in_common_groups[i][j] (i < j) is a vector
// of common variables (var indexes) for variables with indexes
// i and j.
void Inference::CSP::Csp::initialize_groups(const KP_Instance& instance) {
    variable_groups_.clear();  // cleaning groups
    const LW1_Instance& lw1 = ((const LW1_Instance&) instance);
    int number_of_groups = int(lw1.vars_for_variable_groups_.size());
    for ( int i = 0; i < number_of_groups; i++ ) {
        VariableGroup* group = new VariableGroup(lw1.vars_for_variable_groups_[i], i);
        variable_groups_.push_back(group);
    }

    // Building vars in common groups matrix
    vars_in_common_groups_.clear();
    vars_in_common_groups_.assign(number_of_groups, std::vector<std::vector<int>>());
    for( int i = 0; i < number_of_groups; i++ ) {
        vars_in_common_groups_[i].assign(number_of_groups, std::vector<int>());
    }

    for( int i = 0; i < int(variable_groups_.size()); i++ ) {
        for( int j = i+1; j < int(variable_groups_.size()); j++ ) {
            for( int k = 0; k < int(lw1.vars_for_variable_groups_[i].size()); k++ ) {
                int var_index = lw1.vars_for_variable_groups_[i][k];
                if( variable_groups_[j]->get_pos_from_var_index(var_index) != -1) {
                    vars_in_common_groups_[i][j].push_back(var_index);
                }
            }
        }
    }
}
// Intersect current domain with domain
void Inference::CSP::Variable::intersect_with(const std::set<int>& domain) {
#ifdef DEBUG
    std::cout << "INTERSECTING A and B (possible domain)" << std::endl;
    std::cout << "nombre = " << name_ << std::endl;
    std::cout << "A = " << std::endl;
    for (auto i = current_domain_.cbegin(); i != current_domain_.cend(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::cout << "B = " << std::endl;
    for (auto i = domain.cbegin(); i != domain.cend(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::cout << "END OF INTERSECTING DOMAINS " << std::endl;
#endif 
    std::set<int>::iterator cd = current_domain_.begin();
    std::set<int>::const_iterator pd = domain.cbegin();
    while (cd != current_domain_.end() && pd != domain.cend()) {
        if (*cd < *pd) {
            current_domain_.erase(cd++);
        } else {
            if (*cd == *pd) cd++;
            pd++;
        }
    }
    current_domain_.erase(cd, current_domain_.end());

#ifdef DEBUG
    std::cout << "new A = " << std::endl;
    for (auto i = current_domain_.cbegin(); i != current_domain_.cend(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
#endif 
}
// Find variable associated with domain
// and then calls intersect_with
void Inference::CSP::Csp::intersect_domain_of_var(const std::set<int>& domain) {
    assert(domain.size());
    int var_index = get_var_index(*domain.begin()); 
    assert(var_index != -1);
    variables_[var_index]->intersect_with(domain);
}
// Applies unary constraint represented as one (just one)
// possible value (h_atom) over every variable
void Inference::CSP::Csp::prune_domain_of_var(int h_atom) {
    int var_index = get_var_index(h_atom);
    if (var_index != -1)
        variables_[var_index]->apply_unary_constraint(h_atom);
}
// Deletes from group no longer possible valuations
void Inference::CSP::Csp::prune_valuations_of_groups(
        int vg, 
        const std::vector<std::vector<int>> &valuations,
        const Instance &kp_instance) {

#ifdef DEBUG
    for (int i = 0; i < valuations.size(); i++) {
        std::cout << "[ ";
        for (int j = 0; j < valuations[i].size(); j++) {
            std::cout << valuations[i][j] << " ";
        }
        std::cout << " ]";
        std::cout << std::endl;
    }
#endif
    
    std::set<int> possible_domain;
    for (int i = 0; i < int(valuations.size()); i++) {
        std::pair<int, int> masks = get_masks(vg, valuations[i], (const LW1_Instance&) kp_instance);
        int impossibles = masks.first, possibles = masks.second;
#ifdef DEBUG
        std::cout << "INTERSECTING vg = " << vg << std::endl;
#endif
        const std::vector<int> &group = ((const LW1_Instance&) kp_instance).vars_for_variable_groups_[vg];

        for (int value = 0; value < (1 << int(group.size())); value++)
            possible_domain.insert((value & impossibles) | possibles);
    }
    
    variable_groups_[vg]->intersect_with(possible_domain);
}
// Change (Add to) state relevant information of current csp
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
// Clear all variables domains
void Inference::CSP::Csp::clean_domains() {
    for (V_VAR_I it = variables_.begin(); it != variables_.end(); it++) {
        (*it)->reset_domain();
    }
}
// Debugging
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
        state.print_clause_or_term(os, cl, &instance);
        for (VI_CI it2 = cl.cbegin(); it2 != cl.cend(); it2++) {
            os << *it2 << ", ";
        }
        os << std::endl;
    }
}
// Returns a mask of impossible and possible values
// Impossible mask 0010 says that variables in pos 0, 2, 3 are K_not
// Possible mask 0010 says that only variable in pos 1 is K
// Note that both masks will be the same when there is no information
// to be infered
std::pair<int,int> Inference::CSP::Csp::get_masks(
        int vg,
        const std::vector<int>& constraint,
        const LW1_Instance& kp_instance) {

    int impossibles = 0, possibles = 0;
    for (int i = 0; i < int(constraint.size()); i++) {
        int k_atom = constraint[i];
        int var_index = get_var_index(k_atom);
        const std::vector<int> &group = ((const LW1_Instance&) kp_instance).vars_for_variable_groups_[vg]; 

        for (int k = 0; k < int(group.size()); k++) {  // finding var_index possition in valuation!
            if (group[k] == var_index) {
                if (k_atom % 2 == 0) impossibles |= (1 << k); // k_not !
                else possibles |= (1 << k); //k !
            }
        }
    }
    return std::make_pair(~impossibles, possibles);
}
// Get k_literal of a l_atom
int Inference::CSP::get_h_atom(int l_atom) { return l_atom * 2 + 1; }
// Get K_not_literal of h_atom
int Inference::CSP::get_k_not(int h_atom) { return h_atom + 1; }
// Get l_atom of K_literal
int Inference::CSP::get_l_atom(int h_atom) {
    return h_atom > 0 ? (h_atom - 1) / 2 : (-h_atom - 1) / 2 + 1;
}
/************************ AC3 Class ************************/
// Debugging
void Inference::CSP::AC3::print(std::ostream& os, const Instance& instance,
                                Csp& csp, const LW1_State& state) const {
    os << "[AC3] Inverted index table" << std::endl;
    V_VAR variables = csp.get_variables_();
    std::vector<std::vector<int>>& constraints = csp.get_constraints_();

    for (MIVI_CI it = inv_clauses_.cbegin();
         it != inv_clauses_.cend(); it++) {
        os << "[AC3] Variable: " << std::endl;
        variables[it->first]->print(os, instance, state);
        os << "[AC3] Related constraints: " << std::endl;
        VI constraint = it->second;
        for (VI_CI vit = constraint.cbegin(); vit != constraint.cend(); vit++) {
            state.print_clause_or_term(os, constraints[*vit], &instance);
            os << std::endl;
        }
    }
    os << "END OF AC3" << std::endl;
}
// Inserts arcs into worklist
void Inference::CSP::AC3::initialize_worklist() {
    worklist_.clear();
    for( auto it = arcs_.cbegin(); it != arcs_.cend(); it++ ) {
        worklist_.insert(*it);
    }
}
// Arc Reduce algorithm of AC3
bool Inference::CSP::AC3::arc_reduce(Inference::CSP::Arc* arc, Inference::CSP::Csp& csp, const Instance& instance,
                                     const LW1_State& state) {
    Variable* x,* y;

    if( arc->x_is_group()) x = csp.get_group_var(arc->first);
    else x = csp.get_var_from_vars(arc->first);

    if( arc->y_is_group()) y = csp.get_group_var(arc->second);
    else y = csp.get_var_from_vars(arc->second);

    bool change = false; // An element has been erase from dx ?
    assert(x->get_domain_size() && y->get_domain_size());
    for (SI_I vx = x->get_current_begin(); vx != x->get_current_end();) {
        // If arc is already satisfied (this check should be unnecessary)
        int xval = *vx;
        bool found = false;
        for (SI_I vy = y->get_current_begin();
             vy != y->get_current_end(); vy++) {
            int yval = *vy;
            if (evaluate(arc, xval, yval, csp)) {
                found = true;
                break;
            }
        }
        // Erase from domain, and set iterator before next element
        if( ! found ) {
            vx = x->erase(vx);
            change = true;
        } else {
            vx++;
        }
    }
    return change;
}
// Returns an int that represents a valuation of common 
// variables x_var and y_var
// This is done by using an auxiliary structure (common_vars), where
// for each var_index 'i' and 'j', common_vars[i][j] is the vector 
// of var_index for common variables 
int Inference::CSP::AC3::build_commons_valuation(int valuation, VariableGroup* x_var, VariableGroup* y_var, const Csp& csp) const {
    // Because V3D is lower triangular matrix
    int i = std::min(x_var->get_index(), y_var->get_index()); 
    int j = std::max(x_var->get_index(), y_var->get_index());

    const V3D& common_vars = csp.get_vars_in_common_groups();
    int common_valuation = 0;
    for (int t = 0; t < common_vars[i][j].size(); t++) {
        int common_var = common_vars[i][j][t];
        int pos_var = x_var->get_pos_from_var_index(common_var);
        // value of common var in valuation
        int value = (valuation & (1 << pos_var)) >= 1; 
        common_valuation |= (value << t);  
    }
    return common_valuation;
}
// Retunrs true if arc is satisfiable with values x, y
// This is done by considering different cases for Arc.
// 
// If Arc is between to meta-vars (groups), then, it's enough
// to construct common valuations for both variables, and 
// check their equality
//
// If Arc is mixed, then, we have one meta-var (group) and one var.
// For example, let's suppose mixed arc (x_var, y_var)
// where x_var is a meta-var, and y_var is variable (binary)
// First we need to find the position of this y_var into the
// valuations in x_var. Then, we just need to check if the bit 
// corresponding to y_var is the same as the value that y_var
// is taking.
//
// Simple Arc is not considered (not using this in this AC3!)
bool Inference::CSP::AC3::evaluate(Inference::CSP::Arc* arc, int x, int y, const Csp& csp) const {
    assert(x >= 0 && y >= 0);
    if (arc->is_mixed()) {
        if (arc->x_is_group()) {
            int var_index = csp.get_var_index(y);
            VariableGroup* group = csp.get_group_var(arc->first);
            int pos = group->get_pos_from_var_index(var_index);
            int bit = (y % 2) << pos;
            return (x & (1 << pos)) == bit;
        }
        VariableGroup* group = csp.get_group_var(arc->second);
        int var_index = csp.get_var_index(x);
        int pos = group->get_pos_from_var_index(var_index);
        int bit = (x % 2) << pos;
        return (y & (1 << pos)) == bit;
    }

    // if group
    VariableGroup* x_var = csp.get_group_var(arc->first); 
    VariableGroup* y_var = csp.get_group_var(arc->second);
    return build_commons_valuation(x, x_var, y_var, csp) ==
           build_commons_valuation(y, y_var, x_var, csp);
}
// Applies arc consistency over binary arcs
void Inference::CSP::AC3::apply_constraints(Inference::CSP::Csp& csp, const Instance& instance, const LW1_State& state) {
    while( ! worklist_.empty() ) {
        Arc* arc = *worklist_.begin();
        worklist_.erase(worklist_.begin());
        if( arc_reduce(arc, csp, instance, state) ) {
            Variable* x,* y;
            if( arc->x_is_group()) x = csp.get_group_var(arc->first);
            else x = csp.get_var_from_vars(arc->first);

            if( arc->y_is_group()) y = csp.get_group_var(arc->second);
            else y = csp.get_var_from_vars(arc->second);

            for( auto it = arcs_.cbegin(); it != arcs_.cend(); it++ ) {
                Arc* tmp = *it;
                Variable* tmp_z,* tmp_x;
                if( tmp->x_is_group()) tmp_z = csp.get_group_var(tmp->first);
                else tmp_z = csp.get_var_from_vars(tmp->first);

                if( tmp->y_is_group()) tmp_x = csp.get_group_var(tmp->second);
                else tmp_x = csp.get_var_from_vars(tmp->second);

                if( tmp_x == x && tmp_z != y )
                    worklist_.insert(tmp);
            }
        }
    }
}
// Applies Arc Consistency over arcs
void Inference::CSP::AC3::solve_groups(Inference::CSP::Csp& csp,
                                       LW1_State& state,
                                       const Instance& instance) {
    initialize_worklist();
    assert(worklist_.size() == arcs_.size());
    apply_constraints(csp, instance, state);

    // Update state using information in CSP. For each value x that is pruned in domain of
    // CSP variable X corresponding to state variable X, add literal K_not_X=x. For each value
    // z that is pruned in domain of CSP variable Z corresponding to variable group Z, add
    // literal K_not_vg_Z_z
    csp.dump_into(state, instance);
}
// Creates arcs between state variables and meta-variables (groups)
// and creates arcs between meta-variables
void Inference::CSP::AC3::initialize_arcs(const KP_Instance& instance,
                                          Inference::CSP::Csp& csp) {
    arcs_.clear();
    // Building mixed arcs
    const LW1_Instance& lw1 = ((const LW1_Instance&) instance);
    for( int i = 0; i < int(lw1.vars_for_variable_groups_.size()); i++ ) {
        for( int j = 0; j < int(lw1.vars_for_variable_groups_[i].size()); j++ ) {
            int var_index = lw1.vars_for_variable_groups_[i][j];
            arcs_.push_back(new Arc(i, var_index, true, false));
            arcs_.push_back(new Arc(var_index, i, false, true));
        }
    }

    // Build group to group arcs
    const V3D& vars_in_common_groups = csp.get_vars_in_common_groups();
    for( int i = 0; i < int(vars_in_common_groups.size()); i++ ) {
        for( int j = 0; j < int(vars_in_common_groups[i].size()); j++ ) {
            if( ! vars_in_common_groups[i][j].empty() ) {
                arcs_.push_back(new Arc(i, j, true, true));
                arcs_.push_back(new Arc(j, i, true, true));
            }
        }
    }
}
// Debugging
void Inference::CSP::Arc::print(std::ostream& os, const Instance& instance, const LW1_State& state,
                                     const Csp& csp) const {
    Variable* x;
    Variable* y;

    if( x_is_group()) x = csp.get_group_var(first);
    else x = csp.get_var_from_vars(first);

    if( y_is_group()) y = csp.get_group_var(second);
    else y = csp.get_var_from_vars(second);

    x->print(os, instance, state);
    y->print(os, instance, state);
}

#undef DEBUG

