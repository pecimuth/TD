#include "RedTwinGun.h"
#include <SFML/System/Time.hpp>
#include "Projectile.h"
#include "World.h"

const float TWIN_OFFSET = 7.f;
const int TEXTURE_ID = 250;
const float RANGE = 300.f;
const sf::Time COOLDOWN = sf::milliseconds(300);

RedTwinGun::RedTwinGun(Sector sector) :
	Tower(sector, TEXTURE_ID, RANGE, COOLDOWN),
	leftTwinFiredLast(false)
{
}

void RedTwinGun::fireAt(Actor* actor, World& world)
{
	sf::Vector2f origin = sprite.getPosition();
	float towerRotation = toRadians(sprite.getRotation() - ANGLE_CORRECTION);
	auto offset = vectorFromRadians(towerRotation) * TWIN_OFFSET;
	if (leftTwinFiredLast)
		origin += offset;
	else
		origin -= offset;
	leftTwinFiredLast = !leftTwinFiredLast;
	world.fire(Projectile(272, 500.f, 20, origin, actor));
}
