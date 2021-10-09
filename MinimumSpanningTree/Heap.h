#pragma once

#include <iostream>

template <class dataType, class value>
class Heap
{
	std::pair<dataType, value>* heapContainer;
	int heapSize, countChild;

public:
	Heap(int size = 10, int child = 2);
	Heap(const Heap& copyHeap);
	~Heap();
};

