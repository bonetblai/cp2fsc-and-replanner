#ifndef AVAILABLE_OPTIONS_H
#define AVAILABLE_OPTIONS_H

const char *available_options[] = {
    // general
    "parser:print:raw",                    "[PARSER] print the output from the parser",
    "parser:print:translated",             "[PARSER] print the output from the parser after translation (replannner only)",

    // problem options
    "problem:print:raw",                   "[INST] print the problem before preprocessing",
    "problem:print:preprocessed",          "[INST] print the problem after preprocessing",
    "problem:print:atom:creation",         "[INST] print the name of the atoms at creation time",
    "problem:print:action:creation",       "[INST] print the name of the actions at creation time",
    "problem:print:sensor:creation",       "[INST] print the name of the sensors at creation time",
    "problem:print:axiom:creation",        "[INST] print the name of the axioms at creation time",
    "problem:print:deductive-rule:creation", "[INST] print the deductive rule at creation time",

    // preprocessor options
    "problem:print:preprocess:stage",      "[PREP] print the stage name",
    "problem:print:atom:reachable",        "[PREP] print the name of reachable atoms",
    "problem:print:atom:unreachable",      "[PREP] print the name of unreachable atoms",
    "problem:print:action:unreachable" ,   "[PREP] print the name of unreachable actions",
    "problem:print:sensor:unreachable",    "[PREP] print the name of unreachable sensors",
    "problem:print:axiom:unreachable",     "[PREP] print the name of unreachable axioms",
    "problem:print:action:inconsistent",   "[PREP] print the name of inconsistent actions",
    "problem:print:action:useless",        "[PREP] print the name of useless actions",
    "problem:print:atom:static",           "[PREP] print the name of static atoms",

    "problem:print:atom:removal",          "[PREP] print the name of the atoms that are removed",
    "problem:print:action:removal",        "[PREP] print the name of the actions that are removed",
    "problem:print:sensor:removal",        "[PREP] print the name of the sensors that are removed",
    "problem:print:axiom:removal",         "[PREP] print the name of axioms that are removed",
    "problem:print:invariant:removal",     "[PREP] print the invariants are removed",

    "problem:print:action-compilation",    "[PREP] print action compilation",
    "problem:action-compilation",          "[PREP] perform action compilation",

    // cp-translation options (cp2fsc)
    "cp:print:raw",                        "[CP] print the translation before preprocessing",
    "cp:print:preprocessed",               "[CP] print the translation after preprocessing",

    // ks0-translation options (cp2fsc)
    "ks0:print:raw",                       "[KS0] print the translation before processing",
    "ks0:print:preprocessed",              "[KS0] print the translation after processing",
    "ks0:print:reachable",                 "[KS0] print the name of reachable ks0 literals",
    "ks0:print:tag:must",                  "[KS0] print the name of the tags that must be created",
    "ks0:print:tag:atom:creation",         "[KS0] print the name of the atoms created for tags",
    "ks0:print:action",                    "[KS0] print the name of the actions created",
    "ks0:print:merge:literals",            "[KS0] print the name of literals to be merged",
    "ks0:print:merge:action",              "[KS0] print the name of the merge actions",

    // kp-translation options (k_replanner)
    "kp:print:raw",                        "[KP] print the translation before preprocessing",
    "kp:print:preprocessed",               "[KP] print the translation after preprocessing",
    "kp:print:atom:init",                  "[KP] print the name of atoms added to initial situation",
    "kp:print:action:regular",             "[KP] print the name of regular actions",
    "kp:print:action:sensor",              "[KP] print the name of actions added for sensors",
    "kp:print:action:invariant",           "[KP] print the name of actions added for invariants",
    "kp:print:action:drule",               "[KP] print deductive KP actions (lw1 translation)",
    "kp:print:action:drule:var",           "[KP] print deductive KP actions for variables (lw1 translation)",
    "kp:print:action:drule:sensing",       "[KP] print deductive KP actions for sensing (lw1 translation)",
    "kp:merge-drules",                     "[KP] merge decision rules with common precondition",
    "kp:subgoaling",                       "[KP] goal of KP problem is either goal or unknown static fluents",

    // planner options (k_replanner)
    "planner:print:plan",                  "[PLANNER] print classical plan (reduced)",
    "planner:print:plan:raw",              "[PLANNER] print classical plan (raw)",
    "planner:remove-intermediate-files",   "[PLANNER] remove the files created for calling the classical planner",

    // solver options (k_replanner)
    "solver:print:assumptions",            "[SOLVER] print assumptions made in classical plan",
    "solver:print:steps",                  "[SOLVER] print the result of each action in the plan",
    //"solver:print:inconsistency",          "[SOLVER] print when detecting an inconsistency",
    //"solver:print:inconsistency:details",  "[SOLVER] print details of the inconsistency",
    //"solver:print:consistency:check",      "[SOLVER] print each consistency check",
    "solver:print:fired-sensors",          "[SOLVER] print the fired sensors at each step of the plan",
    "solver:print:sensed-literals",        "[SOLVER] print the sensed literals at each step of the plan",

    // clg translation
    "clg:print:effect",                    "[CLG] print effect actions",
    "clg:print:set-sensing",               "[CLG] print set-sensing actions",
    "clg:print:turn-on-sensor",            "[CLG] print turn-on-sensor actions (only when no effect and set-sensing actions)",
    "clg:print:post",                      "[CLG] print post actions",
    "clg:print:sensor",                    "[CLG] print sensors",
    "clg:print:generated",                 "[CLG] print all actions and sensors",
    "clg:print:invariants:var",            "[CLG] print variable invariants",
    "clg:print:invariants:sensing",        "[CLG] print sensing invariants",
    "clg:print:invariants",                "[CLG] print all invariants",

    // lw1 planner
    "lw1:print:observable-atoms",          "[LW1] print observable atoms",
    "lw1:print:atoms-for-state-variables", "[LW1] print atoms for state variables",
    "lw1:print:variables",                 "[LW1] print valued for instantiated variables",
    "lw1:print:beams",                     "[LW1] print beams for observable literals",
    "lw1:print:effect",                    "[LW1] print effect actions",
    "lw1:print:set-sensing",               "[LW1] print set-sensing actions",
    "lw1:print:post",                      "[LW1] print post actions",
    "lw1:print:sensors",                   "[LW1] print sensors",
    "lw1:print:generated",                 "[LW1] print all actions and sensors",
    "lw1:print:drule",                     "[LW1] print all deductive rules",
    "lw1:print:drule:var",                 "[LW1] print deductive rules for variables",
    "lw1:print:drule:sensing",             "[LW1] print deductive rules for sensing",
    "lw1:print:drule:static",              "[LW1] print deductive rules obtained from compilation of static sensing",
    "lw1:print:compiled-static-sensing",   "[LW1] print compiled static sensing models",
    "lw1:print:axioms",                    "[LW1] print axioms generated when compiling static observables",

    "lw1:strict",                          "[LW1] strict compliance with lw1 specification",
    "lw1:compile-static-observables",      "[LW1] compile the value of static observable fluents at init",
    "lw1:complete-effects",                "[LW1] complete effects for multivalued variables",
    "lw1:drule:sensing:type3",             "[LW1] generate deductive rules for sensing of type 3",

    "lw1:inference:forward-chaining",      "[LW1] uses forward chaining of drules to make inference (old and sometimes incorrect method)",
    "lw1:inference:up",                    "[LW1] uses unit resolution as inference mechanism",
    "lw1:inference:up:1-lookahead",        "[LW1] uses unit resolution with 1-lookahead as inference mechanism",

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
