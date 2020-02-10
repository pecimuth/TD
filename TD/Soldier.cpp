#include "Soldier.h"

Soldier::Soldier(const Path& path, SoldierGrade grade):
	Actor(path.cbegin(), path.cend(), getTextureId(grade), getSpeed(grade), getHitPoints(grade), getWorth(grade))
{
}

int Soldier::getTextureId(SoldierGrade grade)
{
	return static_cast<int>(grade) + 245;
}

float Soldier::getSpeed(SoldierGrade grade)
{
	return 140.f + static_cast<float>(grade) * 50.f;
}

int Soldier::getHitPoints(SoldierGrade grade)
{
	return 100 + static_cast<int>(grade) * 120;
}

int Soldier::getWorth(SoldierGrade grade)
{
	return 80 + static_cast<int>(grade) * 10;
}
