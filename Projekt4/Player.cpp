#include "Player.h"

Player::Player(bool white)
{
	_white = white;
}

std::pair<int,int> Player::choseMan(Board board)
{
	std::vector<std::pair<int, int>> mansLeft = this->mansLeft(board);
	std::vector<std::pair<int, int>> availableMans;
	for (auto it = mansLeft.begin(); it != mansLeft.end(); ++it)
	{
		if (this->availableMoves(board,(*it).first, (*it).second).size() != 0)
			availableMans.push_back(*it);
	}
	bool rightChoice = false;
	int row;
	int col;
	do
	{
		std::cout << "Which man u like to move?" << std::endl;
		std::cout << "Man at: ";
		do
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Wrong input!" << std::endl;
			}
			std::cin >> row;
			std::cin >> col;
		} while (std::cin.fail());

		if (std::find_if(availableMans.begin(), availableMans.end(),
			[row, col](const std::pair<int, int>& pair) {return pair == std::make_pair(row, col);})
			!= availableMans.end())
			rightChoice = true;
		else
			std::cout << "Wrong choice!" << std::endl;
	} while (!rightChoice);
	return std::make_pair(row, col);
}

void Player::move(Board& board, std::pair<int, int> whichOne)
{
	auto availableMoves = this->availableMoves(board,whichOne.first, whichOne.second);
	auto availableBeats = this->checkBeats(board,whichOne.first, whichOne.second);
	int row;
	int col;
	bool rightMove = false;
	bool rightBeat = false;
	do
	{
		std::cout << "Where you like to move?" << std::endl;
		std::cout << "Move to: ";
		do
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Wrong input!" << std::endl;
			}
			std::cin >> row;
			std::cin >> col;
		} while (std::cin.fail());

		if (std::find_if(availableMoves.begin(), availableMoves.end(),
			[row, col](const std::pair<int, int>& pair) {return pair == std::make_pair(row, col);})
			!= availableMoves.end())
			rightMove = true;
		else
			rightMove = false;

		if (std::find_if(availableBeats.begin(), availableBeats.end(),
			[row, col](const std::pair<int, int>& pair) {return pair == std::make_pair(row, col);})
			!= availableBeats.end())
			rightBeat = true;
		else
			rightBeat = false;

		if (!rightMove && !rightBeat)
			std::cout << "Can't move here!" << std::endl;

	} while (!rightMove && !rightBeat);
	if(rightMove)
		board.move(whichOne.first, whichOne.second, row, col);
	if (rightBeat)
		board.beat(whichOne.first, whichOne.second, row, col);
}

std::vector<std::pair<int, int>> Player::mansLeft(Board board)
{
	std::vector<std::pair<int, int>> mansLeft;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (_white && board._board(i, j) == 1)
				mansLeft.push_back(std::make_pair(i, j));
			if (!_white && board._board(i, j) == 2)
				mansLeft.push_back(std::make_pair(i, j));
		}
	}
	return mansLeft;
}

std::vector<std::pair<int, int>> Player::kingsLeft(Board board)
{
	std::vector<std::pair<int, int>> kingsLeft;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (_white && board._board(i, j) == 3)
				kingsLeft.push_back(std::make_pair(i, j));
			if (!_white && board._board(i, j) == 4)
				kingsLeft.push_back(std::make_pair(i, j));
		}
	}
	return kingsLeft;
}

