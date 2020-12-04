#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Entity : public sf::Drawable{
public:
	Entity();
	Entity(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	void update(float dt);
	//void render(sf::RenderTarget &target);
private:
	bool defaultControls = true;
	sf::Vector2f movement;
	float movementSpeed;
	void handlePlayerInput();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape shape;

};
