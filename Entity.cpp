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

void Entity::setRotationTowardPosition(sf::Vector2i towardPosition){
	sf::VideoMode windowBounds(globals.getWindowBounds());
	sf::Vector2f layoutSize(globals.getLayoutSize());
	float y, y1;
	float x, x1;
	float m;

	x = this->shape.getPosition().x;
	y = this->shape.getPosition().y;

	// TODO:: fix son else durumundayken karakter ekranýn en sað ve en alt 
	// kýsýmlarýndayken imleç pencernein altýna veya saðýna götürülürse 
	// karakter ters yöne bakýyor. Tam ekranda problem deðil ancak pencereli 
	// modda rahatsýz edici.
	if(x > windowBounds.width / 2.f && x < layoutSize.x - windowBounds.width / 2.f)
		x1 = x + (towardPosition.x - windowBounds.width / 2.f); 
	else if(x < windowBounds.width / 2.f)
		x1 = towardPosition.x;
	else
		x1 = layoutSize.x - (windowBounds.width - towardPosition.x); // 854 / 2 = 427 

	if(y > windowBounds.height / 2.f && y < layoutSize.y - windowBounds.height / 2.f)
		y1 = y + towardPosition.y - windowBounds.height / 2.f;
	else if(y < windowBounds.height / 2.f)
		y1 = towardPosition.y;
	else
		y1 = layoutSize.y - (windowBounds.height - towardPosition.y);

	//std::cout << "x: " << x << "\t y:" << y << "\t x1:" << x1 << "\t y1: " << y1 << "\t tpx:" << towardPosition.x << " \t tpy:" << towardPosition.y << std::endl;
	m = (y - y1) / (x - x1);
	m = atan(m);
	m = m * 180 / 3.14159265;
	if(x > x1) m += 180;

	this->shape.setRotation(m);
}

void Entity::move(sf::Vector2f move){
	this->shape.move(move);
}