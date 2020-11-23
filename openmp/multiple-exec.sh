#!/bin/bash
for i in $(seq 1 $2):
do
    ./$1 | head -n 1
done
echo -1.0