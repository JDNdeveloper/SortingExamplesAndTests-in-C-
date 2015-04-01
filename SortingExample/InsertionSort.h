#pragma once

#include "stdafx.h"

#include "StaticOperations.h"

class InsertionSort 
{
	public:
		InsertionSort() {};
		~InsertionSort() {};

		static void sort(StaticOperations::pIntVec theArray);
};
