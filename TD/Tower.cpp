#include "Tower.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "World.h"
#include "Bullet.h"
#include "Assets.h"

const float Tower::ANGLE_CORRECTION = 90;
const int Tower::PLATFORM_TEXTURE_ID = 181;

Tower::Tower(Sector sector, int textureId, float range, sf::Time cooldown, int price):
	Entity(textureId),
	sector(sector),
	range(range),
	cooldown(cooldown),
	timeAccumulated(sf::Time::Zero),
	platform(),
	price(price)
{
	sprite.setOrigin(Sector::CENTER);
	sprite.setPosition(sector.midpoint());
	platform.setTextureRect(textureRectById(PLATFORM_TEXTURE_ID));
	platform.setPosition(sector.upperLeftPoint());
	platform.setTexture(Assets::get().texture);
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
		Assets::get().audio.play(projectile->getSoundEffect());
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
