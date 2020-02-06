#include "World.h"
#include <memory>
#include "RedTwinGun.h"

World::World():
	grid(),
	actors(),
	towers()
{
	static auto path = Actor::Path{ Sector{4, -1}, Sector{4, 6}, Sector{17, 6}, Sector{17, 14}, Sector{9, 14}, Sector{9, 20} };
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 245, 120.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 246, 60.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 247, 80.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 248, 100.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 245, 110.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 246, 70.f, 100));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 270, 200.f, 300));
	actors.push_back(std::make_unique<Actor>(path.cbegin(), path.cend(), 271, 250.f, 300));
	towers.push_back(std::make_unique<RedTwinGun>(Sector{ 7, 2 }));
	towers.push_back(std::make_unique<Tower>(Sector{ 15, 18 }, 249, 300, sf::milliseconds(400)));
	towers.push_back(std::make_unique<Tower>(Sector{ 15, 12 }, 249, 300, sf::milliseconds(400)));
	towers.push_back(std::make_unique<RedTwinGun>(Sector{ 12, 17 }));
	towers.push_back(std::make_unique<RedTwinGun>(Sector{ 12, 4 }));
}

void World::update(sf::Time delta)
{
	for (auto&& actor : actors)
		actor->move(delta);
	for (auto&& projectile : projectiles)
		projectile.update(delta);

	clean<Projectile>(projectiles, [](const Projectile& projectile) { return projectile.toRemove(); });
	clean<ActorPtr>(actors, [](const ActorPtr& actor) { return actor->toRemove(); });

	for (auto&& tower : towers)
		tower->update(delta, *this);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(grid, states);
	drawAll(projectiles, target, states);
	for (auto&& actor : actors)
		target.draw(*actor, states);
	for (auto&& tower : towers)
		target.draw(*tower, states);
}

void World::fire(Projectile projectile)
{
	projectiles.push_back(std::move(projectile));
}

