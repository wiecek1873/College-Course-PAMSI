#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <chrono>

#include "IntroSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"
#include "PaczkaTablic.h"
#include "Testy.h"
#include "Menu.h"

using namespace std;



int main()
{
	
	int dlugosci[] = {10000,50000,100000,500000,1000000 };
	Testy<int>* testy = new Testy<int>(dlugosci, 100, 5);
	cout << "Teraz test QucikSort'a" << endl;
	testy->TestQuickSort();
	cout << "Teraz test MergeSort'a" << endl;
	testy->TestMergeSort();
	cout << "Teraz test IntroSort'a" << endl;
	testy->TestIntroSort();
	cout << "Koniec" << endl;

	

	

	
	


}



/*
		auto start = chrono::high_resolution_clock::now();
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		cout << "Czas generowania tablic: "<< duration.count()/1000 <<"ms"<< endl;
*/