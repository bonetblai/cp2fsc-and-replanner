#!/bin/bash

for p in corner*.pddl; do
    echo domain_R.pddl $p
    ../../../../src/cp2fsc --tag-all-literals --fsc-states 1 domain_R.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-w-alltags

for p in prize[234]x?_R.pddl prize5x[234]_R.pddl; do
    echo domain_R.pddl $p
    ../../../../src/cp2fsc --tag-all-literals --fsc-states 2 domain_R.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done >> experiment-w-alltags

for p in prize5x5_R.pddl; do
    echo domain_R.pddl $p
    ../../../../src/cp2fsc --tag-all-literals --fsc-states 3 domain_R.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done >> experiment-w-alltags

for p in corner*.pddl; do
    echo domain_R.pddl $p
    ../../../../src/cp2fsc --fsc-states 1 domain_R.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-wo-alltags

for p in prize[234]x?_R.pddl prize5x[234]_R.pddl; do
    echo domain_R.pddl $p
    ../../../../src/cp2fsc --fsc-states 2 domain_R.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done >> experiment-wo-alltags

for p in prize5x5_R.pddl; do
    echo domain_R.pddl $p
    ../../../../src/cp2fsc --fsc-states 3 domain_R.pddl $p > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done >> experiment-wo-alltags

