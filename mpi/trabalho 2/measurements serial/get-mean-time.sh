#!/bin/bash
./multiple-exec.sh $1 $2 $3 > time_values_$2
python3 mean_std_dev.py -v time_values_$2