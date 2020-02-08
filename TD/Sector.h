#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

struct Sector
{
	static Sector fromCoords(int xCoord, int yCoord);
	static const int SIZE = 64;
	static const sf::Vector2f DIAGONAL;
	static const sf::Vector2f CENTER;
	int x;
	int y;
	sf::Vector2f upperLeftPoint() const;
	sf::Vector2f upperRightPoint() const;
	sf::Vector2f midpoint() const;
	bool operator==(const Sector& rhs) const;
};

using Path = std::vector<Sector>;
using PathIterator = Path::const_iterator;

static const int TILESHEET_WIDTH = 23;

sf::IntRect textureRectById(int textureId);

template<typename T>
T lengthSquared(const sf::Vector2<T>& vec)
{
	return vec.x * vec.x + vec.y * vec.y;
}

template<typename T>
sf::Vector2<T> normalize(const sf::Vector2<T>& vec)
{
	if (vec.x == 0 && vec.y == 0)
		return vec;
	return vec / static_cast<T>(sqrt(lengthSquared(vec)));
}

sf::Vector2f velocity(const sf::Vector2f& direction, float moveSpeed, sf::Time delta);

inline float angleRadians(const sf::Vector2f& vec)
{
	return atan2(vec.y, vec.x);
}

inline float toRadians(float alpha)
{
	return alpha * 180.f / 3.14159265f;
}

float angle(const sf::Vector2f& vec);

inline sf::Vector2f vectorFromRadians(float radians)
{
	return sf::Vector2f(cos(radians), sin(radians));
}

sf::Vector2f transformMouseCoordinates(const sf::Vector2i& vec);
sf::Vector2f transformMouseCoordinates(int x, int y);