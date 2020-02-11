#pragma once
#include "World.h"
#include "Wave.h"

class Director
{
public:
	Director();
	void update(sf::Time delta, World& world);
	int getWaveNumber() const { return waveNumber; }
private:
	int waveNumber;
	WavePtr wave;
	static WavePtr makeWave(int number, const Path& path);
};

