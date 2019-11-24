#include "App.h"

#include "WelcomeScene.h"

App::App():
	scene(std::make_unique<WelcomeScene>()),
	window(sf::VideoMode(1200, 800), "TD")
{
}

void App::loop()
{
	while (window.isOpen())
	{
		handleSceneChange();
		handleInput();
		scene->update(sf::Time::Zero);
		window.clear();
		window.draw(*scene);
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
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
