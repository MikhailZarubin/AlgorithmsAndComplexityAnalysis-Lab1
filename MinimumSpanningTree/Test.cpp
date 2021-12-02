#include "Graf.h"
#include "Heap.h"
#include "Timer.h"

#include <iostream>
#include <fstream>

int main()
{
	std::ofstream kruskalData("../KruskalData.txt");
	std::ofstream primData("../PrimData.txt");

	int vertexCount, maxEdgeCount, startEdgeCount, stepEdgeCount;

	std::cout << "VertexCount: ";
	std::cin >> vertexCount;
	std::cout << "MaxEdgeCount: ";
	std::cin >> maxEdgeCount;
	std::cout << "StartEdgeCount: ";
	std::cin >> startEdgeCount;
	std::cout << "StepEdgeCount: ";
	std::cin >> stepEdgeCount;

	kruskalData << vertexCount << ' ' << maxEdgeCount << ' ' << startEdgeCount << ' ' << stepEdgeCount;
	primData << vertexCount << ' ' << maxEdgeCount << ' ' << startEdgeCount << ' ' << stepEdgeCount;

	GrafTest::Timer timer;
	for (int i = startEdgeCount; i <= maxEdgeCount; i += stepEdgeCount)
	{
		Graf testGraf(vertexCount, i, -1000, 1000);

		timer.resetTimer();
		testGraf.KruskalAlgorithm();
		auto kruskalTimeWork = timer.getTime();

		timer.resetTimer();
		testGraf.PrimAlgorithm();
		auto primTimeWork = timer.getTime();

		kruskalData << '\n' << kruskalTimeWork;
		primData << '\n' << primTimeWork;
	}

	/*int vC, eC, minW, maxW;
	std::cout << "Vertex Count: ";
	std::cin >> vC;
	std::cout << "Edge Count: ";
	std::cin >> eC;
	std::cout << "Minimum Weight: ";
	std::cin >> minW;
	std::cout << "Maximum Weight: ";
	std::cin >> maxW;
	Graf graf(vC, eC, minW, maxW);
	if(vC < 10)
		for (int i = 0; i < vC; i++)
		{
			for (int j = 0; j < vC; j++)
				std::cout << graf.getWeightEdge(i, j) << ' ';
			std::cout << std::endl;
		}
	GrafTest::Timer timer;
	auto res = graf.PrimAlgorithm();
	double timeWorkingKruskal = timer.getTime();
	std::cout << "SUM= " << res.second << std::endl << "TIME= " << timeWorkingKruskal << "s";*/
}