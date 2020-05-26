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
	std::vector<std::pair<int, int>> surroundings;
	if (board._board(x, y) == 1 || board._board(x, y) == 2)
	{
		surroundings.push_back(std::make_pair(x - 1, y - 1));
		surroundings.push_back(std::make_pair(x - 1, y + 1));
		surroundings.push_back(std::make_pair(x + 1, y - 1));
		surroundings.push_back(std::make_pair(x + 1, y + 1));
	}
	if (board._board(x, y) == 3 || board._board(x, y) == 4)
	{
		bool obstacleFlag[] = { false,false,false,false };
		for (int i = 1; i < 8; ++i)
		{
			if (0 <= x - i && x - i < 8 &&
				0 <= y - i && y - i < 8 &&
				board._board(x - i, y - i) != 0)
				obstacleFlag[0] = true;
			if (!obstacleFlag[0])
				surroundings.push_back(std::make_pair(x - i, y - i));

			if (0 <= x - i && x - i < 8 &&
				0 <= y + i && y + i < 8 &&
				board._board(x - i, y + i) != 0)
				obstacleFlag[1] = true;
			if (!obstacleFlag[1])
				surroundings.push_back(std::make_pair(x - i, y + i));

			if (0 <= x + i && x + i < 8 &&
				0 <= y - i && y - i < 8 &&
				board._board(x + i, y + i) != 0)
				obstacleFlag[2] = true;
			if (!obstacleFlag[2])
				surroundings.push_back(std::make_pair(x + i, y - i));

			if (0 <= x + i && x + i < 8 &&
				0 <= y + i && y + i < 8 &&
				board._board(x + i, y + i) != 0)
				obstacleFlag[3] = true;
			if (!obstacleFlag[3])
				surroundings.push_back(std::make_pair(x + i, y + i));
		}
	}
	for (auto it = surroundings.begin(); it != surroundings.end(); ++it)
	{
		if (0 <= (*it).first && (*it).first < 8 &&
			0 <= (*it).second && (*it).second < 8 &&
			board._board((*it).first, (*it).second) == 0)
			moves.push_back(*it);
	}
	return moves;
}

std::vector<std::pair<int, int>> Player::checkBeats(Board board, int x, int y)
{
	bool enemyColor = !_white;

	std::vector<std::pair<int, int>> moves;
	std::vector<std::pair<int, int>> surroundings;
	surroundings.push_back(std::make_pair(x - 1, y - 1));
	surroundings.push_back(std::make_pair(x - 1, y + 1));
	surroundings.push_back(std::make_pair(x + 1, y - 1));
	surroundings.push_back(std::make_pair(x + 1, y + 1));
	for (auto it = surroundings.begin(); it != surroundings.end(); ++it)
	{
		if (0 <= (*it).first && (*it).first < 8 &&
			0 <= (*it).second && (*it).second < 8 &&
			board._board((*it).first, (*it).second) == enemyColor)
		{
			int possiblePlaceX = 2 * (*it).first - x;
			int possiblePlaceY = 2 * (*it).second - y;
			if (0 <= possiblePlaceX && possiblePlaceX < 8 &&
				0 <= possiblePlaceY && possiblePlaceY < 8 &&
				board._board(possiblePlaceX, possiblePlaceY) == 0)
				moves.push_back(std::make_pair(2 * (*it).first - x, 2 * (*it).second - y));
		}
	}
	return moves;
}

std::vector<std::pair<int, int>> Player::checkKingBeats(Board board,int x, int y)
{
	int enemyColor[] = { 0,0 };
	if (board._board(x, y) == 0)
		throw std::exception("No man found");
	if (board._board(x, y) == 3)
	{
		enemyColor[0] = 2;
		enemyColor[1] = 4;
	}
	if (board._board(x, y) == 4)
	{
		enemyColor[0] = 1;
		enemyColor[1] = 3;
	}
	std::vector<std::pair<int, int>> moves;
	bool obstacleFlag[] = { false,false,false,false };


	return moves;
}