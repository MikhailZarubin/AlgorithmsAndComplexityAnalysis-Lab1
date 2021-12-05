#include "Graf.h"
#include "Heap.h"
#include "Timer.h"

#include <iostream>
#include <fstream>

int main()
{
	int stratege = 1;

	while (stratege == 1 || stratege == 2)
	{
		std::cout << "Press 1 for test correct work algorithms\nPress 2 for time comparsion\nPress 0 for exit\n";
		std::cin >> stratege;

		if (stratege == 1)
		{
			int vertexCount, edgeCount, minWeight, maxWeight;
			std::cout << "Vertex Count: ";
			std::cin >> vertexCount;
			std::cout << "Edge Count: ";
			std::cin >> edgeCount;
			std::cout << "Minimum Weight: ";
			std::cin >> minWeight;
			std::cout << "Maximum Weight: ";
			std::cin >> maxWeight;

			Graf graf(vertexCount, edgeCount, minWeight, maxWeight);
			if (vertexCount < 10)
			{
				for (int i = 0; i < vertexCount; i++)
				{
					for (int j = 0; j < vertexCount; j++)
						std::cout << graf.getWeightEdge(i, j) << ' ';
					std::cout << std::endl;
				}
			}
			auto resKruskal = graf.KruskalAlgorithm();
			auto resPrim = graf.PrimAlgorithm();

			std::cout << "SumCalculateKruskal: " << resKruskal.second << "\nSumCalculatePrim: " << resPrim.second << '\n';
		}
		else if (stratege == 2)
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
		}
	}
}