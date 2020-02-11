#include "WelcomeScene.h"
#include "SceneType.h"
#include "SceneChangeRequest.h"
#include "App.h"
#include "Sector.h"
#include "Assets.h"

static const sf::Time WELCOME_SCENE_DURATION = sf::seconds(1);
static const char* SECONDARY_TEXT = "programming project in C++\nAndrej Pecimuth\nZS 2019/2020";
static const sf::Color TEXT_COLOR = sf::Color(10, 10, 10);

WelcomeScene::WelcomeScene():
	timeLeft(WELCOME_SCENE_DURATION),
	title(),
	text()
{
	title.setString(App::TITLE);
	title.setCharacterSize(Sector::SIZE * 5);
	title.setFillColor(TEXT_COLOR);
	title.setPosition(Sector{ 2, 2 }.upperLeftPoint());
	text.setString(SECONDARY_TEXT);
	text.setCharacterSize(Sector::SIZE);
	text.setFillColor(TEXT_COLOR);
	text.setPosition(Sector{ 2, 12 }.upperLeftPoint());
	auto& assets = Assets::get();
	title.setFont(assets.font);
	text.setFont(assets.font);
}

void WelcomeScene::update(sf::Time delta)
{
	timeLeft -= delta;
	if (timeLeft <= sf::Time::Zero)
		requestSceneChange(SceneChangeRequest{ SceneType::Game });
}

void WelcomeScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(title, states);
	target.draw(text, states);
}
