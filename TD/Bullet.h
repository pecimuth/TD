#pragma once
#include "Projectile.h"

class Bullet : public Projectile
{
public:
	Bullet(const sf::Vector2f& origin, Actor* target);
	virtual void update(sf::Time delta, World& world) override;
};
