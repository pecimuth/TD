#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "World.h"

template<typename T>
class TowerPreview : public sf::Drawable
{
public:
	TowerPreview(const Sector& sector);
	void setTexture(const sf::Texture& texture);
	void setFont(const sf::Font& font);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Sprite towerPreview;
	sf::Sprite platformPreview;
	sf::Text price;
	sf::CircleShape rangeIndicator;
};

static const int PRICE_FONT_SIZE = 32;
static const sf::Color TOWER_PRICE_COLOR = sf::Color(178, 34, 34);
static const sf::Color RANGE_INDICATOR_COLOR = sf::Color(30, 144, 255, 70);

template<typename T>
TowerPreview<T>::TowerPreview(const Sector& sector) :
	towerPreview(),
	platformPreview(),
	price(),
	rangeIndicator()
{
	towerPreview.setOrigin(Sector::CENTER);
	towerPreview.setTextureRect(textureRectById(T::TEXTURE_ID));
	towerPreview.setPosition(sector.midpoint());
	platformPreview.setOrigin(Sector::CENTER);
	platformPreview.setTextureRect(textureRectById(Tower::PLATFORM_TEXTURE_ID));
	platformPreview.setPosition(sector.midpoint());
	price.setFillColor(TOWER_PRICE_COLOR);
	price.setCharacterSize(PRICE_FONT_SIZE);
	price.setString("-$" + std::to_string(T::PRICE));
	price.setPosition(sector.bottomLeftPoint());
	rangeIndicator.setFillColor(RANGE_INDICATOR_COLOR);
	rangeIndicator.setRadius(T::RANGE);
	rangeIndicator.setOrigin(sf::Vector2f(T::RANGE, T::RANGE));
	rangeIndicator.setPosition(sector.midpoint());
}

template<typename T>
void TowerPreview<T>::setTexture(const sf::Texture& texture)
{
	towerPreview.setTexture(texture);
	platformPreview.setTexture(texture);
}

template<typename T>
void TowerPreview<T>::setFont(const sf::Font& font)
{
	price.setFont(font);
}

template<typename T>
void TowerPreview<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rangeIndicator, states);
	target.draw(platformPreview, states);
	target.draw(towerPreview, states);
	target.draw(price, states);
}
