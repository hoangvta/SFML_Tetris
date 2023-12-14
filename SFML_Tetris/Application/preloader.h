#ifndef H_PRELOADER
#define H_PRELOADER

#include <map>

#include "SFML/Graphics.hpp"

class preloader
{
public:
	preloader();
	preloader(preloader& other) = delete;
	void operator=(const preloader& other) = delete;

	~preloader();

	static preloader& getLoader()
	{
		static preloader p_preloader;
		return p_preloader;
	}

	void save();
	void load();

	void loadFromString(sf::String fileName);

	sf::Texture* getTexture(std::string key);

private:
	std::map<std::string, sf::Texture*> loadedTextures;
};

#endif