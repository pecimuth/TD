#include "Projectile.h"
#include "Sector.h"
#include "Actor.h"
#include <SFML/Graphics/RenderTarget.hpp>

const float Projectile::EPSILON = 0.000001;

Projectile::Projectile(int textureId, float speed, int damage, const sf::Vector2f& origin, Actor* target):
	Entity(textureId),
	speed(speed),
	damage(damage),
	target(target)
{
	sprite.setOrigin(Sector::CENTER);
	sprite.setPosition(origin);
}

bool Projectile::toRemove() const
{
	return target == nullptr || target->toRemove() || reachedDestination();
}

bool Projectile::reachedDestination() const
{
	return isInRange(target->getPosition(), EPSILON);
}

void Projectile::update(sf::Time delta, World& world)
{
	if (target != nullptr && moveTowards(target->getPosition(), delta, speed))
		target->damage(damage);
}
