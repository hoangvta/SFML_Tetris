#include "Application/Application.h"

#include <windows.h>

int main(int argc, char** argv) {

	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);

	Application app;

	app.run();

	return 0;
}