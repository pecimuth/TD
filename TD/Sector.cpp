#include "Sector.h"

const sf::Vector2f Sector::DIAGONAL = sf::Vector2f(SIZE, SIZE);
const sf::Vector2f Sector::CENTER = DIAGONAL / 2.f;

sf::IntRect textureRectById(int textureId)
{
	return sf::IntRect(
		textureId % TILESHEET_WIDTH * Sector::SIZE,
		textureId / TILESHEET_WIDTH * Sector::SIZE,
		Sector::SIZE,
		Sector::SIZE
	);
}

sf::Vector2f velocity(const sf::Vector2f& direction, float moveSpeed, sf::Time delta)
{
	return normalize(direction) * (delta / sf::seconds(1)) * moveSpeed;
}

float angle(const sf::Vector2f& vec)
{
	return atan2(vec.y, vec.x) * 180 / 3.14159265;
}

sf::Vector2f Sector::upperLeftPoint() const
{
	return sf::Vector2f(x * SIZE, y * SIZE);
}

sf::Vector2f Sector::midpoint() const
{
	return sf::Vector2f(x * SIZE + SIZE / 2, y * SIZE + SIZE / 2);
}
