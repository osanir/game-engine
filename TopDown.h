#pragma once
#include "Behavior.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

class TopDown : public Behavior{
public:
	TopDown(Entity *entity);

	void update(float dt);

private:
	bool defaultControls = true;
	void handlePlayerInput();
};

