#include <SFML/Graphics.hpp>
#include "map.h"

int pozycja = 0;
using namespace std;

const int spriteSizeX = 47;
const int spriteSizeY = 47;

sf::Sprite *spriteMap[Map::map_size_y][Map::map_size_x];

void mapaa()
{

	sf::Texture podloga;
	podloga.loadFromFile("podlogaa.png");

	sf::Texture prawy_gorny_rog;
	prawy_gorny_rog.loadFromFile("prawy_gorny_rog.png");

	sf::Texture prawy_dolny_rog;
	prawy_dolny_rog.loadFromFile("prawy_dolny_rog.png");

	sf::Texture lewy_dolny_rog;
	lewy_dolny_rog.loadFromFile("lewy_dolny_rog.png");

	sf::Texture lewy_gorny_rog;
	lewy_gorny_rog.loadFromFile("lewy_gorny_rog.png");

	sf::Texture sciana;
	sciana.loadFromFile("sciana.png");

	sf::Texture kulka;
	kulka.loadFromFile("kulka.png");


	sf::Sprite sp_podloga, sp_pg, sp_pd, sp_lg, sp_ld, sp_sciana, sp_kulka, tekstura;
	sp_podloga.setTexture(podloga);
	sp_sciana.setTexture(sciana);
	sp_pg.setTexture(prawy_gorny_rog);
	sp_pd.setTexture(prawy_dolny_rog);
	sp_ld.setTexture(lewy_dolny_rog);
	sp_lg.setTexture(lewy_gorny_rog);
	sp_kulka.setTexture(kulka);
	
	int licznik = 1;

	sf::RenderWindow oknoAplikacji(sf::VideoMode(1200, 900, 32), "Pac-Man");
	while (oknoAplikacji.isOpen())
	{
		sf::Event zdarzenie;
		while (oknoAplikacji.pollEvent(zdarzenie))
		{
			oknoAplikacji.display();

			if (zdarzenie.type == sf::Event::Closed)
				oknoAplikacji.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
			{
				oknoAplikacji.close();
			}

			Map map;

			for (int i = 0; i < Map::map_size_y; i++) {
				for (int j = 0; j < Map::map_size_x; j++) {
					sf::Sprite *sprite = new sf::Sprite();
					sf::Texture *texture = new sf::Texture();
					switch (map.mapBoard[i][j]) {
					case '|':
						texture->loadFromFile("sciana.png");
						break;
					case '.':
						texture->loadFromFile("kulka.png");
						break;
					default:
						texture->loadFromFile("podlogaa.png");
						break;
					}
					sprite->setTexture(*texture);
					spriteMap[j][i] = sprite;
				}
			}

			for (int i = 0; i < Map::map_size_y; i++) {
				for (int j = 0; j < Map::map_size_x; j++) {
					spriteMap[j][i]->setPosition(j * 47, i * 47);
					oknoAplikacji.draw(spriteMap[j][i]);
				}
			}

		}
	}
			

}

void add_sprite()
{
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
				mapaa();
			}
		}
	}
}

int main()
{
	add_sprite();

	return 0;
}