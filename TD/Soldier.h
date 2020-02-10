#pragma once
#include "Actor.h"

enum class SoldierGrade : int
{
	First = 0,
	Second,
	Third,
	Fourth
};

class Soldier : public Actor
{
public:
	Soldier(const Path& path, SoldierGrade grade);
	static std::unique_ptr<Actor> make(const Path& path, SoldierGrade grade) {
		return std::make_unique<Soldier>(path, grade);
	}
private:
	static int getTextureId(SoldierGrade grade);
	static float getSpeed(SoldierGrade grade);
	static int getHitPoints(SoldierGrade grade);
	static int getWorth(SoldierGrade grade);
};
