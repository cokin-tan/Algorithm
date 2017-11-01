#include<iostream>

#include "PriorityQueue.h"

using namespace std;

int main(int argc, char** argv)
{
	int arr[] = { 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0 };
	int nLength = 14;

	CPrirotyQueue<int> queue(arr, nLength, EType_Max);
	queue.HeapModifyKey(3, 28);
	while (!queue.IsEmpty())
	{
		std::cout << queue.HeapExtractFirstPriority() << " ";
	}
	std::cout << std::endl;

	system("pause");
}