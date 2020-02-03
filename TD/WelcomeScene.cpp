#include "WelcomeScene.h"

#include <SFML/Graphics.hpp>

#include "SceneType.h"
#include "SceneChangeRequest.h"

const sf::Time WelcomeScene::WELCOME_SCENE_DURATION = sf::seconds(1);

WelcomeScene::WelcomeScene():
	timeLeft(WELCOME_SCENE_DURATION)
{
}

void WelcomeScene::handleInput(const sf::Event& event)
{
}

void WelcomeScene::update(sf::Time delta)
{
	timeLeft -= delta;
	if (timeLeft <= sf::Time::Zero)
	{
		requestSceneChange(SceneChangeRequest{ SceneType::Level });
	}
}

void WelcomeScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	target.draw(shape, states);
}
