#pragma once

#include "stdafx.h"

#include "StaticOperations.h"

class MergeSort
{
	private:
		static void mergeSort(StaticOperations::pIntVec theArray, const int LEFT, const int RIGHT);
		static void merge(StaticOperations::pIntVec theArray, const int LEFT, const int RIGHT);
	public:
		MergeSort() {};
		~MergeSort() {};

		static void sort(StaticOperations::pIntVec theArray);
};

