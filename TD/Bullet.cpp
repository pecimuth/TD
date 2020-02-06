#include "Bullet.h"
#include "Actor.h"

const int TEXTURE_ID = 272;
const float SPEED = 500.f;
const int DAMAGE = 20;

Bullet::Bullet(const sf::Vector2f& origin, Actor* target):
	Projectile(TEXTURE_ID, SPEED, DAMAGE, origin, target)
{
}

void Bullet::update(sf::Time delta, World& world)
{
	if (target == nullptr)
		return;
	rotateTowards(target->getPosition());
	Projectile::update(delta, world);
}
