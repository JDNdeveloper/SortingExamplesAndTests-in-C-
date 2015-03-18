#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <iostream>

#include "../SortingExample/SelectionSort.h"
#include "../SortingExample/InsertionSort.h"
#include "SupportFile.h"

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

		const int NUMBER_OF_TEST_INPUTS = 100;
		const int NUMBER_OF_ARRAY_RANDOMIZES = 50;

		const int SIZE = 100;
		const int LOWER_BOUND = -100000;
		const int UPPER_BOUND = 100000;

		bool runProperSort(SortType sortType, std::vector<int>* theArray)
		{
			switch (sortType)
			{
			case INSERTION:
				InsertionSort::sort(theArray);
				break;
			case SELECTION:
				SelectionSort::sort(theArray);
				break;
			default:
				return false;
			}

			return true;
		}

		void generateArray(std::vector<int>* theArray, int size) {
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

		void randomizeArray(std::vector<int>* theArray) {

			//Logger::WriteMessage("Here 1\n");

			for (unsigned i = 0; i < theArray->size() - 1; i++) {
				//Logger::WriteMessage("Here 2\n");

				int randomLocation = getRandInt(i + 1, theArray->size() - 1);

				//Logger::WriteMessage("Here 3\n");

				swapArrayPositions(theArray, i, randomLocation);

				//Logger::WriteMessage("Here 4\n");
			}
		}

		void swapArrayPositions(std::vector<int>* theArray, int pos1, int pos2) {
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
			std::vector<int>* theArray = new std::vector<int>(SIZE);

			for (int i = 0; i < NUMBER_OF_TEST_INPUTS; i++)
			{
				generateArray(theArray, SIZE);

				std::vector<int>* perfectArray = new std::vector<int>(*theArray);

				std::sort(perfectArray->begin(), perfectArray->end());

				for (int j = 0; j < NUMBER_OF_ARRAY_RANDOMIZES; j++)
				{
					randomizeArray(theArray);

					runAllSorts(perfectArray, theArray);
				}


			}
		}

		void runAllSorts(std::vector<int>* perfectArray, std::vector<int>* theArray) {
			for (int sortType = FIRST_SORT_TYPE; sortType <= LAST_SORT_TYPE; sortType++)
			{
				//Logger::WriteMessage("Inside of sort loop\n");

				runProperSort((SortType)sortType, theArray);

				Assert::AreEqual(*perfectArray, *theArray);
			}
		}

		TEST_METHOD(TestGenerateArray) {
			std::vector<int>* v1 = new std::vector<int>(5);

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
			std::vector<int>* v1 = new std::vector<int>();

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
			std::vector<int>* v = new std::vector<int>(5);

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