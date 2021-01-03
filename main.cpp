#include "Game.h"

class Player : public Entity{
public:
	Player() : Entity(sf::Vector2f(50, 50), sf::Vector2f(50, 50), sf::Color::Yellow, 400)
		,topDown(this)
	{
	}

	Player(sf::Vector2f position, sf::Vector2f size, sf::Color color, float speed) 
		: Entity(position, size, color, speed)
		, topDown(this){
	
	}

	void update(float dt){
		topDown.update(dt);
	}
	TopDown topDown;
};

int main(){
	Game game;
	Entity* entity = new Player;
	game.addEntity(entity);
	game.run();
	return 0;
}