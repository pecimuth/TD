#include "RocketLauncher.h"
#include "Rocket.h"
#include "World.h"

const int TEXTURE_ID = 227;
const float RANGE = 800.f;
const sf::Time COOLDOWN = sf::milliseconds(500);

RocketLauncher::RocketLauncher(Sector sector):
	Tower(sector, TEXTURE_ID, RANGE, COOLDOWN)
{
}

ProjectilePtr RocketLauncher::makeProjectile(Actor* actor)
{
	return std::make_unique<Rocket>(sprite.getPosition(), actor);
}
