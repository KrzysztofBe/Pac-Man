#include <iostream>
#include <vector>
#include "windows.h"
#include "map.h"
#include "ghost.h"
#include "player.h"
////////////////////////////////////
using namespace std;
char Map::mapBoard[Map::map_size_y][Map::map_size_x] = {
	"______________________________",
	"||............||............||",
	"||.____._____.||._____.____.||",
	"||0|  |.|   |.||.|   |.|  |0||",
	"||.|__|.|___|.||.|___|.|__|.||",
	"||..........................||",
	"||.____.||.________.||.____.||",
	"||.|__|.||.|______|.||.|__|.||",
	"||......||....||....||......||",
	"||_____.||___ || ___||._____||",
	"|     |.|___| || |___|.|     |",
	"|     |.||          ||.|     |",
	"|     |.|| ___  ___ ||.|     |",
	"|_____|.|| |      | ||.|_____|",
	"<.......   |      |   .......>",
	"_______.|| |      | ||._______",
	"|     |.|| |______| ||.|     |",
	"|     |.||          ||.|     |",
	"|     |.|| ________ ||.|     |",
	"|_____|.|| |______| ||.|_____|",
	"||............||............||",
	"||.____._____.||._____.____.||",
	"||.|__|.|___|.||.|___|.|__|.||",
	"||0..||................||..0||",
	"||__.||.__.________.||.||.__||",
	"|__|.||.||.|______|.||.||.|_||",
	"||......||....||....||......||",
	"||.__________.||.__________.||",
	"||.|________|.||.|________|.||",
	"||..........................||",
	"||__________________________||"
};


bool Map::isPointAccessible(int x, int y)
{
	char point = this->mapBoard[y][x];

	if (point == '.' || point == ' ' || point == '0')
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