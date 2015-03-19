#include "stdafx.h"
#include "MergeSort.h"
#include "StaticOperations.h"
#include <algorithm>

void MergeSort::sort(std::vector<int>* theArray) {
	//std::sort(theArray->begin(), theArray->end());

	mergeSort(theArray, 0 , theArray->size() - 1);
}

void MergeSort::mergeSort(std::vector<int>* theArray, const int LEFT, const int RIGHT) {
	if (RIGHT - LEFT < 1) return;

	const int MIDDLE = (LEFT + RIGHT) / 2;

	mergeSort(theArray, LEFT, MIDDLE);
	mergeSort(theArray, MIDDLE + 1, RIGHT);

	merge(theArray, LEFT, RIGHT);
}

void MergeSort::merge(std::vector<int>* theArray, const int LEFT, const int RIGHT) {
	const int MIDDLE = (LEFT + RIGHT) / 2;

	std::vector<int>* mergedArray = new std::vector<int>(*theArray);

	int leftPos = LEFT;
	int rightPos = MIDDLE + 1;

	int globalLocation = LEFT;

	while (leftPos <= MIDDLE && rightPos <= RIGHT) {
		if (theArray->at(leftPos) < theArray->at(rightPos)) {
			(*mergedArray)[globalLocation] = theArray->at(leftPos);
			leftPos++;
		}
		else {
			(*mergedArray)[globalLocation] = theArray->at(rightPos);
			rightPos++;
		}

		globalLocation++;
	}

	for (; leftPos <= MIDDLE; leftPos++) {
		(*mergedArray)[globalLocation] = theArray->at(leftPos);

		globalLocation++;
	}

	for (; rightPos <= RIGHT; rightPos++) {
		(*mergedArray)[globalLocation] = theArray->at(rightPos);

		globalLocation++;
	}

	//does deep copy of new array into the persistent array
	for (int i = LEFT; i <= RIGHT; i++) {
		(*theArray)[i] =  mergedArray->at(i);
	}
}
