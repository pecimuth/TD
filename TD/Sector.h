#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>

struct Sector
{
	static const int SIZE = 64;
	static const sf::Vector2f DIAGONAL;
	static const sf::Vector2f CENTER;
	int x;
	int y;
	sf::Vector2f upperLeftPoint() const;
	sf::Vector2f midpoint() const;
};

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
float angle(const sf::Vector2f& vec);
