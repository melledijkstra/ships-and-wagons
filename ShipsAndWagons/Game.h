#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"

// forward declaration, otherwise circular dependency
class GameState;

class Game
{
private:
	void loadTextures();

public:
	std::stack<GameState*> states;

	sf::RenderWindow window;
	TextureManager texmgr;
	sf::Sprite background;

	// state management
	void pushState(GameState* state);
	void changeState(GameState* state);
	void popState();
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
};

