#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <memory>
#include "Entity.h"

class Actor;

class Projectile : public Entity
{
public:
	Projectile(int textureId, float speed, int damage, const sf::Vector2f& origin, Actor* target);
	bool toRemove() const;
	virtual void update(sf::Time delta, World& world) override;
protected:
	static const float EPSILON;
	float speed;
	int damage;
	Actor* target;
	bool reachedDestination() const;
};

using ProjectilePtr = std::unique_ptr<Projectile>;
using Projectiles = std::vector<ProjectilePtr>;
