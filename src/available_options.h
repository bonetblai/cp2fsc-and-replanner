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

#ifndef AVAILABLE_OPTIONS_H
#define AVAILABLE_OPTIONS_H

const char *available_options[] = {
    // general
    "parser:print:raw",                                 "[PARSER] print the output from the parser",
    "parser:print:translated",                          "[PARSER] print the output from the parser after translation (replannner only)",

    // problem options
    "problem:print:raw",                                "[INST] print the problem before preprocessing",
    "problem:print:preprocessed",                       "[INST] print the problem after preprocessing",
    "problem:print:atom:creation",                      "[INST] print the name of the atoms at creation time",
    "problem:print:action:creation",                    "[INST] print the name of the actions at creation time",
    "problem:print:sensor:creation",                    "[INST] print the name of the sensors at creation time",
    "problem:print:axiom:creation",                     "[INST] print the name of the axioms at creation time",
    "problem:print:deductive-rule:creation",            "[INST] print the deductive rule at creation time",

    // preprocessor options
    "problem:print:preprocess:stage",                   "[PREP] print the stage name",
    "problem:print:atom:reachable",                     "[PREP] print the name of reachable atoms",
    "problem:print:atom:unreachable",                   "[PREP] print the name of unreachable atoms",
    "problem:print:action:unreachable" ,                "[PREP] print the name of unreachable actions",
    "problem:print:sensor:unreachable",                 "[PREP] print the name of unreachable sensors",
    "problem:print:axiom:unreachable",                  "[PREP] print the name of unreachable axioms",
    "problem:print:action:inconsistent",                "[PREP] print the name of inconsistent actions",
    "problem:print:action:useless",                     "[PREP] print the name of useless actions",
    "problem:print:atom:static",                        "[PREP] print the name of static atoms",

    "problem:print:atom:removal",                       "[PREP] print the name of the atoms that are removed",
    "problem:print:action:removal",                     "[PREP] print the name of the actions that are removed",
    "problem:print:sensor:removal",                     "[PREP] print the name of the sensors that are removed",
    "problem:print:axiom:removal",                      "[PREP] print the name of axioms that are removed",
    "problem:print:invariant:removal",                  "[PREP] print the invariants are removed",

    "problem:print:action-compilation",                 "[PREP] print action compilation",
    "problem:action-compilation",                       "[PREP] perform action compilation",

    // cp-translation options (cp2fsc)
    "cp:print:raw",                                     "[CP] print the translation before preprocessing",
    "cp:print:preprocessed",                            "[CP] print the translation after preprocessing",

    // ks0-translation options (cp2fsc)
    "ks0:print:raw",                                    "[KS0] print the translation before processing",
    "ks0:print:preprocessed",                           "[KS0] print the translation after processing",
    "ks0:print:reachable",                              "[KS0] print the name of reachable ks0 literals",
    "ks0:print:tag:must",                               "[KS0] print the name of the tags that must be created",
    "ks0:print:tag:atom:creation",                      "[KS0] print the name of the atoms created for tags",
    "ks0:print:action",                                 "[KS0] print the name of the actions created",
    "ks0:print:merge:literals",                         "[KS0] print the name of literals to be merged",
    "ks0:print:merge:action",                           "[KS0] print the name of the merge actions",

    // kp-translation options (k_replanner, clg, lw1)
    "kp:print:raw",                                     "[KP] print the translation before preprocessing",
    "kp:print:preprocessed",                            "[KP] print the translation after preprocessing",
    "kp:print:atom:init",                               "[KP] print the name of atoms added to initial situation",
    "kp:print:action:regular",                          "[KP] print the name of regular actions",
    "kp:print:action:sensor",                           "[KP] print the name of actions added for sensors",
    "kp:print:action:invariant",                        "[KP] print the name of actions added for invariants",
    "kp:print:action:drule",                            "[KP] print deductive KP actions (lw1 translation)",
    "kp:print:action:drule:var",                        "[KP] print deductive KP actions for variables (lw1 translation)",
    "kp:print:action:drule:sensing",                    "[KP] print deductive KP actions for sensing (lw1 translation)",
    "kp:print:action:subgoaling",                       "[KP] print subgoaling actions",
    "kp:merge-drules",                                  "[KP] merge decision rules with common precondition",
    "kp:subgoaling",                                    "[KP] replace goal of KP problem (implied option)",
    "kp:subgoaling:non-reversable-goal-atoms",          "[KP] add non-reversable goal atoms as subgoals [EXPERIMENTAL]",
    "kp:subgoaling:static-unknowns",                    "[KP] add unknown static fluents as subgoals [EXPERIMENTAL]",

    // planner options (k_replanner, clg, lw1)
    "planner:print:plan",                               "[PLANNER] print classical plan (reduced)",
    "planner:print:plan:raw",                           "[PLANNER] print classical plan (raw)",
    "planner:remove-intermediate-files",                "[PLANNER] remove the files created for calling the classical planner",
    "planner:support-for-axioms",                       "[PLANNER] indicates that the classical planner supports axioms (aka derived predicates)",

    // solver options (k_replanner, clg, lw1)
    "solver:forced-moves",                              "[SOLVER] don't call planner when there is just one applicable operator",
    "solver:print:assumptions",                         "[SOLVER] print assumptions made in classical plan",
    "solver:print:assumptions:raw",                     "[SOLVER] print assumptions made in raw classical plan",
    "solver:print:steps",                               "[SOLVER] print the result of each action in the plan",
    //"solver:print:inconsistency",                       "[SOLVER] print when detecting an inconsistency", // DEAD CODE in new_solver.h
    //"solver:print:inconsistency:details",               "[SOLVER] print details of the inconsistency",    // DEAD CODE in new_solver.h
    //"solver:print:consistency:check",                   "[SOLVER] print each consistency check",          // DEAD CODE in new_solver.h
    "solver:print:fired-sensors",                       "[SOLVER] print the fired sensors at each step of the plan",
    "solver:print:sensed-literals",                     "[SOLVER] print the sensed literals at each step of the plan",

    // solver option for lw1
    "solver:width-based-action-selection",              "[SOLVER] use width-based algorithm for action selection (LW1)",
    "solver:random-action-selection",                   "[SOLVER] random action selection (LW1)",

    // clg
    "clg:print:effect",                                 "[CLG] print effect actions",
    "clg:print:set-sensing",                            "[CLG] print set-sensing actions",
    "clg:print:turn-on-sensor",                         "[CLG] print turn-on-sensor actions (only when no effect and set-sensing actions)",
    "clg:print:post",                                   "[CLG] print post actions",
    "clg:print:sensor",                                 "[CLG] print sensors",
    "clg:print:generated",                              "[CLG] print all actions and sensors",
    "clg:print:invariants:var",                         "[CLG] print variable invariants",
    "clg:print:invariants:sensing",                     "[CLG] print sensing invariants",
    "clg:print:invariants",                             "[CLG] print all invariants",

    // lw1
    "lw1:print:observable-atoms",                       "[LW1] print observable atoms",
    "lw1:print:atoms-for-state-variables",              "[LW1] print atoms for state variables",
    "lw1:print:variables:groups",                       "[LW1] print instantiated variable groups",
    "lw1:print:variables",                              "[LW1] print valued for instantiated variables",
    "lw1:print:beams",                                  "[LW1] print beams for observable literals",
    "lw1:print:effect",                                 "[LW1] print effect actions",
    "lw1:print:set-sensing",                            "[LW1] print set-sensing actions",
    "lw1:print:turn-on-sensor",                         "[LW1] print turn-on-sensor actions (only when no effect and set-sensing actions)",
    "lw1:print:post",                                   "[LW1] print post actions",
    "lw1:print:sensors",                                "[LW1] print sensors",
    "lw1:print:generated",                              "[LW1] print all actions and sensors",
    "lw1:print:drule",                                  "[LW1] print all deductive rules",
    "lw1:print:drule:var",                              "[LW1] print deductive rules for variables",
    "lw1:print:drule:sensing",                          "[LW1] print deductive rules for sensing",
    "lw1:print:drule:static",                           "[LW1] print deductive rules obtained from compilation of static sensing",
    "lw1:print:compiled-static-sensing",                "[LW1] print compiled static sensing models",
    "lw1:print:axioms",                                 "[LW1] print axioms generated when compiling static observables",

    "lw1:aaai",                                         "[LW1] translation used in AAAI-14 paper",
    "lw1:strict",                                       "[LW1] strict compliance with lw1 specification",
    "lw1:sensing:make-dnf",                             "[LW1] when sensing model is not in DNF, do automatic translation (may be very inefficient)",
    "lw1:enable-kp/s",                                  "[LW1] generate KP/s problem for classical planner [EXPERIMENTAL]",

    // lw1 (inference)
    "lw1:inference:forward-chaining",                   "[LW1] uses forward chaining of drules to make inference (old and sometimes incorrect method)",
    "lw1:inference:up",                                 "[LW1] uses unit resolution as inference mechanism",
    "lw1:inference:up:preload",                         "[LW1] preload axioms before applying inference",
    "lw1:inference:up:watched-literals",                "[LW1] uses unit resolution with watched literals as inference mechanism",
    "lw1:inference:up:lookahead",                       "[LW1] uses unit resolution with 1-lookahead as inference mechanism [EXPERIMENTAL]",
    "lw1:inference:up:enhanced",                        "[LW1] maintain inferred (non-forbidden) clauses [EXPERIMENTAL]",
    "lw1:inference:ac3",                                "[LW1] uses AC3 as inference algorithm",

    // lw1 boost
    "lw1:boost:single-sensing-literal-enablers",        "[LW1] DEPRECATED (don't use)",
    "lw1:boost:compile-static-observables",             "[LW1] compile the value of static observable fluents at init", // CHECK
    "lw1:boost:enable-post-actions",                    "[LW1] XXXX", // CHECK

    "lw1:boost:complete-effects",                       "[LW1] complete effects for variables", // CHECK
    "lw1:boost:complete-effects:type4",                 "[LW1] complete effects for variables", // CHECK
    "lw1:boost:complete-effects:type4:obs",             "[LW1] complete effects for variables", // CHECK
    "lw1:boost:complete-effects:type4:state",           "[LW1] complete effects for variables", // CHECK

    "lw1:boost:drule:sensing:type3",                    "[LW1] generate type3 deductive rules for sensing", // CHECK (rename types)
    "lw1:boost:drule:sensing:type4",                    "[LW1] replace type4 deductive rule by boosted version when DNF has just one term",
    "lw1:boost:drule:sensing:type4:add",                "[LW1] add boosted type4 deductive rules in addition to standard rules",

    "lw1:boost:literals-for-observables",               "[LW1] add literals for static observables (useful in problem with width > 1)", // CHECK
    "lw1:boost:literals-for-observables:dynamic",       "[LW1] add literals for observables (useful in problem with width > 1)", // CHECK

    0
};

const char *cp2fsc_cmdline_options[] = {
    "[--compound-obs-as-fluents]",
    "[--fsc-states <n>]",
    "[--help]",
    "[--no-forbid-inconsistent-tuples]",
    "[--output-metadata <filename>]",
    "[--prefix <prefix>]",
    "[--tag-all-literals]",
    0
};

const char *k_replanner_cmdline_options[] = {
    "[--help]",
    "[--max-time <time>]",
    "[--no-print-plan]",
    "[--prefix <prefix>]",
    "[--keep-intermediate-files]",
    "[--planner {ff|lama|m|mp}]",
    "[--planner-path <path>]",
    "[--tmpfile-path <path>]",
    0
};

#endif
