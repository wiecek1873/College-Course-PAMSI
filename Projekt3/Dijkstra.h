#pragma once
#include "AdjacencyMatrix.h"
#include "PriorityQueue.h"

std::pair<std::vector<int>,std::vector<int>> dijkstra(GraphBase& graph, int source)
{
	std::vector<int> distance(graph._numberOfVertices);
	std::vector<int> previous(graph._numberOfVertices);
	PriorityQueue Q;
	distance[source] = 0;
	for (int i = 0; i < graph._numberOfVertices; ++i)
	{
		if (i != source)
		{
			distance[i] = 1000000; //Nie ustawiam tutaj INT_MAX poniewa¿ mogê póŸniej wyjœæ za zakres int-a
			previous[i] = -1;
		}
		Q.push(std::make_pair(distance[i], i)); //First is distance. Second is vertex index
	}
	while (!Q.empty())
	{
		std::pair<int, int> u = Q.pop();
		std::vector<int>neighbours = graph.neighbours(u.second);
		for (auto v = neighbours.begin(); v != neighbours.end(); ++v)
		{
			int alt = distance[u.second] + graph.weight(u.second, *v);
			if (alt < distance[*v])
			{
				distance[*v] = alt;
				previous[*v] = u.second;
				Q.decreasePriority(*v, alt);
			}
		}
	}
	return make_pair(distance,previous);
}

//Ta metoda jest zrobiona troche na odwrot ale w wymaganiach projektu
//sciezka miala byc od zrodla do punktu dlatego tak wyszlo
void dijkstra(GraphBase& graph, int source, std::string name)
{
	std::pair<std::vector<int>, std::vector<int>> dijkstraOutput = dijkstra(graph, source); //First is distance, second is previous
	std::ofstream file;
	file.open(name.c_str(), std::ios::out);

	for (unsigned int i = 0; i < dijkstraOutput.first.size(); ++i)
	{
		file << dijkstraOutput.first[i] << "\t";
		std::vector<int> path;
		path.push_back(i);
		int position = dijkstraOutput.second[i];

		while (position != source)
		{
			path.push_back(position);
			position = dijkstraOutput.second[position];
		}
		path.push_back(source);

		std::reverse(path.begin(), path.end());
		for (auto it = path.begin(); it != path.end(); ++it)
		{
			file << *it;
			if (it != path.end() - 1)
				file << "->";
		}
		file << std::endl;
	}
	file.close();
}