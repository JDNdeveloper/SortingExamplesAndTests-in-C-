#include "stdafx.h"
#include "CppUnitTest.h"

#include "../SortingExample/InsertionSort.h"
#include "../SortingExample/SelectionSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingExampleTest
{
	TEST_CLASS(SortingTest)
	{
	private:
		enum SortType
		{
			INSERTION, SELECTION
		};
	public:
		
		TEST_METHOD(InsertionSortTest)
		{
			// TODO: InsertionSort Code here
		}

		TEST_METHOD(SelectionSortTest)
		{
			// TODO: SelectionSort Code here
		}

	};
}