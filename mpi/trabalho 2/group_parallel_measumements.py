#!/usr/bin/python3
import sys
import numpy

times = []

line = sys.stdin.readline()
while line:
    label = line.split()[0]
    if label == 'parallel_time:':
        label, value = line.split()
        times.append(float(value))

    line = sys.stdin.readline()

print(label, max(times))