#pragma once

#include "stdafx.h"
#include <vector>

class InsertionSort 
{
	private:
		static void swap(std::vector<int>* theArray, int pos1, int pos2);
	public:
		InsertionSort() {};
		~InsertionSort() {};

		static void sort(std::vector<int>* theArray);
};
