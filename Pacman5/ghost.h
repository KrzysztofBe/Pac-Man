#ifndef __GHOST_H
#define __GHOST_H
class Map;
#include "map.h"

class Ghost
{
private:
	bool isDead;
public:
	Ghost();
	Ghost(int x, int y, char symbol);
	bool outsideLair;
	int startX, startY;
	void reset();
	void setGhostPosition(Map *map, Player *player);
	void movedFromLair();
	void setDead(bool deadStatus);
	bool getDead();
	int x;
	int y;
	char symbol;
};
#endif