#include "GraphBase.h"

void GraphBase::fillRandom(float density)
{
	for (int i = 0; i < _numberOfVertices; ++i)
	{
		for (int j = 0; j < _numberOfVertices; ++j)
		{
			if (i != j)
				addEdge(i, j, rand() % 100);
		}
	}

	int maxNumberOfEdges = (int)(_numberOfVertices * (_numberOfVertices - 1));
	int numberOfEdgesToDelete = maxNumberOfEdges - (int)(density * _numberOfVertices * (_numberOfVertices - 1));
	_numberOfEdges = maxNumberOfEdges - numberOfEdgesToDelete;
	while (numberOfEdgesToDelete > 0)
	{
		deleteEdge(rand() % _numberOfVertices, rand() % _numberOfVertices);
		--numberOfEdgesToDelete;
	}
}

void GraphBase::saveToFile(std::string name)
{
	std::ofstream file;
	file.open(name.c_str(), std::ios::out);

	file << _numberOfEdges << "\t" << _numberOfVertices << "\t" << "0" << std::endl;

	for (int i = 0; i < _numberOfVertices; ++i)
	{
		std::vector<int> neighboursVec = neighbours(i);
		for (auto it = neighboursVec.begin(); it < neighboursVec.end(); ++it)
		{
			file << i << "\t" << *it << "\t" << weight(i, *it) << std::endl;
		}
	}
	file.close();
}

void GraphBase::loadFromFile(std::string name)
{
	std::ifstream file;
	file.open(name.c_str(), std::ios::in);
	file >> _numberOfEdges;
	file >> _numberOfVertices;
	file.ignore(10, '\n');

	while (!file.eof())
	{
		int u;
		int v;
		int weight;
		file >> u;
		file >> v;
		file >> weight;
		if (!file.eof())
			addEdge(u, v, weight);
	}
	file.close();
}