#include "preloader.h"

preloader::preloader()
{
	load();
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

sf::Font& preloader::getFont()
{
	static bool done = false;
	if (done) {
		return font;
	}
	font.loadFromFile("font/font.ttf");
	done = true;
	return getFont();
}


sf::Texture* preloader::getTexture(std::string key) {
	return loadedTextures.at(key);
}
