#include "Tests.h"




using namespace std;

int main()
{

	Tests<AdjacencyList> xd;
	xd.testDijkstraTime();
	Tests<AdjacencyMatrix> xd1;
	xd1.testDijkstraTime();
	

	
	
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