std::vector<std::pair<int, int>> Player::availableMoves(Board board, int x, int y)
{
	std::vector<std::pair<int, int>> moves;
	int directionStart = 0; //0 - up left corner, 1 - up right corner etc.
	int directionEnd = 0; //4 - check every direction
	int range = 0; //2 - range for normal mans, 8 - range for kings
	if (board._board(x, y) == 1)
	{
		directionStart = 0;
		directionEnd = 2;
		range = 2;
	}
	if(board._board(x,y) == 2)
	{
		directionStart = 2;
		directionEnd = 4;
		range = 2;
	}
	if (board._board(x, y) == 3 || board._board(x, y) == 4)
	{
		directionStart = 0;
		directionEnd = 4;
		range = 8;
	}
	int multipilerX[] = { -1,-1,1,1 };
	int multipilerY[] = { -1,1,-1,1 };
	bool obstacleFlag[] = { false,false,false,false };
	for (int i = 1; i < range; ++i)
	{
		for (int j = directionStart; j < directionEnd; ++j)
		{
			if (!obstacleFlag[j] &&
				0 <= x + multipilerX[j] * i && x + multipilerX[j] * i < 8 &&
				0 <= y + multipilerY[j] * i && y + multipilerY[j] * i < 8)
				if(board._board(x + multipilerX[j] * i, y + multipilerY[j] * i) != 0)
					obstacleFlag[j] = true;
			if (!obstacleFlag[j])
				moves.push_back(std::make_pair(x + multipilerX[j] * i, y + multipilerY[j] * i));
		}
	}
	return moves;
}

std::vector<std::pair<int, int>> Player::checkBeats(Board board, int x, int y)
{
	std::vector<std::pair<int, int>> beats;
	int directionStart = 0; //0 - up left corner, 1 - up right corner etc.
	int directionEnd = 4; //4 - check every direction
	int range = 0; //2 - range for normal mans, 8 - range for kings

	int allyColor[2];
	int enemyColor[2];
	if (board._board(x, y) == 1)
	{
		allyColor[0] = 1; allyColor[1] = 3;
		enemyColor[0] = 2; enemyColor[1] = 4;
		range = 2;
	}
	if (board._board(x, y) == 2)
	{
		allyColor[0] = 2; allyColor[1] = 4;
		enemyColor[0] = 1; enemyColor[1] = 3;
		range = 2;
	}
	if (board._board(x, y) == 3)
	{
		allyColor[0] = 1; allyColor[1] = 3;
		enemyColor[0] = 2; enemyColor[1] = 4;
		range = 8;
	}
	if (board._board(x, y) == 4)
	{
		allyColor[0] = 2; allyColor[1] = 4;
		enemyColor[0] = 1; enemyColor[1] = 3;
		range = 8;
	}
	int multipilerX[] = { -1,-1,1,1 };
	int multipilerY[] = { -1,1,-1,1 };
	bool obstacleFlag[] = { false,false,false,false };
	for (int i = 1; i < range; ++i)
	{
		for (int j = directionStart; j < directionEnd; ++j)
		{
			if (!obstacleFlag[j] &&
				0 <= x + multipilerX[j] * i && x + multipilerX[j] * i < 8 &&
				0 <= y + multipilerY[j] * i && y + multipilerY[j] * i < 8)
			{
				if (board._board(x + multipilerX[j] * i, y + multipilerY[j] * i) == allyColor[0] ||
					board._board(x + multipilerX[j] * i, y + multipilerY[j] * i) == allyColor[1])
					obstacleFlag[j] = true;
				else if (board._board(x + multipilerX[j] * i, y + multipilerY[j] * i) == enemyColor[0] ||
					board._board(x + multipilerX[j] * i, y + multipilerY[j] * i) == enemyColor[1])
				{
					if (0 <= x + multipilerX[j] * (i + 1) && x + multipilerX[j] * (i + 1) < 8 &&
						0 <= y + multipilerY[j] * (i + 1) && y + multipilerY[j] * (i + 1) < 8 &&
						board._board(x + multipilerX[j] * (i + 1), y + multipilerY[j] * (i + 1)) == 0)
					beats.push_back(std::make_pair(x + multipilerX[j] * (i + 1), y + multipilerY[j] * (i + 1)));
				}
			}
		}
	}
	return beats;
}

std::vector<std::pair<int, int>> Player::checkKingBeats(Board board,int x, int y)
{
	std::vector<std::pair<int, int>> xd;

	return xd;
}