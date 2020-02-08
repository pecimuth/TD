#include "RocketLauncher.h"
#include "Rocket.h"
#include "World.h"

const int RocketLauncher::TEXTURE_ID = 227;
const float RocketLauncher::RANGE = 800.f;
const sf::Time RocketLauncher::COOLDOWN = sf::milliseconds(500);
const int RocketLauncher::PRICE = 2000;

RocketLauncher::RocketLauncher(Sector sector):
	Tower(sector, TEXTURE_ID, RANGE, COOLDOWN, PRICE)
{
}

ProjectilePtr RocketLauncher::makeProjectile(Actor* actor)
{
	return std::make_unique<Rocket>(sprite.getPosition(), actor);
}
