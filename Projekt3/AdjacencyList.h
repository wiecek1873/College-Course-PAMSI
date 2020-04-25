#pragma once
#include "GraphBase.h"

class AdjacencyList : public GraphBase
{
	struct Adjacency
	{
		int v;
		int weight;
	};
	using NeighboursList = std::vector<Adjacency>;

	std::vector<NeighboursList> _adjacencyList;

public:
	AdjacencyList(int numberOfVerticies);
	virtual void addEdge(int u, int v, int weight) override;
	virtual void deleteEdge(int u, int v) override;
	virtual std::vector<int> neighbours(int u) override;
	virtual int weight(int u, int v) override;
};

