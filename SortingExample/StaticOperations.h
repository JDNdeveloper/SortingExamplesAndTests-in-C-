#pragma once

#include "stdafx.h"
#include <vector>

namespace StaticOperations {	
		
		static void swap(std::vector<int>* theArray, int pos1, int pos2) {
			int num1 = (*theArray)[pos1];
			int num2 = (*theArray)[pos2];

			(*theArray)[pos1] = num2;
			(*theArray)[pos2] = num1;
		}
}