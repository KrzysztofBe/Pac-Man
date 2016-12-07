#include "game.h"
//Komentarz
// Dodatkowy komentarz
Game::Game()
{
	this->map = map;
	this->player = player;
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
			it->setGhostPosition(this->map);
		}
		this->player.getPlayerInput();
		this->player.setPlayerPosition(this->map);
		this->map.draw(this->ghosts, this->player);
	}
}

void Game::stop()
{
	this->mainLoop = false;
}
