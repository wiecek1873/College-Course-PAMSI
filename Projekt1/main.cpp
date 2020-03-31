#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include "Tests.h"

using namespace std;

int main()
{
	Tests test;
	test.testList();
	test.testIterator();
	test.testStack();
	test.testQueue();
	test.testPriorityQueue();
	test.testMap();
}