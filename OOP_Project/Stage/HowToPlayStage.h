#ifndef H_HOW_TO_PLAY
#define H_HOW_TO_PLAY

#include "Stage.h"

#include "../GameObject/Text.h"

class HowToPlayStage : public Stage
{
public:
	HowToPlayStage();

	void update() override;
	void draw() override;
private:

};

#endif