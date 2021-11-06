#include "divider.h"

#include <stdlib.h>
#include <time.h>
#include <iterator>

#define STOP_ITR this->chunks + 1

template<class T>
Divider<T>::Divider(int prob_size, int chunks, T lowest, T highest) {
	this->current_chunk = 0;
	this->data.resize(prob_size);
	this->chunks = chunks;
	// initialize vector with random numbers
	srand(time(NULL));
	for (auto index = this->data.begin(); index !=this->data.end(); ++index) {
		*index = (rand() % highest) + lowest;
	}
	
}

template<class T>
std::vector<T> Divider<T>::getNextChunk() {
	if (this->current_chunk >= STOP_ITR) {
		return std::vector<T>(0);
	}
	
	typename std::vector<T>::iterator start_itr = this->data.begin();
	typename std::vector<T>::iterator end_itr = this->data.begin();
	int size = this->data.size();
	int itr_start = this->current_chunk * (size / this->chunks);
	start_itr += itr_start;
	this->current_chunk ++;
	int itr_end =  this->current_chunk * (size / this->chunks) ;
	end_itr += itr_end;
	typename std::vector<T> ret_vector = std::vector<T>();
	if (this->current_chunk == STOP_ITR ) {
		 ret_vector.assign(start_itr, this->data.end());
		
	} else {
		ret_vector.assign(start_itr, end_itr);		
	}
	return ret_vector;
}


template<class T>
Divider<T>::~Divider() { }

template class Divider<int>;
template class Divider<long>;
template class Divider<unsigned int>;
template class Divider<unsigned long>;
template class Divider<long long>;
template class Divider<short>;
