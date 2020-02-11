#include "App.h"
#include <SFML/System/Time.hpp>
#include "WelcomeScene.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "Assets.h"

const sf::Time App::TIME_PER_UPDATE = sf::seconds(1) / UPDATES_PER_SEC;
const char* App::TITLE = "TD";
static const sf::Color CLEAR_COLOR = sf::Color(250, 250, 250);

App::App():
	scene(std::make_unique<WelcomeScene>()),
	window(sf::VideoMode(960, 640), TITLE),
	updateTimeAccumulator(sf::Time::Zero),
	renderStates(sf::RenderStates::Default)
{
	window.setFramerateLimit(FRAMERATE_LIMIT);
	Assets::get().window = &window;
}

bool App::load()
{
	auto& assets = Assets::get();
	if (!assets.texture.loadFromFile("towerDefense_tilesheet.png"))
		return false;
	renderStates.texture = &assets.texture;
	renderStates.transform.scale(SCALE_FACTOR, SCALE_FACTOR);
	if (!assets.font.loadFromFile("LiberationSans-Regular.ttf"))
		return false;
	return assets.audio.loadAll();
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
