#ifndef NEW_SOLVER_H
#define NEW_SOLVER_H

#include <iostream>
#include <vector>
#include "classical_planner.h"
#include "problem.h"
#include "kp_problem.h"
#include "utils.h"

template<typename T>
class NewSolver {
  public:
    enum { SOLVED = 0, NO_SOLUTION = 1, TIME = 2, ERROR = 3 };
    enum { K_REPLANNER = 0, CLG = 1, LW1 = 2 };
  protected:
    const int translation_type_;
    const Instance &instance_;
    const KP_Instance &kp_instance_;
    const ClassicalPlanner &planner_;
    const int time_bound_;
    const Options::Mode &options_;
  public:
    NewSolver(int translation_type,
              const Instance &instance,
              const KP_Instance &kp_instance,
              const ClassicalPlanner &planner,
              int time_bound)
      : translation_type_(translation_type),
        instance_(instance), kp_instance_(kp_instance),
        planner_(planner), time_bound_(time_bound),
        options_(instance.options_) {
    }
    virtual ~NewSolver() { }

    virtual int solve(const T &initial_hidden_state,
                      Instance::Plan &final_plan,
                      std::vector<std::set<int> > &fired_sensors_during_execution,
                      std::vector<std::set<int> > &sensed_literals_during_execution) const;
  protected:
    virtual void compute_and_add_observations(const Instance::Action *last_action,
                                              const T &hidden,
                                              T &state,
                                              std::set<int> &fired_sensors_at_step,
                                              std::set<int> &sensed_at_step) const;
    virtual void apply_inference(const Instance::Action *action,
                                 const std::set<int> &sensed_at_step,
                                 T &state) const;
    virtual void calculate_relevant_assumptions(const Instance::Plan &plan,
                                                const Instance::Plan &raw_plan,
                                                const T &initial_state,
                                                const index_set &goal,
                                                std::vector<index_set> &assumptions) const;
    virtual bool inconsistent(const T &state, const std::vector<T> &assumptions, size_t k) const;
};

