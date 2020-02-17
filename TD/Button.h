#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include "Sector.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <memory>
#include <SFML/Graphics/CircleShape.hpp>

class World;

class Button : public sf::Drawable
{
public:
	Button(const sf::Vector2f& position, int iconTextureId);
	virtual ~Button() {};
	bool handleInput(const sf::Event& event, World& world);
	void update(World& world, const sf::Vector2f& mousePosition);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool hasBeenClicked() const { return clicked; };
protected:
	bool mouseHovers() const { return mouseIn; }
	virtual void onClick(World& world); // call this in overridden methods
private:
	sf::CircleShape sprite; // background
	sf::Sprite icon; // foreground
	bool mouseIn; // mouse hovers on button?
	bool clicked; // has this ever been clicked?
};

using ButtonPtr = std::unique_ptr<Button>;
using Buttons = std::vector<ButtonPtr>;