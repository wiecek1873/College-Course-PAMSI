#pragma once
#include <chrono>
#include "Dijkstra.h"

template <typename T>
class Tests
{
	double average(std::vector<double> vec);
public:
	double testRandomDijkstra(int numberOfVertices, float density);
	void testDijkstraTime();
};
template <typename T>
double Tests<T>::average(std::vector<double> vec)
{
	double output = 0;
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		output += *it;
	}
	return output / vec.size();
}

template <typename T>
double Tests<T>::testRandomDijkstra(int numberOfVertices, float density)
{
	T graph(numberOfVertices);
	graph.fillRandom(density);
	auto start = chrono::high_resolution_clock::now();

	dijkstra(graph, 0);

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return double(duration.count()) / 1000000;
}

template <typename T>
void Tests<T>::testDijkstraTime()
{
	int sizes[] = {10,50,100,500,1000};
	float densities[] = {0.25,0.5,0.75,1};
	for (int size : sizes)
	{
		for (float density : densities)
		{
			std::vector<double> temp;
			for (int i = 0; i < 100; i++)
			{
				temp.push_back(testRandomDijkstra(size,density));
			}
			std::cout << average(temp) << " ";
		}
		std::cout << std::endl;
	}
}