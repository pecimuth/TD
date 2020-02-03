#pragma once
#include "Sector.h"
#include "BlockCategory.h"
#include <vector>
#include <SFML/Graphics/Drawable.hpp>

class Grid : public sf::Drawable
{
public:
	Grid();
	Grid(int width, int height);
	int blockAt(Sector sector) const { return blocks[sector.y][sector.x]; };
	int blockAt(int x, int y) const { return blocks[y][x]; }
	BlockCategory categoryAt(Sector sector) const { return category(blockAt(sector)); }
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	int width;
	int height;
	std::vector<std::vector<int>> blocks;
	BlockCategory category(int block) const;
};

