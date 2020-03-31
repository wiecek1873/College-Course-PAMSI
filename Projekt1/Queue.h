#pragma once
#include "List.h"

template<class T>
class Queue
{
	List<T>* list;
public:
	Queue() { list = new List<T>(); };
	Queue(const Queue<T>& queue) { list = new List<T>(*queue.list); }
	~Queue() { delete list; };

	void enqueue(const T& newElement);
	T dequeue();
	Queue<T>& operator = (const Queue<T>& queue);
};

template<class T>
void Queue<T>::enqueue(const T& newElement)
{
	list->pushBack(newElement);
}

template<class T>
T Queue<T>::dequeue()
{
	if (list->head != nullptr)
	{
		T temp = (*list)[0];
		list->removeIndex(0);
		return temp;
	}
	else
		throw std::invalid_argument("No value");
}

template<class T>
Queue<T>& Queue<T>::operator = (const Queue<T>& queue)
{
	delete this->list;
	this->list = new List<T>(*queue.list);
	return *this;
}