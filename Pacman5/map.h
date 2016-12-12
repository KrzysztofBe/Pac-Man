#ifndef __MAP_H
#define __MAP_H
#include <iostream>
#include <vector>
class Player;
class Ghost;
#include "ghost.h"
#include "player.h"
#include <fstream>
using namespace std;

class Map
{
public:
	Map();
	static const int map_size_y = 31;
	static const int map_size_x = 30;
	char mapBoard[map_size_y][map_size_x];
	bool isPointAccessible(int x, int y, Ghost *ghost);
	bool isPointAccessible(int x, int y, Player *player);
	float euclideanDistance(int x1, int y1, int x2, int y2);
	char getPoint(int x, int y);
	void setPoint(int x, int y, char symbol);
	void draw(vector<Ghost> ghosts, Player player);
};
#endif