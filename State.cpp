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

void State::addEntity(Entity* entity){
	this->entities.push_back(entity);
}

//bool checkCollision(Entity& e1, Entity& e2){
//	if(e1.getShape().getGlobalBounds().intersects(e2.getShape().getGlobalBounds())){
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

