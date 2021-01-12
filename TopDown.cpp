#include "TopDown.h"

sf::Vector2f normalize(sf::Vector2f source){
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if(length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

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

	entity->movement = normalize(entity->movement);
}
