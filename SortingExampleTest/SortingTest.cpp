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

		const SortType FIRST_SORT_TYPE = INSERTION;
		const SortType LAST_SORT_TYPE = SELECTION;

	public:
		
		TEST_METHOD(RunAllSorts)
		{
			for (int sortType = FIRST_SORT_TYPE; sortType != LAST_SORT_TYPE; sortType++)
			{
				runProperSort((SortType) sortType);
			}
		}

		void runProperSort(SortType sortType)
		{
			
		}

	};
}