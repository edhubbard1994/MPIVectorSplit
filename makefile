CC=mpiCC
CFLAGS += -g
CFLAGS += -lpthread

SRC=main.cpp divider.cpp
INCLUDE=divider.h


.PHONY: bin
bin:
	$(CC) $(CFLAGS) $(INCLUDE)  $(SRC) -o mpi.elf

.PHONY: run
run:
	mpirun -n 20 -preload-binary --oversubscribe -hostfile ~/.mpiconf.txt ./mpi.elf
	#mpirun -n 10 -hostfile mpiconfig.txt  ./mpi.elf
.PHONY: debug
debug:
	mpiexec -n X gdb ./mpi.elf
