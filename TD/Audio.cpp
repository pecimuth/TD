#include "Audio.h"

Audio::Audio():
	buffers(),
	sounds()
{
}

bool Audio::loadAll()
{
	return loadOne(SoundEffect::Gunshot, "gunshot.wav")
		&& loadOne(SoundEffect::RocketLaunch, "rocketlaunch.wav")
		&& loadOne(SoundEffect::Hurt, "hurt.wav")
		&& loadOne(SoundEffect::Select, "select.wav");
}

void Audio::play(SoundEffect effect)
{
	sounds[effect].play();
}

bool Audio::loadOne(SoundEffect effect, const char* filename)
{
	buffers.emplace_back(std::make_unique<sf::SoundBuffer>());
	if (!buffers.back()->loadFromFile(filename))
		return false;
	return sounds.insert(std::make_pair(effect, sf::Sound(*buffers.back()))).second;
}
