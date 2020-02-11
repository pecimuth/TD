#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "Scene.h"

class App
{
public:
	App();
	bool load();
	void loop();
private:
	ScenePtr scene;
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time updateTimeAccumulator;
	sf::RenderStates renderStates;

	void handleSceneChange();
	void handleInput();
	void fixedTimestepUpdate();
};
