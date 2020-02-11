#include "Director.h"

Director::Director() :
	waveNumber(0),
	wave()
{
}

void Director::update(sf::Time delta, World& world)
{
	if (!wave || (wave->isEmpty() && world.getActors().empty()))
		wave = makeWave(++waveNumber, world.getGrid().getPath());
	auto next = wave->maybeSendNext(delta);
	if (next)
		world.getActors().push_back(std::move(next));
}

WavePtr Director::makeWave(int number, const Path& path)
{
	switch (number)
	{
	case 1:
		return std::make_unique<Wave>(SoldierGrade::First, 5, path, Wave::SPACING_HUGE);
	case 2:
		return std::make_unique<Wave>(SoldierGrade::First, 7, path, Wave::SPACING_WIDE);
	case 3:
		return std::make_unique<Wave>(SoldierGrade::Second, 3, path, Wave::SPACING_WIDE);
	case 4:
		return std::make_unique<Wave>(SoldierGrade::First, 13, path, Wave::SPACING_MEDIUM);
	case 5:
		return std::make_unique<Wave>(SoldierGrade::Second, 7, path, Wave::SPACING_MEDIUM);
	case 6:
		return std::make_unique<Wave>(SoldierGrade::First, 17, path, Wave::SPACING_NARROW);
	case 7:
		return std::make_unique<Wave>(SoldierGrade::Second, 10, path, Wave::SPACING_MEDIUM);
	case 8:
		return std::make_unique<Wave>(SoldierGrade::Third, 5, path, Wave::SPACING_WIDE);
	case 9:
		return std::make_unique<Wave>(SoldierGrade::Second, 13, path, Wave::SPACING_NARROW);
	case 10:
		return std::make_unique<Wave>(PlaneGrade::First, 5, path, Wave::SPACING_WIDE);
	case 11:
		return std::make_unique<Wave>(SoldierGrade::Second, 17, path, Wave::SPACING_NARROW);
	case 12:
		return std::make_unique<Wave>(SoldierGrade::Fourth, 5, path, Wave::SPACING_WIDE);
	case 13:
		return std::make_unique<Wave>(SoldierGrade::Third, 7, path, Wave::SPACING_NARROW);
	case 14:
		return std::make_unique<Wave>(SoldierGrade::Second, 20, path, Wave::SPACING_NARROW);
	case 15:
		return std::make_unique<Wave>(PlaneGrade::First, 4, path, Wave::SPACING_MEDIUM);
	case 16:
		return std::make_unique<Wave>(SoldierGrade::Fourth, 7, path, Wave::SPACING_MEDIUM);
	case 17:
		return std::make_unique<Wave>(SoldierGrade::Third, 10, path, Wave::SPACING_NARROW);
	case 18:
		return std::make_unique<Wave>(PlaneGrade::First, 8, path, Wave::SPACING_WIDE);
	case 19:
		return std::make_unique<Wave>(SoldierGrade::Fourth, 7, path, Wave::SPACING_NARROW);
	case 20:
		return std::make_unique<Wave>(PlaneGrade::Second, 5, path, Wave::SPACING_MEDIUM);
	default:
		if (number % 2 == 1)
			return std::make_unique<Wave>(SoldierGrade::Fourth, 10 + (number - 21) * 5, path, Wave::SPACING_NARROW);
		return std::make_unique<Wave>(PlaneGrade::Second, 5 + (number - 22) * 3, path, Wave::SPACING_NARROW);
	}
}
