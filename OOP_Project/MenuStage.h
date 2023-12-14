#ifndef H_MENUSTAGE
#define H_MENUSTAGE

#include <conio.h>

#include "Stage.h"
#include "GameStage.h"
#include "HowToPlayStage.h"
#include "Button.h"

#include "preloader.h"

class MenuStage : public Stage
{
public:
	MenuStage();
	~MenuStage() override;

	void update() override;
	void draw() override;
private:

	Button* buttonList;
};

#endif