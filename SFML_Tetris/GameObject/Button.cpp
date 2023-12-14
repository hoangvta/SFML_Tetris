#include "Button.h"

Button::Button()
{
	setTexture(*preloader::getLoader().getTexture("buttonTexture"));
	getSprite().setOrigin((sf::Vector2f) preloader::getLoader().getTexture("buttonTexture")->getSize() / 2.0f);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(2);
	buttonText.setCharacterSize(24);
}

void Button::setText(sf::String text)
{
	buttonText.setPosition(getSprite().getPosition());
	buttonText.setText(text);
	buttonText.setOrigin((sf::Vector2f)buttonText.getGlobalBounds().getSize() / 2.0f);
}

void Button::update()
{
}

void Button::draw()
{
	InteractableObject::draw();
	buttonText.draw();
}

bool Button::onClick()
{
	return getSprite().getGlobalBounds().contains((sf::Vector2f) ApplicationEvent::getEvent().getMousePos());
}
