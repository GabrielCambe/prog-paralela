#!/bin/bash
for i in $(seq 1 $3):
do
    output=$(./$1 < $2)
    echo "$output" | tail -n 2

done
