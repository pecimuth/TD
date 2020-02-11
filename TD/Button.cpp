#include "Button.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include "Assets.h"

static const float BTN_RADIUS = 48.f;
static const sf::Color BTN_FILL_COLOR = sf::Color(200, 200, 200, 180);
static const sf::Color BTN_OUTLINE_COLOR = sf::Color(150, 150, 150);
static const float BTN_OUTLINE_THICKNESS = 2.f;
static const sf::Vector2f TOWER_PLACE_BTN_SCALE(1.5f, 1.5f);

Button::Button(const sf::Vector2f& position, int iconTextureId):
	sprite(),
	mouseIn(false),
	clicked(false)
{
	sprite.setPosition(position);
	sprite.setRadius(BTN_RADIUS);
	sprite.setOrigin(BTN_RADIUS, BTN_RADIUS);
	sprite.setFillColor(BTN_FILL_COLOR);
	sprite.setOutlineColor(BTN_OUTLINE_COLOR);
	sprite.setOutlineThickness(BTN_OUTLINE_THICKNESS);
	icon.setOrigin(Sector::CENTER);
	icon.setTextureRect(textureRectById(iconTextureId));
	icon.setPosition(position);
	icon.setScale(TOWER_PLACE_BTN_SCALE);
	icon.setTexture(Assets::get().texture);
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
	target.draw(icon, states);
}

void Button::onClick(World& world)
{
	clicked = true;
	Assets::get().audio.play(SoundEffect::Select);
}
