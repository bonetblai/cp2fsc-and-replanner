#!/bin/bash

time_cutoff=$1
shift
files=$*

grep stats $files  | \
    awk '{
             t = $19;
             if (t <= $time_cutoff) {
                 n++;
                 l = $4;
                 if (l > 0) {
                     succ++;
                     steps += l;
                     ptime += $10;
                     stime += $14;
                     time += t;
                 }
             }
         }
         END {
             printf "n=%d, succ=%d, steps=%d, ptime=%f, stime=%f, time=%f\n", n, succ, steps, ptime, stime, time;
         }' 


