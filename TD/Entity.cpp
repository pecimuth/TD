#include "Entity.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "Sector.h"

Entity::Entity(int textureId):
	sprite()
{
	sprite.setTextureRect(textureRectById(textureId));
}

void Entity::setTexture(const sf::Texture& texture)
{
	sprite.setTexture(texture);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

float Entity::distanceSquaredFrom(const sf::Vector2f& target) const
{
	return lengthSquared(target - sprite.getPosition());
}

bool Entity::isInRange(const sf::Vector2f& target, float range) const
{
	return range * range >= distanceSquaredFrom(target);
}

void Entity::rotateTowards(const sf::Vector2f& target, float angleCorrection)
{
	auto direction = target - sprite.getPosition();
	sprite.setRotation(angle(direction) + angleCorrection);
}

bool Entity::moveTowards(const sf::Vector2f& target, sf::Time delta, float speed)
{
	auto direction = target - sprite.getPosition();
	auto vel = velocity(direction, speed, delta);
	auto movementLengthSq = lengthSquared(vel);
	auto distanceSq = lengthSquared(direction);
	bool inProximity = movementLengthSq >= distanceSq;
	if (inProximity)
		vel = direction;
	sprite.move(vel);
	return inProximity;
}
