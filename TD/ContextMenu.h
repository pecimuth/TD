#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include "Button.h"
#include <SFML/Graphics/Font.hpp>
#include "PlaceTowerButton.h"
#include <SFML/Graphics/RectangleShape.hpp>

class ContextMenu : public sf::Drawable
{
public:
	ContextMenu();
	void handleInput(const sf::Event& event, World& world);
	void setTexture(const sf::Texture& newTexture) { texture = &newTexture; }
	void setFont(const sf::Font& newFont) { font = &newFont; }
	void update(World& world, const sf::Vector2f& mousePosition);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	Buttons buttons;
	const sf::Texture* texture;
	const sf::Font* font;

	sf::RectangleShape hoverIndicator;
	bool showActiveIndicator;
	sf::RectangleShape activeIndicator;

	void prepareShoppingList(const Sector& sector);
	void prepareEditList(const Tower& tower);

	void insertButton(ButtonPtr&& btn);
	void insertUpgradeTowerButton(const sf::Vector2f& position, const Tower& tower);

	template<typename T>
	void insertPlaceTowerButton(const sf::Vector2f& position, const Sector& towerSector);
};

template<typename T>
void ContextMenu::insertPlaceTowerButton(const sf::Vector2f& position, const Sector& towerSector)
{
	insertButton(std::make_unique<PlaceTowerButton<T>>(position, towerSector));
}

