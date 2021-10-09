#include "Graf.h"

#include <algorithm>
#include <vector>

Graf::Graf(int vC, int eC, int minWeight, int maxWieght) : vertexCount(vC), edgeCount(std::min(eC, vertexCount* (vertexCount - 1) / 2))
{
	int freeEdge = 0;
	edgeContainer = new std::pair<int, int>[edgeCount];

	graf = new int* [vertexCount - 1];
	for (int i = 0; i < vertexCount - 1; i++)
	{
		graf[i] = new int[vertexCount - i - 1]{ 0 };
		for (int j = 0; j < vertexCount - 1 - i && freeEdge < edgeCount; j++)
		{
			graf[i][j] = static_cast<int>(minWeight + (maxWieght - minWeight) * (double)rand() / RAND_MAX);
			edgeContainer[freeEdge] = { i,j };
			freeEdge++;
		}
	}
}

Graf::Graf(const Graf& copyGraf) : vertexCount(copyGraf.vertexCount), edgeCount(copyGraf.edgeCount)
{
	int freeEdge = 0;
	edgeContainer = new std::pair<int, int>[edgeCount];

	graf = new int* [vertexCount - 1];
	for (int i = 0; i < vertexCount - 1; i++)
	{
		graf[i] = new int[vertexCount - i - 1]{ 0 };
		for (int j = 0; j < vertexCount - 1 - i && freeEdge < edgeCount; j++)
		{
			graf[i][j] = copyGraf.graf[i][j];
			edgeContainer[freeEdge] = { i,j };
			freeEdge++;
		}
	}
}

Graf::~Graf()
{
	for (int i = 0; i < vertexCount - 1; i++)
		delete[] graf[i];
	delete[] graf;
	delete[] edgeContainer;
}

int Graf::getWeightEdge(int vertexOne, int vertexTwo) const
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

std::pair<std::vector<std::pair<int, int>>, int> Graf::KruskalAlgorithm()
{
	std::vector<std::pair<int, int>> result;
	std::vector<std::vector<int>> groupTree;
	int* numberGroupVertex = new int [vertexCount] { 0 };
	int sum{ 0 };
	int lastGroup{ 0 }, occupedVertex{ 1 };

	std::sort(edgeContainer, edgeContainer + edgeCount, [&](std::pair<int, int> a, std::pair<int, int> b) { return graf[a.first][a.second] < graf[b.first][b.second]; });

	for (int i = 0; i < edgeCount && occupedVertex < vertexCount; i++)
	{
		int firstVertex = edgeContainer[i].first, twoVertex = edgeContainer[i].second + 1 + firstVertex;

		if (numberGroupVertex[firstVertex] != numberGroupVertex[twoVertex] || (numberGroupVertex[firstVertex] == 0 || numberGroupVertex[twoVertex] == 0))
		{
			result.push_back(edgeContainer[i]);
			if (numberGroupVertex[firstVertex] == 0 && numberGroupVertex[twoVertex] == 0)
			{
				numberGroupVertex[twoVertex] = ++lastGroup;
				numberGroupVertex[firstVertex] = lastGroup;
				groupTree.push_back(std::vector<int>{ firstVertex, twoVertex });
			}
			else
				if (numberGroupVertex[firstVertex] == 0)
				{
					numberGroupVertex[firstVertex] = numberGroupVertex[twoVertex];
					groupTree[numberGroupVertex[twoVertex] - 1].push_back(firstVertex);
				}
				else if (numberGroupVertex[twoVertex] == 0)
				{
					numberGroupVertex[twoVertex] = numberGroupVertex[firstVertex];
					groupTree[numberGroupVertex[firstVertex] - 1].push_back(twoVertex);
				}
				else {
					if (groupTree[numberGroupVertex[firstVertex] - 1].size() < groupTree[numberGroupVertex[twoVertex] - 1].size())
					{
						int newGroup = numberGroupVertex[*(groupTree[numberGroupVertex[twoVertex] - 1].begin())];
						for (const auto& vert : groupTree[numberGroupVertex[firstVertex] - 1]) {
							groupTree[numberGroupVertex[twoVertex] - 1].push_back(vert);
							numberGroupVertex[vert] = newGroup;
						}
					}
					else
					{
						int newGroup = numberGroupVertex[*(groupTree[numberGroupVertex[firstVertex] - 1].begin())];
						for (const auto& vert : groupTree[numberGroupVertex[twoVertex] - 1])
						{
							groupTree[numberGroupVertex[firstVertex] - 1].push_back(vert);
							numberGroupVertex[vert] = newGroup;
						}
					}
				}
			sum += graf[firstVertex][edgeContainer[i].second];
			occupedVertex++;
		}
	}
	delete[] numberGroupVertex;
	return std::pair<std::vector<std::pair<int, int>>, int> { result, sum };
}