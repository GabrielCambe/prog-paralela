CC = gcc -g -Wall -Wextra

all: gerador ocorrencias
	./gerador 10 | ./ocorrencias

count_number_of_uniques: gerador ocorrencias
	./gerador 10 | ./ocorrencias | wc -l

gerador:
	$(CC) -o gerador gerador.c

ocorrencias:
	$(CC) -o ocorrencias ocorrencias.c

remove:
	rm gerador || true
	rm ocorrencias || true
