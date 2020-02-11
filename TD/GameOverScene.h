#pragma once
#include "TextScene.h"

class GameOverScene : public TextScene
{
public:
	GameOverScene(int waveNumber);
	virtual void update(sf::Time delta) override {};
};
