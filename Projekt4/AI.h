#include "Board.h"
#include "Player.h"
#pragma once
class Ai : public Player
{
public:
	Ai(bool white) : Player(white) {};
	int evaluate(Board board);
	Board checkBeatsAndBeat(Board& board, int x, int y);
	std::vector<Board> beatChilds(Board board, bool white);
	std::vector<Board> moveChilds(Board board, bool white);
	int minimax(Board board, int depth, bool maximizingPlayer);
	void makeMove(Board& board);
};

