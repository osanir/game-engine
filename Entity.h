#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Entity : public sf::Drawable{
public:
	Entity();
	Entity(sf::Vector2f position, sf::Vector2f size, sf::Color color, float speed);
	Entity(std::string fileName, float speed = 200, sf::Vector2f position = {0,0}, sf::Vector2f scale = {1,1});
	virtual void update(float dt) = 0;
	//void render(sf::RenderTarget &target);
private:
	sf::Vector2f movement;
	float movementSpeed;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//sf::RectangleShape shape;
	sf::Texture* texture;
	sf::Sprite shape;

	friend class TopDown;
};
