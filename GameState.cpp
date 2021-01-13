#include "GameState.h"

GameState::GameState(){
	map = new Map("Map.config");
}
GameState::GameState(std::string configFileName){
	map = new Map(configFileName);
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
	//this->checkEntityCollisions();
	this->updateEntities(dt);
}

void GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	this->drawEntities(target, states);
}

void GameState::drawEntities(sf::RenderTarget& target, sf::RenderStates states) const{
	//target.draw(map);
	target.draw(*map);
	for(auto *entity : this->entities){
		target.draw(*entity);
	}
}

void GameState::updateEntities(const float& dt) const{
	for(auto entity : this->entities){
		entity->update(dt);
	}
}
