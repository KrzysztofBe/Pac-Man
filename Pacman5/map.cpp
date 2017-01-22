#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include "windows.h"
#include "map.h"
#include "ghost.h"
#include "player.h"
using namespace std;

Map::Map()
{
	ifstream file;
	string row;
	int i = 0;
	file.open("map.txt");
	if (!file.good())
		throw "Map file cannot be loaded!";

	while (getline(file, row))
	{
		for (int j = 0; j < row.size(); ++j) {
			this->mapBoard[i][j] = row[j];
		}
		i++;
	}
	//row.size() zwraca dlugosc lancucha znakow
	//w zmiennej "j" trzymamy aktualna pozycje
}


float Map::euclideanDistance(int x1, int y1, int x2, int y2)
{
	float wynik;
	wynik = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	
	return wynik;
}

bool Map::isPointAccessible(int x, int y, Ghost *ghost) {
	char point = this->mapBoard[y][x];

	if (point == '.' || point == ' ' || point == '0' || point == '<' || point == '>')
		return true;
	else if ((point == '+') && (!ghost->outsideLair))
		return true;
	else if (point == '+' && ghost->getDead())
		return true;
	else
		return false;
}

bool Map::isPointAccessible(int x, int y, Player *player) {
	char point = this->mapBoard[y][x];

	if (point == '.' || point == ' ' || point == '0' || point == '<' || point == '>')
		return true;
	else
		return false;
}


char Map::getPoint(int x, int y)
{
	char point = this->mapBoard[y][x];
	return point;
}

void Map::setPoint(int x, int y, char symbol)
{
	this->mapBoard[y][x] = symbol;
}

void Map::draw(vector<Ghost>ghosts, Player player)
{

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
					case '.':
						texture->loadFromFile("kulka.png");
						break;
					case '<':
						texture->loadFromFile("kulka.png");
						break;
					case '>':
						texture->loadFromFile("kulka.png");
						break;
					case '1':
						texture->loadFromFile("lewy_gorny_rog.png");
						break;
					case '2':
						texture->loadFromFile("prawy_gorny_rog.png");
						break;
					case '3':
						texture->loadFromFile("lewy_dolny_rog.png");
						break;
					case '4':
						texture->loadFromFile("prawy_dolny_rog.png");
						break;
					case '5':
						texture->loadFromFile("podlogaa.png");
						break;
					case '6':
						texture->loadFromFile("sciana.png");
						break;
					case '7':
						texture->loadFromFile("wieksza kulka.png");
						break;
					case '!':
						texture->loadFromFile("lewy_gorny_rog_polowa.png");
						break;
					case '@':
						texture->loadFromFile("prawy_gorny_rog_polowa.png");
						break;
					case '$':
						texture->loadFromFile("prawy_dolny_rog_polowa.png");
						break;
					case '#':
						texture->loadFromFile("lewy_dolny_rog_polowa.png");
						break;
					case '%':
						texture->loadFromFile("podlogaa.png");
						break;
					case '^':
						texture->loadFromFile("sciana.png");
						break;

					default:
						texture->loadFromFile("nic.png");
						break;
					}
					sprite->setTexture(*texture);
					spriteMap[j][i] = sprite;
				}
			}

			for (int i = 0; i < Map::map_size_y; i++) {
				for (int j = 0; j < Map::map_size_x; j++) {
					spriteMap[j][i]->setPosition(j * 27, i * 27);
					oknoAplikacji.draw(*spriteMap[j][i]);
				}
			}

		}
	}
}

	/*for (int y = 0; y < Map::map_size_y; y++) {
		for (int x = 0; x < Map::map_size_x; x++) {
			if ((player.x == x) && (player.y == y)) {
				cout << player.symbol;
			}
			else {
				bool ghostDrawn = false;
				for (vector<Ghost>::iterator it = ghosts.begin(); it != ghosts.end(); ++it) {
					if (it->x == x && it->y == y && !ghostDrawn)
					{
						ghostDrawn = true;
						cout << it->symbol;
					}
				}
				if (!ghostDrawn)
				{
					cout << this->getPoint(x, y);
				}
			}
		}
		cout << endl;
	}
	cout << "Score: " << player.score;*/