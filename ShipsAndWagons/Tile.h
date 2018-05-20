#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "AnimationHandler.h"

enum class TileType { VOID, GRASS, FOREST, WATER, RESIDENTIAL, COMMERCIAL, INDUSTRIAL, ROAD };

std::string tileTypeToString(TileType type);

class Tile
{
public:
	Tile();
	Tile(unsigned, unsigned, sf::Texture& texture, const std::vector<Animation>& animations, TileType, unsigned, unsigned, unsigned);

	~Tile();

	AnimationHandler animHandler;
	sf::Sprite sprite;

	TileType tileType;

	/* Tile variant, allowing for different looking versions of the
	 * same tile */
	int tileVariant;

	unsigned int regions[1];

	/* Placement cost of the tile */
	unsigned int cost;

	/* Current residents / employees */
	double population;
	/* Maximum population per growth stage / tile variant */
	unsigned int maxPopPerLevel;
	/* Maximum number of building levels */
	unsigned int maxLevels;
	/* Production output per customer/worker per day, either monetary or goods */
	float production;
	/* Goods stored */
	float storedGoods;

	void draw(sf::RenderWindow& window, float dt);

	void update();

	std::string getCost() const
	{
		return std::to_string(this->cost);
	}

};

