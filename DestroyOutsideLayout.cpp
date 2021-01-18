#include "DestroyOutsideLayout.h"

DestroyOutsideLayout::DestroyOutsideLayout(Entity* entity)
	:Behavior(entity)
{
}

void DestroyOutsideLayout::update(float dt){
	sf::Vector2f position(this->entity->getPosition());
	sf::Vector2f layoutSize(globals.getLayoutSize());
	if(position.x > layoutSize.x || position.x < 0
		|| position.y > layoutSize.y || position.y < 0){
		this->entity->destroy();
	}
}