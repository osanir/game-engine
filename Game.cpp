#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Game::Game() : window(sf::VideoMode(854, 480), "Engine"){
	this->dt = this->dtClock.restart().asSeconds();
	std::ifstream ifs("Config/Window.config");

	std::string title = "None";
	sf::VideoMode window_bounds(854, 480);
	unsigned frame_limit = 120;
	bool vertical_sync_enabled = false;

	if( ifs.is_open() ){
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> frame_limit;
		ifs >> vertical_sync_enabled;

		this->window.setTitle(title);
		this->window.setFramerateLimit(frame_limit);
		this->window.setVerticalSyncEnabled(vertical_sync_enabled);
	} else{
		// std::cout << "File Error: Could not open file" << std::endl;
	}

	ifs.close();
}

Game::~Game(){
	while(!this->states.empty()){
		delete this->states.top();
		this->states.pop();
	}
}

void Game::addState(State* state){
	this->states.push(state);
}

void Game::addEntity(Entity* entity){
	this->newEntities.push_back(entity);
}

void Game::updateDt(){
	/* Calculates the elapsed time between two sequential frames. */

	this->dt = this->dtClock.restart().asSeconds();
	// This shows elapsed time between two frames
	//std::cout << this->dt << std::endl;
	// This shows the count of frames per second
	//std::cout << "FPS: " << 1.f / this->dt << std::endl;
}

void Game::run(){
	this->start();
	this->OnStart();
	while(window.isOpen()){
		this->updateDt();
		this->processEvents();
		this->OnUpdate();
		this->update();
		this->render();
	}
}

void Game::processEvents(){
	sf::Event event;
	while(window.pollEvent(event)){
		// Window close
		if(event.type == sf::Event::Closed){
			window.close();
		}
		if(this->states.empty()){
			window.close();
		}
	}
}

void Game::start(){
	// Init something
	this->initStates();
	this->initEntities();

}

void Game::update(){
	if(!this->states.empty()){
		this->states.top()->update(dt);

		if(this->states.top()->getQuit()){
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}

	} 
}

void Game::render(){
	this->window.clear(sf::Color::White);

	if(!this->states.empty()){
		this->window.draw(*this->states.top());
	}
	
	this->window.display();
}

void Game::initStates(){
	if(this->states.empty()){
		this->states.push(new GameState());
	}
}

void Game::initEntities(){
	if(!this->states.empty()){
		for(auto* newEntity : this->newEntities){
			this->states.top()->addEntity(newEntity);
		}
	}
}

