#include <iostream>
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

bool Map::isPointAccessible(int x, int y, Ghost ghost) {
	char point = this->mapBoard[y][x];

	if (point == '.' || point == ' ' || point == '0' || point == '<' || point == '>')
		return true;
	else if (point == '+' && ghost.movedFromLair)
		return false;
	else if (point == '+' && ghost.isDead)
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

void Map::draw(vector<Ghost> ghosts, Player player)
{
	system("cls");
	for (int y = 0; y < Map::map_size_y; y++) {
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
	cout << "Score: " << player.score;
	Sleep(150);
}