#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

// forward declaration, otherwise circular dependency
class GameState;

class Game
{
public:
	std::stack<GameState*> states;

	sf::RenderWindow window;

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

