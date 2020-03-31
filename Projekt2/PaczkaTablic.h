#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
class PaczkaTablic
{
	T*** _paczkaTablic;
	int* _dlugosciTablic;
	int _ilosc;
	int _liczbaDlugosci;

	T*** StworzTablice(int dlugosci[], int ilosc, int liczbaDlugosci);

public:

	PaczkaTablic(int dlugosci[], int ilosc, int liczbaDlugosci);
	~PaczkaTablic();

	int DlugoscTablicy(int indeks) { return _dlugosciTablic[indeks]; }
	int IloscTablic() { return _ilosc; }
	int LiczbaDlugosci() { return _liczbaDlugosci; }

	void ObrocTablice();

	T* operator()(int indeks1, int indeks2);
	T& operator()(int indeks1, int indeks2, int indeks3);
	template<typename T>
	friend ostream& operator <<(ostream& wyjscie, const PaczkaTablic<T>& paczkaTablic);

};

template<typename T>
T*** PaczkaTablic<T>::StworzTablice(int dlugosci[], int ilosc, int liczbaDlugosci)
{
	T*** wyjscie = new T * *[liczbaDlugosci];

	for (int i = 0; i < liczbaDlugosci; i++)
	{
		T** tablicaDlugosci = new T * [ilosc];

		for (int j = 0; j < ilosc; j++)
		{
			T* tablicaIlosci = new T[dlugosci[i]];

			for (int k = 0; k < dlugosci[i]; k++)
			{
				tablicaIlosci[k] = rand();
			}

			tablicaDlugosci[j] = tablicaIlosci;
		}

		wyjscie[i] = tablicaDlugosci;
	}
	return wyjscie;
}

template<typename T>
PaczkaTablic<T>::PaczkaTablic(int dlugosci[], int ilosc, int liczbaDlugosci)
{
	_dlugosciTablic = new int[liczbaDlugosci];
	for (int i = 0; i < liczbaDlugosci; i++)
		_dlugosciTablic[i] = dlugosci[i];
	_ilosc = ilosc;
	_liczbaDlugosci = liczbaDlugosci;

	_paczkaTablic = StworzTablice(dlugosci, ilosc, liczbaDlugosci);
}

template<typename T>
PaczkaTablic<T>::~PaczkaTablic()
{
	delete[] _dlugosciTablic;
	for (int i = 0; i < _liczbaDlugosci; i++)
	{
		for (int j = 0; j < _ilosc; j++)
		{
			delete[] _paczkaTablic[i][j];
		}
	}
}

template<typename T>
void PaczkaTablic<T>::ObrocTablice()
{
	for (int i = 0; i < _liczbaDlugosci; i++)
	{
		for (int j = 0; j < _ilosc; j++)
		{
			for (int k = 0; k < _dlugosciTablic[i] / 2; k++)
			{
				T temp = _paczkaTablic[i][j][k];
				_paczkaTablic[i][j][k] = _paczkaTablic[i][j][_dlugosciTablic[i] - 1 - k];
				_paczkaTablic[i][j][_dlugosciTablic[i] - 1 - k] = temp;
			}
		}
	}
}

template<typename T>
T* PaczkaTablic<T>::operator()(int indeks1, int indeks2)
{
	return _paczkaTablic[indeks1][indeks2];
}

template<typename T>
T& PaczkaTablic<T>::operator()(int indeks1, int indeks2, int indeks3)
{
	if (indeks1 >= LiczbaDlugosci())
		throw;
	if (indeks2 >= IloscTablic())
		throw;
	if (indeks3 >= DlugoscTablicy(indeks1))
		throw;

	return _paczkaTablic[indeks1][indeks2][indeks3];
}

template<typename T>
ostream& operator <<(ostream& wyjscie, const PaczkaTablic<T>& paczkaTablic)
{
	for (int i = 0; i < paczkaTablic._liczbaDlugosci; i++)
	{
		wyjscie << "===============" << endl;
		wyjscie << "Teraz rozmiar: " << paczkaTablic._dlugosciTablic[i] << endl;
		for (int j = 0; j < paczkaTablic._ilosc; j++)
		{
			wyjscie << "***************" << endl;
			wyjscie << "Tablica nr: " << j << endl;
			for (int k = 0; k < paczkaTablic._dlugosciTablic[i]; k++)
			{
				wyjscie << paczkaTablic._paczkaTablic[i][j][k] << endl;
			}
		}
	}
	return wyjscie;
}