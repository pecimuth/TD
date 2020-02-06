#pragma once
#include <vector>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Sector.h"
#include "Entity.h"
#include <memory>

class Actor : public Entity
{
public:
	using Path = std::vector<Sector>;
	using PathIterator = Actor::Path::const_iterator;
	Actor(PathIterator start, PathIterator finish, int textureId, float speed, int hitPoints);
	bool reachedDestination() const { return start == finish; }
	bool isAlive() const { return hitPoints > 0; }
	bool toRemove() const { return reachedDestination() || !isAlive(); }
	virtual void update(sf::Time delta, World& world) override;
	void damage(int severity) { hitPoints -= severity; }
private:
	PathIterator start;
	PathIterator finish;
	float speed;
	int hitPoints;
};

using ActorPtr = std::unique_ptr<Actor>;
using Actors = std::vector<ActorPtr>;
