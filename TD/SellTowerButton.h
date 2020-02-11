#pragma once
#include "Button.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "World.h"
#include "Price.h"

class SellTowerButton : public Button
{
public:
	SellTowerButton(const sf::Vector2f& position, const Tower& tower);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	virtual void onClick(World& world) override;
private:
	const Tower& tower;
	Price price;
	static int resellValue(const Tower& tower);
};
