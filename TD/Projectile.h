#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <memory>
#include "Entity.h"
#include "Audio.h"

class Actor;

class Projectile : public Entity
{
public:
	Projectile(int textureId, float speed, int damage, const sf::Vector2f& origin, Actor* target, SoundEffect effect);
	bool toRemove() const;
	virtual void update(sf::Time delta, World& world) override;
	SoundEffect getSoundEffect() const { return effect; }
protected:
	static const float EPSILON;
	float speed;
	int damage;
	Actor* target;
	bool reachedDestination() const;
private:
	SoundEffect effect;
};

using ProjectilePtr = std::unique_ptr<Projectile>;
using Projectiles = std::vector<ProjectilePtr>;
