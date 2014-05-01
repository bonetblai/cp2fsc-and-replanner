#!/bin/bash

for p in p??.pddl; do
    echo domain.pddl $p
    ../../../src/cp2fsc --tag-all-literals --fsc-states 2 domain.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-w-alltags

for p in p??.pddl; do
    echo domain.pddl $p
    ../../../src/cp2fsc --fsc-states 2 domain.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-wo-alltags

