#pragma once
#include "Tower.h"
class RocketLauncher : public Tower
{
public:
	RocketLauncher(Sector sector);
	virtual ProjectilePtr makeProjectile(Actor* actor) override;
};

