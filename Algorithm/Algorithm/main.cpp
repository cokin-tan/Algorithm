#include<iostream>

#include "PriorityQueue.h"
#include "QuickSort.h"
#include "CountSort.h"

using namespace std;

int main(int argc, char** argv)
{
	//int arr[] = { 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0 };
	int arr[] = { 15, 13, 12, 11, 10, 9, 8, 7, 6, 5, 2, 1 };
	int nLength = 12;

	CCountSort sort(arr, 12, 15);
	
	system("pause");
}