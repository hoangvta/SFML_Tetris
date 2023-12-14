#include "InteractableObject.h"

bool InteractableObject::isSelected()
{
    return selected;
}

void InteractableObject::setTexture(sf::Texture& texture)
{
    objectSprite = sf::Sprite(texture);
}

bool InteractableObject::onUse()
{
    return false;
}

void InteractableObject::setPos(sf::Vector2i pos)
{
    objectPosition = pos;
    objectSprite.setPosition((sf::Vector2f) pos);
}

sf::Vector2i InteractableObject::getPos()
{
    return objectPosition;
}

void InteractableObject::draw()
{
    objectSprite.setPosition((sf::Vector2f) objectPosition);
    ApplicationWindow::getWindow().draw(objectSprite);
}

sf::Sprite& InteractableObject::getSprite()
{
    return objectSprite;
}
