#!/bin/bash
for i in $(seq 1 $2):
do
    echo "rodada $i" 1>&2
    make INPUT=$1 serial-test | tail -n 2
done
