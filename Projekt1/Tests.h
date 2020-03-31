#pragma once
#include <iostream>

#include <list>
#include <stack>
#include <queue>
#include <concurrent_priority_queue.h>
#include <map>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Map.h"

class Tests
{
public:
	void testList();
	void testStack();
	void testQueue();
	void testPriorityQueue();
	void testMap();
	void testIterator();
};

void Tests::testList()
{
	List<int>* list1 = new List<int>();
	std::list<int>* list2 = new std::list<int>();

	for (int i = 1; i < 10; i++)
	{
		list1->pushBack(i);
		list2->push_back(i);
	}

	list1->pushFront(0);
	list2->push_front(0);
	
	list1->insert(100, 0);
	list2->insert(list2->begin(), 100);

	list1->remove(100);
	list2->remove(100);
	
	Iterator<int> iterator1 = list1->begin();
	
	std::cout << "Zaimplementowana lista1: ";
	while (iterator1 != list1->end())
	{
		std::cout << *iterator1 << " ";
		++iterator1;
	}
	std::cout << std::endl;
	
	std::list<int>::iterator iterator2 = list2->begin();

	std::cout << "STL'owa lista2: ";
	while (iterator2 != list2->end())
	{
		std::cout << *iterator2 << " ";
		++iterator2;
	}
	std::cout << std::endl;

	List<int>* list3 = new List<int>(*list1);
	List<int>* list4 = new List<int>();
	*list4 = *list1;

	delete list1;

	Iterator<int> iterator3 = list3->begin();

	std::cout << "Zaimplementowana lista3: ";
	while (iterator3 != list3->end())
	{
		std::cout << *iterator3 << " ";
		++iterator3;
	}
	std::cout << std::endl;

	Iterator<int> iterator4 = list4->begin();

	std::cout << "Moja lista4: ";
	while (iterator4 != list4->end())
	{
		std::cout << *iterator4 << " ";
		++iterator4;
	}
	std::cout << std::endl;

	delete list2;
	delete list3;
	delete list4;
	std::cout << "Listy usuniete" << std::endl;
	std::cout << "*************************************************" << std::endl;
}
void Tests::testStack()
{
	Stack<int>* stack1 = new Stack<int>();
	std::stack<int>* stack2 = new std::stack<int>();

	for (int i = 9; i >= 0 ; i--)
	{
		stack1->push(i);
		stack2->push(i);
	}

	Stack<int>* stack3 = new Stack<int>(*stack1);
	Stack<int>* stack4 = new Stack<int>();
	*stack4 = *stack1;

	std::cout << "Zaimplementowany stack1: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << stack1->pop() << " ";
	}
	std::cout << std::endl;

	std::cout << "STL'owy stack2: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << stack2->top() << " ";
		stack2->pop();
	}
	std::cout << std::endl;

	std::cout << "Zaimplementowany stack3: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << stack3->pop() << " ";
	}
	std::cout << std::endl;

	std::cout << "Zaimplementowany stack4: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << stack4->pop() << " ";
	}
	std::cout << std::endl;

	delete stack1;
	delete stack2;
	delete stack3;
	delete stack4;
	
	std::cout << "Stacki usuniete" << std::endl;
	std::cout << "*************************************************" << std::endl;
}
void Tests::testQueue()
{
	Queue<int>* queue1 = new Queue<int>();
	std::queue<int>* queue2 = new std::queue<int>();

	for (int i = 0; i < 10; i++)
	{
		queue1->enqueue(i);
		queue2->push(i);
	}

	Queue<int>* queue3 = new Queue<int>(*queue1);
	Queue<int>* queue4 = new Queue<int>();
	*queue4 = *queue1;

	std::cout << "Zaimplementowana queue1: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << queue1->dequeue() << " ";
	}
	std::cout << std::endl;	

	std::cout << "STL'owa queue2: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << queue2->front() << " ";
		queue2->pop();
	}
	std::cout << std::endl;

	std::cout << "Zaimplementowana queue3: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << queue3->dequeue() << " ";
	}
	std::cout << std::endl;

	std::cout << "Zaimplementowana queue4: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << queue4->dequeue() << " ";
	}
	std::cout << std::endl;
	delete queue1;
	delete queue2;
	delete queue3;
	delete queue4;
	std::cout << "Queue usuniete" << std::endl;
	std::cout << "*************************************************" << std::endl;
}
void Tests::testPriorityQueue()
{
	PriorityQueue<int>* pQ1 = new PriorityQueue<int>();
	std::priority_queue<int>* pQ2 = new std::priority_queue<int>();

	for (int i = 0; i < 10; i++)
	{
		pQ1->enqueue(i, i);
		pQ2->push(i);
	}

	PriorityQueue<int>* pQ3 = new PriorityQueue<int>(*pQ1);
	PriorityQueue<int>* pQ4 = new PriorityQueue<int>();
	*pQ4 = *pQ1;

	std::cout << "pQ1,pQ3,pQ4 wyswietlaja wartosci ktore sa ulozone" << std::endl;
	std::cout << "wedlug najwiekszego priorytetu. Wartosc komorki jest" << std::endl;
	std::cout << "rowna jego priorytetowi." << std::endl;
	std::cout << "pQ2 wyswietla wartosci ktore zostaly posortowane malejaco." << std::endl << std::endl;

	std::cout << "Zaimplementowana pQ1: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << pQ1->dequeue() << " ";
	}
	std::cout << std::endl;

	std::cout << "STL'owa pQ2: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << pQ2->top() << " ";
		pQ2->pop();
	}
	std::cout << std::endl;

	std::cout << "Zaimplpementowana pQ3: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << pQ3->dequeue() << " ";
	}
	std::cout << std::endl;

	std::cout << "Zaimplementowana pQ4: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << pQ4->dequeue() << " ";
	}
	std::cout << std::endl;
	
	delete pQ1;
	delete pQ2;
	delete pQ3;
	delete pQ4;

	std::cout << "PriorityQueue usuniete" << std::endl;
	std::cout << "*************************************************" << std::endl;
}
void Tests::testMap()
{
	Map<int, int>* map1 = new Map<int, int>();
	Map<string, int>* map2 = new Map<string, int>();

	map1->insert(25, 1);
	map1->insert(30, 2);
	map1->insert(35, 3);
	map2->insert("Ania", 4);
	map2->insert("Damian", 5);
	map2->insert("Ola", 6);

	std::cout << "Zaimplementowana map1<int,int>: ";
	std::cout << (*map1)[25] << " " << (*map1)[30] << " " << (*map1)[35] << std::endl;
	std::cout << "Zaimplementowana map2<string,int>: ";
	std::cout << (*map2)["Ania"] << " " << (*map2)["Damian"] << " " << (*map2)["Ola"] << std::endl;

	delete map1;
	delete map2;

	std::cout << "Map usuniete" << std::endl;
	std::cout << "*************************************************" << std::endl;
	
}
void Tests::testIterator()
{
	List<int>* list = new List<int>();
	for (int i = 0; i < 10; i++)
		list->pushBack(i);
	list->pushBack(15);
	list->pushBack(15);

	Iterator<int> iterator = list->begin();
	std::cout << "Zawartosc listy to: ";
	while (iterator != list->end())
	{
		std::cout << *iterator << " ";
		++iterator;
	}
	std::cout << std::endl;

	std::cout << "Liczba wystapien liczby \"15\": ";
	std::cout << std::count_if(list->begin(), list->end(), [](int i) { return i == 15;}) << std::endl;

	delete list;
	std::cout << "Lista usunieta" << std::endl;
	std::cout << "*************************************************" << std::endl;


}