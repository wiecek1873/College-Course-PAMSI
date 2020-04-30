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
			distance[i] = 100000; //Nie ustawiam tutaj INT_MAX poniewa¿ mogê póŸniej wyjœæ za zakres int-a
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