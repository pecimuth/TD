#pragma once
#include "Actor.h"

enum class PlaneGrade : int
{
	First = 0, // leftmost plane in tilesheet
	Second // rightmost plane
};

class Plane : public Actor
{
public:
	Plane(const Path& path, PlaneGrade grade);
	static std::unique_ptr<Actor> make(const Path& path, PlaneGrade grade) {
		return std::make_unique<Plane>(path, grade);
	}
private:
	// these methods calculate stats based on grade
	static int getTextureId(PlaneGrade grade);
	static float getSpeed(PlaneGrade grade);
	static int getHitPoints(PlaneGrade grade);
	static int getWorth(PlaneGrade grade);
};

