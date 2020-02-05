#include "Tower.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "World.h"
#include "Projectile.h"

Tower::Tower(Sector sector, int textureId, float range, sf::Time cooldown):
	sector(sector),
	range(range),
	cooldown(cooldown),
	timeAccumulated(sf::Time::Zero),
	sprite(),
	platform()
{
	sprite.setOrigin(Sector::CENTER);
	sprite.setTextureRect(textureRectById(textureId));
	sprite.setPosition(sector.midpoint());
	platform.setTextureRect(textureRectById(180));
	platform.setPosition(sector.upperLeftPoint());
}

void Tower::update(sf::Time delta, World& world)
{
	timeAccumulated += delta;
	if (timeAccumulated >= cooldown)
	{
		auto actor = closestActor(world.getActors());
		if (actor == nullptr)
			return;
		auto direction = actor->getPosition() - sprite.getPosition();
		float distanceSquared = lengthSquared(direction);
		if (range * range >= distanceSquared)
		{
			timeAccumulated = sf::Time::Zero;
			sprite.setRotation(angle(direction) + 90);
			world.fire(Projectile(272, 500.f, 20, sprite.getPosition(), actor));
		}
	}
}

void Tower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	platform.setTexture(*states.texture);
	sprite.setTexture(*states.texture);
	target.draw(platform, states);
	target.draw(sprite, states);
}

Actor* Tower::closestActor(Actors& actors)
{
	Actor* result = nullptr;
	float minDistanceSq = 0;
	for (auto&& actor : actors)
	{
		if (result == nullptr)
		{
			result = &*actor;
			minDistanceSq = lengthSquared(actor->getPosition() - sprite.getPosition());
			continue;
		}
		float distanceSq = lengthSquared(actor->getPosition() - sprite.getPosition());
		if (distanceSq < minDistanceSq)
		{
			result = &*actor;
			minDistanceSq = distanceSq;
		}
	}
	return result;
}
