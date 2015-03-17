// SortingExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "InsertionSort.h"
#include "SelectionSort.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Hello World!" << endl;
	std::vector<int>* theArray = new std::vector<int>(1);
	InsertionSort::sort(theArray);
	cout << theArray->at(0) << endl;

	SelectionSort::sort(theArray);
	cout << theArray->at(0) << endl;
	return 0;
}

