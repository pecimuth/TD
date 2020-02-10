#include "Wave.h"

const sf::Time Wave::SPACING_HUGE= sf::milliseconds(1200);
const sf::Time Wave::SPACING_WIDE = sf::milliseconds(800);
const sf::Time Wave::SPACING_MEDIUM = sf::milliseconds(500);
const sf::Time Wave::SPACING_NARROW = sf::milliseconds(300);


Wave::Wave(SoldierGrade grade, int count, const Path& path, sf::Time spacing) :
	actorTemplate(Soldier::make(path, grade)),
	actorsLeft(count),
	spacing(spacing),
	elapsed(sf::Time::Zero)
{
}

Wave::Wave(PlaneGrade grade, int count, const Path& path, sf::Time spacing) :
	actorTemplate(Plane::make(path, grade)),
	actorsLeft(count),
	spacing(spacing),
	elapsed(sf::Time::Zero)
{
}

ActorPtr Wave::maybeSendNext(sf::Time delta)
{
	elapsed += delta;
	if (actorsLeft && elapsed >= delta)
	{
		elapsed -= spacing;
		--actorsLeft;
		return actorTemplate->clone();
	}
	return nullptr;
}
