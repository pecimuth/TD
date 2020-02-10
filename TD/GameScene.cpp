#include "GameScene.h"

GameScene::GameScene():
	world(),
	statusBar(),
	contextMenu(),
	window(),
	director()
{
}

void GameScene::setTexture(const sf::Texture& texture)
{
	world.setTexture(texture);
	contextMenu.setTexture(texture);
	director.setTexture(texture);
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
	director.update(delta, world);
	statusBar.update(world);
	contextMenu.update(world, transformMouseCoordinates(sf::Mouse::getPosition(*window)));
	if (world.getHitPoints() <= 0)
		requestSceneChange(SceneChangeRequest{ SceneType::GameOver, director.getWaveNumber() });
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	world.draw(target, states);
	contextMenu.draw(target, states);
	statusBar.draw(target, states);
}
