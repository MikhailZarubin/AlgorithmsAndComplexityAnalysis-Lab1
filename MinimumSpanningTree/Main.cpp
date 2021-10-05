#include<iostream>
#include"Graf.h"

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
	GrafArray graf(vC, eC, minW, maxW);
	int scet{ 0 };
	for (int i = 0; i < vC; i++)
	{
		for (int j = 0; j < vC; j++)
		{
			std::cout << graf.getWeightEdge(i, j) << ' ';
			if (graf.getWeightEdge(i, j) != 0)
				scet++;
		}
		std::cout << std::endl;
	}
	std::cout << scet;
}