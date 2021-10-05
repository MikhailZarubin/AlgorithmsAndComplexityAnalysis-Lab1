#include "Graf.h"
#include <algorithm>

GrafArray::GrafArray(int vC, int eC, int minWeight, int maxWieght) : vertexCount(vC), edgeCount(std::min(eC, vertexCount* (vertexCount - 1) / 2))
{
	int freeEdge = edgeCount;

	graf = new int* [vertexCount - 1];
	for (int i = 0; i < vertexCount - 1; i++)
	{
		graf[i] = new int[vertexCount - i - 1]{ 0 };
		for (int j = 0; j < vertexCount - 1 - i && freeEdge; j++)
		{
			graf[i][j] = static_cast<int>(minWeight + (maxWieght - minWeight) * (double)rand() / RAND_MAX);
			edgeContainer.push_back({ i, j });
			freeEdge--;
	    }
	}
	std::sort(edgeContainer.begin(), edgeContainer.end(), [this](std::pair<int, int> a, std::pair<int, int> b) { return graf[a.first][a.second] < graf[b.first][b.second]; });
}

GrafArray::~GrafArray()
{
	for (int i = 0; i < vertexCount - 1; i++)
	    delete[] graf[i];
	delete[] graf;
}

int GrafArray::getWeightEdge(int vertexOne, int vertexTwo) const
{
	if (vertexOne >= vertexCount || vertexTwo >= vertexCount)
		throw vertexCount;
	else if (vertexOne == vertexTwo)
		return 0;
	else if (vertexOne > vertexTwo)
		return graf[vertexTwo][--vertexOne - vertexTwo];
	else
		return graf[vertexOne][--vertexTwo - vertexOne];
}
