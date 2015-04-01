#include "stdafx.h"
#include "HeapSort.h"
#include "StaticOperations.h"
#include <queue>


void HeapSort::sort(StaticOperations::pIntVec theArray) {
	//std::sort(theArray->begin(), theArray->end());

	std::priority_queue<int> heap;

	for (unsigned i = 0; i < theArray->size(); i++) {
		heap.push(theArray->at(i));
	}

	
	unsigned i = theArray->size() - 1; 
	while (!heap.empty()) {
		int max = heap.top();

		heap.pop();

		(*theArray)[i] = max;
		i--;
	}
	
	//Below code oddly doesn't work...no clue why not
	/*
	for (unsigned i = theArray->size() - 1; i >= 0; i--) {
		int max = heap.top();

		heap.pop();

		(*theArray)[i] = max;
	}
	*/
}
