#include "Ai.h"

int Ai::evaluate(Board board)
{
	int enemyMans = mansLeft(board, !_white).size();
	int enemyKings = kingsLeft(board, !_white).size();
	int allyMans = mansLeft(board, _white).size();
	int allyKings = kingsLeft(board, _white).size();
	if (enemyMans == 0 && enemyKings == 0)
		return 500;
	return static_cast<int>(10 * allyMans -  5 * enemyMans + 20 * allyKings - 15 * enemyKings);
}

Board Ai::checkBeatsAndBeat(Board& board, int x, int y)
{
	auto beats = checkBeats(board, x, y);
	if (beats.size() == 0)
	{
		return board;
	}
	//Niestety nie wpad³em na PROSTY pomys³ w jaki sposób zbijaæ kolejne pionki jeœli jest wiêcej ni¿ jedna mo¿liwoœæ.
	//W dodatku zwracac do tych mozliwosci osobne plansze.
	//Jesli jest wiecej niz jeden kierunek bicia to funkcja bêdzie wybierac pierwszy zaczynajac od lewego górnego rogu
	//i przechodz¹c po nich wed³ug ruchu wskazówek zegara.
	else
	{
		board.beat(x, y, beats[0].first, beats[0].second);
		return checkBeatsAndBeat(board, beats[0].first, beats[0].second);
	}
}

std::vector<Board> Ai::beatChildren(Board board, bool white)
{
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> beats;
	std::vector<Board> boards;
	auto mans = mansLeft(board, white);
	auto kings = kingsLeft(board, white);
	for (auto it = mans.begin(); it < mans.end(); ++it)
	{
		auto beat = checkBeats(board, (*it).first, (*it).second);
		if (beat.size() > 0)
		{
			for (auto itt = beat.begin(); itt < beat.end(); ++itt)
			{
				beats.push_back(std::make_pair(*it, *itt));
			}
		}
	}
	for (auto it = kings.begin(); it < kings.end(); ++it)
	{
		auto beat = checkBeats(board, (*it).first, (*it).second);
		if (beat.size() > 0)
		{
			for (auto itt = beat.begin(); itt < beat.end(); ++itt)
			{
				beats.push_back(std::make_pair(*it, *itt));
			}
		}
	}
	for (auto it = beats.begin(); it < beats.end(); ++it)
	{
		Board tempBoard(board);
		tempBoard.beat((*it).first.first, (*it).first.second, (*it).second.first, (*it).second.second);
		checkBeatsAndBeat(tempBoard, (*it).second.first, (*it).second.second);
		tempBoard.transformIntoKings();
		boards.push_back(tempBoard);
	}
	return boards;
}

std::vector<Board> Ai::moveChildren(Board board, bool white)
{
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> moves;
	std::vector<Board> boards;
	auto mans = mansLeft(board, white);
	auto kings = kingsLeft(board, white);
	for (auto it = mans.begin(); it < mans.end(); ++it)
	{
		auto move = availableMoves(board, (*it).first, (*it).second);
		if (move.size() > 0)
		{
			for (auto itt = move.begin(); itt < move.end(); ++itt)
			{
				moves.push_back(std::make_pair(*it, *itt));
			}
		}
	}
	for (auto it = kings.begin(); it < kings.end(); ++it)
	{
		auto move = availableMoves(board, (*it).first, (*it).second);
		if (move.size() > 0)
		{
			for (auto itt = move.begin(); itt < move.end(); ++itt)
			{
				moves.push_back(std::make_pair(*it, *itt));
			}
		}
	}
	for (auto it = moves.begin(); it < moves.end(); ++it)
	{
		Board tempBoard(board);
		tempBoard.move((*it).first.first, (*it).first.second, (*it).second.first, (*it).second.second);
		tempBoard.transformIntoKings();
		boards.push_back(tempBoard);
	}
	return boards;
}

int Ai::minimax(Board board, int depth, bool maximizingPlayer)
{
	if (depth == 0)
	{
		board.transformIntoKings();
		return evaluate(board);
	}
	if (maximizingPlayer)
	{
		int maxEval = -10000;
		auto beats = beatChildren(board, maximizingPlayer);
		if (beats.size() > 0)
		{
			for (auto it = beats.begin(); it < beats.end(); ++it)
			{
				int eval = minimax(*it, depth - 1, false);
				maxEval = std::max(maxEval, eval);
			}
			return maxEval;
		}
		else
		{
			auto moves = moveChildren(board, maximizingPlayer);
			for (auto it = moves.begin(); it < moves.end(); ++it)
			{
				int eval = minimax(*it, depth - 1, false);
				maxEval = std::max(maxEval, eval);
			}
			return maxEval;
		}
	}
	else
	{
		int minEval = +10000;
		auto beats = beatChildren(board, maximizingPlayer);
		if (beats.size() > 0)
		{
			for (auto it = beats.begin(); it < beats.end(); ++it)
			{
				int eval = minimax(*it, depth - 1, true);
				minEval = std::min(minEval, eval);
			}
			return minEval;
		}
		else
		{
			auto moves = moveChildren(board, maximizingPlayer);
			for (auto it = moves.begin(); it < moves.end(); ++it)
			{
				int eval = minimax(*it, depth - 1, true);
				minEval = std::min(minEval, eval);
			}
			return minEval;
		}
	}
}

void Ai::makeMove(Board& board)
{
	auto boardsWithBeat = beatChildren(board, _white);
	if(boardsWithBeat.size() > 0)
	{
		std::vector<int> minimaxValue;
		minimaxValue.resize(boardsWithBeat.size());
		for (unsigned int i = 0; i < boardsWithBeat.size(); ++i)
		{
			minimaxValue[i] = minimax(boardsWithBeat[i], 4, false);
		}
		int maxElementIndex = std::max_element(minimaxValue.begin(), minimaxValue.end()) - minimaxValue.begin();
		board = boardsWithBeat[maxElementIndex];
	}
	else
	{
		auto boardsWithMove = moveChildren(board, _white);
		std::vector<int> minimaxValue;
		minimaxValue.resize(boardsWithMove.size());
		for (unsigned int i = 0; i < boardsWithMove.size(); ++i)
		{
			minimaxValue[i] = minimax(boardsWithMove[i], 4, false);
		}
		int maxElementIndex = std::max_element(minimaxValue.begin(), minimaxValue.end()) - minimaxValue.begin();
		board = boardsWithMove[maxElementIndex];
	}
}

