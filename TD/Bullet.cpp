#include "Bullet.h"

static const int TEXTURE_ID = 272;
static const float SPEED = 1200.f;
static const int DAMAGE = 20;

Bullet::Bullet(const sf::Vector2f& origin, Actor* target):
	Projectile(TEXTURE_ID, SPEED, DAMAGE, origin, target)
{
}
