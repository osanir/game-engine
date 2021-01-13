#include "Entity.h"

Entity::Entity(){
	this->shape.setPosition(sf::Vector2f(100, 100));
	//this->shape.setSize(sf::Vector2f(50, 50));
	//this->shape.setFillColor(sf::Color::Red);

	this->movement = sf::Vector2f(0, 0);
	this->movementSpeed = 300;
}

Entity::Entity(sf::Vector2f position, sf::Vector2f size, sf::Color color, float speed){
	this->shape.setPosition(position);
	//this->shape.setSize(size);
	//this->shape.setFillColor(color);
	this->movement = sf::Vector2f(0, 0);
	this->movementSpeed = speed;
}

Entity::Entity(std::string fileName, float speed, sf::Vector2f position, sf::Vector2f scale){
	sf::Texture tex;
	if(!tex.loadFromFile("Resources/Textures/" + fileName)){
		std::cout << fileName + " could not load from file. " << std::endl;
	}
	texture = new sf::Texture(tex);
	this->shape.setTexture(*this->texture);
	this->movement = movement;
	this->movementSpeed = speed;
	this->shape.setScale(scale);
	this->shape.setOrigin(sf::Vector2f(this->texture->getSize().x / 2, this->texture->getSize().y / 2));
}

/*
void Entity::render(sf::RenderTarget &target){
	target.draw(this->shape);
}
*/

//void Entity::update(float dt){
//	//handlePlayerInput();
//	//this->shape.move(movement * dt * movementSpeed);
//
//}

// Collision
bool Entity::onCollision(Entity& entity){
	if(this->shape.getGlobalBounds().intersects(entity.shape.getGlobalBounds())){
		return true;
	}
	return false;
}



void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->shape, states);
}


// Getters
sf::Sprite Entity::getShape(){
	return this->shape;
}

sf::Vector2f Entity::getPosition(){
	return this->shape.getPosition();
}

sf::Vector2u Entity::getSize(){
	return this->texture->getSize();
}

std::vector<Entity*>* Entity::getCollisions(){
	return &(this->collisions);
}

// Setters
void Entity::setMovement(sf::Vector2f movement){
	this->movement = movement;
}

void Entity::setMovementSpeed(float movementSpeed){
	this->movementSpeed = movementSpeed;
}

void Entity::setPosition(sf::Vector2f newPosition){
	this->shape.setPosition(newPosition);
}

void Entity::clearCollisions(){
	this->collisions.clear();
;}

void Entity::move(sf::Vector2f move){
	this->shape.move(move);
}