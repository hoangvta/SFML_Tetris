#include "Block.h"


Block::Block()
{
	setTexture(*preloader::getLoader().getTexture("blockTexture"));
}

Block::~Block()
{
}

void Block::update()
{
	setPos(this->getPos() + sf::Vector2i(0, 24));
}


bool Block::collise(Block& other, bool down)
{
	if (!down) return other.getSprite().getGlobalBounds().intersects(this->getSprite().getGlobalBounds());

	bool ret = false;
	this->setPos(this->getPos() - sf::Vector2i(0, 1));
	
	if (other.getSprite().getGlobalBounds().intersects(this->getSprite().getGlobalBounds())) ret = true;

	this->setPos(this->getPos() + sf::Vector2i(0, 1));
	return ret;
}
