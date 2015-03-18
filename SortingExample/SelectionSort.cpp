#include "stdafx.h"
#include "SelectionSort.h"
#include <algorithm>

void SelectionSort::sort(std::vector<int>* theArray) {
	//std::sort(theArray->begin(), theArray->end());
	
	
	int lowPos = 0;

	for (unsigned i = 0; i < theArray->size(); i++) {

		lowPos = i;

		for (unsigned j = i + 1; j < theArray->size(); j++) {
			if (theArray->at(j) < theArray->at(lowPos))
				lowPos = j;
		}

		swap(theArray, i, lowPos);
	}
	
}

void SelectionSort::swap(std::vector<int>* theArray, int pos1, int pos2) {
	int num1 = (*theArray)[pos1];
	int num2 = (*theArray)[pos2];

	(*theArray)[pos1] = num2;
	(*theArray)[pos2] = num1;
}
