#!/bin/bash

for d in domain-*.pddl; do
    echo $d ${d/domain/p}
    ../../../src/cp2fsc --tag-all-literals --fsc-states 2 $d ${d/domain/p} > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-w-alltags

for d in domain-*.pddl; do
    echo $d ${d/domain/p}
    ../../../src/cp2fsc --fsc-states 2 $d ${d/domain/p} > /dev/null
    (ulimit -t 600; ~/jussi/Mp d.pddl p.pddl | grep "total time")
    rm d.pddl p.pddl
done > experiment-wo-alltags

