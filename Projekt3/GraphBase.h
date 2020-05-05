#pragma 
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

class GraphBase
{
public:
	int _numberOfVertices;
	int _numberOfEdges;

	void fillRandom(float density);
	void saveToFile(std::string name);
	void loadFromFile(std::string name);

	virtual void addEdge(int u, int v, int weight) = 0;
	virtual void deleteEdge(int u, int v) = 0;
	virtual std::vector<int> neighbours(int u) = 0;
	virtual int weight(int u, int v) = 0;
};

