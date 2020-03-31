#pragma once
#include <math.h>
#include "HeapSort.h"
#include "InsertionSort.h"

template<typename T>
class IntroSort
{
	void Zamien(T& a, T& b);
	int PodzielTablice(T tablica[], int pierwszyIndeks, int ostatniIndeks);
	void DzialanieIntroSort(T* tablica, int pierwszyIndeks, int ostatniIndeks, int glebokoscRek);
public:
	void introSort(T* tablica, int pierwszyIndeks, int ostatniIndeks);
};


template<typename T>
void IntroSort<T>::Zamien(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
int IntroSort<T>::PodzielTablice(T tablica[], int pierwszyIndeks, int ostatniIndeks)
{
	T os = tablica[(ostatniIndeks + pierwszyIndeks) / 2];
	int i = pierwszyIndeks - 1;
	int j = ostatniIndeks + 1;
	while (true)
	{
		do
		{
			++i;
		} while (tablica[i] < os);

		do
		{
			--j;
		} while (os < tablica[j]);

		if (i >= j)
		{
			return j;
		}
		Zamien(tablica[i], tablica[j]);
	}
}

template<typename T>
void IntroSort<T>::DzialanieIntroSort(T* tablica, int pierwszyIndeks, int ostatniIndeks, int glebokoscRek)
{
	int rozmiar = ostatniIndeks - pierwszyIndeks + 1;
	if (rozmiar <= 9)
	{
		InsertionSort<T>* insertionSort = new InsertionSort<T>();
		insertionSort->insertionSort(tablica, pierwszyIndeks, ostatniIndeks);
		delete insertionSort;
	}
	else if (glebokoscRek == 0)
	{
		HeapSort<T>* heapSort = new HeapSort<T>();
		heapSort->heapSort(tablica, pierwszyIndeks, ostatniIndeks);
		delete heapSort;
	}
	else if (pierwszyIndeks < ostatniIndeks)
	{
		int os = PodzielTablice(tablica, pierwszyIndeks, ostatniIndeks);
		DzialanieIntroSort(tablica, pierwszyIndeks, os, --glebokoscRek);
		DzialanieIntroSort(tablica, os + 1, ostatniIndeks, --glebokoscRek);
	}
}

template<typename T>
void IntroSort<T>::introSort(T* tablica, int pierwszyIndeks, int ostatniIndeks)
{
	int glebokoscRek = (int)log(ostatniIndeks - pierwszyIndeks + 1) * 2;
	DzialanieIntroSort(tablica, pierwszyIndeks, ostatniIndeks, glebokoscRek);
}