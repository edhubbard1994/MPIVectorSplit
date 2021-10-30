#include <mpi.h>
#include <iostream>
#include <memory>
#include "divider.h"


int main (int argv, char **argc) {
	int rank;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	
	if (rank == 0) {
		
		std::shared_ptr<Divider> div = std::make_shared<Divider>(200,4,1,28);
		std::cout << "start the loop\n";
			
	 	std::shared_ptr<std::vector<int> > v(nullptr);
		while (true) {	
		 	auto chunk = div->getNextChunk();
			if (chunk == nullptr){
				break;
			}
			std::cout << chunk->size() <<std::endl;
			delete chunk;
		}
		
	}
	MPI_Finalize();



	return 0;
}
