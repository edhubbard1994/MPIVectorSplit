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
	
	auto itr = this->data->begin();
	int size = this->data->size();
	//TODO: get actual start and end  iterators 
	return new std::vector<int>(this->data->begin(), this->data->end());		

}


Divider::~Divider() {
	delete this->data;
}
