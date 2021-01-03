#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Entity : public sf::Drawable{
public:
	Entity();
	Entity(sf::Vector2f position, sf::Vector2f size, sf::Color color, float speed);
	virtual void update(float dt) = 0;
	//void render(sf::RenderTarget &target);
private:
	sf::Vector2f movement;
	float movementSpeed;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape shape;

	friend class TopDown;
};
