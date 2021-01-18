#pragma once
#include "Behavior.h"

class Bullet : public Behavior{
public:
	Bullet(Entity *entity);
	void update(float dt);
	void setSpeed(float speed);
private:
	sf::Vector2f movement;
	float speed;
	//bool setAngle;
	// float acceleration;
	// float gravity;
	// bool bounceOfSolids;

};

