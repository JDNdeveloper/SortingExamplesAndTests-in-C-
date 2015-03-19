#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>

#include "../SortingExample/SelectionSort.h"
#include "../SortingExample/InsertionSort.h"
#include "../SortingExample/BubbleSort.h"
#include "../SortingExample/HeapSort.h"
#include "../SortingExample/MergeSort.h"
#include "../SortingExample/QuickSort.h"
#include "SupportFile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef std::vector<int>* pIntVec;

namespace SortingExampleTest
{
	TEST_CLASS(SortingTest)
	{
	private:
		enum SortType
		{
			INSERTION, BUBBLE, HEAP, MERGE, QUICK, SELECTION
		};

		const SortType FIRST_SORT_TYPE = INSERTION;
		const SortType LAST_SORT_TYPE = SELECTION;

		const int NUMBER_OF_TEST_INPUTS = 10;
		const int NUMBER_OF_ARRAY_RANDOMIZES = 10;

		const int SIZE = 100;
		const int LOWER_BOUND = -10000;
		const int UPPER_BOUND = 10000;

		bool runProperSort(SortType sortType, pIntVec theArray)
		{
			switch (sortType)
			{
			case INSERTION:
				InsertionSort::sort(theArray);
				break;
			case BUBBLE:
				BubbleSort::sort(theArray);
				break;
			case HEAP:
				HeapSort::sort(theArray);
				break;
			case MERGE:
				MergeSort::sort(theArray);
				break;
			case QUICK:
				QuickSort::sort(theArray);
				break;
			case SELECTION:
				SelectionSort::sort(theArray);
				break;
			default:
				return false;
			}

			return true;
		}

		void generateArray(pIntVec theArray, int size) {
			//below line wiped out all data and made size 0

			theArray->clear();

			for (int i = 0; i < size; i++) {
				int randomValue = getRandInt(LOWER_BOUND, UPPER_BOUND);

				theArray->push_back(randomValue);
			}

			/*
			for (unsigned i = 0; i < theArray->size(); i++) {
			int randomValue = getRandInt(LOWER_BOUND, UPPER_BOUND);

			(*theArray)[i] = randomValue;
			}
			*/
		}

		void randomizeArray(pIntVec theArray) {

			//Logger::WriteMessage("Here 1\n");

			for (unsigned i = 0; i < theArray->size() - 1; i++) {
				//Logger::WriteMessage("Here 2\n");

				int randomLocation = getRandInt(i + 1, theArray->size() - 1);

				//Logger::WriteMessage("Here 3\n");

				swapArrayPositions(theArray, i, randomLocation);

				//Logger::WriteMessage("Here 4\n");
			}
		}

		void swapArrayPositions(pIntVec theArray, int pos1, int pos2) {
			int num1 = (*theArray)[pos1];
			int num2 = (*theArray)[pos2];

			(*theArray)[pos1] = num2;
			(*theArray)[pos2] = num1;
		}

		int getRandInt(int min, int max) {
			return min + (rand() % (int)(max - min + 1));
		}

	public:
		
		TEST_METHOD(TestSorts)
		{
			unsigned int time_ui = unsigned int(time(NULL));
			srand(time_ui);

			pIntVec theArray = new std::vector<int>(SIZE);

			for (int i = 0; i < NUMBER_OF_TEST_INPUTS; i++)
			{
				generateArray(theArray, SIZE);

				pIntVec perfectArray = new std::vector<int>(*theArray);

				std::sort(perfectArray->begin(), perfectArray->end());

				for (int j = 0; j < NUMBER_OF_ARRAY_RANDOMIZES; j++)
				{
					randomizeArray(theArray);

					runAllSorts(perfectArray, theArray);
				}


			}
		}

		void runAllSorts(pIntVec perfectArray, pIntVec theArray) {
			for (int sortType = FIRST_SORT_TYPE; sortType <= LAST_SORT_TYPE; sortType++)
			{
				//Logger::WriteMessage("Inside of sort loop\n");

				pIntVec tempArray = new std::vector<int>(*theArray);

				runProperSort((SortType)sortType, tempArray);

				Assert::AreEqual(*perfectArray, *tempArray);
			}
		}

		TEST_METHOD(TestGenerateArray) {
			pIntVec v1 = new std::vector<int>(5);

			generateArray(v1, 5);
			
			Logger::WriteMessage("Test Generate Array:\n");

			for (std::vector<int>::iterator it = v1->begin(); it != v1->end(); ++it) {
				char buffer[33];
				Logger::WriteMessage(_itoa(*it, buffer, 10));
				Logger::WriteMessage("\n");
			}

			Logger::WriteMessage("End of Test Generate Array\n");
		}

		TEST_METHOD(TestRandomizeArray) {
			pIntVec v1 = new std::vector<int>();

			Logger::WriteMessage("Test Randomize Array:\n");

			for (unsigned i = 0; i < 10; i++) {
				v1->push_back(i);
			}

			for (std::vector<int>::iterator it = v1->begin(); it != v1->end(); ++it) {
				char buffer[33];
				Logger::WriteMessage(_itoa(*it, buffer, 10));
				Logger::WriteMessage("\n");
			}

			Logger::WriteMessage("Finished loading vector\n");

			randomizeArray(v1);

			Logger::WriteMessage("Finished randomizing vector\n");

			for (std::vector<int>::iterator it = v1->begin(); it != v1->end(); ++it) {
				char buffer[33];
				Logger::WriteMessage(_itoa(*it, buffer, 10));
				Logger::WriteMessage("\n");
			}

			Logger::WriteMessage("End of Test Randomize Array\n");
		}

		/*
		TEST_METHOD(TestIteratorLoop) {
			pIntVec v = new std::vector<int>(5);

			int i = 0;
			for (std::vector<int>::iterator it = v->begin(); it != v->end(); ++it) {
				auto newIterator(it);
				char buffer[33];
				Logger::WriteMessage(itoa(i, buffer, 10));
				v->insert(newIterator, i);
				i++;
			}
		}
		*/

	};
}