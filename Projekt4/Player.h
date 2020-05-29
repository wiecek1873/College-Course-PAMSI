#pragma once
#include "Board.h"
#include <algorithm>

class Player
{
protected:
	//Okresla jakim kolorem pionkow gracz dysponuje.
	bool _white;
public:
	//Metoda stanowi interfejs dla uzytkownika i zwraca wspolrzedne wybranego przez niego pionu.
	std::pair<int, int> choseMan(Board board);
	//Metoda stanowi interfejs dla uzytkownika. Pozwala wybrac pion i wykonac nim ruch lub bicie.
	void move(Board& board);
	//Dzieki tej metodzie mozliwe jest, zeby gracz wykonywal po sobie kolejne bicia.
	std::pair<int, int> beatAgain(Board& board);

	//Konstruktor tworzy obiekt klasy Player i przypisuje mu jego kolor.
	Player(bool white);
	//Sprawdza ile pozostalo pionow o okreslonym kolorze.
	std::vector<std::pair<int, int>> mansLeft(Board board, bool white);
	//Sprawdza ile pozostalo damek o okreslonym kolorze.
	std::vector<std::pair<int, int>> kingsLeft(Board board, bool white);
	//Sprawdza mozliwe ruchy dla piona o wspolrzednych (x,y).
	std::vector<std::pair<int, int>> availableMoves(Board board, int x, int y);
	//Sprawdza mozliwe bicia dla piona o wspolrzednych (x,y).
	std::vector<std::pair<int, int>> checkBeats(Board board, int x, int y);
};

