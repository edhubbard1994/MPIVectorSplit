#include <mpi.h>
#include <iostream>
#include <memory>
#include "divider.h"

#define DATA_SIZE 50000
#define NUM_PARTITIONS 19 // each worker can only handle exactly 1 message values > 19 will not return correct sum
#define START_RANGE 0
#define END_RANGE 10

int main (int argv, char **argc) {
	int rank;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	
	if (rank == 0) {

	// Host process
	
		std::shared_ptr<Divider> div = std::make_shared<Divider>(DATA_SIZE,NUM_PARTITIONS,START_RANGE,END_RANGE);
		std::cout << "start the loop\n";
			
		std::vector<int> chunk = div->getNextChunk();
		int proc_count = 1;
		while (chunk.size() > 0) {	
			MPI_Send(&chunk.front(),chunk.size(),MPI_INT,proc_count,1,MPI_COMM_WORLD);
			chunk = div->getNextChunk();
			proc_count ++;
			if (proc_count > 19) {
				proc_count = 1;
			}
		}

		
	} else {

	// worker process
		std::vector<int> v(DATA_SIZE / NUM_PARTITIONS);
		MPI_Recv(&v[0],(DATA_SIZE / NUM_PARTITIONS), MPI_INT, 0 ,1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		std::cout << "Received data of size: " << v.size() << " \n";
		int acc = 0;
		for (int x : v) {
			acc += x;
		}
		MPI_Send( &acc, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
	}

	int proc_count = 1;
	int acc = 0;
	while (proc_count < 20 ) {
		int p;
		MPI_Recv(&p,1, MPI_INT, proc_count, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		std::cout << "Local Total: " << p << " \n";
		++proc_count;
		acc += p;
	}
	std::cout << "===============\n\n";
	std::cout << " THE GRAND TOTAL = " << acc << "\n\n";
	MPI_Finalize();



	return 0;
}
