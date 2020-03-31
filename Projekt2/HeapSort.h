#pragma once

template <typename T>
class HeapSort
{
	void Zamien(T& a, T& b);
public:
	void TworzKopiec(T* tablica, int rozmiar, int szczyt);
	void heapSort(T* tablica, int pierwszyIndeks, int ostatniIndeks);
};

template<typename T>
void HeapSort<T>::Zamien(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void HeapSort<T>::TworzKopiec(T* tablica, int rozmiar, int szczyt)
{
	int najwiekszy = szczyt;
	int lewy = 2 * szczyt + 1;
	int prawy = 2 * szczyt + 2;

	if (lewy < rozmiar && tablica[lewy] > tablica[najwiekszy])
	{
		najwiekszy = lewy;
	}
	if (prawy < rozmiar && tablica[prawy] > tablica[najwiekszy])
	{
		najwiekszy = prawy;
	}
	if (najwiekszy != szczyt)
	{
		Zamien(tablica[szczyt], tablica[najwiekszy]);
		TworzKopiec(tablica, rozmiar, najwiekszy);
	}
}

template <typename T>
void HeapSort<T>::heapSort(T* tablica, int pierwszyIndeks, int ostatniIndeks) {
	++ostatniIndeks;

	T* temp = new T[ostatniIndeks - pierwszyIndeks];
	for (int i = 0; i < ostatniIndeks - pierwszyIndeks; i++) {
		temp[i] = tablica[i + pierwszyIndeks];
	}

	for (int i = (ostatniIndeks - pierwszyIndeks) / 2 - 1; i >= 0; --i) {
		TworzKopiec(temp, (ostatniIndeks - pierwszyIndeks), i);
	}
	for (int i = (ostatniIndeks - pierwszyIndeks) - 1; i >= 0; --i) {
		Zamien(temp[0], temp[i]);
		TworzKopiec(temp, i, 0);
	}

	for (int i = 0; i < ostatniIndeks - pierwszyIndeks; i++) {
		tablica[i + pierwszyIndeks] = temp[i];
	}
	delete[] temp;
}