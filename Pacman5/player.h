#ifndef __PLAYER_H
#define __PLAYER_H
class Map;
#include "map.h"
#include "input.h"

class Player
{
private:
	int numberOfLives;
	int bonusStart;
public:
	Player();
	int x, y;
	char symbol;
	int score;
	bool hasBonus;
	void setNumberOfLives(int lives);
	void dies(int actualLives);
	void getNumberOfLives();
	void getPlayerInput();
	void startBonus();
	void endBonus();
	void setPlayerPosition(Map *map);
	Input input, oldInput;
};
#endif