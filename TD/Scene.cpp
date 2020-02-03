#include "Scene.h"

#include <memory>
#include "SceneChangeRequest.h"

void Scene::requestSceneChange(SceneChangeRequest request)
{
	sceneChangeRequest = std::make_unique<SceneChangeRequest>(std::move(request));
}
