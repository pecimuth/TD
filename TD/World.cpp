#include "World.h"
#include <memory>
#include "RedTwinGun.h"
#include "RocketLauncher.h"
#include "GreenGun.h"
#include "Sector.h"

static const int BASE_BALANCE = 1000;
static const int BASE_HIT_POINTS = 1000;

World::World():
	grid(),
	actors(),
	towers(),
	balance(BASE_BALANCE),
	hitPoints(BASE_HIT_POINTS)
{
	const Path& path = grid.getPath();
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 245, 120.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 246, 60.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 247, 80.f, 1000));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 248, 100.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 245, 110.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 246, 70.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 270, 200.f, 300));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 271, 250.f, 300));
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

	std::for_each(
		actors.begin(), actors.end(),
		[this](const ActorPtr& entity) {
			if (entity->reachedDestination())
				this->hitPoints -= entity->getWorth();
			else if (!entity->isAlive())
				this->balance += entity->getWorth();
		}
	);

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

void World::placeTower(TowerPtr&& tower, int cost)
{
	if (balance >= cost)
	{
		towers.push_back(std::move(tower));
		balance -= cost;
	}
}

bool World::canPlaceTowerAt(const Sector& target) const
{
	return grid.isBuildingAllowedAt(target)
		&& std::none_of(
			towers.cbegin(),
			towers.cend(),
			[&target](const TowerPtr& tower) { return tower->getSector() == target; });
}
