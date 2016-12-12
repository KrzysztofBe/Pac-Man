#ifndef __GAME_H
#define __GAME_H
#include "map.h"
#include "player.h"
#include "ghost.h"
#include "input.h"

class Game
{
public:
	Game();
	Ghost ghost;
	Map *map;
	Player *player;
	void start();
	bool mainLoop;
	void stop();
	vector<Ghost> ghosts;
	void addGhost(int x, int y, char symbol);

};

#endif