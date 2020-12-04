#include "Game.h"
class Player : public Entity{
public:
	Player() : Entity(sf::Vector2f(50, 50), sf::Vector2f(50, 50), sf::Color::Yellow) {
	}

private:

};
int main(){
	Game game;
	Entity* entity = new Player;
	game.addEntity(entity);
	game.run();
	return 0;
}