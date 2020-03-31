#pragma once
#include "List.h"

template<class T>
class PriorityQueue
{
public:
	List<T>* values;
	List<int>* priorities;

	PriorityQueue() { values = new List<T>(); priorities = new List<int>(); }
	PriorityQueue(const PriorityQueue<T>& priorityQueue);
	~PriorityQueue() { delete values; delete priorities; }

	void enqueue(const T& newElement, int priority);
	T dequeue();
	PriorityQueue<T>& operator = (const PriorityQueue<T>& priorityQueue);
};

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& priorityQueue)
{
	values = new List<T>(*priorityQueue.values);
	priorities = new List<T>(*priorityQueue.priorities);
}

template<class T>
void PriorityQueue<T>::enqueue(const T& newElement, int priority)
{
	int index = 0;
	bool inserted = false;
	bool frontBigger = false;
	bool backSmaller = false;
	Iterator<T> iterator = priorities->begin();

	if (!(iterator != priorities->end()))
	{
		values->insert(newElement,0);
		priorities->insert(priority,0);
		inserted = true;
	}
	else
	{
		while (!inserted)
		{
			++iterator;

			if (index == 0 || (*priorities)[index] >= priority)
				frontBigger = true;
			else
				frontBigger = false;

			if (!(iterator != priorities->end()) || (*priorities)[index + 1] < priority)
				backSmaller = true;
			else
				backSmaller = false;

			if (index == 0 && priority >= (*priorities)[index])
			{
				priorities->insert(priority, index);
				values->insert(newElement, index);
				inserted = true;
			}

			if (frontBigger && backSmaller && !inserted)
			{
				priorities->insert(priority, index+1);
				values->insert(newElement, index+1);
				inserted = true;
			}
			else
				++index;
		}
	}
}

template<class T>
T PriorityQueue<T>::dequeue()
{
	if (values->head != nullptr)
	{
		T temp = (*values)[0];
		values->removeIndex(0);
		priorities->removeIndex(0);
		return temp;
	}
	else
		throw std::invalid_argument("No value");
}

template<class T>
PriorityQueue<T>& PriorityQueue<T>::operator = (const PriorityQueue<T>& priorityQueue)
{
	delete this->values;
	delete this->priorities;
	this->values = new List<T>(*priorityQueue.values);
	this->priorities = new List<T>(*priorityQueue.priorities);
	return *this;
}