template<typename T>
int NewSolver<T>::solve(const T &initial_hidden_state,
                        Instance::Plan &final_plan,
                        std::vector<std::set<int> > &fired_sensors_during_execution,
                        std::vector<std::set<int> > &sensed_literals_during_execution) const {
    std::vector<index_set> assumptions;
    T hidden(initial_hidden_state), state;
    Instance::Plan raw_plan, plan;
    std::set<int> fired_sensors_at_step, sensed_at_step;
    index_set goal_condition;

    // the initial hidden state is already closed with the axioms
    // (see set_initial_state in problem.cc).
    // Axioms appear in k-replanner only in translations of multivalued
    // variable problems when compiling static observables. These axioms
    // are only present in the original problem (instance_) and not in
    // the kp-problem (kp_instance_). The axioms are only used once to
    // complete the initial *hidden* state with the hidden observable
    // fluents.

    // close hidden state with deductive rule.
    // (Disabled since if hidden is not corect, result is a propositional
    // model of invariants that can be unintended hidden state.)
    //instance_.apply_deductive_rules(hidden);

    // set the initial state
    kp_instance_.set_initial_state(state);
    if( translation_type_ != LW1 )
        compute_and_add_observations(0, hidden, state, fired_sensors_at_step, sensed_at_step);
    apply_inference(0, sensed_at_step, state);
    fired_sensors_during_execution.push_back(fired_sensors_at_step);
    sensed_literals_during_execution.push_back(sensed_at_step);
    fired_sensors_at_step.clear();
    sensed_at_step.clear();

    if( options_.is_enabled("solver:print:steps") ) {
        std::cout << ">>> initial state=";
        state.print(std::cout, kp_instance_);
        std::cout << std::endl << ">>> initial hidden=";
        hidden.print(std::cout, instance_);
        std::cout << std::endl;
    }

    // set goal state with (new-goal). It is used to compute
    // the relevant assumptions of a classical plan that are
    // then used to detect when replanning is necessary.
    kp_instance_.set_goal_condition(goal_condition);

    // plan/replan loop
    final_plan.clear();
    size_t planner_calls = 0;
    while( !state.goal(kp_instance_) ) {

        // obtain plan for state
        int status = planner_.get_plan(state, raw_plan, plan);
        if( status != ClassicalPlanner::SOLVED ) {
            if( status == ClassicalPlanner::NO_SOLUTION )
                return NO_SOLUTION;
            else
                return ERROR;
        } else if( planner_.get_time() > time_bound_ ) {
            return TIME;
        }
        assert(!plan.empty());
        ++planner_calls;

        calculate_relevant_assumptions(plan, raw_plan, state, goal_condition, assumptions);
        assert(plan.size() == assumptions.size());
        if( options_.is_enabled("solver:print:assumptions") ) {
            std::cout << "Assumptions (sz=" << assumptions.size() << "):" << std::endl;
            for( size_t k = 0; k < assumptions.size(); ++k ) {
                std::cout << "    step=" << k << ", "
                          << plan[k] << "." << kp_instance_.actions_[plan[k]]->name_->to_string()
                          << ": ";
                kp_instance_.write_atom_set(std::cout, assumptions[k]);
                std::cout << std::endl;
            }
        }

        // first assumption for reduced plan should be satisfied by current state.
        // If not, there must be an incomplete or invalid specification of hidden
        // state or initial state, or problem with domain
        assert(!assumptions.empty());
        if( !state.satisfy(assumptions[0]) ) {
            std::cout << Utils::error() << "current state doesn't satisfy first assumption"
                      << " in (reduced) plan: check specification!"
                      << std::endl;
            return ERROR;
        }

        // likewise, first action in reduced plan should be applied at current state.
        // If not, there must be an incomplete or invalid specification of hidden
        // state or initial state, or problem with domain
        if( !state.applicable(*kp_instance_.actions_[plan[0]]) ) {
            std::cout << Utils::error() << "first action in reduced plan isn't applicable: check specification!"
                      << std::endl;
            return ERROR;
        }

        // apply plan until an inconsistency is found or termination
        for( size_t k = 0; k < plan.size(); ++k ) {
            const Instance::Action &kp_act = *kp_instance_.actions_[plan[k]];
            assert(kp_instance_.is_regular_action(kp_act.index_));
            //std::cout << ">>> kp-action=" << kp_act.name_ << std::endl;

            // if current state doesn't satisfy corresponding assumption, replan
            if( !state.satisfy(assumptions[k]) || !state.applicable(kp_act) ) break;

            // apply action at state
            if( options_.is_enabled("solver:print:steps") ) {
                std::cout << ">>> kp-action=" << kp_act.name_;
                if( !kp_instance_.is_subgoaling_rule(plan[k]) )
                    std::cout << " [action=" << instance_.actions_[kp_instance_.remap_action(plan[k])]->name_ << "]" << std::endl;
                else
                    std::cout << " [subgoaling action]" << std::endl;
            }
            state.apply(kp_act);

            // if action is standard action, insert it into plan, apply it at
            // hidden state and gather observations (if any)
            if( !kp_instance_.is_subgoaling_rule(kp_act.index_) ) {
                size_t action_id = kp_instance_.remap_action(plan[k]);
                final_plan.push_back(action_id);
                const Instance::Action &act = *instance_.actions_[action_id];

                if( !hidden.applicable(act) ) {
                    std::cout << Utils::error() << "action " << act.name_->to_string()
                              << " isn't applicable at hidden state: "
                              << "check whether hidden specification is correct!"
                              << std::endl;
                    return ERROR;
                }

                hidden.apply(act);
                //instance_.apply_deductive_rules(hidden); // CHECK
                compute_and_add_observations(&kp_act, hidden, state, fired_sensors_at_step, sensed_at_step);
                if( (translation_type_ != LW1) || !sensed_at_step.empty() )
                    apply_inference(&kp_act, sensed_at_step, state);
                fired_sensors_during_execution.push_back(fired_sensors_at_step);
                sensed_literals_during_execution.push_back(sensed_at_step);
                fired_sensors_at_step.clear();
                sensed_at_step.clear();

                if( options_.is_enabled("solver:print:steps") ) {
                    std::cout << ">>> state=";
                    state.print(std::cout, kp_instance_);
                    std::cout << std::endl << ">>> hidden=";
                    hidden.print(std::cout, instance_);
                    std::cout << std::endl;
                }

#if 0
                // check for consistency of remaining plan
                if( inconsistent(state, assumptions, k+1) ) {
                    if( options_.is_enabled("solver:print:inconsistency") ||
                        options_.is_enabled("solver:print:inconsistency:details") ) {
                        std::cout << "*** inconsistency found with action "
                                  << plan[k+1] << "." << kp_instance_.actions_[plan[k+1]]->name_
                                  << std::endl;
                        if( options_.is_enabled("solver:print:inconsistency:details") ) {
                            std::cout << "    details:" << std::endl;
                                 cout << "        state=";
                            state.print(std::cout, kp_instance_);
                            std::cout << std::endl << "        hidden=";
                            hidden.print(std::cout, instance_);
                            std::cout << std::endl;
                            for( size_t l = k+1; l < assumptions.size(); ++l ) {
                                std::cout << "        support[layer=" << l << "]=";
                                assumptions[l].print(std::cout, kp_instance_);
                                std::cout << std::endl;
                            }
                        }
                    }
                    break;
                }
#endif
            }
        }
    }

    if( !hidden.goal(instance_) ) {
        std::cout << Utils::error() << "kp state is goal but hidden state isn't. Check specification."
                  << Utils::normal() << std::endl;
        return ERROR;
    }

    if( options_.is_enabled("solver:print:steps") ) {
        std::cout << " state=";
        state.print(std::cout, kp_instance_);
        std::cout << std::endl;
    }

    return SOLVED;
}

