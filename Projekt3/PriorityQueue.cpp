#include "PriorityQueue.h"

void PriorityQueue::push(pi element)
{
	container.push_back(element);
}
pi PriorityQueue::pop()
{
	std::swap(*std::min_element(container.begin(), container.end()), *(container.end() - 1));
	auto top = *(container.end() - 1);
	container.pop_back();
	return top;
}
bool PriorityQueue::empty()
{
	if (container.begin() == container.end())
		return true;
	else
		return false;
}
void PriorityQueue::decreasePriority(int which, int value)
{
	auto it = std::find_if(container.begin(), container.end(), [which](const pi& pair) { return which == pair.second; });

	if (container.end() == it)
		throw std::exception("Not found");

	(*it).first = value;
}