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
#include <memory>
#include <functional>

class World : public sf::Drawable
{
public:
	World();
	void update(sf::Time delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	Actors& getActors() { return actors; }
	void fire(ProjectilePtr&& projectile);
	void placeTower(TowerPtr&& tower, int cost); // decrease balance by cost
	void removeTower(const Tower* tower, int cashback); // increase balance bycost
	const Tower* getTowerAt(const Sector& target) const;
	bool canPlaceTowerAt(const Sector& target) const;
	int getBalance() const { return balance; }
	int getHitPoints() const { return hitPoints; }
	const Grid& getGrid() const { return grid; }
private:
	Grid grid;
	Actors actors;
	Towers towers;
	Projectiles projectiles;
	int balance; // how much money does the player have
	int hitPoints;

	template<typename T>
	void clean(std::vector<std::unique_ptr<T>>& vec); // remove entities that want to be removed

	template<typename T>
	void updateAll(const std::vector<std::unique_ptr<T>>& vec, sf::Time delta);

	template<typename T>
	void drawAll(const std::vector<std::unique_ptr<T>>& vec, sf::RenderTarget& target, const sf::RenderStates& states) const;
};

template<typename T>
inline void World::clean(std::vector<std::unique_ptr<T>>& vec)
{
	vec.erase(
		std::remove_if(
			vec.begin(),
			vec.end(),
			[](const std::unique_ptr<T>& entity) { return entity->toRemove(); }
		),
		vec.end()
	);
}

template<typename T>
inline void World::updateAll(const std::vector<std::unique_ptr<T>>& vec, sf::Time delta)
{
	for (auto&& entity : vec)
		entity->update(delta, *this);
}

template<typename T>
inline void World::drawAll(const std::vector<std::unique_ptr<T>>& vec, sf::RenderTarget& target, const sf::RenderStates& states) const
{
	for (auto&& entity : vec)
		target.draw(*entity, states);
}
