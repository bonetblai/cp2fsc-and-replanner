#!/bin/bash

export LW1_ROOT=$HOME/software/pure-lw1
export benchmarks=$LW1_ROOT/benchmarks/lw1

family=$1
domain=$2
problem=$3
hidden_prefix=$4
number=$5
options=$6

num_hidden=`ls $benchmarks/$family/$hidden_prefix/h*.pddl | wc | awk '{ print $1; }'`

echo hola | \
  awk '{ n = number < num_hidden ? number : num_hidden;
         ndigits = 1;
         if( num_hidden > 9 ) ++ndigits;
         if( num_hidden > 99 ) ++ndigits;
         if( num_hidden > 999 ) ++ndigits;
         if( num_hidden > 9999 ) ++ndigits;
         for( i = 1; i <= n; ++i ) {
             printf "%s %s %s %s/h%0*d.pddl %s\n", options, domain, problem, hidden_prefix, ndigits, i, family;
         }
       }' \
       number=$number \
       num_hidden=$num_hidden \
       family=$family \
       domain=$family/$domain \
       problem=$family/$problem \
       hidden_prefix=$family/$hidden_prefix \
       options=$options

