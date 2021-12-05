#pragma once

#include <iostream>

template <class dataType, class value>
class BinaryHeap
{
	std::pair<dataType, value>* heapContainer;
	int heapSize, currentSize;
	value sumValue;

	int getLevel(int index) const;
	void siftUp(int index);
	void siftDown(int index);
	void allocation();

public:
	BinaryHeap(int size = 100);
	BinaryHeap(const BinaryHeap& copyHeap);
	~BinaryHeap();
	void insertElem(std::pair<dataType, value> newElem);
	std::pair<dataType, value> deleteElem(int index);
	std::pair<dataType, value> getHead();
	int getSize() const;
	friend std::ostream& operator<< (std::ostream& out, const BinaryHeap<dataType, value>& heap)
	{
		int lastLevel = 0;
		for (int i = 0; i < heap.currentSize; i++)
		{
			if (heap.getLevel(i) != lastLevel)
			{
				lastLevel = heap.getLevel(i);
				out << std::endl;
			}
			out << heap.heapContainer[i].first << ',' << heap.heapContainer[i].second << ' ';
		}

		return out;
	}
};

template <class dataType, class value>
BinaryHeap<dataType, value>::BinaryHeap(int size)
{
	if (size <= 0)
		throw size;

	heapSize = size;
	currentSize = 0;
	sumValue = 0;
	heapContainer = new std::pair<dataType, value>[heapSize];
}

template <class dataType, class value>
BinaryHeap<dataType, value>::BinaryHeap(const BinaryHeap<dataType, value>& copyHeap)
{
	heapSize = copyHeap.heapSize;
	currentSize = copyHeap.currentSize;
	sumValue = copyHeap.sumValue;

	heapContainer = new std::pair<dataType, value>[heapSize];
	for (int i = 0; i < currentSize; i++)
		heapContainer[i] = copyHeap.heapContainer[i];
}

template <class dataType, class value>
BinaryHeap<dataType, value>::~BinaryHeap()
{
	delete[] heapContainer;
}

template <class dataType, class value>
int BinaryHeap<dataType, value>::getLevel(int index) const
{
	int level{ 0 };

	for (int i = 1; i <= index; i += pow(2, level))
		level++;

	return level;
}

template<class dataType, class value>
void BinaryHeap<dataType, value>::siftDown(int index)
{
	while (2 * index + 1 < currentSize)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (right >= currentSize)
			right = left;

		if (heapContainer[left].second < heapContainer[index].second || heapContainer[right].second < heapContainer[index].second)
		{
			int newIndex = heapContainer[left].second < heapContainer[index].second ? left : right;
			std::swap(heapContainer[newIndex], heapContainer[index]);
			index = newIndex;
		}
		else
			break;
	}
}

template<class dataType, class value>
void BinaryHeap<dataType, value>::siftUp(int index)
{
	while (heapContainer[index].second < heapContainer[(index - 1) / 2].second)
	{
		std::swap(heapContainer[index], heapContainer[(index - 1) / 2]);
		index = (index - 1) / 2;

		if (index == 0)
			break;
	}
}

template<class dataType, class value>
void BinaryHeap<dataType, value>::insertElem(std::pair<dataType, value> newElem)
{
	if (currentSize == heapSize)
		allocation();

	heapContainer[currentSize++] = newElem;
	sumValue += newElem.second;

	siftUp(currentSize - 1);
}

template<class dataType, class value>
std::pair<dataType, value> BinaryHeap<dataType, value>::deleteElem(int index)
{
	if (index >= currentSize)
		throw index;

	sumValue -= heapContainer[index].second;

	std::pair<dataType, value> deletingElem = heapContainer[index];
	heapContainer[index] = heapContainer[--currentSize];

	if (currentSize > 1)
		siftDown(index);

	return deletingElem;
}

template<class dataType, class value>
int BinaryHeap<dataType, value>::getSize() const
{
	return currentSize;
}

template<class dataType, class value>
std::pair<dataType, value> BinaryHeap<dataType,value>::getHead()
{
	if (currentSize == 0)
		throw 0;

	return heapContainer[0];
}

template<class dataType, class value>
void BinaryHeap<dataType, value>::allocation()
{
	std::pair<dataType, value>* newHeap = new std::pair<dataType, value>[heapSize * 2];

	for (int i = 0; i < heapSize; i++)
		newHeap[i] = heapContainer[i];

	heapSize *= 2;
	delete[] heapContainer;
	heapContainer = newHeap;
}