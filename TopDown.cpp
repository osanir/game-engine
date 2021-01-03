#include "TopDown.h"

TopDown::TopDown(Entity *entity) : Behaivor(entity){
	
}

void TopDown::update(float dt){
	handlePlayerInput();
	entity->shape.move(entity->movement * dt * entity->movementSpeed);
}

void TopDown::handlePlayerInput(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		entity->movement.x = 1;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		entity->movement.x = -1;
	} else{
		entity->movement.x = 0;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		entity->movement.y = -1;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		entity->movement.y = 1;
	} else{
		entity->movement.y = 0;
	}

}