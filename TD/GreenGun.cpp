#include "GreenGun.h"
#include "Bullet.h"

const int GreenGun::TEXTURE_ID = 249;
const float GreenGun::RANGE = 300.f;
const sf::Time GreenGun::COOLDOWN = sf::milliseconds(900);
const int GreenGun::PRICE = 800;

GreenGun::GreenGun(Sector sector) :
	Tower(sector, TEXTURE_ID, RANGE, COOLDOWN, PRICE)
{
}

ProjectilePtr GreenGun::makeProjectile(Actor* actor)
{
	return std::make_unique<Bullet>(sprite.getPosition(), actor);
}
