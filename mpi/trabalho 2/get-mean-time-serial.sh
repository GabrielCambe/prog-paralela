#!/bin/bash
./multiple-exec-serial.sh $1 $2 > time-values-serial-$1
python3 mean_std_dev.py -v time-values-serial-$1 > mean-time-serial-$1
