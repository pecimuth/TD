#pragma once
#include "Tower.h"

class GreenGun : public Tower
{
public:
	GreenGun(Sector sector);
	virtual ProjectilePtr makeProjectile(Actor* actor) override;
};
