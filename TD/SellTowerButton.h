#pragma once
#include "Button.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "World.h"

class SellTowerButton : public Button
{
public:
	SellTowerButton(const sf::Vector2f& position, const Tower& tower);
	virtual void setTexture(const sf::Texture& texture) override;
	virtual void setFont(const sf::Font& font) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	virtual void onClick(World& world) override;
private:
	const Tower& tower;
	sf::Sprite icon;
	sf::Text price;
};
