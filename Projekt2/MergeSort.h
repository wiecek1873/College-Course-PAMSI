#pragma once
#include "PaczkaTablic.h"

template<typename T>
class MergeSort
{
	void Scal(T tablica[], int pierwszyIndeks, int os, int ostatniIndeks);
public:
	void mergeSort(T tablica[], int pierwszyIndeks, int ostatniIndeks);
};

template<typename T>
void MergeSort<T>::Scal(T tablica[], int pierwszyIndeks, int os, int ostatniIndeks)
{
	int i, j, k;
	int n1 = os - pierwszyIndeks + 1;
	int n2 = ostatniIndeks - os;

	T* L = new T[n1];
	T* R = new T[n2];

	for (i = 0; i < n1; i++)
		L[i] = tablica[pierwszyIndeks + i];
	for (j = 0; j < n2; j++)
		R[j] = tablica[os + 1 + j];
	i = 0;
	j = 0;
	k = pierwszyIndeks;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			tablica[k] = L[i];
			i++;
		}
		else
		{
			tablica[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		tablica[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		tablica[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

template<typename T>
void MergeSort<T>::mergeSort(T tablica[], int pierwszyIndeks, int ostatniIndeks)
{
	if (pierwszyIndeks < ostatniIndeks)
	{
		int os = pierwszyIndeks + (ostatniIndeks - pierwszyIndeks) / 2;

		mergeSort(tablica, pierwszyIndeks, os);
		mergeSort(tablica, os + 1, ostatniIndeks);

		Scal(tablica, pierwszyIndeks, os, ostatniIndeks);
	}
}
