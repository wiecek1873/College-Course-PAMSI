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

	bool gameIsFinished();
	void transformIntoKings();
	void print();

	void move(int x, int y, int toX, int toY);
	void beat(int x, int y, int toX, int toY);


};

