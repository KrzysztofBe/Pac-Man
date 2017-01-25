#ifndef __GHOST_H
#define __GHOST_H
class Map;
#include "map.h"
#include <SFML/Graphics.hpp>

class Ghost
{
private:
	bool isDead;
public:
	Ghost();
	Ghost(int x, int y, char symbol, const char *ghostFile);
	bool outsideLair;
	sf::Sprite *newSymbol;
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