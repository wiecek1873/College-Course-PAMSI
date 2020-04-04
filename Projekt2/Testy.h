#pragma once
#include <fstream> 
#include <chrono>
#include <iomanip>
#include "IntroSort.h"
#include"PaczkaTablic.h"
#include"QuickSort.h"
#include"MergeSort.h"
using namespace std;

template<typename T>
class Testy
{
	int* _dlugosciTablic;
	int _ilosc;
	int _liczbaDlugosci;

	bool CzyPosortowane(T tablica[], int dlugoscTablicy, bool rosnaco);
	bool CzyPosortowaneCalaPaczka(PaczkaTablic<T>* paczka, bool rosnaco);
public:
	Testy(int dlugosci[], int ilosc, int liczbaDlugosci);
	void TestQuickSort();
	void TestMergeSort();
	void TestIntroSort();
};

template<typename T>
bool Testy<T>::CzyPosortowane(T tablica[], int dlugoscTablicy, bool rosnaco)
{
	bool posortowane = true;
	int i = 0;
	while (posortowane && i < dlugoscTablicy - 1)
	{
		if (rosnaco)
		{
			if (tablica[i] > tablica[i + 1])
				posortowane = false;
			i++;
		}
		else
		{
			if (tablica[i] < tablica[i + 1])
				posortowane = false;
			i++;
		}
	}
	return posortowane;
}

template<typename T>
bool Testy<T>::CzyPosortowaneCalaPaczka(PaczkaTablic<T>* paczka, bool rosnaco)
{
	int liczbaDlugosci = paczka->LiczbaDlugosci();
	int iloscTablic = paczka->IloscTablic();

	for (int i = 0; i < liczbaDlugosci; i++)
	{
		for (int j = 0; j < iloscTablic; j++)
		{
			if (!(CzyPosortowane((*paczka)(i, j), paczka->DlugoscTablicy(i), rosnaco)))
				return false;
		}
	}
	return true;
}

template<typename T>
Testy<T>::Testy(int dlugosci[], int ilosc, int liczbaDlugosci)
{
	_dlugosciTablic = new int[liczbaDlugosci];
	for (int i = 0; i < liczbaDlugosci; i++)
		_dlugosciTablic[i] = dlugosci[i];
	_ilosc = ilosc;
	_liczbaDlugosci = liczbaDlugosci;
}

template<typename T>
void Testy<T>::TestQuickSort()
{
	PaczkaTablic<T>* paczka = new PaczkaTablic<T>(_dlugosciTablic, _ilosc, _liczbaDlugosci);

	fstream plik;
	plik.open("QuickSort.txt", ios::out);

	for (int i = 0; i < _liczbaDlugosci; i++)
	{
		for (int j = 0; j < _ilosc; j++)
		{
			auto start = chrono::high_resolution_clock::now();

			quickSort((*paczka)(i, j), 0, (_dlugosciTablic)[i] - 1);

			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
			plik << double(duration.count()) / 1000000  << "," ;
		}
		plik << endl;
	}

	if (!CzyPosortowaneCalaPaczka(paczka, true))
		plik << "Poprzedni test zle wykonany!!!!!!" << endl;
	delete paczka;
	plik << "=================================================" << endl;
	
	double ilePosortowac[] = { 0.25, 0.5, 0.75, 0.95, 0.99, 0.997};
	for (int k = 0; k < 6; k++)
	{
		paczka = new PaczkaTablic<T>(_dlugosciTablic, _ilosc, _liczbaDlugosci);
		quickSort(paczka, ilePosortowac[k]);

		for (int i = 0; i < _liczbaDlugosci; i++)
		{
			for (int j = 0; j < _ilosc; j++)
			{
				auto start = chrono::high_resolution_clock::now();

				quickSort((*paczka)(i, j), 0, (_dlugosciTablic)[i] - 1);

				auto stop = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
				plik << double(duration.count()) / 1000000 << ",";
			}
			plik << endl;
		}
		if (!CzyPosortowaneCalaPaczka(paczka, true))
			plik << "Poprzedni test zle wykonany!!!!!!" << endl;
		plik << endl;
		delete paczka;
	}
	plik << "=================================================" << endl;
	
	paczka = new PaczkaTablic<T>(_dlugosciTablic, _ilosc, _liczbaDlugosci);
	quickSort(paczka);
	paczka->ObrocTablice();
	if (!CzyPosortowaneCalaPaczka(paczka, false))
		plik << "Problem z obrotem tablicy!!!!!!!" << endl;
	for (int i = 0; i < _liczbaDlugosci; i++)
	{
		for (int j = 0; j < _ilosc; j++)
		{
			auto start = chrono::high_resolution_clock::now();

			quickSort((*paczka)(i, j), 0, (_dlugosciTablic)[i] - 1);

			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
			plik << double(duration.count()) / 1000000 << ",";
		}
		plik << endl;
	}

	if (!CzyPosortowaneCalaPaczka(paczka, true))
		plik << "Poprzedni test zle wykonany!!!!!!" << endl;
	delete paczka;
	plik << "=================================================" << endl;
	plik.close();
}

template<typename T>
void Testy<T>::TestMergeSort()

