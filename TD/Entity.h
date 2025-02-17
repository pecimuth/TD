#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <vector>

class World;

class Entity : public sf::Drawable
{
public:
	Entity(int textureId);
	virtual ~Entity() {};
	const sf::Vector2f& getPosition() const { return sprite.getPosition(); }
	virtual void update(sf::Time delta, World& world) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	sf::Sprite sprite;
	int getTextureId() const { return textureId; }
	// squared distance from the midpoint of sprite to target
	float distanceSquaredFrom(const sf::Vector2f& target) const;
	// is the distance from target <= range?
	bool isInRange(const sf::Vector2f& target, float range) const;
	void rotateTowards(const sf::Vector2f& target, float angleCorrection = 0);
	// speed is in points per second, delta is the elapsed time
	bool moveTowards(const sf::Vector2f& target, sf::Time delta, float speed);
private:
	int textureId;
};

using EntityPtr = std::unique_ptr<Entity>;
using Entities = std::vector<EntityPtr>;
