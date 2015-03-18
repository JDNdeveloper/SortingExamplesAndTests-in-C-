#include "stdafx.h"
#include "InsertionSort.h"
#include "StaticOperations.h"
#include <algorithm>

void InsertionSort::sort(std::vector<int>* theArray) {
	//std::sort(theArray->begin(), theArray->end());

	for (unsigned i = 1; i < theArray->size(); i++) {
		int current = i;
		int previous = i - 1;

		//order of the terms in this statement matter! otherwise array out of bounds error
		while (previous >= 0 && theArray->at(previous) > theArray->at(current)) {
			StaticOperations::swap(theArray, current, previous);
			previous--;
			current--;
		}

	}
}