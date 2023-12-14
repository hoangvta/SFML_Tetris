#include "Text.h"

Text::Text()
{
	setFont(ApplicationEvent::getEvent().getFont());
	setCharacterSize(12);
	setFillColor(sf::Color::White);
}

void Text::setText(sf::String text)
{
	setString(text);
}

void Text::draw()
{
	ApplicationWindow::getWindow().draw(*this);
}
