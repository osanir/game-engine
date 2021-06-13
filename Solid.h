#pragma once
#include "Entity.h"
class Solid : public Entity{
public:
	Solid(std::string fileName)
		:Entity(fileName){
		this->isSolid = true;
	}

	void update(float dt){
	}


};

