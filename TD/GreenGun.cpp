#include "GreenGun.h"
#include "Bullet.h"

const int TEXTURE_ID = 249;
const float RANGE = 300.f;
const sf::Time COOLDOWN = sf::milliseconds(300);

GreenGun::GreenGun(Sector sector) :
	Tower(sector, TEXTURE_ID, RANGE, COOLDOWN)
{
}

ProjectilePtr GreenGun::makeProjectile(Actor* actor)
{
	return std::make_unique<Bullet>(sprite.getPosition(), actor);
}
