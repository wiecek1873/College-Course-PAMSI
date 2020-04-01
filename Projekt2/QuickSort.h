#pragma once 
#include "PaczkaTablic.h"

template<typename T>
class QuickSort
{
	int PodzielTablice(T tablica[], int pierwszyIndeks, int ostatniIndeks);
	void Zamien(T& a, T& b);
public:
	void quickSort(T tablica[], int pierwszyIndeks, int ostatniIndeks);
	void quickSort(PaczkaTablic<T>* paczka);
	void quickSort(PaczkaTablic<T>* paczka, double ilePosortowac);
};

template<typename T>
int QuickSort<T>::PodzielTablice(T tablica[], int pierwszyIndeks, int ostatniIndeks)
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
void QuickSort<T>::Zamien(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void QuickSort<T>::quickSort(T tablica[], int pierwszyIndeks, int ostatniIndeks)
{
	if (pierwszyIndeks < ostatniIndeks)
	{
		int os = PodzielTablice(tablica, pierwszyIndeks, ostatniIndeks);
		quickSort(tablica, pierwszyIndeks, os);
		quickSort(tablica, os + 1, ostatniIndeks);
	}
}

template<typename T>
void QuickSort<T>::quickSort(PaczkaTablic<T>* paczka)
{
	int liczbaWielkosci = paczka->LiczbaDlugosci();
	int iloscTablic = paczka->IloscTablic();
	for (int i = 0; i < liczbaWielkosci; i++)
	{
		for (int j = 0; j < iloscTablic; j++)
		{
			quickSort((*paczka)(i, j), 0, paczka->DlugoscTablicy(i) - 1);
		}
	}
}

template<typename T>
void QuickSort<T>::quickSort(PaczkaTablic<T>* paczka, double ilePosortowac)
{
	int liczbaWielkosci = paczka->LiczbaDlugosci();
	int iloscTablic = paczka->IloscTablic();
	for (int i = 0; i < liczbaWielkosci; i++)
	{
		for (int j = 0; j < iloscTablic; j++)
		{
			quickSort((*paczka)(i, j), 0, static_cast<int>(paczka->DlugoscTablicy(i) * ilePosortowac));
		}
	}
}