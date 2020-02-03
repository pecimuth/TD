#include "Actor.h"
#include "Sector.h"
#include <SFML/Graphics/RenderTarget.hpp>

Actor::Actor(PathIterator start, PathIterator finish, int textureId, float moveSpeed, int hitPoints):
	start(start),
	finish(finish),
	moveSpeed(moveSpeed),
	hitPoints(hitPoints),
	sprite()
{
	sprite.setTextureRect(textureRectById(textureId));
	sprite.setOrigin(Sector::CENTER);
	if (start != finish)
	{
		sprite.setPosition(start->midpoint());
		++start;
		headDestination();
	}
}

void Actor::move(sf::Time delta)
{
	if (toRemove())
		return;
	sf::Vector2f dest = start->midpoint();
	auto direction = dest - sprite.getPosition();
	auto vel = velocity(direction, moveSpeed, delta);
	auto movementLengthSq = lengthSquared(vel);
	auto distanceSq = lengthSquared(direction);
	if (movementLengthSq >= distanceSq)
	{
		vel = direction;
		++start;
		headDestination();
	}
	sprite.move(vel);
}

void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sprite.setTexture(*states.texture);
	target.draw(sprite, states);
}

void Actor::headDestination()
{
	if (start != finish)
	{
		auto direction = start->midpoint() - sprite.getPosition();
		sprite.setRotation(atan2(direction.y, direction.x) * 180 / 3.14159265);
	}
}
