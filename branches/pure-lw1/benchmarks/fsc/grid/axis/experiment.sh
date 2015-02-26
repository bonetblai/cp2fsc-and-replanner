#!/bin/bash

for p in corner*.pddl prize*.pddl; do
    echo domain_A.pddl $p
    ../../../../src/cp2fsc --tag-all-literals --fsc-states 1 domain_A.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-w-alltags

for p in corner*.pddl prize*.pddl; do
    echo domain_A.pddl $p
    ../../../../src/cp2fsc --fsc-states 1 domain_A.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-wo-alltags

