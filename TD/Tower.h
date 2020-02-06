#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Sector.h"
#include "Actor.h"
#include "Entity.h"
#include <vector>
#include <memory>

class World;

class Tower : public Entity
{
public:
	Tower(Sector sector, int textureId, float range, sf::Time cooldown);
	void setTexture(const sf::Texture& texture) override;
	void update(sf::Time delta, World& world) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	static const float ANGLE_CORRECTION;
	Sector sector;
	float range;
	sf::Time cooldown;
	virtual void fireAt(Actor* actor, World& world);
private:
	sf::Time timeAccumulated;
	sf::Sprite platform;
	Actor* closestActor(Actors& actors);
};

using TowerPtr = std::unique_ptr<Tower>;
using Towers = std::vector<TowerPtr>;
