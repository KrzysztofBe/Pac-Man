#include <math.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include "ghost.h"
#define M_PI 3.14159265

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
	this->isDead = false;
}

void Ghost::setGhostPosition(Map *map, Player *player) {
	//zapisujemy sobie lokalnie pozycje duszka
	int x = this->x;
	int y = this->y;
	// ustawiamy minimalny indeks i minimalna odleglosc na nieosiagalne wartosci(o tym pozniej)
	int minIndex = -1;
	int minValue = 1000;
	// tworzymy tablice z potencjalnymi punktami do odwiedzenia dla duszka, oraz domyslna(duza) odlegloscia duszka od gracza
	int pointsToCheck[4][3] = {
		{ this->x + 1, this->y, 1000 },
		{ this->x - 1, this->y, 1000 },
		{ this->x, this->y + 1, 1000 },
		{ this->x, this->y - 1, 1000 } };


	for (int i = 0; i < 4; i++) {
		// dla kazdego punktu - sprawdzamy, czy jest on osiagalny(czy mozna tam stanac), oraz czy jest poza jaskinia
		if (map->isPointAccessible(pointsToCheck[i][0], pointsToCheck[i][1], this) && this->outsideLair) {
			if (this->getDead()) {
				int xToGo = 15;
				int yToGo = 11;
				pointsToCheck[i][2] = map->euclideanDistance(pointsToCheck[i][0], pointsToCheck[i][1], xToGo, yToGo);
			}
			// jezeli gracz ma bonus - duszki powinny uciekac
			else if (player->hasBonus) {
				// obliczamy sobie sin(180*) i cos(180*) - potrzebny do obrotu
				float originSin = sin(180 * M_PI / 180);
				float originCos = cos(180 * M_PI / 180);
				// ustawiamy punkt, wokol ktorego dokonamy obrotu
				int originX = 15;
				int originY = 14;
				// obliczamy(w przyblizeniu) punkt przeciwlegly do punktu gracza- duszki beda tam uciekac
				int oppositePlayerX = floor((player->x - originX) * originCos - (player->y - originY) * originSin + originX);
				int oppositePlayerY = floor((player->x - originX) * originSin + (player->y - originY) * originCos + originY);

				// i sprawdzamy, ktory jest "najdalej"
				pointsToCheck[i][2] = map->euclideanDistance(pointsToCheck[i][0], pointsToCheck[i][1], oppositePlayerX, oppositePlayerY);
			}
			else {
				// w przeciwnym wypadku, obliczamy dla kazdego dostepnego punktu - jak daleko jest gracz
				pointsToCheck[i][2] = map->euclideanDistance(pointsToCheck[i][0], pointsToCheck[i][1], player->x, player->y);
			}
		}
		// jezeli duszek nie jest poza jaskinia
		else if (!this->outsideLair) {
			// szukamy najlepszych punktow na ktore moze sie przemiescic, zeby trafic na (15,11)
			int xToGo = 15;
			int yToGo = 11;
			pointsToCheck[i][2] = map->euclideanDistance(pointsToCheck[i][0], pointsToCheck[i][1], xToGo, yToGo);
		}
	}

	// wyszukujemy najmniejsza wartosc odleglosci z punktow do sprawdzenia, oraz indeks punktu z najmniejsza odlegloscia
	for (int i = 0; i < 4; i++) {
		if (pointsToCheck[i][2] < minValue) {
			minValue = pointsToCheck[i][2];
			minIndex = i;
		}
	}

	// dodajemy troche losowosci - kiedy indeks >=0 - wtedy istnieje punkt o minimalnej odleglosci i jest on pod indeksem minIndex, dodatkowo losujemy wartosc
	// od 0-9, kiedy wartosc jest > 4, idziemy do tego punktu - w przeciwnym wypadku wybieramy losowo pozycje do przemieszczenia
	if ((minIndex >= 0) && (rand() % 10) > 4) {
		x = pointsToCheck[minIndex][0];
		y = pointsToCheck[minIndex][1];
	}
	else {
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
	}

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
