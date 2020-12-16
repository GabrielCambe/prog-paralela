PROG = hellompi
CFLAGS = -Wall -Werror -Wextra -Wno-unused-variable -Wno-unused-result -O3 
HOSTFILE = hosts
NUM_PROCS = 8

.PHONY: clean purge

parallel:
	mpicc $(PROG).c $(CFLAGS) -o $(PROG)

parallel-test: parallel
	mpirun --hostfile $(HOSTFILE) -np $(NUM_PROCS) ./$(PROG)

clean:
	rm *~ || true

purge: clean
	rm $(PROG) || true
