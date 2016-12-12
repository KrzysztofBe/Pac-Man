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

void Ghost::setGhostPosition(Map *map, Player *player) {
	int x = this->x;
	int y = this->y;
	int minIndex = 0;
	int minValue = 1000;
	int pointsToCheck[4][3] = {
		{ this->x + 1, this->y, 1000 },
		{ this->x - 1, this->y, 1000 },
		{ this->x, this->y + 1, 1000 },
		{ this->x, this->y - 1, 1000 } };
	for (int i = 0; i < 4; i++) {
		if (map->isPointAccessible(pointsToCheck[i][0], pointsToCheck[i][1], this) && this->outsideLair) {
			pointsToCheck[i][2] = map->euclideanDistance(pointsToCheck[i][0], pointsToCheck[i][1], player->x, player->y);
		}
	}

	for (int i = 0; i < 4; i++) {
		if (pointsToCheck[i][2] < minValue) {
			minValue = pointsToCheck[i][2];
			minIndex = 0;
		}
	}

	x = pointsToCheck[minIndex][0];
	y = pointsToCheck[minIndex][1];
	// switch (rand() % 4) {
	// case 0:
	//  x += 1;
	//  break;
	// case 1:
	//  x -= 1;
	//  break;
	// case 2:
	//  y += 1;
	//  break;
	// case 3:
	//  y -= 1;
	//  break;
	// }

	if (map->isPointAccessible(x, y, this)) {
		this->x = x;
		this->y = y;
	}
}

void Ghost::movedFromLair()
{
	if ((this->x == 14 && this->y == 11) || (this->x == 15 && this->y == 11))
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
