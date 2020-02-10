#include "Plane.h"

Plane::Plane(const Path& path, PlaneGrade grade) :
	Actor(path.cbegin(), path.cend(), getTextureId(grade), getSpeed(grade), getHitPoints(grade), getWorth(grade))
{
}

int Plane::getTextureId(PlaneGrade grade)
{
	return static_cast<int>(grade) + 270;
}

float Plane::getSpeed(PlaneGrade grade)
{
	return 200.f + static_cast<float>(grade) * 100.f;
}

int Plane::getHitPoints(PlaneGrade grade)
{
	return 400 + static_cast<int>(grade) * 400;
}

int Plane::getWorth(PlaneGrade grade)
{
	return 140 + static_cast<int>(grade) * 20;
}
