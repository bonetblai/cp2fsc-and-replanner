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

#ifndef NEW_SOLVER_H
#define NEW_SOLVER_H

#include <cassert>
#include <iostream>
#include <vector>

#include "action_selection.h"
#include "random_action_selection.h"
#include "problem.h"
#include "kp_problem.h"
#include "utils.h"

//#define DEBUG

template<typename T> class NewSolver {
  public:
    enum { SOLVED = 0, NO_SOLUTION = 1, TIME = 2, AS_CALLS = 3, ERROR = 4 };
    enum { K_REPLANNER = 0, CLG = 1, LW1 = 2 };

  protected:
    const int translation_type_;
    const Instance &instance_;
    const KP_Instance &kp_instance_;
    const ActionSelection<T> &action_selection_;
    const int time_bound_;
    const int max_as_calls_;
    const Options::Mode &options_;

  public:
    NewSolver(int translation_type,
              const Instance &instance,
              const KP_Instance &kp_instance,
              const ActionSelection<T> &action_selection,
              int time_bound,
              int max_as_calls)
      : translation_type_(translation_type),
        instance_(instance), kp_instance_(kp_instance), action_selection_(action_selection),
        time_bound_(time_bound), max_as_calls_(max_as_calls),
        options_(instance.options_) {
    }
    virtual ~NewSolver() { }

    virtual void initialize(const KP_Instance &kp);
    virtual int solve(const T &initial_hidden_state,
                      Instance::Plan &final_plan,
                      std::vector<std::set<int> > &fired_sensors_during_execution,
                      std::vector<std::set<int> > &sensed_literals_during_execution) const;

    virtual void calculate_relevant_assumptions(const Instance::Plan &plan,
                                                const Instance::Plan &raw_plan,
                                                const T &initial_state,
                                                const index_set &goal,
                                                std::vector<index_set> &assumptions) const;
    virtual void calculate_relevant_assumptions(const Instance::Plan &plan,
                                                const std::vector<const T*> &sampled_state_trajectory,
                                                const T &initial_state,
                                                const index_set &goal,
                                                std::vector<index_set> &assumptions) const;
    bool calculate_assumptions(const Instance::Plan &plan,
                               const T &initial_state,
                               const index_set &goal,
                               std::vector<index_set> &assumptions) const;
    bool calculate_assumptions(const Instance::Plan &plan,
                               const std::vector<const T*> &sampled_state_trajectory,
                               const T &initial_state,
                               const index_set &goal,
                               std::vector<index_set> &assumptions) const;
    bool plan_backchain(const Instance::Plan &plan,
                        const std::vector<const T*> &state_trajectory,
                        const index_set &goal,
                        std::vector<index_set> &condition_vec,
                        index_set &open) const;

  protected:
    virtual void compute_and_add_observations(const Instance::Action *last_action,
                                              const T &hidden,
                                              T &state,
                                              std::set<int> &fired_sensors_at_step,
                                              std::set<int> &sensed_at_step) const;
    virtual void apply_inference(const Instance::Action *action,
                                 const std::set<int> &sensed_at_step,
                                 T &state) const;
    virtual bool inconsistent(const T &state, const std::vector<T> &assumptions, size_t k) const;
};

template<typename T>
void NewSolver<T>::initialize(const KP_Instance &kp) {
}

