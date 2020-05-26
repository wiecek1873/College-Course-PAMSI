#pragma once
#include "Board.h"
#include <algorithm>

class Player
{

protected:
	bool _white;
public:
	Player(bool white);
	std::pair<int, int> choseMan(Board board);
	void move(Board& board, std::pair<int, int> whichOne);

	std::vector<std::pair<int, int>> mansLeft(Board board);
	std::vector<std::pair<int, int>> kingsLeft(Board board);
	std::vector<std::pair<int, int>> availableMoves(Board board, int x, int y);
	std::vector<std::pair<int, int>> checkBeats(Board board, int x, int y);
	std::vector<std::pair<int, int>> checkKingBeats(Board board, int x, int y);
};

