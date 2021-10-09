#include "Heap.h"

template <class dataType, class value>
Heap<dataType, value>::Heap(int size, int child)
{
	if (size <= 0)
		throw size;

	heapSize = size;
	countChild = child;
	heapContainer = new std::pair<dataType, value>[heapSize];
}

template <class dataType, class value>
Heap<dataType, value>::Heap(const Heap<dataType, value>& copyHeap)
{
	heapSize = copyHeap.heapSize;
	heapContainer = new std::pair<dataType, value>[heapSize];
	for (int i = 0; i < heapSize; i++)
		heapContainer[i] = copyHeap.heapContainer[i];
}

template <class dataType, class value>
Heap<dataType, value>::~Heap()
{
	delete[] heapContainer;
}