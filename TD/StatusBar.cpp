#include "StatusBar.h"

static const int FONT_SIZE = 48;
static const sf::Color HP_COLOR = sf::Color(220, 20, 60);
static const sf::Color MONEY_COLOR = sf::Color(255, 215, 0);

StatusBar::StatusBar():
	balanceText(),
	hitPointsText()
{
	balanceText.setFillColor(MONEY_COLOR);
	hitPointsText.setFillColor(HP_COLOR);
	balanceText.setCharacterSize(FONT_SIZE);
	hitPointsText.setCharacterSize(FONT_SIZE);
	balanceText.setPosition(Sector{ 4, 0 }.upperLeftPoint());
	hitPointsText.setPosition(Sector{ 1, 0 }.upperLeftPoint());
}

void StatusBar::setFont(const sf::Font& font)
{
	balanceText.setFont(font);
	hitPointsText.setFont(font);
}

void StatusBar::update(const World& world)
{
	balanceText.setString('$' + std::to_string(world.getBalance()));
	hitPointsText.setString(std::to_string(world.getHitPoints()));
}

void StatusBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(balanceText, states);
	target.draw(hitPointsText, states);
}

