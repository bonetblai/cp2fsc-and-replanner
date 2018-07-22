#!/bin/bash

folders=$*

for folder in $folders; do
    cd $folder
    git rm -f h?*.pddl

    mkdir -p broken-hidden
    cp ../../doors/p05/broken-hidden/README broken-hidden

    n=`wc h.pddl | awk '{ print $1; }'`
    for ((i=2;i<11;i++)); do (echo "(define (problem x)"; head -$i h.pddl | tail -1; echo ")") > broken-hidden/h000$((i-1)).pddl; done
    for ((i=11;i<101;i++)); do (echo "(define (problem x)"; head -$i h.pddl | tail -1; echo ")") > broken-hidden/h00$((i-1)).pddl; done
    for ((i=101;i<1001;i++)); do (echo "(define (problem x)"; head -$i h.pddl | tail -1; echo ")") > broken-hidden/h0$((i-1)).pddl; done
    for ((i=1001;i<$n;i++)); do (echo "(define (problem x)"; head -$i h.pddl | tail -1; echo ")") > broken-hidden/h$((i-1)).pddl; done

    grep -h hidden h.pddl > xxx
    grep -h hidden broken-hidden/h*.pddl > yyy
    diff xxx yyy

    git add h.pddl broken-hidden/*
    cd ..
done

