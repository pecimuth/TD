#pragma once
#include "Button.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "World.h"
#include "TowerPreview.h"
#include "PlaceTowerButton.h"

template<typename T>
class UpgradeTowerButton : public PlaceTowerButton<typename T::UPGRADE>
{
public:
	UpgradeTowerButton(const sf::Vector2f& position, const Sector& towerSector);
protected:
	virtual void onClick(World& world) override;
};

template<typename T>
UpgradeTowerButton<T>::UpgradeTowerButton(const sf::Vector2f& position, const Sector& towerSector) :
	PlaceTowerButton<typename T::UPGRADE>(position, towerSector)
{
}

template<typename T>
void UpgradeTowerButton<T>::onClick(World& world)
{
	if (T::UPGRADE::PRICE <= world.getBalance())
	{
		world.removeTower(world.getTowerAt(PlaceTowerButton<typename T::UPGRADE>::towerSector), 0);
		PlaceTowerButton<T::UPGRADE>::onClick(world);
	}
	else
		Button::onClick(world);
}
