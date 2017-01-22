#include <SFML/Graphics.hpp>
#include "map.h"
#include "player.h"

int pozycja = 0;
using namespace std;


void add_sprite()
{
	Map map;

	sf::Texture startGame_blue;
	startGame_blue.loadFromFile("StartGame_blue.png");

	sf::Texture logo;
	logo.loadFromFile("logo.png");

	sf::Texture startGame_yellow;
	startGame_yellow.loadFromFile("StartGame_yellow.png");

	sf::Texture HighScore_blue;
	HighScore_blue.loadFromFile("HighScore_blue.png");

	sf::Texture HighScore_yellow;
	HighScore_yellow.loadFromFile("HighScore_yellow.png");

	sf::Texture EndGame_blue;
	EndGame_blue.loadFromFile("EndGame_blue.png");

	sf::Texture EndGame_yellow;
	EndGame_yellow.loadFromFile("EndGame_yellow.png");

	sf::Sprite sprajt, sprajt2, sprajt3, sprajt4, sprajt5, sprajt6, logoo;

	logoo.setTexture(logo);
	logoo.setPosition(300, 50);

	sprajt.setTexture(startGame_blue);
	sprajt.setPosition(400, 250);

	sprajt2.setTexture(startGame_yellow);
	sprajt2.setPosition(400, 250);

	sprajt3.setTexture(HighScore_blue);
	sprajt3.setPosition(400, 350);

	sprajt4.setTexture(HighScore_yellow);
	sprajt4.setPosition(400, 350);

	sprajt5.setTexture(EndGame_blue);
	sprajt5.setPosition(400, 450);

	sprajt6.setTexture(EndGame_yellow);
	sprajt6.setPosition(400, 450);

	sf::RenderWindow oknoAplikacji(sf::VideoMode(1200, 800, 32), "Pac-Man");
	while (oknoAplikacji.isOpen())
	{
		sf::Event zdarzenie;
		while (oknoAplikacji.pollEvent(zdarzenie))
		{
			oknoAplikacji.clear(sf::Color::Black);
			oknoAplikacji.draw(logoo);
			oknoAplikacji.draw(sprajt2);
			oknoAplikacji.draw(sprajt4);
			oknoAplikacji.draw(sprajt6);

			if (zdarzenie.type == sf::Event::Closed)
				oknoAplikacji.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down && pozycja >= -2)
			{
				if (pozycja == 0)
					oknoAplikacji.draw(sprajt);
				if (pozycja == -1)
					oknoAplikacji.draw(sprajt3);
				if (pozycja == -2)

					oknoAplikacji.draw(sprajt5);
				pozycja--;

				oknoAplikacji.display();
			}
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up && pozycja <= -2)
			{
				if (pozycja == -2)
					oknoAplikacji.draw(sprajt);
				if (pozycja == -3)
					oknoAplikacji.draw(sprajt3);
				pozycja++;

				oknoAplikacji.display();
			}
			if (pozycja == -3 && zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Return)
			{
				oknoAplikacji.close();
			}

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
			{
				oknoAplikacji.close();
			}

			if (pozycja == -1 && zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Return)
			{
				map.draw();
			}
		}
	}
}

int main()
{
	add_sprite();

	return 0;
}