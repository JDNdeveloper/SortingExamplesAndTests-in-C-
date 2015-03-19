#include "stdafx.h"
#include "QuickSort.h"
#include "StaticOperations.h"
#include <algorithm>

void QuickSort::sort(std::vector<int>* theArray) {
	//std::sort(theArray->begin(), theArray->end());

	quickSort(theArray, 0, theArray->size() - 1);
}

void QuickSort::quickSort(std::vector<int>* theArray, const int LEFT, const int RIGHT) {
	if (RIGHT - LEFT < 1) return;

	//int partitionPosition = partition(theArray, LEFT, RIGHT);
	int partitionPosition = partitionInPlace(theArray, LEFT, RIGHT);

	quickSort(theArray, LEFT, partitionPosition - 1);
	quickSort(theArray, partitionPosition + 1, RIGHT);
}

int QuickSort::partition(std::vector<int>* theArray, const int LEFT, const int RIGHT) {

	const int MIDDLE = (LEFT + RIGHT) / 2;
	int pivotValue = medianOfThree(theArray->at(LEFT), theArray->at(MIDDLE), theArray->at(RIGHT));
	int pivot = getPivotPositionFromValue(theArray, LEFT, MIDDLE, RIGHT, pivotValue);

	std::vector<int>* leftPartition = new std::vector<int>();
	std::vector<int>* rightPartition = new std::vector<int>();

	for (int i = LEFT; i <= RIGHT; i++) {
		if (i == pivot) {
			//do nothing
		}
		else if (theArray->at(i) < theArray->at(pivot)) {
			leftPartition->push_back(theArray->at(i));
		}
		else {
			rightPartition->push_back(theArray->at(i));
		}
	}

	//does deep copy of new array into the persistent array
	int pos = LEFT;
	for (unsigned i = 0; i < leftPartition->size(); i++) {
		(*theArray)[pos] = leftPartition->at(i);
		pos++;
	}

	pivot = pos;
	(*theArray)[pos] = pivotValue;
	pos++;

	for (unsigned i = 0; i < leftPartition->size(); i++) {
		(*theArray)[pos] = rightPartition->at(i);
		pos++;
	}

	return pivot;
}

int QuickSort::partitionInPlace(std::vector<int>* theArray, const int LEFT, const int RIGHT) {

	const int MIDDLE = (LEFT + RIGHT) / 2;
	int pivotValue = medianOfThree(theArray->at(LEFT), theArray->at(MIDDLE), theArray->at(RIGHT));
	int pivot = getPivotPositionFromValue(theArray, LEFT, MIDDLE, RIGHT, pivotValue);

	StaticOperations::swap(theArray, pivot, RIGHT);

	int storeIndex = LEFT;

	for (int i = LEFT; i < RIGHT; i++) {
		if (theArray->at(i) < pivotValue) {
			StaticOperations::swap(theArray, i, storeIndex);
			storeIndex++;
		}
	}

	StaticOperations::swap(theArray, storeIndex, RIGHT);

	return storeIndex;
}

int QuickSort::getPivotPositionFromValue(std::vector<int>* theArray, int pos1, int pos2, int pos3, int pivotValue) {
	if (theArray->at(pos1) == pivotValue) {
		return pos1;
	}
	else if (theArray->at(pos2) == pivotValue) {
		return pos2;
	}
	else {
		return pos3;
	}
}

int QuickSort::medianOfThree(const int num1, const int num2, const int num3) {
	int median = -1;

	if (num1 < num2) {
		if (num1 > num3) {
			median = num1;
		}
		else {
			if (num2 < num3) {
				median = num2;
			}
			else {
				median = num3;
			}
		}
	}
	else {
		if (num1 < num3) {
			median = num1;
		}
		else {
			if (num2 > num3) {
				median = num2;
			}
			else {
				median = num3;
			}
		}
	}

	return median;
}
