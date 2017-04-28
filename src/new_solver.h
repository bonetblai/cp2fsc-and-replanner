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

template<typename T> class NewSolver {
  public:
    enum { SOLVED = 0, NO_SOLUTION = 1, TIME = 2, NCALLS = 3, ERROR = 4 };
    enum { K_REPLANNER = 0, CLG = 1, LW1 = 2 };
  protected:
    const int translation_type_;
    const Instance &instance_;
    const KP_Instance &kp_instance_;
    const ActionSelection<T> &action_selection_;
    const int time_bound_;
    const int ncalls_bound_;
    const Options::Mode &options_;
  public:
    NewSolver(int translation_type,
              const Instance &instance,
              const KP_Instance &kp_instance,
              const ActionSelection<T> &action_selection,
              int time_bound,
              int ncalls_bound)
      : translation_type_(translation_type),
        instance_(instance), kp_instance_(kp_instance), action_selection_(action_selection),
        time_bound_(time_bound), ncalls_bound_(ncalls_bound),
        options_(instance.options_) {
    }
    virtual ~NewSolver() { }

    virtual void initialize(const KP_Instance &kp);
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
    Instance::Plan raw_plan, plan;
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
            if( action_selection_.n_calls() >= ncalls_bound_ ) return NCALLS;
            int status = action_selection_.get_plan(state, raw_plan, plan);
            if( status != ActionSelection<T>::SOLVED ) {
                if( status == ActionSelection<T>::NO_SOLUTION )
                    return NO_SOLUTION;
                else
                    return ERROR;
            } else if( action_selection_.get_time() > time_bound_ ) {
                return TIME;
            }
            assert(!plan.empty());
            if( options_.is_enabled("solver:naive-random-action-selection") || options_.is_enabled("solver:random-action-selection") ) {
                // we need to diferentiate because calculate_relevant_assumptions()
                // assumes the plan reaches the goal
                if( options_.is_enabled("solver:naive-random-action-selection") ) {
                    assumptions.push_back(index_set());
                } else {
                    assert(dynamic_cast<const RandomActionSelection<T>*>(&action_selection_) != 0);
                    const RandomActionSelection<T> &random_action_selection = static_cast<const RandomActionSelection<T>&>(action_selection_);
                    if( random_action_selection.used_alternate_selection() )
                        calculate_relevant_assumptions(plan, raw_plan, state, goal_condition, assumptions);
                    else
                        assumptions.push_back(index_set());
                }
            } else if( options_.is_enabled("solver:hop") ) {
                // apply actions in plan as long as they are applicable
                assumptions.insert(assumptions.end(), plan.size(), index_set());
            } else {
                calculate_relevant_assumptions(plan, raw_plan, state, goal_condition, assumptions);
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
    bool status = kp_instance_.calculate_relevant_assumptions(raw_plan, initial_state, goal, assumptions_on_raw_plan);
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

#endif

