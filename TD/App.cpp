#include "App.h"

#include <SFML/System/Time.hpp>
#include "WelcomeScene.h"
#include "GameScene.h"

const sf::Time App::TIME_PER_UPDATE = sf::seconds(1) / UPDATES_PER_SEC;

App::App():
	scene(std::make_unique<WelcomeScene>()),
	window(sf::VideoMode(960, 640), "TD"),
	updateTimeAccumulator(sf::Time::Zero),
	texture(),
	renderStates(sf::RenderStates::Default)
{
	window.setFramerateLimit(FRAMERATE_LIMIT);
}

bool App::load()
{
	if (!texture.loadFromFile("towerDefense_tilesheet.png"))
		return false;
	renderStates.texture = &texture;
	renderStates.transform.scale(0.5, 0.5);
	return true;
}

void App::loop()
{
	while (window.isOpen())
	{
		handleSceneChange();
		handleInput();
		fixedTimestepUpdate();
		window.clear();
		window.draw(*scene, renderStates);
		window.display();
	}
}

void App::handleSceneChange()
{
	if (scene->isSceneChangeRequested())
	{
		auto request = scene->takeSceneChangeRequest();
		switch (request->targetScene)
		{
		case SceneType::Level:
			scene = std::make_unique<GameScene>();
			break;
		case SceneType::Welcome:
		default:
			scene = std::make_unique<WelcomeScene>();
			break;
		}
	}
}

void App::handleInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		scene->handleInput(event);
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void App::fixedTimestepUpdate()
{
	updateTimeAccumulator += clock.restart();
	while (updateTimeAccumulator >= TIME_PER_UPDATE)
	{
		scene->update(TIME_PER_UPDATE);
		updateTimeAccumulator -= TIME_PER_UPDATE;
	}
}
