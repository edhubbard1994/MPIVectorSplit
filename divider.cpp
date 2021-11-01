#include "divider.h"

#include <stdlib.h>
#include <time.h>
#include <iterator>

#define STOP_ITR this->chunks + 1

Divider::Divider(int prob_size, int chunks, int lowest, int highest) {
	this->current_chunk = 0;
	this->data.resize(prob_size);
	this->chunks = chunks;
	// initialize vector with random numbers
	srand(time(NULL));
	for (auto index = this->data.begin(); index !=this->data.end(); ++index) {
		*index = (rand() % highest) + lowest;
	}
	
}


std::vector<int> Divider::getNextChunk() {
	if (this->current_chunk >= STOP_ITR) {
		return std::vector<int>(0);
	}
	
	std::vector<int>::iterator start_itr = this->data.begin();
	std::vector<int>::iterator end_itr = this->data.begin();
	int size = this->data.size();
	int itr_start = this->current_chunk * (size / this->chunks);
	start_itr += itr_start;
	this->current_chunk ++;
	int itr_end =  this->current_chunk * (size / this->chunks) ;
	end_itr += itr_end;
	std::vector<int> ret_vector = std::vector<int>();
	if (this->current_chunk == STOP_ITR ) {
		 ret_vector.assign(start_itr, this->data.end());
		
	} else {
		ret_vector.assign(start_itr, end_itr);		
	}
	return ret_vector;
}


Divider::~Divider() { }
