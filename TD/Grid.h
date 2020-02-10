#pragma once
#include "Sector.h"
#include <vector>
#include <SFML/Graphics/Drawable.hpp>

class Grid : public sf::Drawable
{
public:
	Grid();
	int blockAt(const Sector& sector) const { return blocks[sector.y][sector.x]; };
	int blockAt(int x, int y) const { return blocks[y][x]; }
	bool isBuildingAllowedAt(const Sector& sector) const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	const Path& getPath() const { return path; }
private:
	int width;
	int height;
	std::vector<std::vector<int>> blocks;
	Path path;
	bool isBuildingAllowedOn(int block) const;
};

