#pragma once

template<class T>
struct Node
{
	T value;
	Node<T>* ptr;

	Node(const T& newElement);
	void setPtr(Node* newNode);
};

template<class T>
Node<T>::Node(const T& newElement)
{
	value = newElement;
	ptr = nullptr;
}

template<class T>
void Node<T>::setPtr(Node* newNode)
{
	ptr = newNode;
}