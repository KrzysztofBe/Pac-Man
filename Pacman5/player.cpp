#include <vector>
#include <SFML/Graphics.hpp>
#include "windows.h"
#include "player.h"
#include "map.h"
#include "input.h"
#include <time.h>


Player::Player()
{
	sf::Texture *pacman = new sf::Texture();
	sf::Sprite *sprite = new sf::Sprite();
	pacman->loadFromFile("pacman_lewo.png");
	sprite->setTexture(*pacman);
	this->newSymbol = sprite;

	this->x = 13;
	this->y = 23;
	this->score = 0;
	this->startX = this->x;
	this->startY = this->y;
	this->hasBonus = false;
	this->bonusStart = 0;
	this->numberOfLives = 0;
	//this->symbol = 'C';
}

void Player::reset()
{
	this->x = this->startX;
	this->y = this->startY;
}

void Player::dies()
{
	this->numberOfLives -= 1;
	this->reset();
}

void Player::setNumberOfLives(int lives)
{
	this->numberOfLives = lives;
}

int Player::getNumberOfLives()
{
	return this->numberOfLives;
}


void Player::getPlayerInput(sf::Event event)
{
	this->oldInput = this->input;

	if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
	{
		this->input.x = -1;
		this->input.y = 0;
	}
	if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
	{
		this->input.x = 1;
		this->input.y = 0;
	}
	if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
	{
		this->input.x = 0;
		this->input.y = -1;
	}
	if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
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
		}

		if (point == '0') {
			this->score += 100;
			this->startBonus();
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
	//this->symbol = '@';
}

void Player::endBonus()
{
	time_t currentTime = time(NULL);
	if ((currentTime - this->bonusStart) > 12) {
		this->bonusStart = 0;
		this->hasBonus = false;
		//this->symbol = 'C';
	}
}