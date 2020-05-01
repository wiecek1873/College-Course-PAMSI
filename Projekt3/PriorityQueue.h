#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

typedef std::pair<int, int> pi; //Type to contain distance to vertex as first argument and vertex index

class PriorityQueue
{
public:
	std::vector<pi> container;
public:
	void push(pi element);
	pi pop();

	bool empty();
	void decreasePriority(int which, int value);
	PriorityQueue() {};
};