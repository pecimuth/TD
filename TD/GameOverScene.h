#pragma once
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Scene.h"

class GameOverScene : public Scene
{
public:
	GameOverScene(int waveNumber);
	virtual ~GameOverScene() {}
	virtual void handleInput(const sf::Event& event) override;
	virtual void update(sf::Time delta) override {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Text title;
	sf::Text text;
};
