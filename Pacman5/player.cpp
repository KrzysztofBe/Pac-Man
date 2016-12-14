#include <vector>
#include "windows.h"
#include "player.h"
#include "map.h"
#include "input.h"
#include <time.h>

Player::Player()
{
	this->x = 13;
	this->y = 20;
	this->score = 0;
	this->symbol = 'C';
	this->hasBonus = false;
	this->bonusStart = 0;
	this->numberOfLives = 0;
}


void Player::setNumberOfLives(Player player)
{
	this->numberOfLives = 3;

	if (player == dies)
	{
		numberOfLives -= 1;

		if (numberOfLives == 0)
		{
			gameOver();
		}
	}
}

void Player::getNumberOfLives()
{

}



void Player::getPlayerInput()
{
	this->oldInput = this->input;

	if (GetAsyncKeyState(VK_LEFT) != 0)
	 {
	 	this->input.x = -1;
	 	this->input.y = 0;
	 }
	 if (GetAsyncKeyState(VK_RIGHT) != 0)
	 {
	 	this->input.x = 1;
	 	this->input.y = 0;
	 }
	 if (GetAsyncKeyState(VK_UP) != 0)
	 {
	 	this->input.x = 0;
	 	this->input.y = -1;
	 }
	 if (GetAsyncKeyState(VK_DOWN) != 0)
	 {
	 	this->input.x = 0;
	 	this->input.y = 1;
	 }

}

void Player::setPlayerPosition(Map *map)
{
	int temp_x = this->x + this->input.x;
	int temp_y = this->y + this->input.y;
	char point = map->getPoint(temp_x, temp_y);

	if (map->isPointAccessible(temp_x, temp_y, this)) {
		if (point == '.' || point == ' ' || point == '0') {
			map->setPoint(temp_x, temp_y, ' ');
			this->x = temp_x;
			this->y = temp_y;
		}
		if (point == '.') {
			this->score += 10;
			Beep(700, 100);
		}

		if (point == '0') {
			this->score += 100;
			this->startBonus();
			Beep(500, 100);
		}

		if (point == '>') {
			this->x = 0;
		}

		if (point == '<') {
			this->x = 29;
		}

	}
	else {
		this->input = this->oldInput;
	}
}

void Player::startBonus()
{
	this->bonusStart = time(NULL);
	this->hasBonus = true;
	this->symbol = '@';
}

void Player::endBonus()
{
	time_t currentTime = time(NULL);
	if ((currentTime - this->bonusStart) > 12) {
		this->bonusStart = 0;
		this->hasBonus = false;
		this->symbol = 'C';
	}
}