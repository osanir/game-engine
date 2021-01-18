#include "Bullet.h"
#define PI 3.14159265
Bullet::Bullet(Entity* entity)
	:Behavior(entity)
{
	this->entity->isBullet = true;
	this->speed = 400;
}

void Bullet::update(float dt){
	float angle = this->entity->getAngle();
	this->movement.x = cos(angle * PI / 180);
	this->movement.y = sin(angle * PI / 180);
	entity->move(this->movement * dt * this->speed);
}

void Bullet::setSpeed(float speed){
	this->speed = speed;
}