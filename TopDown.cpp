#include "TopDown.h"
#include "Globals.h"

// TODO: normalize gibi fonksiyonlar� utilites gibi ortak bir 
// s�n�f alt�nda toplamak gerekiyor. Globals s�n�f� gibi 
//  her yerden eri�ilebilir olmal�d�r.

/* Hareket vekt�r�n� birim vekt�r olarak g�nceller. */
sf::Vector2f normalize(sf::Vector2f source){
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if(length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

TopDown::TopDown(Entity *entity) : Behavior(entity){
	
}

// TODO: feature TopDown davran���na sahip varl�k kat� objelerin i�inden ge�memeli.
bool checkCollision(Entity& e1, Entity& e2){
	return e1.getSprite().getGlobalBounds().intersects(e2.getSprite().getGlobalBounds());
}
bool checkCollision(sf::Sprite e1, sf::Sprite e2){
	//std::cout << "t1x: " << e1.getPosition().x << "\t e1y: " << e1.getPosition().y << "\t e2x: " << e2.getPosition().x << "\t e2y: " << e2.getPosition().y << std::endl;
	return e1.getGlobalBounds().intersects(e2.getGlobalBounds());
}

void TopDown::update(float dt){
	handlePlayerInput();
	/*entity->collisionShape.setSize(sf::Vector2f(entity->texture->getSize().x, entity->texture->getSize().y));
	entity->collisionShape.setPosition(entity->shape.getPosition());
	entity->collisionShape.move(entity->movement * dt * entity->movementSpeed);
	if( entity.ge)*/
	std::vector<Entity*> currentEntities = *(globals.getCurrentEntities());
	int size = currentEntities.size();
	for(int i = 0; i < size; i++){
		if( currentEntities[i]->isSolid && checkCollision(currentEntities[i]->getSprite(), this->getNextFrameSprite(dt)) ){

			sf::Vector2f s1 = currentEntities[i]->getSprite().getPosition();
			sf::Vector2f s2 = this->getNextFrameSprite(dt).getPosition();

			if(abs(s1.x - s2.x) > abs(s1.y - s2.y)){
				this->entity->movement.x = 0;
			} else{
				this->entity->movement.y = 0;
			}
		}
	}
	entity->move(entity->movement * dt * entity->movementSpeed);
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

sf::Sprite TopDown::getNextFrameSprite(float dt){
	sf::Sprite nextSprite(this->entity->getSprite());
	sf::Vector2f nextPos(this->entity->getPosition());
	nextPos.x += this->entity->movement.x * dt * this->entity->movementSpeed;
	nextPos.y += this->entity->movement.y * dt * this->entity->movementSpeed;
	nextSprite.setPosition(nextPos);
	return nextSprite;
}
