#pragma once
#include "Tower.h"

class GreenGun : public Tower
{
public:
	GreenGun(Sector sector);
	virtual ProjectilePtr makeProjectile(Actor* actor) override;
	static const int TEXTURE_ID;
	static const float RANGE;
	static const sf::Time COOLDOWN;
	static const int PRICE;
};
