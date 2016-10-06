#!/bin/bash

for n in node04 node06 node07 node08 node09 node10; do
    ./clean-sge-node.sh $n
done

