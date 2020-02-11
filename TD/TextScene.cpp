#include "TextScene.h"
#include "Sector.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "Assets.h"

static const sf::Color TEXT_COLOR = sf::Color(10, 10, 10);

TextScene::TextScene(const char* primaryText, const char* secondaryText, const char* tertiaryText, SceneType nextScene) :
	primary(),
	secondary(),
	tertiary(),
	nextScene(nextScene)
{
	primary.setString(primaryText);
	primary.setCharacterSize(Sector::SIZE * 2);
	primary.setFillColor(TEXT_COLOR);
	primary.setPosition(Sector{ 2, 2 }.upperLeftPoint());
	secondary.setString(secondaryText);
	secondary.setCharacterSize(Sector::SIZE);
	secondary.setFillColor(TEXT_COLOR);
	secondary.setPosition(Sector{ 2, 7 }.upperLeftPoint());
	tertiary.setString(tertiaryText);
	tertiary.setCharacterSize(Sector::SIZE);
	tertiary.setFillColor(TEXT_COLOR);
	tertiary.setPosition(Sector{ 2, 12 }.upperLeftPoint());
	auto& assets = Assets::get();
	primary.setFont(assets.font);
	secondary.setFont(assets.font);
	tertiary.setFont(assets.font);
}

void TextScene::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::EventType::KeyPressed)
		requestSceneChange(SceneChangeRequest { nextScene });
}

void TextScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(primary, states);
	target.draw(secondary, states);
	target.draw(tertiary, states);
}
