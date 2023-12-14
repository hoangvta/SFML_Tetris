#ifndef H_APPLICATION_EVENT
#define H_APPLICATION_EVENT

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/Font.hpp"

#include "ApplicationWindow.h"

#include <stdlib.h>
#include <time.h>

class ApplicationEvent 
{
public:

	static ApplicationEvent& getEvent() {
		static ApplicationEvent s_event;
		srand(time(NULL));
		return s_event;
	}

	bool isKeyPressed(sf::Keyboard::Key key);
	bool isKeyHolding(sf::Keyboard::Key key);
	bool isKeyRelease(sf::Keyboard::Key key);

	bool isMouseClick(sf::Mouse::Button button);
	sf::Vector2i getMousePos();

	void update();

	sf::Font& getFont();

	const float& getDeltaTime();
	void updateTime();

	int getRandomInt() {
		return rand();
	}

	enum class ButtonState {
		UNTOUCH = 0,
		RELEASE,
		PRESS,
		HOLD,
		STATE_SIZE
	};	
private:
	float deltaTime;
	ButtonState buttonPressList[sf::Keyboard::Key::KeyCount] = {};
	
	sf::Vector2i mousePos;
	ButtonState mouseClickList[sf::Mouse::Button::ButtonCount] = {};
	sf::Font font;
};

#endif