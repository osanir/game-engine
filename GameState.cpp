#include "GameState.h"

GameState::GameState(){
}

GameState::~GameState(){
}

void GameState::endState(){
	std::cout << "Ending States" << std::endl;
}

void GameState::updateKeybinds(const float& dt){
	this->checkForQuit();
}

void GameState::update(const float& dt){
	this->updateKeybinds(dt);
}

void GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const{

}