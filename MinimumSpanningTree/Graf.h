#pragma once

#include <iostream>
#include <vector>

class GrafArray
{
	int** graf;
	int vertexCount, edgeCount;
	std::pair<int, int>* edgeContainer;

public:
	GrafArray(int vC = 0, int eC = 0, int minWeight = 0, int maxWeight = 0);
	GrafArray(const GrafArray& copyGraf);
	~GrafArray();
	int getWeightEdge(int vertexOne, int vertexTwo) const;
	std::pair < std::vector < std::pair<int, int>>, int > KruskalAlgorithm();
};

