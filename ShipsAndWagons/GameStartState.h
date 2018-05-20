#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

class GameStartState : public GameState
{
private:
	sf::View view;

public:
	virtual void update(const float dt);
	virtual void draw(const float dt);
	virtual void handleInput();

	GameStartState(Game* game);
};

