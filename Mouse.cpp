#include "Mouse.h"

Mouse::Mouse(){
	this->alreadyClicked = false;
}

bool Mouse::onButtonDown(std::string button){

	if(button == "left"){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			return true;
		} else{
			return false;
		}
	}

	if(button == "right"){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
			return true;
		} else{
			return false;
		}
	}

	return false;
}

bool Mouse::onLeftButtonDown(){
	return this->onButtonDown("left");
}

bool Mouse::onRightButtonDown(){
	return this->onButtonDown("right");
}

bool Mouse::onButtonClicked(std::string button){
	static bool leftButtonAlreadyClicked = false;
	static bool rightButtonAlreadyClicked = false;
	
	if(button == "left"){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(leftButtonAlreadyClicked){
				return false;
			} else{
				leftButtonAlreadyClicked = true;
				return true;
			}
		} else{
			leftButtonAlreadyClicked = false;
			return false;
		}
	}
	
	if(button == "right"){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
			if(rightButtonAlreadyClicked){
				return false;
			} else{
				rightButtonAlreadyClicked = true;
				return true;
			}
		} else{
			rightButtonAlreadyClicked = false;
			return false;
		}
	}

	return false;
}

bool Mouse::onLeftButtonClicked(){
	return this->onButtonClicked("left");
}

bool Mouse::onRightButtonClicked(){
	return this->onButtonClicked("right");
}
