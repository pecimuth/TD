#include "GameScene.h"

void GameScene::setTexture(const sf::Texture& texture)
{
	world.setTexture(texture);
}

void GameScene::update(sf::Time delta)
{
	world.update(delta);
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	world.draw(target, states);
}
