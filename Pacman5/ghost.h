#ifndef __GHOST_H
#define __GHOST_H
class Map;
#include "map.h"

class Ghost
{
public:
	Ghost();
	Ghost(int x, int y, char symbol);
	void setGhostPosition(Map *map, Ghost ghost);
	bool movedFromLair();
	bool eaten(Ghost ghost, Player player);
	bool isDead(Ghost ghost);
	int x;
	int y;
	char symbol;
};
#endif