#include "Projectile.h"
#include "Sector.h"
#include "Actor.h"
#include <SFML/Graphics/RenderTarget.hpp>

const float Projectile::EPSILON = 0.001;

Projectile::Projectile(int textureId, float speed, int damage, const sf::Vector2f& origin, Actor* target):
	speed(speed),
	damage(damage),
	target(target),
	sprite()
{
	sprite.setOrigin(Sector::CENTER);
	sprite.setTextureRect(textureRectById(textureId));
	sprite.setPosition(origin);
}

bool Projectile::toRemove() const
{
	return target == nullptr || target->toRemove() || reachedDestination();
}

bool Projectile::reachedDestination() const
{
	return lengthSquared(target->getPosition() - sprite.getPosition()) < EPSILON;
}

void Projectile::update(sf::Time delta)
{
	if (target == nullptr)
		return;
	auto direction = target->getPosition() - sprite.getPosition();
	auto vel = velocity(direction, speed, delta);
	auto movementLengthSq = lengthSquared(vel);
	auto distanceSq = lengthSquared(direction);
	if (movementLengthSq >= distanceSq)
		vel = direction;
	sprite.move(vel);
	if (reachedDestination())
		target->damage(damage);
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sprite.setTexture(*states.texture);
	target.draw(sprite, states);
}
