#ifndef H_BUTTON
#define H_BUTTON

#include "SFML/Graphics.hpp"

#include "InteractableObject.h"
#include "Text.h"

class Button : public InteractableObject
{
public:
	Button();

	void setText(sf::String);

	void update() override;
	void draw() override;

	bool onClick();
private:
	Text buttonText;
};

#endif
