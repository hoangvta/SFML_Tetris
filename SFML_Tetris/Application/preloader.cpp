#include "preloader.h"

preloader::preloader()
{
	loadFromString("buttonTexture");

	loadFromString("blockTexture");

	loadFromString("I_texture");
	loadFromString("S_texture");
	loadFromString("Z_texture");
	loadFromString("J_texture");
	loadFromString("L_texture");
	loadFromString("O_texture");
	loadFromString("T_texture");
}

preloader::~preloader()
{
	for (auto item : floorTypeTextures) {
		delete item.second;
	}
	floorTypeTextures.clear();
}

void preloader::save()
{
}

void preloader::load()
{
}

void preloader::loadFromString(sf::String fileName)
{
	sf::Texture* tmpTexture = new sf::Texture();
	tmpTexture->loadFromFile("image/" + fileName + ".png");
	floorTypeTextures[fileName] = tmpTexture;
}

sf::Texture* preloader::getTexture(std::string key) {
	return floorTypeTextures.at(key);
}
