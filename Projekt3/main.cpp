#include "Dijkstra.h"



using namespace std;

int main()
{
	AdjacencyMatrix adj(100);
	adj.fillRandom(0.25);

	
	/*
	AdjacencyList adj(5);
	adj.addEdge(0, 1, 2);
	adj.addEdge(0, 3, 4);
	adj.addEdge(1, 2, 3);
	adj.addEdge(1, 3, 3);
	adj.addEdge(2, 4, 2);
	adj.addEdge(3, 2, 3);
	adj.addEdge(3, 4, 4);
	auto xd = dijkstra(adj, 0);
	for (int i = 0; i < 5; ++i)
	{
		cout << xd[i] << " ";
	}
	*/
	/*
	AdjacencyList adjList(10);
	adjList.addEdge(0, 1 ,10);
	adjList.addEdge(0, 2, 20);
	adjList.addEdge(0, 3, 30);
	adjList.addEdge(0, 4, 40);
	adjList.addEdge(0, 5, 50);
	adjList.addEdge(0, 6, 60);
	adjList.addEdge(0, 7, 70);
	adjList.addEdge(0, 8, 80);
	adjList.addEdge(0, 9, 90);


	vector<int> dane = adjList.neighbours(0);
	auto iterator = dane.begin();
	while (iterator != dane.end())
	{
		cout << "Edge: " << *iterator << endl;
		cout << "Value: " << adjList.weight(0, *iterator) << endl;
		iterator++;
	}
	*/


}
