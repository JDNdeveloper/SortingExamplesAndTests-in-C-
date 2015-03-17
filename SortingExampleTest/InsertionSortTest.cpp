#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>

#include "../SortingExample/InsertionSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingExampleTest
{		
	TEST_CLASS(InsertionSortTest)
	{
	public:
		
		TEST_METHOD(TestSort)
		{
			int* a1 = new int[2];
			int* a2 = InsertionSort::sort(a1);
			Assert::IsTrue(a2[0] == a2[1]);
		}

	};
}