#pragma once
#include <vector>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Sector.h"
#include "Entity.h"
#include <memory>

class Actor;
using ActorPtr = std::unique_ptr<Actor>;
using Actors = std::vector<ActorPtr>;

class Actor : public Entity
{
public:
	Actor(PathIterator start, PathIterator finish, int textureId, float speed, int hitPoints, int worth);
	bool reachedDestination() const { return start == finish; }
	bool isAlive() const { return hitPoints > 0; }
	bool toRemove() const { return reachedDestination() || !isAlive(); }
	virtual void update(sf::Time delta, World& world) override;
	void damage(int severity) { hitPoints -= severity; }
	virtual int getWorth() const { return worth; }
	virtual ActorPtr clone() const;
private:
	PathIterator start;
	PathIterator finish;
	float speed;
	int hitPoints;
	int worth;
};

