#ifndef H_GAME_STAGE
#define H_GAME_STAGE

#include "preloader.h"

#include "Stage.h"
#include "Block.h"
#include "GameBoard.h"

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