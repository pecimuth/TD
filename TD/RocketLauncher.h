#pragma once
#include "Tower.h"

class RocketLauncher : public Tower
{
public:
	RocketLauncher(Sector sector);
	virtual ProjectilePtr makeProjectile(Actor* actor) override;
	static const int TEXTURE_ID;
	static const float RANGE;
	static const sf::Time COOLDOWN;
	static const int PRICE;
	virtual TowerType getTowerType() const override { return TowerType::RocketLauncher; };
};
