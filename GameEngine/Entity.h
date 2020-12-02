#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Entity : public sf::Drawable{
public:
	Entity();
	void update(float dt);
	//void render(sf::RenderTarget &target);
private:
	sf::Vector2f movement;
	float movementSpeed;
	void handlePlayerInput();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape shape;

};

