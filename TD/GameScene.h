#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "Scene.h"
#include "World.h"
#include "StatusBar.h"
#include "ContextMenu.h"
#include "Director.h"

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene() {}
	virtual void handleInput(const sf::Event& event) override;
	virtual void update(sf::Time delta) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	World world;
	StatusBar statusBar;
	ContextMenu contextMenu;
	Director director;
};

