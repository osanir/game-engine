#pragma once
#include "Entity.h"

class Behaivor{
public:
	Behaivor(Entity *entity);
	Entity* entity;
	virtual void update(float dt) = 0;
private:

};

