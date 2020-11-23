#!/bin/bash
make -s mean
echo $(./multiple-exec.sh $1 $2) | ./mean