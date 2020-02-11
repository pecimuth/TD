#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "World.h"
#include "Assets.h"
#include "Price.h"

template<typename T>
class TowerPreview : public sf::Drawable
{
public:
	TowerPreview(const Sector& sector);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Sprite towerPreview;
	sf::Sprite platformPreview;
	Price price;
	sf::CircleShape rangeIndicator;
};

template<typename T>
TowerPreview<T>::TowerPreview(const Sector& sector) :
	towerPreview(),
	platformPreview(),
	price(-T::PRICE, sector.bottomLeftPoint()),
	rangeIndicator()
{
	const sf::Color RANGE_INDICATOR_COLOR = sf::Color(30, 144, 255, 70);
	towerPreview.setOrigin(Sector::CENTER);
	towerPreview.setTextureRect(textureRectById(T::TEXTURE_ID));
	towerPreview.setPosition(sector.midpoint());
	platformPreview.setOrigin(Sector::CENTER);
	platformPreview.setTextureRect(textureRectById(Tower::PLATFORM_TEXTURE_ID));
	platformPreview.setPosition(sector.midpoint());
	rangeIndicator.setFillColor(RANGE_INDICATOR_COLOR);
	rangeIndicator.setRadius(T::RANGE);
	rangeIndicator.setOrigin(sf::Vector2f(T::RANGE, T::RANGE));
	rangeIndicator.setPosition(sector.midpoint());
	auto& texture = Assets::get().texture;
	towerPreview.setTexture(texture);
	platformPreview.setTexture(texture);
}

template<typename T>
void TowerPreview<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rangeIndicator, states);
	target.draw(platformPreview, states);
	target.draw(towerPreview, states);
	target.draw(price, states);
}
