#pragma 
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

class GraphBase
{
public:
	int _numberOfVertices;
	virtual void addEdge(int u, int v, int weight) = 0;
	virtual void deleteEdge(int u, int v) = 0;
	virtual std::vector<int> neighbours(int u) = 0;
	virtual int weight(int u, int v) = 0;

	void fillRandom(float density)
	{
		for (int i = 0; i < _numberOfVertices; ++i)
		{
			for (int j = 0; j < _numberOfVertices; ++j)
			{
				if (i != j)
					addEdge(i, j, rand() % 100);
			}
		}
		
		int numberOfEdges = (int)( _numberOfVertices * (_numberOfVertices - 1));
		int numberOfEdgesToDelete = numberOfEdges - (int)(density * _numberOfVertices * (_numberOfVertices - 1));
		while (numberOfEdgesToDelete > 0)
		{
			deleteEdge(rand() % _numberOfVertices, rand() % _numberOfVertices);
			--numberOfEdgesToDelete;
		}
	}
};

