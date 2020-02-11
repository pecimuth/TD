#include "SellTowerButton.h"
#include "Assets.h"

static int REMOVE_ICON_TEXTURE_ID = 296;
static const int RETURN_COEF = 2;

SellTowerButton::SellTowerButton(const sf::Vector2f& position, const Tower& tower):
	Button(position, REMOVE_ICON_TEXTURE_ID),
	tower(tower),
	price(resellValue(tower), tower.getSector().bottomLeftPoint())
{
}

void SellTowerButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Button::draw(target, states);
	if (mouseHovers())
		target.draw(price, states);
}

void SellTowerButton::onClick(World& world)
{
	Button::onClick(world);
	world.removeTower(&tower, resellValue(tower));
}

int SellTowerButton::resellValue(const Tower& tower)
{
	return tower.getPrice() / RETURN_COEF;
}
