#include "Graf.h"

#include <algorithm>
#include <random>
#include <vector>
#include <set>

Graf::Graf(int vC, int eC, int minWeight, int maxWieght) : vertexCount(vC), edgeCount(std::min(eC, vertexCount* (vertexCount - 1) / 2))
{
	int freeEdge = 0;
	edgeContainer = new std::pair<int, int>[edgeCount];

	graf = new int* [vertexCount - 1];
	edgeHeap = new BinaryHeap<int, int>[vertexCount - 1];

	std::random_device dev;
	std::mt19937 gen(dev());
	std::uniform_real_distribution<> urd(minWeight, maxWieght);
	for (int i = 0; i < vertexCount - 1; i++)
	{
		graf[i] = new int[vertexCount - i - 1]{ 0 };
		for (int j = 0; j < vertexCount - 1 - i && freeEdge < edgeCount; j++)
		{
			int weight = static_cast<int>(urd(gen));
			weight = weight <= 0 ? 1 : weight;

			graf[i][j] = weight;
			edgeContainer[freeEdge] = { i,j };
			edgeHeap[i].insertElem({ j, weight });
			freeEdge++;
		}
	}
}

Graf::Graf(const Graf& copyGraf) : vertexCount(copyGraf.vertexCount), edgeCount(copyGraf.edgeCount)
{
	int freeEdge = 0;
	edgeContainer = new std::pair<int, int>[edgeCount];

	graf = new int* [vertexCount - 1];
	edgeHeap = new BinaryHeap<int, int>[vertexCount - 1];
	for (int i = 0; i < vertexCount - 1; i++)
	{
		graf[i] = new int[vertexCount - i - 1]{ 0 };
		for (int j = 0; j < vertexCount - 1 - i && freeEdge < edgeCount; j++)
		{
			graf[i][j] = copyGraf.graf[i][j];
			edgeContainer[freeEdge] = { i,j };
			edgeHeap[i].insertElem({ j, graf[i][j] });
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
	delete[] edgeHeap;
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
	if (vertexCount < 2 || edgeCount < vertexCount - 1)
	{
		return { {}, 0 };
	}

	std::vector<std::pair<int, int>> result;
	std::vector<std::vector<int>> groupTree;
	std::vector<int> numberGroupVertex(vertexCount, 0);
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
	return std::pair<std::vector<std::pair<int ,int>>, int> { result, sum };
}

void Graf::recoverEdgeHeap()
{
	delete[] edgeHeap;
	edgeHeap = new BinaryHeap<int, int>[vertexCount - 1];

	int freeEdge = 0;
	for (int i = 0; i < vertexCount - 1; i++)
	{
		for (int j = 0; j < vertexCount - 1 - i && freeEdge < edgeCount; j++)
		{
			edgeHeap[i].insertElem({ j, graf[i][j] });
			freeEdge++;
		}
	}
}

std::pair<std::vector<std::pair<int, int>>, int> Graf::PrimAlgorithm()
{
	if (vertexCount < 2 || edgeCount < vertexCount - 1)
	{
		return { {}, 0 };
	}

	std::pair<std::vector<std::pair<int, int>>, int> result;
	std::set<int> blockedVertex;

	std::pair<int, int> startElem = edgeHeap[0].deleteElem();
	result.first.push_back({ 0, startElem.first + 1 });
	result.second += startElem.second;
	blockedVertex.insert(0);
	blockedVertex.insert(startElem.first + 1);

	while (blockedVertex.size() != vertexCount)
	{
		BinaryHeap<std::pair<int, int>, int> temporaryHeap;

		for (auto it : blockedVertex)
		{
			if (it != vertexCount - 1 && edgeHeap[it].getSize() > 0)
			{
				std::pair<int, int> temporaryMinEdge = edgeHeap[it].seeElem();
				while (blockedVertex.find(temporaryMinEdge.first + it + 1) != blockedVertex.end() && edgeHeap[it].getSize() > 0)
				{
					edgeHeap[it].deleteElem();
					if (edgeHeap[it].getSize() > 0)
						temporaryMinEdge = edgeHeap[it].seeElem();
				}
				temporaryHeap.insertElem({ {it, temporaryMinEdge.first + it + 1}, temporaryMinEdge.second });
			}
		}

		std::pair<std::pair<int, int>, int> newElem = temporaryHeap.deleteElem();

		blockedVertex.insert(newElem.first.second);
		edgeHeap[newElem.first.first].deleteElem();
		result.first.push_back({ newElem.first.first, newElem.first.second });
		result.second += newElem.second;
	}
	return result;
}
