#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameState.h"

Game::Game()
{
	this->loadTextures();

	this->window.create(sf::VideoMode(800, 600), "ShipsAndWagons");
	this->window.setFramerateLimit(60);

	this->background.setTexture(this->texmgr.getTexture("background"));
}

Game::~Game()
{
	while (!this->states.empty()) popState();
}

void Game::loadTextures()
{
	texmgr.loadTexture("background", "Resources/Images/background.png");

	texmgr.loadTexture("grass", "Resources/Images/Tiles/grass.png");
	texmgr.loadTexture("forest", "Resources/Images/Tiles/forest.png");
	texmgr.loadTexture("water", "Resources/Images/Tiles/water.png");
	texmgr.loadTexture("residential", "Resources/Images/Tiles/residential.png");
	texmgr.loadTexture("commercial", "Resources/Images/Tiles/commercial.png");
	texmgr.loadTexture("industrial", "Resources/Images/Tiles/industrial.png");
	texmgr.loadTexture("road", "Resources/Images/Tiles/road.png");
}

void Game::loadTiles()
{
	const Animation staticAnim(0, 0, 1.0f);
	this->tileAtlas["grass"] =
		Tile(tileSize, 1, texmgr.getTexture("grass"),
			{ staticAnim },
			TileType::GRASS, 50, 0, 1);
	tileAtlas["forest"] =
		Tile(tileSize, 1, texmgr.getTexture("forest"),
			{ staticAnim },
			TileType::FOREST, 100, 0, 1);
	tileAtlas["water"] =
		Tile(tileSize, 1, texmgr.getTexture("water"),
			{ Animation(0, 3, 0.5f),
			Animation(0, 3, 0.5f),
			Animation(0, 3, 0.5f) },
			TileType::WATER, 0, 0, 1);
	tileAtlas["residential"] =
		Tile(tileSize, 2, texmgr.getTexture("residential"),
			{ staticAnim, staticAnim, staticAnim,
			staticAnim, staticAnim, staticAnim },
			TileType::RESIDENTIAL, 300, 50, 6);
	tileAtlas["commercial"] =
		Tile(tileSize, 2, texmgr.getTexture("commercial"),
			{ staticAnim, staticAnim, staticAnim, staticAnim },
			TileType::COMMERCIAL, 300, 50, 4);
	tileAtlas["industrial"] =
		Tile(tileSize, 2, texmgr.getTexture("industrial"),
			{ staticAnim, staticAnim, staticAnim,
			staticAnim },
			TileType::INDUSTRIAL, 300, 50, 4);
	tileAtlas["road"] =
		Tile(tileSize, 1, texmgr.getTexture("road"),
			{ staticAnim, staticAnim, staticAnim,
			staticAnim, staticAnim, staticAnim,
			staticAnim, staticAnim, staticAnim,
			staticAnim, staticAnim },
			TileType::ROAD, 100, 0, 1);
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
		auto elapsed = clock.restart();
		auto dt = elapsed.asSeconds();

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

