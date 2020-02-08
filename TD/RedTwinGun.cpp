#include "RedTwinGun.h"
#include <SFML/System/Time.hpp>
#include "Bullet.h"
#include "World.h"

static const float TWIN_OFFSET = 7.f;
const int RedTwinGun::TEXTURE_ID = 250;
const float RedTwinGun::RANGE = 300.f;
const sf::Time RedTwinGun::COOLDOWN = sf::milliseconds(300);
const int RedTwinGun::PRICE = 1000;

RedTwinGun::RedTwinGun(Sector sector) :
	Tower(sector, TEXTURE_ID, RANGE, COOLDOWN, PRICE),
	leftTwinFiredLast(false)
{
}

ProjectilePtr RedTwinGun::makeProjectile(Actor* actor)
{
	sf::Vector2f origin = sprite.getPosition();
	float towerRotation = toRadians(sprite.getRotation());
	auto offset = vectorFromRadians(towerRotation) * TWIN_OFFSET;
	if (leftTwinFiredLast)
		origin += offset;
	else
		origin -= offset;
	leftTwinFiredLast = !leftTwinFiredLast;
	return std::make_unique<Bullet>(origin, actor);
}
