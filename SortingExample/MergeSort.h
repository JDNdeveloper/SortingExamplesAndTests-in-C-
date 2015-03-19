#pragma once

#include "stdafx.h"
#include <vector>

class MergeSort
{
	private:
		static void mergeSort(std::vector<int>* theArray, const int LEFT, const int RIGHT);
		static void merge(std::vector<int>* theArray, const int LEFT, const int RIGHT);
	public:
		MergeSort() {};
		~MergeSort() {};

		static void sort(std::vector<int>* theArray);
};

