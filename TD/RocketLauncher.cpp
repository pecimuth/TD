#include "RocketLauncher.h"
#include "Rocket.h"
#include "World.h"

const int RocketLauncher::TEXTURE_ID = 227;
const float RocketLauncher::RANGE = 500.f;
const sf::Time RocketLauncher::COOLDOWN = sf::seconds(1);
const int RocketLauncher::PRICE = 4000;

RocketLauncher::RocketLauncher(Sector sector):
	Tower(sector, TEXTURE_ID, RANGE, COOLDOWN, PRICE)
{
}

ProjectilePtr RocketLauncher::makeProjectile(Actor* actor)
{
	return std::make_unique<Rocket>(sprite.getPosition(), actor);
}
