#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "Tile.h"

// forward declaration, otherwise circular dependency
class GameState;

class Game
{
private:
	void loadTextures();
	void loadTiles();

public:

	const static int tileSize = 8;

	std::stack<GameState*> states;

	sf::RenderWindow window;
	TextureManager texmgr;
	sf::Sprite background;

	std::map<std::string, Tile> tileAtlas;

	// state management
	void pushState(GameState* state);
	void changeState(GameState* state);
	void popState();
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
};

