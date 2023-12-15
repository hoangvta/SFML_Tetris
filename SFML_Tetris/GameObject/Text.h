#ifndef H_TEXT
#define H_TEXT

#include "SFML/Graphics/Text.hpp"

#include "../Application/preloader.h"
#include "../Application/ApplicationWindow.h"

class Text : public sf::Text 
{
public:
	Text();

	void setText(sf::String text);

	void draw();
private:
};

#endif
