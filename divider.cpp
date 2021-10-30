#include "divider.h"

#include <stdlib.h>
#include <time.h>
#include <iterator>

Divider::Divider(int prob_size, int chunks, int lowest, int highest) {
	this->current_chunk = 0;
	this->data = new std::vector<int>(prob_size);
	this->chunks = chunks;
	// initialize vector with random numbers
	srand(time(NULL));
	for (auto index = this->data->begin(); index !=this->data->end(); ++index) {
		*index = (rand() % highest) + lowest;
	}
	
}


std::vector<int> *Divider::getNextChunk() {
	if (this->current_chunk >= this->chunks) {
		return nullptr;
	}
	
	auto start_itr = this->data->begin();
	auto end_itr = this->data->begin();
	int size = this->data->size();
	int itr_start = this->current_chunk * (size / this->chunks);
	std::advance(start_itr, itr_start);
	this->current_chunk ++;
	int itr_end = this->current_chunk * (size / this->chunks);
	if (itr_end == size) {
		return new std::vector<int>(start_itr, this->data->end());
	}

	return new std::vector<int>(start_itr, end_itr);		

}


Divider::~Divider() {
	delete this->data;
}
