#include "stdafx.h"
#include "CppUnitTest.h"

#include "../SortingExample/SelectionSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingExampleTest
{
	TEST_CLASS(SelectionSortTest)
	{
	public:
		
		TEST_METHOD(TestSort)
		{
			Assert::AreEqual(SelectionSort::getThree(), 3);
		}

	};
}