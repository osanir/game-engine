#include "Entity.h"

Entity::Entity(){
	this->shape.setPosition(sf::Vector2f(100, 100));
	this->shape.setSize(sf::Vector2f(50, 50));
	this->shape.setFillColor(sf::Color::Red);

	this->movement = sf::Vector2f(0, 0);
	this->movementSpeed = 300;
}

Entity::Entity(sf::Vector2f position, sf::Vector2f size, sf::Color color){
	this->shape.setPosition(position);
	this->shape.setSize(size);
	this->shape.setFillColor(color);

	this->movement = sf::Vector2f(0, 0);
	this->movementSpeed = 300;
}

/*
void Entity::render(sf::RenderTarget &target){
	target.draw(this->shape);
}
*/

void Entity::update(float dt){
	handlePlayerInput();
	this->shape.move(movement * dt * movementSpeed);

}


void Entity::handlePlayerInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movement.x = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		movement.x = -1;
	}
	else {
		movement.x = 0;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		movement.y = -1;
	} 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		movement.y = 1;
	}
	else {
		movement.y = 0;
	}

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->shape, states);
}
