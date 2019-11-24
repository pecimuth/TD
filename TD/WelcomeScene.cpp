#include "WelcomeScene.h"

#include <SFML/Graphics.hpp>

void WelcomeScene::handleInput(const sf::Event& event)
{
}

void WelcomeScene::update(sf::Time delta)
{
}

void WelcomeScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	target.draw(shape, states);
}
