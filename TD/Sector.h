#pragma once
#include <SFML/System/Vector2.hpp>

struct Sector
{
	static const int SIZE = 64;
	static const sf::Vector2i DIAGONAL;
	int x;
	int y;
};