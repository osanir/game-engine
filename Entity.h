#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Globals.h"

class Entity : public sf::Drawable{
public:
	Entity();
	Entity(sf::Vector2f position, sf::Vector2f size, sf::Color color, float speed);
	Entity(std::string fileName, float speed = 200, sf::Vector2f position = {0,0}, sf::Vector2f scale = {1,1});
	virtual void update(float dt) = 0;
	bool isSolid;

	// Collision
	bool onCollision(Entity& entity);
	// Getters
	sf::Sprite getShape();
	sf::Vector2f getPosition();
	sf::Vector2u getSize();

	// Setters
	void setMovement(sf::Vector2f movement);
	void setMovementSpeed(float movementSpeed);
	void setPosition(sf::Vector2f newPosition);
	void setRotationTowardPosition(sf::Vector2i towardPosition);

	void move(sf::Vector2f move);
private:
	sf::Vector2f movement;
	float movementSpeed;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Texture* texture;
	sf::Sprite shape;

	// Friends
	friend class TopDown;
	friend class ScrollTo;
};
