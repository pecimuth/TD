#include "World.h"

World::World():
	grid(),
	actors(),
	towers()
{
	static auto path = Actor::Path{ Sector{4, -1}, Sector{4, 6}, Sector{17, 6}, Sector{17, 14}, Sector{9, 14}, Sector{9, 20} };
	actors = {
		Actor{path.cbegin(), path.cend(), 245, 120.f, 100},
		Actor{path.cbegin(), path.cend(), 246, 60.f, 100},
		Actor{path.cbegin(), path.cend(), 247, 80.f, 100},
		Actor{path.cbegin(), path.cend(), 248, 100.f, 100},
		Actor{path.cbegin(), path.cend(), 245, 110.f, 100},
		Actor{path.cbegin(), path.cend(), 246, 70.f, 100},
		Actor{path.cbegin(), path.cend(), 247, 90.f, 100},
		Actor{path.cbegin(), path.cend(), 248, 50.f, 100}
	};
	towers = {
		Tower(Sector{7, 2}, 249, 300, sf::milliseconds(400)),
		Tower(Sector{15, 18}, 249, 300, sf::milliseconds(400)),
		Tower(Sector{15, 12}, 249, 300, sf::milliseconds(400)),
		Tower(Sector{12, 17}, 250, 300, sf::milliseconds(300)),
		Tower(Sector{12, 4}, 250, 300, sf::milliseconds(300)),
	};
}

void World::update(sf::Time delta)
{
	for (auto&& actor : actors)
		actor.move(delta);
	for (auto&& projectile : projectiles)
		projectile.update(delta);

	clean(actors);
	clean(projectiles);

	for (auto&& tower : towers)
		tower.update(delta, *this);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(grid, states);
	drawAll(projectiles, target, states);
	drawAll(actors, target, states);
	drawAll(towers, target, states);
}

void World::fire(Projectile projectile)
{
	projectiles.push_back(std::move(projectile));
}

