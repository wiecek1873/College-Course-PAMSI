#pragma once
#include <iterator>
#include "Node.h"

template<class T>
struct Iterator
{
	using difference_type = std::size_t;
	using value_type = T;
	using reference = T&;
	using pointer = T*;
	using iterator_category = std::input_iterator_tag;

	Node<T>* node;

	Iterator(Node<T>* newNode) : node(newNode) {};
	~Iterator() {};

	void operator++();
	bool operator != (Iterator const& iterator) const;
	T& operator*();
};

template<class T>
void Iterator<T>::operator++()
{
	if (node != nullptr)
		node = node->ptr;
	else
		throw std::invalid_argument("Out of range");
}

template<class T>
bool Iterator<T>::operator != (Iterator const& iterator) const
{
	return this->node != iterator.node;
}

template<class T>
T& Iterator<T>::operator*()
{
	return node->value;
}

template<class T>
struct ConstIterator
{
	Node<T>* node;

	ConstIterator(Node<T>* newNode) : node(newNode) {};

	void operator++();
	bool operator != (ConstIterator const& iterator) const;
	T& operator*();
};

template<class T>
void ConstIterator<T>::operator++()
{
	if (node != nullptr)
		node = node->ptr;
	else
		throw std::invalid_argument("Out of range");
}

template<class T>
bool ConstIterator<T>::operator != (ConstIterator const& iterator) const
{
	return this->node != iterator.node;
}

template<class T>
T& ConstIterator<T>::operator*()
{
	return node->value;
}