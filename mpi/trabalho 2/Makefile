LIKWID = /usr/local
LIKWID_FLAGS = -I$(LIKWID)/bin/ -I$(LIKWID)/sbin -DLIKWID_PERFMON -I$(LIKWID)/include/
LIKWID_LIBS = -L$(LIKWID)/lib/ -llikwid

PROG = kmeans
CFLAGS = -Wall -Werror -Wextra -Wno-unused-variable -Wno-unused-result -O3 
HOSTFILE = hosts
# NUM_PROCS = 8

# INPUT = 10x1M.txt # P CMD LINE

.PHONY: clean purge

serial:
	@gcc $(PROG).c $(LIKWID_FLAGS) $(LIKWID_LIBS) $(LFLAGS) -o $(PROG)

serial-test: serial
	@./$(PROG) < $(INPUT)

parallel:
	@mpicc $(PROG)-parallel.c $(LIKWID_FLAGS) $(LIKWID_LIBS) $(CFLAGS) -o $(PROG)-parallel

parallel-test: parallel
	@mpirun --hostfile $(HOSTFILE) -np $(NUM_PROCS) ./$(PROG)-parallel < $(INPUT)

clean:
	rm *~ || true

purge: clean
	rm $(PROG) || true
	rm $(PROG)-parallel || true
