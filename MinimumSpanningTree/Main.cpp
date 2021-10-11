#include "Graf.h"
#include "Heap.h"
#include "Timer.h"

#include <ctime>

int main()
{
	int vC, eC, minW, maxW;
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
	std::cout << "SUM= " << res.second << std::endl << "TIME= " << timeWorkingKruskal << "s";
}