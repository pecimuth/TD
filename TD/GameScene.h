#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "Scene.h"
#include "World.h"

class GameScene : public Scene
{
public:
	GameScene(): world() {};
	virtual ~GameScene() {}
	virtual void setTexture(const sf::Texture& texture) override;
	virtual void setFont(const sf::Font& font) override {};
	virtual void setViewport(const sf::Vector2f& viewport) override {};
	virtual void handleInput(const sf::Event& event) override {};
	virtual void update(sf::Time delta) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	World world;
};

