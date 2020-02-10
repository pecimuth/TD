#pragma once

#include <memory>

#include "SceneType.h"

struct SceneChangeRequest
{
	SceneType targetScene;
	int waveNumber;
};

using SceneChangeRequestPtr = std::unique_ptr<SceneChangeRequest>;
