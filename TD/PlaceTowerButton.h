#pragma once
#include "Button.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "World.h"

template<typename T>
class PlaceTowerButton : public Button
{
public:
	PlaceTowerButton(const sf::Vector2f& position, Sector towerSector);
	virtual void setTexture(const sf::Texture& texture) override;
	virtual void setFont(const sf::Font& font) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	virtual void onClick(World& world) override;
private:
	Sector towerSector;
	sf::Sprite icon;
	sf::Text price;
	sf::CircleShape rangeIndicator;
};

template<typename T>
PlaceTowerButton<T>::PlaceTowerButton(const sf::Vector2f& position, Sector towerSector):
	Button(position),
	towerSector(towerSector),
	icon(),
	price(),
	rangeIndicator()
{
	icon.setOrigin(Sector::CENTER);
	icon.setTextureRect(textureRectById(T::TEXTURE_ID));
	icon.setPosition(position);
	price.setOrigin(Sector::CENTER);
	price.setFillColor(sf::Color::Yellow);
	price.setCharacterSize(32);
	price.setString('$' + std::to_string(T::PRICE));
	price.setPosition(position);
	rangeIndicator.setFillColor(sf::Color(149, 202, 255, 100));
	rangeIndicator.setOrigin(sf::Vector2f(T::RANGE, T::RANGE) / 2.f);
	rangeIndicator.setRadius(T::RANGE);
	rangeIndicator.setPosition(position);
}

template<typename T>
inline void PlaceTowerButton<T>::setTexture(const sf::Texture& texture)
{
	Button::setTexture(texture);
	icon.setTexture(texture);
}

template<typename T>
inline void PlaceTowerButton<T>::setFont(const sf::Font& font)
{
	price.setFont(font);
}

template<typename T>
void PlaceTowerButton<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (mouseHovers())
		target.draw(rangeIndicator, states);
	Button::draw(target, states);
	target.draw(icon, states);
	target.draw(price, states);	
}

template<typename T>
void PlaceTowerButton<T>::onClick(World& world)
{
	Button::onClick(world);
	auto tower = std::make_unique<T>(towerSector);
	tower->setTexture(*icon.getTexture());
	world.placeTower(std::move(tower), T::PRICE);
}
