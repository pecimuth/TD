#pragma once
#include "Tower.h"
#include "Sector.h"

class RedTwinGun : public Tower
{
public:
	RedTwinGun(Sector sector);
	virtual ProjectilePtr makeProjectile(Actor* actor) override;
private:
	bool leftTwinFiredLast;
};
