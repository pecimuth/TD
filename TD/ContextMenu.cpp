#include "ContextMenu.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "World.h"
#include "PlaceTowerButton.h"
#include "GreenGun.h"
#include "RocketLauncher.h"

static const sf::Color HOVER_POSITIVE_COLOR = sf::Color(65, 105, 225, 128);
static const sf::Color HOVER_NEGATIVE_COLOR = sf::Color(255, 0, 0, 128);
static const sf::Color ACTIVE_COLOR = HOVER_POSITIVE_COLOR;
static const float OUTLINE_THICKNESS = 2.f;

ContextMenu::ContextMenu():
	buttons(),
	texture(),
	font(),
	hoverIndicator(),
	showActiveIndicator(false),
	activeIndicator()
{
	hoverIndicator.setSize(Sector::DIAGONAL);
	hoverIndicator.setFillColor(sf::Color::Transparent);
	hoverIndicator.setOutlineThickness(OUTLINE_THICKNESS);
	activeIndicator.setSize(Sector::DIAGONAL);
	activeIndicator.setFillColor(sf::Color::Transparent);
	activeIndicator.setOutlineColor(ACTIVE_COLOR);
	activeIndicator.setOutlineThickness(OUTLINE_THICKNESS);
}

void ContextMenu::handleInput(const sf::Event& event, World& world)
{
	for (auto&& button : buttons)
	{
		if (button->handleInput(event, world))
		{
			showActiveIndicator = false;
			return;
		}
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
	{
		showActiveIndicator = false;
		if (!buttons.empty())
			buttons.clear();
		else
		{
			Sector sector = Sector::fromCoords(transformMouseCoordinates(event.mouseButton.x, event.mouseButton.y));
			if (world.canPlaceTowerAt(sector))
			{
				showActiveIndicator = true;
				activeIndicator.setPosition(sector.upperLeftPoint());
				prepareShoppingList(sector);
			}
		}
	}
}

void ContextMenu::update(World& world, const sf::Vector2f& mousePosition)
{
	for (auto&& button : buttons)
		button->update(world, mousePosition);
	if (std::any_of(buttons.begin(), buttons.end(), [](const ButtonPtr& btn) { return btn->hasBeenClicked(); }))
		buttons.clear();
	Sector hoverSector = Sector::fromCoords(mousePosition);
	hoverIndicator.setPosition(hoverSector.upperLeftPoint());
	hoverIndicator.setOutlineColor(world.getGrid().isBuildingAllowedAt(hoverSector) ? HOVER_POSITIVE_COLOR : HOVER_NEGATIVE_COLOR);
}

void ContextMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(showActiveIndicator ? activeIndicator : hoverIndicator, states);
	for (auto&& button : buttons)
		target.draw(*button, states);
}

void ContextMenu::prepareShoppingList(const Sector& sector)
{
	insertPlaceTowerButton<GreenGun>((sector + Sector{ -1, -1 }).midpoint(), sector);
	insertPlaceTowerButton<RocketLauncher>((sector + Sector{ 1, -1 }).midpoint(), sector);
}
