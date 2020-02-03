#include "GameScene.h"

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	grid.draw(target, states);
}
