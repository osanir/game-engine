#include "GameState.h"

GameState::GameState()
	: GameState("Map.config"){

}
GameState::GameState(std::string configFileName){
	map = new Map(configFileName);
	globals.setLayoutSize(this->map->getLayoutSize());
}

GameState::~GameState(){
}

void GameState::endState(){
	// TODO: endState fonksiyonunu destructor içine ekleyebiliriz.
	// Kullandýðý bütün kaynaklarý serbest býrakmalýdýr.
	std::cout << "Ending States" << std::endl;
}

void GameState::updateKeybinds(const float& dt){
	this->checkForQuit();
}

void GameState::update(const float& dt){
	/* State'i sonlandýrmak için escape tuþuna 
	   basýlýp basýlmadýðýný kontrol eder. */
	this->updateKeybinds(dt);
	//this->checkEntityCollisions();
	this->updateEntities(dt);
	//std::cout << this->map->getLayoutSize().x << "  " << this->map->getLayoutSize().y << std::endl;
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
