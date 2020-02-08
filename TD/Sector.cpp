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
	return toRadians(angleRadians(vec));
}

sf::Vector2f transformMouseCoordinates(const sf::Vector2i& vec)
{
	return sf::Vector2f(vec * 2);
}

sf::Vector2f transformMouseCoordinates(int x, int y)
{
	return sf::Vector2f(x, y) * 2.f;
}

Sector Sector::fromCoords(int xCoord, int yCoord)
{
	return Sector{ xCoord / Sector::SIZE, yCoord / Sector::SIZE };
}

sf::Vector2f Sector::upperLeftPoint() const
{
	return sf::Vector2f(x * SIZE, y * SIZE);
}

sf::Vector2f Sector::upperRightPoint() const
{
	return sf::Vector2f((x + 1) * SIZE, y * SIZE);
}

sf::Vector2f Sector::midpoint() const
{
	return sf::Vector2f(x * SIZE + SIZE / 2, y * SIZE + SIZE / 2);
}

bool Sector::operator==(const Sector& rhs) const
{
	return x == rhs.x && y == rhs.y;
}
