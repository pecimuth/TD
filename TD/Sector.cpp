#include "Sector.h"

const int Sector::SIZE = 64;
const sf::Vector2f Sector::DIAGONAL = sf::Vector2f(Sector::SIZE, Sector::SIZE);
const sf::Vector2f Sector::CENTER = Sector::DIAGONAL / 2.f;
const int Sector::TILESHEET_WIDTH = 23;
const float Sector::SCALE_FACTOR = 0.5f;
const float Sector::INVERSE_SCALE_FACTOR = 1.f / SCALE_FACTOR;

Sector operator+(const Sector& lhs, const Sector& rhs)
{
	return Sector{ lhs.x + rhs.x, lhs.y + rhs.y };
}

sf::IntRect textureRectById(int textureId)
{
	return sf::IntRect(
		textureId % Sector::TILESHEET_WIDTH * Sector::SIZE,
		textureId / Sector::TILESHEET_WIDTH * Sector::SIZE,
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

sf::Vector2f vectorFromRadians(float radians)
{
	return sf::Vector2f(static_cast<float>(cos(radians)), static_cast<float>(sin(radians)));
}

sf::Vector2f transformMouseCoordinates(const sf::Vector2i& vec)
{
	return sf::Vector2f(vec) * Sector::INVERSE_SCALE_FACTOR;
}

sf::Vector2f transformMouseCoordinates(int x, int y)
{
	return sf::Vector2f(static_cast<float>(x), static_cast<float>(y)) * Sector::INVERSE_SCALE_FACTOR;
}

sf::Vector2f Sector::upperLeftPoint() const
{
	return sf::Vector2f(static_cast<float>(x * SIZE), static_cast<float>(y * SIZE));
}

sf::Vector2f Sector::upperRightPoint() const
{
	return sf::Vector2f(static_cast<float>((x + 1) * SIZE), static_cast<float>(y * SIZE));
}

sf::Vector2f Sector::bottomLeftPoint() const
{
	return sf::Vector2f(static_cast<float>(x * SIZE), static_cast<float>((y + 1) * SIZE));
}

sf::Vector2f Sector::midpoint() const
{
	return sf::Vector2f(static_cast<float>(x * SIZE + SIZE / 2), static_cast<float>(y * SIZE + SIZE / 2));
}

bool Sector::operator==(const Sector& rhs) const
{
	return x == rhs.x && y == rhs.y;
}
