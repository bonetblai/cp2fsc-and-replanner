#!/bin/bash

planner=$1
options=$2
domain=$3
problem=$4
hidden=$5

export LW1_ROOT=$HOME/software/pure-lw1
export FPATH=$HOME/software/FF-v2.3-parse-patch
export MPATH=$HOME/software/madagascar
export BENCHMARKS=$LW1_ROOT/benchmarks/lw1
export TMPFILE_PATH=/scratch

if [ "$planner" == "ff" ]; then
    $LW1_ROOT/src/lw1 --max-time 10800 --planner-path $FPATH --tmpfile-path $TMPFILE_PATH --options=${options} $BENCHMARKS/$domain $BENCHMARKS/$problem $BENCHMARKS/$hidden
elif [ "$planner" == "m" ]; then
    $LW1_ROOT/src/lw1 --max-time 10800 --planner-path $MPATH --planner $planner --tmpfile-path $TMPFILE_PATH --options=${options} $BENCHMARKS/$domain $BENCHMARKS/$problem $BENCHMARKS/$hidden
elif [ "$planner" == "mp" ]; then
    $LW1_ROOT/src/lw1 --max-time 10800 --planner-path $MPATH --planner $planner --tmpfile-path $TMPFILE_PATH --options=${options} $BENCHMARKS/$domain $BENCHMARKS/$problem $BENCHMARKS/$hidden
else
    echo "Unknown planner '$planner'"
fi

