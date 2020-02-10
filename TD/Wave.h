#pragma once
#include "Actor.h"
#include "Soldier.h"
#include "Plane.h"

class Wave
{
public:
	static const sf::Time SPACING_HUGE;
	static const sf::Time SPACING_WIDE;
	static const sf::Time SPACING_MEDIUM;
	static const sf::Time SPACING_NARROW;

	Wave(SoldierGrade grade, int count, const Path& path, sf::Time spacing);
	Wave(PlaneGrade grade, int count, const Path& path, sf::Time spacing);

	ActorPtr maybeSendNext(sf::Time delta);
	bool isEmpty() const { return actorsLeft <= 0; }
private:
	ActorPtr actorTemplate;
	int actorsLeft;
	sf::Time spacing;
	sf::Time elapsed;
};

using WavePtr = std::unique_ptr<Wave>;