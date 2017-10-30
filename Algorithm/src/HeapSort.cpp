#include<iostream>

using namespace std;

#define PARENT(i) (((i)-1)/2)
#define LEFT(i) (2*(i) + 1)
#define RIGHT(i) (2*(i) + 2)

typedef void(*pHealFunc)(int*, int, int);

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void MaxHeapify(int arr[], int nIndex, int nHeapSize)
{
	int nLeft = LEFT(nIndex);
	int nRight = RIGHT(nIndex);
	int nLargest = nIndex;
	if (nLeft < nHeapSize && arr[nLeft] > arr[nIndex])
	{
		nLargest = nLeft;
	}
	if (nRight < nHeapSize && arr[nRight] > arr[nLargest])
	{
		nLargest = nRight;
	}

	if (nLargest != nIndex)
	{
		Swap(arr[nIndex], arr[nLargest]);
		MaxHeapify(arr, nLargest, nHeapSize);
	}
}

void MinHeapify(int arr[], int nIndex, int nHeapSize)
{
	int nLeft = LEFT(nIndex);
	int nRight = RIGHT(nIndex);
	int nSmallest = nIndex;
	if (nLeft < nHeapSize && arr[nLeft] < arr[nIndex])
	{
		nSmallest = nLeft;
	}
	if (nRight < nHeapSize && arr[nRight] < arr[nSmallest])
	{
		nSmallest = nRight;
	}

	if (nSmallest != nIndex)
	{
		Swap(arr[nSmallest], arr[nIndex]);
		MinHeapify(arr, nSmallest, nHeapSize);
	}
}

void BuildHeap(int arr[], int nLength, pHealFunc func)
{
	for (int nIndex = nLength/2; nIndex >= 0; --nIndex)
	{
		func(arr, nIndex, nLength);
	}

	for (int nIndex = 0; nIndex < nLength; nIndex++)
	{
		std::cout << arr[nIndex] << "  ";
	}
	std::cout << std::endl;
}

void HeapSort(int arr[], int nLength, pHealFunc func)
{
	int nHeapSize = nLength;
	BuildHeap(arr, nLength, func);
	for (int nIndex = nLength-1; nIndex >= 0; --nIndex)
	{
		Swap(arr[nIndex], arr[0]);
		--nHeapSize;
		func(arr, 0, nHeapSize);
	}

	for (int nIndex = 0; nIndex < nLength; nIndex++)
	{
		std::cout << arr[nIndex] << "  ";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	int arr[] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
	int nLength = 14;

	//BuildHeap(arr, nLength, MaxHeapify);
	//BuildHeap(arr, nLength, MinHeapify);

	//HeapSort(arr, nLength, MaxHeapify);
	HeapSort(arr, nLength, MinHeapify);

	system("pause");

	return 0;
}