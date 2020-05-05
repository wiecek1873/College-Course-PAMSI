#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int numberOfVertices): _matrix(numberOfVertices,numberOfVertices)
{
	_numberOfVertices = numberOfVertices;
}

void AdjacencyMatrix::addEdge(int u, int v, int weight)
{
	_matrix(u, v) = weight;
}

void AdjacencyMatrix::deleteEdge(int u, int v)
{
	_matrix(u, v) = -1;
}

std::vector<int> AdjacencyMatrix::neighbours(int u)
{
	std::vector<int> neighboursVec;
	for (int i = 0; i < _numberOfVertices; ++i)
	{
		if (_matrix(u, i) != -1)
			neighboursVec.push_back(i);
	}
	return neighboursVec;
}

int AdjacencyMatrix::weight(int u, int v)
{
	return _matrix(u, v);
}
