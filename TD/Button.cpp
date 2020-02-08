#include "Button.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

static const int TEXTURE_ID = 84;

Button::Button(const sf::Vector2f& position):
	sprite(),
	enabled(true),
	mouseIn(false),
	clicked(false)
{
	sprite.setOrigin(Sector::CENTER);
	sprite.setPosition(position);
	sprite.setTextureRect(textureRectById(TEXTURE_ID));
}

void Button::setTexture(const sf::Texture& texture)
{
	sprite.setTexture(texture);
}

bool Button::handleInput(const sf::Event& event, World& world)
{
	if (event.type == sf::Event::MouseButtonPressed
		&& event.mouseButton.button == sf::Mouse::Button::Left
		&& sprite.getGlobalBounds().contains(transformMouseCoordinates(event.mouseButton.x, event.mouseButton.y)))
	{
		onClick(world);
		return true;
	}
	return false;
}

void Button::update(World& world, const sf::Vector2f& mousePosition)
{
	mouseIn = sprite.getGlobalBounds().contains(mousePosition);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

