#pragma once
#include "Dijkstra.h"

template <typename T>
class Tests
{
	double average(std::vector<double> vec);
	double testRandomDijkstra(int numberOfVertices, float density);
public:
	void testDijkstraTime();
	void saveRandomGraph(int numberOfVertices, float density, std::string name);
	void loadGraph(int numberOfVertices, std::string name);
	void saveRandomDijkstraOutput(int numberOfVertices, float density, std::string name);
};

template <typename T>
double Tests<T>::average(std::vector<double> vec)
{
	if (vec.size() == 0)
		throw std::exception("Size equal 0");

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
	return double(duration.count()) / 1000;
}

template <typename T>
void Tests<T>::testDijkstraTime()
{
	std::fstream file;
	if (typeid(T) == typeid(AdjacencyList))
		file.open("List.txt", std::ios::out);
	else
		file.open("Matrix.txt", std::ios::out);

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
				std::cout << "Stage: " << stage << "/20 " << "Done: "<< std::setw(2) << i << "%" << "\r" << std::flush;
			}
			++stage;
			file << average(temp) << " ";
		}
		file << std::endl;
	}
	file.close();
}

template <typename T>
void Tests<T>::saveRandomGraph(int numberOfVertices, float density, std::string name)
{
	T graph(numberOfVertices);
	graph.fillRandom(density);
	graph.saveToFile(name);
}

template <typename T>
void Tests<T>::loadGraph(int numberOfVertices,std::string name)
{
	T graph(numberOfVertices);
	graph.loadFromFile(name);
}

template <typename T>
void Tests<T>::saveRandomDijkstraOutput(int numberOfVertices, float density, std::string name)
{
	T graph(numberOfVertices);
	graph.fillRandom(density);
	dijkstra(graph, 0, name);
}