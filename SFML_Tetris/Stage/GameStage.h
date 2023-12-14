#ifndef H_GAME_STAGE
#define H_GAME_STAGE

#include "../Application/preloader.h"

#include "Stage.h"

#include "../GameObject/Block.h"
#include "../GameObject/GameBoard.h"

class GameStage : public Stage {
public:
	GameStage();
	~GameStage();

	void update() override;
	void draw() override;
private:

	GameBoard board;
};

#endif