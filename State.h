#pragma once
#include <iostream>
#include <vector>
#include <stack>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Map.h"

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
	void addEntity(Entity* entity);
	//void checkEntityCollisions();
protected:
	virtual void drawEntities(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void updateEntities(const float& dt) const = 0;
	std::vector<Entity*> entities;
	Map map;

private:
	std::vector<sf::Texture> textures;
	bool quit;

};

