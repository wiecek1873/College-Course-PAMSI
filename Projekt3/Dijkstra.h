#pragma once
#include "AdjacencyList.h"
#include "PriorityQueue.h"
#define infinity 2147483647
#define undefined -1



std::vector<int> dijkstra(GraphBase& graph, int source)
{
	std::vector<int> distance(graph._numberOfVerticies);
	std::vector<int> previous(graph._numberOfVerticies);
	PriorityQueue Q;
	distance[source] = 0;
	for (int i = 0; i < graph._numberOfVerticies; ++i)
	{
		if (i != source)
		{
			distance[i] = infinity;
			previous[i] = undefined;
		}
		Q.push(std::make_pair(distance[i], i));
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
	return distance, previous;
}