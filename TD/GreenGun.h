#pragma once
#include "Tower.h"
#include "RedTwinGun.h"

class GreenGun : public Tower
{
public:
	GreenGun(Sector sector);
	virtual ProjectilePtr makeProjectile(Actor* actor) override;
	static const int TEXTURE_ID;
	static const float RANGE;
	static const sf::Time COOLDOWN;
	static const int PRICE;
	using UPGRADE = RedTwinGun;
	virtual bool isUpgradeable() const override { return true; }
	virtual TowerType getTowerType() const override { return TowerType::GreenGun; };
};
