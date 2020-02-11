#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Scene.h"

class App
{
public:
	App();
	bool load();
	void loop();
	static const char* TITLE;
private:
	static const unsigned int FRAMERATE_LIMIT = 60;
	static const sf::Int64 UPDATES_PER_SEC = 30;
	static const sf::Time TIME_PER_UPDATE;

	ScenePtr scene;
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time updateTimeAccumulator;
	sf::Texture texture;
	sf::RenderStates renderStates;
	sf::Font font;
	Audio audio;

	void handleSceneChange();
	void handleInput();
	void fixedTimestepUpdate();
};
