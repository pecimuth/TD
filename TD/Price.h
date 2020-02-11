#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>

class Price : public sf::Drawable
{
public:
	Price(int value, const sf::Vector2f& position);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Text price;
	static sf::Color colorByValue(int value);
	static std::string contentsByValue(int value);
};
