#ifndef H_INTERACTABLE_OBJECT
#define H_INTERACTABLE_OBJECT

#include "../Application/preloader.h"

#include "SFML/Graphics.hpp"

#include "../Application/ApplicationWindow.h"
#include "../Application/ApplicationEvent.h"

class InteractableObject abstract
{
public:

	bool isSelected();

	void setTexture(sf::Texture& texture);
	virtual bool onUse();

	void setPos(sf::Vector2i pos);
	sf::Vector2i getPos();

	virtual void draw();
	virtual void update() = 0;

	sf::Sprite& getSprite();
private:

	bool selected;
	int spriteState;

	sf::Vector2i objectPosition;

	sf::Sprite objectSprite;
};

#endif