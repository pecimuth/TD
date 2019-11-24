#pragma once

#include <memory>

#include "SceneType.h"

struct SceneChangeRequest
{
	SceneType targetScene;
};

using SceneChangeRequestPtr = std::unique_ptr<SceneChangeRequest>;
