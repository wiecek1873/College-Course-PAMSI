#pragma once
#include <iostream>

#include "QuickSort.h"
#include "MergeSort.h"
#include "PaczkaTablic.h"
#include "Testy.h"

using namespace std;

template<class typ>
class Menu
{
	char _wybor;
	Testy<typ>* _testy;

	void WyswietlMenu()
	{
		cout << "=========================" << endl;
		cout << "1. Generuj Paczke Tablic" << endl;
		cout << "2. Posortuj Quick Sortem" << endl;
		cout << "3. Posortuj Merge Sortem" << endl;
		cout << "4. Posortuj Intro Sortem" << endl;
		cout << "5. Odpal demo" << endl;
		cout << "6. Co to demo?" << endl;
		cout << endl;
		cout << "q. Wyjscie" << endl;
	}

	void Wybor()
	{
		bool wybrane = false;
		while (!wybrane)
		{
			cin >> _wybor;
			if (_wybor == '1' || _wybor == '2' || _wybor == '3' || _wybor == '4' || _wybor == '5' || _wybor == '6' || _wybor == 'q')
				wybrane = true;
			else
				cout << "Zly wybor" << endl;

		}
	}




public:

	void Wykonaj()
	{
		WyswietlMenu();
		Wybor();

		
	}
	
};

