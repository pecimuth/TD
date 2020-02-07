#include "WelcomeScene.h"

#include <SFML/Graphics.hpp>

#include "SceneType.h"
#include "SceneChangeRequest.h"
#include "App.h"

const sf::Time WELCOME_SCENE_DURATION = sf::seconds(1);

WelcomeScene::WelcomeScene():
	timeLeft(WELCOME_SCENE_DURATION),
	text()
{
	text.setString(App::TITLE);
	text.setCharacterSize(128);
	shape.setSize(sf::Vector2f(128.f, 128.f));
	text.setFillColor(sf::Color::White);
	shape.setFillColor(sf::Color::Red);
}

void WelcomeScene::setFont(const sf::Font& font)
{
	text.setFont(font);
}

void WelcomeScene::setViewport(const sf::Vector2f& viewport)
{
	auto bounds = text.getGlobalBounds();
	text.setOrigin(sf::Vector2f(64.f, 64.f));
	text.setPosition(viewport / 2.f);
	shape.setOrigin(sf::Vector2f(64.f, 64.f));
	shape.setPosition(viewport / 2.f);
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
	target.draw(shape);
	target.draw(text);
}
