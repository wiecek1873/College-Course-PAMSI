#pragma once 
#include "PaczkaTablic.h"

template<typename T>
void Zamien(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T& MedianaZTrzech(T* tablica, int pierwszy, int ostatni)
{
	int srodkowy = (ostatni + pierwszy) / 2;
	if (tablica[pierwszy] < tablica[srodkowy] && tablica[srodkowy] < tablica[ostatni])
		return tablica[srodkowy];

	if (tablica[pierwszy] < tablica[ostatni] && tablica[ostatni] <= tablica[srodkowy])
		return tablica[ostatni];

	if (tablica[srodkowy] <= tablica[pierwszy] && tablica[pierwszy] < tablica[ostatni])
		return tablica[pierwszy];

	if (tablica[srodkowy] < tablica[ostatni] && tablica[ostatni] <= tablica[pierwszy])
		return tablica[ostatni];

	if (tablica[ostatni] <= tablica[pierwszy] && tablica[pierwszy] < tablica[srodkowy])
		return tablica[pierwszy];

	if (tablica[ostatni] <= tablica[srodkowy] && tablica[srodkowy] <= tablica[pierwszy])
		return tablica[srodkowy];
}

template<typename T>
int PodzielTablice(T* tablica, int pierwszyIndeks, int ostatniIndeks)
{
	T os = MedianaZTrzech(tablica,pierwszyIndeks,ostatniIndeks);
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
void quickSort(T* tablica, int pierwszyIndeks, int ostatniIndeks)
{
	if (pierwszyIndeks < ostatniIndeks)
	{
		int os = PodzielTablice(tablica, pierwszyIndeks, ostatniIndeks);
		quickSort(tablica, pierwszyIndeks, os);
		quickSort(tablica, os + 1, ostatniIndeks);
	}
}

template<typename T>
void quickSort(PaczkaTablic<T>* paczka)
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
void quickSort(PaczkaTablic<T>* paczka, double ilePosortowac)
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