#include "World.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <algorithm>

World::World():
	grid(),
	actors()
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
}

void World::update(sf::Time delta)
{
	for (auto&& actor : actors)
		actor.move(delta);
	actors.erase(
		std::remove_if(
			actors.begin(),
			actors.end(),
			[](const Actor& actor) { return actor.toRemove(); }
		),
		actors.end()
	);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(grid, states);
	for (auto&& actor : actors)
		target.draw(actor, states);
}