{
	PaczkaTablic<T>* paczka = new PaczkaTablic<T>(_dlugosciTablic, _ilosc, _liczbaDlugosci);

	fstream plik;
	plik.open("MergeSort.txt", ios::out);

	for (int i = 0; i < _liczbaDlugosci; i++)
	{
		for (int j = 0; j < _ilosc; j++)
		{
			auto start = chrono::high_resolution_clock::now();

			mergeSort((*paczka)(i, j), 0, (_dlugosciTablic)[i] - 1);

			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
			plik << double(duration.count()) / 1000000 << ",";
		}
		plik << endl;
	}

	if (!CzyPosortowaneCalaPaczka(paczka, true))
		plik << "Poprzedni test zle wykonany!!!!!!" << endl;

	delete paczka;
	plik << "=================================================" << endl;

	double ilePosortowac[] = { 0.25, 0.5, 0.75, 0.95, 0.99, 0.997 };
	for (int k = 0; k < 6; k++)
	{
		paczka = new PaczkaTablic<T>(_dlugosciTablic, _ilosc, _liczbaDlugosci);
		quickSort(paczka, ilePosortowac[k]);

		for (int i = 0; i < _liczbaDlugosci; i++)
		{
			for (int j = 0; j < _ilosc; j++)
			{
				auto start = chrono::high_resolution_clock::now();

				mergeSort((*paczka)(i, j), 0, (_dlugosciTablic)[i] - 1);

				auto stop = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
				plik << double(duration.count()) / 1000000 << ",";
			}
			plik << endl;
		}
		if (!CzyPosortowaneCalaPaczka(paczka, true))
			plik << "Poprzedni test zle wykonany!!!!!!" << endl;
		plik << endl;
		delete paczka;
	}
	plik << "=================================================" << endl;

	paczka = new PaczkaTablic<T>(_dlugosciTablic, _ilosc, _liczbaDlugosci);
	quickSort(paczka);
	paczka->ObrocTablice();
	if (!CzyPosortowaneCalaPaczka(paczka, false))
		plik << "Problem z obrotem tablicy!!!!!!!" << endl;

	for (int i = 0; i < _liczbaDlugosci; i++)
	{
		for (int j = 0; j < _ilosc; j++)
		{
			auto start = chrono::high_resolution_clock::now();

			mergeSort((*paczka)(i, j), 0, (_dlugosciTablic)[i] - 1);

			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
			plik << double(duration.count()) / 1000000 << ",";
		}
		plik << endl;
	}

	if (!CzyPosortowaneCalaPaczka(paczka, true))
		plik << "Poprzedni test zle wykonany!!!!!!" << endl;
	delete paczka;
	plik << "=================================================" << endl;
	plik.close();
}

template<typename T>
void Testy<T>::TestIntroSort()
{
	PaczkaTablic<T>* paczka = new PaczkaTablic<T>(_dlugosciTablic, _ilosc, _liczbaDlugosci);

	fstream plik;
	plik.open("IntroSort.txt", ios::out);

	for (int i = 0; i < _liczbaDlugosci; i++)
	{
		for (int j = 0; j < _ilosc; j++)
		{
			auto start = chrono::high_resolution_clock::now();

			introSort((*paczka)(i, j), 0, (_dlugosciTablic)[i] - 1);

			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
			plik << double(duration.count()) / 1000000 << ",";
		}
		plik << endl;
	}

	if (!CzyPosortowaneCalaPaczka(paczka, true))
		plik << "Poprzedni test zle wykonany!!!!!!" << endl;
	delete paczka;
	plik << "=================================================" << endl;

	double ilePosortowac[] = { 0.25, 0.5, 0.75, 0.95, 0.99, 0.997 };
	for (int k = 0; k < 6; k++)
	{
		paczka = new PaczkaTablic<T>(_dlugosciTablic, _ilosc, _liczbaDlugosci);
		quickSort(paczka, ilePosortowac[k]);

		for (int i = 0; i < _liczbaDlugosci; i++)
		{
			for (int j = 0; j < _ilosc; j++)
			{
				auto start = chrono::high_resolution_clock::now();

				introSort((*paczka)(i, j), 0, (_dlugosciTablic)[i] - 1);

				auto stop = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
				plik << double(duration.count()) / 1000000 << ",";
			}
			plik << endl;
		}
		if (!CzyPosortowaneCalaPaczka(paczka, true))
			plik << "Poprzedni test zle wykonany!!!!!!" << endl;
		plik << endl;
		delete paczka;
	}
	plik << "=================================================" << endl;

	paczka = new PaczkaTablic<T>(_dlugosciTablic, _ilosc, _liczbaDlugosci);
	quickSort(paczka);
	paczka->ObrocTablice();
	if (!CzyPosortowaneCalaPaczka(paczka, false))
		plik << "Problem z obrotem tablicy!!!!!!!" << endl;
	for (int i = 0; i < _liczbaDlugosci; i++)
	{
		for (int j = 0; j < _ilosc; j++)
		{
			auto start = chrono::high_resolution_clock::now();

			introSort((*paczka)(i, j), 0, (_dlugosciTablic)[i] - 1);

			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
			plik << double(duration.count()) / 1000000 << ",";
		}
		plik << endl;
	}

	if (!CzyPosortowaneCalaPaczka(paczka, true))
		plik << "Poprzedni test zle wykonany!!!!!!" << endl;
	delete paczka;
	plik << "=================================================" << endl;
	plik.close();
}



