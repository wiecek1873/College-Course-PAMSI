#pragma once
#include <iostream>
#include <vector>

class Board
{
	class Matrix
	{
		std::vector<int> vector;
		int numberOfColumns;
	public:
		Matrix(int n, int m, int defaultValue = 0) : numberOfColumns{ n } { vector.resize(n * m, defaultValue); }
		int& operator()(int x, int y) { return vector[x * numberOfColumns + y]; }
	};
public:
	Matrix _board;
	Board();

	//Sprawdza czy gra zostala zakonczona tj. na planszy sa tylko pionki jednego koloru
	bool gameIsFinished();
	//Zamienia piony ktore przeszly na krance planszy w damki
	void transformIntoKings();
	//Drukuje aktualny stan planszy na konsoli
	void print();

	//Wykonuje ruch pionem z (x,y) na (toX,toY)
	void move(int x, int y, int toX, int toY);
	//Wykonuje ruch pionem z (x,y) na (toX,toY) i usuwa przeskoczone piony przeciwnika
	void beat(int x, int y, int toX, int toY);
};

