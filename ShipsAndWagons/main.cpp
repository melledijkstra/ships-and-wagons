
#include "Game.h"
#include "GameStartState.h"

int main()
{
	Game game;

	game.pushState(new GameStartState(&game));
	game.gameLoop();

	return 0;
}