#include "GameStage.h"

GameStage::GameStage()
{
}

GameStage::~GameStage()
{
}

void GameStage::update()
{
	if (ApplicationEvent::getEvent().isKeyPressed(sf::Keyboard::Escape)) {
		stop();
	}

	board.update();
}

void GameStage::draw()
{
	board.draw();
}
