#pragma once
#include <iostream>
#include "Iterator.h"

template<class T>
class List
{
public:
	Node<T>* head;

	List();
	List(List<T>& list);
	~List();

	void pushBack(const T& newElement);
	void pushFront(const T& newElement);
	void insert(const T& newElement, unsigned int index);
	void remove(const T& element);
	void removeIndex(unsigned int index);
	Iterator<T> begin();
	Iterator<T> end();
	ConstIterator<T> cbegin() const;
	ConstIterator<T> cend() const;
	T& operator [] (int index);
	List<T>& operator = (const List& lista);
};

template<class T>
List<T>::List()
{
	head = nullptr;
}

template<class T> //!!!Przy wywo³aniu jawnym obiekty tworzony i obiekt kopiowany nie mog¹ byæ zmiennymi wskaŸnikowymi
List<T>::List(List<T>& list)
{
	ConstIterator<T> constIterator = list.cbegin();

	while (constIterator != list.cend())
	{
		this->pushBack(*constIterator);
		++constIterator;
	}
}

template<class T>
List<T>::~List()
{
	Node<T>* node = head;
	Node<T>* deleteNode = head;
	while (node != nullptr)
	{
		node = node->ptr;
		delete deleteNode;
		deleteNode = node;
	}

}

template<class T>
void List<T>::pushBack(const T& newElement)
{
	Node<T>* node = head;
	if (head == nullptr)
	{
		head = new Node<T>(newElement);
	}
	else
	{
		while (node->ptr != nullptr)
		{
			node = node->ptr;
		}
		node->ptr = new Node<T>(newElement);
	}
}

template<class T>
void List<T>::pushFront(const T& newElement)
{
	Node<T>* node = new Node<T>(newElement);
	node->ptr = head;
	head = node;
}

template<class T>
void List<T>::insert(const T& newElement, unsigned int index)
{
	Node<T>* node = head;
	Node<T>* preNode = nullptr;
	Node<T>* postNode = nullptr;
	if (head == nullptr || index == 0)
	{
		if (head == nullptr)
			head = new Node<T>(newElement);
		else
		{
			postNode = head;
			head = new Node<T>(newElement);
			head->ptr = postNode;
		}
	}
	else
	{
		for (unsigned int i = 0; i < index; i++)
		{
			if (node == nullptr)
				throw std::invalid_argument("Index out of range");
			if (index - i == 1)
				preNode = node;

			node = node->ptr;
		}
		preNode->ptr = new Node<T>(newElement);
		preNode->ptr->ptr = node;
	}
}

template<class T>
void List<T>::remove(const T& element)
{
	Node<T>* node = head;
	Node<T>* preNode = nullptr;
	Node<T>* postNode = nullptr;
	if (head != nullptr)
	{
		if (head->value == element)
		{
			postNode = head->ptr;
			delete head;
			head = postNode;
		}
		else
		{
			while (node->ptr != nullptr)
			{
				preNode = node;
				node = node->ptr;
				if (node != nullptr && node->value == element)
				{
					postNode = node->ptr;
					delete node;
					preNode->ptr = postNode;
					node = preNode;
				}
			}
		}
	}
}

template<class T>
void List<T>::removeIndex(unsigned int index)
{
	Node<T>* node = head;
	Node<T>* preNode = nullptr;
	Node<T>* postNode = nullptr;

	if (index == 0)
	{
		if (head != nullptr)
		{
			if (head->ptr != nullptr)
			{
				postNode = head->ptr;
				delete node;
				head = postNode;
			}
			else
			{
				delete node;
				head = nullptr;
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < index; i++)
		{
			if (node == nullptr)
				throw std::invalid_argument("Index out of range");
			if (index - i == 1)
				preNode = node;

			node = node->ptr;
		}
		if (node->ptr != nullptr)
			postNode = node->ptr;
		delete node;
		preNode->ptr = postNode;
	}
}

template<class T>
Iterator<T> List<T>::begin()
{
	return Iterator<T>(head);
}

template<class T>
Iterator<T> List<T>::end()
{
	return Iterator<T>(nullptr);
}

template<class T>
ConstIterator<T> List<T>::cbegin() const
{
	return ConstIterator<T>(head);
}

template<class T>
ConstIterator<T> List<T>::cend() const
{
	return ConstIterator<T>(nullptr);
}

template<class T>
T& List<T>::operator [] (int index)
{
	Node<T>* node = head;

	if (node == nullptr)
		throw std::invalid_argument("Out of range");

	for (int i = 0; i < index; i++)
	{
		node = node->ptr;
		if (node == nullptr)
			throw std::invalid_argument("Out of range");
	}
	return node->value;

}

template<class T>
List<T>& List<T>::operator = (const List& lista)
{

	Node<T>* node = this->head;
	Node<T>* deleteNode = this->head;

	while (node != nullptr)
	{
		node = node->ptr;
		delete deleteNode;
		deleteNode = node;
	}

	node = lista.head;
	while (node != nullptr)
	{
		this->pushBack(node->value);
		node = node->ptr;
	}
	return *this;
}