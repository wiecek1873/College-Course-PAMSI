#include "Board.h"

Board::Board() : _board(8,8)
{
	int rows[] = { 0,1,2,5,6,7 };
	for (int row : rows)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (row < 3)
			{
				if (row % 2 == 0)
					_board(row, ++i) = 2;
				else
					_board(row, i++) = 2;
			}
			else
			{
				if (row % 2 == 0)
					_board(row, ++i) = 1;
				else
					_board(row, i++) = 1;
			}
		}
	}
}

bool Board::gameIsFinished()
{
	int white = 0;
	int black = 0;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; j++)
		{
			if (_board(i, j) == 1 || _board(i, j) == 3)
				++white;
			if (_board(i, j) == 2 || _board(i, j) == 4)
				++black;
		}
	}

	if (white == 0 || black == 0)
		return true;
	else
		return false;
}

void Board::transformIntoKings()
{
	for (int i = 0; i < 8; ++i)
	{
		if (_board(0, i) == 1)
			_board(0, i) = 3;
		if (_board(7, i) == 2)
			_board(7, i) = 4;
	}
}

void Board::print()
{
	std::cout << "  0 1 2 3 4 5 6 7" << std::endl;
	for (int i = 0; i < 8; ++i)
	{
		std::cout << i << " ";
		for (int j = 0; j < 8; ++j)
		{
			if (_board(i, j) == 3)
				std::cout << "W" << " ";
			else if (_board(i, j) == 4)
				std::cout << "B" << " ";
			else if (i % 2 == 0 && j % 2 == 0)
				std::cout << "  ";
			else if (i % 2 == 1 && j % 2 == 1)
				std::cout << "  ";
			else if (_board(i, j) == 0)
				std::cout << "_ ";
			else
				std::cout << _board(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

void Board::move(int x, int y, int toX, int toY)
{
	if (_board(x, y) == 0)
		throw std::exception("Field is empty");
	if (toX < 0 || 7 < toX || toY < 0 || 7 < toY)
		throw std::exception("Out of board bro");
	if (_board(toX, toY) != 0)
		throw std::exception("Field isn't empty");

	std::swap(_board(x, y), _board(toX, toY));
}

void Board::beat(int x, int y, int toX, int toY)
{
	if (_board(x, y) == 0)
		throw std::exception("Field is empty");
	if (toX < 0 || 7 < toX || toY < 0 || 7 < toY)
		throw std::exception("Out of board bro");
	if (_board(toX, toY) != 0)
		throw std::exception("Field isn't empty");

	bool white;
	if (_board(x, y) == 1 || _board(x, y) == 3)
		white = true;
	if (_board(x, y) == 2 || _board(x, y) == 4)
		white = false;

	int itX = x;
	int itY = y;
	while (itX != toX && itY != toY)
	{
		if (x < toX)
			++itX;
		else
			--itX;

		if (y < toY)
			++itY;
		else
			--itY;

		if (white && (_board(itX, itY) == 2 || _board(itX, itY) == 4))
			_board(itX, itY) = 0;
		else if (!white && (_board(itX, itY) == 1 || _board(itX, itY) == 3))
			_board(itX, itY) = 0;
	}
	std::swap(_board(x, y), _board(toX, toY));
}