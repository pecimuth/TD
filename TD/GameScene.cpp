#include "GameScene.h"

GameScene::GameScene():
	world(),
	statusBar(),
	contextMenu()
{
}

void GameScene::setTexture(const sf::Texture& texture)
{
	world.setTexture(texture);
	contextMenu.setTexture(texture);
}

void GameScene::setFont(const sf::Font& font)
{
	statusBar.setFont(font);
	contextMenu.setFont(font);
}

void GameScene::setWindow(const sf::Window& windowValue)
{
	window = &windowValue;
}

void GameScene::handleInput(const sf::Event& event)
{
	contextMenu.handleInput(event, world);
}

void GameScene::update(sf::Time delta)
{
	world.update(delta);
	statusBar.update(world);
	contextMenu.update(world, transformMouseCoordinates(sf::Mouse::getPosition(*window)));
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	world.draw(target, states);
	contextMenu.draw(target, states);
	statusBar.draw(target, states);
}
