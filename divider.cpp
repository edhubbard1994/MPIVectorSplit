#include "divider.h"
#include <stdlib.h>
#include <time.h>

Divider::Divider(int prob_size, int chunks, int lowest, int highest) {
	this.data = new std::vector(prob_size);
	srand(time(NULL));
	for (int index : this.data) {
		index = (rand() % highest) + lowest;
	}
	
}

Divider::~Divider() {
	delete this.data;
}