template<typename T>
void NewSolver<T>::calculate_relevant_assumptions(const Instance::Plan &plan,
                                                  const Instance::Plan &raw_plan,
                                                  const T &initial_state,
                                                  const index_set &goal,
                                                  std::vector<index_set> &assumptions) const {
    // calculate assumptions for raw plan
    std::vector<index_set> assumptions_on_raw_plan;
    kp_instance_.calculate_relevant_assumptions(raw_plan, initial_state, goal, assumptions_on_raw_plan);
    assert(raw_plan.size() == assumptions_on_raw_plan.size());

    // extract assumptions for cooked plan
    assumptions.clear();
    assumptions.reserve(plan.size());
    for( size_t k = 0, i = 0; k < raw_plan.size(); ++k, ++i ) {
        while( (k < raw_plan.size()) && (raw_plan[k] != plan[i]) ) ++k;
        assert(((k == raw_plan.size()) && (i == plan.size())) || (raw_plan[k] == plan[i]));
        if( k < raw_plan.size() ) assumptions.push_back(assumptions_on_raw_plan[k]);
    }
    assert(plan.size() == assumptions.size());
}

template<typename T>
void NewSolver<T>::compute_and_add_observations(const Instance::Action *last_action,
                                                const T &hidden,
                                                T &state,
                                                std::set<int> &fired_sensors_at_step,
                                                std::set<int> &sensed_at_step) const {
    assert(fired_sensors_at_step.empty());
    assert(sensed_at_step.empty());

    // fire observation rules
    index_set observations;
    for( size_t k = 0; k < instance_.n_sensors(); ++k ) {
        const Instance::Sensor &r = *instance_.sensors_[k];
        if( hidden.satisfy(r.condition_) ) {
            fired_sensors_at_step.insert(k);
            for( index_set::const_iterator it = r.sense_.begin(); it != r.sense_.end(); ++it ) {
                int obs = *it > 0 ? *it - 1 : -*it - 1;
                if( hidden.satisfy(obs) ) {
                    state.remove(2*obs + 1);
                    state.add(2*obs);
                    sensed_at_step.insert(1 + obs);
                } else {
                    state.remove(2*obs);
                    state.add(2*obs+1);
                    sensed_at_step.insert(-(1 + obs));
                }
            }
        }
    }
}

template<typename T>
void NewSolver<T>::apply_inference(const Instance::Action *last_action,
                                   const std::set<int> &sensed_at_step,
                                   T &state) const {
    // translation_type is either K_REPLANNER or CLG. 
    assert(translation_type_ != LW1);

    // compute deductive closure with respect to invariants (for K-replanner and clg)
    bool fix_point_reached = false;
    while( !fix_point_reached ) {
        T old_state(state);
        for( size_t k = kp_instance_.first_deductive_action(); k < kp_instance_.last_deductive_action(); ++k ) {
            const Instance::Action &act = *kp_instance_.actions_[k];
            if( state.applicable(act) )
                state.apply(act);
        }
        fix_point_reached = old_state == state;
    }
}
 
template<typename T>
bool NewSolver<T>::inconsistent(const T &state, const std::vector<T> &assumptions, size_t k) const {
    bool verbose = options_.is_enabled("solver:print:consistency:check");
    for( typename T::const_iterator it = state.begin(); it != state.end(); ++it ) {
        int atom = *it/2;

        if( verbose ) {
            std::cout << "*** checking consistency of " << instance_.atoms_[atom]->name_ << ": ";
        }

        if( instance_.is_observable(atom) ) {
            int comp = *it%2 == 0 ? *it + 1 : *it - 1;
            for( size_t i = k; i < assumptions.size(); ++i ) {
                std::cout << "assumption: " << assumptions[i] << std::endl;
                if( assumptions[i].satisfy(comp) ) {
                    if( verbose ) std::cout << "inconsistent!" << std::endl;
                    return true;
                }
            }
            if( verbose ) std::cout << "consistent!" << std::endl;
        } else {
            if( verbose ) std::cout << " [not checked since not observable]" << std::endl;
        }
    }
    return false;
}

#endif

