#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

// Behaviors
#include "TopDown.h"
#include "ScrollTo.h"

#include "Globals.h"

#include "Entity.h"
#include "GameState.h"
#include "Camera.h"

using namespace std;

class Game{
public:
	// Constructor & Destructor
	Game();
	~Game();

	void addState(State* state);
	void addEntity(Entity* entity);
	void run();

	// Getters
	sf::RenderWindow* getWindow();
	sf::Vector2i getMousePosition();

	virtual void OnStart() = 0;
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
	void initEntities();

	sf::Clock dtClock;

	sf::RenderWindow window;

	std::stack<State*> states;

	bool newObjectsWillBeAdded = false;
	vector<Entity*> newEntities;
};
