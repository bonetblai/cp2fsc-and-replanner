#!/bin/bash

folders=$*

for folder in $folders; do
    cd $folder
    for domain in *; do
        tmp1=${domain//_/ }
        family=`echo $tmp1 | cut -f1 -d' '`
        domain_file=`echo $tmp1 | cut -f2 -d' '`
        cd $domain
        for problem in *; do
            tmp1=${problem//_/ }
            problem_file=`echo $tmp1 | cut -f2 -d' '`
            cd $problem
            for file in *; do
                grep ^stats $file | \
                  awk '{ planner = $2;
                         plan_size = $4;
                         planner_calls = $6;
                         prep_time = $8;
                         planner_time = $(10);
                         planner_search_time = $(12);
                         inference_time = $(14);
                         instance_time = $(16);
                         total_acc_time = $(18);
                         printf "\"%s\",%s,%s,%s,%s,%d,%d,%f,%f,%f,%f,%f,%f\n", folder, family, domain_file, problem_file, planner, plan_size, planner_calls, prep_time, planner_time, planner_search_time, inference_time, instance_time, total_acc_time;
                       }' \
                       folder=$folder \
                       family=$family \
                       domain_file=$domain_file \
                       problem_file=$problem_file
            done
            cd ..
        done
        cd ..
    done
    cd ..
done

