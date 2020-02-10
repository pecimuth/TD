#include "GameOverScene.h"
#include "Sector.h"
#include <SFML/Graphics/RenderTarget.hpp>

static const char* SECONDARY_TEXT = "press any key to restart";
static const sf::Color TEXT_COLOR = sf::Color(10, 10, 10);

GameOverScene::GameOverScene(int waveNumber) :
	title(),
	text()
{
	title.setString(std::string("You made it to wave ") + std::to_string(waveNumber));
	title.setCharacterSize(Sector::SIZE * 2);
	title.setFillColor(TEXT_COLOR);
	title.setPosition(Sector{ 2, 2 }.upperLeftPoint());
	text.setString(SECONDARY_TEXT);
	text.setCharacterSize(Sector::SIZE);
	text.setFillColor(TEXT_COLOR);
	text.setPosition(Sector{ 2, 12 }.upperLeftPoint());
}

void GameOverScene::setFont(const sf::Font& font)
{
	title.setFont(font);
	text.setFont(font);
}

void GameOverScene::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::EventType::KeyPressed)
		requestSceneChange(SceneChangeRequest { SceneType::Game });
}

void GameOverScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(title, states);
	target.draw(text, states);
}
