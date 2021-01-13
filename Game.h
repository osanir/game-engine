#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include "TopDown.h"
#include "Entity.h"
#include "GameState.h"
using namespace std;

class Game{
public:
	// Constructor & Destructor
	Game();
	~Game();

	void addState(State* state);
	void addEntity(Entity* entity);
	void run();

	virtual void OnUpdate() = 0;
private:
	void start();
	void processEvents();
	void updateDt();
	void update();
	void render();
	float dt;
	// Initialization
	void initStates();

	sf::Clock dtClock;

	sf::RenderWindow window;

	std::stack<State*> states;

	bool newObjectsWillBeAdded = false;
	vector<Entity*> newEntities;
};
