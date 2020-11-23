#!/bin/bash

lista=$(likwid-perfctr -a | grep -e $' .[A-Z,0-9,_]*\t' -o) 

for i in $lista; do
    echo $i
done
	
