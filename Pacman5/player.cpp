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

	switch (map->getPoint(temp_x, temp_y))
	{
	case '.':
		map->setPoint(temp_x, temp_y, ' ');
		this->score += 10;
		this->x += this->input.x;
		this->y += this->input.y;
		break;

	case ' ':
		map->setPoint(temp_x, temp_y, ' ');
		this->x += this->input.x;
		this->y += this->input.y;
		break;

	case '0':
		map->setPoint(temp_x, temp_y, ' ');
		this->score += 100;
		this->x += this->input.x;
		this->y += this->input.y;
		this->startBonus();
		break;

	case '<':
		this->x = 29;
		break;

	case '>':
		this->x = 0;
		break;

	default: this->input = this->oldInput;
	}
}

void Player::startBonus()
{
	bonusStart = time(NULL);
}

void Player::endBonus()
{
	time_t currentTime = time(NULL);
	if ((currentTime - this->bonusStart) > 20) {
		this->bonusStart = 0;
		this->hasBonus = false;
	}
}