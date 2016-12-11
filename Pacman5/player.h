#ifndef __PLAYER_H
#define __PLAYER_H
class Map;
#include "map.h"
#include "input.h"

class Player
{
public:
	Player();
	int x, y;
	char symbol;
	int score;
	void getPlayerInput();
	bool bonus(Player player);
	void setPlayerPosition(Map *map);
	Input input, oldInput;
};
#endif