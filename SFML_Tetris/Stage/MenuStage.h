#ifndef H_MENUSTAGE
#define H_MENUSTAGE

#include "../Application/preloader.h"

#include "Stage.h"
#include "GameStage.h"
#include "HowToPlayStage.h"
#include "../GameObject/Button.h"

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