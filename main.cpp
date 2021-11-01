#include <mpi.h>
#include <iostream>
#include <memory>
#include "divider.h"

#define DATA_SIZE 119
#define NUM_PARTITIONS 29
#define START_RANGE 0
#define END_RANGE 100

int main (int argv, char **argc) {
	int rank;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	
	if (rank == 0) {
	// Host process	
		std::shared_ptr<Divider> div = std::make_shared<Divider>(DATA_SIZE,NUM_PARTITIONS,START_RANGE,END_RANGE);
		std::cout << "start the loop\n";
			
		std::vector<int> chunk = div->getNextChunk();
		while (chunk.size() > 0) {	
			std::cout << chunk.size() <<std::endl;
			chunk = div->getNextChunk();
		}
		
	} else {
	// worker process
		std::cout << "worker: " << rank << "says hello\n";
	}
	MPI_Finalize();



	return 0;
}
