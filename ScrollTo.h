#pragma once
#include "Behavior.h"
#include "Camera.h"
class ScrollTo : public Behavior{
public:
	ScrollTo(Entity* entity);
	// TODO: Karakter ekran�n sa� taraf�na hareket etti�inde beyaz alanlar g�r�n�yor. Fix
	void update(float dt);
	void setWindow(sf::RenderWindow* window);
private:
	sf::RenderWindow* window;
	Camera camera;
};

