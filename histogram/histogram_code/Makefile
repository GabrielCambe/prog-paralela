LIKWID = /usr/local
LIKWID_FLAGS = -I$(LIKWID)/bin/ -I$(LIKWID)/sbin -DLIKWID_PERFMON -I$(LIKWID)/include/
LIKWID_LIBS = -L$(LIKWID)/lib/ -llikwid

LFLAGS = $(LIKWID_LIBS) -lm
CFLAGS = $(LIKWID_FLAGS) 

PROG = histogram

.PHONY: clean purge

serial:
	gcc $(PROG).c -lm -o $(PROG)

serial-test: serial
	./$(PROG) < ../4k/4k-a.ppm > out.txt

parallel:
	gcc -fopenmp $(PROG)-parallel.c -lm -o $(PROG)-parallel

parallel-test:
	export OMP_NUM_THREADS=4
	./$(PROG)-parallel < ../4k/4k-a.ppm > out.txt

# serial-likwid:
# 	gcc $(PROG).c $(CFLAGS) $(LFLAGS) -o $(PROG)

# serial-test: serial-likwid
# 	./$(PROG) < ../4k/4k-a.ppm > out.txt

clean:
	rm *~ || true

purge:
	rm $(PROG) || true