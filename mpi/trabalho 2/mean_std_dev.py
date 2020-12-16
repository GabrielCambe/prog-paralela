#!/usr/bin/python3
import argparse
import numpy

parser = argparse.ArgumentParser(
    description='Recebe lista de valores e seus labels na entrada e gera a média e desvio padrão deles.'
)
parser.add_argument('-v', '--values', dest='values')
args = parser.parse_args()
measures = {}

with open(args.values, 'r') as values:
    line = values.readline()
    while line:
        label, value = line.split()
        try:
            measures.update({label: measures[label] + [float(value)]})
        except KeyError:
            measures.update({label: [float(value)]})

        line = values.readline()

for key in measures.keys():
    print( { 'mean_'+key: numpy.mean(measures[key])} )
    print( { 'std_'+key: numpy.std(measures[key])} )