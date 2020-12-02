#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Entity.h"

using namespace std;

class Game{
public:
	Game();
	void updateDt();
	void run();
	void processEvents();
	void start();
	void update();
	void render();
private:
	sf::Clock dtClock;
	float dt;

	sf::RenderWindow window;
	Entity player;
};
