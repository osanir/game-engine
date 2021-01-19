#include "Platform.h"
#include "Globals.h"

// TODO: Doðrudan topdown sýnýfýndan alýndý düzenlenmesi gerekiyor.

/* Hareket vektörünü birim vektör olarak günceller. */
sf::Vector2f Platform::normalize(sf::Vector2f source){
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if(length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

Platform::Platform(Entity* entity) : Behavior(entity){

}

// TODO: feature TopDown davranýþýna sahip varlýk katý objelerin içinden geçmemeli.
bool Platform::checkCollision(Entity& e1, Entity& e2){
	return e1.getSprite().getGlobalBounds().intersects(e2.getSprite().getGlobalBounds());
}
bool Platform::checkCollision(sf::Sprite e1, sf::Sprite e2){
	//std::cout << "t1x: " << e1.getPosition().x << "\t e1y: " << e1.getPosition().y << "\t e2x: " << e2.getPosition().x << "\t e2y: " << e2.getPosition().y << std::endl;
	return e1.getGlobalBounds().intersects(e2.getGlobalBounds());
}

void Platform::update(float dt){
	handlePlayerInput();
	/*entity->collisionShape.setSize(sf::Vector2f(entity->texture->getSize().x, entity->texture->getSize().y));
	entity->collisionShape.setPosition(entity->shape.getPosition());
	entity->collisionShape.move(entity->movement * dt * entity->movementSpeed);
	if( entity.ge)*/
	std::vector<Entity*> currentEntities = *(globals.getCurrentEntities());
	entity->movement.y += 0.05f;
	int size = currentEntities.size();
	for(int i = 0; i < size; i++){
		if(currentEntities[i]->isSolid && checkCollision(currentEntities[i]->getSprite(), this->getNextFrameSprite(dt))){

			sf::Vector2f s1 = currentEntities[i]->getSprite().getPosition();
			sf::Vector2f s2 = this->getNextFrameSprite(dt).getPosition();

			if(abs(s1.x - s2.x) > abs(s1.y - s2.y)){
				this->entity->movement.x = 0;
			} else{
				this->entity->movement.y = 0;
				canJump = true;
			}
		}
	}
	entity->move(entity->movement * dt * entity->movementSpeed);
}

void Platform::handlePlayerInput(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		entity->movement.x = 1;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		entity->movement.x = -1;
	} else{
		entity->movement.x = 0;
	}

	if(canJump && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		entity->movement.y = -1;
		canJump = false;
	} 

}

sf::Sprite Platform::getNextFrameSprite(float dt){
	sf::Sprite nextSprite(this->entity->getSprite());
	sf::Vector2f nextPos(this->entity->getPosition());
	nextPos.x += this->entity->movement.x * dt * this->entity->movementSpeed;
	nextPos.y += this->entity->movement.y * dt * this->entity->movementSpeed;
	nextSprite.setPosition(nextPos);
	return nextSprite;
}
