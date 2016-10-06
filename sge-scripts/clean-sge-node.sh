#!/bin/bash

node=$1
echo "cleaning sge-node $node ..."
ssh $node "rm -f /scratch/ff.output.* /scratch/Mp.output.* /scratch/M.output.* /scratch/gen-d*.pddl /scratch/gen-p*.pddl"

