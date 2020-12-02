#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Game::Game() : window(sf::VideoMode(854, 480), "Engine"){
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
}

void Game::updateDt(){
	/* Update edilen her bir kare arasýnda geçen süres hesaplanýr. */

	this->dt = this->dtClock.restart().asSeconds();
	// This shows elapsed time between two frames
	//std::cout << this->dt << std::endl;
	// This shows the count of frames per second
	//std::cout << "FPS: " << 1.f / this->dt << std::endl;
}

void Game::run(){
	this->start();
	while(window.isOpen()){
		this->updateDt();
		this->processEvents();
		this->update();
		this->render();
	}
}

void Game::processEvents(){
	sf::Event event;
	while(window.pollEvent(event)){
		// Window close
		switch(event.type){
		case sf::Event::Closed:
			window.close();
			break;
		default:
			break;
		}
	}
}

void Game::start(){
	// Init something
}

void Game::update(){
	player.update(dt);
}

void Game::render(){
	window.clear();
	window.draw(player);
	window.display();
}

