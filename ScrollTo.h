#pragma once
#include "Behavior.h"
#include "Camera.h"
class ScrollTo : public Behavior{
public:
	ScrollTo(Entity* entity);

	void update(float dt);
	void setWindow(sf::RenderWindow* window);
private:
	sf::RenderWindow* window;
	Camera camera;
};

