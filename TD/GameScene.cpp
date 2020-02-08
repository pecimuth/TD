#include "GameScene.h"

void GameScene::setTexture(const sf::Texture& texture)
{
	world.setTexture(texture);
}

void GameScene::setFont(const sf::Font& font)
{
	statusBar.setFont(font);
}

void GameScene::update(sf::Time delta)
{
	world.update(delta);
	statusBar.update(world);
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	world.draw(target, states);
	statusBar.draw(target, states);
}
