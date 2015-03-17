#include "stdafx.h"
#include "InsertionSort.h"
#include <algorithm>

void InsertionSort::sort(std::vector<int>* theArray) {
	std::sort(theArray->begin(), theArray->end());
}