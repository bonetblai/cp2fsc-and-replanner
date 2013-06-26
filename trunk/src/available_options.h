#ifndef AVAILABLE_OPTIONS_H
#define AVAILABLE_OPTIONS_H

const char *available_options[] = {
    // problem options
    "print:atom:creation",                 "[INST] print the name of the atoms at creation time",
    "print:action:creation",               "[INST] print the name of the actions at creation time",
    "print:sensor:creation",               "[INST] print the name of the sensors at creation time",
    "print:axiom:creation",                "[INST] print the name of the axioms at creation time",
    "print:deductive-rule",                "[INST] print the deductive rule at creation time",

    // preprocessor options
    "print:atom:removal",                  "[PREP] print the name of the atoms that are removed",
    "print:action:removal",                "[PREP] print the name of the actions that are removed",
    "print:sensor:removal",                "[PREP] print the name of the sensors that are removed",
    "print:axiom:removal",                 "[PREP] print the name of axioms that are removed",

    "print:preprocess:stage",              "[PREP] print the stage name",
    "print:atom:unreachable",              "[PREP] print the name of unreachable atoms",
    "print:atom:static",                   "[PREP] print the name of static atoms",
    "print:action:unreachable" ,           "[PREP] print the name of unreachable actions",
    "print:action:inconsistent",           "[PREP] print the name of inconsistent actions",
    "print:action:useless",                "[PREP] print the name of useless actions",
    "print:sensor:unreachable",            "[PREP] print the name of unreachable sensors",
    "print:axiom:unreachable",             "[PREP] print the name of unreachable axioms",

    // cp-translation options (cp2fsc)
    "print:cp:raw",                        "[CP] print the translation before preprocessing",
    "print:cp:preprocessed",               "[CP] print the translation after preprocessing",

    // ks0-translation options (cp2fsc)
    "print:ks0:raw",                       "[KS0] print the translation before processing",
    "print:ks0:preprocessed",              "[KS0] print the translation after processing",
    "print:ks0:reachable",                 "[KS0] print the name of reachable ks0 literals",
    "print:ks0:tag:must",                  "[KS0] print the name of the tags that must be created",
    "print:ks0:tag:atom:creation",         "[KS0] print the name of the atoms created for tags",
    "print:ks0:action",                    "[KS0] print the name of the actions created",
    "print:ks0:merge:literals",            "[KS0] print the name of literals to be merged",
    "print:ks0:merge:action",              "[KS0] print the name of the merge actions",

    // kp-translation options (k_replanner)
    "print:kp:raw",                        "[KP] print the translation before preprocessing",
    "print:kp:preprocessed",               "[KP] print the translation after preprocessing",
    "print:kp:atom:init",                  "[KP] print the name of atoms added to initial situation",
    "print:kp:action:regular",             "[KP] print the name of regular actions",
    "print:kp:action:sensor",              "[KP] print the name of actions added for sensors",
    "print:kp:action:invariant",           "[KP] print the name of actions added for invariants",

    // solver options (k_replanner)
    "print:solver:plan",                   "[SOLV] print classical plan",
    "print:solver:assumptions",            "[SOLV] print assumptions made in classical plan",
    "print:solver:plan-step",              "[SOLV] print the result of each action in the plan",
    "print:solver:inconsistency",          "[SOLV] print when detecting an inconsistency",
    "print:solver:inconsistency:details",  "[SOLV] print details of the inconsistency",
    "print:solver:consistency:check",      "[SOLV] print the details of each consistency check",
    "remove-intermediate-files",           "[SOLV] remove the files created for calling the classical planner",
    "print:fired-sensors",                 "[SOLV] print the fired sensors at each step of the plan",
    "print:sensed-literals",               "[SOLV] print the sensed literals at each step of the plan",

    // general
    "print:parser:raw",                    "[GEN] print the output from the parser",
    "print:problem:raw",                   "[GEN] print the problem before preprocessing",
    "print:problem:preprocessed",          "[GEN] print the problem after preprocessing",

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
    "[--no-remove-intermediate-files]",
    "[--use-{ff|lama|m|mp}]",
    "[--planner-path <path>]",
    0
};

#endif
