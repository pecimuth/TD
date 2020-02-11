#include "SellTowerButton.h"
#include "Assets.h"

static const sf::Vector2f TOWER_SELL_BTN_SCALE(1.5f, 1.5f);
static int REMOVE_ICON_TEXTURE_ID = 296;
static const int PRICE_FONT_SIZE = 32;
static const sf::Color TOWER_PRICE_COLOR = sf::Color(0, 100, 0);
static const int RETURN_COEF = 2;

SellTowerButton::SellTowerButton(const sf::Vector2f& position, const Tower& tower):
	Button(position),
	tower(tower),
	icon()
{
	icon.setOrigin(Sector::CENTER);
	icon.setTextureRect(textureRectById(REMOVE_ICON_TEXTURE_ID));
	icon.setScale(TOWER_SELL_BTN_SCALE);
	icon.setPosition(position);
	price.setFillColor(TOWER_PRICE_COLOR);
	price.setCharacterSize(PRICE_FONT_SIZE);
	price.setString("+$" + std::to_string(tower.getPrice() / RETURN_COEF));
	price.setPosition(tower.getSector().bottomLeftPoint());
	auto& assets = Assets::get();
	icon.setTexture(assets.texture);
	price.setFont(assets.font);
}

void SellTowerButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Button::draw(target, states);
	target.draw(icon, states);
	if (mouseHovers())
		target.draw(price, states);
}

void SellTowerButton::onClick(World& world)
{
	Button::onClick(world);
	world.removeTower(&tower, tower.getPrice() / RETURN_COEF);
}
