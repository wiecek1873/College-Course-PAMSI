#pragma once
#include "AdjacencyList.h"
class AdjacencyMatrix : public GraphBase
{
	class Matrix
	{
		std::vector<int> vector;
		int numberOfColumns;
	public:
		Matrix(int n, int m, int defaultValue = -1) : numberOfColumns {n} { vector.resize(n * m, defaultValue); }
		int& operator()(int x, int y) { return vector[x * numberOfColumns + y]; }
	};

	Matrix _matrix;
public:
	AdjacencyMatrix(int numberOfVertices);
	virtual void addEdge(int u, int v, int weight) override;
	virtual void deleteEdge(int u, int v) override;
	virtual std::vector<int> neighbours(int u) override;
	virtual int weight(int u, int v) override;
};

