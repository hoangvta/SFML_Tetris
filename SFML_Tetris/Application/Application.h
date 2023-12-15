#ifndef H_APPLICATION
#define H_APPLICATION

#include <stack>

#include "preloader.h"

#include "ApplicationEvent.h"
#include "ApplicationWindow.h"

#include "../Stage/MenuStage.h"

class Application
{
public:
	Application();
	~Application();

	void init();

	void run();

private:
	bool applicationAlive;
	float deltaTime;
	std::stack<Stage*> stageList;
};

#endif
