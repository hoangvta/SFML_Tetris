#include "Stage.h"

Stage::Stage()
{
	sID = 0;
	nextStage = nullptr;
	ended = false;
}

Stage::~Stage()
{
	nextStage = nullptr;
}

void Stage::setNextStage(Stage* stage)
{
	nextStage = stage;
}

Stage* Stage::getNextStage()
{
	return nextStage;
}

void Stage::setID(int id)
{
	sID = id;
}
