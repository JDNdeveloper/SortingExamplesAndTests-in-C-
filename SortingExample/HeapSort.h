#pragma once

#include "stdafx.h"

#include "StaticOperations.h"

class HeapSort
{
public:
	HeapSort() {};
	~HeapSort() {};

	static void sort(StaticOperations::pIntVec theArray);
};

