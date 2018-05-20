#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "TextureManager.h"

TextureManager::TextureManager()
{
	
}


TextureManager::~TextureManager()
{
}

void TextureManager::loadTexture(const std::string& name, const std::string& filename)
{
	/* Load the texture */
	sf::Texture tex;
	tex.loadFromFile(filename);

	this->textures[name] = tex;
}

sf::Texture& TextureManager::getTexture(const std::string& texture)
{
	return this->textures.at(texture);
}


