#pragma once
#include "Projectile.h"

class Rocket : public Projectile
{
public:
	Rocket(const sf::Vector2f& origin, Actor* target);
	virtual void update(sf::Time delta, World& world) override;
};

