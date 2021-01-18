#pragma once
#include "Behavior.h"
class DestroyOutsideLayout : public Behavior{
public:
	DestroyOutsideLayout(Entity* entity);

	void update(float dt);
private:
};

