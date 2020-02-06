#include "Tower.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "World.h"
#include "Bullet.h"

const float Tower::ANGLE_CORRECTION = 90;
const int PLATFORM_TEXTURE_ID = 181;

Tower::Tower(Sector sector, int textureId, float range, sf::Time cooldown):
	Entity(textureId),
	sector(sector),
	range(range),
	cooldown(cooldown),
	timeAccumulated(sf::Time::Zero),
	platform()
{
	sprite.setOrigin(Sector::CENTER);
	sprite.setPosition(sector.midpoint());
	platform.setTextureRect(textureRectById(PLATFORM_TEXTURE_ID));
	platform.setPosition(sector.upperLeftPoint());
}

void Tower::setTexture(const sf::Texture& texture)
{
	platform.setTexture(texture);
	Entity::setTexture(texture);
}

void Tower::update(sf::Time delta, World& world)
{
	timeAccumulated += delta;
	if (timeAccumulated < cooldown)
		return;

	auto actor = closestActor(world.getActors());
	if (actor != nullptr && isInRange(actor->getPosition(), range))
	{
		timeAccumulated = sf::Time::Zero;
		rotateTowards(actor->getPosition(), ANGLE_CORRECTION);
		auto projectile = makeProjectile(actor);
		projectile->setTexture(*sprite.getTexture());
		world.fire(std::move(projectile));
	}
}

void Tower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(platform, states);
	Entity::draw(target, states);
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
			minDistanceSq = distanceSquaredFrom(actor->getPosition());
			continue;
		}
		float distanceSq = distanceSquaredFrom(actor->getPosition());
		if (distanceSq < minDistanceSq)
		{
			result = &*actor;
			minDistanceSq = distanceSq;
		}
	}
	return result;
}
