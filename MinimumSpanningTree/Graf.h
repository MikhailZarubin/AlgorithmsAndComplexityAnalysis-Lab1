#pragma once

#include <iostream>
#include <vector>

class GrafArray
{
	int** graf;
	int vertexCount, edgeCount;
	std::vector<std::pair<int, int>> edgeContainer;
public:
	GrafArray(int vC = 0, int eC = 0, int minWeight = 0, int maxWeight = 0);
	~GrafArray();
	int getWeightEdge(int vertexOne, int vertexTwo) const;
};

