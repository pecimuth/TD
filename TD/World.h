#pragma once
#include "Grid.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include <algorithm>
#include "Actor.h"
#include "Tower.h"
#include "Projectile.h"
#include <functional>

class World : public sf::Drawable
{
public:
	World();
	void update(sf::Time delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	Actors& getActors() { return actors; }
	void fire(Projectile projectile);
private:
	Grid grid;
	Actors actors;
	Towers towers;
	Projectiles projectiles;

	template<typename T>
	void clean(std::vector<T>& vec, std::function<bool(const T&)> pred);

	template<typename T>
	void drawAll(const std::vector<T>& vec, sf::RenderTarget& target, const sf::RenderStates& states) const;
};

template<typename T>
inline void World::clean(std::vector<T>& vec, std::function<bool(const T&)> pred)
{
	vec.erase(
		std::remove_if(
			vec.begin(),
			vec.end(),
			pred
		),
		vec.end()
	);
}

template<typename T>
inline void World::drawAll(const std::vector<T>& vec, sf::RenderTarget& target, const sf::RenderStates& states) const
{
	for (auto&& entity : vec)
		target.draw(entity, states);
}
