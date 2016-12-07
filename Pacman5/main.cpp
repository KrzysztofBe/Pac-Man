#include "game.h"
#include <math.h>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));

	Game game;
	game.addGhost(13, 14, 'I');
	game.addGhost(14, 15, 'P');
	game.addGhost(15, 14, 'Z');
	game.start();

	return 0;
}