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

void Ghost::setGhostPosition(Map map) {
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

	if (map.isPointAccessible(x, y)) {
		this->x = x;
		this->y = y;
	}
}
