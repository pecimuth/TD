#include "GameOverScene.h"
#include "Sector.h"

GameOverScene::GameOverScene(int waveNumber) :
	TextScene(
		(std::string("You've made it to wave ") + std::to_string(waveNumber)).c_str(),
		"press any key to restart",
		"",
		SceneType::Game
	)
{
}
