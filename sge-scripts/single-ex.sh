#/bin/bash

planner=$1
parameters=$2
output_dir=$3
nr=`wc -l $parameters | awk '{ print $1; }'`

mkdir -p output
rm -f output/out.$output_dir output/err.$output_dir
sed "s/XXX/$nr/" < template.sub | sed "s/OUT/out.$output_dir/" | sed "s/ERR/err.$output_dir/" > tmp.sub
qsub tmp.sub $planner $parameters $output_dir
rm tmp.sub

