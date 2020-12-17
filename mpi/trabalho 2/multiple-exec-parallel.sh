#!/bin/bash
for i in $(seq 1 $3):
do
    echo "rodada $i" 1>&2
    make INPUT=$2 NUM_PROCS=$1 parallel-test | ./group_parallel_measumements.py
done
