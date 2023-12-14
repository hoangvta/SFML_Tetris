#include "Application.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

int main(int argc, char** argv) {

	Application app;

	//sf::Window window(sf::VideoMode(640, 480), "hello world!");

 //   while (window.isOpen()) {
 //       sf::Event event;
 //       while (window.pollEvent(event))
 //           if (event.type ==
 //               sf::Event::Closed)
 //               window.close();
 //   }

	app.run();

	return 0;
}