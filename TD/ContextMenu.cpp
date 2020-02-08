#include "ContextMenu.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "World.h"
#include "PlaceTowerButton.h"
#include "GreenGun.h"
#include "RocketLauncher.h"

ContextMenu::ContextMenu():
	buttons(),
	texture(),
	font()
{
}

void ContextMenu::handleInput(const sf::Event& event, World& world)
{
	for (auto&& button : buttons)
	{
		if (button->handleInput(event, world))
			return;
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
	{
		buttons.clear();
		Sector sector = Sector::fromCoords(event.mouseButton.x * 2, event.mouseButton.y * 2);
		if (world.canPlaceTowerAt(sector))
			prepareShoppingList(sector);
	}
}

void ContextMenu::update(World& world, const sf::Vector2f& mousePosition)
{
	for (auto&& button : buttons)
		button->update(world, mousePosition);
	if (std::any_of(buttons.begin(), buttons.end(), [](const ButtonPtr& btn) { return btn->hasBeenClicked(); }))
		buttons.clear();
}

void ContextMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto&& button : buttons)
		target.draw(*button, states);
}

void ContextMenu::prepareShoppingList(const Sector& sector)
{
	insertPlaceTowerButton<GreenGun>(sector.upperLeftPoint(), sector);
	insertPlaceTowerButton<RocketLauncher>(sector.upperRightPoint(), sector);
}
