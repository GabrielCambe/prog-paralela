#!/bin/bash
./multiple-exec-parallel.sh $1 $2 $3 > time-values-parallel-$1PROCS-$2
python3 mean_std_dev.py -v time-values-parallel-$1PROCS-$2 > mean-time-parallel-$1PROCS-$2
