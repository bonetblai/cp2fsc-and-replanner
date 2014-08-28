#!/bin/bash

USAGE="Usage: ./runme.sh <standard/clg/mvv2> <model/raw/preprocessed>"

if [ "model" = "$2" ];
then
    OPT=" --options=mvv:print:compiled-sensing-models"
elif [ "raw" = "$2" ];
then
    OPT=" --options=problem:print:raw"
elif [ "preprocessed" = "$2" ];
then
    OPT=" --options=kp:print:preprocessed"
elif [ "none" = "$2" ];
then
    OPT = ""
else
    echo
    echo $USAGE
    echo
    exit
fi

if [ "standard" = "$1" ];
then
    ./k-replanner --print-domain-only$OPT --keep-intermediate-files --max-time 10 ../benchmarks/replanner/doors/known_init_pos/domain.pddl ../benchmarks/replanner/doors/known_init_pos/problems/n05.pddl
elif [ "clg" = "$1" ];
then
    ./k-replanner --print-domain-only$OPT --keep-intermediate-files --max-time 10 ../benchmarks/replanner/CLG/wumpus/wumpus05/d.pddl ../benchmarks/replanner/CLG/wumpus/wumpus05/p.pddl
elif [ "mvv2" = "$1" ];
then
    ./k-replanner --print-domain-only$OPT --keep-intermediate-files --max-time 10 ../benchmarks/replanner/CLG/wumpus/multivalued-variables/diag05/d.pddl ../benchmarks/replanner/CLG/wumpus/multivalued-variables/diag05/p.pddl
    #./k-replanner --print-domain-only$OPT --keep-intermediate-files --max-time 10 ../benchmarks/replanner/CLG/doors/multivalued-variables/new-d.pddl ../benchmarks/replanner/CLG/doors/multivalued-variables/new-p5.pddl
else
    echo
    echo $USAGE
    echo
fi
