#include "Board.h"
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
int main()
{
	Board board;
	Player player1(true);
	Player player2(false);
	board.move(5, 2, 4, 3);
	board.move(2, 5, 3, 4);
	board._board(4, 3) = 3;
	board._board(1, 0) = 0;
	board._board(6, 5) = 0;
	board.move(5, 6, 4, 5);
	board.move(3, 4, 5, 6);
	board.transformIntoKings();
	board.print();

	auto xd = player1.checkBeats(board, 5,6);
	for (auto it = xd.begin(); it != xd.end(); ++it)
	{
		std::cout << "Mo¿liwe ruchy:" << (*it).first << " " << (*it).second << std::endl;
	}
	//system("CLS");


}

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