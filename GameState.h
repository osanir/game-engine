#pragma once
#include "State.h"

class GameState : public State{
public:
	GameState();
	virtual ~GameState();

	// Functions
	void endState();
	void updateKeybinds(const float& dt);
	void update(const float& dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawEntities(sf::RenderTarget& target, sf::RenderStates states) const;
	void updateEntities(const float&dt) const ;
private:

};

