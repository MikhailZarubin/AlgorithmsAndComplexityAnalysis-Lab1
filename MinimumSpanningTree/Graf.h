#pragma once

#include "Heap.h"

#include <vector>

class Graf
{
	int** graf;
	int vertexCount, edgeCount;
	std::pair<int, int>* edgeContainer;
	BinaryHeap<int, int>* edgeHeap;

public:
	Graf(int vC = 0, int eC = 0, int minWeight = 0, int maxWeight = 0);
	Graf(const Graf& copyGraf);
	~Graf();
	int getWeightEdge(int vertexOne, int vertexTwo) const;
	std::pair <std::vector<std::pair<int, int>>, int> KruskalAlgorithm();
	std::pair <std::vector<std::pair<int, int>>, int> PrimAlgorithm();
	void recoverEdgeHeap();
};

