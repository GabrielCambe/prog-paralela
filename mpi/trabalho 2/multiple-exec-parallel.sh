#!/bin/bash
for i in $(seq 1 $3):
do
    output=$(make INPUT=$2 NUM_PROCS=$1 parallel-test | ./group_parallel_measumements.py)
    echo "$output" 

done
