#pragma once
#include <SFML/Audio.hpp>
#include <map>
#include <vector>

enum class SoundEffect
{
	Gunshot,
	RocketLaunch,
	Hurt,
	Select
};

class Audio
{
public:
	Audio();
	bool loadAll();
	void play(SoundEffect effect);
private:
	std::vector<std::unique_ptr<sf::SoundBuffer>> buffers;
	std::map<SoundEffect, sf::Sound> sounds;
	bool loadOne(SoundEffect effect, const char* filename);
};

