#pragma once
#include "Actor.h"

enum class PlaneGrade : int
{
	First = 0,
	Second
};


class Plane : public Actor
{
public:
	Plane(const Path& path, PlaneGrade grade);
	static std::unique_ptr<Actor> make(const Path& path, PlaneGrade grade) {
		return std::make_unique<Plane>(path, grade);
	}
private:
	static int getTextureId(PlaneGrade grade);
	static float getSpeed(PlaneGrade grade);
	static int getHitPoints(PlaneGrade grade);
	static int getWorth(PlaneGrade grade);
};

