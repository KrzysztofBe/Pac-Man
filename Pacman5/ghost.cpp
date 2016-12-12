#include <math.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include "ghost.h"

Ghost::Ghost()
{
	this->outsideLair = false;
	this->isDead = false;
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

bool Ghost::movedFromLair()
{
	if ((this->x == 13 && this->y == 14) || (this->x == 14 && this->y == 15) || (this->x == 15 && this->y == 14))
		this->outsideLair = false;

	else if ((this->x == 15 && this->y == 11) || (this->x == 16 && this->y == 11))
		this->outsideLair = true;
}

bool Ghost::getDead()
{
	return this->isDead;
}

void Ghost::setDead(bool deadStatus)
{
	this->isDead = deadStatus;
}
