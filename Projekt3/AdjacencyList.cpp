#include "AdjacencyList.h"
AdjacencyList::AdjacencyList(int numberOfVertices)
{ 
	_adjacencyList.resize(numberOfVertices);
	_numberOfVertices = numberOfVertices; 
}

void AdjacencyList::addEdge(int u, int v, int weight)
{
	Adjacency adj{ v,weight };
	_adjacencyList[u].push_back(adj);
}

void AdjacencyList::deleteEdge(int u, int v)
{
	NeighboursList& neighboursList = _adjacencyList[u];
	std::remove_if(neighboursList.begin(), neighboursList.end(), [v](const Adjacency& adj) {
		return adj.v == v;});
}

std::vector<int> AdjacencyList::neighbours(int u)
{
	std::vector<int> neighboursVec;
	NeighboursList& neighboursList = _adjacencyList[u];
	std::transform(neighboursList.begin(), neighboursList.end(), std::back_inserter(neighboursVec),
                [](const Adjacency& adj) { return adj.v; });
	return neighboursVec;
}

int AdjacencyList::weight(int u, int v)
{
	NeighboursList& neighboursList = _adjacencyList[u];
	auto it = std::find_if(neighboursList.begin(), neighboursList.end(), [v](const Adjacency& adj) { return v == adj.v; });

	if(neighboursList.end() == it)
	throw std::exception("Not found (u,v) edge");

	return it->weight;
}