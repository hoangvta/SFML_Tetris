#ifndef H_APPLICATION_WINDOW
#define H_APPLICATION_WINDOW

#include "SFML/Graphics/RenderWindow.hpp"

class ApplicationWindow
{
public:
	static sf::RenderWindow& getWindow() {
		static sf::RenderWindow s_window(sf::VideoMode(800, 600), "The Tetris", sf::Style::Titlebar | sf::Style::Close);
		return s_window;
	}
private:
};

#endif