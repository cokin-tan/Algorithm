#include<iostream>

#include "HeapSort.h"

using namespace std;

int main(int argc, char** argv)
{
	int arr[] = { 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0 };
	int nLength = 14;

	CHeapSort<int> heapSort(arr, nLength);
	heapSort.BuildMaxHeap();
	heapSort.Print();
	heapSort.MaxHeapSort();
	heapSort.Print();

	heapSort.BuildMinHeap();
	heapSort.Print();
	heapSort.MinHeapSort();
	heapSort.Print();

	system("pause");
}