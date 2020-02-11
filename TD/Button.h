#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "Sector.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <vector>
#include <memory>
#include <SFML/Graphics/CircleShape.hpp>
#include "Audio.h"

class World;

class Button : public sf::Drawable
{
public:
	Button(const sf::Vector2f& position);
	bool handleInput(const sf::Event& event, World& world);
	void update(World& world, const sf::Vector2f& mousePosition);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void setEnabled(bool enabledValue) { enabled = enabledValue; }
	bool isEnabled() const { return enabled; }
	bool hasBeenClicked() const { return clicked; };
protected:
	bool mouseHovers() const { return mouseIn; }
	virtual void onClick(World& world);
private:
	sf::CircleShape sprite;
	bool enabled;
	bool mouseIn;
	bool clicked;
};

using ButtonPtr = std::unique_ptr<Button>;
using Buttons = std::vector<ButtonPtr>;