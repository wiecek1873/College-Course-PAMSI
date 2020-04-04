#pragma once
#include "QuickSort.h"

template<typename T>
void insertionSort(T* tablica, int pierwszyIndeks, int ostatniIndeks)
{
	ostatniIndeks++;
	int i = pierwszyIndeks;
	while (i < ostatniIndeks)
	{
		int j = i;
		while (j > 0 && tablica[j - 1] > tablica[j])
		{
			Zamien(tablica[j], tablica[j - 1]);
			--j;
		}
		++i;
	}
}