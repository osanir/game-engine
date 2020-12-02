#include "Game.h"

Game::Game() : window(sf::VideoMode(854, 480), "Engine"){
	this->window.setFramerateLimit(120);
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

