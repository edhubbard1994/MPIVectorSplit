#ifndef __divider_h
#define __divider_h

#include <vector>
#include <memory>
/**
 * @class Divider
 * A class to create and split vectors for message passing
 *
 * */
template <class T>
class Divider {
	int chunks; //number of partitions
	int current_chunk; //chunk index next to be processed
	std::vector<T> data;
public:
	Divider(int prob_size, int chunks, T lowest, T highest);
	~Divider();

	std::vector<T>  getNextChunk();

};





#endif
