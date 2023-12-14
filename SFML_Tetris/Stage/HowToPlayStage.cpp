#include "HowToPlayStage.h"

HowToPlayStage::HowToPlayStage()
{
	stageText.setText("Left Arrow: Move left\n\nRight Arrow: Move right\n\nDown Arrow: Soft Drop\n\nUp Arrow: Rotate Right\n\nZ: Rotate Left\n\nEscape: Return to main menu");

	stageText.setCharacterSize(26);
	stageText.setOutlineColor(sf::Color::Transparent);
	stageText.setPosition({ 10, 50 });
}

void HowToPlayStage::update()
{
	if (ApplicationEvent::getEvent().isKeyPressed(sf::Keyboard::Escape)) {
		stop();
	}
}

void HowToPlayStage::draw()
{
	stageText.draw();
}
