#include "MenuStage.h"

MenuStage::MenuStage()
{
	buttonList = new Button[3];
	buttonList[0].setPos((sf::Vector2i)ApplicationWindow::getWindow().getSize() / 2 - sf::Vector2i(0, 150));
	buttonList[0].setText("Play Game");
	buttonList[1].setPos((sf::Vector2i)ApplicationWindow::getWindow().getSize() / 2);
	buttonList[1].setText("How to play");
	buttonList[2].setPos((sf::Vector2i)ApplicationWindow::getWindow().getSize() / 2 + sf::Vector2i(0, 150));
	buttonList[2].setText("Exit game");
}

MenuStage::~MenuStage()
{
	delete[] buttonList;
}

void MenuStage::update()
{
	if (ApplicationEvent::getEvent().isMouseClick(sf::Mouse::Left)) {
		if (buttonList[0].onClick()) {
			setNextStage(new GameStage());
		}
		if (buttonList[1].onClick()) {

		}
		if (buttonList[2].onClick()) {
			stop();
		}
	}
}

void MenuStage::draw()
{
	buttonList[0].draw();
	buttonList[1].draw();
	buttonList[2].draw();
}
