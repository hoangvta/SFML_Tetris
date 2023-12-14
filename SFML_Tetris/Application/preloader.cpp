#include "preloader.h"

preloader::preloader()
{
	load()
}

preloader::~preloader()
{
	for (auto item : loadedTextures) {
		delete item.second;
	}
	loadedTextures.clear();

	save();
}

void preloader::save()
{
}

void preloader::load()
{

	loadFromString("buttonTexture");

	loadFromString("blockTexture");

}

void preloader::loadFromString(sf::String fileName)
{
	sf::Texture* tmpTexture = new sf::Texture();
	tmpTexture->loadFromFile("image/" + fileName + ".png");
	loadedTextures[fileName] = tmpTexture;
}

sf::Texture* preloader::getTexture(std::string key) {
	return loadedTextures.at(key);
}
