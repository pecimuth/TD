#include "Rocket.h"
#include "Actor.h"

static const int TEXTURE_ID = 251;
static const float SPEED = 500.f;
static const float ACCELARATION = 2000.f;
static const int DAMAGE = 70;
static const float ANGLE_CORRECTION = 90;

Rocket::Rocket(const sf::Vector2f& origin, Actor* target):
	Projectile(TEXTURE_ID, SPEED, DAMAGE, origin, target)
{
}

void Rocket::update(sf::Time delta, World& world)
{
	if (target == nullptr)
		return;
	speed += ACCELARATION * delta / sf::seconds(1);
	rotateTowards(target->getPosition(), ANGLE_CORRECTION);
	Projectile::update(delta, world);
}
