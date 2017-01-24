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
	Ghost(int x, int y, char symbol);
	bool outsideLair;
	sf::Sprite *newSymbol1;
	sf::Sprite *newSymbol2;
	sf::Sprite *newSymbol3;
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