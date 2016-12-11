#include <math.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include "ghost.h"

Ghost::Ghost()
{

}
Ghost::Ghost(int x, int y, char symbol)
{
	this->x = x;
	this->y = y;
	this->symbol = symbol;
}

void Ghost::setGhostPosition(Map *map, Ghost ghost) {
	int x = this->x;
	int y = this->y;
	switch (rand() % 4) {
	case 0:
		x += 1;
		break;
	case 1:
		x -= 1;
		break;
	case 2:
		y += 1;
		break;
	case 3:
		y -= 1;
		break;
	}

	if (map->isPointAccessible(x, y, ghost)) {
		this->x = x;
		this->y = y;
	}
}

bool Ghost::movedFromLair(Ghost ghost)
{
	if ((ghost.x == 13 && ghost.y == 14) || (ghost.x == 14 && ghost.y == 15) || (ghost.x == 15 && ghost.y == 14))
		return false;

	else if ((ghost.x == 15 && ghost.y == 11) || (ghost.x == 16 && ghost.y == 11))
		return true;
}

bool Ghost::isDead(Ghost ghost)
{
	if (ghost.eaten == true)
	{
		ghost.movedFromLair == false;
	}
}

bool Ghost::eaten(Ghost ghost, Player player)
{
	if ((player.x && player.y) == (ghost.x && ghost.y))
	{
		if (player.bonus == true)
		{
			ghost.isDead;
		}
	}
}