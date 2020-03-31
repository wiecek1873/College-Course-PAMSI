#pragma once

template<typename T>
class InsertionSort
{
	void Zamien(T& a, T& b);
public:

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
};

template<typename T>
void InsertionSort<T>::Zamien(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}