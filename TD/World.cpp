#include "World.h"
#include <memory>
#include "RedTwinGun.h"
#include "RocketLauncher.h"
#include "GreenGun.h"

World::World():
	grid(),
	actors(),
	towers()
{
	static auto path = Actor::Path{ Sector{4, -1}, Sector{4, 6}, Sector{17, 6}, Sector{17, 14}, Sector{9, 14}, Sector{9, 20} };
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 245, 120.f, 1000));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 246, 60.f, 1000));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 247, 80.f, 1000));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 248, 100.f, 1000));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 245, 110.f, 1000));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 246, 70.f, 1000));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 270, 200.f, 3000));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 271, 250.f, 3000));
	towers.push_back(std::make_unique<RedTwinGun>(Sector{ 7, 2 }));
	towers.push_back(std::make_unique<GreenGun>(Sector{ 15, 18 }));
	towers.push_back(std::make_unique<GreenGun>(Sector{ 15, 12 }));
	towers.push_back(std::make_unique<RocketLauncher>(Sector{ 12, 17 }));
	towers.push_back(std::make_unique<RocketLauncher>(Sector{ 12, 4 }));
}

void World::setTexture(const sf::Texture& texture)
{
	for (auto&& entity : actors)
		entity->setTexture(texture);
	for (auto&& entity : towers)
		entity->setTexture(texture);
	for (auto&& entity : projectiles)
		entity->setTexture(texture);
}

void World::update(sf::Time delta)
{
	updateAll(actors, delta);
	updateAll(projectiles, delta);
	clean(projectiles);
	clean(actors);
	updateAll(towers, delta);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(grid, states);
	drawAll(projectiles, target, states);
	drawAll(actors, target, states);
	drawAll(towers, target, states);
}

void World::fire(ProjectilePtr&& projectile)
{
	projectiles.push_back(std::move(projectile));
}
