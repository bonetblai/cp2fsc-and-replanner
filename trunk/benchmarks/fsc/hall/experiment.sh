#!/bin/bash

for p in p1x4_A.pddl; do
    echo domain_A.pddl $p
    ../../../src/cp2fsc --tag-all-literals --fsc-states 2 domain_A.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-w-alltags

for p in p4x4_A.pddl; do
    echo domain_A.pddl $p
    ../../../src/cp2fsc --tag-all-literals --fsc-states 4 domain_A.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done >> experiment-w-alltags

for p in p1x4_A.pddl; do
    echo domain_A.pddl $p
    ../../../src/cp2fsc --fsc-states 2 domain_A.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-wo-alltags

for p in p4x4_A.pddl; do
    echo domain_A.pddl $p
    ../../../src/cp2fsc --fsc-states 4 domain_A.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done >> experiment-wo-alltags

