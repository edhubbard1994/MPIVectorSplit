#ifndef __divider_h
#define __divider_h

#include <vector>
/**
 * @class Divider
 * A class to create and split vectors for message passing
 *
 * */
class Divider {
	int chunck_size;
	std::vector *data;
	Divider(int prob_size, int chunks, int lowest, int highest);
	~Divider();
public:
	std::vector *getChunk();




};





#endif
