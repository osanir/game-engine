#pragma once
#include <iostream>
#include <vector>
#include <stack>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class State : public sf::Drawable{
public:
	State();
	virtual ~State();

	const bool& getQuit() const;
	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

private:
	std::vector<sf::Texture> textures;
	bool quit;

};

