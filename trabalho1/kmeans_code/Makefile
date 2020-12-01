LIKWID = /usr/local
LIKWID_FLAGS = -I$(LIKWID)/bin/ -I$(LIKWID)/sbin -DLIKWID_PERFMON -I$(LIKWID)/include/
LIKWID_LIBS = -L$(LIKWID)/lib/ -llikwid

LFLAGS = -Wall -Werror -Wextra -Wno-unused-variable -Wno-unused-result -O3 

PROG = kmeans

.PHONY: clean purge

serial:
	gcc $(PROG).c $(LIKWID_FLAGS) $(LIKWID_LIBS) $(LFLAGS) -o $(PROG)

serial-test: serial
	./$(PROG) < ../input/10x1M.txt

parallel:
	gcc -fopenmp $(PROG)-parallel.c $(LIKWID_FLAGS) $(LIKWID_LIBS) $(LFLAGS) -o $(PROG)-parallel

parallel-test: parallel
	export OMP_NUM_THREADS=2
	./$(PROG)-parallel < ../input/10x1M.txt

mean:
	gcc mean.c -o mean

speedup:
	gcc speedup.c -o speedup

clean:
	rm *~ || true

purge: clean
	rm $(PROG) || true
	rm $(PROG)-parallel || true
