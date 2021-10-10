#include "Graf.h"
#include "Heap.h"
#include "Timer.h"

#include <ctime>

int main()
{
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
	auto res = graf.KruskalAlgorithm();
	double timeWorkingKruskal = timer.getTime();
	std::cout << "SUM= " << res.second << std::endl << "TIME= " << timeWorkingKruskal << "s";*/
	BinaryHeap<int, int> test(10);
	for (int i = 0;i<10;i++)
	{
		int elem = 0 + (100) * (double)rand() / RAND_MAX;
		test.insertElem({ i,elem });
	}
	std::cout << test;
	for (int i = 5; i >= 0; i--)
	{
		test.deleteElem(i);
	}
	std::cout << std::endl << "NEW" << std::endl << test;
}