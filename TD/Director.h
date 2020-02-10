#pragma once
#include "World.h"
#include "Wave.h"

class Director
{
public:
	Director();
	void setTexture(const sf::Texture& newTexture);
	void update(sf::Time delta, World& world);
	int getWaveNumber() const { return waveNumber; }
private:
	int waveNumber;
	WavePtr wave;
	const sf::Texture* texture;
	static WavePtr makeWave(int number, const Path& path);
};

