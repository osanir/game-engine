#pragma once
#include "Behaivor.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

class TopDown : public Behaivor{
public:
	TopDown(Entity *entity);

	void update(float dt);

private:
	bool defaultControls = true;
	void handlePlayerInput();
};

