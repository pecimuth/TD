#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

class Actor;

class Projectile : public sf::Drawable
{
public:
	Projectile(int textureId, float speed, int damage, const sf::Vector2f& origin, Actor* target);
	bool toRemove() const { return target == nullptr || reachedDestination(); }
	void update(sf::Time delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	static const float EPSILON;
	float speed;
	int damage;
	Actor* target;
	mutable sf::Sprite sprite;
	bool reachedDestination() const;
};

using Projectiles = std::vector<Projectile>;
