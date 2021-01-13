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
	{

	}

	void update(float dt){
		topDown.update(dt);
	}
	TopDown topDown;
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

	MyGame(){
		this->player = new Player("player.png");
		this->wall = new Wall("wall.png");
		this->wall->isSolid = true;
		this->wall->setPosition({300,300});
		this->addEntity(player);
		this->addEntity(wall);
	}

	void OnUpdate(){
		if(player->onCollision(*wall)){
			std::cout << "Çarpýþtý" << std::endl;
		}
	}
};

int main(){
	MyGame game;

	game.run();
	return 0;
}