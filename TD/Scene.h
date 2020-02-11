#pragma once

#include <memory>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "SceneChangeRequest.h"
#include <SFML/Graphics/Font.hpp>
#include "Audio.h"

class Scene : public sf::Drawable
{
public:
	virtual ~Scene() { }
	virtual void handleInput(const sf::Event& event) = 0;
	virtual void update(sf::Time delta) = 0;
	bool isSceneChangeRequested() const { return sceneChangeRequest != nullptr; }
	SceneChangeRequestPtr takeSceneChangeRequest() { return std::move(sceneChangeRequest); }
protected:
	void requestSceneChange(SceneChangeRequest request);
private:
	SceneChangeRequestPtr sceneChangeRequest;
};

using ScenePtr = std::unique_ptr<Scene>;
