#include "stdafx.h"
#include "BubbleSort.h"
#include "StaticOperations.h"
#include <algorithm>

void BubbleSort::sort(std::vector<int>* theArray) {
	//std::sort(theArray->begin(), theArray->end());

	for (unsigned i = 0; i < theArray->size(); i++) {
		for (unsigned j = 1; j < theArray->size() - i; j++) {
			if (theArray->at(j - 1) > theArray->at(j))
				StaticOperations::swap(theArray, j - 1, j);
		}
	}
}

