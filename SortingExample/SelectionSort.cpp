#include "stdafx.h"
#include "SelectionSort.h"
#include "StaticOperations.h"


void SelectionSort::sort(StaticOperations::pIntVec theArray) {
	//std::sort(theArray->begin(), theArray->end());
	
	
	int lowPos = 0;

	for (unsigned i = 0; i < theArray->size(); i++) {

		lowPos = i;

		for (unsigned j = i + 1; j < theArray->size(); j++) {
			if (theArray->at(j) < theArray->at(lowPos))
				lowPos = j;
		}

		StaticOperations::swap(theArray, i, lowPos);
	}
	
}

