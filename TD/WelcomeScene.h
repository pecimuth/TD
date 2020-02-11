#pragma once
#include "TextScene.h"

class WelcomeScene : public TextScene
{
public:
	WelcomeScene();
	virtual void update(sf::Time delta) override {};
};
