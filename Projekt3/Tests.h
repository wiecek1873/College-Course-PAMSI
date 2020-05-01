#pragma once
#include <chrono>
#include <fstream>
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
	std::ofstream file;
	if (typeid(T) == typeid(AdjacencyList))
		file.open("List.txt",ios::out);
	else
		file.open("Matrix.txt",ios::out);

	int stage = 1; //Display of progression
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
				std::cout << "Stage: " << stage << "/20 " << "Done: " << i << "%" << "\r" << std::flush;
			}
			++stage;
			file << average(temp) << " ";
		}
		file << std::endl;
	}
	file.close();
}