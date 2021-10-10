#pragma once

#include <iostream>

template <class dataType, class value>
class BinaryHeap
{
	std::pair<dataType, value>* heapContainer;
	int heapSize, currentSize;
	value sumValue;

	int getLevel(int index) const;
	int getExtremeLevel(int level, bool searchMaxElem) const;
	void recoverHeap(int index = -1);

public:
	BinaryHeap(int size = 10);
	BinaryHeap(const BinaryHeap& copyHeap);
	~BinaryHeap();
	void insertElem(std::pair<dataType, value> newElem);
	void deleteElem(int index);
	value getSum() const;
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
int BinaryHeap<dataType, value>::getExtremeLevel(int level, bool searchMaxElem) const
{
	if (level == 0)
		return 0;

	int left{ 0 };
	for (int i = 0; i < level; i++)
	{
		left += pow(2, i);
	}
	int right = left + pow(2, level), extremIndex = left;
	value extremValue = heapContainer[left].second;

	for (int i = left; i < std::min(right, currentSize - 1); i++)
	{
		if ((searchMaxElem && extremValue < heapContainer[i].second) || (!searchMaxElem && extremValue > heapContainer[i].second))
		{
			extremValue = heapContainer[i].second;
			extremIndex = i;
		}
	}

	return extremIndex;
}

template<class dataType, class value>
void BinaryHeap<dataType, value>::recoverHeap(int index)
{
	if (index >= currentSize)
		throw index;

	int maxLevel = getLevel(currentSize - 1);

	if (index != -1)
	{
		int currentLevel = getLevel(index);

		if (currentLevel < maxLevel)
		{
			int indexMinElemNextLevel = getExtremeLevel(++currentLevel, false);

			while (heapContainer[index].second > heapContainer[indexMinElemNextLevel].second && currentLevel <= maxLevel)
			{
				std::swap(heapContainer[index], heapContainer[indexMinElemNextLevel]);
				index = indexMinElemNextLevel;
				if (currentLevel < maxLevel)
					indexMinElemNextLevel = getExtremeLevel(++currentLevel, false);
			}
		}
	}

	else
	{
		if (maxLevel > 0)
		{
			int index = currentSize - 1, indexMaxElemLastLevel = getExtremeLevel(--maxLevel, true);

			while (heapContainer[index].second < heapContainer[indexMaxElemLastLevel].second && maxLevel >= 0)
			{
				std::swap(heapContainer[index], heapContainer[indexMaxElemLastLevel]);
				index = indexMaxElemLastLevel;
				if (maxLevel > 0)
					indexMaxElemLastLevel = getExtremeLevel(--maxLevel, true);
			}
		}
	}
}

template<class dataType, class value>
void BinaryHeap<dataType, value>::insertElem(std::pair<dataType, value> newElem)
{
	if (currentSize == heapSize)
		throw heapSize;

	heapContainer[currentSize++] = newElem;
	sumValue += newElem.second;

	recoverHeap();
}

template<class dataType, class value>
void BinaryHeap<dataType, value>::deleteElem(int index)
{
	if (index >= currentSize)
		throw index;

	sumValue -= heapContainer[index];
	heapContainer[index] = heapContainer[--currentSize];

	recoverHeap(index);
}

template<class dataType, class value>
value BinaryHeap<dataType, value>::getSum() const
{
	return sumValue;
}