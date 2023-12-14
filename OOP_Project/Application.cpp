#include "Application.h"

Application::Application()
{
	init();
}

void Application::init()
{
	stageList.push(new MenuStage());
}

void Application::run()
{
	while (ApplicationWindow::getWindow().isOpen()) {
		if (stageList.empty()) {
			ApplicationWindow::getWindow().close();
			continue;
		}
		if (stageList.top()->isStop()) {
			delete stageList.top();
			stageList.pop();

			if (!stageList.empty()) {
				stageList.top()->setNextStage(nullptr);
			}

			continue;
		}

		if (stageList.top()->getNextStage() != nullptr) {
			stageList.push(stageList.top()->getNextStage());
			continue;
		}

		ApplicationWindow::getWindow().clear();
		
		ApplicationEvent::getEvent().update();

		stageList.top()->setID(stageList.size());
		
		stageList.top()->update();
		stageList.top()->draw();

		ApplicationWindow::getWindow().display();
	}
}

