#include "Globals.h"

Globals globals;

Globals::Globals(){
}

sf::VideoMode Globals::getWindowBounds(){
	return this->windowBounds;
}

sf::Vector2f Globals::getLayoutSize(){
	return this->layoutSize;
}

void Globals::setWindowBounds(sf::VideoMode windowBounds){
	this->windowBounds.width = windowBounds.width;
	this->windowBounds.height = windowBounds.height;
}

void Globals::setLayoutSize(sf::Vector2f layoutSize){
	this->layoutSize = layoutSize;
}
