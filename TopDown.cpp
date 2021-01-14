#include "TopDown.h"

// TODO: normalize gibi fonksiyonlarý utilites gibi ortak bir 
// sýnýf altýnda toplamak gerekiyor. Globals sýnýfý gibi 
//  her yerden eriþilebilir olmalýdýr.

/* Hareket vektörünü birim vektör olarak günceller. */
sf::Vector2f normalize(sf::Vector2f source){
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if(length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

TopDown::TopDown(Entity *entity) : Behavior(entity){
	
}

// TODO: feature TopDown davranýþýna sahip varlýk katý objelerin içinden geçmemeli.
bool checkCollision(Entity& e1, Entity& e2){
	if(e1.getShape().getGlobalBounds().intersects(e2.getShape().getGlobalBounds())){
		return true;
	}
	return false;
}

void TopDown::update(float dt){
	handlePlayerInput();
	/*entity->collisionShape.setSize(sf::Vector2f(entity->texture->getSize().x, entity->texture->getSize().y));
	entity->collisionShape.setPosition(entity->shape.getPosition());
	entity->collisionShape.move(entity->movement * dt * entity->movementSpeed);
	if( entity.ge)*/
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
