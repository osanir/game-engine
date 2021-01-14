#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Globals{
public:
	Globals();
	// Getters
	sf::VideoMode getWindowBounds();
	sf::Vector2f getLayoutSize();
	// Setters
	void setWindowBounds(sf::VideoMode windowBounds);
	void setLayoutSize(sf::Vector2f layoutSize);
private:
	sf::VideoMode windowBounds;
	sf::Vector2f layoutSize;
};

extern Globals globals;


