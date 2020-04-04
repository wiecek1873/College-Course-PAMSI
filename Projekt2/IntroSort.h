#pragma once
#include <math.h>
#include "HeapSort.h"
#include "InsertionSort.h" 
#include "QuickSort.h"

template<typename T>
void DzialanieIntroSort(T* tablica, int pierwszyIndeks, int ostatniIndeks, int glebokoscRek)
{
	int rozmiar = ostatniIndeks - pierwszyIndeks + 1;

	if (rozmiar <= 9)
		insertionSort(tablica, pierwszyIndeks, ostatniIndeks);
	else if (glebokoscRek == 0)
		heapSort(tablica, pierwszyIndeks, ostatniIndeks);
	else if (pierwszyIndeks < ostatniIndeks)
	{
		int os = PodzielTablice(tablica, pierwszyIndeks, ostatniIndeks);
		DzialanieIntroSort(tablica, pierwszyIndeks, os, --glebokoscRek);
		DzialanieIntroSort(tablica, os + 1, ostatniIndeks, --glebokoscRek);
	}
}

template<typename T>
void introSort(T* tablica, int pierwszyIndeks, int ostatniIndeks)
{
	int glebokoscRek = (int)log(ostatniIndeks - pierwszyIndeks + 1) * 2;
	DzialanieIntroSort(tablica, pierwszyIndeks, ostatniIndeks, glebokoscRek);
}