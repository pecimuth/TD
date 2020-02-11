#include "App.h"

#include <SFML/System/Time.hpp>
#include "WelcomeScene.h"
#include "GameScene.h"
#include "GameOverScene.h"

const sf::Time App::TIME_PER_UPDATE = sf::seconds(1) / UPDATES_PER_SEC;
const char* App::TITLE = "TD";
static const sf::Color CLEAR_COLOR = sf::Color(250, 250, 250);

App::App():
	scene(std::make_unique<WelcomeScene>()),
	window(sf::VideoMode(960, 640), TITLE),
	updateTimeAccumulator(sf::Time::Zero),
	texture(),
	renderStates(sf::RenderStates::Default),
	font(),
	audio()
{
	window.setFramerateLimit(FRAMERATE_LIMIT);
	scene->setTexture(texture);
	scene->setFont(font);
	scene->setWindow(window);
	scene->setAudio(audio);
}

bool App::load()
{
	if (!texture.loadFromFile("towerDefense_tilesheet.png"))
		return false;
	renderStates.texture = &texture;
	renderStates.transform.scale(SCALE_FACTOR, SCALE_FACTOR);
	if (!font.loadFromFile("LiberationSans-Regular.ttf"))
		return false;
	return audio.loadAll();
}

void App::loop()
{
	while (window.isOpen())
	{
		handleSceneChange();
		handleInput();
		fixedTimestepUpdate();
		window.clear(CLEAR_COLOR);
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
		case SceneType::Game:
			scene = std::make_unique<GameScene>();
			break;
		case SceneType::GameOver:
			scene = std::make_unique<GameOverScene>(request->waveNumber);
			break;
		case SceneType::Welcome:
		default:
			scene = std::make_unique<WelcomeScene>();
			break;
		}
		scene->setTexture(texture);
		scene->setFont(font);
		scene->setWindow(window);
		scene->setAudio(audio);
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
