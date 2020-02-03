#include "App.h"
#include <iostream>

int main()
{
	App app;
	if (!app.load())
	{
		std::cerr << "Failed to load the game." << std::endl;
		return 0;
	}
	app.loop();
	return 0;
}
