#include "game.h"
#include "windows.h"

Game::Game()
{
	this->map = new Map();
	this->player = new Player();
	this->mainLoop = true;
}

void Game::addGhost(int x, int y, char symbol, const char *ghostFile)
{
	this->ghosts.push_back(Ghost(x, y, symbol, ghostFile));
}


void Game::start()
{
	/*while (this->mainLoop == true) {
		for (vector<Ghost>::iterator it = this->ghosts.begin(); it != this->ghosts.end(); ++it) {
			it->setGhostPosition(this->map, this->player);
		}
		this->player->getPlayerInput();
		this->player->setPlayerPosition(this->map);
		this->map->draw(this->ghosts, *this->player);
		this->detectCollisions();
		this->player->endBonus();
		Sleep(30);
		if (this->player->hasBonus) {
		}
	}*/
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
			Ghost & ghost = *it;
			if (this->player->hasBonus) {
				ghost.setDead(true);
			}
			else {
				this->playerDied();
			}
		}
	}
}

void Game::playerDied()
{
	this->player->dies();
	if (this->player->getNumberOfLives() <= 0) {
		system("cls");
		throw "Game Over";
	}
	for (vector<Ghost>::iterator it = ghosts.begin(); it != ghosts.end(); ++it)
	{
		Ghost & ghost = *it;
		ghost.reset();
	}
}
