#include "StatusBar.h"

StatusBar::StatusBar():
	balanceText(),
	hitPointsText()
{
	balanceText.setFillColor(sf::Color::Yellow);
	hitPointsText.setFillColor(sf::Color::Red);
	balanceText.setCharacterSize(48);
	hitPointsText.setCharacterSize(48);
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

