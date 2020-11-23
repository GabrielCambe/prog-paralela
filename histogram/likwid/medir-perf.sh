#!/bin/bash

grupos_de_teste=$(likwid-perfctr -a | grep -e $' .[A-Z,0-9,_]*\t' -o)

#for i in 32 50 64 100 128 200 256 300 400 512 1000 1024 2000 2048 3000 4000 4096 5000 10000; do
for i in 32; do
    for j in $grupos_de_teste;
    do
	if [[ $j == $'FLOPS_DP' || $j == $'L3'] || $j = $'L2CACHE' ]];
	then
	    likwid-perfctr -O -C 0 -g $j -m ./matmult $i > $j.$i
	    cat $j.$i | grep -e $',Region*'
	fi
    done
done
