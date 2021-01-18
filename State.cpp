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
	/* Escape tuþuna basýldýðý zaman mevcut state sonlanýr. */
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		this->quit = true;
	}
}

void State::addEntity(Entity* entity){
	this->entities.push_back(entity);
}

std::vector<Entity*> *State::getEntities(){
	return &this->entities;
}

//bool checkCollision(Entity& e1, Entity& e2){
//	if(e1.getSprite().getGlobalBounds().intersects(e2.getSprite().getGlobalBounds())){
//		return true;
//	}
//	return false;
//}

//void State::checkEntityCollisions(){
//	for(int i = 0; i < entities.size(); i++){
//		entities[i]->clearCollisions();
//	}
//
//	for(int i = 0; i < entities.size()-1; i++){
//		for(int j = i+1; j < entities.size(); j++){
//			if( checkCollision(*entities[i], *entities[j])){
//				entities[i]->getCollisions()->push_back(entities[j]);
//				entities[j]->getCollisions()->push_back(entities[i]);
//			}
//		}
//	}
//}

