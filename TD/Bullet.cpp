#include "Bullet.h"

const int TEXTURE_ID = 272;
const float SPEED = 1200.f;
const int DAMAGE = 10;

Bullet::Bullet(const sf::Vector2f& origin, Actor* target):
	Projectile(TEXTURE_ID, SPEED, DAMAGE, origin, target)
{
}
