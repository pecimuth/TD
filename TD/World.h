#pragma once
#include "Grid.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Time.hpp>
#include "Actor.h"
#include <vector>

class World : public sf::Drawable
{
public:
	World();
	void update(sf::Time delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	Grid grid;
	std::vector<Actor> actors;
};

