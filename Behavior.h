#pragma once
#include "Entity.h"

class Behavior{
public:
	Behavior(Entity *entity);
	Entity* entity;
	virtual void update(float dt) = 0;
private:

};

