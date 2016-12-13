#include "game.h"
#include "windows.h"

Game::Game()
{
	this->map = new Map();
	this->player = new Player();
	this->mainLoop = true;
}

void Game::addGhost(int x, int y, char symbol)
{
	this->ghosts.push_back(Ghost(x, y, symbol));
}


void Game::start()
{
	while (this->mainLoop == true) {
		for (vector<Ghost>::iterator it = this->ghosts.begin(); it != this->ghosts.end(); ++it) {
			it->setGhostPosition(this->map, this->player);
		}
		this->player->getPlayerInput();
		this->player->setPlayerPosition(this->map);
		this->map->draw(this->ghosts, *this->player);
		this->detectCollisions();
		this->player->endBonus();
		Sleep(70);
		if (this->player->hasBonus) {
			Beep((rand() % 300) + 200, 100);
		}
		else
		{
			Beep((rand() % 200) + 500, 100);
		}
	}
}

void Game::stop()
{
	this->mainLoop = false;
}

void Game::detectCollisions()
{
	for (vector<Ghost>::iterator it = ghosts.begin(); it != ghosts.end(); ++it) {
		if ((this->player->x == it->x) && (this->player->y == it->y))
		{
			throw "Collision";
		}
	}
}