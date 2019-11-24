#pragma once

#include <memory>
#include <SFML\Graphics\RenderWindow.hpp>

#include "Scene.h"

class App
{
public:
	App();
	void loop();

private:
	ScenePtr scene;
	sf::RenderWindow window;

	void handleSceneChange();
	void handleInput();
};