template<typename T>
int NewSolver<T>::solve(const T &initial_hidden_state,
                        Instance::Plan &final_plan,
                        std::vector<std::set<int> > &fired_sensors_during_execution,
                        std::vector<std::set<int> > &sensed_literals_during_execution) const {
    T hidden(initial_hidden_state), state;
    std::set<int> fired_sensors_at_step, sensed_at_step;
    index_set goal_condition;

    // the initial hidden state is already closed with the axioms
    // (see set_initial_state in problem.cc).
    // Axioms appear in k-replanner only in translations of lw1
    // problems when compiling static observables. These axioms
    // are present in the original problem (instance_) and not
    // in the kp-problem (kp_instance_). The axioms are used only
    // once to complete the initial *hidden* state with the
    // hidden observable fluents.

    // close hidden state with deductive rules.
    // (Disabled since if hidden is not corect, result is a propositional
    // model of invariants that can be an unintended hidden state.)
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
    // the relevant assumptions of a classical plan which are
    // then used to detect when replanning is necessary.
    kp_instance_.get_goal_condition(goal_condition);

    // replan loop
    std::vector<index_set> assumptions;
    Instance::Plan plan;
    final_plan.clear();

    while( !state.is_goal(kp_instance_) ) {
        plan.clear();
        assumptions.clear();

        // if there is only one applicable operator, there is no need
        // to do action selection
        if( options_.is_enabled("solver:forced-moves") ) {
            int action_index = -1;
            int num_applicable_actions = 0;
            for( size_t i = 0; i < kp_instance_.actions_.size(); ++i ) {
                if( (kp_instance_.remap_action(i) == -1) && !kp_instance_.is_subgoaling_rule(i) ) continue;
                if( state.applicable(*kp_instance_.actions_[i]) ) {
                    action_index = i;
                    if( ++num_applicable_actions == 2 )
                        break;
                }
            }
            if( num_applicable_actions == 0 ) {
                std::cout << Utils::error() << "no action is applicable at current state:"
                          << std::endl;
                std::cout << ">>> state=";
                state.print(std::cout, kp_instance_);
                std::cout << std::endl << ">>> hidden=";
                hidden.print(std::cout, instance_);
                std::cout << std::endl;
                return ERROR;
            } else if( num_applicable_actions == 1 ) {
                plan.push_back(action_index);
                assumptions.push_back(index_set());
            }
        }

        // call action selection method to obtain plan for state
        if( plan.empty() ) {
            Instance::Plan raw_plan;
            std::vector<const T*> sampled_state_trajectory;
            if( action_selection_.n_calls() >= max_as_calls_ ) return AS_CALLS;
            int status = action_selection_.get_plan(state, plan, raw_plan, sampled_state_trajectory);
            if( status != ActionSelection<T>::SOLVED ) {
                if( status == ActionSelection<T>::NO_SOLUTION )
                    return NO_SOLUTION;
                else
                    return ERROR;
            } else if( action_selection_.get_time() > time_bound_ ) {
                return TIME;
            }
            assert(!plan.empty());
            action_selection_.calculate_assumptions(*this, state, plan, raw_plan, sampled_state_trajectory, goal_condition, assumptions);
            while( !sampled_state_trajectory.empty() ) {
                delete sampled_state_trajectory.back();
                sampled_state_trajectory.pop_back();
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

        // likewise, first action in reduced plan should be applicable at current
        // state. If not, there must be an incomplete or invalid specification of
        // hidden state or initial state, or problem with domain
        if( !state.applicable(*kp_instance_.actions_[plan[0]]) ) {
            std::cout << Utils::error() << "first action in reduced plan isn't applicable: check specification!"
                      << std::endl;
            return ERROR;
        }

        // apply plan until an inconsistency is found or termination
        assert(plan.size() == assumptions.size());
        for( size_t k = 0; k < plan.size(); ++k ) {
            const Instance::Action &kp_act = *kp_instance_.actions_[plan[k]];
            assert(kp_instance_.is_regular_action(kp_act.index()));
            //std::cout << ">>> kp-action=" << kp_act.name() << std::endl;

            // if current state doesn't satisfy corresponding assumption, replan
            if( !state.satisfy(assumptions[k]) || !state.applicable(kp_act) ) break;

            // apply action at state
            if( options_.is_enabled("solver:print:steps") ) {
                std::cout << ">>> kp-action=" << Utils::red() << kp_act.name() << Utils::normal();
                if( !kp_instance_.is_subgoaling_rule(plan[k]) )
                    std::cout << " [action=" << instance_.actions_[kp_instance_.remap_action(plan[k])]->name() << "]" << std::endl;
                else
                    std::cout << " [subgoaling action]" << std::endl;
            }
            state.apply(kp_act);

            // if action is standard action, insert it into plan, apply it at
            // hidden state and gather observations (if any)
            if( !kp_instance_.is_subgoaling_rule(kp_act.index()) ) {
                size_t action_id = kp_instance_.remap_action(plan[k]);
                final_plan.push_back(action_id);
                const Instance::Action &act = *instance_.actions_[action_id];

                if( !hidden.applicable(act) ) {
                    std::cout << Utils::error() << "action " << act.name()
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
                                  << plan[k+1] << "." << kp_instance_.actions_[plan[k+1]]->name()
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

    if( !hidden.is_goal(instance_) ) {
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
    bool status = calculate_assumptions(raw_plan, initial_state, goal, assumptions_on_raw_plan);
    if( !status ) {
        std::cout << Utils::error() << "assumptions on raw plan could not be calculated" << std::endl;
        return;
    }
    assert(raw_plan.size() == assumptions_on_raw_plan.size());

    // print assumptions on raw plan
    if( options_.is_enabled("solver:print:assumptions:raw") ) {
        std::cout << "Assumptions on raw plan (sz=" << assumptions_on_raw_plan.size() << "):" << std::endl;
        for( size_t k = 0; k < assumptions_on_raw_plan.size(); ++k ) {
            std::cout << "    step=" << k << ", "
                      << raw_plan[k] << "." << kp_instance_.actions_[raw_plan[k]]->name()
                      << ": ";
            kp_instance_.write_atom_set(std::cout, assumptions_on_raw_plan[k]);
            std::cout << std::endl;
        }
    }

    // extract assumptions for cooked plan
    assumptions.clear();
    assumptions.reserve(plan.size());
    for( size_t k = 0, i = 0; k < raw_plan.size(); ++k, ++i ) {
        while( (k < raw_plan.size()) && (raw_plan[k] != plan[i]) ) ++k;
        assert(((k == raw_plan.size()) && (i == plan.size())) || (raw_plan[k] == plan[i]));
        if( k < raw_plan.size() ) assumptions.push_back(assumptions_on_raw_plan[k]);
    }
    assert(plan.size() == assumptions.size());

    // print assumptions
    if( options_.is_enabled("solver:print:assumptions") ) {
        std::cout << "Assumptions (sz=" << assumptions.size() << "):" << std::endl;
        for( size_t k = 0; k < assumptions.size(); ++k ) {
            std::cout << "    step=" << k << ", "
                      << plan[k] << "." << kp_instance_.actions_[plan[k]]->name()
                      << ": ";
            kp_instance_.write_atom_set(std::cout, assumptions[k]);
            std::cout << std::endl;
        }
    }
}

template<typename T>
void NewSolver<T>::calculate_relevant_assumptions(const Instance::Plan &plan,
                                                  const std::vector<const T*> &sampled_state_trajectory,
                                                  const T &initial_state,
                                                  const index_set &goal,
                                                  std::vector<index_set> &assumptions) const {
    // calculate assumptions for plan
    bool status = calculate_assumptions(plan, sampled_state_trajectory, initial_state, goal, assumptions);
    if( !status ) {
        std::cout << Utils::error() << "assumptions on plan could not be calculated" << std::endl;
        return;
    }
}

template<typename T>
bool NewSolver<T>::calculate_assumptions(const Instance::Plan &plan,
                                         const T &initial_state,
                                         const index_set &goal,
                                         std::vector<index_set> &assumptions) const {
    assert(!plan.empty());

#ifdef DEBUG
    std::cout << Utils::magenta() << "Calculate relevant assumptions:" << std::endl;
    std::cout << Utils::magenta() << "  Progression:" << std::endl;
#endif

    // calculate trajectory of states generated by plan
    T current_state;
    std::vector<const T*> state_trajectory;
    state_trajectory.reserve(plan.size());
    current_state = initial_state;
    for( size_t k = 0; k < plan.size(); ++k ) {
#ifdef DEBUG
        std::cout << Utils::red() << "    state=" << Utils::normal();
        current_state.print(std::cout, kp_instance_);
        std::cout << std::endl;
#endif

        state_trajectory.push_back(new T(current_state));
        const Instance::Action &action = *kp_instance_.actions_[plan[k]];
#ifdef DEBUG
        std::cout << Utils::yellow() << "    " << action.name() << Utils::normal() << std::endl;
#endif
        assert(current_state.applicable(action));
        current_state.apply(action);
#ifdef DEBUG
        if( current_state == *state_trajectory.back() ) std::cout << Utils::yellow() << "  Action " << action.name() << " is useless!" << std::endl;
#endif
    }
    state_trajectory.push_back(new T(current_state));

    // backchain plan through state trajectory to identify relevant assumptions in plan
    index_set open;                          // signed set of current open conditions
    std::vector<index_set> condition_vec;    // stores computed assumptions in reverse order
    bool status = plan_backchain(plan, state_trajectory, goal, condition_vec, open);

    // clean state trajectory and check status
    while( !state_trajectory.empty() ) {
        delete state_trajectory.back();
        state_trajectory.pop_back();
    }
    if( !status ) return false;

    // at the end, the open conditions should be met by initial state
    for( State::const_iterator it = initial_state.begin(); it != initial_state.end(); ++it ) {
        assert(*it >= 0);
        open.erase(1 + *it);
    }
#ifdef DEBUG
    std::cout << "after erasing init: open="; kp_instance_.write_atom_set(std::cout, open); std::cout << std::endl;
#endif
    assert(open.empty());

    // assumptions is reversed vector of conditions
    assumptions.clear();
    assumptions.reserve(condition_vec.size());
    assumptions.insert(assumptions.end(), condition_vec.rbegin(), condition_vec.rend());
    return true;
}

template<typename T>
bool NewSolver<T>::calculate_assumptions(const Instance::Plan &plan,
                                         const std::vector<const T*> &sampled_state_trajectory,
                                         const T &initial_state,
                                         const index_set &goal,
                                         std::vector<index_set> &assumptions) const {
    // backchain plan through state trajectory to identify relevant assumptions in plan
    index_set open;                          // signed set of current open conditions
    std::vector<index_set> condition_vec;    // stores computed assumptions in reverse order
    bool status = plan_backchain(plan, sampled_state_trajectory, goal, condition_vec, open);
    if( !status ) return false;

    // the open conditions should be met by initial state *in sampled state trajectory*
    assert(!sampled_state_trajectory.empty());
    const State &initial_state_in_sampled_trajectory = **sampled_state_trajectory.begin();
    for( State::const_iterator it = initial_state_in_sampled_trajectory.begin(); it != initial_state_in_sampled_trajectory.end(); ++it ) {
        assert(*it >= 0);
        open.erase(1 + *it);
    }
#ifdef DEBUG
    std::cout << "after erasing init: open="; kp_instance_.write_atom_set(std::cout, open); std::cout << std::endl;
#endif
    assert(open.empty());

    // assumptions is reversed vector of conditions
    assumptions.clear();
    assumptions.reserve(condition_vec.size());
    assumptions.insert(assumptions.end(), condition_vec.rbegin(), condition_vec.rend());
    return true;
}

template<typename T>
bool NewSolver<T>::plan_backchain(const Instance::Plan &plan,
                                  const std::vector<const T*> &state_trajectory,
                                  const index_set &goal,
                                  std::vector<index_set> &condition_vec,
                                  index_set &open) const {
    assert(state_trajectory.size() == 1 + plan.size());

    // backchain from goal to identify relevant assumptions in plan
#ifdef DEBUG
    std::cout << Utils::magenta() << "  Back-chaining:" << std::endl;
#endif
    int plan_size = plan.size();
    condition_vec.reserve(plan_size);
    open = index_set(goal);
    for( int k = plan_size - 1; k >= 0; --k ) {
        const Instance::Action &action = *kp_instance_.actions_[plan[k]];

#ifdef DEBUG
        std::string mode = k % 2 == 0 ? Utils::red() : Utils::cyan();
        std::cout << mode;
        std::cout << "    open="; kp_instance_.write_atom_set(std::cout, open); std::cout << std::endl;
        std::cout << "    action=" << Utils::yellow() << action.name() << mode << " is applied at state=" << Utils::normal();
        state_trajectory[k]->print(std::cout, kp_instance_);
        std::cout << std::endl;
        for( index_set::const_iterator it = open.begin(); it != open.end(); ++it ) std::cout << *it << " "; std::cout << std::endl;
#endif

        // sets of literals to update set of open conditions
        index_set to_be_added, to_be_removed;

        // if action removes an open condition, the removal has to be conditional
        // (otherwise the plan cannot be valid). Thus, add the negated condition
        // to open conditions.
        for( index_set::const_iterator it = action.effect().begin(); it != action.effect().end(); ++it ) {
            if( (*it < 0) && (open.find(-*it) != open.end()) ) {
                std::cout << Utils::error() << "plan removes the open condition: ";
                State::print_literal(std::cout, *it, &kp_instance_);
                std::cout << std::endl;
                return false;
            }
        }

        for( size_t i = 0; i < action.when().size(); ++i ) {
            const Instance::When &when = action.when()[i];
            for( index_set::const_iterator it = when.effect().begin(); it != when.effect().end(); ++it ) {
                if( (*it < 0) && (open.find(-*it) != open.end()) ) {
                    if( when.condition().size() > 1 ) {
                        std::cout << Utils::warning()
                                  << "conditional effect with more than one literal in condition removes open condition ";
                        State::print_literal(std::cout, *it, &kp_instance_);
                        std::cout << "." << std::endl
                                  << "Regression may be too strong. Consider removing conditional effect by enlarging precondition."
                                  << std::endl;
                    }
                    for( index_set::const_iterator jt = when.condition().begin(); jt != when.condition().end(); ++jt )
                        to_be_added.insert(*jt > 0 ? (*jt % 2 == 0 ? *jt + 1 : *jt - 1) : -*jt);
                }
            }
        }

        // if action achieves any open condition, update set of achieved conditions
        // and update set of conditions to add to open
        for( index_set::const_iterator it = action.effect().begin(); it != action.effect().end(); ++it ) {
            if( (*it > 0) && (open.find(*it) != open.end()) ) {
                to_be_added.insert(action.precondition().begin(), action.precondition().end());
                to_be_removed.insert(*it);
            }
        }

        for( size_t i = 0; i < action.when().size(); ++i ) {
            const Instance::When &when = action.when()[i];
            for( index_set::const_iterator it = when.effect().begin(); it != when.effect().end(); ++it ) {
                if( state_trajectory[k]->satisfy(when.condition()) && (*it > 0) && (open.find(*it) != open.end()) ) {
                    to_be_added.insert(action.precondition().begin(), action.precondition().end());
                    to_be_added.insert(when.condition().begin(), when.condition().end());
                    to_be_removed.insert(*it);
                }
            }
        }

        // remove negative literals for condition
        for( index_set::iterator it = to_be_added.begin(); it != to_be_added.end(); ) {
            if( *it < 0 ) {
                int literal = *it++;
                to_be_added.erase(literal);
            } else {
                ++it;
            }
        }
        condition_vec.push_back(to_be_added);

#ifdef DEBUG
        std::cout << Utils::magenta();
        std::cout << "    action " << action.name() << std::endl;
        std::cout << Utils::green();
        std::cout << "        to_be_removed="; kp_instance_.write_atom_set(std::cout, to_be_removed); std::cout << std::endl;
        std::cout << "        to_be_added="; kp_instance_.write_atom_set(std::cout, to_be_added); std::cout << std::endl;
        std::cout << Utils::normal();
#endif

        // update set of open conditions
        for( index_set::const_iterator it = to_be_removed.begin(); it != to_be_removed.end(); ++it )
            open.erase(*it);
        open.insert(to_be_added.begin(), to_be_added.end());
    }

#ifdef DEBUG
    std::cout << "open="; kp_instance_.write_atom_set(std::cout, open); std::cout << std::endl;
#endif

    return true;
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
        if( hidden.satisfy(r.condition()) ) {
            fired_sensors_at_step.insert(k);
            for( index_set::const_iterator it = r.sense().begin(); it != r.sense().end(); ++it ) {
                int obs = *it > 0 ? *it - 1 : -*it - 1;
                if( hidden.satisfy(obs) ) {
                    state.remove(2 * obs + 1);
                    state.add(2 * obs);
                    sensed_at_step.insert(1 + obs);
                } else {
                    state.remove(2 * obs);
                    state.add(2 * obs + 1);
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
            std::cout << "*** checking consistency of " << instance_.atoms_[atom]->name() << ": ";
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

#undef DEBUG

#endif

