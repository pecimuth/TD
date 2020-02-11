#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Audio.h"

struct Assets
{
public:
	static Assets& get()
	{
		static Assets assets;
		return assets;
	}

	sf::RenderWindow* window;
	sf::Texture texture;
	sf::Font font;
	Audio audio;
private:
	Assets() : window(), texture(), font(), audio() {};
};
