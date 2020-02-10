#include "ContextMenu.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "World.h"
#include "PlaceTowerButton.h"
#include "GreenGun.h"
#include "RocketLauncher.h"
#include "UpgradeTowerButton.h"
#include "SellTowerButton.h"

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
			auto tower = world.getTowerAt(sector);
			auto allowedBuilding = world.getGrid().isBuildingAllowedAt(sector);

			if (tower != nullptr || allowedBuilding)
			{
				showActiveIndicator = true;
				activeIndicator.setPosition(sector.upperLeftPoint());
				if (tower == nullptr)
					prepareShoppingList(sector);
				else
					prepareEditList(*tower);
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

void ContextMenu::prepareEditList(const Tower& tower)
{
	insertUpgradeTowerButton((tower.getSector() + Sector{ -1, -1 }).midpoint(), tower);
	insertButton(std::make_unique<SellTowerButton>((tower.getSector() + Sector{ 1, -1 }).midpoint(), tower));
}

void ContextMenu::insertButton(ButtonPtr&& btn)
{
	btn->setTexture(*texture);
	btn->setFont(*font);
	buttons.push_back(std::move(btn));
}

void ContextMenu::insertUpgradeTowerButton(const sf::Vector2f& position, const Tower& tower)
{
	if (!tower.isUpgradeable())
		return;

	switch (tower.getTowerType())
	{
	case TowerType::GreenGun:
		insertButton(std::make_unique<UpgradeTowerButton<GreenGun>>(position, tower.getSector()));
		break;
	default:
		break;
	}
}
