#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Sector.h"
#include "Actor.h"
#include "Entity.h"
#include "Projectile.h"
#include <vector>
#include <memory>
#include "TowerType.h"

class World;

class Tower : public Entity
{
public:
	Tower(Sector sector, int textureId, float range, sf::Time cooldown, int price);
	void update(sf::Time delta, World& world) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	float getRange() const { return range; };
	int getPrice() const { return price; }
	const Sector& getSector() const { return sector; }
	static const int PLATFORM_TEXTURE_ID;
	virtual bool isUpgradeable() const { return false; }
	virtual TowerType getTowerType() const = 0;
protected:
	static const float ANGLE_CORRECTION; // towers face north on the tilesheet, must be corrected
	virtual ProjectilePtr makeProjectile(Actor* actor) = 0;
private:
	Sector sector;
	float range; // can fire at actors at most range points away from sector.midpoint()
	sf::Time cooldown; // can fire every cooldown times
	sf::Time timeAccumulated; // accumulates every step, greater/equal than cooldown => fire
	sf::Sprite platform; // only visual
	int price;
	Actor* closestActor(Actors& actors); // nullptr if there is no actor in range
};

using TowerPtr = std::unique_ptr<Tower>;
using Towers = std::vector<TowerPtr>;
