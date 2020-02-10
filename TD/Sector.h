#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

struct Sector
{
	template<typename T>
	static Sector fromCoords(T xCoord, T yCoord);
	template<typename T>
	static Sector fromCoords(const sf::Vector2<T>& coords);
	static const int SIZE = 64;
	static const sf::Vector2f DIAGONAL;
	static const sf::Vector2f CENTER;
	int x;
	int y;
	sf::Vector2f upperLeftPoint() const;
	sf::Vector2f upperRightPoint() const;
	sf::Vector2f bottomLeftPoint() const;
	sf::Vector2f midpoint() const;
	bool operator==(const Sector& rhs) const;
};

Sector operator+(const Sector& lhs, const Sector& rhs);

using Path = std::vector<Sector>;
using PathIterator = Path::const_iterator;

static const int TILESHEET_WIDTH = 23;
static const float SCALE_FACTOR = 0.5f;
static const float INVERSE_SCALE_FACTOR = 1.f / SCALE_FACTOR;

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
	return static_cast<float>(atan2(vec.y, vec.x));
}

inline float toRadians(float alpha)
{
	return alpha * 180.f / 3.14159265f;
}

float angle(const sf::Vector2f& vec);
sf::Vector2f vectorFromRadians(float radians);

sf::Vector2f transformMouseCoordinates(const sf::Vector2i& vec);
sf::Vector2f transformMouseCoordinates(int x, int y);

template<typename T>
inline Sector Sector::fromCoords(T xCoord, T yCoord)
{
	return Sector{ static_cast<int>(xCoord) / SIZE, static_cast<int>(yCoord) / SIZE };
}

template<typename T>
inline Sector Sector::fromCoords(const sf::Vector2<T>& coords)
{
	return fromCoords(coords.x, coords.y);
}
