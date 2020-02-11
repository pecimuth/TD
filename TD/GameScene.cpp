#include "GameScene.h"
#include "Assets.h"

GameScene::GameScene():
	world(),
	statusBar(),
	contextMenu(),
	director()
{
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
	auto& window = Assets::get().window;
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
