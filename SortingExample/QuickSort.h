#pragma once

#include "stdafx.h"

#include "StaticOperations.h"

class QuickSort
{
	private:
		static void quickSort(StaticOperations::pIntVec theArray, const int LEFT, const int RIGHT);
		static int partition(StaticOperations::pIntVec theArray, const int LEFT, const int RIGHT);
		static int partitionInPlace(StaticOperations::pIntVec theArray, const int LEFT, const int RIGHT);
		static int getPivotPositionFromValue(StaticOperations::pIntVec theArray, int pos1, int pos2, int pos3, int pivotValue);
		static int QuickSort::medianOfThree(const int num1, const int num2, const int num3);
	public:
		QuickSort() {};
		~QuickSort() {};

		static void sort(StaticOperations::pIntVec theArray);
};

