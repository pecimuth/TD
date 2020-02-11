#include "Price.h"
#include "Assets.h"

static const int PRICE_FONT_SIZE = 32;
static const sf::Color POSITIVE_PRICE_COLOR = sf::Color(0, 100, 0);
static const sf::Color NEGATIVE_PRICE_COLOR = sf::Color(178, 34, 34);

Price::Price(int value, const sf::Vector2f& position)
{
	price.setFillColor(colorByValue(value));
	price.setCharacterSize(PRICE_FONT_SIZE);
	price.setString(contentsByValue(value));
	price.setPosition(position);
	price.setFont(Assets::get().font);
}

void Price::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(price, states);
}

sf::Color Price::colorByValue(int value)
{
	return (value >= 0) ? POSITIVE_PRICE_COLOR : NEGATIVE_PRICE_COLOR;
}

std::string Price::contentsByValue(int value)
{
	return ((value >= 0) ? "+$" : "-$") + std::to_string(abs(value));
}
