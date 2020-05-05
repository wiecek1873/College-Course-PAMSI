#include "Tests.h"
using namespace std;

int main()
{	
	Tests<AdjacencyMatrix> matrix;
	Tests<AdjacencyList> list;
	matrix.testDijkstraTime();
	list.testDijkstraTime();

	matrix.saveRandomGraph(10,1,"SaveGraph.txt");
	matrix.loadGraph(10,"SaveGraph.txt");
	matrix.saveRandomDijkstraOutput(10, 1, "DijkstraOutput.txt");
}
