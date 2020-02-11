#pragma once
#include "Scene.h"
#include <SFML/Graphics/Text.hpp>

class TextScene : public Scene
{
public:
	TextScene(const char* primary, const char* secondary, const char* tertiary, SceneType nextScene);
	virtual void handleInput(const sf::Event& event) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Text primary;
	sf::Text secondary;
	sf::Text tertiary;
	SceneType nextScene;
};
