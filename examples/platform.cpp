#include "Game.h"
#include "Logger.h"

class Player : public Entity{
public:
	Player(std::string fileName)
		:Entity(fileName)
		//,topDown(this)
		,platform(this)
		,scrollTo(this)
	{
		setPosition(sf::Vector2f(300, 100));
		setMovementSpeed(500);
	}

	void update(float dt){
		//topDown.update(dt);
		platform.update(dt);
		scrollTo.update(dt);
	}
	//TopDown topDown;
	Platform platform;
	ScrollTo scrollTo;

};

class Wall : public Entity{
public:
	Wall(std::string fileName)
		:Entity(fileName)
	{
		isSolid = true;
	}
	void update(float dt){
	}
};

class Missile : public Entity{
public:
	Missile(std::string fileName)
		:Entity(fileName),
		bullet(this),
		dol(this)
	{
		bullet.setSpeed(1000);
	}

	void update(float dt){
		bullet.update(dt);
		dol.update(dt);
	}
	Bullet bullet;
	DestroyOutsideLayout dol;
};

class MyGame : public Game{
public:
	GameState	state;
	Player		player;
	Missile		missile;
	Mouse		mouse;
	Wall		wall1, wall2, wall3, wall4, wall5, wall6;
	//std::vector<Wall*> myWalls;

	MyGame(): Game(),
		state("Map2.config"),
		player("blue.png"),
		missile("bullet.png"),
		wall1("box.png"),
		wall2("box.png"),
		wall3("box.png"),
		wall4("box.png"),
		wall5("box.png"),
		wall6("box.png")
	{
		//myWalls.resize(40);
		//for(int i = 0; i < 40; i++){
		//	Wall* wall = new Wall("box.png");
		//	wall->setPosition(sf::Vector2f(i * 70, 640));
		//	myWalls.push_back(wall);
		//}

		wall1.setPosition(sf::Vector2f(1 * 70, 640));
		wall2.setPosition(sf::Vector2f(2 * 70, 640));
		wall3.setPosition(sf::Vector2f(3 * 70, 640));
		wall4.setPosition(sf::Vector2f(4 * 70, 640));
		wall5.setPosition(sf::Vector2f(5 * 70, 640));
		wall6.setPosition(sf::Vector2f(6 * 70, 640));

		addState(&state);

		addEntity(&wall1);
		addEntity(&wall2);
		addEntity(&wall3);
		addEntity(&wall4);
		addEntity(&wall5);
		addEntity(&wall6);
		addEntity(&player);
		addEntity(&missile);
	}
	
	void OnStart(){
		//for(int i = 0; i < 40; i++){
		//	addEntity(myWalls[i]);
		//}

		player.scrollTo.setWindow(this->getWindow());
	}

	void OnUpdate(){

	}
};

int main(){
	MyGame game;
	game.run();
	return 0;
}