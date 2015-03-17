// SortingExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "InsertionSort.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Hello World!" << endl;
	int a2[3];
	int* a1 = InsertionSort::sort(a2);
	cout << a1[1] << endl;
	return 0;
}

