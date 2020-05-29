#include "Board.h"
#include "Player.h"
#include "Ai.h"

int main()
{
	Board board;
	Ai player1(true);
	Player player2(false);

	while (!board.gameIsFinished())
	{
		player1.makeMove(board);
		board.transformIntoKings();
		board.print();

		player2.move(board);
		board.transformIntoKings();
		system("CLS");
	}
	std::cout << "Game is finished!" << std::endl;
}

//Zostawilem kod ktory mial byc odpowiedzialny za wersje graficzna na wypadek gdybym chcial skonczyc ja w przyszlosci
/*
	sf::RenderWindow window(sf::VideoMode(800, 800), "Checkers");

	sf::Sprite sprite;
	sf::Texture whiteMan;
	whiteMan.loadFromFile("graphics/whiteMan.png");
	sprite.setTexture(whiteMan);

	bool isMove = false;
	float dx = 0, dy = 0;
	while (window.isOpen())
	{
		sf::Vector2i pos = sf::Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
					if (sprite.getGlobalBounds().contains(static_cast<int>(pos.x), static_cast<int>(pos.y)))
					{
						isMove = true;
						dx = pos.x - sprite.getPosition().x;
						dy = pos.y - sprite.getPosition().y;
					}
			if (event.type == sf::Event::MouseButtonReleased)
				if (event.mouseButton.button == sf::Mouse::Left)
					isMove = false;
		}
		if (isMove)
			sprite.setPosition(pos.x - dx, pos.y - dy);
		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}
*/