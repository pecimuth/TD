#pragma once
#include "Tower.h"
#include "Sector.h"

class RedTwinGun : public Tower
{
public:
	RedTwinGun(Sector sector);
	virtual void fireAt(Actor* actor, World& world) override;
private:
	bool leftTwinFiredLast;
};

