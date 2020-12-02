#include "State.h"

State::State(){
	this->quit = false;
}

State::~State(){
}

const bool& State::getQuit() const{
	return this->quit;
}

void State::checkForQuit(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		this->quit = true;
	}
}
