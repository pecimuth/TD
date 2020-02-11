#pragma once

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include "World.h"

class StatusBar : public sf::Drawable
{
public:
	StatusBar();
	void update(const World& world);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Text balanceText;
	sf::Text hitPointsText;
};

