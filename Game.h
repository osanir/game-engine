#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include "Entity.h"
#include "GameState.h"

using namespace std;

class Game{
public:
	// Constructor & Destructor
	Game();
	~Game();

	void run();
	void start();
	void processEvents();
	void updateDt();
	void update();
	void render();
private:
	// Initialization
	void initStates();

	sf::Clock dtClock;
	float dt;

	sf::RenderWindow window;
	Entity player;

	std::stack<State*> states;
};
