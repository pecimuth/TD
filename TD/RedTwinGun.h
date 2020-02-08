#pragma once
#include "Tower.h"
#include "Sector.h"

class RedTwinGun : public Tower
{
public:
	RedTwinGun(Sector sector);
	virtual ProjectilePtr makeProjectile(Actor* actor) override;
	static const int TEXTURE_ID;
	static const float RANGE;
	static const sf::Time COOLDOWN;
	static const int PRICE;
private:
	bool leftTwinFiredLast;
};
