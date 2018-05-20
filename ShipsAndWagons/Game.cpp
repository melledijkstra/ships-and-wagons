#include <stack>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "Game.h"
#include "GameState.h"

Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "ShipsAndWagons");
	this->window.setFramerateLimit(60);
}

Game::~Game()
{
	while (!this->states.empty()) popState();
}

//// <summary>
/// The actual game loop
/// 1. handle input
/// 2. update game
/// 3. draw
/// </summary>
/// <returns></returns>
void Game::gameLoop() 
{
	sf::Clock clock;

	while (this->window.isOpen()) 
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		// handle input
		peekState()->handleInput();
		// update the game
		peekState()->update(dt);
		// draw on the screen
		this->window.clear();
		peekState()->draw(dt);
		this->window.display();
	}

}

void Game::pushState(GameState* state)
{
	this->states.push(state);
	return;
}

void Game::popState()
{
	delete this->states.top();
	this->states.pop();

	return;
}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
		popState();
	pushState(state);
	return;
}

GameState* Game::peekState()
{
	if (this->states.empty()) return nullptr;
	return this->states.top();
}

