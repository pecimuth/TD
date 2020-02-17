#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

struct Sector
{
	int x;
	int y;

	// from sector coords to world coords
	sf::Vector2f upperLeftPoint() const;
	sf::Vector2f upperRightPoint() const;
	sf::Vector2f bottomLeftPoint() const;
	sf::Vector2f midpoint() const;
	bool operator==(const Sector& rhs) const;

	// from world coords to sector
	template<typename T>
	static Sector fromCoords(T xCoord, T yCoord);
	template<typename T>
	static Sector fromCoords(const sf::Vector2<T>& coords);

	static const int SIZE; // length of one side
	static const sf::Vector2f DIAGONAL;
	static const sf::Vector2f CENTER;
	static const int TILESHEET_WIDTH;

	// the textures are too big - everything is scaled down
	static const float SCALE_FACTOR;
	static const float INVERSE_SCALE_FACTOR;
};

Sector operator+(const Sector& lhs, const Sector& rhs);

using Path = std::vector<Sector>;
using PathIterator = Path::const_iterator;

template<typename T>
T lengthSquared(const sf::Vector2<T>& vec) // squared length of the vector
{
	return vec.x * vec.x + vec.y * vec.y;
}

template<typename T>
sf::Vector2<T> normalize(const sf::Vector2<T>& vec) // returns vector with the same angle, length 1
{
	if (vec.x == 0 && vec.y == 0)
		return vec;
	return vec / static_cast<T>(sqrt(lengthSquared(vec)));
}

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

inline float angleRadians(const sf::Vector2f& vec)
{
	return static_cast<float>(atan2(vec.y, vec.x));
}

inline float toRadians(float alpha) // degrees to radians
{
	return alpha * 180.f / 3.14159265f;
}

sf::IntRect textureRectById(int textureId); // rectangle in the tilesheet from ID, based on Tiled
// get velocity from moveSpeed (=points/sec) in the direction, when delta time elapsed
sf::Vector2f velocity(const sf::Vector2f& direction, float moveSpeed, sf::Time delta);
float angle(const sf::Vector2f& vec); // angle of the vector
sf::Vector2f vectorFromRadians(float radians); // unit vector from the angle
sf::Vector2f transformMouseCoordinates(const sf::Vector2i& vec); // adjust for scale
sf::Vector2f transformMouseCoordinates(int x, int y);
