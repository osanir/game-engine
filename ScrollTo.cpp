#include "ScrollTo.h"

ScrollTo::ScrollTo(Entity* entity) : Behavior(entity){

}

void ScrollTo::update(float dt){
	this->camera.update(this->entity->getPosition());
	this->window->setView(this->camera.getView());
}

void ScrollTo::setWindow(sf::RenderWindow* window){
	this->window = window;
}
