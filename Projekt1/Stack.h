#pragma once
#include "List.h"

template<class T>
class Stack
{
	List<T>* list;
public:
	Stack() { list = new List<T>(); };
	Stack(Stack<T>& stack) { list = new List<T>(*stack.list); };
	~Stack() { delete list; };

	void push(const T& newElement);
	T pop();
	Stack<T>& operator = (const Stack<T>& stack);
};

template<class T>
void Stack<T>::push(const T& newElement)
{
	list->pushFront(newElement);
}

template<class T>
T Stack<T>::pop()
{
	if (list->head == nullptr)
		throw std::invalid_argument("No values left");
	else
	{
		T out = (*list)[0];
		list->removeIndex(0);
		return out;
	}
}

template<class T>
Stack<T>& Stack<T>::operator = (const Stack& stack)
{
	delete this->list;
	this->list = new List<T>(*stack.list);
	return *this;
}