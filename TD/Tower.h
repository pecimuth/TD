#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Sector.h"
#include "Actor.h"
#include <vector>

class World;

class Tower : public sf::Drawable
{
public:
	Tower(Sector sector, int textureId, float range, sf::Time cooldown);
	void update(sf::Time delta, World& world);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	Sector sector;
	float range;
	sf::Time cooldown;
	sf::Time timeAccumulated;
	mutable sf::Sprite sprite;
	mutable sf::Sprite platform;
	Actor* closestActor(Actors& actors);
};

using Towers = std::vector<Tower>;
