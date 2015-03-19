#pragma once

#include "stdafx.h"
#include <vector>

class QuickSort
{
	private:
		static void quickSort(std::vector<int>* theArray, const int LEFT, const int RIGHT);
		static int partition(std::vector<int>* theArray, const int LEFT, const int RIGHT);
		static int partitionInPlace(std::vector<int>* theArray, const int LEFT, const int RIGHT);
		static int getPivotPositionFromValue(std::vector<int>* theArray, int pos1, int pos2, int pos3, int pivotValue);
		static int QuickSort::medianOfThree(const int num1, const int num2, const int num3);
	public:
		QuickSort() {};
		~QuickSort() {};

		static void sort(std::vector<int>* theArray);
};

