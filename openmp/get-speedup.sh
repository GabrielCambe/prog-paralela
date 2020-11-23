#!/bin/bash
make -s speedup
./compare-time.sh $1 $2 $3 | ./speedup