#pragma once

#include "stdafx.h"
#include <vector>

class SelectionSort
{
	private:
		static void swap(std::vector<int>* theArray, int pos1, int pos2);
	public:
		SelectionSort() {};
		~SelectionSort() {};

		static void sort(std::vector<int>* theArray);
};

