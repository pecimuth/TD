#pragma once
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Sector.h"
#include <memory>

class Actor : public sf::Drawable
{
public:
	using Path = std::vector<Sector>;
	using PathIterator = Actor::Path::const_iterator;
	Actor(PathIterator start, PathIterator finish, int textureId, float moveSpeed, int hitPoints);
	bool reachedDestination() const { return start == finish; }
	bool isAlive() const { return hitPoints > 0; }
	bool toRemove() const { return reachedDestination() || !isAlive(); }
	void move(sf::Time delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Vector2f getPosition() const { return sprite.getPosition(); }
	void damage(int severity) { hitPoints -= severity; }
private:
	PathIterator start;
	PathIterator finish;
	float moveSpeed;
	int hitPoints;
	mutable sf::Sprite sprite;
	void headDestination();
};

using ActorPtr = std::unique_ptr<Actor>;
using Actors = std::vector<ActorPtr>;
