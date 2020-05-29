#include "Board.h"
#include "Player.h"
#pragma once
class Ai : public Player
{
public:
	//Konstruktor tworzy obiekt klasy Ai i przypisuje mu kolor
	Ai(bool white) : Player(white) {};
	//Ocenia wartosc danej planszy i zwraca ja
	int evaluate(Board board);

	//Rekurencyjnie zbija wszystkie napotkane i mozliwe do zbicia pionki przeciwnika. Zwraca plansze kiedy wykorzysta mozliwe ruchy.
	Board checkBeatsAndBeat(Board& board, int x, int y);
	//Rozpatruje mozliwe bicia dla wszystkich pionkow i zwraca wektor plansz po wykonaniu tych bic.
	std::vector<Board> beatChildren(Board board, bool white);
	//Rozpatruje mozliwe ruchy dla wszystkich pionkow i zwraca wektor plansz po wykonaniu tych ruchow.
	std::vector<Board> moveChildren(Board board, bool white);
	//Algorytm minimax ktory zwraca wartosc oceny najlepszej sytuacji na planszy na "depth" krokow do przodu.
	//W programie glebokosc rekurencji jest ustawiona na 4 poniewaz dla takiej wartosci udalo sie osiagnac odpowiedni czas oczekiwania.
	int minimax(Board board, int depth, bool maximizingPlayer);
	//Glowna metoda odpowiadajaca za ruch bota.
	//Sprawdza mozliwe ruchy dla aktualnej sytuacji i zaczyna budowac drzewo dla kazdego z tych ruchow.
	//Nastepnie wybiera ruch najlepiej punktowany i wykonuje go edytujac "board"
	void makeMove(Board& board);
};

