#include "Game.h"

class Player : public Entity{
public:
	/*
		Player() :
		Entity(sf::Vector2f(50, 50), sf::Vector2f(50, 50), sf::Color::Yellow, 400)
		,topDown(this)
	{
	}

	Player(sf::Vector2f position, sf::Vector2f size, sf::Color color, float speed) 
		: Entity(position, size, color, speed)
		, topDown(this){
	
	}
	//*/

	Player(std::string fileName)
		:Entity(fileName)
		,topDown(this)
		,scrollTo(this)
	{

	}

	void update(float dt){
		topDown.update(dt);
		scrollTo.update(dt);
	}
	TopDown topDown;
	ScrollTo scrollTo;

};

class Wall : public Entity{
public:
	Wall(std::string fileName)
		:Entity(fileName)
	{
	}
	void update(float dt){
		
	}

	
};

class MyGame : public Game{
public:
	Player* player;
	Wall* wall;
	State* state;

	MyGame(){
		this->player = new Player("player.png");
		this->player->setMovementSpeed(500);
		this->wall = new Wall("wall.png");
		this->player->scrollTo.setWindow(this->getWindow());

		this->state = new GameState("Map2.config");
		this->wall->isSolid = true;
		this->wall->setPosition({300,300});
		this->addState(state);
		this->addEntity(player);
		this->addEntity(wall);
	}
	
	void OnStart(){

	}

	void OnUpdate(){
		if(player->onCollision(*wall)){
			std::cout << "Çarpýþtý" << std::endl;
		}

		player->setRotationTowardPosition(this->getMousePosition());
	}
};

int main(){
	MyGame game;

	game.run();
	return 0;
}