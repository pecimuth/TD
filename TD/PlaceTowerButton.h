#pragma once
#include "Button.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "World.h"
#include "TowerPreview.h"

template<typename T>
class PlaceTowerButton : public Button
{
public:
	PlaceTowerButton(const sf::Vector2f& position, const Sector& towerSector);
	virtual void setTexture(const sf::Texture& texture) override;
	virtual void setFont(const sf::Font& font) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	virtual void onClick(World& world) override;
	Sector towerSector;
private:
	sf::Sprite icon;
	TowerPreview<T> preview;
};

static const sf::Vector2f TOWER_PLACE_BTN_SCALE(1.5f, 1.5f);

template<typename T>
PlaceTowerButton<T>::PlaceTowerButton(const sf::Vector2f& position, const Sector& towerSector):
	Button(position),
	towerSector(towerSector),
	icon(),
	preview(towerSector)
{
	icon.setOrigin(Sector::CENTER);
	icon.setTextureRect(textureRectById(T::TEXTURE_ID));
	icon.setPosition(position);
	icon.setScale(TOWER_PLACE_BTN_SCALE);
}

template<typename T>
inline void PlaceTowerButton<T>::setTexture(const sf::Texture& texture)
{
	icon.setTexture(texture);
	preview.setTexture(texture);
}

template<typename T>
inline void PlaceTowerButton<T>::setFont(const sf::Font& font)
{
	preview.setFont(font);
}

template<typename T>
void PlaceTowerButton<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (mouseHovers())
		target.draw(preview, states);
	Button::draw(target, states);
	target.draw(icon, states);
}

template<typename T>
void PlaceTowerButton<T>::onClick(World& world)
{
	Button::onClick(world);
	auto tower = std::make_unique<T>(towerSector);
	tower->setTexture(*icon.getTexture());
	tower->setAudio(*getAudio());
	world.placeTower(std::move(tower), T::PRICE);
}
