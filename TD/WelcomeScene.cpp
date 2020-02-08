#include "WelcomeScene.h"

#include <SFML/Graphics.hpp>

#include "SceneType.h"
#include "SceneChangeRequest.h"
#include "App.h"
#include "Sector.h"

const sf::Time WELCOME_SCENE_DURATION = sf::seconds(1);
static const char* SECONDARY_TEXT = "programming project in C++\nAndrej Pecimuth\nZS 2019/2020";

WelcomeScene::WelcomeScene():
	timeLeft(WELCOME_SCENE_DURATION),
	title(),
	text()
{
	title.setString(App::TITLE);
	title.setCharacterSize(Sector::SIZE * 5);
	title.setFillColor(sf::Color::White);
	title.setPosition(Sector{ 2, 2 }.upperLeftPoint());
	text.setString(SECONDARY_TEXT);
	text.setCharacterSize(Sector::SIZE);
	text.setFillColor(sf::Color::White);
	text.setPosition(Sector{ 2, 12 }.upperLeftPoint());
}

void WelcomeScene::setFont(const sf::Font& font)
{
	title.setFont(font);
	text.setFont(font);
}

void WelcomeScene::setViewport(const sf::Vector2f& viewport)
{
}

void WelcomeScene::handleInput(const sf::Event& event)
{
}

void WelcomeScene::update(sf::Time delta)
{
	timeLeft -= delta;
	if (timeLeft <= sf::Time::Zero)
		requestSceneChange(SceneChangeRequest{ SceneType::Level });
}

void WelcomeScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(title, states);
	target.draw(text, states);
}
