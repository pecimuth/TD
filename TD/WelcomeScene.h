#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Scene.h"

class WelcomeScene : public Scene
{
public:
	WelcomeScene();
	virtual ~WelcomeScene() {}
	virtual void setTexture(const sf::Texture& texture) override {};
	virtual void handleInput(const sf::Event& event) override;
	virtual void update(sf::Time delta) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Time timeLeft;
	static const sf::Time WELCOME_SCENE_DURATION;
};
