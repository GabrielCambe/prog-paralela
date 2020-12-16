LIKWID = /usr/local
LIKWID_FLAGS = -I$(LIKWID)/bin/ -I$(LIKWID)/sbin -DLIKWID_PERFMON -I$(LIKWID)/include/
LIKWID_LIBS = -L$(LIKWID)/lib/ -llikwid

LFLAGS = $(LIKWID_LIBS) -lm
CFLAGS = $(LIKWID_FLAGS) 

PROG = pi

.PHONY: clean purge

serial:
	gcc $(PROG).c $(LIKWID_FLAGS) $(LIKWID_LIBS) -lm -o $(PROG)

serial-test: serial
	./$(PROG)

parallel:
	gcc -fopenmp $(PROG)-parallel.c $(LIKWID_FLAGS) $(LIKWID_LIBS) -lm -o $(PROG)-parallel

parallel-test: parallel
	export OMP_NUM_THREADS=2
	./$(PROG)-parallel

mean:
	gcc mean.c -o mean

speedup:
	gcc speedup.c -o speedup

clean:
	rm *~ || true

purge: clean
	rm $(PROG) || true
	rm $(PROG)-parallel || true