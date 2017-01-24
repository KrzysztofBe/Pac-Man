#ifndef __PLAYER_H
#define __PLAYER_H
class Map;
#include "map.h"
#include <SFML/Graphics.hpp>
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
	sf::Sprite *newSymbol;
	int score;
	bool hasBonus;
	int startX, startY;
	void reset();
	void setNumberOfLives(int lives);
	void dies();
	int getNumberOfLives();
	void getPlayerInput(sf::Event event);
	void startBonus();
	void endBonus();
	void setPlayerPosition(Map *map);
	Input input, oldInput;
};
#endif