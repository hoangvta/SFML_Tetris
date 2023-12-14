#ifndef H_STAGE
#define H_STAGE

#include "ApplicationEvent.h"

class Stage abstract
{
public:
	Stage();
	virtual ~Stage();
	virtual void update() = 0;
	virtual void draw() = 0;

	void setNextStage(Stage* stage);
	Stage* getNextStage();

	inline bool isStop() { return ended; }
	inline void stop() { ended = true; }
	void setID(int id);

protected:
	unsigned int sID;

	bool ended;
	Stage* nextStage;
private:
};

#endif

